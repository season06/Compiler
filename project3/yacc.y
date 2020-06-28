%{
#include <iostream>
#include <string>
#include <fstream>
#include "math.h"
#include "symbol.hpp"
#include "lex.yy.cpp"
using namespace std;

#define Trace(t)	cout << t << "\n";

extern "C"
{
	void yyerror(const char *s);
	extern int yylex();
	//extern FILE* yyin;
}

void yyerror(string s)
{
	cout << s << "\n";
	exit(-1);
}

string objName = "";
SymbolTables table = SymbolTables();

fstream fp;
void printTab();
void logic_operator(string);

int nowTab = 0;
int nowLabel = 0;
int nowStack = 0;
bool isConst = false;
vector<int> elseLabel;

string nowFunc = "";
vector<vector<IDinfo>> funcCall;

%}
/****** Definition of yytype *****/

/* yacc lex shared variable */
%union {
	int v_int;
	float v_float;
	char v_char;
	string* v_string;
	bool v_bool;

	IDinfo* info;
	IDtype type;
	vector<IDinfo*>* funcCall;
};

%union {
	struct {
		int beginLabel;
		int exitLable;
	} whileLoop;
}

/* declare a terminal */
%token OBJECT CLASS DEF
%token VAR VAL INT FLOAT CHAR STRING BOOLEAN
%token TYPE _NULL TRUE FALSE
%token FOR TO DO WHILE REPEAT
%token BREAK CASE COUNTINUE EXIT RETURN
%token IF ELSE
%token PRINT PRINTLN READ

/* value is transmitted by lex */
%token <v_int> T_INT
%token <v_float> T_FLOAT
%token <v_char> T_CHAR
%token <v_string> T_STRING
%token <v_bool> T_BOOL
%token <v_string> ID

/* declare a nonterminal */
%type <info> values expr bool_expr function_invoc
%type <type> dataType
%type <whileLoop> WHILE

/* declare a terminal that is left-associative */
%left OR
%left AND
%left '!'
%left LT LTQ GT GTQ EQ NEQ
%left '+' '-'
%left '*' '/' '%'

/* declare a terminal that is nonassociative */
%nonassoc UMINUS

/* grammar start symbol */
%start program

%%
//////////////////////// object ////////////////////////
program : OBJECT ID 				{
										//Trace("create object table");
										objName = *$2;
										fp << "class " << objName << "\n" << "{" << "\n";
										nowTab++;

										table.push_table();
										IDinfo *f = new IDinfo(t_unknown, s_object, false);
										int t = table.insert(*$2, *f);
										
										if(t == -1)
											yyerror(*$2 + " has been declared");
									}
		  '{' objContent '}'		{
										//Trace("object ID objBlock ---> program");

										IDinfo id = table.list[table.top].idmap["main"];
										if(id.scope != s_function)
											yyerror("no main function");

										fp << "}";
										table.dump();
										table.pop_table();
									};

objContent : funcDecs objContent
 		   | declarations objContent
		   |
		   ;
//////////////////////// function ////////////////////////
// def id ( <formal argu> ) <:type>
funcDecs : funcDec funcDecs
		 | funcDec
		 ;
