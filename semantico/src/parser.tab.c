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
#include "ast.h"
#include "list_error.h"
#include "sym_table.h"
#include "lex.yy.c"

/*Macro para alocar e inicializar a struct toda com 0*/
#define NEW(TYPE) memset(malloc(sizeof(TYPE)), 0, sizeof(TYPE))

void yyerror(const char *str) {    
    size_t sz = strlen(str) + 256;
    char* msg = malloc(sz);

    has_errors = 1;

    sprintf(msg, "%d:%d: %s\n", line, col, str);
    
    comp_error_t* err = make_error(0, msg, line, col);
    add_error(&error_list_root, err);
}

enum {
         WHILE_T, IO_T, STMT_T, STMTS_T, ID_LIST_T, PROC_T, APPEXPR_T, NONAPP_T, WHERE_T, EXPRS_T, OP_T,
         YIELDEXPR_T, IFEXPR_T, EXPR_T, BASIC_TYPE_T, FUNTYPE_T, FUNTYPE_DECL_T, BASIC_VAL_T, ARG_T, 
         FUN_T, LINES_T, LINE_T, ARGS_T, PROGRAM_T, LIST_EXPR_T, LIST_ARGS_T, BUILT_LIST_VAL_T, LIST_VALUE_T }
 union_type;

void print_tree(YYSTYPE node, char node_type, int lvl);


#line 99 "parser.tab.c" /* yacc.c:339  */

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
    UNDERSCORE = 259,
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
#line 66 "parser.y" /* yacc.c:355  */

    while_t* while_f;          
    io_t* io_f;             
    stmt_t* stmt_f;           
    stmts_t* stmts_f;          
    id_list_t* id_list_f;
    proc_t* proc_f;           
    appexpr_t* appexpr_f;        
    nonapp_t* nonapp_f;        
    where_t* where_f;          
    op_t* op_f;             
    yieldexpr_t* yieldexpr_f;      
    ifexpr_t* ifexpr_f;         
    expr_t* expr_f;           
    exprs_t* exprs_f;           
    list_expr_t* list_expr_f;
    basic_type_t* basic_type_f;     
    funtype_t* funtype_f;        
    funtype_decl_t* funtype_decl_f;   
    basic_val_t* basic_val_f;      
    arg_t* arg_f;            
    decl_t* decl_f;
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

#line 207 "parser.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 222 "parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   388

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  209

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
       2,     2,     2,     2,     2,     2,     2,    44,     2,     2,
      34,    35,    45,    42,    39,    43,     2,    46,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    33,
      40,    32,    41,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    47,     2,    48,     2,     2,     2,     2,
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
       0,   146,   146,   160,   166,   174,   180,   186,   195,   213,
     230,   242,   255,   267,   280,   281,   285,   292,   298,   304,
     310,   317,   323,   332,   339,   344,   350,   357,   363,   369,
     375,   382,   390,   397,   405,   411,   418,   425,   433,   440,
     445,   454,   457,   465,   476,   482,   488,   495,   505,   510,
     515,   520,   526,   533,   541,   549,   559,   565,   574,   581,
     587,   596,   606,   612,   618,   627,   635,   644,   652,   661,
     669,   677,   685,   693,   701,   709,   718,   726,   734,   743,
     751,   759,   768,   769,   778,   779,   780,   789,   795,   801,
     807,   816,   821,   831,   836,   843,   852,   863,   876,   886,
     897,   901,   906,   915,   922,   929,   936,   942,   948,   954,
     958,   963,   968,   973,   982
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "UNDERSCORE", "FLOAT", "BOOLVAL",
  "BOOL", "NUMBER", "FLOATNUM", "INTEGER", "IF", "ELSE", "THEN", "WHILE",
  "WHERE", "YIELD", "DO", "PRINT", "READBOOL", "READFLOAT", "READINT",
  "RARROW", "LARROW", "DIFF", "EQUALS", "DOUBLECOLON", "APPEND", "AND",
  "OR", "LEQ", "GEQ", "'='", "';'", "'('", "')'", "':'", "'['", "']'",
  "','", "'<'", "'>'", "'+'", "'-'", "'%'", "'*'", "'/'", "'{'", "'}'",
  "$accept", "program", "line_elems", "line_elem", "decl_w_args",
  "decl_no_args", "fundecl", "args", "arg_value", "id_list", "basic_value",
  "list_value", "list_args", "built_list_value", "funtype_decl", "funtype",
  "basic_type", "appexpr", "nonapp", "expr", "ifexpr", "yieldexpr",
  "op_prec1", "op_prec2", "op_prec3", "op_prec4", "op_prec5", "op_prec6",
  "op_prec7", "op_prec8", "exprs", "list_expr", "where_exp", "procdecl",
  "stmts", "stmt", "io_stmt", "while_expr", YY_NULLPTR
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
      60,    62,    43,    45,    37,    42,    47,   123,   125
};
# endif

#define YYPACT_NINF -91

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-91)))

