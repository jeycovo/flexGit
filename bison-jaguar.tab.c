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
#line 1 "bison-jaguar.y" /* yacc.c:339  */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "tablasimbolo-jaguar.h"
#include "Qlib.h"

#define YYDEBUG 1

extern FILE *yyin;
extern int numlin;
extern int current_scope;
extern struct reg *punteroVector;
//int yydebug=1;
void yyerror (char* mens);
int yylex();
char* concN (char* string, int n);
int powJ(int a, int b);

//Generación de código
int sm = 0x12000;
int fm;
int et = 1;

FILE *obj;

#line 95 "bison-jaguar.tab.c" /* yacc.c:339  */

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
   by #include "bison-jaguar.tab.h".  */
#ifndef YY_YY_BISON_JAGUAR_TAB_H_INCLUDED
# define YY_YY_BISON_JAGUAR_TAB_H_INCLUDED
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
    VOID = 258,
    INT = 259,
    CHAR = 260,
    BOOL = 261,
    STRING = 262,
    NUMBER = 263,
    CHARACTER = 264,
    IDENTIF = 265,
    STRINGLITERAL = 266,
    RETURN = 267,
    IFCOND = 268,
    ELIF = 269,
    ELSECOND = 270,
    FOR = 271,
    WHILELOOP = 272,
    DOLOOP = 273,
    BREAK = 274,
    CONTINUE = 275,
    PRINTF = 276,
    PRINTFARROW = 277,
    SMALLEREQUALTHAN = 278,
    BIGGEREQUALTHAN = 279,
    EQUIVALENT = 280,
    EQUIVALENTNOT = 281,
    AND = 282,
    OR = 283,
    NOT = 284,
    TRUE = 285,
    FALSE = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "bison-jaguar.y" /* yacc.c:355  */

	int entero;
	char caracter;
	char* cadena;
	int booleano;

#line 174 "bison-jaguar.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_JAGUAR_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 191 "bison-jaguar.tab.c" /* yacc.c:358  */

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
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   828

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  426

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      39,    40,    36,    34,    44,    35,     2,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      33,    45,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    41,     2,    42,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   106,   106,   107,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   127,   127,   128,   128,   129,   129,
     130,   130,   131,   131,   132,   135,   138,   138,   139,   143,
     144,   145,   146,   147,   148,   149,   150,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   166,   167,
     167,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   193,
     194,   195,   196,   199,   202,   203,   206,   209,   210,   210,
     213,   214,   215,   216,   217,   218,   219,   220,   224,   225,
     226,   229,   230,   230,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   249,   250,   251,   252,
     253,   286,   288,   290,   292,   294,   295,   296,   297,   298,
     299,   300,   301,   337,   337,   338,   339,   339,   340,   341,
     341,   342,   351,   352,   352,   355,   355,   356,   357,   357,
     358,   359,   359,   360,   372,   373,   373,   376,   376,   377,
     378,   378,   379,   380,   380,   381,   392,   393,   393,   396,
     396,   397,   398,   398,   399,   400,   400,   401,   412,   413,
     413,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   430,   431,   432,   433,   434,   435,   436,   440,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     452,   453,   454,   455,   456,   457,   458,   459,   460,   461,
     462,   465,   466,   467
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "CHAR", "BOOL", "STRING",
  "NUMBER", "CHARACTER", "IDENTIF", "STRINGLITERAL", "RETURN", "IFCOND",
  "ELIF", "ELSECOND", "FOR", "WHILELOOP", "DOLOOP", "BREAK", "CONTINUE",
  "PRINTF", "PRINTFARROW", "SMALLEREQUALTHAN", "BIGGEREQUALTHAN",
  "EQUIVALENT", "EQUIVALENTNOT", "AND", "OR", "NOT", "TRUE", "FALSE",
  "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'^'", "'('", "')'", "'{'",
  "'}'", "';'", "','", "'='", "'['", "']'", "$accept", "programa",
  "bloque", "functionStructure", "$@1", "$@2", "$@3", "$@4", "$@5",
  "functionCallStructure", "functionParameter", "$@6", "Parameter",
  "functionCallParameter", "functionBlockEmpty", "$@7", "functionBlock",
  "conditionalStructure", "ifStructure", "elifStructure", "elseStructure",
  "ifBlockEmpty", "$@8", "ifBlock", "loopStructure", "loopBlockEmpty",
  "$@9", "loopBlock", "instr", "dexp", "declVI", "$@10", "$@11", "$@12",
  "viContent", "$@13", "declVC", "$@14", "$@15", "$@16", "vcContent",
  "$@17", "declVS", "$@18", "$@19", "$@20", "vsContent", "$@21", "declVB",
  "$@22", "$@23", "$@24", "vbContent", "$@25", "expI", "expS", "expB",
  "expC", YY_NULLPTR
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
     285,   286,    62,    60,    43,    45,    42,    47,    94,    40,
      41,   123,   125,    59,    44,    61,    91,    93
};
# endif

#define YYPACT_NINF -353

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-353)))

