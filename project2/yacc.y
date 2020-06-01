%{
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define Trace(t)	cout << t << "\n";

extern "C" {
	int yyerror(const char *s)
	extern int yylex();
	extern int yylineno;
	extern FILE* yyin;
}

enum TokenType {
	t_int,
	t_float,
	t_string,
	t_bool,
	t_unknown
};

typedef union {
	
}

%}
/****** Definition of yytype *****/

// yacc lex shared variable
// token
%union {
	typedef struct {
		int type;
		union {
			int v_int;
			float v_float;
			bool v_bool;
			char* v_str;
			
		};
	}token;
}

// declare a terminal
%token OBJECT CLASS DEF
%token VAR VAL INT FLOAT CHAR STRING BOOLEAN
%token TYPE NULL TRUE FALSE
%token FOR TO DO WHILE REPEAT
%token BREAK CASE COUNTINUE EXIT RETURN
%token IF ELSE
%token PRINT PRINTLN
%token <token> T_INT T_REAL T_STRING
%token <token> ID

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
%type <token> valDec, varDec, arrDec;
%type <token> dataType;
%type <token> func;
%type <token> funcArgs, parameter;
%type <token> expr, state;

%%
program : OBJECT ID declarations funcDecs {}
		| OBJECT ID funcDecs {}

////////////// function //////////////
// object ID {}
// def id ( <formal argu> ) <:type>
funcDecs : funcDec funcDecs {}
		 | funcDec {}

funcDec : DEF ID '(' funcArgs ')' ':' ID_type funcScope {}
		| DEF ID '(' funcArgs ')' funcScope {}

funcArgs : ID ':' ID_type
		  | funcArgs ',' ID ':' ID_type
		  | %empty

funcScope : '{' socpeContent '}' {}
scopeContent : 

//////////////  declaration //////////////
declarations : declaration declarations {}
			 | declaration {}

declaration : varDec {}
			| constDec {}
			| arrDec {}
// val id <:type> = constant
// var id <:type> <=constant>
// var id : type [num]
varDec : VAR ID ':' dataType '=' expr ';' {}
	   | VAR ID '=' expr ';' {}
	   | VAR ID ':' dataType ';' {}
	   | VAR ID ';' {}

constDec : VAL ID ':' dataType '=' expr ';' {}
		 | VAL ID '=' expr ';' {}

arrDec : VAL ID ':' dataType '[' expr ']' ';' {}
    
dataType : INT		{
						$$ = $1;
						$$.type = t_int;
					}
		 | FLOAT		{
						$$ = $1;
						$$.type = t_float;
					}
		 | CHAR		{
						$$ = $1;
						$$.type = t_string;
					}
		 | STRING		{
						$$ = $1;
						$$.type = t_string;
					}
		 | BOOLEAN	{
						$$ = $1;
						$$.type = t_bool;
					}

////////////// statement //////////////
states : state states {}
	   | state {}
state : ID '=' expr ';' {}
	  | ID '[' expr ']' '=' EXPR ';' {}
	  | PRINT '(' expr ')' ';' {}
	  | PRINTLN '(' expr ')' ';' {}
	  | RETURN expr ';' {}
	  | RETURN ';' {}
	  | READ ID ';' {}
	  | ifState {}
	  | loopState {}
	  | block {}

ifState : IF '(' bool_expr ')' {} ELSE STATE {}
		| IF '(' bool_expr ')' {}

loopState : WHILE '(' bool_expr ')' {}
		  | FOR '(' ID "<-" expr TO expr ')' {}

block : '{' scopeContent '}' {}

////////////// expression //////////////
expr : '(' expr ')' { $$ = $2; }
	 | expr '+' expr { $$ = $1 + $3; }
	 | expr '-' expr { $$ = $1 - $3; }
	 | expr '*' expr { $$ = $1 * $3; }
	 | expr '/' expr { $$ = $1 / $3; }
	 | expr '%' expr { $$ = $1 % $3; }
	 | '-' expr %prec UMINUS { $$ = -1 * $2; }
	 | bool_expr {}
	 | ID'[' expr ']' {}
	 | ID'(' parameter ')' {}
	 | ID {}
	 | T_INT {}
	 | T_REAL {}
	 | T_STRING {}

bool_expr : TRUE {}
		  | FALSE {}
		  | '!' expr { $$ = !($2); }
		  | expr LT expr { $$ = $1 < $3; }
		  | expr LTQ expr { $$ = $1 <= $3; }
		  | expr GT expr { $$ = $1 > $3; }
		  | expr GTQ expr { $$ = $1 >= $3; }
		  | expr EQ expr { $$ = $1 == $3; }
	 	  | expr NEQ expr { $$ = $1 != $3; }
		  | expr AND expr { $$ = $1 && $3; }
		  | expr OR expr { $$ = $1 || $3; }

parameter : expr ',' expr
		  | expr
		  | %empty

%%