#define YYTABLE_NINF -102

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      29,   321,    38,   -91,    29,    98,   203,   -91,   -91,   -91,
       2,   -91,   160,   -91,   -91,   -91,    17,   -91,   263,    13,
     160,   -91,   -91,   -91,   239,     3,   220,   227,    33,   207,
     325,   325,    -5,   -91,   -91,    31,    30,   341,    95,    18,
      37,   -91,   -91,    21,    22,    86,   -91,   -91,   -91,   -91,
     -91,   246,   289,    42,    49,    52,   -91,    78,    50,    60,
      63,   -91,   148,   -91,    87,   359,    73,   -91,    72,    76,
     220,   -91,   -91,   220,   -91,   -91,   -91,    70,   -91,   -91,
      33,    33,    33,    33,    33,    33,    33,    33,    33,    33,
      33,    33,    33,    33,    33,   359,   -91,   -91,   359,   101,
     -91,    93,   107,   108,   -91,    17,   281,   -91,   106,   109,
     -91,   298,   -91,   117,   239,   119,   122,   125,   121,   239,
     239,   -91,   -91,   -91,   130,   129,   124,    45,   134,   -91,
     335,   239,   -91,   138,   139,    29,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   -91,   -91,   -91,    18,    18,    37,   -91,
     -91,   128,   131,   -91,   155,   -91,   -91,    52,   145,    60,
     -91,   342,   150,   146,    52,   -91,   -91,   172,   -91,    75,
      75,   239,   325,   -91,   -91,   -91,   184,   -91,   181,   -91,
     -91,   -91,   -91,   -91,   151,   181,   -91,    17,   -91,   305,
     239,   -91,   -91,   165,   168,   174,   -91,   -91,   -91,   -91,
     -91,   -91,   -91,   161,   -91,   -91,   359,   169,   -91
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     4,     0,     0,     5,     7,     6,
       0,    30,    19,    29,    27,    28,     0,     9,     0,     0,
      18,    21,     1,     3,     0,     0,     0,     0,     0,    87,
      59,     0,     0,    60,    58,    66,    68,    75,    78,    81,
      83,    86,    88,     0,     0,     0,    17,    52,    49,    50,
      48,     0,     0,     0,    44,     0,    31,     0,     0,    21,
       0,    36,     0,    16,     0,     0,     0,    94,    91,     0,
       0,    87,    90,     0,    56,    54,    55,     0,    10,    11,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    12,    13,     0,     0,
      53,     0,     0,     0,    43,     0,     0,    41,    39,     0,
      22,     0,    20,     0,     0,     0,    25,    26,     0,     0,
       0,   112,   111,   110,     0,     0,     0,     0,     0,   107,
      89,     0,    93,     0,     0,     0,    65,    67,    70,    69,
      72,    74,    71,    73,    77,    76,    79,    80,    82,    84,
      85,     0,     0,    15,    45,    51,    46,    34,     0,     0,
      35,     0,    42,    30,    38,    32,    14,     0,   109,     0,
       0,     0,    63,    62,    64,   113,     0,   106,    96,   102,
     108,    92,    89,    57,     0,    98,   100,     0,    40,     0,
       0,    23,    24,     0,     0,     0,   104,    97,    95,    99,
      47,    33,    61,     0,   103,   105,     0,     0,   114
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -91,   -91,     5,   -91,   -91,   -91,   -91,    23,   -17,   -79,
      -1,   -90,    58,   -91,   -91,   -48,   170,   105,   -24,     7,
     113,   -91,   -66,   144,   301,    14,   -91,    34,   142,   -20,
     112,   -91,   -42,   -91,   -80,   -91,    68,    82
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,     5,     6,     7,    19,    20,   124,
      71,    60,   109,    61,     8,    53,    54,    30,    31,    68,
      33,   125,    34,    35,    36,    37,    38,    39,    40,    41,
      69,    42,    79,     9,   126,   127,   128,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,    58,    97,   101,    29,    29,    75,    76,    72,    23,
      77,    21,    32,    44,   136,   151,   160,    59,   152,    21,
      47,   165,    48,    29,    49,    29,    29,    50,    78,    74,
      74,    64,     1,    66,    45,    46,    11,    77,    22,    13,
     108,    14,    15,    63,    29,    62,   115,   179,   116,   117,
      65,    51,    99,   174,    52,    96,    21,   156,    81,   118,
      80,   119,    92,   120,   121,   122,   123,    70,    95,    29,
      27,   105,    29,   149,   150,   104,    28,   133,   116,   117,
     134,    11,    93,    94,    13,   110,    14,    15,   106,    11,
     191,   192,    13,  -101,    14,    15,   111,    24,   112,   201,
     114,    11,   144,   145,    13,   159,    14,    15,   130,    24,
     159,   131,    18,    29,   132,    25,   107,   135,    29,    29,
      26,   167,    88,    27,   146,   147,   207,   175,   154,    28,
      29,    89,    26,    98,   153,    27,   197,    90,    91,   200,
     184,    28,   100,   199,   108,   161,   155,   162,    75,   113,
     166,    -8,   168,   176,    -8,   171,    -8,    -8,   169,    -8,
      21,   170,   177,    11,    12,    -8,    13,   180,    14,    15,
      29,    74,   178,   182,   183,    29,   185,   187,   193,   186,
      56,   -37,    -8,   194,   190,    -8,   189,    11,   159,    29,
      13,    -8,    14,    15,    18,    24,    77,   202,   118,   198,
     203,   204,   120,   121,   122,   123,    11,   205,   206,    13,
     -56,    14,    15,   -56,    24,   -56,   -56,   208,    26,   188,
      43,    27,   103,    11,   172,   137,    13,    28,    14,    15,
      11,    24,   173,    13,   148,    14,    15,    26,    24,     0,
      27,   -56,    11,   181,   195,    13,    28,    14,    15,    47,
      24,    48,     0,    49,    26,    56,    50,    27,   196,     0,
       0,    26,     0,    28,    27,    67,    11,    55,     0,    13,
      28,    14,    15,    26,     0,     0,    27,     0,     0,     0,
      51,   100,    28,    52,    11,   157,     0,    13,     0,    14,
      15,     0,    47,     0,    48,     0,    49,    18,    56,    50,
      57,   163,   164,     0,    13,     0,    14,    15,    11,    55,
       0,    13,     0,    14,    15,   158,     0,     0,    57,     0,
       0,     0,    10,   102,    11,    12,    52,    13,    11,    14,
      15,    13,   158,    14,    15,    57,     0,     0,   -57,   158,
       0,   -57,    57,   -57,   -57,    11,     0,    16,    13,     0,
      14,    15,     0,    17,     0,    18,     0,     0,     0,    73,
     115,     0,   116,   117,     0,    82,    83,     0,     0,   -57,
       0,    84,    85,   118,     0,   119,    18,   120,   121,   122,
     123,    86,    87,   138,   139,   140,   141,   142,   143
};

