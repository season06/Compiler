/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */

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


#line 108 "y.tab.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.hpp".  */
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
#line 45 "yacc.y" /* yacc.c:355  */

	int v_int;
	float v_float;
	char v_char;
	string* v_string;
	bool v_bool;

	IDinfo* info;
	IDtype type;
	vector<IDinfo*>* funcCall;
#line 57 "yacc.y" /* yacc.c:355  */

	struct {
		int beginLabel;
		int exitLable;
	} whileLoop;

#line 258 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 275 "y.tab.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   260

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  99
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  180

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,     2,     2,    51,     2,     2,
      55,    56,    49,    47,    57,    48,     2,    50,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,     2,
       2,    59,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    60,     2,    61,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    41,    42,    43,    44,    45,
      46,    52
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   102,   102,   102,   127,   128,   129,   133,   134,   136,
     149,   136,   202,   205,   208,   210,   223,   226,   229,   236,
     244,   244,   287,   288,   290,   293,   297,   302,   303,   305,
     326,   343,   343,   358,   358,   373,   376,   379,   382,   385,
     389,   389,   402,   402,   413,   416,   421,   416,   434,   434,
     442,   442,   444,   444,   453,   454,   457,   458,   461,   462,
     464,   472,   501,   528,   547,   567,   567,   582,   582,   596,
     600,   616,   632,   648,   664,   680,   696,   700,   714,   717,
     752,   757,   772,   781,   790,   799,   808,   837,   866,   883,
     900,   903,   906,   909,   912,   915,   925,   929,   933,   943
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OBJECT", "CLASS", "DEF", "VAR", "VAL",
  "INT", "FLOAT", "CHAR", "STRING", "BOOLEAN", "TYPE", "_NULL", "TRUE",
  "FALSE", "FOR", "TO", "DO", "WHILE", "REPEAT", "BREAK", "CASE",
  "COUNTINUE", "EXIT", "RETURN", "IF", "ELSE", "PRINT", "PRINTLN", "READ",
  "T_INT", "T_FLOAT", "T_CHAR", "T_STRING", "T_BOOL", "ID", "OR", "AND",
  "'!'", "LT", "LTQ", "GT", "GTQ", "EQ", "NEQ", "'+'", "'-'", "'*'", "'/'",
  "'%'", "UMINUS", "'{'", "'}'", "'('", "')'", "','", "':'", "'='", "'['",
  "']'", "$accept", "program", "$@1", "objContent", "funcDecs", "funcDec",
  "$@2", "$@3", "args", "arg", "returnType", "returnVal", "function_invoc",
  "$@4", "parameters", "parameter", "para", "stats", "stat", "$@5", "$@6",
  "ifStat", "$@7", "elseStat", "$@8", "loopStat", "$@9", "$@10", "$@11",
  "block_or_stat", "block", "$@12", "blockContent", "declarations",
  "declaration", "varDeclare", "constDeclare", "$@13", "$@14", "expr",
  "bool_expr", "dataType", "values", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
      33,   295,   296,   297,   298,   299,   300,    43,    45,    42,
      47,    37,   301,   123,   125,    40,    41,    44,    58,    61,
      91,    93
};
# endif

