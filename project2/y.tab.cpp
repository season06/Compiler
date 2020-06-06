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


#line 95 "y.tab.cpp" /* yacc.c:339  */

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
#line 32 "yacc.y" /* yacc.c:355  */

	int v_int;
	float v_float;
	char v_char;
	string* v_string;
	bool v_bool;

	IDinfo* info;
	IDtype type;
	vector<IDinfo*>* func_call;

#line 239 "y.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 256 "y.tab.cpp" /* yacc.c:358  */

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
#define YYLAST   237

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  90
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  169

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
       0,    82,    82,    82,    96,    97,    98,   102,   103,   105,
     105,   123,   126,   129,   131,   140,   143,   146,   150,   154,
     158,   158,   177,   178,   180,   183,   187,   192,   193,   195,
     205,   219,   222,   225,   228,   231,   234,   237,   241,   245,
     248,   252,   258,   258,   267,   268,   269,   270,   271,   274,
     275,   277,   278,   282,   288,   298,   306,   313,   321,   331,
     340,   344,   359,   386,   413,   440,   467,   494,   498,   512,
     513,   524,   529,   540,   563,   586,   609,   632,   659,   686,
     697,   708,   711,   714,   717,   720,   723,   727,   731,   735,
     739
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
  "$@2", "args", "arg", "returnType", "returnVal", "function_invoc", "$@3",
  "parameters", "parameter", "para", "stats", "stat", "ifStat", "elseStat",
  "loopStat", "block", "$@4", "blockContent", "declarations",
  "declaration", "varDeclare", "constDeclare", "expr", "bool_expr",
  "dataType", "values", YY_NULLPTR
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

#define YYPACT_NINF -108

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-108)))

#define YYTABLE_NINF -21

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -2,   -26,    14,  -108,  -108,   -21,    49,    28,    45,    56,
       3,    49,    62,    49,    43,  -108,  -108,  -108,     1,    26,
    -108,  -108,  -108,  -108,  -108,    53,    13,   -28,    13,   -28,
      61,  -108,  -108,  -108,  -108,  -108,    32,  -108,  -108,  -108,
    -108,  -108,   -45,   -28,   -28,   -28,  -108,   150,  -108,  -108,
      10,   150,    42,    48,    52,   -28,    98,   -28,    76,   174,
    -108,   118,   -28,   -28,   -28,   -28,   -28,   -28,   -28,   -28,
     -28,   -28,   -28,   -28,   -28,   -28,    13,    75,    61,   150,
      73,    97,   -28,  -108,   163,   174,    77,    77,    77,    77,
      77,    77,    30,    30,  -108,  -108,  -108,   150,  -108,    13,
      96,  -108,  -108,  -108,    94,  -108,    95,   150,  -108,    46,
    -108,   -28,    99,   100,   115,   -28,   -28,   114,    37,  -108,
      46,    41,  -108,  -108,  -108,   127,    46,  -108,   149,   -28,
     -28,   150,   150,  -108,   -28,   139,    46,  -108,  -108,   -28,
     133,  -108,   162,   150,   170,   171,   150,   167,   175,   150,
    -108,   182,   178,   178,   173,  -108,   -28,  -108,   205,   -28,
      72,   178,  -108,   150,   -28,  -108,   134,   178,  -108
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     1,     0,     6,     0,     0,     0,
       0,     6,     8,     6,    50,    51,    52,     9,    57,     0,
       3,     4,     7,     5,    49,     0,     0,     0,     0,     0,
      13,    81,    82,    83,    84,    85,    56,    86,    87,    88,
      89,    90,    70,     0,     0,     0,    69,    55,    67,    71,
       0,    59,     0,     0,    12,     0,     0,     0,     0,    72,
      61,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    13,    54,
       0,     0,    23,    60,    80,    79,    73,    74,    75,    76,
      77,    78,    62,    63,    64,    65,    66,    58,    14,     0,
       0,    11,    53,    68,     0,    22,    25,    26,    15,    48,
      21,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      47,    28,    34,    35,    36,    19,    46,    24,     0,     0,
       0,    31,    32,    33,     0,     0,    48,    45,    27,    18,
       0,    44,     0,     0,    67,    67,    29,     0,     0,    17,
      10,     0,     0,     0,     0,    43,     0,    40,    39,     0,
       0,     0,    37,    30,     0,    38,     0,     0,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -108,  -108,  -108,    51,   222,  -108,  -108,   157,  -108,  -108,
    -108,  -108,  -108,  -108,   125,  -108,   116,  -108,  -108,  -108,
    -108,   -66,  -108,  -107,    20,  -108,  -108,  -108,   -27,   -24,
     -25,  -108
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    10,    11,    12,    25,    53,    54,   100,
     140,    46,    58,   104,   105,   106,   120,   121,   122,   162,
     123,   124,   136,   125,   126,    14,    15,    16,   107,    48,
      36,    49
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      47,     1,    51,    50,    37,    38,    39,    40,    41,    42,
     -20,     3,    43,   137,     4,    57,    59,    60,    61,   141,
      44,    31,    32,    33,    34,    35,    13,    45,    79,   148,
      81,    13,     6,    13,    24,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,     8,
       9,    98,     8,     9,     7,     8,     9,    20,   112,    26,
      27,   113,    21,   112,    23,    17,   113,     7,   114,    75,
     115,   116,   117,   114,   108,   115,   116,   117,   118,    72,
      73,    74,    18,   118,    28,    29,   157,   158,   131,   132,
     164,    55,    56,    19,   119,   165,   134,   135,    52,   119,
      76,   168,   143,   143,    77,   144,   145,   146,    30,    78,
      62,    63,   149,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    70,    71,    72,    73,    74,   160,
      80,    82,   163,    99,   102,    62,    63,   166,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   109,
     110,   133,   111,   139,   128,   129,    62,    63,   103,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     130,   147,    62,    63,    83,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   142,   150,    62,    63,
     167,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    63,   151,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   152,   153,   154,   155,
     156,   119,   159,   161,    22,   101,   127,   138
};