static const yytype_int16 yycheck[] =
{
       1,    18,    44,    51,     5,     6,    30,    31,    28,     4,
      15,    12,     5,     6,    80,    95,   106,    18,    98,    20,
       3,   111,     5,    24,     7,    26,    27,    10,    33,    30,
      31,    24,     3,    26,    32,    12,     3,    15,     0,     6,
      57,     8,     9,    20,    45,    32,     1,   127,     3,     4,
      47,    34,    45,   119,    37,    33,    57,   105,    28,    14,
      29,    16,    44,    18,    19,    20,    21,    34,    47,    70,
      37,    22,    73,    93,    94,    33,    43,    70,     3,     4,
      73,     3,    45,    46,     6,    35,     8,     9,    36,     3,
     169,   170,     6,    48,     8,     9,    36,    11,    35,   189,
      13,     3,    88,    89,     6,   106,     8,     9,    35,    11,
     111,    39,    34,   114,    38,    17,    38,    47,   119,   120,
      34,   114,    27,    37,    90,    91,   206,   120,    35,    43,
     131,    36,    34,    47,    33,    37,   178,    42,    43,   187,
     135,    43,    35,   185,   161,    39,    38,    38,   172,     1,
      33,     3,    33,    23,     6,    34,     8,     9,    36,    11,
     161,    36,    33,     3,     4,    17,     6,    33,     8,     9,
     171,   172,    48,    35,    35,   176,    48,    22,   171,    48,
      35,    35,    34,   176,    12,    37,    36,     3,   189,   190,
       6,    43,     8,     9,    34,    11,    15,   190,    14,    48,
      35,    33,    18,    19,    20,    21,     3,    33,    47,     6,
       3,     8,     9,     6,    11,     8,     9,    48,    34,   161,
      17,    37,    52,     3,   119,    81,     6,    43,     8,     9,
       3,    11,   119,     6,    92,     8,     9,    34,    11,    -1,
      37,    34,     3,   131,   176,     6,    43,     8,     9,     3,
      11,     5,    -1,     7,    34,    35,    10,    37,   176,    -1,
      -1,    34,    -1,    43,    37,    38,     3,     4,    -1,     6,
      43,     8,     9,    34,    -1,    -1,    37,    -1,    -1,    -1,
      34,    35,    43,    37,     3,     4,    -1,     6,    -1,     8,
       9,    -1,     3,    -1,     5,    -1,     7,    34,    35,    10,
      37,     3,     4,    -1,     6,    -1,     8,     9,     3,     4,
      -1,     6,    -1,     8,     9,    34,    -1,    -1,    37,    -1,
      -1,    -1,     1,    34,     3,     4,    37,     6,     3,     8,
       9,     6,    34,     8,     9,    37,    -1,    -1,     3,    34,
      -1,     6,    37,     8,     9,     3,    -1,    26,     6,    -1,
       8,     9,    -1,    32,    -1,    34,    -1,    -1,    -1,    34,
       1,    -1,     3,     4,    -1,    24,    25,    -1,    -1,    34,
      -1,    30,    31,    14,    -1,    16,    34,    18,    19,    20,
      21,    40,    41,    82,    83,    84,    85,    86,    87
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    50,    51,    52,    53,    54,    55,    63,    82,
       1,     3,     4,     6,     8,     9,    26,    32,    34,    56,
      57,    59,     0,    51,    11,    17,    34,    37,    43,    59,
      66,    67,    68,    69,    71,    72,    73,    74,    75,    76,
      77,    78,    80,    17,    68,    32,    56,     3,     5,     7,
      10,    34,    37,    64,    65,     4,    35,    37,    57,    59,
      60,    62,    32,    56,    68,    47,    68,    38,    68,    79,
      34,    59,    78,    34,    59,    67,    67,    15,    33,    81,
      29,    28,    24,    25,    30,    31,    40,    41,    27,    36,
      42,    43,    44,    45,    46,    47,    33,    81,    47,    68,
      35,    64,    34,    65,    33,    22,    36,    38,    57,    61,
      35,    36,    35,     1,    13,     1,     3,     4,    14,    16,
      18,    19,    20,    21,    58,    70,    83,    84,    85,    86,
      35,    39,    38,    68,    68,    47,    71,    72,    73,    73,
      73,    73,    73,    73,    74,    74,    76,    76,    77,    78,
      78,    83,    83,    33,    35,    38,    64,     4,    34,    59,
      60,    39,    38,     3,     4,    60,    33,    68,    33,    36,
      36,    34,    66,    69,    71,    68,    23,    33,    48,    83,
      33,    79,    35,    35,    51,    48,    48,    22,    61,    36,
      12,    58,    58,    68,    68,    85,    86,    81,    48,    81,
      64,    60,    68,    35,    33,    33,    47,    83,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    51,    51,    52,    52,    52,    53,    54,
      55,    55,    55,    55,    55,    55,    56,    56,    56,    56,
      57,    57,    57,    58,    58,    58,    58,    59,    59,    59,
      59,    59,    60,    60,    60,    60,    60,    60,    60,    61,
      61,    62,    62,    63,    64,    64,    64,    64,    65,    65,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    69,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    73,    73,    73,    73,    73,    74,    74,    74,    75,
      75,    75,    76,    76,    77,    77,    77,    78,    78,    78,
      78,    79,    79,    80,    80,    81,    82,    82,    82,    82,
      82,    83,    83,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    85,    85,    86
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     2,
       3,     3,     3,     3,     5,     5,     2,     2,     1,     1,
       3,     1,     3,     3,     3,     1,     1,     1,     1,     1,
       1,     2,     3,     5,     3,     3,     1,     3,     3,     1,
       3,     2,     3,     4,     1,     3,     3,     5,     1,     1,
       1,     3,     1,     2,     2,     2,     1,     3,     1,     1,
       1,     6,     2,     2,     2,     3,     1,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     3,     3,     1,     1,     1,     3,
       2,     1,     3,     3,     2,     4,     5,     6,     5,     6,
       6,     1,     2,     4,     3,     4,     2,     1,     2,     2,
       1,     1,     1,     2,     7
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
#line 146 "parser.y" /* yacc.c:1646  */
    {
        program_t* tmp = NEW(program_t);
        tmp->lines = (yyvsp[0].lines_f);
        YYSTYPE node;
        node.program_f = tmp;
        if(!has_errors) {
            printf("================== Syntax tree  ==================\n");
            print_tree(node, PROGRAM_T, 0);
        }
        (yyval.program_f) = tmp;
    }
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 160 "parser.y" /* yacc.c:1646  */
    {
        lines_t* tmp = NEW(lines_t);
        tmp->line = (yyvsp[-1].line_f);
        tmp->next = (yyvsp[0].lines_f);
        (yyval.lines_f) = tmp; 
    }
#line 1501 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 166 "parser.y" /* yacc.c:1646  */
    {
        lines_t* tmp = NEW(lines_t);
        tmp->line = (yyvsp[0].line_f);
        (yyval.lines_f) = tmp;
    }
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 174 "parser.y" /* yacc.c:1646  */
    {
        line_t* tmp = NEW(line_t);
        tmp->opt_type = L_FUN;
        tmp->opt.fun = (yyvsp[0].fun_f);
        (yyval.line_f) = tmp; 
    }
#line 1522 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 180 "parser.y" /* yacc.c:1646  */
    {
        line_t* tmp = NEW(line_t);
        tmp->opt_type = L_PROC;
        tmp->opt.proc = (yyvsp[0].proc_f);
        (yyval.line_f) = tmp; 
    }
#line 1533 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 186 "parser.y" /* yacc.c:1646  */
    {
        line_t* tmp = NEW(line_t);
        tmp->opt_type = L_FUNTYPE;
        tmp->opt.funtype = (yyvsp[0].funtype_decl_f);
        (yyval.line_f) = tmp; 
    }
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 195 "parser.y" /* yacc.c:1646  */
    {
        decl_t* tmp = NEW(decl_t);
        tmp->label = (yyvsp[-2].str);
        tmp->args = (yyvsp[-1].args_f);
        (yyval.decl_f) = tmp;

        sym_node_t* sym = get_symbol(tmp->label);
        if(sym == NULL) {
            // ERRO
        } else {
        
        }

        enter_ctxt();
    }
#line 1564 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 213 "parser.y" /* yacc.c:1646  */
    {
        decl_t* tmp = NEW(decl_t);
        tmp->label = (yyvsp[-1].str);
        (yyval.decl_f) = tmp;

        sym_node_t* sym = get_symbol(tmp->label);
        if(sym == NULL) {
            // ERRO
        } else {
        
        }

        enter_ctxt();
    }
#line 1583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 230 "parser.y" /* yacc.c:1646  */
    {
        fun_t* tmp = NEW(fun_t);
        decl_t* d = (yyvsp[-2].decl_f);
        tmp->label = d->label;
        tmp->args = d->args;
        tmp->expr = (yyvsp[-1].expr_f);
        (yyval.fun_f) = tmp;
        free(d);

        leave_ctxt();
    
    }
#line 1600 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 242 "parser.y" /* yacc.c:1646  */
    {
        fun_t* tmp = NEW(fun_t);
        decl_t* d = (yyvsp[-2].decl_f);
        tmp->label = d->label;
        tmp->args = d->args;
        tmp->expr = (yyvsp[-1].expr_f);
        tmp->where_exp = (yyvsp[0].where_f);
        (yyval.fun_f) = tmp;
        free(d);

        leave_ctxt();
    
    }
#line 1618 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 255 "parser.y" /* yacc.c:1646  */
    {
        fun_t* tmp = NEW(fun_t);
        decl_t* d = (yyvsp[-2].decl_f);
        tmp->label = d->label;
        tmp->expr = (yyvsp[-1].expr_f);
        (yyval.fun_f) = tmp;
        sym_node_t* sym = get_symbol(tmp->label);
        free(d);
    
        leave_ctxt();

    }
#line 1635 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 267 "parser.y" /* yacc.c:1646  */
    {
        fun_t* tmp = NEW(fun_t);
        decl_t* d = (yyvsp[-2].decl_f);
        tmp->label = d->label;
        tmp->expr = (yyvsp[-1].expr_f);
        tmp->where_exp = (yyvsp[0].where_f);
        (yyval.fun_f) = tmp;
        sym_node_t* sym = get_symbol(tmp->label);
        free(d);

        leave_ctxt();
    
    }
#line 1653 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 280 "parser.y" /* yacc.c:1646  */
    {yyerrok;}
#line 1659 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 281 "parser.y" /* yacc.c:1646  */
    { yyerrok; }
#line 1665 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 285 "parser.y" /* yacc.c:1646  */
    {
        args_t* tmp = NEW(args_t);
        tmp->arg = (yyvsp[-1].arg_f);
        tmp->next = (yyvsp[0].args_f);
        (yyval.args_f) = tmp;
    
    }
#line 1677 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 292 "parser.y" /* yacc.c:1646  */
    {
        args_t* tmp = NEW(args_t);
        tmp->next = (yyvsp[0].args_f);
        (yyval.args_f) = tmp;
    
    }
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 298 "parser.y" /* yacc.c:1646  */
    {
        args_t* tmp = NEW(args_t);
        tmp->arg = (yyvsp[0].arg_f);
        (yyval.args_f) = tmp;
    
    }
#line 1699 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 304 "parser.y" /* yacc.c:1646  */
    {
        (yyval.args_f) = NEW(arg_t);
    }
#line 1707 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 310 "parser.y" /* yacc.c:1646  */
    {
        arg_t* tmp = NEW(arg_t);
        tmp->tp = AR_LIST;
        tmp->opt.listval = (yyvsp[-1].list_value_f);
        (yyval.arg_f) = tmp;
    
    }
#line 1719 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 317 "parser.y" /* yacc.c:1646  */
    {
        arg_t* tmp = NEW(arg_t);
        tmp->tp = AR_BASIC;
        tmp->opt.basicval = (yyvsp[0].basic_val_f);
        (yyval.arg_f) = tmp; 
    }
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 323 "parser.y" /* yacc.c:1646  */
    {
        arg_t* tmp = NEW(arg_t);
        tmp->tp = AR_ARG;
        tmp->opt.argval = (yyvsp[-1].arg_f);
        (yyval.arg_f) = tmp; 
    }
#line 1741 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 332 "parser.y" /* yacc.c:1646  */
    {
            id_list_t* tmp = NEW(id_list_t);
            tmp->label = (yyvsp[-2].str);
            tmp->next = (yyvsp[0].id_list_f);
            (yyval.id_list_f) = tmp;
            add_symbol((yyvsp[-2].str), NULL);
      }
#line 1753 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 339 "parser.y" /* yacc.c:1646  */
    {
            id_list_t* tmp = NEW(id_list_t);
            tmp->next = (yyvsp[0].id_list_f);
            (yyval.id_list_f) = tmp;
      }
#line 1763 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 344 "parser.y" /* yacc.c:1646  */
    {
            id_list_t* tmp = NEW(id_list_t);
            tmp->label = (yyvsp[0].str);
            (yyval.id_list_f) = tmp; 
            add_symbol((yyvsp[0].str), NULL);
      }
#line 1774 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 350 "parser.y" /* yacc.c:1646  */
    {
            id_list_t* tmp = NEW(id_list_t);
            (yyval.id_list_f) = tmp; 
      }
#line 1783 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 357 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BINT;
        tmp->val.intval = (yyvsp[0].intval);
        (yyval.basic_val_f) = tmp;
    }