#define YYPACT_NINF -154

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-154)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      31,   -36,     4,  -154,  -154,   -42,     8,    12,    15,    30,
      14,     8,    68,     8,    48,  -154,  -154,  -154,    -2,     1,
    -154,  -154,  -154,  -154,  -154,    20,   243,   119,   243,  -154,
      43,  -154,  -154,  -154,  -154,  -154,     3,  -154,  -154,  -154,
    -154,  -154,   -48,   119,   119,   119,  -154,   175,  -154,  -154,
      25,   119,    27,    32,    29,   119,    60,   119,    38,   199,
    -154,   143,   119,   119,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,  -154,   175,   243,    36,    43,
     175,    34,    78,   119,  -154,   188,   199,   209,   209,   209,
     209,   209,   209,   -18,   -18,  -154,  -154,  -154,   119,  -154,
     243,  -154,  -154,  -154,  -154,    42,  -154,    45,   175,   175,
    -154,    50,  -154,   119,    70,  -154,    49,  -154,   119,    51,
    -154,  -154,    74,     5,  -154,  -154,  -154,   146,  -154,  -154,
      61,    70,    77,    75,   175,   119,   119,   119,  -154,   119,
     119,  -154,  -154,  -154,    90,   119,   175,    79,   175,   175,
     175,    99,    85,   159,  -154,    98,   102,  -154,    52,   119,
     118,    52,  -154,  -154,   130,  -154,   175,   129,  -154,    70,
    -154,  -154,   106,   110,    52,  -154,  -154,  -154,    52,  -154
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,     0,     0,
       0,     6,     8,     6,    57,    58,    59,     9,    64,     0,
       3,     4,     7,     5,    56,     0,     0,     0,     0,    67,
      14,    90,    91,    92,    93,    94,    63,    95,    96,    97,
      98,    99,    79,     0,     0,     0,    78,    62,    76,    80,
       0,     0,     0,     0,    13,     0,     0,     0,     0,    81,
      70,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    65,    68,     0,    17,    14,
      61,     0,     0,    23,    69,    89,    88,    82,    83,    84,
      85,    86,    87,    71,    72,    73,    74,    75,     0,    15,
       0,    10,    12,    60,    77,     0,    22,    25,    26,    66,
      16,     0,    21,     0,    28,    24,     0,    45,    19,     0,
      31,    33,     0,    20,    36,    39,    55,    28,    37,    38,
       0,    28,     0,     0,    18,     0,     0,     0,    35,     0,
       0,    27,    11,    54,     0,     0,     0,    76,    32,    34,
      29,     0,     0,     0,    40,     0,     0,    46,     0,     0,
       0,     0,    52,    51,    44,    50,    30,     0,    47,    28,
      42,    41,     0,     0,     0,    48,    53,    43,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -154,  -154,  -154,    16,   153,  -154,  -154,  -154,    89,  -154,
    -154,  -154,  -108,  -154,  -154,    56,  -154,    44,  -153,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -152,
    -154,  -154,  -121,   156,  -111,  -154,  -154,  -154,  -154,   -27,
      76,   -26,  -154
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    10,    11,    12,    25,   111,    53,    54,
     101,   124,    46,    58,   105,   106,   107,   126,   127,   136,
     137,   128,   158,   171,   174,   129,   133,   161,   178,   164,
     165,   169,   130,    13,    14,    15,    16,    98,    51,   108,
      48,    36,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,     3,    50,   131,     4,   163,   125,   -20,   163,   168,
     143,     6,    57,     7,     8,     9,    59,    60,    61,   125,
     131,   163,   177,   125,    76,   163,   179,    21,    80,    23,
      82,    72,    73,    74,     1,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,   173,    17,
     125,    99,    18,   125,     8,     9,    26,    27,   131,    28,
      29,   125,    55,    56,   139,   140,   125,    19,    20,   116,
     125,   109,   117,     7,   110,    30,     8,     9,   118,   119,
      52,   120,   121,   122,    75,    77,    79,   116,    78,   123,
     117,   134,    81,    83,   100,   103,   118,   119,   112,   120,
     121,   122,   113,   114,   132,   162,   135,   123,   146,   148,
     149,   138,   150,   151,   144,   142,    62,    63,   153,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     145,   152,   166,   156,   160,   154,   167,    62,    63,   104,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    37,    38,    39,    40,    41,    42,   159,   170,    43,
     155,   172,   175,   116,   176,    22,   117,    44,   102,   115,
      24,   141,   118,   119,    45,   120,   121,   122,     0,     0,
       0,    62,    63,   123,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,    62,    63,    84,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   147,     0,    62,    63,   157,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    63,     0,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    31,    32,    33,    34,    35,    70,    71,    72,    73,
      74
};