funcDec : DEF ID 									{
														//Trace("create function table");
														IDinfo *f = new IDinfo(t_unknown, s_function, false);
														int t = table.insert(*$2, *f);
														if(t == -1)
															yyerror(*$2 + " has been declared");
														nowFunc = *$2;
														table.push_table();

														nowStack = 0;
														printTab();
														fp << "method public static ";
													}
		'(' args ')' returnType						{
														IDinfo *id = table.lookup(*$2);
														if(*$2 == "main")
															fp << "void main(java.lang.String[])" << "\n";
														else
														{
															if(id->return_type == t_int)
																fp << "int ";
															else if(id->return_type == t_bool)
																fp << "bool ";
															else
																fp << "void ";
															fp << *$2 << "(";

															vector<IDinfo> parm = id->args_value;
															for(int i = 0; i < parm.size(); i++)
															{
																if(parm[i].type == t_int)
																	fp << "int";
																else if(parm[i].type == t_bool)
																	fp << "bool";
																
																if(i != parm.size()-1)
																	fp << ", ";
															}
															fp << ")" << "\n";
														}

														printTab();
														fp << "max_stack 15" << "\n";
														printTab();
														fp << "max_locals 15" << "\n";
														printTab();
														fp << "{" << "\n";
														nowTab++;
													}
		'{' blockContent '}'						{
														//Trace("def ID (args) type {} ---> funcDec");
														IDinfo *id = table.lookup(*$2);
														if(id->return_type == t_unknown && id->hasReturn == true)
															yyerror("function has no return type");
														else if(id->return_type != t_unknown && id->hasReturn == false)
															yyerror("function has no return value");

														table.dump();
														table.pop_table();

														if(id->return_type == t_unknown)
														{
															printTab();
															fp << "return" << "\n";
														}

														nowTab--;
														printTab();
														fp << "}" << "\n";
													};

args : arg ',' args						{
											//Trace("args, arg ---> args");
										}
	 |  arg 							{
											//Trace("arg ---> args");
										}
	 |										/* empty */
	 ;
arg : ID ':' dataType					{
											//Trace("ID:type ---> arg");
											IDinfo *f = new IDinfo($3, s_variable, false);
											int t = table.insert(*$1, *f);
											t = table.list[table.top-1].insert_args(nowFunc, *$1, *f);
											if(t == -1)
												yyerror(*$1 + " has been declared");

											IDinfo *id = table.lookup(*$1);
											id->stackIndex = nowStack;
											nowStack++;
										};

returnType : ':' dataType 				{
											table.list[table.top-1].idmap[nowFunc].return_type = $2;
										}
		   | 							{	/* empty */
			   								table.list[table.top-1].idmap[nowFunc].return_type = t_unknown;
		   								}; 
returnVal : RETURN expr 				{
											//Trace("return expr ---> returnVal");
											table.list[table.top-1].idmap[nowFunc].return_value = new IDinfo(*$2);
											table.list[table.top-1].idmap[nowFunc].hasReturn = true;

											printTab();
											fp << "ireturn" << "\n";
										}
	 	  | RETURN 						{
											//Trace("return ---> returnVal");
											table.list[table.top-1].idmap[nowFunc].return_value = new IDinfo();

											printTab();
											fp << "return" << "\n";
										};
//////////////////////// call function ////////////////////////
function_invoc : ID 					{
											funcCall.push_back(vector<IDinfo>());
										}
				'('	parameters ')'		{
											//Trace("ID(parameter) ---> function_invoc");
											IDinfo *id = table.lookup(*$1);
											if(id == NULL)
												yyerror(*$1 + " not found");
											if(id->scope != s_function)
												yyerror("ID type is not function, can't use ()");

											vector<IDinfo> parm = id->args_value;
											for(int i=0; i<parm.size(); i++)
											{
												if(funcCall[funcCall.size()-1][i].type != parm[i].type)
													yyerror("type error: parameter and declaration");
											}
											funcCall.pop_back();
											$$ = id;

											printTab();
											fp << "invokestatic ";
											if(id->return_type == t_int)
												fp << "int ";
											else if(id->return_type == t_bool)
												fp << "bool ";
											else
												fp << "void ";
											
											fp << objName << "." << id->id << "(";

											for(int i = 0; i < parm.size(); i++)
											{
												if(parm[i].type == t_int)
													fp << "int";
												else if(parm[i].type == t_bool)
													fp << "bool";
												
												if(i != parm.size()-1)
													fp << ", ";
											}
											fp << ")" << "\n";
										}
parameters: parameter
		  |
		  ;
parameter : para ',' parameter			{
											//Trace("expr, parameter ---> function parameter");
										}
		  | para 						{
											//Trace("expr ---> function parameter");
		  								}
		;							