#line 1794 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 363 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BFLOAT;
        tmp->val.floatval = (yyvsp[0].floatval);
        (yyval.basic_val_f) = tmp;
    }
#line 1805 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 369 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BBOOL;
        tmp->val.boolval = (yyvsp[0].boolval);
        (yyval.basic_val_f) = tmp; 
    }
#line 1816 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 375 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BLABEL;
        tmp->val.label = (yyvsp[0].str);
        (yyval.basic_val_f) = tmp; 
        add_symbol((yyvsp[0].str), NULL);
    }
#line 1828 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 382 "parser.y" /* yacc.c:1646  */
    {
        basic_val_t* tmp = NEW(basic_val_t);
        tmp->valtype = BUNIT;
        (yyval.basic_val_f) = tmp; 
    }
#line 1838 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 390 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_BASIC;
        tmp->opt.basic_val = (yyvsp[-2].basic_val_f);
        tmp->next = (yyvsp[0].list_value_f);
        (yyval.list_value_f) = tmp;
    }
#line 1850 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 397 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_LIST;
        tmp->opt.list_args_val = (yyvsp[-3].list_args_f);
        tmp->next = (yyvsp[0].list_value_f);
        (yyval.list_value_f) = tmp;
    
    }
#line 1863 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 405 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_WLD;
        (yyval.list_value_f) = tmp;
    
    }
#line 1874 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 411 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_WLD;
        tmp->next = (yyvsp[0].list_value_f);
        (yyval.list_value_f) = tmp;
    
    }
#line 1886 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 418 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_BLT;
        tmp->opt.built_list_val = (yyvsp[0].built_list_val_f);
        (yyval.list_value_f) = tmp;
    
    }
#line 1898 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 425 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        tmp->ls_type = LS_BASIC;
        tmp->opt.basic_val = (yyvsp[-2].basic_val_f);
        tmp->label = (yyvsp[0].str);
        (yyval.list_value_f) = tmp;
        add_symbol((yyvsp[0].str), NULL);
    }
#line 1911 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 433 "parser.y" /* yacc.c:1646  */
    {
        list_value_t* tmp = NEW(list_value_t);
        (yyval.list_value_f) = tmp;
    }
#line 1920 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 440 "parser.y" /* yacc.c:1646  */
    {
            list_args_t* tmp = NEW(list_args_t);
            tmp->arg = (yyvsp[0].arg_f);
            (yyval.list_args_f) = tmp;
         }
#line 1930 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 445 "parser.y" /* yacc.c:1646  */
    {
            list_args_t* tmp = NEW(list_args_t);
            tmp->arg = (yyvsp[-2].arg_f);
            tmp->next = (yyvsp[0].list_args_f);
            (yyval.list_args_f) = tmp;
         }
#line 1941 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 454 "parser.y" /* yacc.c:1646  */
    {
        (yyval.built_list_val_f) = NEW(built_list_val_t);
    }
#line 1949 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 457 "parser.y" /* yacc.c:1646  */
    {
        built_list_val_t* tmp = NEW(built_list_val_t);
        tmp->vals = (yyvsp[-1].list_args_f);
        (yyval.built_list_val_f) = tmp;
    }
#line 1959 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 465 "parser.y" /* yacc.c:1646  */
    {
        funtype_decl_t* tmp = NEW(funtype_decl_t);
        tmp->label = (yyvsp[-3].str);
        tmp->type = (yyvsp[-1].funtype_f);
        (yyval.funtype_decl_f) = tmp;
        add_symbol((yyvsp[-3].str),  (yyvsp[-1].funtype_f));

    }
#line 1972 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 476 "parser.y" /* yacc.c:1646  */
    {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_BASIC;
        tmp->tp.btype = (yyvsp[0].basic_type_f);
        (yyval.funtype_f) = tmp;
    }
#line 1983 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 482 "parser.y" /* yacc.c:1646  */
    {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_FUNC;
        tmp->tp.ftype = (yyvsp[-1].funtype_f);
        (yyval.funtype_f) = tmp;
    }
#line 1994 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 488 "parser.y" /* yacc.c:1646  */
    {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_BASIC;
        tmp->tp.btype = (yyvsp[-2].basic_type_f);
        tmp->next = (yyvsp[0].funtype_f);
        (yyval.funtype_f) = tmp;
    }
#line 2006 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 495 "parser.y" /* yacc.c:1646  */
    {
        funtype_t* tmp = NEW(funtype_t);
        tmp->typeorder = T_FUNC;
        tmp->tp.ftype = (yyvsp[-3].funtype_f);
        tmp->next = (yyvsp[0].funtype_f);
        (yyval.funtype_f) = tmp;
    }
#line 2018 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 505 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_INTEGER;
        (yyval.basic_type_f) = tmp;
    }
#line 2028 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 510 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_FLOAT;
        (yyval.basic_type_f) = tmp;
    }
#line 2038 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 515 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_BOOL;
        (yyval.basic_type_f) = tmp;
    }
#line 2048 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 520 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_LIST;
        tmp->internal_list_type = (yyvsp[-1].basic_type_f);
        (yyval.basic_type_f) = tmp;
    }
#line 2059 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 526 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_VAR;
        tmp->label = (yyvsp[0].str);
        (yyval.basic_type_f) = tmp;
        add_symbol((yyvsp[0].str), NULL);
    }
#line 2071 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 533 "parser.y" /* yacc.c:1646  */
    {
        basic_type_t* tmp = NEW(basic_type_t);
        tmp->whichtype = BT_UNIT;
        (yyval.basic_type_f) = tmp;
    }
#line 2081 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 541 "parser.y" /* yacc.c:1646  */
    {
            appexpr_t* tmp = NEW(appexpr_t);
            tmp->tp = A_APP;
            tmp->app_tp.app = (yyvsp[-1].appexpr_f);
            tmp->napp2 = (yyvsp[0].nonapp_f);
            (yyval.appexpr_f) = tmp;
       
       }
#line 2094 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 549 "parser.y" /* yacc.c:1646  */
    {
            appexpr_t* tmp = NEW(appexpr_t);
            tmp->tp = A_NAPP;
            tmp->app_tp.napp1 = (yyvsp[-1].nonapp_f);
            tmp->napp2 = (yyvsp[0].nonapp_f);
            (yyval.appexpr_f) = tmp;
       }
#line 2106 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 559 "parser.y" /* yacc.c:1646  */
    {
            nonapp_t* tmp = NEW(nonapp_t);
            tmp->tp = NA_BASIC;
            tmp->n_tp.bvalue = (yyvsp[0].basic_val_f);
            (yyval.nonapp_f) = tmp;
      }
#line 2117 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 565 "parser.y" /* yacc.c:1646  */
    {
            nonapp_t* tmp = NEW(nonapp_t);
            tmp->tp = NA_EXPR;
            tmp->n_tp.expr = (yyvsp[-1].expr_f);
            (yyval.nonapp_f) = tmp;
      }
#line 2128 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 574 "parser.y" /* yacc.c:1646  */
    {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = OP_EXPR;
        tmp->tp.op_expr = (yyvsp[0].op_f);
        (yyval.expr_f) = tmp;
    
    }