static const yytype_uint8 yycheck[] =
{
      27,     3,    29,    28,    32,    33,    34,    35,    36,    37,
      55,    37,    40,   120,     0,    60,    43,    44,    45,   126,
      48,     8,     9,    10,    11,    12,     6,    55,    55,   136,
      57,    11,    53,    13,    14,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,     6,
       7,    76,     6,     7,     5,     6,     7,    54,    17,    58,
      59,    20,    11,    17,    13,    37,    20,     5,    27,    59,
      29,    30,    31,    27,    99,    29,    30,    31,    37,    49,
      50,    51,    37,    37,    58,    59,   152,   153,   115,   116,
      18,    59,    60,    37,    53,   161,    59,    60,    37,    53,
      58,   167,   129,   130,    56,   129,   130,   134,    55,    57,
      38,    39,   139,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    47,    48,    49,    50,    51,   156,
      32,    55,   159,    58,    61,    38,    39,   164,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    53,
      56,    37,    57,    26,    55,    55,    38,    39,    61,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      55,    32,    38,    39,    56,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    37,    54,    38,    39,
      56,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    39,    41,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    56,    56,    61,    54,
      48,    53,    59,    28,    12,    78,   111,   121
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    63,    37,     0,    64,    53,     5,     6,     7,
      65,    66,    67,    86,    87,    88,    89,    37,    37,    37,
      54,    65,    66,    65,    86,    68,    58,    59,    58,    59,
      55,     8,     9,    10,    11,    12,    92,    32,    33,    34,
      35,    36,    37,    40,    48,    55,    73,    90,    91,    93,
      92,    90,    37,    69,    70,    59,    60,    60,    74,    90,
      90,    90,    38,    39,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    59,    58,    56,    57,    90,
      32,    90,    55,    56,    90,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    92,    58,
      71,    69,    61,    61,    75,    76,    77,    90,    92,    53,
      56,    57,    17,    20,    27,    29,    30,    31,    37,    53,
      78,    79,    80,    82,    83,    85,    86,    76,    55,    55,
      55,    90,    90,    37,    59,    60,    84,    85,    78,    26,
      72,    85,    37,    90,    91,    91,    90,    32,    85,    90,
      54,    41,    56,    56,    61,    54,    48,    83,    83,    59,
      90,    28,    81,    90,    18,    83,    90,    56,    83
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    62,    64,    63,    65,    65,    65,    66,    66,    68,
      67,    69,    69,    69,    70,    71,    71,    72,    72,    72,
      74,    73,    75,    75,    76,    76,    77,    78,    78,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    81,    81,
      82,    82,    84,    83,    85,    85,    85,    85,    85,    86,
      86,    87,    87,    88,    88,    88,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    92,    92,    92,    92,    92,    93,    93,    93,    93,
      93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     6,     2,     2,     0,     2,     1,     0,
      11,     3,     1,     0,     3,     2,     0,     2,     1,     0,
       0,     5,     1,     0,     3,     1,     1,     2,     1,     3,
       6,     2,     2,     2,     1,     1,     1,     6,     2,     0,
       5,    10,     0,     4,     2,     2,     1,     1,     0,     2,
       1,     1,     1,     7,     6,     4,     4,     2,     6,     4,
       3,     2,     3,     3,     3,     3,     3,     1,     4,     1,
       1,     1,     2,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1
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
#line 82 "yacc.y" /* yacc.c:1646  */
    {
									Trace("create object table");
									table.push_table();
									IDinfo *f = new IDinfo(t_unknown, s_object, false);
									int t = table.insert(*(yyvsp[0].v_string), *f);
									if(t == -1)
										yyerror(*(yyvsp[0].v_string) + " has been declared");
								}
#line 1477 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 90 "yacc.y" /* yacc.c:1646  */
    {
									Trace("object ID objBlock ---> program");
									table.dump();
									table.pop_table();
								}
#line 1487 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 105 "yacc.y" /* yacc.c:1646  */
    {
												Trace("create function table");
												IDinfo *f = new IDinfo(t_unknown, s_function, false);
												int t = table.insert(*(yyvsp[0].v_string), *f);
												if(t == -1)
													yyerror(*(yyvsp[0].v_string) + " has been declared");
												now_func = *(yyvsp[0].v_string);
												table.push_table();
											}
#line 1501 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 115 "yacc.y" /* yacc.c:1646  */
    {
												Trace("def ID (args) type {} ---> funcDec");
												//if($7 != $10->type)
												//	yyerror("type error: function type and return type");
												table.dump();
												table.pop_table();
											}
#line 1513 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 123 "yacc.y" /* yacc.c:1646  */
    {
										Trace("args, arg ---> args");
									}
#line 1521 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 126 "yacc.y" /* yacc.c:1646  */
    {
										Trace("arg ---> args");
									}
#line 1529 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 131 "yacc.y" /* yacc.c:1646  */
    {
										Trace("ID:type ---> arg");
										IDinfo *f = new IDinfo((yyvsp[0].type), s_variable, false);
										int t = table.insert(*(yyvsp[-2].v_string), *f);
										t = table.list[table.top].insert_args(now_func, *(yyvsp[-2].v_string), *f);
										if(t == -1)
											yyerror(*(yyvsp[-2].v_string) + " has been declared");
									}
#line 1542 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 140 "yacc.y" /* yacc.c:1646  */
    {
										table.list[table.top].idmap[now_func].return_type = (yyvsp[0].type);
									}
#line 1550 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 143 "yacc.y" /* yacc.c:1646  */
    {	//empty
			   							table.list[table.top].idmap[now_func].return_type = t_unknown;
		   							}
#line 1558 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 146 "yacc.y" /* yacc.c:1646  */
    {
										Trace("return expr ---> returnVal");
										table.list[table.top].idmap[now_func].return_value = new IDinfo(*(yyvsp[0].info));
									}
#line 1567 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 150 "yacc.y" /* yacc.c:1646  */
    {
										Trace("return ---> returnVal");
										table.list[table.top].idmap[now_func].return_value = new IDinfo();
									}
#line 1576 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 154 "yacc.y" /* yacc.c:1646  */
    {	// empty
										table.list[table.top].idmap[now_func].return_value = new IDinfo();
									}
#line 1584 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 158 "yacc.y" /* yacc.c:1646  */
    {
											func_call.push_back(vector<IDinfo>());
										}
#line 1592 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 161 "yacc.y" /* yacc.c:1646  */
    {
											Trace("ID(parameter) ---> expr");
											IDinfo *id = table.lookup(*(yyvsp[-4].v_string));
											if(id == NULL)
												yyerror(*(yyvsp[-4].v_string) + " not found");
											if(id->scope != IDscope::s_function)
												yyerror("ID type is not function, can't use ()");
											vector<IDinfo> parm = id->args_value;
											for(int i=0; i<parm.size(); i++)
											{
												if(func_call[func_call.size()-1][i].type != parm[i].type)
													yyerror("type error: parameter and declaration");
											}
											func_call.pop_back();
											(yyval.info) = id->return_value;
										}
#line 1613 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 180 "yacc.y" /* yacc.c:1646  */
    {
											Trace("expr, parameter ---> function parameter");
										}
#line 1621 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 183 "yacc.y" /* yacc.c:1646  */
    {
											Trace("expr ---> function parameter");
		  								}
#line 1629 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 187 "yacc.y" /* yacc.c:1646  */
    {
											func_call[func_call.size()-1].push_back(*(yyvsp[0].info));
										}
#line 1637 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 195 "yacc.y" /* yacc.c:1646  */
    {
										Trace("ID[expr] ---> stat");
										IDinfo *id = table.lookup(*(yyvsp[-2].v_string));
										if(id == NULL)
											yyerror(*(yyvsp[-2].v_string) + " not found");
										if(id->scope != s_variable)
											yyerror(*(yyvsp[-2].v_string) + " is not variable, can't be assign");
										id->setValue((yyvsp[0].info)->value);
										id->init = true;
									}
#line 1652 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 205 "yacc.y" /* yacc.c:1646  */
    {
										Trace("ID[expr]=expr ---> stat");
										IDinfo *id = table.lookup(*(yyvsp[-5].v_string));
										if(id == NULL)
											yyerror(*(yyvsp[-5].v_string) + " not found");
										if(id->scope != s_array)
											yyerror(*(yyvsp[-5].v_string) + " is not array");
										if((yyvsp[-3].v_int) >= id->arr_size || (yyvsp[-3].v_int) < 0)
											yyerror("array index out of range");
										if(id->arr_size != (yyvsp[0].info)->type)
											yyerror("array assign data type error");
										id->arr_value[(yyvsp[-3].v_int)].setValue((yyvsp[0].info)->value);
										id->init = true;
									}
#line 1671 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 219 "yacc.y" /* yacc.c:1646  */
    {
									Trace("print ---> stat");
								}
#line 1679 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 222 "yacc.y" /* yacc.c:1646  */
    {
									Trace("println ---> stat");
								}
#line 1687 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 225 "yacc.y" /* yacc.c:1646  */
    {
									Trace("read ID ---> stat");
								}
#line 1695 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 228 "yacc.y" /* yacc.c:1646  */
    {
									Trace("ifStat ---> stat");
								}
#line 1703 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 231 "yacc.y" /* yacc.c:1646  */
    {
									Trace("loopStat ---> stat");
								}
#line 1711 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 234 "yacc.y" /* yacc.c:1646  */
    {
									Trace("block ---> stat");
								}
#line 1719 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 238 "yacc.y" /* yacc.c:1646  */
    {
									Trace("IF (bool_expr) block elseStat ---> ifStat");
								}
#line 1727 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 242 "yacc.y" /* yacc.c:1646  */
    {
									Trace("else block ---> elseStat");
								}
#line 1735 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 249 "yacc.y" /* yacc.c:1646  */
    {
													Trace("WHILE (bool_expr) block ---> loopStat");
												}
#line 1743 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 253 "yacc.y" /* yacc.c:1646  */
    {
													Trace("for (id <- expr to expr) block ---> loopStat");
												}
#line 1751 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 258 "yacc.y" /* yacc.c:1646  */
    {
								Trace("create block table");
								table.push_table();
							}
#line 1760 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 262 "yacc.y" /* yacc.c:1646  */
    {
								Trace("{blockContent} ---> block");
								table.dump();
								table.pop_table();
							}
#line 1770 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 282 "yacc.y" /* yacc.c:1646  */
    {
													Trace("var id : type [ expr ] ---> declaration");
													int t = table.insert_arr(*(yyvsp[-5].v_string), (yyvsp[-3].type), (yyvsp[-1].v_int));
													if(t == -1)
														yyerror(*(yyvsp[-5].v_string) + " has been declared");
												}
#line 1781 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 288 "yacc.y" /* yacc.c:1646  */
    {
													Trace("var id : type = expr ---> declaration");
													if((yyvsp[-2].type) != (yyvsp[0].info)->type)
														yyerror("type error: dataType and expr");
													(yyvsp[0].info)->scope = s_variable;
													(yyvsp[0].info)->init = true;
													int t = table.insert(*(yyvsp[-4].v_string), *(yyvsp[0].info));
													if(t == -1)
														yyerror(*(yyvsp[-4].v_string) + " has been declared");
												}
#line 1796 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 298 "yacc.y" /* yacc.c:1646  */
    {
													Trace("var id = expr ---> declaration");
													(yyvsp[0].info)->scope = s_variable;
													(yyvsp[0].info)->init = true;
													int t = table.insert(*(yyvsp[-2].v_string), *(yyvsp[0].info));
													if(t == -1)
														yyerror(*(yyvsp[-2].v_string) + " has been declared");
												}
#line 1809 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 306 "yacc.y" /* yacc.c:1646  */
    {
													Trace("var id : type ---> declaration");
													IDinfo *f = new IDinfo((yyvsp[0].type), s_variable, false);
													int t = table.insert(*(yyvsp[-2].v_string), *f);
													if(t == -1)
														yyerror(*(yyvsp[-2].v_string) + " has been declared");
												}
#line 1821 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 313 "yacc.y" /* yacc.c:1646  */
    {
													Trace("var id ---> declaration");
													IDinfo *f = new IDinfo(t_unknown, s_variable, false);
													int t = table.insert(*(yyvsp[0].v_string), *f);
													if(t == -1)
														yyerror(*(yyvsp[0].v_string) + " has been declared");
												}
#line 1833 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 321 "yacc.y" /* yacc.c:1646  */
    {
												Trace("val id : type = expr ---> declaration");
												if((yyvsp[-2].type) != (yyvsp[0].info)->type)
													yyerror("type error: dataType and expr");
												(yyvsp[0].info)->scope = s_const;
												(yyvsp[0].info)->init = true;
												int t = table.insert(*(yyvsp[-4].v_string), *(yyvsp[0].info));
												if(t == -1)
													yyerror(*(yyvsp[-4].v_string) + " has been declared");
											}
#line 1848 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 331 "yacc.y" /* yacc.c:1646  */
    {
												Trace("val id = expr ---> declaration");
												(yyvsp[0].info)->scope = s_const;
												(yyvsp[0].info)->init = true;
												int t = table.insert(*(yyvsp[-2].v_string), *(yyvsp[0].info));
												if(t == -1)
													yyerror(*(yyvsp[-2].v_string) + " has been declared");
											}
#line 1861 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 340 "yacc.y" /* yacc.c:1646  */
    {
								Trace("(expr) ---> expr");
								(yyval.info) = (yyvsp[-1].info);
							}
#line 1870 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 344 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("-expr ---> expr");
									if((yyvsp[0].info)->type == t_int)
									{
										(yyval.info)->value.v_int = (yyvsp[0].info)->value.v_int;
									}
									else if((yyvsp[0].info)->type == t_float)
									{
										(yyval.info)->value.v_float =  (yyvsp[0].info)->value.v_float;
									}
									else
									{
										yyerror("type error -> - expr");
									}
								}
