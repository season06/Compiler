%{
/****** C Declaration and include ******/
#include <iostream>
#include <string>
using namespace std;
#include "y.tab.h"

extern "C"
{
	int yylex();
	int yywrap();
}

#define LIST                    strcat(buf, yytext)
#define MAX_LINE_LENG 1024

int linenum = 1;
char buf[MAX_LINE_LENG];
int start_str = 0;
char tempStr[MAX_LINE_LENG];
%}

/****** Definition: <name> <regexp> ******/
alphabat    [_A-Za-z]
alphabats   [_A-Za-z]+
dig         [0-9]
digs        [0-9]+
integer     {digs}
plain_real  {digs}"."{digs}
expreal     {digs}"."{digs}[Ee][+-]?{digs}
real        [+-]?({plain_real}|{expreal})

boolean     true|false

ID          {alphabat}({alphabat}|{dig})*

char		'([^'\\\n]|\\.)'
delimiter 	[,:\.;()\[\]\{\}]
arithmetic	[\+\-\*/%]
assign		[=\]
not			'!'
/* string */
/*string         \"[^\"]*\"*/
/*string_two     \"[^\"]*\"\"[^\"]*\"*/

/* comment */
line_comment        "//"[^\n]*|"\/\*".*"\*\/"

/* state */
%x STRING
%x COMMENT

/****** <regexp> <action> ******/
/* yytext: match lexeme */
/* yyleng: length of the lexeme */
/* yylval: hold the lexical value of the token */
/* yywarp(): called by lexical analyzer if end of the input file */
/* yyless(n): n character in yytext are retained */
/* yymore(): next input recognized is to be tacked on the end of this input */
/* c = input(): read another character */
/* unput(c): put a character back to be read again a moment later */
/* output(c): write a character on an output device */
%%
boolean   { LIST; return BOOLEAN; }
break     { LIST; return BREAK; }
char      { LIST; return CHAR; }
case      { LIST; return CASE; }
class     { LIST; return CLASS; }
continue  { LIST; return COUNTINUE; }
def       { LIST; return DEF; }
do        { LIST; return DO; }
else      { LIST; return ELSE; }
exit      { LIST; return EXIT; }
false     { yylval.v_bool = false
			LIST; return T_BOOL; }
float     { LIST; return FLOAT; }
for       { LIST; return FOR; }
if        { LIST; return IF; }
int       { LIST; return INT; }
null      { LIST; return _NULL; }
object    { LIST; return OBJECT; }
print     { LIST; return PRINT; }
println   { LIST; return PRINTLN; }
read	  { LIST; return READ; }
repeat    { LIST; return REPEAT; }
return    { LIST; return RETURN; }
string    { LIST; return STRING; }
to        { LIST; return TO; }
true      { yylval.v_bool = true
			LIST; return T_BOOL; }
type      { LIST; return TYPE; }
val       { LIST; return VAL; }
var	      { LIST; return VAR; }
while     { LIST; return WHILE; }

{delimiter} { LIST; return *yytext; }
{arithmetic} { LIST; return *yytext; )

"<" 	    { LIST; return LT; }
"<="    	{ LIST; return LTQ; }
">="    	{ LIST; return GTQ; }
">"     	{ LIST; return GT; }
"=="    	{ LIST; return EQ; }
"!="		{ LIST; return NEQ; }
{assign}	{ LIST; return *yytext; }

"&&"    	{ LIST; return AND; }
"||"    	{ LIST; return OR; }
{not}		{ LIST; return *yytext; }

{integer}   {
				yylval.v_int = atoi(yytext);
				return T_INT;
			}
{real}      {
				yylval.v_float = atof(yytext);
				return T_FLOAT;
			}
{char}		{
				LIST; 
				yylval.v_char = yytext[1];
				return T_CHAR;
			}
{ID}        { 
				LIST; 
				yylval.v_string = new string(yytext);
				return ID;
			}

\"              {
                    LIST;
                    BEGIN(STRING);
                }
<STRING>\"\"    {
					strcat(tempStr, "\"");
					yymore();
                }
<STRING>\"      {
                    LIST;
					yylval.v_string = new string(tempStr);
					BEGIN(INITIAL);
					return T_STRING;
                }
<STRING>\n      {
					LIST;
                	//printf("%d: %s\n", linenum, buf);
                	//printf("bad character:’%s’\n", "\"");
					BEGIN(INITIAL);
                	exit(-1);
                }
<STRING>.       {
                    strcat(tempStr, &yytext[yyleng-1]);
					yymore();
                }

{line_comment}  { LIST; }
"/*"			{ LIST; BEGIN(COMMENT); }
<COMMENT>"*/"	{
                 	LIST;
                    BEGIN(INITIAL);
                }
<COMMENT>\n     {
                 	LIST;
                    //printf("%d: %s", linenum++, buf);
                    buf[0] = '\0';
                }
<COMMENT>.		{ LIST; }

[ \t]*      { LIST; }

\n|\r\n     {
                LIST;
                //printf("%d: %s", linenum++, buf);
                buf[0] = '\0';
            }

.           {
                LIST;
                //printf("%d: %s\n", linenum, buf);
                //printf("bad character:’%s’\n", yytext);
                exit(-1);
            }

%%

/****** User Subroutines (C) ******/

int yywrap()
{
	return 1;
}