#line 2140 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 581 "parser.y" /* yacc.c:1646  */
    {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = APP_EXPR;
        tmp->tp.appexpr = (yyvsp[0].appexpr_f);
        (yyval.expr_f) = tmp;
    }
#line 2151 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 587 "parser.y" /* yacc.c:1646  */
    {
        expr_t* tmp = NEW(expr_t);
        tmp->expr_tp = IF_EXPR;
        tmp->tp.ifexpr = (yyvsp[0].ifexpr_f);
        (yyval.expr_f) = tmp;
    }
#line 2162 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 596 "parser.y" /* yacc.c:1646  */
    {
        ifexpr_t* tmp = NEW(ifexpr_t);
        tmp->expr1 = (yyvsp[-4].expr_f);
        tmp->expr2 = (yyvsp[-2].expr_f);
        tmp->expr3 = (yyvsp[0].expr_f);
        (yyval.ifexpr_f) = tmp;
    }
#line 2174 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 606 "parser.y" /* yacc.c:1646  */
    {
        yieldexpr_t* tmp = NEW(yieldexpr_t);
        tmp->yield_tp = Y_IF;
        tmp->tp.ifexpr = (yyvsp[0].ifexpr_f);
        (yyval.yieldexpr_f) = tmp;
    }
#line 2185 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 612 "parser.y" /* yacc.c:1646  */
    {
        yieldexpr_t* tmp = NEW(yieldexpr_t);
        tmp->yield_tp = Y_APP;
        tmp->tp.appexpr = (yyvsp[0].appexpr_f);
        (yyval.yieldexpr_f) = tmp;
    }
#line 2196 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 618 "parser.y" /* yacc.c:1646  */
    {
        yieldexpr_t* tmp = NEW(yieldexpr_t);
        tmp->yield_tp = Y_OP;
        tmp->tp.op_expr = (yyvsp[0].op_f);
        (yyval.yieldexpr_f) = tmp;
    }
#line 2207 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 627 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_OR;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2220 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 635 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2231 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 644 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_AND;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2244 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 652 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2255 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 661 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_EQ;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2268 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 669 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_DIFF;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2281 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 677 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_LESS;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2294 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 685 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_LEQ;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2307 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 693 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_GREATER;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2320 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 701 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_GEQ;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2333 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 709 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2344 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 718 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_CONS;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2357 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 726 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_APPEND;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2370 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 734 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2381 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 743 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_PLUS;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2394 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 751 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_MINUS;
        tmp->opt.opt1 = (yyvsp[-2].op_f);
        tmp->opt2 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    
    }
#line 2407 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 759 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2418 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 769 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
     }
#line 2429 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 780 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEXT;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2440 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 789 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_BVALUE;
        tmp->opt.bval = (yyvsp[0].basic_val_f);
        (yyval.op_f) = tmp;
    }
#line 2451 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 795 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_LIST;
        tmp->opt.lexpr = (yyvsp[0].list_expr_f);
        (yyval.op_f) = tmp;
    }
#line 2462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 801 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_EXPR;
        tmp->opt.expr = (yyvsp[-1].expr_f);
        (yyval.op_f) = tmp;
    }
#line 2473 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 807 "parser.y" /* yacc.c:1646  */
    {
        op_t* tmp = NEW(op_t);
        tmp->op_tp = O_NEG;
        tmp->opt.opt1 = (yyvsp[0].op_f);
        (yyval.op_f) = tmp;
    }
#line 2484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 816 "parser.y" /* yacc.c:1646  */
    {
        exprs_t* tmp = NEW(exprs_t);
        tmp->expr = (yyvsp[0].expr_f);
        (yyval.exprs_f) = tmp;
    }
#line 2494 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 821 "parser.y" /* yacc.c:1646  */
    {
        exprs_t* tmp = NEW(exprs_t);
        tmp->expr = (yyvsp[-2].expr_f);
        tmp->next = (yyvsp[0].exprs_f);
        (yyval.exprs_f) = tmp;
    
    }
#line 2506 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 831 "parser.y" /* yacc.c:1646  */
    {
        list_expr_t* tmp = NEW(list_expr_t);
        tmp->inner = (yyvsp[-1].exprs_f);
        (yyval.list_expr_f) = tmp;
     }
#line 2516 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 836 "parser.y" /* yacc.c:1646  */
    {
        (yyval.list_expr_f) = NEW(exprs_t);
    }
#line 2524 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 843 "parser.y" /* yacc.c:1646  */
    {
        where_t* tmp = NEW(where_t);
        tmp->lines = (yyvsp[-1].lines_f);
        (yyval.where_f) = tmp;
    }
#line 2534 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 852 "parser.y" /* yacc.c:1646  */
    { 
        proc_t* tmp = NEW(proc_t);
        decl_t* d = (yyvsp[-4].decl_f);
        tmp->label = d->label;
        tmp->args = d->args;
        tmp->stmts = (yyvsp[-1].stmts_f);
        (yyval.proc_f) = tmp;
        free(d);

        leave_ctxt();
    }
#line 2550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 863 "parser.y" /* yacc.c:1646  */
    { 
        proc_t* tmp = NEW(proc_t);
        decl_t* d = (yyvsp[-5].decl_f);
        tmp->label = d->label;
        tmp->args = d->args;
        tmp->stmts = (yyvsp[-2].stmts_f);
        tmp->where_exp = (yyvsp[0].where_f);
        (yyval.proc_f) = tmp;
        free(d);


        leave_ctxt();
    }
#line 2568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 876 "parser.y" /* yacc.c:1646  */
    { 
        proc_t* tmp = NEW(proc_t);
        decl_t* d = (yyvsp[-4].decl_f);
        tmp->label = d->label;
        tmp->stmts = (yyvsp[-1].stmts_f);
        (yyval.proc_f) = tmp;
        free(d);

        leave_ctxt();
    }
#line 2583 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 886 "parser.y" /* yacc.c:1646  */
    { 
        proc_t* tmp = NEW(proc_t);
        decl_t* d = (yyvsp[-5].decl_f);
        tmp->label = d->label;
        tmp->stmts = (yyvsp[-2].stmts_f);
        tmp->where_exp = (yyvsp[0].where_f);
        (yyval.proc_f) = tmp;
        free(d);

        leave_ctxt();
    }
#line 2599 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 897 "parser.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2605 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 901 "parser.y" /* yacc.c:1646  */
    {
        stmts_t* tmp = NEW(stmts_t);
        tmp->stmt = (yyvsp[0].stmt_f);
        (yyval.stmts_f) = tmp;
    }
#line 2615 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 906 "parser.y" /* yacc.c:1646  */
    {
        stmts_t* tmp = NEW(stmts_t);
        tmp->stmt = (yyvsp[-1].stmt_f);
        tmp->next = (yyvsp[0].stmts_f);
        (yyval.stmts_f) = tmp;
    }
#line 2626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 915 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_EXPR;
       tmp->lhs = (yyvsp[-3].id_list_f);
       tmp->body.expr = (yyvsp[-1].expr_f);
       (yyval.stmt_f) = tmp;
    }
#line 2638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 922 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_WH;
       tmp->lhs = (yyvsp[-2].id_list_f);
       tmp->body.while_expr = (yyvsp[0].while_f);
       (yyval.stmt_f) = tmp;
    }
#line 2650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 929 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_IO;
       tmp->lhs = (yyvsp[-3].id_list_f);
       tmp->body.io_expr = (yyvsp[-1].io_f);
       (yyval.stmt_f) = tmp;
    }
#line 2662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 936 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_YIELD;
       tmp->body.yieldexpr = (yyvsp[-1].yieldexpr_f);
       (yyval.stmt_f) = tmp;
    }
#line 2673 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 942 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_WH;
       tmp->body.while_expr = (yyvsp[0].while_f);
       (yyval.stmt_f) = tmp;
    }
#line 2684 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 948 "parser.y" /* yacc.c:1646  */
    {
       stmt_t* tmp = NEW(stmt_t);
       tmp->stmt_type = STMT_IO;
       tmp->body.io_expr = (yyvsp[-1].io_f);
       (yyval.stmt_f) = tmp;
    }