static const yytype_int16 yycheck[] =
{
      27,    37,    28,   114,     0,   158,   114,    55,   161,   161,
     131,    53,    60,     5,     6,     7,    43,    44,    45,   127,
     131,   174,   174,   131,    51,   178,   178,    11,    55,    13,
      57,    49,    50,    51,     3,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   169,    37,
     158,    77,    37,   161,     6,     7,    58,    59,   169,    58,
      59,   169,    59,    60,    59,    60,   174,    37,    54,    17,
     178,    98,    20,     5,   100,    55,     6,     7,    26,    27,
      37,    29,    30,    31,    59,    58,    57,    17,    56,    37,
      20,   118,    32,    55,    58,    61,    26,    27,    56,    29,
      30,    31,    57,    53,    55,    53,    55,    37,   135,   136,
     137,    37,   139,   140,    37,    54,    38,    39,   145,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      55,    41,   159,    48,    32,    56,    18,    38,    39,    61,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    32,    33,    34,    35,    36,    37,    59,    28,    40,
      61,    32,    56,    17,    54,    12,    20,    48,    79,   113,
      14,   127,    26,    27,    55,    29,    30,    31,    -1,    -1,
      -1,    38,    39,    37,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    -1,    -1,    38,    39,    56,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,   135,    -1,    38,    39,    56,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    39,    -1,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,     8,     9,    10,    11,    12,    47,    48,    49,    50,
      51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    63,    37,     0,    64,    53,     5,     6,     7,
      65,    66,    67,    95,    96,    97,    98,    37,    37,    37,
      54,    65,    66,    65,    95,    68,    58,    59,    58,    59,
      55,     8,     9,    10,    11,    12,   103,    32,    33,    34,
      35,    36,    37,    40,    48,    55,    74,   101,   102,   104,
     103,   100,    37,    70,    71,    59,    60,    60,    75,   101,
     101,   101,    38,    39,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    59,   101,    58,    56,    57,
     101,    32,   101,    55,    56,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,    99,   103,
      58,    72,    70,    61,    61,    76,    77,    78,   101,   101,
     103,    69,    56,    57,    53,    77,    17,    20,    26,    27,
      29,    30,    31,    37,    73,    74,    79,    80,    83,    87,
      94,    96,    55,    88,   101,    55,    81,    82,    37,    59,
      60,    79,    54,    94,    37,    55,   101,   102,   101,   101,
     101,   101,    41,   101,    56,    61,    48,    56,    84,    59,
      32,    89,    53,    80,    91,    92,   101,    18,    91,    93,
      28,    85,    32,    94,    86,    56,    54,    91,    90,    91
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    64,    63,    65,    65,    65,    66,    66,    68,
      69,    67,    70,    70,    70,    71,    72,    72,    73,    73,
      75,    74,    76,    76,    77,    77,    78,    79,    79,    80,
      80,    81,    80,    82,    80,    80,    80,    80,    80,    80,
      84,    83,    86,    85,    85,    88,    89,    87,    90,    87,
      91,    91,    93,    92,    94,    94,    95,    95,    96,    96,
      97,    97,    97,    97,    97,    99,    98,   100,    98,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   104,   104,   104,   104,   104
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     2,     0,     2,     1,     0,
       0,    11,     3,     1,     0,     3,     2,     0,     2,     1,
       0,     5,     1,     0,     3,     1,     1,     2,     0,     3,
       6,     0,     3,     0,     3,     2,     1,     1,     1,     1,
       0,     7,     0,     3,     0,     0,     0,     7,     0,    11,
       1,     1,     0,     4,     2,     1,     2,     0,     1,     1,
       7,     6,     4,     4,     2,     0,     7,     0,     5,     3,
       2,     3,     3,     3,     3,     3,     1,     4,     1,     1,
       1,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 102 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("create object table");
										objName = *(yyvsp[0].v_string);
										fp << "class " << objName << "\n" << "{" << "\n";
										nowTab++;

										table.push_table();
										IDinfo *f = new IDinfo(t_unknown, s_object, false);
										int t = table.insert(*(yyvsp[0].v_string), *f);
										
										if(t == -1)
											yyerror(*(yyvsp[0].v_string) + " has been declared");
									}
#line 1513 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 115 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("object ID objBlock ---> program");

										IDinfo id = table.list[table.top].idmap["main"];
										if(id.scope != s_function)
											yyerror("no main function");

										fp << "}";
										//table.dump();
										table.pop_table();
									}
#line 1529 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 136 "yacc.y" /* yacc.c:1646  */
    {
														//Trace("create function table");
														IDinfo *f = new IDinfo(t_unknown, s_function, false);
														int t = table.insert(*(yyvsp[0].v_string), *f);
														if(t == -1)
															yyerror(*(yyvsp[0].v_string) + " has been declared");
														nowFunc = *(yyvsp[0].v_string);
														table.push_table();

														nowStack = 0;
														printTab();
														fp << "method public static ";
													}