#line 1890 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 359 "yacc.y" /* yacc.c:1646  */
    { 
								Trace("expr + expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int + (yyvsp[0].info)->value.v_int;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (yyvsp[-2].info)->value.v_float + (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (float)(yyvsp[-2].info)->value.v_int + (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (yyvsp[-2].info)->value.v_float + (float)(yyvsp[0].info)->value.v_int;
								}
								else
								{
									yyerror("type error -> expr + expr");
								}
							}
#line 1922 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 386 "yacc.y" /* yacc.c:1646  */
    { 
								Trace("expr - expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int - (yyvsp[0].info)->value.v_int;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (yyvsp[-2].info)->value.v_float - (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (float)(yyvsp[-2].info)->value.v_int - (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (yyvsp[-2].info)->value.v_float - (float)(yyvsp[0].info)->value.v_int;
								}
								else
								{
									yyerror("type error -> expr - expr");
								}
							}
#line 1954 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 413 "yacc.y" /* yacc.c:1646  */
    { 
								Trace("expr * expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int * (yyvsp[0].info)->value.v_int;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (yyvsp[-2].info)->value.v_float * (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (float)(yyvsp[-2].info)->value.v_int * (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (yyvsp[-2].info)->value.v_float * (float)(yyvsp[0].info)->value.v_int;
								}
								else
								{
									yyerror("type error -> expr * expr");
								}
							}