#line 2695 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 954 "parser.y" /* yacc.c:1646  */
    { yyerrok; }
#line 2701 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 958 "parser.y" /* yacc.c:1646  */
    {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_READINT;
        (yyval.io_f) = tmp;
    }
#line 2711 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 963 "parser.y" /* yacc.c:1646  */
    {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_READFLOAT;
        (yyval.io_f) = tmp;
    }
#line 2721 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 968 "parser.y" /* yacc.c:1646  */
    {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_READBOOL;
        (yyval.io_f) = tmp;
    }
#line 2731 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 973 "parser.y" /* yacc.c:1646  */
    {
        io_t* tmp = NEW(io_t);
        tmp->opt = I_PRINT;
        tmp->expr = (yyvsp[0].expr_f);
        (yyval.io_f) = tmp;
    }
#line 2742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 982 "parser.y" /* yacc.c:1646  */
    { 
                while_t* tmp = NEW(while_t);
                tmp->expr = (yyvsp[-4].expr_f);
                tmp->stmts = (yyvsp[-1].stmts_f);
                (yyval.while_f) = tmp;
    }
#line 2753 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 2757 "parser.tab.c" /* yacc.c:1646  */
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
#line 989 "parser.y" /* yacc.c:1906  */


void print_basictype(basic_type_t* btype) {
    if(btype) {
        switch(btype->whichtype) {
            case BT_INTEGER:
                printf("Integer");
                break;
            case BT_FLOAT:
                printf("Float");
                break;
            case BT_BOOL:
                printf("Bool");
                break;
            case BT_LIST:
                printf("[");
                print_basictype(btype->internal_list_type);
                printf("]");
                break;
            case BT_VAR:
                printf("%s", btype->label);
                break;
            default:
                printf("()");
                break;
        }
    } 
}

void print_type(funtype_t* type) {
    if(type) {
        if(type->typeorder == T_BASIC) {
            basic_type_t* btype = type->tp.btype;
            print_basictype(btype);
        } else {
            print_type(type->tp.ftype); 
        }
        if(type->next != NULL) {
            printf(" -> ");
            print_type(type->next);
        }
    }
}

void print_symbols() {
    /*sym_node_t* cur = NULL;*/
    /*cur = symtable;*/
    /*// Printando erros*/
    /*printf("================== Symbol table ==================\n");*/
    /*while(cur != NULL) {*/
        /*if(cur->type == NULL) {*/
            /*printf("Symbol: %s\t\tType: ?\n", cur->label); */
        /*} else {*/
            /*printf("Symbol: %s\t\tType: ", cur->label); */
            /*print_type(cur->type);*/
            /*printf("\n");*/
        
        /*}*/
        /*cur = cur->next;*/
    /*}*/
    /*[>del_list(error_list_root);<]*/
    /*symtable = NULL;*/
    /*printf("\n");*/

}
void print_errors() {
    list_error_t* cur = NULL;
    cur = error_list_root;
    // Printando erros
    while(cur != NULL) {
        printf("%s\n", cur->erro->msg); 
        cur = cur->next;
    }
    /*del_list(error_list_root);*/
    error_list_root = NULL;
    printf("\n");

}


void ident(int lvl) {
    while(lvl) {
        printf("|");
        lvl--;
    }
}

/*  Função para imprimir um nó e seus filhos.
    Como a árvore é heterogênea, a union do bison é usada para receber os nós.
    Um enum é usado para identificar qual o nó ativo da union.
    Para tratar a identação, o parâmetro lvl é usado e incrementado nas chamadas
    recursivas.
    O uso de memset é para garantir que não ocorram problemas devido às sobreposições
    nas posições de memória no uso da union.*/
