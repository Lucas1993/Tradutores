/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include "lex.yy.c"

/*Macro para alocar e inicializar a struct toda com 0*/
#define NEW(TYPE) memset(malloc(sizeof(TYPE)), 0, sizeof(TYPE))

void yyerror(const char *str) {    
    printf("%d:%d: %s\n", line, col, str);
}

#line 79 "parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    WILDSCORE = 259,
    FLOAT = 260,
    BOOLVAL = 261,
    BOOL = 262,
    NUMBER = 263,
    FLOATNUM = 264,
    INTEGER = 265,
    IF = 266,
    ELSE = 267,
    THEN = 268,
    WHILE = 269,
    WHERE = 270,
    YIELD = 271,
    DO = 272,
    PRINT = 273,
    READBOOL = 274,
    READFLOAT = 275,
    READINT = 276,
    RARROW = 277,
    LARROW = 278,
    DIFF = 279,
    EQUALS = 280,
    DOUBLECOLON = 281,
    APPEND = 282,
    AND = 283,
    OR = 284,
    LEQ = 285,
    GEQ = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 46 "parser.y" /* yacc.c:355  */

    while_t* while_f;          
    io_t* io_f;             
    stmt_t* stmt_f;           
    stmts_t* stmts_f;          
    proc_t* proc_f;           
    list_t* list_f;           
    appexpr_t* appexpr_f;        
    nonapp_t* nonapp_f;        
    where_t* where_f;          
    exprs_t* exprs_f;       
    op_t* op_f;             
    yieldexpr_t* yieldexpr_f;      
    ifexpr_t* ifexpr_f;         
    expr_t* expr_f;           
    basic_type_t* basic_type_f;     
    funtype_t* funtype_f;        
    funtype_decl_t* funtype_decl_f;   
    basic_val_t* basic_val_f;      
    arg_t* arg_f;            
    fun_t* fun_f;            
    lines_t* lines_f;          
    line_t* line_f;           
    args_t* args_f;           
    program_t* program_f;        
    list_args_t* list_args_f;      
    built_list_val_t* built_list_val_f; 
    list_value_t* list_value_f;
    char* str;
    int intval;
    float floatval;
    int boolval;

#line 185 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 200 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   362

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  100
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

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
       2,     2,     2,     2,     2,     2,     2,    46,     2,     2,
      34,    35,    47,    44,    39,    45,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    33,
      42,    32,    43,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    40,     2,    41,     2,     2,     2,     2,
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
       0,   121,   121,   129,   135,   143,   149,   155,   164,   172,
     181,   188,   199,   206,   212,   218,   225,   231,   240,   246,
     252,   258,   264,   272,   279,   287,   294,   304,   309,   318,
     321,   329,   339,   345,   351,   361,   366,   371,   376,   382,
     387,   395,   403,   413,   419,   428,   435,   441,   447,   456,
     466,   472,   478,   487,   495,   504,   512,   521,   529,   537,
     545,   553,   561,   569,   578,   586,   594,   603,   611,   619,
     628,   629,   638,   639,   640,   649,   655,   661,   667,   676,
     681,   691,   694,   701,   709,   716,   724,   730,   740,   745,
     754,   761,   768,   775,   781,   787,   796,   801,   806,   811,
     820
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "WILDSCORE", "FLOAT", "BOOLVAL",
  "BOOL", "NUMBER", "FLOATNUM", "INTEGER", "IF", "ELSE", "THEN", "WHILE",
  "WHERE", "YIELD", "DO", "PRINT", "READBOOL", "READFLOAT", "READINT",
  "RARROW", "LARROW", "DIFF", "EQUALS", "DOUBLECOLON", "APPEND", "AND",
  "OR", "LEQ", "GEQ", "'='", "';'", "'('", "')'", "':'", "'['", "']'",
  "','", "'{'", "'}'", "'<'", "'>'", "'+'", "'-'", "'%'", "'*'", "'/'",
  "$accept", "program", "line_elems", "line_elem", "fundecl", "args",
  "arg_value", "basic_value", "list_value", "list_args",
  "built_list_value", "funtype_decl", "funtype", "basic_type", "appexpr",
  "nonapp", "expr", "ifexpr", "yieldexpr", "op_prec1", "op_prec2",
  "op_prec3", "op_prec4", "op_prec5", "op_prec6", "op_prec7", "op_prec8",
  "exprs", "list_expr", "where_exp", "procdecl", "stmts", "stmt",
  "io_stmt", "while_expr", YY_NULLPTR
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
     285,   286,    61,    59,    40,    41,    58,    91,    93,    44,
     123,   125,    60,    62,    43,    45,    37,    42,    47
};
# endif