#define YYTABLE_NINF -211

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     487,   507,     5,    -2,     2,    36,    37,   112,   -33,   -10,
       6,    16,    26,  -353,   526,    56,   546,    35,   565,   585,
      73,    86,    97,   122,   149,  -353,  -353,   264,    -5,   279,
      50,   289,   117,   306,   120,   196,   114,   131,   206,   131,
     206,   206,  -353,  -353,  -353,  -353,   169,   177,   215,  -353,
    -353,  -353,  -353,  -353,  -353,  -353,  -353,   195,   189,   201,
    -353,   198,   242,   131,   250,   710,   139,   231,   277,   715,
     212,   252,   290,   729,   161,   260,   307,   734,  -353,   262,
    -353,  -353,  -353,   206,   271,   340,   402,    80,    -8,   206,
     266,  -353,   748,   166,   640,   707,   458,   137,   764,   670,
     674,   206,   283,  -353,   293,   163,  -353,   375,   293,   328,
    -353,   774,   303,   131,   131,   131,   131,   131,   349,   230,
    -353,  -353,   293,   315,   352,   228,  -353,   449,   293,   324,
     360,   186,   238,  -353,   574,    60,   293,   336,   373,   196,
     377,   581,   619,   678,  -353,   131,   131,   131,   131,   131,
     131,   238,   196,   238,   238,   238,   238,   238,   238,   238,
     131,   196,   206,   206,   206,   206,   196,   256,   256,   196,
     341,   351,   416,   269,   131,   356,   355,   206,   382,   389,
     694,   391,   387,   397,   643,   403,   384,  -353,  -353,   243,
     243,  -353,  -353,  -353,   399,   437,   407,  -353,   406,   417,
    -353,   413,   451,   211,   781,   346,   421,  -353,   436,  -353,
     448,  -353,  -353,   375,   375,   375,   375,   375,   375,  -353,
    -353,  -353,    60,    60,    60,    60,    60,    60,   460,    76,
    -353,  -353,  -353,  -353,  -353,  -353,   453,  -353,  -353,  -353,
    -353,  -353,   457,   462,   455,   753,   206,   283,   301,   473,
     473,   475,  -353,   476,   478,   480,   486,  -353,   492,   621,
     493,   477,   527,   528,   530,   531,  -353,   504,  -353,   508,
    -353,   510,   514,   512,  -353,   519,   515,  -353,   520,   532,
     533,  -353,   126,  -353,  -353,   238,   206,  -353,   536,   640,
     707,   449,   137,   534,   131,   535,   387,   542,   283,  -353,
    -353,   550,   551,   554,   555,   557,   558,   578,   586,   591,
     592,   612,   578,   131,   576,  -353,   578,   256,   583,   578,
     206,   611,   225,   578,   238,   614,  -353,    66,  -353,   131,
    -353,   788,  -353,  -353,  -353,  -353,   621,  -353,   615,   629,
    -353,  -353,   642,   676,   643,   643,   643,   643,   645,   638,
     131,   648,   644,   617,   256,   665,   661,   206,   667,   664,
     238,  -353,   671,  -353,  -353,  -353,  -353,   677,   560,  -353,
     253,   676,  -353,   676,   676,   676,  -353,  -353,  -353,  -353,
    -353,  -353,   666,  -353,  -353,   673,   668,  -353,  -353,   680,
    -353,  -353,   681,   473,   206,  -353,   258,   430,   446,   313,
      -4,  -353,  -353,  -353,  -353,  -353,   256,  -353,  -353,  -353,
     687,   698,   676,   676,   676,   676,   676,  -353,  -353,   692,
    -353,  -353,  -353,  -353,  -353,  -353
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     2,     0,     0,     0,    69,     0,     0,
       0,     0,     0,     0,     0,    12,    22,    14,     0,    16,
       0,    18,     0,    20,     0,    38,   141,     0,     0,     0,
       0,     0,     1,     9,    24,    10,     0,     0,    70,    72,
      13,    11,   106,   107,   108,   110,   109,     0,     0,     0,
     177,   180,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   211,   180,
     185,   207,   208,     0,     0,    44,    47,    45,    46,     0,
       0,   142,     0,   180,     0,     0,     0,     0,     0,     0,
       0,     0,    78,    71,    26,   180,   115,   111,    26,     0,
     178,     0,   125,     0,     0,     0,     0,     0,     0,   213,
     117,   113,    26,   137,     0,   180,   116,   112,    26,   161,
       0,   180,     0,   118,     0,   114,    26,   149,     0,    38,
       0,     0,     0,     0,    25,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    38,     0,     0,     0,     0,    38,     0,     0,    38,
       0,     0,   156,   168,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   176,   123,   171,
     172,   173,   174,   175,   128,     0,     0,   135,   140,     0,
     159,   164,     0,   180,     0,     0,     0,   147,   152,    39,
       0,   184,   206,   200,   198,   191,   195,   203,   205,   173,
     182,    40,   201,   199,   193,   197,   202,   204,   181,   183,
      43,   190,   194,   188,   189,    41,   213,   192,   196,    42,
     153,   165,     0,     0,     0,   132,     0,    78,     0,    92,
      92,     0,    76,     0,     0,    96,    95,    79,    94,     0,
      97,     0,     0,     0,     0,     0,    27,     0,   179,     0,
     126,     0,     0,     0,   138,     0,     0,   162,     0,     0,
       0,   150,   179,   154,   166,     0,     0,   130,     0,   131,
     155,   167,   143,     0,     0,     0,     0,     0,    78,    98,
      99,     0,     0,   105,   104,   103,   102,    49,    29,    30,
      32,    31,    49,     0,     0,   212,    49,     0,     0,    49,
       0,     0,   179,    49,     0,     0,   158,   156,   170,     0,
      73,     0,    90,    96,    95,    94,    93,    97,     0,     0,
     100,   101,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   144,     0,     0,     0,     0,     0,     0,
       0,   134,     0,   105,   104,   103,   102,     0,    74,    23,
       0,    53,    50,    52,    51,    54,    33,    34,    36,    35,
      15,   124,     0,    17,   136,     0,     0,    19,   160,     0,
      21,   148,     0,    92,     0,    75,   180,     0,     0,     0,
       0,    68,    67,    66,    60,   127,     0,   139,   163,   151,
       0,     0,    55,    56,    59,    57,    58,   146,    88,     0,
      61,    62,    65,    63,    64,    89
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -353,  -353,   302,     9,  -353,  -353,  -353,  -353,  -353,   588,
     -13,  -353,   323,   -68,    38,  -353,  -294,    19,  -353,   368,
     689,  -223,  -353,  -353,    51,  -246,  -353,   459,    72,  -353,
    -353,  -353,  -353,  -353,  -297,  -353,  -353,  -353,  -353,  -353,
    -352,  -353,  -353,  -353,  -353,  -353,  -284,  -353,  -353,  -353,
    -353,  -353,  -279,  -353,    29,   263,   -27,   -35
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    13,   371,    59,    67,    71,    75,    57,    15,
     183,   184,   266,    84,   342,   343,   372,   373,    17,    48,
      49,   181,   182,   257,   374,   295,   296,   259,   375,    20,
      21,   269,   314,    90,   244,   288,    22,   273,   318,    91,
     352,   385,    23,   280,   325,   283,   170,   242,    24,   276,
     321,   284,   171,   243,    94,    95,    87,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      88,   326,   386,    60,   297,    61,    38,   328,    27,    14,
      14,    96,    29,    99,   100,    26,   349,   167,   168,    16,
      16,   167,   168,    14,   293,    14,    42,    14,    14,    39,
      62,   121,   361,    16,    63,    16,   169,    16,    16,   416,
     359,   356,    64,   127,    28,    40,    31,    33,    30,    46,
      47,    18,    18,   382,   417,    41,   143,    65,    60,    69,
      61,    73,   173,    77,    85,    18,    92,    18,    98,    18,
      18,   209,    19,    19,   180,   339,   392,   401,   389,   402,
     403,   404,    32,    34,   221,    62,    19,   107,    19,    63,
      19,    19,   111,   230,   159,   185,   160,    68,   235,    44,
     159,   239,   160,   134,    88,   162,   163,   164,   165,   196,
    -157,   114,   141,   116,   117,   199,    52,    88,   420,   421,
     422,   423,   424,   206,   166,    60,    88,    61,    60,    53,
      61,    88,   237,   238,    88,   231,   232,   233,   234,    60,
      54,    61,   189,   190,   191,   192,   193,   410,    78,   119,
     248,    35,    62,  -209,  -209,    62,    63,    36,    37,    63,
      89,   204,   167,   168,    72,    55,    62,    76,    85,    60,
      63,   131,    80,  -186,   213,   214,   215,   216,   217,   218,
     219,    85,   134,   134,   134,   134,   134,   134,   134,   229,
      85,   255,    56,  -210,  -210,    85,    62,    60,    85,   105,
     132,   256,    35,   245,    60,    78,    79,    80,   101,   109,
    -187,   292,   140,  -187,    60,    78,    93,    80,   102,   291,
      60,    78,   125,    80,    62,    35,    81,    82,    63,  -187,
      47,    62,   202,   258,   104,    83,    81,    82,  -187,  -187,
     108,    62,    81,    82,   109,    83,    60,    62,   203,    80,
     110,    83,  -186,  -186,   260,  -210,  -210,   202,  -187,   173,
     112,    60,    78,   396,    80,    78,   236,    35,   303,    35,
     122,  -210,  -186,    62,   140,   289,   195,   132,   304,   115,
     116,   117,   353,    81,    82,  -210,  -210,   123,    62,  -210,
    -210,   128,    83,   173,   162,   163,   164,   165,    86,   136,
     129,   412,   -37,    25,   140,   333,   139,  -119,   140,    58,
     305,   144,   174,  -169,   134,   334,    43,   137,    45,   353,
      50,    51,  -121,   331,    66,   -77,   162,   163,   164,   165,
     173,   306,  -120,   -28,    70,   400,   186,   135,   162,   163,
     164,   165,   245,   399,   294,   363,   142,   335,   188,  -122,
     348,    74,   172,   134,   351,   364,   415,   355,   245,   194,
     197,   358,   198,   145,   146,   147,   148,   411,   337,   200,
     201,   353,   149,   150,   113,   114,   151,   116,   117,   245,
     159,   207,   160,   208,   152,   210,   211,   365,   240,   134,
       2,     3,     4,     5,     6,   205,   247,     7,   241,   397,
       8,   246,    86,     9,    10,    11,   253,   254,   366,   113,
     114,   115,   116,   117,   220,    86,   222,   223,   224,   225,
     226,   227,   228,   249,    86,   153,   154,   155,   156,    86,
     250,   268,    86,   252,   157,   158,   159,   261,   160,   153,
     154,   155,   156,   267,   270,   271,   161,   272,   157,   158,
     159,   274,   160,   145,   146,   147,   148,   275,   277,   278,
    -157,   279,   149,   150,   113,   114,   151,   116,   117,   153,
     154,   155,   156,   413,   162,   163,   164,   165,   157,   158,
     159,   281,   160,   162,   163,   164,   165,    -3,     1,   414,
       2,     3,     4,     5,     6,   282,   160,     7,   176,   195,
       8,   285,   287,     9,    10,    11,   286,    -8,     1,   290,
       2,     3,     4,     5,     6,   -91,   298,     7,   307,   299,
       8,   300,   -82,     9,    10,    11,    -7,     1,   -81,     2,
       3,     4,     5,     6,   -80,   -83,     7,   308,   309,     8,
     310,   311,     9,    10,    11,   312,    -6,     1,   327,     2,
       3,     4,     5,     6,   313,   316,     7,   315,   317,     8,
     319,   320,     9,    10,    11,    -4,     1,   322,     2,     3,
       4,     5,     6,   323,    46,     7,   330,   332,     8,   324,
     329,     9,    10,    11,   338,    -5,     1,   327,     2,     3,
       4,     5,     6,   340,   341,     7,   -87,   -86,     8,   -85,
     -84,     9,    10,    11,   145,   146,   147,   148,   113,   114,
     151,   116,   117,   149,   150,   113,   114,   151,   116,   117,
     -48,   187,   350,   327,     2,     3,     4,     5,     6,   354,
     344,     7,   367,   398,     8,   345,   346,     9,    10,    11,
     301,   302,   153,   154,   155,   156,   106,   262,   263,   264,
     265,   157,   158,   159,   120,   160,   347,   357,   126,   211,
     360,  -145,   133,   145,   146,   147,   148,   376,   377,   378,
     379,   368,   149,   150,   113,   114,   151,   116,   117,     2,
       3,     4,     5,     6,   369,   381,     7,   380,   370,     8,
     383,   384,     9,    10,    11,   162,   163,   164,   165,   162,
     163,   164,   165,   162,   163,   164,   165,   387,   388,   390,
     178,   391,   393,   405,   179,   407,   394,   406,   212,   162,
     163,   164,   165,   162,   163,   164,   165,   408,   409,   418,
     153,   154,   155,   156,   251,   425,   395,   103,   419,   157,
     158,   159,     0,   160,   113,   114,   115,   116,   117,   113,
     114,   115,   116,   117,     0,   336,     0,   118,     0,     0,
       0,     0,   124,   113,   114,   115,   116,   117,   113,   114,
     115,   116,   117,     0,     0,     0,   130,     0,     0,     0,
       0,   138,   113,   114,   115,   116,   117,   113,   114,   115,
     116,   117,     0,     0,     0,   175,     0,  -133,   113,   114,
     115,   116,   117,     0,     0,     0,     0,   177,   113,   114,
     115,   116,   117,     0,   187,   113,   114,   151,   116,   117,
       0,   187,   113,   114,   115,   116,   117,     0,   362
};