#line 1986 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 440 "yacc.y" /* yacc.c:1646  */
    { 
								Trace("expr / expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int / (yyvsp[0].info)->value.v_int;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (yyvsp[-2].info)->value.v_float / (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (float)(yyvsp[-2].info)->value.v_int / (yyvsp[0].info)->value.v_float;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = (yyvsp[-2].info)->value.v_float / (float)(yyvsp[0].info)->value.v_int;
								}
								else
								{
									yyerror("type error -> expr / expr");
								}
							}
#line 2018 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 467 "yacc.y" /* yacc.c:1646  */
    { 
								Trace("expr % expr ---> expr");
								if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_int;
									(yyval.info)->value.v_int = (yyvsp[-2].info)->value.v_int % (yyvsp[0].info)->value.v_int;
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = fmod((yyvsp[-2].info)->value.v_float, (yyvsp[0].info)->value.v_float);
								}
								else if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_float)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = fmod((float)(yyvsp[-2].info)->value.v_int, (yyvsp[0].info)->value.v_float);
								}
								else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_int)
								{
									(yyval.info)->type = t_float;
									(yyval.info)->value.v_float = fmod((yyvsp[-2].info)->value.v_float, (float)(yyvsp[0].info)->value.v_int);
								}
								else
								{
									yyerror("type error -> expr % expr");
								}
							}