#line 1547 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "yacc.y" /* yacc.c:1646  */
    {
														IDinfo *id = table.lookup(*(yyvsp[-5].v_string));
														if(*(yyvsp[-5].v_string) == "main")
															fp << "void main(java.lang.String[])" << "\n";
														else
														{
															if(id->return_type == t_int)
																fp << "int ";
															else if(id->return_type == t_bool)
																fp << "bool ";
															else
																fp << "void ";
															fp << *(yyvsp[-5].v_string) << "(";

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
#line 1588 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 185 "yacc.y" /* yacc.c:1646  */
    {
														//Trace("def ID (args) type {} ---> funcDec");
														//table.dump();
														table.pop_table();

														IDinfo *id = table.lookup(*(yyvsp[-9].v_string));
														if(id->return_type == t_unknown)
														{
															printTab();
															fp << "return" << "\n";
														}

														nowTab--;
														printTab();
														fp << "}" << "\n";
													}
#line 1609 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 202 "yacc.y" /* yacc.c:1646  */
    {
											//Trace("args, arg ---> args");
										}
#line 1617 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 205 "yacc.y" /* yacc.c:1646  */
    {
											//Trace("arg ---> args");
										}
#line 1625 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 210 "yacc.y" /* yacc.c:1646  */
    {
											//Trace("ID:type ---> arg");
											IDinfo *f = new IDinfo((yyvsp[0].type), s_variable, false);
											int t = table.insert(*(yyvsp[-2].v_string), *f);
											t = table.list[table.top-1].insert_args(nowFunc, *(yyvsp[-2].v_string), *f);
											if(t == -1)
												yyerror(*(yyvsp[-2].v_string) + " has been declared");

											IDinfo *id = table.lookup(*(yyvsp[-2].v_string));
											id->stackIndex = nowStack;
											nowStack++;
										}
#line 1642 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 223 "yacc.y" /* yacc.c:1646  */
    {
											table.list[table.top-1].idmap[nowFunc].return_type = (yyvsp[0].type);
										}
#line 1650 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 226 "yacc.y" /* yacc.c:1646  */
    {	/* empty */
			   								table.list[table.top-1].idmap[nowFunc].return_type = t_unknown;
		   								}
#line 1658 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 229 "yacc.y" /* yacc.c:1646  */
    {
											//Trace("return expr ---> returnVal");
											table.list[table.top-1].idmap[nowFunc].return_value = new IDinfo(*(yyvsp[0].info));

											printTab();
											fp << "ireturn" << "\n";
										}
#line 1670 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 236 "yacc.y" /* yacc.c:1646  */
    {
											//Trace("return ---> returnVal");
											table.list[table.top-1].idmap[nowFunc].return_value = new IDinfo();

											printTab();
											fp << "return" << "\n";
										}
#line 1682 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 244 "yacc.y" /* yacc.c:1646  */
    {
											funcCall.push_back(vector<IDinfo>());
										}
#line 1690 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 247 "yacc.y" /* yacc.c:1646  */
    {
											//Trace("ID(parameter) ---> function_invoc");
											IDinfo *id = table.lookup(*(yyvsp[-4].v_string));
											if(id == NULL)
												yyerror(*(yyvsp[-4].v_string) + " not found");
											if(id->scope != s_function)
												yyerror("ID type is not function, can't use ()");

											vector<IDinfo> parm = id->args_value;
											for(int i=0; i<parm.size(); i++)
											{
												if(funcCall[funcCall.size()-1][i].type != parm[i].type)
													yyerror("type error: parameter and declaration");
											}
											funcCall.pop_back();
											(yyval.info) = id;

											printTab();
											fp << "invokestatic ";
											if(id->type == t_int)
												fp << "int ";
											else if(id->type == t_bool)
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
#line 1735 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 290 "yacc.y" /* yacc.c:1646  */
    {
											//Trace("expr, parameter ---> function parameter");
										}
#line 1743 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 293 "yacc.y" /* yacc.c:1646  */
    {
											//Trace("expr ---> function parameter");
		  								}
#line 1751 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 297 "yacc.y" /* yacc.c:1646  */
    {
											funcCall[funcCall.size()-1].push_back(*(yyvsp[0].info));
										}
#line 1759 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 305 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("ID[expr] ---> stat");
										IDinfo *id = table.lookup(*(yyvsp[-2].v_string));
										if(id == NULL)
											yyerror(*(yyvsp[-2].v_string) + " not found");
										if(id->scope != s_variable)
											yyerror(*(yyvsp[-2].v_string) + " is not variable, can't be assign");
										id->setValue((yyvsp[0].info)->value);
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
#line 1785 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 326 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("ID[expr]=expr ---> stat");
										IDinfo *id = table.lookup(*(yyvsp[-5].v_string));
										if(id == NULL)
											yyerror(*(yyvsp[-5].v_string) + " not found");
										if(id->scope != s_array)
											yyerror(*(yyvsp[-5].v_string) + " is not array");
										if((yyvsp[-3].info)->type != t_int)
											yyerror("Arrey index must be integer");
										int index = (yyvsp[-3].info)->value.v_int;
										if(index >= id->arr_size || index < 0)
											yyerror("array index out of range");
										if(id->type != (yyvsp[0].info)->type)
											yyerror("array assign data type error");
										id->arr_value[index].setValue((yyvsp[0].info)->value);
										id->init = true;
									}
#line 1807 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 343 "yacc.y" /* yacc.c:1646  */
    {	
										//Trace("print ---> stat");
										printTab();
										fp << "getstatic java.io.PrintStream java.lang.System.out" << "\n";
									}
#line 1817 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 348 "yacc.y" /* yacc.c:1646  */
    {
										printTab();
										fp << "invokevirtual void java.io.PrintStream.print(";
										if((yyvsp[0].info)->type == t_int)
											fp << "int)" << "\n";
										else if((yyvsp[0].info)->type == t_bool)
											fp << "boolean)" << "\n";
										else if((yyvsp[0].info)->type == t_string)
											fp << "java.lang.String)" << "\n";
									}
#line 1832 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 358 "yacc.y" /* yacc.c:1646  */
    {	
										//Trace("println ---> stat");
										printTab();
										fp << "getstatic java.io.PrintStream java.lang.System.out" << "\n";
									}
#line 1842 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 363 "yacc.y" /* yacc.c:1646  */
    {
										printTab();
										fp << "invokevirtual void java.io.PrintStream.println(";
										if((yyvsp[0].info)->type == t_int)
											fp << "int)" << "\n";
										else if((yyvsp[0].info)->type == t_bool)
											fp << "boolean)" << "\n";
										else if((yyvsp[0].info)->type == t_string)
											fp << "java.lang.String)" << "\n";
									}
#line 1857 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 373 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("read ID ---> stat");
									}
#line 1865 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 376 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("returnVal ---> stat");
									}