para: expr								{
											funcCall[funcCall.size()-1].push_back(*$1);
										}

//////////////////////// statement ////////////////////////
stats : stat stats
	  |
	  ;
stat : ID '=' expr 					{
										//Trace("ID[expr] ---> stat");
										IDinfo *id = table.lookup(*$1);
										if(id == NULL)
											yyerror(*$1 + " not found");
										if(id->scope != s_variable)
											yyerror(*$1 + " is not variable, can't be assign");
										if($3->scope == s_function && $3->hasReturn == false)
											yyerror("function has no return value, can't be assign");
										
										if($3->scope == s_function)
											id->setValue($3->return_value->value);
										else
											id->setValue($3->value);

										if($3->scope == s_function)
											id->type = $3->return_value->type;
										else
											id->type = $3->type;
										id->init = true;
										
										if(id->global)
										{
											printTab();
											fp << "putstatic int " << objName << "." << id->id << "\n";
										}
										else
										{
											printTab();
											fp << "istore "<< id->stackIndex << "\n";
										}
									}
	| ID '[' expr ']' '=' expr 		{
										//Trace("ID[expr]=expr ---> stat");
										IDinfo *id = table.lookup(*$1);
										if(id == NULL)
											yyerror(*$1 + " not found");
										if(id->scope != s_array)
											yyerror(*$1 + " is not array");
										if($3->type != t_int)
											yyerror("Arrey index must be integer");
										int index = $3->value.v_int;
										if(index >= id->arr_size || index < 0)
											yyerror("array index out of range");
										if(id->type != $6->type)
											yyerror("array assign data type error");
										id->arr_value[index].setValue($6->value);
										id->init = true;
									}
	| 	PRINT  						{	
										//Trace("print ---> stat");
										printTab();
										fp << "getstatic java.io.PrintStream java.lang.System.out" << "\n";
									}
		expr						{
										printTab();
										fp << "invokevirtual void java.io.PrintStream.print(";
										if($3->type == t_int)
											fp << "int)" << "\n";
										else if($3->type == t_bool)
											fp << "boolean)" << "\n";
										else if($3->type == t_string)
											fp << "java.lang.String)" << "\n";
									}
	| 	PRINTLN  					{	
										//Trace("println ---> stat");
										printTab();
										fp << "getstatic java.io.PrintStream java.lang.System.out" << "\n";
									}
		expr						{
										printTab();
										fp << "invokevirtual void java.io.PrintStream.println(";
										if($3->type == t_int)
											fp << "int)" << "\n";
										else if($3->type == t_bool)
											fp << "boolean)" << "\n";
										else if($3->type == t_string)
											fp << "java.lang.String)" << "\n";
									}
	| READ ID 						{
										//Trace("read ID ---> stat");
									}
	| returnVal						{
										//Trace("returnVal ---> stat");
									}
	| ifStat						{	
										//Trace("ifStat ---> stat");
									}
	| loopStat						{
										//Trace("loopStat ---> stat");
									}
	| function_invoc				{
										//Trace("function_invoc ---> stat");
									}
	;
ifStat : IF '(' bool_expr ')' 		{
										printTab();
										fp << "ifeq " << "L" << nowLabel << "\n";
										elseLabel.push_back(nowLabel);
										nowLabel++;
									}
		 block_or_stat elseStat		{
			 							//Trace("IF (bool_expr) block elseStat ---> ifStat");
										
										fp << "L" << elseLabel.back() << ":" << "\n";
										elseLabel.pop_back();

										printTab();
										fp << "nop" << "\n";
									}
	   ;
elseStat : ELSE						{
										printTab();
										fp << "goto " << "L" << nowLabel << "\n";
										fp << "L" << elseLabel.back() << ":" << "\n";
										elseLabel.pop_back();
										elseLabel.push_back(nowLabel);
										nowLabel++;

										printTab();
										fp << "nop" << "\n";
									}
		   block_or_stat			{
			   							//Trace("else block ---> elseStat");
									}
		 | //empty
		 ;