#define YYPACT_NINF -116

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define YYTABLE_NINF -45

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      10,   263,    18,  -116,    10,  -116,  -116,  -116,  -116,   -15,
    -116,  -116,  -116,     7,    44,   271,   248,    -8,   284,    -9,
    -116,  -116,  -116,  -116,   295,  -116,  -116,  -116,  -116,   304,
     323,    -1,    12,   228,    48,     3,   160,   204,    99,   103,
     193,   193,    -7,  -116,  -116,  -116,     9,    59,    49,   -16,
      31,    28,  -116,  -116,   -15,  -116,    53,  -116,    51,    56,
     213,  -116,   295,    61,    -9,  -116,  -116,    63,    64,    62,
    -116,     7,    88,   193,  -116,  -116,   140,    68,  -116,    71,
      75,   160,  -116,  -116,   160,  -116,  -116,  -116,    94,  -116,
    -116,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,  -116,   316,   102,    95,
       0,  -116,  -116,  -116,  -116,   105,   119,   113,   228,  -116,
    -116,  -116,   117,   111,   140,   120,   122,   328,   228,  -116,
     127,   129,    10,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,    31,    31,    28,  -116,  -116,  -116,   295,
     140,  -116,  -116,   228,   172,   228,  -116,  -116,   142,  -116,
    -116,  -116,  -116,  -116,  -116,   124,  -116,   126,   131,   146,
     149,   151,   152,  -116,  -116,   142,   177,  -116,  -116,  -116,
     158,  -116,   163,   140,   228,   159,   167,  -116,  -116
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     5,     7,     6,    21,    14,
      20,    18,    19,     0,     0,     0,     0,     0,    13,    16,
      15,    26,     1,     3,     0,    39,    36,    37,    35,     0,
       0,     0,    32,     0,     0,     0,     0,     0,     0,    75,
      46,     0,     0,    47,    48,    45,    54,    56,    63,    66,
      69,    71,    74,    76,     0,    22,     0,    29,    27,     0,
       0,    12,     0,     0,     0,    25,    40,     0,     0,     0,
      31,     0,     0,    51,    50,    52,     0,     0,    82,    79,
       0,     0,    75,    78,     0,    43,    41,    42,     0,    10,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,     0,    30,     0,
       0,    23,    33,    38,    34,     0,    21,     0,     0,    98,
      97,    96,     0,     0,    88,     0,     0,    77,     0,    81,
       0,     0,     0,    53,    55,    58,    57,    60,    62,    59,
      61,    65,    64,    67,    68,    70,    72,    73,    28,     0,
       0,     8,     9,     0,     0,     0,    99,    93,    86,    89,
      95,    94,    80,    77,    44,     0,    24,     0,     0,     0,
       0,     0,     0,    87,    83,    84,     0,    90,    92,    91,
       0,    85,     0,     0,     0,     0,     0,   100,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,    -2,  -116,  -116,   186,   -12,    24,   -17,   104,
    -116,  -116,   -13,   184,   189,    -4,   -14,   191,  -116,   -28,
     134,   249,   -69,  -116,   -18,   115,   -33,   100,  -116,  -109,
    -116,  -115,  -116,    78,    79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,     5,    17,    18,    39,    20,    59,
      21,     6,    31,    32,    40,    41,   122,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    80,    53,    90,
       7,   123,   124,   125,   126
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      42,   152,    23,    56,    58,    83,    75,    65,    88,   159,
      25,    99,    26,     1,    27,    88,    67,    28,    22,    72,
     100,    24,    77,    79,    60,    19,    89,    62,   101,   102,
     141,   142,    70,   151,    71,   167,    86,    87,    91,    19,
      19,    29,    19,    76,    30,   111,   110,     8,    64,   173,
      10,     8,    11,    12,    10,    33,    11,    12,   114,    33,
      34,    35,    82,   133,    85,    85,   181,   130,   185,    86,
     131,   146,   147,    93,    94,   104,   105,   103,    36,    95,
      96,    37,    36,   143,   144,    37,    64,    92,   106,    38,
     107,    97,    98,    38,   108,    58,    55,    85,   112,    66,
     113,   115,     8,   127,   156,    10,   -43,    11,    12,   -43,
     128,   -43,   -43,   129,    79,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    82,    82,
     165,    19,   166,    81,   132,   150,    37,   -43,   149,   168,
     169,   172,   154,   116,    38,   153,    10,   155,    11,    12,
     157,    33,   158,   160,   117,   161,    34,    88,   118,   119,
     120,   121,   163,     8,   164,   174,    10,   175,    11,    12,
     186,    33,   176,    64,    36,     8,    34,    37,    10,   177,
      11,    12,   178,    33,   179,    38,   117,   180,    34,   182,
     118,   119,   120,   121,    36,    55,     8,    37,   183,    10,
     187,    11,    12,   184,    61,    38,    36,     8,   188,    37,
      10,   148,    11,    12,    69,    33,     8,    38,   145,    10,
      34,    11,    12,    73,    33,    74,   134,    84,   162,    34,
     109,     8,   170,   171,    10,     0,    11,    12,    36,    33,
       0,    37,    78,     0,    34,     0,     0,    36,     0,    38,
      37,     8,    54,     0,    10,     0,    11,    12,    38,     0,
       0,     0,    36,     0,     0,    37,     8,     9,     0,    10,
       0,    11,    12,    38,     8,    54,     0,    10,     0,    11,
      12,     0,    15,     0,     0,    16,    57,     8,     9,    13,
      10,     0,    11,    12,     0,    14,     0,    15,     8,    54,
      16,    10,     0,    11,    12,    15,    55,    25,    16,    26,
       0,    27,     0,     0,    28,     0,     0,     0,    15,     8,
      54,    16,    10,     0,    11,    12,    25,     0,    26,    63,
      27,   -44,    16,    28,   -44,     0,   -44,   -44,    29,    66,
       0,    30,   135,   136,   137,   138,   139,   140,     0,     0,
      15,     0,     0,    16,     0,     0,     0,    68,     0,     0,
      30,     0,   -44
};