#line 1873 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 379 "yacc.y" /* yacc.c:1646  */
    {	
										//Trace("ifStat ---> stat");
									}
#line 1881 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 382 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("loopStat ---> stat");
									}
#line 1889 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 385 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("function_invoc ---> stat");
									}
#line 1897 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 389 "yacc.y" /* yacc.c:1646  */
    {
										printTab();
										fp << "ifeq " << "L" << nowLabel << "\n";
										elseLabel.push_back(nowLabel);
										nowLabel++;
									}
#line 1908 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 395 "yacc.y" /* yacc.c:1646  */
    {
			 							//Trace("IF (bool_expr) block elseStat ---> ifStat");
										
										fp << "L" << elseLabel.back() << ":" << "\n";
										elseLabel.pop_back();
									}
#line 1919 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 402 "yacc.y" /* yacc.c:1646  */
    {
										printTab();
										fp << "goto " << "L" << nowLabel << "\n";
										fp << "L" << elseLabel.back() << ":" << "\n";
										elseLabel.pop_back();
										elseLabel.push_back(nowLabel);
										nowLabel++;
									}
#line 1932 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 410 "yacc.y" /* yacc.c:1646  */
    {
			   							//Trace("else block ---> elseStat");
									}
#line 1940 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 416 "yacc.y" /* yacc.c:1646  */
    {
													fp << "L" << nowLabel << ":" << "\n";
													(yyvsp[0].whileLoop).beginLabel = nowLabel;
													nowLabel++;
												}
#line 1950 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 421 "yacc.y" /* yacc.c:1646  */
    {
													printTab();
													fp << "ifeq " << "L" << nowLabel << "\n";
													(yyvsp[-4].whileLoop).exitLable = nowLabel;
													nowLabel++;
												}
#line 1961 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 427 "yacc.y" /* yacc.c:1646  */
    {
													//Trace("WHILE (expr) ---> loopStat");

													printTab();
													fp << "goto " << "L" << (yyvsp[-6].whileLoop).beginLabel << "\n";
													fp << "L" << (yyvsp[-6].whileLoop).exitLable << ":" << "\n";
												}
#line 1973 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 434 "yacc.y" /* yacc.c:1646  */
    {
													IDinfo *id = table.lookup(*(yyvsp[-6].v_string));
													if(id == NULL)
														yyerror(*(yyvsp[-6].v_string) + " not found");
												}
#line 1983 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 439 "yacc.y" /* yacc.c:1646  */
    {	
			   										//Trace("for (id <- expr to expr) ---> loopStat");
		   										}
#line 1991 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 444 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("create block table");
										table.push_table();
									}
#line 2000 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 448 "yacc.y" /* yacc.c:1646  */
    {
										//Trace("{blockContent} ---> block");
										//table.dump();
										table.pop_table();
									}
#line 2010 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 464 "yacc.y" /* yacc.c:1646  */
    {
													//Trace("var id : type [ expr ] ---> declaration");
													IDinfo *f = new IDinfo((yyvsp[-3].type), s_array, false);
													int t = table.insert(*(yyvsp[-5].v_string), *f);
													if(t == -1)
														yyerror(*(yyvsp[-5].v_string) + " has been declared");
													table.list[table.top].insert_arr(*(yyvsp[-5].v_string), (yyvsp[-3].type), (yyvsp[-1].v_int));
												}