loopStat : 	WHILE								{
													fp << "L" << nowLabel << ":" << "\n";
													$1.beginLabel = nowLabel;
													nowLabel++;
												}
			'(' expr ')' 						{
													printTab();
													fp << "ifeq " << "L" << nowLabel << "\n";
													$1.exitLable = nowLabel;
													nowLabel++;
												}
		   	block_or_stat						{
													//Trace("WHILE (expr) ---> loopStat");

													printTab();
													fp << "goto " << "L" << $1.beginLabel << "\n";
													fp << "L" << $1.exitLable << ":" << "\n";

													printTab();
													fp << "nop" << "\n";
												}
		 | FOR '(' ID LT '-' T_INT TO T_INT ')' {
													IDinfo *id = table.lookup(*$3);
													if(id == NULL)
														yyerror(*$3 + " not found");
												}
		   block_or_stat						{	
			   										//Trace("for (id <- expr to expr) ---> loopStat");
		   										};
block_or_stat: block | stat;

block : '{' 						{
										//Trace("create block table");
										table.push_table();
									}
		blockContent '}' 			{
										//Trace("{blockContent} ---> block");
										table.dump();
										table.pop_table();
									};
blockContent : declaration blockContent
			 | stats
			 ;
////////////////////////  declaration ////////////////////////
declarations : declaration declarations
			 | 
			 ;

declaration : varDeclare
			| constDeclare

varDeclare : VAR ID ':' dataType '[' T_INT ']'	{
													//Trace("var id : type [ expr ] ---> declaration");
													IDinfo *f = new IDinfo($4, s_array, false);
													int t = table.insert(*$2, *f);
													if(t == -1)
														yyerror(*$2 + " has been declared");
													table.list[table.top].insert_arr(*$2, $4, $6);
												}
		   | VAR ID ':' dataType '=' expr 		{
													//Trace("var id : type = expr ---> declaration");
													if($4 != $6->type)
														yyerror("type error: dataType and expr");
													$6->scope = s_variable;
													$6->init = true;
													int t = table.insert(*$2, *$6);
													if(t == -1)
														yyerror(*$2 + " has been declared");

													IDinfo *id = table.lookup(*$2);
													if(id->global)
													{
														printTab();
														if(id->type == t_int)
															fp << "field static int " << id->id << " = " << id->value.v_int << "\n";
														else if(id->type == t_bool)
															fp << "field static int " << id->id << " = " << id->value.v_bool << "\n";
													}
													else
													{
														id->stackIndex = nowStack;
														nowStack++;

														printTab();
														if(id->type == t_int || id->type == t_bool)
															fp << "istore " << id->stackIndex << "\n";
													}
												}
		   | VAR ID '=' expr 					{
													//Trace("var id = expr ---> declaration");
													$4->scope = s_variable;
													$4->init = true;
													int t = table.insert(*$2, *$4);
													if(t == -1)
														yyerror(*$2 + " has been declared");

													IDinfo *id = table.lookup(*$2);
													if(id->global)
													{
														printTab();
														if(id->type == t_int)
															fp << "field static int " << id->id << " = " << id->value.v_int << "\n";
														else if(id->type == t_bool)
															fp << "field static int " << id->id << " = " << id->value.v_bool << "\n";
													}
													else
													{
														id->stackIndex = nowStack;
														nowStack++;

														printTab();
														if(id->type == t_int || id->type == t_bool)
															fp << "istore " << id->stackIndex << "\n";
													}
												}
		   | VAR ID ':' dataType 				{
													//Trace("var id : type ---> declaration");
													IDinfo *f = new IDinfo($4, s_variable, false);
													int t = table.insert(*$2, *f);
													if(t == -1)
														yyerror(*$2 + " has been declared");

													IDinfo *id = table.lookup(*$2);
													if(id->global)
													{
														printTab();
														fp << "field static " << IDtype2str(id->type) << " " << id->id << "\n";
													}
													else
													{
														id->stackIndex = nowStack;
														nowStack++;
													}
												}
		   | VAR ID 							{
													//Trace("var id ---> declaration");
													IDinfo *f = new IDinfo(t_unknown, s_variable, false);
													int t = table.insert(*$2, *f);
													if(t == -1)
														yyerror(*$2 + " has been declared");

													IDinfo *id = table.lookup(*$2);
													if(id->global)
													{
														printTab();
														fp << "field static int " << id->id << "\n";
													}
													else
													{
														id->stackIndex = nowStack;
														nowStack++;
													}
												};