static const yytype_int16 yycheck[] =
{
      14,   110,     4,    15,    16,    38,    34,    24,    15,   124,
       3,    27,     5,     3,     7,    15,    29,    10,     0,    33,
      36,    36,    36,    37,    32,     1,    33,    36,    44,    45,
      99,   100,    33,    33,    22,   150,    40,    41,    29,    15,
      16,    34,    18,    40,    37,    62,    60,     3,    24,   158,
       6,     3,     8,     9,     6,    11,     8,     9,    71,    11,
      16,    17,    38,    91,    40,    41,   175,    81,   183,    73,
      84,   104,   105,    24,    25,    47,    48,    46,    34,    30,
      31,    37,    34,   101,   102,    37,    62,    28,    35,    45,
      39,    42,    43,    45,    38,   107,    35,    73,    35,    35,
      38,    13,     3,    35,   118,     6,     3,     8,     9,     6,
      39,     8,     9,    38,   128,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     132,   107,   149,    34,    40,    40,    37,    34,    36,   153,
     154,   155,    23,     3,    45,    40,     6,    34,     8,     9,
      33,    11,    41,    33,    14,    33,    16,    15,    18,    19,
      20,    21,    35,     3,    35,    41,     6,    41,     8,     9,
     184,    11,    41,   149,    34,     3,    16,    37,     6,    33,
       8,     9,    33,    11,    33,    45,    14,    35,    16,    12,
      18,    19,    20,    21,    34,    35,     3,    37,    40,     6,
      41,     8,     9,    40,    18,    45,    34,     3,    41,    37,
       6,   107,     8,     9,    30,    11,     3,    45,   103,     6,
      16,     8,     9,    34,    11,    34,    92,    34,   128,    16,
      17,     3,   154,   154,     6,    -1,     8,     9,    34,    11,
      -1,    37,    38,    -1,    16,    -1,    -1,    34,    -1,    45,
      37,     3,     4,    -1,     6,    -1,     8,     9,    45,    -1,
      -1,    -1,    34,    -1,    -1,    37,     3,     4,    -1,     6,
      -1,     8,     9,    45,     3,     4,    -1,     6,    -1,     8,
       9,    -1,    34,    -1,    -1,    37,    38,     3,     4,    26,
       6,    -1,     8,     9,    -1,    32,    -1,    34,     3,     4,
      37,     6,    -1,     8,     9,    34,    35,     3,    37,     5,
      -1,     7,    -1,    -1,    10,    -1,    -1,    -1,    34,     3,
       4,    37,     6,    -1,     8,     9,     3,    -1,     5,    34,
       7,     3,    37,    10,     6,    -1,     8,     9,    34,    35,
      -1,    37,    93,    94,    95,    96,    97,    98,    -1,    -1,
      34,    -1,    -1,    37,    -1,    -1,    -1,    34,    -1,    -1,
      37,    -1,    34
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,    51,    52,    53,    60,    79,     3,     4,
       6,     8,     9,    26,    32,    34,    37,    54,    55,    56,
      57,    59,     0,    51,    36,     3,     5,     7,    10,    34,
      37,    61,    62,    11,    16,    17,    34,    37,    45,    56,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    77,     4,    35,    55,    38,    55,    58,
      32,    54,    36,    34,    56,    57,    35,    61,    34,    62,
      33,    22,    65,    63,    66,    68,    40,    65,    38,    65,
      76,    34,    56,    75,    34,    56,    64,    64,    15,    33,
      78,    29,    28,    24,    25,    30,    31,    42,    43,    27,
      36,    44,    45,    46,    47,    48,    35,    39,    38,    17,
      65,    57,    35,    38,    61,    13,     3,    14,    18,    19,
      20,    21,    65,    80,    81,    82,    83,    35,    39,    38,
      65,    65,    40,    68,    69,    70,    70,    70,    70,    70,
      70,    71,    71,    73,    73,    74,    75,    75,    58,    36,
      40,    33,    78,    40,    23,    34,    65,    33,    41,    80,
      33,    33,    76,    35,    35,    51,    57,    80,    65,    65,
      82,    83,    65,    78,    41,    41,    41,    33,    33,    33,
      35,    78,    12,    40,    40,    80,    65,    41,    41
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    53,    53,
      53,    53,    54,    54,    54,    55,    55,    55,    56,    56,
      56,    56,    56,    57,    57,    57,    57,    58,    58,    59,
      59,    60,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    65,    65,    66,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    71,    71,    71,    72,    72,    72,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    76,
      76,    77,    77,    78,    79,    79,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    81,    82,    82,    82,    82,
      83
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     5,     5,
       4,     4,     2,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     3,     5,     3,     1,     1,     3,     2,
       3,     4,     1,     3,     3,     1,     1,     1,     3,     1,
       2,     2,     2,     1,     3,     1,     1,     1,     1,    10,
       2,     2,     2,     3,     1,     3,     1,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     3,     3,     1,     1,     1,     3,     2,     1,
       3,     3,     2,     4,     7,     8,     6,     7,     1,     2,
       4,     4,     4,     2,     2,     2,     1,     1,     1,     2,
       7
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
#line 121 "parser.y" /* yacc.c:1646  */
    {
        program_t* tmp = NEW(program_t);
        tmp->lines = (yyvsp[0].lines_f);
        (yyval.program_f) = tmp;
    }
#line 1449 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 129 "parser.y" /* yacc.c:1646  */
    {
        lines_t* tmp = NEW(lines_t);
        tmp->line = (yyvsp[-1].line_f);
        tmp->next = (yyvsp[0].lines_f);
        (yyval.lines_f) = tmp; 
    }
#line 1460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 135 "parser.y" /* yacc.c:1646  */
    {
        lines_t* tmp = NEW(lines_t);
        tmp->line = (yyvsp[0].line_f);
        (yyval.lines_f) = tmp;
    }
#line 1470 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 143 "parser.y" /* yacc.c:1646  */
    {
        line_t* tmp = NEW(line_t);
        tmp->opt_type = L_FUN;
        tmp->opt.fun = (yyvsp[0].fun_f);
        (yyval.line_f) = tmp; 
    }
#line 1481 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 149 "parser.y" /* yacc.c:1646  */
    {
        line_t* tmp = NEW(line_t);
        tmp->opt_type = L_PROC;
        tmp->opt.proc = (yyvsp[0].proc_f);
        (yyval.line_f) = tmp; 
    }
#line 1492 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 155 "parser.y" /* yacc.c:1646  */
    {
        line_t* tmp = NEW(line_t);
        tmp->opt_type = L_FUNTYPE;
        tmp->opt.funtype = (yyvsp[0].funtype_decl_f);
        (yyval.line_f) = tmp; 
    }
#line 1503 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 164 "parser.y" /* yacc.c:1646  */
    {
        fun_t* tmp = NEW(fun_t);
        tmp->label = (yyvsp[-4].str);
        tmp->args = (yyvsp[-3].args_f);
        tmp->expr = (yyvsp[-1].expr_f);
        (yyval.fun_f) = tmp;
    
    }
#line 1516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 172 "parser.y" /* yacc.c:1646  */
    {
        fun_t* tmp = NEW(fun_t);
        tmp->label = (yyvsp[-4].str);
        tmp->args = (yyvsp[-3].args_f);
        tmp->expr = (yyvsp[-1].expr_f);
        tmp->where_exp = (yyvsp[0].where_f);
        (yyval.fun_f) = tmp;
    
    }
#line 1530 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 181 "parser.y" /* yacc.c:1646  */
    {
        fun_t* tmp = NEW(fun_t);
        tmp->label = (yyvsp[-3].str);
        tmp->expr = (yyvsp[-1].expr_f);
        (yyval.fun_f) = tmp;
    
    }
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 188 "parser.y" /* yacc.c:1646  */
    {
        fun_t* tmp = NEW(fun_t);
        tmp->label = (yyvsp[-3].str);
        tmp->expr = (yyvsp[-1].expr_f);
        tmp->where_exp = (yyvsp[0].where_f);
        (yyval.fun_f) = tmp;
    
    }
#line 1555 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 199 "parser.y" /* yacc.c:1646  */
    {
        args_t* tmp = NEW(args_t);
        tmp->arg = (yyvsp[-1].arg_f);
        tmp->next = (yyvsp[0].args_f);
        (yyval.args_f) = tmp;
    
    }
#line 1567 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 206 "parser.y" /* yacc.c:1646  */
    {
        args_t* tmp = NEW(args_t);
        tmp->arg = (yyvsp[0].arg_f);
        (yyval.args_f) = tmp;
    
    }
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 212 "parser.y" /* yacc.c:1646  */
    {
        (yyval.args_f) = NEW(arg_t);
    }
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 218 "parser.y" /* yacc.c:1646  */
    {
        arg_t* tmp = NEW(arg_t);
        tmp->tp = AR_LIST;
        tmp->opt.listval = (yyvsp[0].list_value_f);
        (yyval.arg_f) = tmp;
    
    }
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 225 "parser.y" /* yacc.c:1646  */
    {
        arg_t* tmp = NEW(arg_t);
        tmp->tp = AR_BASIC;
        tmp->opt.basicval = (yyvsp[0].basic_val_f);
        (yyval.arg_f) = tmp; 
    }
#line 1609 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 231 "parser.y" /* yacc.c:1646  */
    {
        arg_t* tmp = NEW(arg_t);
        tmp->tp = AR_ARG;
        tmp->opt.argval = (yyvsp[-1].arg_f);
        (yyval.arg_f) = tmp; 
    }
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 240 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BINT;
        tmp->val.intval = (yyvsp[0].intval);
        (yyval.basic_val_f) = tmp;
    }
