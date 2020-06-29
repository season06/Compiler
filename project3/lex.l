%{
/****** C Declaration and include ******/
#include <iostream>
using namespace std;
#include "y.tab.hpp"

extern "C"
{
	int yylex();
	int yywrap();
}

#define LIST                    strcat(buf, yytext)
#define token(t)                {							\
                                    LIST;					\
									return t;				\
                                }

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
assign		'='
not			'!'
/* string */
/*string         \"[^\"]*\"*/
/*string_two     \"[^\"]*\"\"[^\"]*\"*/

/* comment */
line_comment        "//"[^\n]*|"\/\*".*"\*\/"

/* state */
%x S_STRING
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
boolean   { token(BOOLEAN); }
break     { token(BREAK); }
char      { token(CHAR); }
case      { token(CASE); }
class     { token(CLASS); }
continue  { token(COUNTINUE); }
def       { token(DEF); }
do        { token(DO); }
else      { token(ELSE); }
exit      { token(EXIT); }
false     { yylval.v_bool = false;
			token(T_BOOL); }
float     { token(FLOAT); }
for       { token(FOR); }
if        { token(IF); }
int       { token(INT); }
null      { token(_NULL); }
object    { token(OBJECT); }
print     { token(PRINT); }
println   { token(PRINTLN); }
repeat    { token(REPEAT); }
return    { token(RETURN); }
string    { token(STRING); }
to        { token(TO); }
true      { yylval.v_bool = true;
			token(T_BOOL); }
type      { token(TYPE); }
val       { token(VAL); }
var	      { token(VAR); }
while     { token(WHILE); }

","     { token(','); }
"."     { token('.'); }
";"     { token(';'); }
":"     { token(':'); }
"("     { token('('); }
")"     { token(')'); }
"["     { token('['); }
"]"     { token(']'); }
"{"     { token('{'); }
"}"     { token('}'); }

"+"     { token('+'); }
"-"     { token('-'); }
"*"     { token('*'); }
"/"     { token('/'); }
"%"     { token('%'); }

"<"     { token(LT); }
"<="    { token(LTQ); }
">="    { token(GTQ); }
">"     { token(GT); }
"=="    { token(EQ); }
"!="    { token(NEQ); }
"="     { token('='); }

"&&"    { token(AND); }
"||"    { token(OR); }
"!"     { token('!'); }


{integer}   {
				yylval.v_int = atoi(yytext);
				token(T_INT);
			}
{real}      {
				yylval.v_float = atof(yytext);
				token(T_FLOAT);
			}
{char}		{
				LIST;
				yylval.v_char = yytext[1];
				token(T_CHAR);
			}
{ID}        { 
				LIST;
				yylval.v_string = new string(yytext);
				token(ID);
			}

\"              {
                    LIST;
                    BEGIN(S_STRING);
                }
<S_STRING>\"\"  {
					strcat(tempStr, "\"");
					yymore();
                }
<S_STRING>\"    {
                    LIST;
					yylval.v_string = new string(tempStr);
					tempStr[0] = '\0';
					BEGIN(INITIAL);
					token(T_STRING);
                }
<S_STRING>\n    {
					LIST;
                	//printf("%d: %s\n", linenum, buf);
                	//printf("bad character:’%s’\n", "\"");
					BEGIN(INITIAL);
                	exit(-1);
                }
<S_STRING>.     {
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