constDeclare : 	VAL ID ':' dataType '=' 		{ 
													isConst = true;
												}
				expr							{
													//Trace("val id : type = expr ---> declaration");
													if($4 != $7->type)
														yyerror("type error: dataType and expr");
													$7->scope = s_const;
													$7->init = true;
													int t = table.insert(*$2, *$7);
													if(t == -1)
														yyerror(*$2 + " has been declared");

													isConst = false;
												}
		 	 | 	VAL ID '='						{
				  									isConst = true;
												}
			   	expr							{
													//Trace("val id = expr ---> declaration");
													$5->scope = s_const;
													$5->init = true;
													int t = table.insert(*$2, *$5);
													if(t == -1)
														yyerror(*$2 + " has been declared");

													isConst = false;
												};
//////////////////////// expression ////////////////////////
expr : '(' expr ')' 		{
								//Trace("(expr) ---> expr");
								$$ = $2;
							}
	| '-' expr %prec UMINUS { 
								//Trace("-expr ---> expr");
								if($2->type == t_int)
								{
									$2->value.v_int *= -1;
									$$ = $2;
								}
								else
									yyerror("type error -> - expr");

								if(!isConst && !table.isGlobal())
								{
									printTab();
									fp << "ineg\n";
								}
							}
	 | expr '+' expr 		{ 
								//Trace("expr + expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int + $3->value.v_int;
								}
								else
									yyerror("type error -> expr + expr");
								
								if(!isConst && !table.isGlobal())
								{
									printTab();
									fp << "iadd\n";
								}
							}
	 | expr '-' expr  		{ 
								//Trace("expr - expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int - $3->value.v_int;
								}
								else
									yyerror("type error -> expr - expr");
								
								if(!isConst && !table.isGlobal())
								{
									printTab();
									fp << "isub\n";
								}
							}
	 | expr '*' expr  		{ 
								//Trace("expr * expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int * $3->value.v_int;
								}
								else
									yyerror("type error -> expr * expr");
								
								if(!isConst && !table.isGlobal())
								{
									printTab();
									fp << "imul\n";
								}
							}
	 | expr '/' expr  		{ 
								//Trace("expr / expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int / $3->value.v_int;
								}
								else
									yyerror("type error -> expr / expr");
								
								if(!isConst && !table.isGlobal())
								{
									printTab();
									fp << "idiv\n";
								}
							}
	 | expr '%' expr  		{ 
								//Trace("expr % expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int % $3->value.v_int;
								}
								else
									yyerror("type error -> expr % expr");
								
								if(!isConst && !table.isGlobal())
								{
									printTab();
									fp << "irem\n";
								}
							}
	 | bool_expr 			{
								//Trace("bool_expr ---> expr");
								$$ = $1;
							}
	 | ID '[' expr ']' 		{
								//Trace("ID[expr] ---> expr");
								IDinfo *id = table.lookup(*$1);
								if(id == NULL)
									yyerror(*$1 + " not found");
								if(id->scope != s_array)
									yyerror("ID type is not array, can't use []");
								if($3->type != t_int)
									yyerror("Arrey index must be integer");
								int index = $3->value.v_int;
								if(index > id->arr_size || index < 0)
									yyerror("Arrey index out of range");
								$$ = new IDinfo(id->arr_value[index]);
							}
	 | function_invoc		{
		 						//Trace("function_invoc ---> expr");
								$$ = $1;
							}
	 | ID 					{
								//Trace("ID ---> expr");
								IDinfo *id = table.lookup(*$1);
								if(id == NULL)
									yyerror(*$1 + " not found");
								if(id->scope == s_array)
									yyerror("ID in array scope has no index.");
								if(id->scope == s_function)
									yyerror("ID call function has no parameter.");
								$$ = id;

								if(id->scope == s_const)
								{
									printTab();
									if(id->type == t_int)
										fp << "sipush " << id->value.v_int << "\n";
									else if(id->type == t_bool)
										fp << "iconst_" << id->value.v_bool << "\n";
								}
								else
								{
									if(id->global)
									{
										printTab();
										if(id->type == t_int || id->type == t_bool)
											fp << "getstatic int " << objName << "." << id->id << "\n";
									}
									else
									{
										printTab();
										if(id->type == t_int || id->type == t_bool)
											fp << "iload " << id->stackIndex << "\n";
									}
								}
							}
	 | values 				{
								//Trace("values ---> expr");
								$$ = $1;
							};