#line 1631 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 246 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BFLOAT;
        tmp->val.floatval = (yyvsp[0].floatval);
        (yyval.basic_val_f) = tmp;
    }
#line 1642 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 252 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BBOOL;
        tmp->val.boolval = (yyvsp[0].boolval);
        (yyval.basic_val_f) = tmp; 
    }
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 258 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BLABEL;
        tmp->val.label = (yyvsp[0].str);
        (yyval.basic_val_f) = tmp; 
    }
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 264 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BUNIT;
        (yyval.basic_val_f) = tmp; 
    }
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 272 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_BASIC;
        tmp->opt.basic_val = (yyvsp[-2].basic_val_f);
        tmp->next = (yyvsp[0].list_value_f);
        (yyval.list_value_f) = tmp;
    }
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 279 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_LIST;
        tmp->opt.list_args_val = (yyvsp[-3].list_args_f);
        tmp->next = (yyvsp[0].list_value_f);
        (yyval.list_value_f) = tmp;
    
    }
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 287 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_WLD;
        tmp->next = (yyvsp[0].list_value_f);
        (yyval.list_value_f) = tmp;
    
    }
#line 1711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 294 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_BLT;
        tmp->opt.built_list_val = (yyvsp[0].built_list_val_f);
        (yyval.list_value_f) = tmp;
    
    }