static const yytype_int16 yycheck[] =
{
      35,   285,   354,     8,   250,    10,    39,   286,    10,     0,
       1,    38,    10,    40,    41,    10,   313,    25,    26,     0,
       1,    25,    26,    14,   247,    16,     0,    18,    19,    39,
      35,    66,   329,    14,    39,    16,    44,    18,    19,    43,
     324,   320,    47,    70,    46,    39,    10,    10,    46,    14,
      15,     0,     1,   350,   406,    39,    83,    28,     8,    30,
      10,    32,    89,    34,    35,    14,    37,    16,    39,    18,
      19,   139,     0,     1,   101,   298,   360,   371,   357,   373,
     374,   375,    46,    46,   152,    35,    14,    58,    16,    39,
      18,    19,    63,   161,    34,   108,    36,    47,   166,    43,
      34,   169,    36,    74,   139,    25,    26,    27,    28,   122,
      44,    35,    83,    37,    38,   128,    43,   152,   412,   413,
     414,   415,   416,   136,    44,     8,   161,    10,     8,    43,
      10,   166,   167,   168,   169,   162,   163,   164,   165,     8,
      43,    10,   113,   114,   115,   116,   117,   393,     9,    10,
     177,    39,    35,    27,    28,    35,    39,    45,    46,    39,
      46,   132,    25,    26,    47,    43,    35,    47,   139,     8,
      39,    10,    11,    47,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   182,    43,    27,    28,   166,    35,     8,   169,    10,
      39,   182,    39,   174,     8,     9,    10,    11,    39,    46,
      44,   246,    46,    47,     8,     9,    10,    11,    41,   246,
       8,     9,    10,    11,    35,    39,    30,    31,    39,    43,
      15,    35,    46,   182,    39,    39,    30,    31,    27,    28,
      39,    35,    30,    31,    46,    39,     8,    35,    10,    11,
       8,    39,    27,    28,   182,    27,    28,    46,    47,   286,
      10,     8,     9,    10,    11,     9,    10,    39,   259,    39,
      39,    43,    47,    35,    46,   246,    46,    39,   259,    36,
      37,    38,   317,    30,    31,    27,    28,    10,    35,    27,
      28,    39,    39,   320,    25,    26,    27,    28,    35,    39,
      10,    43,    40,     1,    46,   296,    44,    43,    46,    45,
     259,    40,    46,    44,   285,   296,    14,    10,    16,   354,
      18,    19,    43,   294,    45,    42,    25,    26,    27,    28,
     357,   259,    43,    40,    45,   370,     8,    74,    25,    26,
      27,    28,   313,   370,    43,   336,    83,   296,    45,    43,
     312,    45,    89,   324,   316,   336,    43,   319,   329,    10,
      45,   323,    10,    23,    24,    25,    26,   394,   296,    45,
      10,   406,    32,    33,    34,    35,    36,    37,    38,   350,
      34,    45,    36,    10,    44,     8,    40,   336,    47,   360,
       3,     4,     5,     6,     7,   132,    41,    10,    47,   370,
      13,    45,   139,    16,    17,    18,    19,    20,   336,    34,
      35,    36,    37,    38,   151,   152,   153,   154,   155,   156,
     157,   158,   159,    41,   161,    23,    24,    25,    26,   166,
      41,    47,   169,    42,    32,    33,    34,    40,    36,    23,
      24,    25,    26,    40,    45,     8,    44,    40,    32,    33,
      34,    45,    36,    23,    24,    25,    26,    40,    45,     8,
      44,    40,    32,    33,    34,    35,    36,    37,    38,    23,
      24,    25,    26,    43,    25,    26,    27,    28,    32,    33,
      34,    45,    36,    25,    26,    27,    28,     0,     1,    43,
       3,     4,     5,     6,     7,    47,    36,    10,    40,    46,
      13,    44,    47,    16,    17,    18,    44,     0,     1,   246,
       3,     4,     5,     6,     7,    42,    41,    10,    41,    43,
      13,    43,    42,    16,    17,    18,     0,     1,    42,     3,
       4,     5,     6,     7,    42,    42,    10,    10,    10,    13,
      10,    10,    16,    17,    18,    41,     0,     1,   285,     3,
       4,     5,     6,     7,    46,    41,    10,    47,    46,    13,
      41,    46,    16,    17,    18,     0,     1,    47,     3,     4,
       5,     6,     7,    41,    14,    10,    42,    42,    13,    46,
      44,    16,    17,    18,    42,     0,     1,   324,     3,     4,
       5,     6,     7,    43,    43,    10,    42,    42,    13,    42,
      42,    16,    17,    18,    23,    24,    25,    26,    34,    35,
      36,    37,    38,    32,    33,    34,    35,    36,    37,    38,
      42,    40,    46,   360,     3,     4,     5,     6,     7,    46,
      44,    10,    17,   370,    13,    44,    44,    16,    17,    18,
      19,    20,    23,    24,    25,    26,    58,     4,     5,     6,
       7,    32,    33,    34,    66,    36,    44,    46,    70,    40,
      46,    44,    74,    23,    24,    25,    26,   344,   345,   346,
     347,    42,    32,    33,    34,    35,    36,    37,    38,     3,
       4,     5,     6,     7,    42,    47,    10,    42,    12,    13,
      42,    47,    16,    17,    18,    25,    26,    27,    28,    25,
      26,    27,    28,    25,    26,    27,    28,    42,    47,    42,
      40,    47,    41,    47,    40,    47,    39,    44,    40,    25,
      26,    27,    28,    25,    26,    27,    28,    47,    47,    42,
      23,    24,    25,    26,    40,    43,   368,    48,    40,    32,
      33,    34,    -1,    36,    34,    35,    36,    37,    38,    34,
      35,    36,    37,    38,    -1,   296,    -1,    47,    -1,    -1,
      -1,    -1,    47,    34,    35,    36,    37,    38,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    47,    34,    35,    36,    37,    38,    34,    35,    36,
      37,    38,    -1,    -1,    -1,    47,    -1,    44,    34,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    43,    34,    35,
      36,    37,    38,    -1,    40,    34,    35,    36,    37,    38,
      -1,    40,    34,    35,    36,    37,    38,    -1,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,    10,    13,    16,
      17,    18,    49,    50,    51,    57,    65,    66,    72,    76,
      77,    78,    84,    90,    96,    50,    10,    10,    46,    10,
      46,    10,    46,    10,    46,    39,    45,    46,    39,    39,
      39,    39,     0,    50,    43,    50,    14,    15,    67,    68,
      50,    50,    43,    43,    43,    43,    43,    56,    45,    52,
       8,    10,    35,    39,    47,   102,    45,    53,    47,   102,
      45,    54,    47,   102,    45,    55,    47,   102,     9,    10,
      11,    30,    31,    39,    61,   102,   103,   104,   105,    46,
      81,    87,   102,    10,   102,   103,   104,   105,   102,   104,
     104,    39,    41,    68,    39,    10,    57,   102,    39,    46,
       8,   102,    10,    34,    35,    36,    37,    38,    47,    10,
      57,   105,    39,    10,    47,    10,    57,   104,    39,    10,
      47,    10,    39,    57,   102,   103,    39,    10,    47,    44,
      46,   102,   103,   104,    40,    23,    24,    25,    26,    32,
      33,    36,    44,    23,    24,    25,    26,    32,    33,    34,
      36,    44,    25,    26,    27,    28,    44,    25,    26,    44,
      94,   100,   103,   104,    46,    47,    40,    43,    40,    40,
     104,    69,    70,    58,    59,    58,     8,    40,    45,   102,
     102,   102,   102,   102,    10,    46,    58,    45,    10,    58,
      45,    10,    46,    10,   102,   103,    58,    45,    10,    61,
       8,    40,    40,   102,   102,   102,   102,   102,   102,   102,
     103,    61,   103,   103,   103,   103,   103,   103,   103,   102,
      61,   104,   104,   104,   104,    61,    10,   105,   105,    61,
      47,    47,    95,   101,    82,   102,    45,    41,   104,    41,
      41,    40,    42,    19,    20,    51,    65,    71,    72,    75,
      76,    40,     4,     5,     6,     7,    60,    40,    47,    79,
      45,     8,    40,    85,    45,    40,    97,    45,     8,    40,
      91,    45,    47,    93,    99,    44,    44,    47,    83,   102,
     103,   104,   105,    69,    43,    73,    74,    73,    41,    43,
      43,    19,    20,    51,    65,    72,    76,    41,    10,    10,
      10,    10,    41,    46,    80,    47,    41,    46,    86,    41,
      46,    98,    47,    41,    46,    92,    94,   103,   100,    44,
      42,   102,    42,    51,    65,    72,    75,    76,    42,    69,
      43,    43,    62,    63,    44,    44,    44,    44,    62,    82,
      46,    62,    88,   105,    46,    62,   100,    46,    62,    94,
      46,    82,    40,    51,    65,    72,    76,    17,    42,    42,
      12,    51,    64,    65,    72,    76,    60,    60,    60,    60,
      42,    47,    82,    42,    47,    89,    88,    42,    47,   100,
      42,    47,    94,    41,    39,    67,    10,   102,   103,   104,
     105,    64,    64,    64,    64,    47,    44,    47,    47,    47,
      73,   104,    43,    43,    43,    43,    43,    88,    42,    40,
      64,    64,    64,    64,    64,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    52,    51,    53,    51,    54,    51,
      55,    51,    56,    51,    51,    57,    59,    58,    58,    60,
      60,    60,    60,    60,    60,    60,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    62,    63,
      62,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    65,
      65,    65,    65,    66,    67,    67,    68,    69,    70,    69,
      71,    71,    71,    71,    71,    71,    71,    71,    72,    72,
      72,    73,    74,    73,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    76,    76,    76,
      76,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    79,    78,    78,    80,    78,    78,    81,
      78,    78,    82,    83,    82,    85,    84,    84,    86,    84,
      84,    87,    84,    84,    88,    89,    88,    91,    90,    90,
      92,    90,    90,    93,    90,    90,    94,    95,    94,    97,
      96,    96,    98,    96,    96,    99,    96,    96,   100,   101,
     100,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   105,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     0,     9,     0,     9,     0,     9,
       0,     9,     0,     9,     2,     4,     0,     2,     0,     2,
       2,     2,     2,     4,     4,     4,     4,     1,     0,     3,
       3,     3,     3,     3,     1,     1,     1,     1,     0,     0,
       2,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       2,     4,     4,     4,     4,     4,     2,     2,     2,     1,
       2,     3,     2,     7,     7,     8,     4,     0,     0,     2,
       1,     1,     1,     1,     2,     2,     2,     2,    11,    12,
       7,     0,     0,     2,     1,     1,     1,     1,     2,     2,
       3,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     2,
       2,     2,     2,     0,     9,     4,     0,    10,     5,     0,
       6,     6,     1,     0,     4,     0,     9,     4,     0,    10,
       5,     0,     3,     6,     1,     0,     4,     0,     9,     4,
       0,    10,     5,     0,     6,     6,     1,     0,     4,     0,
       9,     4,     0,    10,     5,     0,     6,     6,     1,     0,
       4,     3,     3,     3,     3,     3,     3,     1,     2,     4,
       1,     3,     3,     3,     3,     1,     4,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     4,
       1,     1,     4,     1
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
        case 14:
#line 127 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena),func,Int,numlin);}
#line 1641 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 127 "bison-jaguar.y" /* yacc.c:1646  */
    {notFunction();}
#line 1647 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 128 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena),func,Char,numlin);}
#line 1653 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 128 "bison-jaguar.y" /* yacc.c:1646  */
    {notFunction();}
#line 1659 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena),func,Bool,numlin);}
#line 1665 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 129 "bison-jaguar.y" /* yacc.c:1646  */
    {notFunction();}
#line 1671 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 130 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena),func,String,numlin);}
#line 1677 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 130 "bison-jaguar.y" /* yacc.c:1646  */
    {notFunction();}
#line 1683 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 131 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena),func,Void,numlin);}
#line 1689 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 131 "bison-jaguar.y" /* yacc.c:1646  */
    {notFunction();}
#line 1695 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 138 "bison-jaguar.y" /* yacc.c:1646  */
    {current_scope++;}
#line 1701 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 139 "bison-jaguar.y" /* yacc.c:1646  */
    {current_scope++;}
#line 1707 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 143 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena),param,Int,numlin);}
#line 1713 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 144 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena),param,Char,numlin);}
#line 1719 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 145 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena),param,String,numlin);}
#line 1725 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 146 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena),param,Bool,numlin);}
#line 1731 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 147 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[-2].cadena),param,Int,numlin);}
#line 1737 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 148 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[-2].cadena),param,Char,numlin);}
#line 1743 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 149 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[-2].cadena),param,String,numlin);}
#line 1749 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 150 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[-2].cadena),param,Bool,numlin);}
#line 1755 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 167 "bison-jaguar.y" /* yacc.c:1646  */
    {isFunction();}
#line 1761 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 210 "bison-jaguar.y" /* yacc.c:1646  */
    {current_scope++;}
#line 1767 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 210 "bison-jaguar.y" /* yacc.c:1646  */
    {finBloque();}
#line 1773 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 230 "bison-jaguar.y" /* yacc.c:1646  */
    {current_scope++;}
#line 1779 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 230 "bison-jaguar.y" /* yacc.c:1646  */
    {finBloque();}
#line 1785 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 287 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = ins((yyvsp[-2].cadena), var, Int, numlin); if(r != NULL) {r->int_type=(yyvsp[0].entero);printf("Valor Bison-> %d\n",(yyvsp[0].entero));printValorRegistro(r);}}
#line 1791 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 289 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = ins((yyvsp[-2].cadena), var, Bool, numlin); if(r != NULL) {r->bool_type=(yyvsp[0].booleano);printf("Valor Bison-> %d\n",(yyvsp[0].booleano));printValorRegistro(r);}}
#line 1797 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 291 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = ins((yyvsp[-2].cadena), var, CHAR, numlin); if(r != NULL) {r->char_type=(yyvsp[0].caracter);printf("Valor Bison-> %c\n",(yyvsp[0].caracter));printValorRegistro(r);}}
#line 1803 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 293 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = ins((yyvsp[-2].cadena), var, Int, numlin); if(r != NULL) {r->string_type=(yyvsp[0].cadena);printf("Valor Bison-> %s\n",(yyvsp[0].cadena));printValorRegistro(r);}}
#line 1809 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 298 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena), var, Int, numlin);}
#line 1815 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 299 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena), var, Bool, numlin);}
#line 1821 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 300 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena), var, Char, numlin);}
#line 1827 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 301 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena), var, String, numlin);}
#line 1833 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 337 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[-1].cadena), varV, Int, numlin);}
#line 1839 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 337 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 1845 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 338 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena), varV, Int, numlin);}
#line 1851 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 339 "bison-jaguar.y" /* yacc.c:1646  */
    {cambiarTamVector((yyvsp[-3].entero)); ins((yyvsp[-1].cadena), varV, Int, numlin);}
#line 1857 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 339 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 1863 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 340 "bison-jaguar.y" /* yacc.c:1646  */
    {cambiarTamVector((yyvsp[-2].entero)); ins((yyvsp[0].cadena), varV, Int, numlin);}
#line 1869 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 341 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = busq((yyvsp[-1].cadena)); if(r!=NULL) punteroVector = r; else yyerror("Vector no encontrado");}
#line 1875 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 341 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 1881 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 342 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = busq((yyvsp[-5].cadena)); if(r!=NULL) setVectorI(r, (yyvsp[-3].entero), (yyvsp[0].entero)); else yyerror("Vector no encontrado");}
#line 1887 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 351 "bison-jaguar.y" /* yacc.c:1646  */
    {if(punteroVector != NULL) insVectorInt((yyvsp[0].entero));}
#line 1893 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 352 "bison-jaguar.y" /* yacc.c:1646  */
    {if(punteroVector != NULL) insVectorInt((yyvsp[0].entero));}
#line 1899 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 355 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[-1].cadena), varV, Char, numlin);}
#line 1905 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 355 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 1911 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 356 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena), varV, Char, numlin);}
#line 1917 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 357 "bison-jaguar.y" /* yacc.c:1646  */
    {cambiarTamVector((yyvsp[-3].entero)); ins((yyvsp[-1].cadena), varV, Char, numlin);}
#line 1923 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 357 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 1929 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 358 "bison-jaguar.y" /* yacc.c:1646  */
    {cambiarTamVector((yyvsp[-2].entero)); ins((yyvsp[0].cadena), varV, Char, numlin);}
#line 1935 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 359 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = busq((yyvsp[-1].cadena)); if(r!=NULL) punteroVector = r; else yyerror("Vector no encontrado");}
#line 1941 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 359 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 1947 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 360 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = busq((yyvsp[-5].cadena)); if(r!=NULL) setVectorC(r, (yyvsp[-3].entero), (yyvsp[0].caracter)); else yyerror("Vector no encontrado");}
#line 1953 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 372 "bison-jaguar.y" /* yacc.c:1646  */
    {insVectorChar((yyvsp[0].caracter));}
#line 1959 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 373 "bison-jaguar.y" /* yacc.c:1646  */
    {insVectorChar((yyvsp[0].caracter));}
#line 1965 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 376 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[-1].cadena), varV, String, numlin);}
#line 1971 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 376 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 1977 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 377 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena), varV, String, numlin);}
#line 1983 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 378 "bison-jaguar.y" /* yacc.c:1646  */
    {cambiarTamVector((yyvsp[-3].entero)); ins((yyvsp[-1].cadena), varV, String, numlin);}
#line 1989 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 378 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 1995 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 379 "bison-jaguar.y" /* yacc.c:1646  */
    {cambiarTamVector((yyvsp[-2].entero)); ins((yyvsp[0].cadena), varV, String, numlin);}
#line 2001 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 380 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = busq((yyvsp[-4].cadena)); if(r!=NULL) punteroVector = r; else yyerror("Vector no encontrado");}
#line 2007 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 380 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 2013 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 381 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = busq((yyvsp[-5].cadena)); if(r!=NULL) setVectorS(r, (yyvsp[-3].entero), (yyvsp[0].cadena)); else yyerror("Vector no encontrado");}
#line 2019 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 392 "bison-jaguar.y" /* yacc.c:1646  */
    {insVectorString((yyvsp[0].cadena));}
#line 2025 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 393 "bison-jaguar.y" /* yacc.c:1646  */
    {insVectorString((yyvsp[0].cadena));}
#line 2031 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 396 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[-1].cadena), varV, Bool, numlin);}
#line 2037 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 396 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 2043 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 397 "bison-jaguar.y" /* yacc.c:1646  */
    {ins((yyvsp[0].cadena), varV, Bool, numlin);}
#line 2049 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 398 "bison-jaguar.y" /* yacc.c:1646  */
    {cambiarTamVector((yyvsp[-3].entero)); ins((yyvsp[-1].cadena), varV, Bool, numlin);}
#line 2055 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 398 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 2061 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 399 "bison-jaguar.y" /* yacc.c:1646  */
    {cambiarTamVector((yyvsp[-2].entero)); ins((yyvsp[0].cadena), varV, Bool, numlin);}
#line 2067 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 400 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = busq((yyvsp[-4].cadena)); if(r!=NULL) punteroVector = r; else yyerror("Vector no encontrado");}
#line 2073 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 400 "bison-jaguar.y" /* yacc.c:1646  */
    {chequearTamVector();}
#line 2079 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 401 "bison-jaguar.y" /* yacc.c:1646  */
    {struct reg *r = busq((yyvsp[-5].cadena)); if(r!=NULL) setVectorB(r, (yyvsp[-3].entero), (yyvsp[0].booleano)); else yyerror("Vector no encontrado");}
#line 2085 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 412 "bison-jaguar.y" /* yacc.c:1646  */
    {insVectorBool((yyvsp[0].booleano));}
#line 2091 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 413 "bison-jaguar.y" /* yacc.c:1646  */
    {insVectorBool((yyvsp[0].booleano));}
#line 2097 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 417 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[-2].entero) + (yyvsp[0].entero);}
#line 2103 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 418 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[-2].entero) - (yyvsp[0].entero);}
#line 2109 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 419 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[-2].entero) * (yyvsp[0].entero);}
#line 2115 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 420 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[-2].entero) / (yyvsp[0].entero);}
#line 2121 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 421 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.entero) = powJ((yyvsp[-2].entero),(yyvsp[0].entero));}
#line 2127 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 422 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[-1].entero);}
#line 2133 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 423 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.entero) = (yyvsp[0].entero);}
#line 2139 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 424 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.entero) = -(yyvsp[0].entero);}
#line 2145 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 425 "bison-jaguar.y" /* yacc.c:1646  */
    {printf("soy un elemento de un vector");}
#line 2151 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 426 "bison-jaguar.y" /* yacc.c:1646  */
    {printf("soy una variable");}
#line 2157 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 430 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.cadena) = strcat((yyvsp[-2].cadena),(yyvsp[0].cadena));}
#line 2163 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 431 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.cadena) = concN((yyvsp[0].cadena),(yyvsp[-2].entero));}
#line 2169 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 432 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.cadena) = concN((yyvsp[-2].cadena),(yyvsp[0].entero));}
#line 2175 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 433 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.cadena) = (yyvsp[-1].cadena);}
#line 2181 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 434 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.cadena) = (yyvsp[0].cadena);}
#line 2187 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 435 "bison-jaguar.y" /* yacc.c:1646  */
    {printf("soy un elemento de un vector");}
#line 2193 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 436 "bison-jaguar.y" /* yacc.c:1646  */
    {printf("soy una variable");}
#line 2199 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 440 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (yyvsp[-2].booleano) * (yyvsp[0].booleano);}
#line 2205 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 441 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].booleano)+(yyvsp[0].booleano) >= 1) 			? 1: 0;}
#line 2211 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 442 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].booleano) == (yyvsp[0].booleano))  			? 1: 0;}
#line 2217 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 443 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].entero) == (yyvsp[0].entero))  			? 1: 0;}
#line 2223 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 444 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].caracter) == (yyvsp[0].caracter))  			? 1: 0;}
#line 2229 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 445 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (strcmp((yyvsp[-2].cadena), (yyvsp[0].cadena)) == 0) ? 1: 0;}
#line 2235 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 446 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].booleano) == (yyvsp[0].booleano))  			? 0: 1;}
#line 2241 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 195:
#line 447 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].entero) == (yyvsp[0].entero))  			? 0: 1;}
#line 2247 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 448 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].caracter) == (yyvsp[0].caracter))  			? 0: 1;}
#line 2253 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 449 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (strcmp((yyvsp[-2].cadena), (yyvsp[0].cadena)) == 0) ? 0: 1;}
#line 2259 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 450 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].entero) >= (yyvsp[0].entero))  			? 1: 0;}
#line 2265 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 451 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (strcmp((yyvsp[-2].cadena), (yyvsp[0].cadena)) >= 0) ? 1: 0;}
#line 2271 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 452 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].entero) <= (yyvsp[0].entero))  			? 1: 0;}
#line 2277 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 453 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (strcmp((yyvsp[-2].cadena), (yyvsp[0].cadena)) <= 0) ? 1: 0;}
#line 2283 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 454 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (strcmp((yyvsp[-2].cadena), (yyvsp[0].cadena))  > 0) ? 1: 0;}
#line 2289 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 455 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].entero) > (yyvsp[0].entero))  			? 1: 0;}
#line 2295 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 456 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (strcmp((yyvsp[-2].cadena), (yyvsp[0].cadena))  < 0) ? 1: 0;}
#line 2301 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 457 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = ((yyvsp[-2].entero) < (yyvsp[0].entero))  			? 1: 0;}
#line 2307 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 458 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (yyvsp[-1].booleano);}
#line 2313 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 459 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (yyvsp[0].booleano);}
#line 2319 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 460 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.booleano) = (yyvsp[0].booleano);}
#line 2325 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 461 "bison-jaguar.y" /* yacc.c:1646  */
    {printf("soy un elemento de un vector");}
#line 2331 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 462 "bison-jaguar.y" /* yacc.c:1646  */
    {printf("soy una variable");}
#line 2337 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 465 "bison-jaguar.y" /* yacc.c:1646  */
    {(yyval.caracter) = (yyvsp[0].caracter);}
#line 2343 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 466 "bison-jaguar.y" /* yacc.c:1646  */
    {printf("soy un elemento de un vector");}
#line 2349 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 467 "bison-jaguar.y" /* yacc.c:1646  */
    {printf("soy una variable");}
#line 2355 "bison-jaguar.tab.c" /* yacc.c:1646  */
    break;


#line 2359 "bison-jaguar.tab.c" /* yacc.c:1646  */
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
#line 470 "bison-jaguar.y" /* yacc.c:1906  */

int powJ(int a, int b){
	int n = 1;
	int num = a;
	if (b == 0){
		return 1;
	}else{
		int i;
		for(i = 0; i<b; i++){
			num = num * a;
		}
		return num;
	}
}

void lol(){
	printf("lol");
}

char* concN (char* string, int n){
	int i = 0;
	char* concatenado = malloc(strlen(string)*n);

		for(i=0; i<n; i++){
			strcat(concatenado,string);
		}

	return concatenado;
}

void yyerror (char* mens){
	printf("mal, revisate la línea %i: %s\n", numlin, mens);
}

int main (int argc, char** argv){
	if (argc>1) yyin=fopen(argv[1],"r");	//Abrimos el Programa escrito en Jaguar
	if (argc>2) obj=fopen(argv[2],"w");		//Abrimos el Fichero resultado
	lol();
	fprintf(obj, "#include \"Q.h\"\nBEGIN\n");	//comienzo generacion de código
	yyparse();							//Ejecutamos el parser
	fprintf(obj, "END\n");				//Final generación de código.
	
	printTodo();		//Printeamos lo que quede de la tabla de simbo
	//finBloque();
	fclose(yyin);		//Cerramos el programa escrito en Jaguar
	fclose(obj);		//Cerramos el programa escrito en Jaguar
	return 0;			//Si todo termina bien, devolvemos 0
}		