bool_expr : '!' expr 		{ 
								//Trace("! expr ---> bool_expr");
								if($2->type != t_bool)
									yyerror("type error -> ! expr");
								else
									$$->value.v_bool = !($2->value.v_bool);

								if(!isConst && !table.isGlobal())
								{
									printTab();
									fp << "iconst_1" << "\n";
									printTab();
									fp << "ixor" << "\n";
								}
							}
		  | expr LT expr 	{ 
								//Trace("expr < expr ---> bool_expr");
								if($1->type == t_int && $3->type == t_int)
									$$->value.v_bool = $1->value.v_int < $3->value.v_int;
								else
									yyerror("type error -> expr < expr");
								
								logic_operator("iflt");
							}
		  | expr LTQ expr 	{ 
								//Trace("expr <= expr ---> bool_expr");
								if($1->type == t_int && $3->type == t_int)
									$$->value.v_bool = $1->value.v_int <= $3->value.v_int;
								else
									yyerror("type error -> expr <= expr");
								
								logic_operator("ifle");
							}
		  | expr GT expr 	{ 
								//Trace("expr > expr ---> bool_expr");
								if($1->type == t_int && $3->type == t_int)
									$$->value.v_bool = $1->value.v_int > $3->value.v_int;
								else
									yyerror("type error -> expr > expr");
								
								logic_operator("ifgt");
							}
		  | expr GTQ expr 	{ 
								//Trace("expr >= expr ---> bool_expr");
								if($1->type == t_int && $3->type == t_int)
									$$->value.v_bool = $1->value.v_int >= $3->value.v_int;
								else
									yyerror("type error -> expr >= expr");
								
								logic_operator("ifge");
							}
		  | expr EQ expr 	{ 
								//Trace("expr == expr ---> bool_expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->value.v_bool = $1->value.v_int == $3->value.v_int;
								}
								else if($1->type == t_float && $3->type == t_float)
								{
									$$->value.v_bool = $1->value.v_float == $3->value.v_float;
								}
								else if($1->type == t_char && $3->type == t_char)
								{
									$$->value.v_bool = $1->value.v_char == $3->value.v_char;
								}
								else if($1->type == t_string && $3->type == t_string)
								{
									$$->value.v_bool = $1->value.v_string == $3->value.v_string;
								}
								else if($1->type == t_bool && $3->type == t_bool)
								{
									$$->value.v_bool = $1->value.v_bool == $3->value.v_bool;
								}
								else
								{
									yyerror("type error -> expr == expr");
								}

								logic_operator("ifeq");
							}
	 	  | expr NEQ expr 	{ 
								//Trace("expr != expr ---> bool_expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->value.v_bool = $1->value.v_int != $3->value.v_int;
								}
								else if($1->type == t_float && $3->type == t_float)
								{
									$$->value.v_bool = $1->value.v_float != $3->value.v_float;
								}
								else if($1->type == t_char && $3->type == t_char)
								{
									$$->value.v_bool = $1->value.v_char != $3->value.v_char;
								}
								else if($1->type == t_string && $3->type == t_string)
								{
									$$->value.v_bool = $1->value.v_string != $3->value.v_string;
								}
								else if($1->type == t_bool && $3->type == t_bool)
								{
									$$->value.v_bool = $1->value.v_bool != $3->value.v_bool;
								}
								else
								{
									yyerror("type error -> expr != expr");
								}

								logic_operator("ifne");
							}
		  | expr AND expr	{ 
								//Trace("expr && expr ---> bool_expr");
								if($1->type != t_bool || $3->type != t_bool)
								{
									yyerror("type error -> expr && expr");
								}
								else
								{
									$$->value.v_bool = $1->value.v_bool && $3->value.v_bool;
								}

								if(!isConst && !table.isGlobal())
								{
									printTab();
									fp << "iand\n";
								}
							}
		  | expr OR expr	{ 
								//Trace("expr || expr ---> bool_expr");
								if($1->type != t_bool || $3->type != t_bool)
								{
									yyerror("type error -> expr || expr");
								}
								else
								{
									$$->value.v_bool = $1->value.v_bool || $3->value.v_bool;
								}

								if(!isConst && !table.isGlobal())
								{
									printTab();
									fp << "ior\n";
								}
							};
