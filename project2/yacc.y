%{
#include <iostream>
#include <string>
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

SymbolTables table = SymbolTables();
string now_func = "";
vector<vector<IDinfo>> func_call;

%}
/****** Definition of yytype *****/

// yacc lex shared variable
%union {
	int v_int;
	float v_float;
	char v_char;
	string* v_string;
	bool v_bool;

	IDinfo* info;
	IDtype type;
	vector<IDinfo*>* func_call;
};

// declare a terminal
%token OBJECT CLASS DEF
%token VAR VAL INT FLOAT CHAR STRING BOOLEAN
%token TYPE _NULL TRUE FALSE
%token FOR TO DO WHILE REPEAT
%token BREAK CASE COUNTINUE EXIT RETURN
%token IF ELSE
%token PRINT PRINTLN READ

// value is transmitted by lex
%token <v_int> T_INT
%token <v_float> T_FLOAT
%token <v_char> T_CHAR
%token <v_string> T_STRING
%token <v_bool> T_BOOL
%token <v_string> ID

// declare a nonterminal
%type <info> values expr bool_expr function_invoc
%type <type> dataType
%type <func_call> parameter

// declare a terminal that is left-associative
%left OR
%left AND
%left '!'
%left LT LTQ GT GTQ EQ NEQ
%left '+' '-'
%left '*' '/' '%'

// declare a terminal that is nonassociative
%nonassoc UMINUS

//grammar start symbol
%start program