#line 2050 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 494 "yacc.y" /* yacc.c:1646  */
    {
									Trace("bool_expr ---> expr");
									(yyval.info) = (yyvsp[0].info);
								}
#line 2059 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 498 "yacc.y" /* yacc.c:1646  */
    {
									Trace("ID[expr] ---> expr");
									IDinfo *id = table.lookup(*(yyvsp[-3].v_string));
									if(id == NULL)
										yyerror(*(yyvsp[-3].v_string) + " not found");
									if(id->scope != s_array)
										yyerror("ID type is not array, can't use []");
									if((yyvsp[-1].info)->type != t_int)
										yyerror("Arrey index must be integer");
									if((yyvsp[-1].info)->value.v_int > id->arr_size || (yyvsp[-1].info)->value.v_int < 0)
										yyerror("Arrey index out of range");
									(yyval.info) = new IDinfo(id->arr_value[(yyvsp[-1].info)->value.v_int]);
									
								}
#line 2078 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 512 "yacc.y" /* yacc.c:1646  */
    {	Trace("function_invoc ---> expr");	}
#line 2084 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 513 "yacc.y" /* yacc.c:1646  */
    {
									Trace("ID ---> expr");
									IDinfo *id = table.lookup(*(yyvsp[0].v_string));
									if(id == NULL)
										yyerror(*(yyvsp[0].v_string) + " not found");
									if(id->scope == s_array)
										yyerror("ID in array scope has no index.");
									if(id->scope == s_function)
										yyerror("ID call function has no parameter.");
									(yyval.info) = id;
								}