dataType : INT			{
							$$ = t_int;
						}
		 | FLOAT		{
							$$ = t_float;
						}
		 | CHAR			{
							$$ = t_char;
						}
		 | STRING		{
							$$ = t_string;
						}
		 | BOOLEAN		{
							$$ = t_bool;
						};
values : T_INT			{
							//Trace("T_INT ---> values");
							$$ = set_int($1);

							if(!isConst && !table.isGlobal())
							{
								printTab();
								fp << "sipush " << $1 << "\n";
							}
						}
	   | T_FLOAT		{
							//Trace("T_FLOAT ---> values");
							$$ = set_float($1);
						}
	   | T_CHAR			{
							//Trace("T_CHAR ---> values");
							$$ = set_char($1);
						}
	   | T_STRING		{
							//Trace("T_STRING ---> values");
							$$ = set_string(*$1);

							if(!isConst && !table.isGlobal())
							{
								printTab();
								fp << "ldc \"" << *$1 << "\"" << "\n";
							}
						}
	   | T_BOOL			{
							//Trace("T_BOOL ---> values");
							$$ = set_bool($1);

							if(!isConst && !table.isGlobal())
							{
								printTab();
								if($1 == true)
									fp << "iconst_1 " << "\n";
								else if($1 == false)
									fp << "iconst_0 " << "\n";
							}
						};
%%

void printTab()
{
	for(int i = 0; i < nowTab; i++)
		fp << "\t";
}

void logic_operator(string op)
{
	printTab();
	fp << "isub" << "\n";
	printTab();
	fp << op << " L" << nowLabel << "\n";
	printTab();
	fp << "iconst_0" << "\n";
	printTab();
	fp << "goto L" << nowLabel+1 << "\n";
	fp << "L" << nowLabel << ":" << "\n";
	printTab();
	fp << "iconst_1" << "\n";
	fp << "L" << nowLabel+1 << ":" << "\n";
	nowLabel += 2;
}

int main(int argc, char *argv[])
{
    // have a file or not
    if(argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;

	string filename = "./jasmFile/" + string(argv[2]) + ".jasm";
	fp.open(filename, ios::out);
	if(!fp)
	{
		cout << "open file error\n";
		exit(-1);
	}

    if(yyparse() == 1)
		yyerror("parsing error");
	else
	{
		table.dump();
		cout << "=============Parsing Success=============\n";
	}
	fp.close();

    return 0;
}