#line 1723 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 304 "parser.y" /* yacc.c:1646  */
    {
            list_args_t* tmp = NEW(list_args_t);
            tmp->arg = (yyvsp[0].arg_f);
            (yyval.list_args_f) = tmp;
         }
#line 1733 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 309 "parser.y" /* yacc.c:1646  */
    {
            list_args_t* tmp = NEW(list_args_t);
            tmp->arg = (yyvsp[-2].arg_f);
            tmp->next = (yyvsp[0].list_args_f);
            (yyval.list_args_f) = tmp;
         }
#line 1744 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 318 "parser.y" /* yacc.c:1646  */
    {
        (yyval.built_list_val_f) = NEW(built_list_val_t);
    }
#line 1752 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 321 "parser.y" /* yacc.c:1646  */
    {
        built_list_val_t* tmp = NEW(built_list_val_t);
        tmp->vals = (yyvsp[-1].list_args_f);
        (yyval.built_list_val_f) = tmp;
    }
#line 1762 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 329 "parser.y" /* yacc.c:1646  */
    {
        funtype_decl_t* tmp = NEW(funtype_decl_t);
        tmp->label = (yyvsp[-3].str);
        tmp->type = (yyvsp[-1].funtype_f);
        (yyval.funtype_decl_f) = tmp;

    }