#line 2023 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 472 "yacc.y" /* yacc.c:1646  */
    {
													//Trace("var id : type = expr ---> declaration");
													if((yyvsp[-2].type) != (yyvsp[0].info)->type)
														yyerror("type error: dataType and expr");
													(yyvsp[0].info)->scope = s_variable;
													(yyvsp[0].info)->init = true;
													int t = table.insert(*(yyvsp[-4].v_string), *(yyvsp[0].info));
													if(t == -1)
														yyerror(*(yyvsp[-4].v_string) + " has been declared");

													IDinfo *id = table.lookup(*(yyvsp[-4].v_string));
													if(id->global)
													{
														printTab();
														if(id->type == t_int)
															fp << "field static int " << id->id << " = " << id->value.v_int << "\n";
														else if(id->type == t_int)
															fp << "field static bool " << id->id << " = " << id->value.v_bool << "\n";
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
#line 2057 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 501 "yacc.y" /* yacc.c:1646  */
    {
													//Trace("var id = expr ---> declaration");
													(yyvsp[0].info)->scope = s_variable;
													(yyvsp[0].info)->init = true;
													int t = table.insert(*(yyvsp[-2].v_string), *(yyvsp[0].info));
													if(t == -1)
														yyerror(*(yyvsp[-2].v_string) + " has been declared");

													IDinfo *id = table.lookup(*(yyvsp[-2].v_string));
													if(id->global)
													{
														printTab();
														if(id->type == t_int)
															fp << "field static int " << id->id << " = " << id->value.v_int << "\n";
														else if(id->type == t_int)
															fp << "field static bool " << id->id << " = " << id->value.v_bool << "\n";
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
#line 2089 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 528 "yacc.y" /* yacc.c:1646  */
    {
													//Trace("var id : type ---> declaration");
													IDinfo *f = new IDinfo((yyvsp[0].type), s_variable, false);
													int t = table.insert(*(yyvsp[-2].v_string), *f);
													if(t == -1)
														yyerror(*(yyvsp[-2].v_string) + " has been declared");

													IDinfo *id = table.lookup(*(yyvsp[-2].v_string));
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
#line 2113 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 547 "yacc.y" /* yacc.c:1646  */
    {
													//Trace("var id ---> declaration");
													IDinfo *f = new IDinfo(t_unknown, s_variable, false);
													int t = table.insert(*(yyvsp[0].v_string), *f);
													if(t == -1)
														yyerror(*(yyvsp[0].v_string) + " has been declared");

													IDinfo *id = table.lookup(*(yyvsp[0].v_string));
													if(id->global)
													{
														printTab();
														fp << "field static int" << id->id << "\n";
													}
													else
													{
														id->stackIndex = nowStack;
														nowStack++;
													}
												}
#line 2137 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 567 "yacc.y" /* yacc.c:1646  */
    { 
													isConst = true;
												}
#line 2145 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 570 "yacc.y" /* yacc.c:1646  */
    {
													//Trace("val id : type = expr ---> declaration");
													if((yyvsp[-3].type) != (yyvsp[0].info)->type)
														yyerror("type error: dataType and expr");
													(yyvsp[0].info)->scope = s_const;
													(yyvsp[0].info)->init = true;
													int t = table.insert(*(yyvsp[-5].v_string), *(yyvsp[0].info));
													if(t == -1)
														yyerror(*(yyvsp[-5].v_string) + " has been declared");

													isConst = false;
												}
#line 2162 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 582 "yacc.y" /* yacc.c:1646  */
    {
				  									isConst = true;
												}
#line 2170 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 585 "yacc.y" /* yacc.c:1646  */
    {
													//Trace("val id = expr ---> declaration");
													(yyvsp[0].info)->scope = s_const;
													(yyvsp[0].info)->init = true;
													int t = table.insert(*(yyvsp[-3].v_string), *(yyvsp[0].info));
													if(t == -1)
														yyerror(*(yyvsp[-3].v_string) + " has been declared");

													isConst = false;
												}
#line 2185 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 596 "yacc.y" /* yacc.c:1646  */
    {
								//Trace("(expr) ---> expr");
								(yyval.info) = (yyvsp[-1].info);
							}
#line 2194 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 600 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("-expr ---> expr");
								if((yyvsp[0].info)->type == t_int)
								{
									(yyvsp[0].info)->value.v_int *= -1;
									(yyval.info) = (yyvsp[0].info);
								}
								else
									yyerror("type error -> - expr");

								if(!isConst)
								{
									printTab();
									fp << "ineg\n";
								}
							}
#line 2215 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 616 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr + expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int + (yyvsp[0].info)->value.v_int;
								}
								else
									yyerror("type error -> expr + expr");
								
								if(!isConst)
								{
									printTab();
									fp << "iadd\n";
								}
							}
#line 2236 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 632 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr - expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int - (yyvsp[0].info)->value.v_int;
								}
								else
									yyerror("type error -> expr - expr");
								
								if(!isConst)
								{
									printTab();
									fp << "isub\n";
								}
							}
