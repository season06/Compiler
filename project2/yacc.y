%{
#include <iostream>
#include "symbol.h"
using namespace std;

#define Trace(t)	cout << t << "\n";

extern "C"
{
	void yyerror(const char *s);
	extern int yylex();
	extern FILE* yyin();
}

void yyerror(string s)
{
	cout << s << "\n";
	exit(-1);
}

SymbolTables table = SymbolTables();

%}
/****** Definition of yytype *****/

// yacc lex shared variable
%union {
	int type;
	int v_int;
	float v_float;
	char v_char;
	string v_string;
	bool v_bool;
	// for temp value
	map<string, IDinfo*> func_args;
	IDinfo *idinfo;
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

// declare the type of semantic value for nonterminal
%type <func_args> funcArgs
%type <idinfo> funcBlock optionType returnState
%type <idinfo> dataType values;
%type <idinfo> expr bool_expr;

%%
//////////////////////// object ////////////////////////
program : OBJECT ID {
						Trace("create object table");
						Symbol now = table.list[table.size];
						int t = now.insert_init($2, $2.type, IDscope::s_object);
						if(t == -1)
							yyerror("ID has been declared");
						table.push_table();
					}
		  objBlock 	{
						Trace("object ID objBlock ---> program");
					}
objBlock : '{'				{ 
								table.push_table();
							}
		   objContent '}'	{ 	
								table.dump();
								table.pop_table();
							}

objContent : funcDecs objContent
 		   | declarations blockContent
		   | stats blockContent
		   | funcDecs
		   | declarations
		   | stats
//////////////////////// function ////////////////////////
// def id ( <formal argu> ) <:type>
funcDecs : funcDec funcDecs
		 | funcDec

funcDec : DEF ID 								{
													Trace("create function table");
													Symbol now = table.list[table.size];
													int t = now.insert_init($2, $2.type, IDscope::s_function);
													if(t == -1)
														yyerror("ID has been declared");
													table.push_table();
												}
		  '(' funcArgs ')' optionType funcBlock {
													Trace("def ID (funcArgs) type funcBlock ---> funcDec");
													Symbol now = table.list[table.size];
													//now.insert_funcArgs($2, $4);
													now.idmap[$2].return_value = $7;
													table.dump();
													table.pop_table();
												}
funcBlock : '{' 								
			blockContent returnState '}'		{
													Trace("{blockContent returnState} ---> funcBlock");
													$$ = $3;
												}

funcArgs : ID ':' dataType 						{
													Trace("ID:type ---> funcArgs");
													IDinfo tmp;
													tmp.id = $1; tmp.type = $3;
													$$[$1] = tmp;
												}
		 | funcArgs ',' ID ':' dataType 			{
													Trace("funcArgs, ID:type ---> funcArgs");
													if($1.func_args($3) != $1.end())
														yyerror("ID has been declared in function");
													IDinfo tmp;
													tmp.id = $3; tmp.type = $5;
													$$[$3] = tmp;
												}
		 | %empty 								{	Trace("function Argument is empty"); }

optionType : ':' dataType 						{
													$$ = $2;
												}
		   | %empty 							{	Trace("function datatype is empty"); }

returnState : RETURN expr ';'					{
													Trace("return expr ---> returnState");
													$$ = $2;
												}
	 		| RETURN ';'						{
													Trace("return ---> returnState");
													$$ = IDvalue value;
												}

////////////////////////  declaration ////////////////////////
declarations : declaration declarations
			 | declaration

declaration : varDeclare
			| constDeclare
			| arrDeclare
// val id <:type> = constant
// var id <:type> <=constant>
// var id : type [num]
varDeclare : VAR ID ':' dataType '=' expr 	{
												Trace("var id : type = expr ---> declaration");
												if($4 != $6.type)
													yyerror("type error -> dataType and expr");
												Symbol now = table.list[table.size];
												int t = now.insert_init($2, $6.type, IDscope::s_variable, $6);
												if(t == -1)
													yyerror("ID has been declared");
											}
		   | VAR ID '=' expr 				{
												Trace("var id = expr ---> declaration");
												Symbol now = table.list[table.size];
												int t = now.insert_init($2, $4.type, IDscope::s_variable, $4);
												if(t == -1)
													yyerror("ID has been declared");
											}
		   | VAR ID ':' dataType 			{
												Trace("var id : type ---> declaration");
												Symbol now = table.list[table.size];
												int t = now.insert($2, $4.type, IDscope::s_variable);
												if(t == -1)
													yyerror("ID has been declared");
											}
		   | VAR ID 						{
												Trace("var id ---> declaration");
												Symbol now = table.list[table.size];
												int t = now.insert($2, $2.type, IDscope::s_variable);
												if(t == -1)
													yyerror("ID has been declared");
											}

constDeclare : VAL ID ':' dataType '=' expr	{
												Trace("val id : type = expr ---> declaration");
												if($4 != $6.type)
													yyerror("type error -> dataType and expr");
												Symbol now = table.list[table.size];
												int t = now.insert_init($2, $6.type, IDscope::s_const, $6);
												if(t == -1)
													yyerror("ID has been declared");
											}
		 	 | VAL ID '=' expr				{
												Trace("val id = expr ---> declaration");
												Symbol now = table.list[table.size];
												int t = now.insert_init($2, $4.type, IDscope::s_const, $4);
												if(t == -1)
													yyerror("ID has been declared");
											}

arrDeclare : VAR ID ':' dataType '[' T_INT ']'	{
													Trace("val id : type [ expr ] ---> declaration");
													Symbol now = table.list[table.size];
													int t = now.insert_arr($2, $4.type, IDscope::s_array, $6.v_int);
													if(t == -1)
														yyerror("ID has been declared");
												}
//////////////////////// statement ////////////////////////
stats : stat stats
	  | stat
stat : ID '=' expr ';'				{
										Trace("ID[expr] ---> stat");
										IDinfo *id = table.lookup($1);
										if(id == NULL)
											yyerror("ID not found");
									}
	 | ID '[' expr ']' '=' expr ';'	{
										Trace("ID[expr] ---> stat");
										IDinfo *id = table.lookup($1);
										if(id == NULL)
											yyerror("ID not found");
									}
	 | PRINT expr ';'			{
									Trace("print ---> stat");
								}
	 | PRINTLN expr ';'			{
									Trace("println ---> stat");
								}
	 | READ ID ';'				{
									Trace("read ID ---> stat");
								}
	 | ifStat					{
									Trace("ifStat ---> stat");
								}
	 | loopStat					{
									Trace("loopStat ---> stat");
								}
	 | block					{
									Trace("block ---> stat");
								}
ifStat : IF '(' bool_expr ')' 	
		 block elseStat			{
									Trace("IF (bool_expr) block elseStat ---> ifStat");
								}
elseStat : ELSE					
		   block				{
									Trace("else block ---> elseStat");
								}
		 | %empty				{	Trace("elseState is empty"); }

loopStat : WHILE '(' bool_expr ')' 				
		   block								{
													Trace("WHILE (bool_expr) block ---> loopStat");
												}
		 | FOR '(' ID LT '-' expr TO expr ')' 	
		   block								{
													Trace("for (id <- expr to expr) block ---> loopStat");
												}


block : '{' 				{
								Trace("create block table");
								table.push_table();
							}
		blockContent '}' 	{
								Trace("{blockContent} ---> block");
								table.dump();
								table.pop_table();
							}
blockContent : declarations blockContent
			 | stats blockContent
			 | declarations
			 | stats
		 	 | %empty
//////////////////////// expression ////////////////////////
expr : '(' expr ')' 		{
								Trace("(expr) ---> expr");
								$$ = $2;
							}
	 | expr '+' expr 		{ 
								Trace("expr + expr ---> expr");
								if($1.type == t_int && $3.type == t_int)
								{
									$$.type = t_int;
									$$.v_int = $1.v_int + $3.v_int;
								}
								else if($1.type == t_float && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float + $3.v_float;
								}
								else if($1.type == t_int && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = (float)$1.v_int + $3.v_float;
								}
								else if($1.type == t_float && $3.type == t_int)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float + (float)$3.v_int;
								}
								else
								{
									yyerror("type error -> expr + expr");
								}
							}
	 | expr '-' expr  		{ 
								Trace("expr - expr ---> expr");
								if($1.type == t_int && $3.type == t_int)
								{
									$$.type = t_int;
									$$.v_int = $1.v_int - $3.v_int;
								}
								else if($1.type == t_float && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float - $3.v_float;
								}
								else if($1.type == t_int && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = (float)$1.v_int - $3.v_float;
								}
								else if($1.type == t_float && $3.type == t_int)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float - (float)$3.v_int;
								}
								else
								{
									yyerror("type error -> expr - expr");
								}
							}
	 | expr '*' expr  		{ 
								Trace("expr * expr ---> expr");
								if($1.type == t_int && $3.type == t_int)
								{
									$$.type = t_int;
									$$.v_int = $1.v_int * $3.v_int;
								}
								else if($1.type == t_float && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float * $3.v_float;
								}
								else if($1.type == t_int && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = (float)$1.v_int * $3.v_float;
								}
								else if($1.type == t_float && $3.type == t_int)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float * (float)$3.v_int;
								}
								else
								{
									yyerror("type error -> expr * expr");
								}
							}
	 | expr '/' expr  		{ 
								Trace("expr / expr ---> expr");
								if($1.type == t_int && $3.type == t_int)
								{
									$$.type = t_int;
									$$.v_int = $1.v_int / $3.v_int;
								}
								else if($1.type == t_float && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float / $3.v_float;
								}
								else if($1.type == t_int && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = (float)$1.v_int / $3.v_float;
								}
								else if($1.type == t_float && $3.type == t_int)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float / (float)$3.v_int;
								}
								else
								{
									yyerror("type error -> expr / expr");
								}
							}
	 | expr '%' expr  		{ 
								Trace("expr % expr ---> expr");
								if($1.type == t_int && $3.type == t_int)
								{
									$$.type = t_int;
									$$.v_int = $1.v_int % $3.v_int;
								}
								else if($1.type == t_float && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float % $3.v_float;
								}
								else if($1.type == t_int && $3.type == t_float)
								{
									$$.type = t_float;
									$$.v_float = (float)$1.v_int % $3.v_float;
								}
								else if($1.type == t_float && $3.type == t_int)
								{
									$$.type = t_float;
									$$.v_float = $1.v_float % (float)$3.v_int;
								}
								else
								{
									yyerror("type error -> expr % expr");
								}
							}
	 | '-' expr %prec UMINUS 	{ 
									Trace("- expr ---> expr");
									if($2.type == t_int)
									{
										$$.v_int = -1 * $2.v_int;
									}
									else if($2.type == t_float)
									{
										$$.v_float = -1 * $2.v_float;
									}
									else
									{
										yyerror("type error -> - expr");
									}
								}
	 | bool_expr 				{
									Trace("bool_expr ---> expr");
									$$ = $1;
								}
	 | ID'[' expr ']' 			{
									Trace("ID[expr] ---> expr");
									IDinfo *id = table.lookup($1);
									if(id == NULL)
										yyerror("ID not found");
									if(id->scope != IDscope::s_array)
										yyerror("ID type is not array, can't use []");
									if($3.type != IDtype::t_int)
										yyerror("Arrey index not integer");
									if($3.v_int > id->arr_size || $3.v_int < 0)
										yyerror("Arrey index out of range");
									$$ = id->arr_value[$3.v_int];
								}
	 | ID'(' parameter ')' 		{
									Trace("ID(parameter) ---> expr");
									IDinfo *id = table.lookup($1);
									if(id == NULL)
										yyerror("ID not found");
									if(id->scope != IDscope::s_function)
										yyerror("ID type is not function, can't use ()");

									
								}
	 | ID 						{
									Trace("ID ---> expr");
									IDinfo *id = table.lookup($1);
									if(id == NULL)
										yyerror("ID not found");
									$$ = id->value
								}
	 | values 					{
									Trace("values ---> expr");
									$$ = $1;
								}