#line 1774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 339 "parser.y" /* yacc.c:1646  */
    {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_BASIC;
        tmp->tp.btype = (yyvsp[0].basic_type_f);
        (yyval.funtype_f) = tmp;
    }
#line 1785 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 345 "parser.y" /* yacc.c:1646  */
    {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_FUNC;
        tmp->tp.ftype = (yyvsp[-1].funtype_f);
        (yyval.funtype_f) = tmp;
    }
#line 1796 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 351 "parser.y" /* yacc.c:1646  */
    {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_BASIC;
        tmp->tp.btype = (yyvsp[-2].basic_type_f);
        tmp->next = (yyvsp[0].funtype_f);
        (yyval.funtype_f) = tmp;
    }
#line 1808 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 361 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_INTEGER;
        (yyval.basic_type_f) = tmp;
    }
#line 1818 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 366 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_FLOAT;
        (yyval.basic_type_f) = tmp;
    }
#line 1828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 371 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_BOOL;
        (yyval.basic_type_f) = tmp;
    }
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 376 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_LIST;
        tmp->internal_list_type = (yyvsp[-1].basic_type_f);
        (yyval.basic_type_f) = tmp;
    }
#line 1849 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 382 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_VAR;
        (yyval.basic_type_f) = tmp;
    }
#line 1859 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 387 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_UNIT;
        (yyval.basic_type_f) = tmp;
    }
#line 1869 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 395 "parser.y" /* yacc.c:1646  */
    {
            appexpr_t* tmp = NEW(appexpr_t);
            tmp->tp = A_APP;
            tmp->app_tp.app = (yyvsp[-1].appexpr_f);
            tmp->napp2 = (yyvsp[0].nonapp_f);
            (yyval.appexpr_f) = tmp;
       
       }
#line 1882 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 403 "parser.y" /* yacc.c:1646  */
    {
            appexpr_t* tmp = NEW(appexpr_t);
            tmp->tp = A_NAPP;
            tmp->app_tp.napp1 = (yyvsp[-1].nonapp_f);
            tmp->napp2 = (yyvsp[0].nonapp_f);
            (yyval.appexpr_f) = tmp;
       }
#line 1894 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 413 "parser.y" /* yacc.c:1646  */
    {
            nonapp_t* tmp = NEW(nonapp_t);
            tmp->tp = NA_BASIC;
            tmp->n_tp.bvalue = (yyvsp[0].basic_val_f);
            (yyval.nonapp_f) = tmp;
      }
#line 1905 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 419 "parser.y" /* yacc.c:1646  */
    {
            nonapp_t* tmp = NEW(nonapp_t);
            tmp->tp = NA_EXPR;
            tmp->n_tp.expr = (yyvsp[-1].expr_f);
            (yyval.nonapp_f) = tmp;
      }
#line 1916 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 428 "parser.y" /* yacc.c:1646  */
    {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = OP_EXPR;
        tmp->tp.op_expr = (yyvsp[0].op_f);
        (yyval.expr_f) = tmp;
    
    }