%%
//////////////////////// object ////////////////////////
program : OBJECT ID 			{
									Trace("create object table");
									table.push_table();
									IDinfo *f = new IDinfo(t_unknown, s_object, false);
									int t = table.insert(*$2, *f);
									if(t == -1)
										yyerror(*$2 + " has been declared");
								}
		  '{' objContent '}'	{
									Trace("object ID objBlock ---> program");
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
funcDec : DEF ID 							{
												Trace("create function table");
												IDinfo *f = new IDinfo(t_unknown, s_function, false);
												int t = table.insert(*$2, *f);
												if(t == -1)
													yyerror(*$2 + " has been declared");
												now_func = *$2;
												table.push_table();
											} 
		'(' args ')' returnType '{' blockContent returnVal '}'								
											{
												Trace("def ID (args) type {} ---> funcDec");
												//if($7 != $10->type)
												//	yyerror("type error: function type and return type");
												table.dump();
												table.pop_table();
											};

args : arg ',' args					{
										Trace("args, arg ---> args");
									}
	 |  arg 						{
										Trace("arg ---> args");
									}
	 |									// empty
	 ; 
arg : ID ':' dataType				{
										Trace("ID:type ---> arg");
										IDinfo *f = new IDinfo($3, s_variable, false);
										int t = table.insert(*$1, *f);
										t = table.list[table.top].insert_args(now_func, *$1, *f);
										if(t == -1)
											yyerror(*$1 + " has been declared");
									};

returnType : ':' dataType 			{
										table.list[table.top].idmap[now_func].return_type = $2;
									}
		   | 						{	//empty
			   							table.list[table.top].idmap[now_func].return_type = t_unknown;
		   							}; 
returnVal : RETURN expr 			{
										Trace("return expr ---> returnVal");
										table.list[table.top].idmap[now_func].return_value = new IDinfo(*$2);
									}
	 	  | RETURN 					{
										Trace("return ---> returnVal");
										table.list[table.top].idmap[now_func].return_value = new IDinfo();
									}
		  | 						{	// empty
										table.list[table.top].idmap[now_func].return_value = new IDinfo();
									};
//////////////////////// call function ////////////////////////
function_invoc : ID 					{
											func_call.push_back(vector<IDinfo>());
										}
				'('	parameters ')'		{
											Trace("ID(parameter) ---> expr");
											IDinfo *id = table.lookup(*$1);
											if(id == NULL)
												yyerror(*$1 + " not found");
											if(id->scope != IDscope::s_function)
												yyerror("ID type is not function, can't use ()");
											vector<IDinfo> parm = id->args_value;
											for(int i=0; i<parm.size(); i++)
											{
												if(func_call[func_call.size()-1][i].type != parm[i].type)
													yyerror("type error: parameter and declaration");
											}
											func_call.pop_back();
											$$ = id->return_value;
										}
parameters: parameter
		  |
		  ;
parameter : para ',' parameter			{
											Trace("expr, parameter ---> function parameter");
										}
		  | para 						{
											Trace("expr ---> function parameter");
		  								}
		;							
para: expr								{
											func_call[func_call.size()-1].push_back(*$1);
										}

//////////////////////// statement ////////////////////////
stats : stat stats
	  | stat
	  ;
stat : ID '=' expr 					{
										Trace("ID[expr] ---> stat");
										IDinfo *id = table.lookup(*$1);
										if(id == NULL)
											yyerror(*$1 + " not found");
										if(id->scope != s_variable)
											yyerror(*$1 + " is not variable, can't be assign");
										id->setValue($3->value);
										id->init = true;
									}
	| ID '[' T_INT ']' '=' expr 	{
										Trace("ID[expr]=expr ---> stat");
										IDinfo *id = table.lookup(*$1);
										if(id == NULL)
											yyerror(*$1 + " not found");
										if(id->scope != s_array)
											yyerror(*$1 + " is not array");
										if($3 >= id->arr_size || $3 < 0)
											yyerror("array index out of range");
										if(id->arr_size != $6->type)
											yyerror("array assign data type error");
										id->arr_value[$3].setValue($6->value);
										id->init = true;
									}
	| PRINT expr 				{
									Trace("print ---> stat");
								}
	| PRINTLN expr 				{
									Trace("println ---> stat");
								}
	| READ ID 					{
									Trace("read ID ---> stat");
								}
	| ifStat					{
									Trace("ifStat ---> stat");
								}
	| loopStat					{
									Trace("loopStat ---> stat");
								}
	| block						{
									Trace("block ---> stat");
								};
ifStat : IF '(' bool_expr ')' 	
		 block elseStat			{
									Trace("IF (bool_expr) block elseStat ---> ifStat");
								};
elseStat : ELSE
		   block				{
									Trace("else block ---> elseStat");
								}
		 | //empty
		 ;

loopStat : WHILE '(' bool_expr ')' 				
		   block								{
													Trace("WHILE (bool_expr) block ---> loopStat");
												}
		 | FOR '(' ID LT '-' expr TO expr ')' 	
		   block								{
													Trace("for (id <- expr to expr) block ---> loopStat");
												};


block : '{' 				{
								Trace("create block table");
								table.push_table();
							}
		blockContent '}' 	{
								Trace("{blockContent} ---> block");
								table.dump();
								table.pop_table();
							};
blockContent : declarations blockContent
			 | stats blockContent
			 | declarations
			 | stats
		 	 |  //empty
			  ;
////////////////////////  declaration ////////////////////////
declarations : declaration declarations
			 | declaration

declaration : varDeclare
			| constDeclare
// val id <:type> = constant
// var id <:type> <=constant>
// var id : type [num]
varDeclare : VAR ID ':' dataType '[' T_INT ']'	{
													Trace("var id : type [ expr ] ---> declaration");
													int t = table.insert_arr(*$2, $4, $6);
													if(t == -1)
														yyerror(*$2 + " has been declared");
												}
		   | VAR ID ':' dataType '=' expr 		{
													Trace("var id : type = expr ---> declaration");
													if($4 != $6->type)
														yyerror("type error: dataType and expr");
													$6->scope = s_variable;
													$6->init = true;
													int t = table.insert(*$2, *$6);
													if(t == -1)
														yyerror(*$2 + " has been declared");
												}
		   | VAR ID '=' expr 					{
													Trace("var id = expr ---> declaration");
													$4->scope = s_variable;
													$4->init = true;
													int t = table.insert(*$2, *$4);
													if(t == -1)
														yyerror(*$2 + " has been declared");
												}
		   | VAR ID ':' dataType 				{
													Trace("var id : type ---> declaration");
													IDinfo *f = new IDinfo($4, s_variable, false);
													int t = table.insert(*$2, *f);
													if(t == -1)
														yyerror(*$2 + " has been declared");
												}
		   | VAR ID 							{
													Trace("var id ---> declaration");
													IDinfo *f = new IDinfo(t_unknown, s_variable, false);
													int t = table.insert(*$2, *f);
													if(t == -1)
														yyerror(*$2 + " has been declared");
												};

constDeclare : VAL ID ':' dataType '=' expr	{
												Trace("val id : type = expr ---> declaration");
												if($4 != $6->type)
													yyerror("type error: dataType and expr");
												$6->scope = s_const;
												$6->init = true;
												int t = table.insert(*$2, *$6);
												if(t == -1)
													yyerror(*$2 + " has been declared");
											}
		 	 | VAL ID '=' expr				{
												Trace("val id = expr ---> declaration");
												$4->scope = s_const;
												$4->init = true;
												int t = table.insert(*$2, *$4);
												if(t == -1)
													yyerror(*$2 + " has been declared");
											};
//////////////////////// expression ////////////////////////
expr : '(' expr ')' 		{
								Trace("(expr) ---> expr");
								$$ = $2;
							}
	| '-' expr %prec UMINUS 	{ 
									Trace("-expr ---> expr");
									if($2->type == t_int)
									{
										$$->value.v_int = $2->value.v_int;
									}
									else if($2->type == t_float)
									{
										$$->value.v_float =  $2->value.v_float;
									}
									else
									{
										yyerror("type error -> - expr");
									}
								}
	 | expr '+' expr 		{ 
								Trace("expr + expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int + $3->value.v_int;
								}
								else if($1->type == t_float && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = $1->value.v_float + $3->value.v_float;
								}
								else if($1->type == t_int && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = (float)$1->value.v_int + $3->value.v_float;
								}
								else if($1->type == t_float && $3->type == t_int)
								{
									$$->type = t_float;
									$$->value.v_float = $1->value.v_float + (float)$3->value.v_int;
								}
								else
								{
									yyerror("type error -> expr + expr");
								}
							}
	 | expr '-' expr  		{ 
								Trace("expr - expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int - $3->value.v_int;
								}
								else if($1->type == t_float && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = $1->value.v_float - $3->value.v_float;
								}
								else if($1->type == t_int && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = (float)$1->value.v_int - $3->value.v_float;
								}
								else if($1->type == t_float && $3->type == t_int)
								{
									$$->type = t_float;
									$$->value.v_float = $1->value.v_float - (float)$3->value.v_int;
								}
								else
								{
									yyerror("type error -> expr - expr");
								}
							}
	 | expr '*' expr  		{ 
								Trace("expr * expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int * $3->value.v_int;
								}
								else if($1->type == t_float && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = $1->value.v_float * $3->value.v_float;
								}
								else if($1->type == t_int && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = (float)$1->value.v_int * $3->value.v_float;
								}
								else if($1->type == t_float && $3->type == t_int)
								{
									$$->type = t_float;
									$$->value.v_float = $1->value.v_float * (float)$3->value.v_int;
								}
								else
								{
									yyerror("type error -> expr * expr");
								}
							}
	 | expr '/' expr  		{ 
								Trace("expr / expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int / $3->value.v_int;
								}
								else if($1->type == t_float && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = $1->value.v_float / $3->value.v_float;
								}
								else if($1->type == t_int && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = (float)$1->value.v_int / $3->value.v_float;
								}
								else if($1->type == t_float && $3->type == t_int)
								{
									$$->type = t_float;
									$$->value.v_float = $1->value.v_float / (float)$3->value.v_int;
								}
								else
								{
									yyerror("type error -> expr / expr");
								}
							}
	 | expr '%' expr  		{ 
								Trace("expr % expr ---> expr");
								if($1->type == t_int && $3->type == t_int)
								{
									$$->type = t_int;
									$$->value.v_int = $1->value.v_int % $3->value.v_int;
								}
								else if($1->type == t_float && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = fmod($1->value.v_float, $3->value.v_float);
								}
								else if($1->type == t_int && $3->type == t_float)
								{
									$$->type = t_float;
									$$->value.v_float = fmod((float)$1->value.v_int, $3->value.v_float);
								}
								else if($1->type == t_float && $3->type == t_int)
								{
									$$->type = t_float;
									$$->value.v_float = fmod($1->value.v_float, (float)$3->value.v_int);
								}
								else
								{
									yyerror("type error -> expr % expr");
								}
							}
	 | bool_expr 				{
									Trace("bool_expr ---> expr");
									$$ = $1;
								}
	 | ID '[' expr ']' 		{
									Trace("ID[expr] ---> expr");
									IDinfo *id = table.lookup(*$1);
									if(id == NULL)
										yyerror(*$1 + " not found");
									if(id->scope != s_array)
										yyerror("ID type is not array, can't use []");
									if($3->type != t_int)
										yyerror("Arrey index must be integer");
									if($3->value.v_int > id->arr_size || $3->value.v_int < 0)
										yyerror("Arrey index out of range");
									$$ = new IDinfo(id->arr_value[$3->value.v_int]);
									
								}
	 | function_invoc			{	Trace("function_invoc ---> expr");	}
	 | ID 						{
									Trace("ID ---> expr");
									IDinfo *id = table.lookup(*$1);
									if(id == NULL)
										yyerror(*$1 + " not found");
									if(id->scope == s_array)
										yyerror("ID in array scope has no index.");
									if(id->scope == s_function)
										yyerror("ID call function has no parameter.");
									$$ = id;
								}
	 | values 					{
									Trace("values ---> expr");
									$$ = $1;
								};

bool_expr : '!' expr 			{ 
									Trace("! expr ---> bool_expr");
									if($2->type != t_bool)
									{
										yyerror("type error -> ! expr");
									}
									else
									{
										$$->value.v_bool = !($2->value.v_bool);
									}
								}
		  | expr LT expr 		{ 
									Trace("expr < expr ---> bool_expr");
									if($1->type == t_int && $3->type == t_int)
									{
										$$->value.v_bool = $1->value.v_int < $3->value.v_int;
									}
									else if($1->type == t_float && $3->type == t_float)
									{
										$$->value.v_bool = $1->value.v_float < $3->value.v_float;
									}
									else if($1->type == t_int && $3->type == t_float)
									{
										$$->value.v_bool = (float)$1->value.v_int < $3->value.v_float;
									}
									else if($1->type == t_float && $3->type == t_int)
									{
										$$->value.v_bool = $1->value.v_float < (float)$3->value.v_int;
									}
									else
									{
										yyerror("type error -> expr < expr");
									}
								}
		  | expr LTQ expr 		{ 
									Trace("expr <= expr ---> bool_expr");
									if($1->type == t_int && $3->type == t_int)
									{
										$$->value.v_bool = $1->value.v_int <= $3->value.v_int;
									}
									else if($1->type == t_float && $3->type == t_float)
									{
										$$->value.v_bool = $1->value.v_float <= $3->value.v_float;
									}
									else if($1->type == t_int && $3->type == t_float)
									{
										$$->value.v_bool = (float)$1->value.v_int <= $3->value.v_float;
									}
									else if($1->type == t_float && $3->type == t_int)
									{
										$$->value.v_bool = $1->value.v_float <= (float)$3->value.v_int;
									}
									else
									{
										yyerror("type error -> expr <= expr");
									}
								}
		  | expr GT expr 		{ 
									Trace("expr > expr ---> bool_expr");
									if($1->type == t_int && $3->type == t_int)
									{
										$$->value.v_bool = $1->value.v_int > $3->value.v_int;
									}
									else if($1->type == t_float && $3->type == t_float)
									{
										$$->value.v_bool = $1->value.v_float > $3->value.v_float;
									}
									else if($1->type == t_int && $3->type == t_float)
									{
										$$->value.v_bool = (float)$1->value.v_int > $3->value.v_float;
									}
									else if($1->type == t_float && $3->type == t_int)
									{
										$$->value.v_bool = $1->value.v_float > (float)$3->value.v_int;
									}
									else
									{
										yyerror("type error -> expr > expr");
									}
								}
		  | expr GTQ expr 		{ 
									Trace("expr >= expr ---> bool_expr");
									if($1->type == t_int && $3->type == t_int)
									{
										$$->value.v_bool = $1->value.v_int >= $3->value.v_int;
									}
									else if($1->type == t_float && $3->type == t_float)
									{
										$$->value.v_bool = $1->value.v_float >= $3->value.v_float;
									}
									else if($1->type == t_int && $3->type == t_float)
									{
										$$->value.v_bool = (float)$1->value.v_int >= $3->value.v_float;
									}
									else if($1->type == t_float && $3->type == t_int)
									{
										$$->value.v_bool = $1->value.v_float >= (float)$3->value.v_int;
									}
									else
									{
										yyerror("type error -> expr >= expr");
									}
								}
		  | expr EQ expr 		{ 
									Trace("expr == expr ---> bool_expr");
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
								}
	 	  | expr NEQ expr 		{ 
									Trace("expr != expr ---> bool_expr");
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
								}
		  | expr AND expr		{ 
									Trace("expr && expr ---> bool_expr");
									if($1->type != t_bool || $3->type != t_bool)
									{
										yyerror("type error -> expr && expr");
									}
									else
									{
										$$->value.v_bool = $1->value.v_bool && $3->value.v_bool;
									}
								}
		  | expr OR expr		{ 
									Trace("expr || expr ---> bool_expr");
									if($1->type != t_bool || $3->type != t_bool)
									{
										yyerror("type error -> expr || expr");
									}
									else
									{
										$$->value.v_bool = $1->value.v_bool || $3->value.v_bool;
									}
								};
dataType : INT		{
						$$ = t_int;
					}
		 | FLOAT	{
						$$ = t_float;
					}
		 | CHAR		{
						$$ = t_char;
					}
		 | STRING	{
						$$ = t_string;
					}
		 | BOOLEAN	{
						$$ = t_bool;
					};
values : T_INT		{
						Trace("T_INT ---> values");
						$$ = set_int($1);
					}
	   | T_FLOAT	{
						Trace("T_FLOAT ---> values");
						$$ = set_float($1);
					}
	   | T_CHAR		{
						Trace("T_CHAR ---> values");
						$$ = set_char($1);
					}
	   | T_STRING	{
						Trace("T_STRING ---> values");
						$$ = set_string(*$1);
					}
	   | T_BOOL		{
						Trace("T_BOOL ---> values");
						$$ = set_bool($1);
					};
%%

int main(int argc, char *argv[])
{
    // have a file or not
    if(argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;

    if(yyparse() == 1)
		yyerror("parsing error");

    table.dump();
	cout << "=============Parsing Success=============\n";

    return 0;
}