#line 2257 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 648 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr * expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int * (yyvsp[0].info)->value.v_int;
								}
								else
									yyerror("type error -> expr * expr");
								
								if(!isConst)
								{
									printTab();
									fp << "imul\n";
								}
							}
#line 2278 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 664 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr / expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int / (yyvsp[0].info)->value.v_int;
								}
								else
									yyerror("type error -> expr / expr");
								
								if(!isConst)
								{
									printTab();
									fp << "idiv\n";
								}
							}
#line 2299 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 680 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr % expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int % (yyvsp[0].info)->value.v_int;
								}
								else
									yyerror("type error -> expr % expr");
								
								if(!isConst)
								{
									printTab();
									fp << "irem\n";
								}
							}
#line 2320 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 696 "yacc.y" /* yacc.c:1646  */
    {
								//Trace("bool_expr ---> expr");
								(yyval.info) = (yyvsp[0].info);
							}
#line 2329 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 700 "yacc.y" /* yacc.c:1646  */
    {
								//Trace("ID[expr] ---> expr");
								IDinfo *id = table.lookup(*(yyvsp[-3].v_string));
								if(id == NULL)
									yyerror(*(yyvsp[-3].v_string) + " not found");
								if(id->scope != s_array)
									yyerror("ID type is not array, can't use []");
								if((yyvsp[-1].info)->type != t_int)
									yyerror("Arrey index must be integer");
								int index = (yyvsp[-1].info)->value.v_int;
								if(index > id->arr_size || index < 0)
									yyerror("Arrey index out of range");
								(yyval.info) = new IDinfo(id->arr_value[index]);
							}
#line 2348 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 714 "yacc.y" /* yacc.c:1646  */
    {
		 						//Trace("function_invoc ---> expr");
							}
#line 2356 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 717 "yacc.y" /* yacc.c:1646  */
    {
								//Trace("ID ---> expr");
								IDinfo *id = table.lookup(*(yyvsp[0].v_string));
								if(id == NULL)
									yyerror(*(yyvsp[0].v_string) + " not found");
								if(id->scope == s_array)
									yyerror("ID in array scope has no index.");
								if(id->scope == s_function)
									yyerror("ID call function has no parameter.");
								(yyval.info) = id;

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
#line 2396 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 752 "yacc.y" /* yacc.c:1646  */
    {
								//Trace("values ---> expr");
								(yyval.info) = (yyvsp[0].info);
							}
#line 2405 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 757 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("! expr ---> bool_expr");
								if((yyvsp[0].info)->type != t_bool)
									yyerror("type error -> ! expr");
								else
									(yyval.info)->value.v_bool = !((yyvsp[0].info)->value.v_bool);

								if(!isConst)
								{
									printTab();
									fp << "iconst_1" << "\n";
									printTab();
									fp << "ixor" << "\n";
								}
							}
#line 2425 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 772 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr < expr ---> bool_expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int < (yyvsp[0].info)->value.v_int;
								else
									yyerror("type error -> expr < expr");
								
								logic_operator("iflt");
							}
#line 2439 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 781 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr <= expr ---> bool_expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int <= (yyvsp[0].info)->value.v_int;
								else
									yyerror("type error -> expr <= expr");
								
								logic_operator("ifle");
							}
#line 2453 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 790 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr > expr ---> bool_expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int > (yyvsp[0].info)->value.v_int;
								else
									yyerror("type error -> expr > expr");
								
								logic_operator("ifgt");
							}
#line 2467 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 799 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr >= expr ---> bool_expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int >= (yyvsp[0].info)->value.v_int;
								else
									yyerror("type error -> expr >= expr");
								
								logic_operator("ifge");
							}