#line 1928 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 435 "parser.y" /* yacc.c:1646  */
    {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = APP_EXPR;
        tmp->tp.appexpr = (yyvsp[0].appexpr_f);
        (yyval.expr_f) = tmp;
    }
#line 1939 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 441 "parser.y" /* yacc.c:1646  */
    {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = IF_EXPR;
        tmp->tp.ifexpr = (yyvsp[0].ifexpr_f);
        (yyval.expr_f) = tmp;
    }
#line 1950 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 447 "parser.y" /* yacc.c:1646  */
    {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = YIELD_EXPR;
        tmp->tp.yieldexpr = (yyvsp[0].yieldexpr_f);
        (yyval.expr_f) = tmp;
    }
#line 1961 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 456 "parser.y" /* yacc.c:1646  */
    {
        ifexpr_t* tmp = NEW(ifexpr_t);
        tmp->expr1 = (yyvsp[-8].expr_f);
        tmp->expr2 = (yyvsp[-5].expr_f);
        tmp->expr3 = (yyvsp[-1].expr_f);
        (yyval.ifexpr_f) = tmp;
    }
#line 1973 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 466 "parser.y" /* yacc.c:1646  */
    {
        yieldexpr_t* tmp = NEW(yieldexpr_t);
        tmp->yield_tp = Y_IF;
        tmp->tp.ifexpr = (yyvsp[0].ifexpr_f);
        (yyval.yieldexpr_f) = tmp;
    }
#line 1984 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 472 "parser.y" /* yacc.c:1646  */
    {
        yieldexpr_t* tmp = NEW(yieldexpr_t);
        tmp->yield_tp = Y_APP;
        tmp->tp.appexpr = (yyvsp[0].appexpr_f);
        (yyval.yieldexpr_f) = tmp;
    }
#line 1995 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 478 "parser.y" /* yacc.c:1646  */
    {
        yieldexpr_t* tmp = NEW(yieldexpr_t);
        tmp->yield_tp = Y_OP;
        tmp->tp.op_expr = (yyvsp[0].op_f);
        (yyval.yieldexpr_f) = tmp;
    }
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 487 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_OR;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2019 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 495 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2030 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 504 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_AND;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2043 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 512 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2054 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 521 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_EQ;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2067 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 529 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_DIFF;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2080 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 537 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_LESS;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2093 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 545 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_LEQ;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2106 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 553 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_GREATER;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2119 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 561 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_GEQ;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2132 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 569 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2143 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 578 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_CONS;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2156 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 586 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_APPEND;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2169 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 594 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2180 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 603 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_PLUS;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2193 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 611 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_MINUS;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2206 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 619 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2217 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 629 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
     }
#line 2228 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 640 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2239 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 649 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_BVALUE;
        tmp->opt.bval = (yyvsp[0].basic_val_f);
        (yyval.op_f) = tmp;
    }
#line 2250 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 655 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_LIST;
        tmp->opt.lexpr = (yyvsp[0].exprs_f);
        (yyval.op_f) = tmp;
    }
#line 2261 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 661 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_EXPR;
        tmp->opt.expr = (yyvsp[-1].expr_f);
        (yyval.op_f) = tmp;
    }
#line 2272 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 667 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEG;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2283 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 676 "parser.y" /* yacc.c:1646  */
    {
        exprs_t* tmp = NEW(exprs_t);
        tmp->expr = (yyvsp[0].expr_f);
        (yyval.exprs_f) = tmp;
    }
#line 2293 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 681 "parser.y" /* yacc.c:1646  */
    {
        exprs_t* tmp = NEW(exprs_t);
        tmp->expr = (yyvsp[-2].expr_f);
        tmp->next = (yyvsp[0].exprs_f);
        (yyval.exprs_f) = tmp;
    
    }
#line 2305 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 691 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exprs_f) = (yyvsp[-1].exprs_f);
     }
#line 2313 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 694 "parser.y" /* yacc.c:1646  */
    {
        (yyval.exprs_f) = NEW(exprs_t);
    }
#line 2321 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 701 "parser.y" /* yacc.c:1646  */
    {
        where_t* tmp = NEW(where_t);
        tmp->lines = (yyvsp[-1].lines_f);
        (yyval.where_f) = tmp;
    }
#line 2331 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 709 "parser.y" /* yacc.c:1646  */
    { 
        proc_t* tmp = NEW(proc_t);
        tmp->label = (yyvsp[-6].str);
        tmp->args = (yyvsp[-5].args_f);
        tmp->stmts = (yyvsp[-1].stmts_f);
        (yyval.proc_f) = tmp;
    }