#line 2100 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 524 "yacc.y" /* yacc.c:1646  */
    {
									Trace("values ---> expr");
									(yyval.info) = (yyvsp[0].info);
								}
#line 2109 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 529 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("! expr ---> bool_expr");
									if((yyvsp[0].info)->type != t_bool)
									{
										yyerror("type error -> ! expr");
									}
									else
									{
										(yyval.info)->value.v_bool = !((yyvsp[0].info)->value.v_bool);
									}
								}
#line 2125 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 540 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("expr < expr ---> bool_expr");
									if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int < (yyvsp[0].info)->value.v_int;
									}
									else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float < (yyvsp[0].info)->value.v_float;
									}
									else if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_float)
									{
										(yyval.info)->value.v_bool = (float)(yyvsp[-2].info)->value.v_int < (yyvsp[0].info)->value.v_float;
									}
									else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_int)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float < (float)(yyvsp[0].info)->value.v_int;
									}
									else
									{
										yyerror("type error -> expr < expr");
									}
								}
#line 2153 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 563 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("expr <= expr ---> bool_expr");
									if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int <= (yyvsp[0].info)->value.v_int;
									}
									else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float <= (yyvsp[0].info)->value.v_float;
									}
									else if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_float)
									{
										(yyval.info)->value.v_bool = (float)(yyvsp[-2].info)->value.v_int <= (yyvsp[0].info)->value.v_float;
									}
									else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_int)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float <= (float)(yyvsp[0].info)->value.v_int;
									}
									else
									{
										yyerror("type error -> expr <= expr");
									}
								}