bool_expr : '!' expr 			{ 
									Trace("! expr ---> bool_expr");
									if($2.type != t_bool)
									{
										yyerror("type error -> ! expr");
									}
									else
									{
										$$.v_bool = !($2.v_bool);
									}
								}
		  | expr LT expr 		{ 
									Trace("expr < expr ---> bool_expr");
									if($1.type == t_int && $3.type == t_int)
									{
										$$.v_bool = $1.v_int < $3.v_int;
									}
									else if($1.type == t_float && $3.type == t_float)
									{
										$$.v_bool = $1.v_float < $3.v_float;
									}
									else if($1.type == t_int && $3.type == t_float)
									{
										$$.v_bool = (float)$1.v_int < $3.v_float;
									}
									else if($1.type == t_float && $3.type == t_int)
									{
										$$.v_bool = $1.v_float < (float)$3.v_int;
									}
									else
									{
										yyerror("type error -> expr < expr");
									}
								}
		  | expr LTQ expr 		{ 
									Trace("expr <= expr ---> bool_expr");
									if($1.type == t_int && $3.type == t_int)
									{
										$$.v_bool = $1.v_int <= $3.v_int;
									}
									else if($1.type == t_float && $3.type == t_float)
									{
										$$.v_bool = $1.v_float <= $3.v_float;
									}
									else if($1.type == t_int && $3.type == t_float)
									{
										$$.v_bool = (float)$1.v_int <= $3.v_float;
									}
									else if($1.type == t_float && $3.type == t_int)
									{
										$$.v_bool = $1.v_float <= (float)$3.v_int;
									}
									else
									{
										yyerror("type error -> expr <= expr");
									}
								}
		  | expr GT expr 		{ 
									Trace("expr > expr ---> bool_expr");
									if($1.type == t_int && $3.type == t_int)
									{
										$$.v_bool = $1.v_int > $3.v_int;
									}
									else if($1.type == t_float && $3.type == t_float)
									{
										$$.v_bool = $1.v_float > $3.v_float;
									}
									else if($1.type == t_int && $3.type == t_float)
									{
										$$.v_bool = (float)$1.v_int > $3.v_float;
									}
									else if($1.type == t_float && $3.type == t_int)
									{
										$$.v_bool = $1.v_float > (float)$3.v_int;
									}
									else
									{
										yyerror("type error -> expr > expr");
									}
								}
		  | expr GTQ expr 		{ 
									Trace("expr >= expr ---> bool_expr");
									if($1.type == t_int && $3.type == t_int)
									{
										$$.v_bool = $1.v_int >= $3.v_int;
									}
									else if($1.type == t_float && $3.type == t_float)
									{
										$$.v_bool = $1.v_float >= $3.v_float;
									}
									else if($1.type == t_int && $3.type == t_float)
									{
										$$.v_bool = (float)$1.v_int >= $3.v_float;
									}
									else if($1.type == t_float && $3.type == t_int)
									{
										$$.v_bool = $1.v_float >= (float)$3.v_int;
									}
									else
									{
										yyerror("type error -> expr >= expr");
									}
								}
		  | expr EQ expr 		{ 
									Trace("expr == expr ---> bool_expr");
									if($1.type == t_int && $3.type == t_int)
									{
										$$.v_bool = $1.v_int == $3.v_int;
									}
									else if($1.type == t_float && $3.type == t_float)
									{
										$$.v_bool = $1.v_float == $3.v_float;
									}
									else if($1.type == t_char && $3.type == t_char)
									{
										$$.v_bool = $1.v_char == $3.v_char;
									}
									else if($1.type == t_string && $3.type == t_string)
									{
										$$.v_bool = $1.v_string == $3.v_string;
									}
									else if($1.type == t_bool && $3.type == t_bool)
									{
										$$.v_bool = $1.v_bool == $3.v_bool;
									}
									else
									{
										yyerror("type error -> expr == expr");
									}
								}
	 	  | expr NEQ expr 		{ 
									Trace("expr != expr ---> bool_expr");
									if($1.type == t_int && $3.type == t_int)
									{
										$$.v_bool = $1.v_int != $3.v_int;
									}
									else if($1.type == t_float && $3.type == t_float)
									{
										$$.v_bool = $1.v_float != $3.v_float;
									}
									else if($1.type == t_char && $3.type == t_char)
									{
										$$.v_bool = $1.v_char != $3.v_char;
									}
									else if($1.type == t_string && $3.type == t_string)
									{
										$$.v_bool = $1.v_string != $3.v_string;
									}
									else if($1.type == t_bool && $3.type == t_bool)
									{
										$$.v_bool = $1.v_bool != $3.v_bool;
									}
									else
									{
										yyerror("type error -> expr != expr");
									}
								}
		  | expr AND expr		{ 
									Trace("expr && expr ---> bool_expr");
									if($1.type != t_bool || $3.type != t_bool)
									{
										yyerror("type error -> expr && expr");
									}
									else
									{
										$$.v_bool = $1.v_bool && $3.v_bool;
									}
								}
		  | expr OR expr		{ 
									Trace("expr || expr ---> bool_expr");
									if($1.type != t_bool || $3.type != t_bool)
									{
										yyerror("type error -> expr || expr");
									}
									else
									{
										$$.v_bool = $1.v_bool || $3.v_bool;
									}
								}

