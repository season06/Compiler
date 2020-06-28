/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OBJECT = 258,
    CLASS = 259,
    DEF = 260,
    VAR = 261,
    VAL = 262,
    INT = 263,
    FLOAT = 264,
    CHAR = 265,
    STRING = 266,
    BOOLEAN = 267,
    TYPE = 268,
    _NULL = 269,
    TRUE = 270,
    FALSE = 271,
    FOR = 272,
    TO = 273,
    DO = 274,
    WHILE = 275,
    REPEAT = 276,
    BREAK = 277,
    CASE = 278,
    COUNTINUE = 279,
    EXIT = 280,
    RETURN = 281,
    IF = 282,
    ELSE = 283,
    PRINT = 284,
    PRINTLN = 285,
    READ = 286,
    T_INT = 287,
    T_FLOAT = 288,
    T_CHAR = 289,
    T_STRING = 290,
    T_BOOL = 291,
    ID = 292,
    OR = 293,
    AND = 294,
    LT = 295,
    LTQ = 296,
    GT = 297,
    GTQ = 298,
    EQ = 299,
    NEQ = 300,
    UMINUS = 301
  };
#endif
/* Tokens.  */
#define OBJECT 258
#define CLASS 259
#define DEF 260
#define VAR 261
#define VAL 262
#define INT 263
#define FLOAT 264
#define CHAR 265
#define STRING 266
#define BOOLEAN 267
#define TYPE 268
#define _NULL 269
#define TRUE 270
#define FALSE 271
#define FOR 272
#define TO 273
#define DO 274
#define WHILE 275
#define REPEAT 276
#define BREAK 277
#define CASE 278
#define COUNTINUE 279
#define EXIT 280
#define RETURN 281
#define IF 282
#define ELSE 283
#define PRINT 284
#define PRINTLN 285
#define READ 286
#define T_INT 287
#define T_FLOAT 288
#define T_CHAR 289
#define T_STRING 290
#define T_BOOL 291
#define ID 292
#define OR 293
#define AND 294
#define LT 295
#define LTQ 296
#define GT 297
#define GTQ 298
#define EQ 299
#define NEQ 300
#define UMINUS 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 45 "yacc.y" /* yacc.c:1909  */

	int v_int;
	float v_float;
	char v_char;
	string* v_string;
	bool v_bool;

	IDinfo* info;
	IDtype type;
	vector<IDinfo*>* funcCall;
#line 57 "yacc.y" /* yacc.c:1909  */

	struct {
		int beginLabel;
		int exitLable;
	} whileLoop;

#line 164 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