#line 2181 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 586 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("expr > expr ---> bool_expr");
									if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int > (yyvsp[0].info)->value.v_int;
									}
									else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float > (yyvsp[0].info)->value.v_float;
									}
									else if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_float)
									{
										(yyval.info)->value.v_bool = (float)(yyvsp[-2].info)->value.v_int > (yyvsp[0].info)->value.v_float;
									}
									else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_int)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float > (float)(yyvsp[0].info)->value.v_int;
									}
									else
									{
										yyerror("type error -> expr > expr");
									}
								}
#line 2209 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 609 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("expr >= expr ---> bool_expr");
									if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_int)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_int >= (yyvsp[0].info)->value.v_int;
									}
									else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_float)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float >= (yyvsp[0].info)->value.v_float;
									}
									else if((yyvsp[-2].info)->type == t_int && (yyvsp[0].info)->type == t_float)
									{
										(yyval.info)->value.v_bool = (float)(yyvsp[-2].info)->value.v_int >= (yyvsp[0].info)->value.v_float;
									}
									else if((yyvsp[-2].info)->type == t_float && (yyvsp[0].info)->type == t_int)
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_float >= (float)(yyvsp[0].info)->value.v_int;
									}
									else
									{
										yyerror("type error -> expr >= expr");
									}
								}
#line 2237 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 632 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("expr == expr ---> bool_expr");
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
								}
#line 2269 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 659 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("expr != expr ---> bool_expr");
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
								}
#line 2301 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 686 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("expr && expr ---> bool_expr");
									if((yyvsp[-2].info)->type != t_bool || (yyvsp[0].info)->type != t_bool)
									{
										yyerror("type error -> expr && expr");
									}
									else
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_bool && (yyvsp[0].info)->value.v_bool;
									}
								}
#line 2317 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 697 "yacc.y" /* yacc.c:1646  */
    { 
									Trace("expr || expr ---> bool_expr");
									if((yyvsp[-2].info)->type != t_bool || (yyvsp[0].info)->type != t_bool)
									{
										yyerror("type error -> expr || expr");
									}
									else
									{
										(yyval.info)->value.v_bool = (yyvsp[-2].info)->value.v_bool || (yyvsp[0].info)->value.v_bool;
									}
								}
#line 2333 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 708 "yacc.y" /* yacc.c:1646  */
    {
						(yyval.type) = t_int;
					}
#line 2341 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 711 "yacc.y" /* yacc.c:1646  */
    {
						(yyval.type) = t_float;
					}
#line 2349 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 714 "yacc.y" /* yacc.c:1646  */
    {
						(yyval.type) = t_char;
					}
#line 2357 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 717 "yacc.y" /* yacc.c:1646  */
    {
						(yyval.type) = t_string;
					}
#line 2365 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 720 "yacc.y" /* yacc.c:1646  */
    {
						(yyval.type) = t_bool;
					}
#line 2373 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 723 "yacc.y" /* yacc.c:1646  */
    {
						Trace("T_INT ---> values");
						(yyval.info) = set_int((yyvsp[0].v_int));
					}
#line 2382 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 727 "yacc.y" /* yacc.c:1646  */
    {
						Trace("T_FLOAT ---> values");
						(yyval.info) = set_float((yyvsp[0].v_float));
					}
#line 2391 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 731 "yacc.y" /* yacc.c:1646  */
    {
						Trace("T_CHAR ---> values");
						(yyval.info) = set_char((yyvsp[0].v_char));
					}
#line 2400 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 735 "yacc.y" /* yacc.c:1646  */
    {
						Trace("T_STRING ---> values");
						(yyval.info) = set_string(*(yyvsp[0].v_string));
					}
#line 2409 "y.tab.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 739 "yacc.y" /* yacc.c:1646  */
    {
						Trace("T_BOOL ---> values");
						(yyval.info) = set_bool((yyvsp[0].v_bool));
					}
#line 2418 "y.tab.cpp" /* yacc.c:1646  */
    break;


#line 2422 "y.tab.cpp" /* yacc.c:1646  */
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
#line 743 "yacc.y" /* yacc.c:1906  */


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
