%{
/****** C Declaration and include ******/
#include <stdio.h>
#include <stdlib.h>
#include "symbol.c"
#include "y.tab.h"

#define LIST                    strcat(buf, yytext)
#define token(t)                {										\
                                    LIST;								\
                                    printf("<%s>\n", t);				\
									return t;							\
                                }
#define tokenInteger(type, val) {										\
                                    LIST;								\
                                    printf("<%s: %d>\n", type, val);	\
									return type;						\
                                }
#define tokenFloat(type, val)   {										\
                                    LIST;								\
                                    printf("<%s: %f>\n", type, val);	\
									return type;						\
                                }
#define tokenString(type, val)  {										\
                                    printf("<%s: %s>\n", type, val);	\
									tempStr[0] = '\0';					\
									return type;						\
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
boolean   { token("BOOLEAN"); }
break     { token("BREAK"); }
char      { token("CHAR"); }
case      { token("CASE"); }
class     { token("CLASS"); }
continue  { token("COUNTINUE"); }
def       { token("DEF"); }
do        { token("DO"); }
else      { token("ELSE"); }
exit      { token("EXIT"); }
false     { token("FALSE"); }
float     { token("FLOAT"); }
for       { token("FOR"); }
if        { token("IF"); }
int       { token("INT"); }
null      { token("NULL"); }
object    { token("OBJECT"); }
print     { token("PRINT"); }
println   { token("PRINTLN"); }
repeat    { token("REPEAT"); }
return    { token("RETURN"); }
string    { token("STRING"); }
to        { token("TO"); }
true      { token("TRUE"); }
type      { token("TYPE"); }
val       { token("VAL"); }
var	      { token("VAR"); }
while     { token("WHILE"); }

","     { token(","); }
"."     { token("."); }
";"     { token(";"); }
":"     { token(":"); }
"("     { token("("); }
")"     { token(")"); }
"["     { token("["); }
"]"     { token("]"); }
"{"     { token("{"); }
"}"     { token("}"); }

"+"     { token("+"); }
"-"     { token("-"); }
"*"     { token("*"); }
"/"     { token("/"); }
"%"     { token("%"); }

"<"     { token("LT"); }
"<="    { token("LTQ"); }
">="    { token("GTQ"); }
">"     { token("GT"); }
"=="    { token("EQ"); }
"!="    { token("NEQ"); }
"="     { token("="); }

"&&"    { token("AND"); }
"||"    { token("OR"); }
"!"     { token("!"); }

{integer}   {
				yylval.token.v_int = atoi(yytext);
				tokenInteger("T_INT", atoi(yytext));
			}
{real}      {
				yylval.token.v_float = atof(yytext);
				tokenFloat("T_REAL", atof(yytext));
			}
{ID}        { 
				LIST; 
				insert(TABLE, yytext); 
				tokenString("T_ID", yytext);
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
					yylval.token.v_string = strdup(tempStr);
                    tokenString("T_STRING", tempStr);
					BEGIN(INITIAL);
                }
<STRING>\n      {
					LIST;
                	printf("%d: %s\n", linenum, buf);
                	printf("bad character:’%s’\n", "\"");
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
                    printf("%d: %s", linenum++, buf);
                    buf[0] = '\0';
                }
<COMMENT>.		{ LIST; }

[ \t]*      { LIST; }

\n|\r\n     {
                LIST;
                printf("%d: %s", linenum++, buf);
                buf[0] = '\0';
            }

.           {
                LIST;
                printf("%d: %s\n", linenum, buf);
                printf("bad character:’%s’\n", yytext);
                exit(-1);
            }

%%

/****** User Subroutines (C) ******/

int main(int argc, char *argv[])
{
    // have a file or not
    if(argc > 1)
        yyin = fopen(argv[1], "r");
    else
        yyin = stdin;

    TABLE = create(NOW);	// create symbol table
    yylex();				// start analysis
    dump();             	// print symbol table

    return 0;
}
int yywrap()
{
	return 1;
}