#line 2343 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 716 "parser.y" /* yacc.c:1646  */
    { 
        proc_t* tmp = NEW(proc_t);
        tmp->label = (yyvsp[-7].str);
        tmp->args = (yyvsp[-6].args_f);
        tmp->stmts = (yyvsp[-2].stmts_f);
        tmp->where_exp = (yyvsp[0].where_f);
        (yyval.proc_f) = tmp;
    }
#line 2356 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 724 "parser.y" /* yacc.c:1646  */
    { 
        proc_t* tmp = NEW(proc_t);
        tmp->label = (yyvsp[-5].str);
        tmp->stmts = (yyvsp[-1].stmts_f);
        (yyval.proc_f) = tmp;
    }
#line 2367 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 730 "parser.y" /* yacc.c:1646  */
    { 
        proc_t* tmp = NEW(proc_t);
        tmp->label = (yyvsp[-6].str);
        tmp->stmts = (yyvsp[-2].stmts_f);
        tmp->where_exp = (yyvsp[0].where_f);
        (yyval.proc_f) = tmp;
    }
#line 2379 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 740 "parser.y" /* yacc.c:1646  */
    {
        stmts_t* tmp = NEW(stmts_t);
        tmp->stmt = (yyvsp[0].stmt_f);
        (yyval.stmts_f) = tmp;
    }
#line 2389 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 745 "parser.y" /* yacc.c:1646  */
    {
        stmts_t* tmp = NEW(stmts_t);
        tmp->stmt = (yyvsp[-1].stmt_f);
        tmp->next = (yyvsp[0].stmts_f);
        (yyval.stmts_f) = tmp;
    }
#line 2400 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 754 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_EXPR;
       tmp->lhs = (yyvsp[-3].str);
       tmp->body.expr = (yyvsp[-1].expr_f);
       (yyval.stmt_f) = tmp;
    }
#line 2412 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 761 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_WH;
       tmp->lhs = (yyvsp[-3].str);
       tmp->body.while_expr = (yyvsp[-1].while_f);
       (yyval.stmt_f) = tmp;
    }
#line 2424 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 768 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_IO;
       tmp->lhs = (yyvsp[-3].str);
       tmp->body.io_expr = (yyvsp[-1].io_f);
       (yyval.stmt_f) = tmp;
    }
#line 2436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 775 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_EXPR;
       tmp->body.expr = (yyvsp[-1].expr_f);
       (yyval.stmt_f) = tmp;
    }
#line 2447 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 781 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_WH;
       tmp->body.while_expr = (yyvsp[-1].while_f);
       (yyval.stmt_f) = tmp;
    }
#line 2458 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 787 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_IO;
       tmp->body.io_expr = (yyvsp[-1].io_f);
       (yyval.stmt_f) = tmp;
    }
#line 2469 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 796 "parser.y" /* yacc.c:1646  */
    {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_READINT;
        (yyval.io_f) = tmp;
    }
#line 2479 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 801 "parser.y" /* yacc.c:1646  */
    {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_READFLOAT;
        (yyval.io_f) = tmp;
    }
#line 2489 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 806 "parser.y" /* yacc.c:1646  */
    {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_READBOOL;
        (yyval.io_f) = tmp;
    }
#line 2499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 811 "parser.y" /* yacc.c:1646  */
    {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_PRINT;
        tmp->expr = (yyvsp[0].expr_f);
        (yyval.io_f) = tmp;
    }
#line 2510 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 820 "parser.y" /* yacc.c:1646  */
    { 
                while_t* tmp = NEW(while_t);
                tmp->expr = (yyvsp[-4].expr_f);
                tmp->stmts = (yyvsp[-1].stmts_f);
                (yyval.while_f) = tmp;
    }
#line 2521 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2525 "parser.tab.c" /* yacc.c:1646  */
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
#line 827 "parser.y" /* yacc.c:1906  */


void print_errors() {
    list_error_t* cur = NULL;
    cur = error_list_root;
    // Printando erros
    while(cur != NULL) {
        printf("%s", cur->erro->msg); 
        cur = cur->next;
    }
    del_list(&error_list_root);
    printf("\n");

}

int main(int argc, char** argv) {

    if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }

    yyparse();

    print_errors();


    return 0;
}