parameter : expr ',' parameter	{
									Trace("expr, parameter ---> function parameter");
								}
		  | expr ',' expr		{
									Trace("expr, expr ---> function parameter");
								}
		  | %empty				{	Trace("function parameter is empty");	}

dataType : INT		{
						$$ = IDtype::t_int;
					}
		 | FLOAT	{
						$$ = IDtype::t_float;
					}
		 | CHAR		{
						$$ = IDtype::t_char;
					}
		 | STRING	{
						$$ = IDtype::t_string;
					}
		 | BOOLEAN	{
						$$ = IDtype::t_bool;
					}
values : T_INT		{
						Trace("int value");
						$$.type = IDtype::t_int;
						$$.v_int = $1;
					}
	   | T_FLOAT	{
						Trace("float value");
						$$.type = IDtype::t_float;
						$$.v_float = $1;
					}
	   | T_CHAR		{
						Trace("char value");
						$$.type = IDtype::t_char;
						$$.v_char = $1;
					}
	   | T_STRING	{
						Trace("string value");
						$$.type = IDtype::t_string;
						$$.v_string = $1;
					}
	   | T_BOOL		{
						Trace("bool value");
						$$.type = IDtype::t_bool;
						$$.v_bool = $1;
					}
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

    table.dump();             	// print symbol table
	cout << "parsing success\n";

    return 0;
}