void print_tree(YYSTYPE node, char node_type, int lvl) {
    YYSTYPE tmp;
    memset(&tmp, 0, sizeof(YYSTYPE));
    switch(node_type) {
        case WHILE_T:
            ident(lvl); printf("| while_expr\n");
            tmp.expr_f = node.while_f->expr;
            ident(lvl + 1); printf("| (\n");
            print_tree(tmp, EXPR_T, lvl + 1);
            ident(lvl + 1); printf("| )\n");
            ident(lvl + 1); printf("| {\n");
            memset(&tmp, 0, sizeof(YYSTYPE));
            tmp.stmts_f = node.while_f->stmts;
            print_tree(tmp, STMTS_T, lvl + 1);
            ident(lvl + 1); printf("| }\n");
            break;
        case IO_T:
            ident(lvl); printf("| io_stmt\n");
            switch(node.io_f->opt) {
                case I_READINT:
                    ident(lvl + 1); printf("| READINT\n");
                    break;
                case I_READFLOAT:
                    ident(lvl + 1); printf("| READFLOAT\n");
                    break;
                case I_READBOOL:
                    ident(lvl + 1); printf("| READBOOL\n");
                    break;
                case I_PRINT:
                    ident(lvl + 1); printf("| PRINT\n");
                    tmp.expr_f = node.io_f->expr;
                    print_tree(tmp, EXPR_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case STMT_T:
            ident(lvl); printf("| stmt\n");
            switch(node.stmt_f->stmt_type) {
                case STMT_EXPR:
                    if(node.stmt_f->lhs != NULL) {
                        ident(lvl + 1); printf("| id_list \n");
                        tmp.id_list_f = node.stmt_f->lhs;
                        print_tree(tmp, ID_LIST_T, lvl + 1);
                        ident(lvl + 1); printf("| LARROW\n");
                    }
                    tmp.expr_f = node.stmt_f->body.expr;
                    print_tree(tmp, EXPR_T, lvl + 1);
                    ident(lvl + 1); printf("| ;\n");
                    break;
                case STMT_WH:
                    if(node.stmt_f->lhs != NULL) {
                        ident(lvl + 1); printf("| id_list \n");
                        tmp.id_list_f = node.stmt_f->lhs;
                        print_tree(tmp, ID_LIST_T, lvl + 1);
                        ident(lvl + 1); printf("| LARROW\n");
                    }
                    tmp.while_f = node.stmt_f->body.while_expr;
                    print_tree(tmp, WHILE_T, lvl + 1);
                    break;
                case STMT_IO:
                    if(node.stmt_f->lhs != NULL) {
                        ident(lvl + 1); printf("| id_list \n");
                        tmp.id_list_f = node.stmt_f->lhs;
                        print_tree(tmp, ID_LIST_T, lvl + 1);
                        ident(lvl + 1); printf("| LARROW\n");
                    }
                    tmp.io_f = node.stmt_f->body.io_expr;
                    print_tree(tmp, IO_T, lvl + 1);
                    ident(lvl + 1); printf("| ;\n");
                    break;
                case STMT_YIELD:
                    if(node.stmt_f->lhs != NULL) {
                        ident(lvl + 1); printf("| id_list \n");
                        tmp.id_list_f = node.stmt_f->lhs;
                        print_tree(tmp, ID_LIST_T, lvl + 1);
                        ident(lvl + 1); printf("| LARROW\n");
                    }
                    memset(&tmp, 0, sizeof(YYSTYPE));
                    tmp.yieldexpr_f = node.stmt_f->body.yieldexpr;
                    print_tree(tmp, YIELDEXPR_T, lvl + 1);
                    ident(lvl + 1); printf("| ;\n");
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case STMTS_T:
            ident(lvl); printf("| stmts\n");

            tmp.stmt_f = node.stmts_f->stmt;
            print_tree(tmp, STMT_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));

            if(node.stmts_f->next != NULL) {
                tmp.stmts_f = node.stmts_f->next;
                print_tree(tmp, STMTS_T, lvl + 1);
            }
            break;
        case ID_LIST_T:
            ident(lvl); printf("| id_list\n");

            ident(lvl + 1); printf("| ID, %s\n", node.id_list_f->label);

            if(node.id_list_f->next != NULL) {
                tmp.id_list_f = node.id_list_f->next;
                print_tree(tmp, ID_LIST_T, lvl + 1);
            }
            break;
            break;
        case PROC_T:
            ident(lvl); printf("| procdecl\n");
            ident(lvl + 1); printf("| ID, %s\n", node.proc_f->label);
            if(node.proc_f->args != NULL) {
                tmp.args_f = node.proc_f->args;
                print_tree(tmp, ARGS_T, lvl + 1);
            }
            memset(&tmp, 0, sizeof(YYSTYPE));
            ident(lvl + 1); printf("| = \n");
            ident(lvl + 1); printf("| DO \n");

            ident(lvl + 1); printf("| { \n");
            tmp.stmts_f = node.proc_f->stmts;
            print_tree(tmp, STMTS_T, lvl + 1);
            ident(lvl + 1); printf("| } \n");
            memset(&tmp, 0, sizeof(YYSTYPE));

            if(node.proc_f->where_exp != NULL) {
                tmp.where_f = node.proc_f->where_exp;
                print_tree(tmp, WHERE_T, lvl + 1);
            }
            break;
        case APPEXPR_T:
            ident(lvl); printf("| appexpr\n");
            switch(node.appexpr_f->tp) {
                case A_APP:
                    tmp.appexpr_f = node.appexpr_f->app_tp.app;
                    print_tree(tmp, APPEXPR_T, lvl + 1);
                    break;
                case A_NAPP:
                    tmp.nonapp_f = node.appexpr_f->app_tp.napp1;
                    print_tree(tmp, NONAPP_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            memset(&tmp, 0, sizeof(YYSTYPE));
            tmp.nonapp_f = node.appexpr_f->napp2;
            print_tree(tmp, NONAPP_T, lvl + 1);
            break;
        case NONAPP_T:
            ident(lvl); printf("| nonapp\n");
            switch(node.nonapp_f->tp) {
                case NA_BASIC:
                    tmp.basic_val_f = node.nonapp_f->n_tp.bvalue;
                    print_tree(tmp, BASIC_VAL_T, lvl + 1);
                    break;
                case NA_EXPR:
                    tmp.expr_f = node.nonapp_f->n_tp.expr;
                    print_tree(tmp, EXPR_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case WHERE_T:
            ident(lvl); printf("| where_exp\n");
            ident(lvl + 1); printf("| WHERE\n");
            ident(lvl + 1); printf("| {\n");
            tmp.lines_f = node.where_f->lines;
            print_tree(tmp, LINES_T, lvl + 1);
            ident(lvl + 1); printf("| }\n");
            break;
        case EXPRS_T:
            ident(lvl); printf("| exprs\n");
            tmp.expr_f = node.exprs_f->expr;
            print_tree(tmp, EXPR_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));
            if(node.exprs_f->next != NULL) {
                tmp.exprs_f = node.exprs_f->next;
                print_tree(tmp, EXPRS_T, lvl + 1);
            }
            break;
        case OP_T:
            ident(lvl); printf("| op_precN\n");
            static const char* operations[] = { "OR", "AND", "EQ", "DIFF", "LESS", "LEQ", "GREATER", "GEQ", "CONS", "APPEND", "PLUS", "MINUS", "MOD", "TIMES", "DIV" };
            if(node.op_f->op_tp >= O_OR) {
                tmp.op_f = node.op_f->opt.opt1;
                print_tree(tmp, OP_T, lvl + 1);
                memset(&tmp, 0, sizeof(YYSTYPE));
                ident(lvl + 1); printf("| %s\n", operations[node.op_f->op_tp - O_OR]);
                tmp.op_f = node.op_f->opt2;
                print_tree(tmp, OP_T, lvl + 1);
            } else {
                switch(node.op_f->op_tp) {
                    case O_BVALUE:
                        tmp.basic_val_f = node.op_f->opt.bval;
                        print_tree(tmp, BASIC_VAL_T, lvl + 1);
                        break;
                    case O_LIST:
                        tmp.list_expr_f = node.op_f->opt.lexpr;
                        print_tree(tmp, LIST_EXPR_T, lvl + 1);
                        break;
                    case O_EXPR:
                        tmp.expr_f = node.op_f->opt.expr;
                        ident(lvl + 1); printf("| (\n");
                        print_tree(tmp, EXPR_T, lvl + 1);
                        ident(lvl + 1); printf("| )\n");
                        break;
                    case O_NEG:
                        ident(lvl + 1); printf("| -\n");
                        tmp.op_f = node.op_f->opt.opt1;
                        print_tree(tmp, OP_T, lvl + 1);
                        break;
                    case O_NEXT:
                        tmp.op_f = node.op_f->opt.opt1;
                        print_tree(tmp, OP_T, lvl + 1);
                        break;
                    default:
                        printf("ERROR!"); 
                } 
            } 
            break;
        case YIELDEXPR_T:
            ident(lvl); printf("| yieldexpr\n");
            switch(node.yieldexpr_f->yield_tp) {
                case Y_IF:
                    tmp.ifexpr_f = node.yieldexpr_f->tp.ifexpr;
                    print_tree(tmp, IFEXPR_T, lvl + 1);
                    break;
                case Y_APP:
                    tmp.appexpr_f = node.yieldexpr_f->tp.appexpr;
                    print_tree(tmp, APPEXPR_T, lvl + 1);
                    break;
                case Y_OP:
                    tmp.op_f = node.yieldexpr_f->tp.op_expr;
                    print_tree(tmp, OP_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case IFEXPR_T:
            ident(lvl); printf("| ifexpr\n");
            ident(lvl + 1); printf("| IF\n");

            tmp.expr_f = node.ifexpr_f->expr1;
            print_tree(tmp, EXPR_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));

            ident(lvl + 1); printf("| THEN\n");
            ident(lvl + 1); printf("| {\n");

            tmp.expr_f = node.ifexpr_f->expr2;
            print_tree(tmp, EXPR_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));

            ident(lvl + 1); printf("| }\n");
            ident(lvl + 1); printf("| ELSE\n");
            ident(lvl + 1); printf("| {\n");

            tmp.expr_f = node.ifexpr_f->expr3;
            print_tree(tmp, EXPR_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));
            ident(lvl + 1); printf("| }\n");
            break;
        case EXPR_T:
            ident(lvl); printf("| expr\n");
            switch(node.expr_f->expr_tp) {
                case OP_EXPR:
                    tmp.op_f = node.expr_f->tp.op_expr;
                    print_tree(tmp, OP_T, lvl + 1);
                    break;
                case APP_EXPR:
                    tmp.appexpr_f = node.expr_f->tp.appexpr;
                    print_tree(tmp, APPEXPR_T, lvl + 1);
                    break;
                case IF_EXPR:
                    tmp.ifexpr_f = node.expr_f->tp.ifexpr;
                    print_tree(tmp, IFEXPR_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!\n");
                    break; 
            }
            break;
        case BASIC_TYPE_T:
            ident(lvl); printf("| basic_type\n");
            switch(node.basic_type_f->whichtype) {
                case BT_INTEGER:
                    ident(lvl + 1); printf("| INTEGER\n");
                    break;
                case BT_FLOAT:
                    ident(lvl + 1); printf("| FLOAT\n");
                    break;
                case BT_BOOL:
                    ident(lvl + 1); printf("| BOOL\n");
                    break;
                case BT_UNIT:
                    ident(lvl + 1); printf("| (\n");
                    ident(lvl + 1); printf("| )\n");
                    break;
                case BT_VAR:
                    ident(lvl + 1); printf("| ID, %s \n", node.basic_type_f->label);
                    break;
                case BT_LIST:
                    tmp.basic_type_f = node.basic_type_f->internal_list_type;
                    ident(lvl + 1); printf("| [\n");
                    print_tree(tmp, BASIC_TYPE_T, lvl + 1);
                    ident(lvl + 1); printf("| ]\n");
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case FUNTYPE_T:
            ident(lvl); printf("| funtype\n");
            switch(node.funtype_f->typeorder) {
                case T_BASIC:
                    tmp.basic_type_f = node.funtype_f->tp.btype;
                    print_tree(tmp, BASIC_TYPE_T, lvl + 1);
                    break;
                case T_FUNC:
                    tmp.funtype_f = node.funtype_f->tp.ftype;
                    print_tree(tmp, FUNTYPE_T, lvl + 1);
                    memset(&tmp, 0, sizeof(YYSTYPE));
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            if(node.funtype_f->next != NULL) {
                tmp.funtype_f = node.funtype_f->next;
                print_tree(tmp, FUNTYPE_T, lvl + 1);
            }
            break;
        case FUNTYPE_DECL_T:
            ident(lvl); printf("| funtype_decl\n");
            ident(lvl + 1); printf("| ID, %s\n", node.funtype_decl_f->label);
            ident(lvl + 1); printf("| ::\n");

            tmp.funtype_f = node.funtype_decl_f->type;
            print_tree(tmp, FUNTYPE_T, lvl + 1);
            ident(lvl + 1); printf("| ;\n");
            break;
        case BASIC_VAL_T:
            ident(lvl); printf("| basic_value\n");
            switch(node.basic_val_f->valtype) {
                case BINT:
                    ident(lvl + 1); printf("| NUMBER, %d\n", node.basic_val_f->val.intval);
                    break;
                case BFLOAT:
                    ident(lvl + 1); printf("| FLOATNUM, %.4f\n", node.basic_val_f->val.floatval);
                    break;
                case BBOOL:
                    if(node.basic_val_f->val.intval) {
                        ident(lvl + 1); printf("| BOOLVAL, True\n");
                    } else {
                        ident(lvl + 1); printf("| BOOLVAL, False\n");
                    }
                    break;
                case BLABEL:
                    ident(lvl + 1); printf("| ID, %s \n", node.basic_val_f->val.label);
                    break;
                case BUNIT:
                    ident(lvl + 1); printf("| ( \n");;
                    ident(lvl + 1); printf("| ) \n");;
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case ARG_T:
            ident(lvl); printf("| arg_value\n");
            switch(node.arg_f->tp) {
                case AR_LIST:
                    ident(lvl + 1); printf("| ( \n");;
                    tmp.list_value_f = node.arg_f->opt.listval;
                    print_tree(tmp, LIST_VALUE_T, lvl + 1);
                    ident(lvl + 1); printf("| ) \n");;
                    break;
                case AR_BASIC:
                    tmp.basic_val_f = node.arg_f->opt.basicval;
                    print_tree(tmp, BASIC_VAL_T, lvl + 1);
                    break;
                case AR_ARG:
                    ident(lvl + 1); printf("| ( \n");;

                    tmp.arg_f = node.arg_f->opt.argval;
                    print_tree(tmp, ARG_T, lvl + 1);

                    ident(lvl + 1); printf("| ) \n");;
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case FUN_T:
            ident(lvl); printf("| fundecl\n");
            ident(lvl + 1); printf("| ID, %s\n", node.fun_f->label);
            if(node.fun_f->args != NULL) {
                tmp.args_f = node.fun_f->args;
                print_tree(tmp, ARGS_T, lvl + 1);
            }
            memset(&tmp, 0, sizeof(YYSTYPE));
            ident(lvl + 1); printf("| = \n");

            tmp.expr_f = node.fun_f->expr;
            print_tree(tmp, EXPR_T, lvl + 1);
            memset(&tmp, 0, sizeof(YYSTYPE));

            if(node.proc_f->where_exp != NULL) {
                tmp.where_f = node.proc_f->where_exp;
                print_tree(tmp, WHERE_T, lvl + 1);
            }
            ident(lvl+1); printf("| ;\n");
            break;
        case LINES_T:
            ident(lvl); printf("| line_elems\n");
            tmp.line_f = node.lines_f->line;
            print_tree(tmp, LINE_T, lvl + 1);
            if(node.lines_f->next != NULL) {
                tmp.lines_f = node.lines_f->next;
                print_tree(tmp, LINES_T, lvl + 1);
            }
            break;
        case LINE_T:
            ident(lvl); printf("| line_elem\n");
            switch(node.line_f->opt_type) {
                case L_FUN:
                    tmp.fun_f = node.line_f->opt.fun;
                    print_tree(tmp, FUN_T, lvl + 1);
                    break;
                case L_PROC:
                    tmp.proc_f = node.line_f->opt.proc;
                    print_tree(tmp, PROC_T, lvl + 1);
                    break;
                case L_FUNTYPE:
                    tmp.funtype_decl_f = node.line_f->opt.funtype;
                    print_tree(tmp, FUNTYPE_DECL_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            break;
        case ARGS_T:
            ident(lvl); printf("| args\n");
            if(node.args_f->arg != NULL) {
                tmp.arg_f = node.args_f->arg;
                print_tree(tmp, ARG_T, lvl + 1);
                if(node.args_f->next != NULL) {
                    tmp.args_f = node.args_f->next;
                    print_tree(tmp, ARGS_T, lvl + 1);
                }
            } else {
                ident(lvl + 1); printf("| UNDERSCORE\n");
                if(node.args_f->next != NULL) {
                    tmp.args_f = node.args_f->next;
                    print_tree(tmp, ARGS_T, lvl + 1);
                }
            }
            break;
        case PROGRAM_T:
            ident(lvl); printf("| program\n");
            tmp.lines_f = node.program_f->lines;
            print_tree(tmp, LINES_T, lvl + 1);
            break;
        case LIST_ARGS_T:
            ident(lvl); printf("| list_args\n");
            tmp.arg_f = node.list_args_f->arg;
            print_tree(tmp, ARG_T, lvl + 1);
            if(node.list_args_f->next != NULL) {
                printf("| ,\n");
                tmp.list_args_f = node.list_args_f->next;
                print_tree(tmp, LIST_ARGS_T, lvl + 1);
            }
            break;
        case BUILT_LIST_VAL_T:
            ident(lvl); printf("| built_list_value\n");
            ident(lvl + 1); printf("| [\n");
            if(node.built_list_val_f->vals != NULL) {
                tmp.list_args_f = node.built_list_val_f->vals;
                print_tree(tmp, LIST_ARGS_T, lvl + 1);
            }
            ident(lvl + 1); printf("| ]\n");
            break;
        case LIST_VALUE_T:
            ident(lvl); printf("| list_value\n");
            switch(node.list_value_f->ls_type) {
                case LS_BASIC:
                    tmp.basic_val_f = node.list_value_f->opt.basic_val;
                    print_tree(tmp, BASIC_VAL_T, lvl + 1);
                    break;
                case LS_LIST:
                    ident(lvl + 1); printf("| [\n");
                    tmp.list_args_f = node.list_value_f->opt.list_args_val;
                    print_tree(tmp, LIST_ARGS_T, lvl + 1);
                    ident(lvl + 1); printf("| ]\n");
                    break;
                case LS_WLD:
                    ident(lvl + 1); printf("| UNDERSCORE\n");
                    break;
                case LS_BLT:
                    tmp.built_list_val_f = node.list_value_f->opt.built_list_val;
                    print_tree(tmp, BUILT_LIST_VAL_T, lvl + 1);
                    break;
                default:
                    printf("ERRO!");
                    break; 
            }
            if(node.list_value_f->next != NULL) {
                ident(lvl + 1); printf("| :\n");
                tmp.list_value_f = node.list_value_f->next;
                print_tree(tmp, LIST_VALUE_T, lvl + 1);
            } else {
                if(node.list_value_f->label != NULL) {
                    ident(lvl + 1); printf("| :\n");
                    ident(lvl + 1); printf("ID, %s\n", node.list_value_f->label);
                } else {
                    if(node.list_value_f->ls_type != LS_BLT) {
                        ident(lvl + 1); printf("| :\n");
                        ident(lvl + 1); printf("| _\n"); 
                    }
                }
            }
            break;
        case LIST_EXPR_T:
            ident(lvl); printf("| list_expr\n");
            ident(lvl + 1); printf("| [\n");
            if(node.list_expr_f->inner != NULL) {
                tmp.exprs_f = node.list_expr_f->inner;
                print_tree(tmp, EXPRS_T, lvl + 1);
            }
            ident(lvl + 1); printf("| ]\n");
            break;
    }


}

int main(int argc, char** argv) {

    if(argc > 1) {
        yyin = fopen(argv[1], "r");
    }

    enter_ctxt();

    yyparse();


    print_errors();
    if(!has_errors) {
        print_symbols(); 
    }

    leave_ctxt();


    return 0;
}