#line 2481 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 808 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr == expr ---> bool_expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int == (yyvsp[0].info)->value.v_int;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float == (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_char && (yyvsp[0].info)->type == t_char)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_char == (yyvsp[0].info)->value.v_char;
								}
								else if((yyvsp[-2].info)->type == t_string && (yyvsp[0].info)->type == t_string)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_string == (yyvsp[0].info)->value.v_string;
								}
								else if((yyvsp[-2].info)->type == t_bool && (yyvsp[0].info)->type == t_bool)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_bool == (yyvsp[0].info)->value.v_bool;
								}
								else
								{
									yyerror("type error -> expr == expr");
								}

								logic_operator("ifeq");
							}
#line 2515 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 837 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr != expr ---> bool_expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int != (yyvsp[0].info)->value.v_int;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float != (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_char && (yyvsp[0].info)->type == t_char)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_char != (yyvsp[0].info)->value.v_char;
								}
								else if((yyvsp[-2].info)->type == t_string && (yyvsp[0].info)->type == t_string)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_string != (yyvsp[0].info)->value.v_string;
								}
								else if((yyvsp[-2].info)->type == t_bool && (yyvsp[0].info)->type == t_bool)
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_bool != (yyvsp[0].info)->value.v_bool;
								}
								else
								{
									yyerror("type error -> expr != expr");
								}

								logic_operator("ifne");
							}
#line 2549 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 866 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr && expr ---> bool_expr");
								if((yyvsp[-2].info)->type != t_bool || (yyvsp[0].info)->type != t_bool)
								{
									yyerror("type error -> expr && expr");
								}
								else
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_bool && (yyvsp[0].info)->value.v_bool;
								}

								if(!isConst)
								{
									printTab();
									fp << "iand\n";
								}
							}
#line 2571 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 883 "yacc.y" /* yacc.c:1646  */
    { 
								//Trace("expr || expr ---> bool_expr");
								if((yyvsp[-2].info)->type != t_bool || (yyvsp[0].info)->type != t_bool)
								{
									yyerror("type error -> expr || expr");
								}
								else
								{
									(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_bool || (yyvsp[0].info)->value.v_bool;
								}

								if(!isConst)
								{
									printTab();
									fp << "ior\n";
								}
							}
#line 2593 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 900 "yacc.y" /* yacc.c:1646  */
    {
							(yyval.type) = t_int;
						}
#line 2601 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 903 "yacc.y" /* yacc.c:1646  */
    {
							(yyval.type) = t_float;
						}
#line 2609 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 906 "yacc.y" /* yacc.c:1646  */
    {
							(yyval.type) = t_char;
						}
#line 2617 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 909 "yacc.y" /* yacc.c:1646  */
    {
							(yyval.type) = t_string;
						}
#line 2625 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 912 "yacc.y" /* yacc.c:1646  */
    {
							(yyval.type) = t_bool;
						}
#line 2633 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 915 "yacc.y" /* yacc.c:1646  */
    {
							//Trace("T_INT ---> values");
							(yyval.info) = set_int((yyvsp[0].v_int));

							if(!isConst)
							{
								printTab();
								fp << "sipush " << (yyvsp[0].v_int) << "\n";
							}
						}
#line 2648 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 925 "yacc.y" /* yacc.c:1646  */
    {
							//Trace("T_FLOAT ---> values");
							(yyval.info) = set_float((yyvsp[0].v_float));
						}
#line 2657 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 929 "yacc.y" /* yacc.c:1646  */
    {
							//Trace("T_CHAR ---> values");
							(yyval.info) = set_char((yyvsp[0].v_char));
						}
#line 2666 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 933 "yacc.y" /* yacc.c:1646  */
    {
							//Trace("T_STRING ---> values");
							(yyval.info) = set_string(*(yyvsp[0].v_string));

							if(!isConst)
							{
								printTab();
								fp << "ldc \"" << *(yyvsp[0].v_string) << "\"" << "\n";
							}
						}
#line 2681 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 943 "yacc.y" /* yacc.c:1646  */
    {
							//Trace("T_BOOL ---> values");
							(yyval.info) = set_bool((yyvsp[0].v_bool));

							if(!isConst)
							{
								printTab();
								if((yyvsp[0].v_bool) == true)
									fp << "iconst_1 " << "\n";
								else if((yyvsp[0].v_bool) == false)
									fp << "iconst_0 " << "\n";
							}
						}
#line 2699 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2703 "y.tab.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 956 "yacc.y" /* yacc.c:1906  */


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

	fp.open("output.jasm", ios::out);
	if(!fp)
	{
		cout << "open file error\n";
		exit(-1);
	}

    if(yyparse() == 1)
		yyerror("parsing error");
	else
	{
		//table.dump();
		cout << "=============Parsing Success=============\n";
	}
	fp.close();

    return 0;
}
