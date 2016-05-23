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
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         gpib_yyparse
#define yylex           gpib_yylex
#define yyerror         gpib_yyerror
#define yydebug         gpib_yydebug
#define yynerrs         gpib_yynerrs


/* Copy the first part of user declarations.  */
#line 1 "ibConfYacc.y" /* yacc.c:339  */

#include <stdio.h>
#include "ib_internal.h"
#undef EXTERN
#include "ibP.h"
#include <string.h>
#include <stdlib.h>
#include "ibConfYacc.h"
#include "ibConfLex.h"

#define YYERROR_VERBOSE
static void yyerror(struct YYLTYPE *a, void *b, void *c, const char *s)
{
	fprintf(stderr, "%s\n", s);
}

YY_DECL;

typedef struct
{
	yyscan_t yyscanner;
	ibConf_t *configs;
	unsigned int configs_length;
	unsigned int config_index;
	ibBoard_t *boards;
	unsigned int boards_length;
	int board_index;
}gpib_yyparse_private_t;

static inline gpib_yyparse_private_t* priv( gpib_yyparse_private_t *parse_arg )
{
	return parse_arg;
}

static inline ibConf_t* current_config( gpib_yyparse_private_t *parse_arg )
{
	return &parse_arg->configs[ parse_arg->config_index ];
}

static inline ibBoard_t* current_board( gpib_yyparse_private_t *parse_arg )
{
	if( parse_arg->board_index < 0 ) return NULL;
	return &parse_arg->boards[ parse_arg->board_index ];
}

void init_gpib_yyparse_private( gpib_yyparse_private_t *priv )
{
	priv->yyscanner = 0;
	priv->configs = NULL;
	priv->configs_length = 0;
	priv->config_index = 0;
	priv->boards = NULL;
	priv->boards_length = 0;
	priv->board_index = -1;
}

int parse_gpib_conf( const char *filename, ibConf_t *configs, unsigned int configs_length,
	ibBoard_t *boards, unsigned int boards_length )
{
	FILE *infile;
	int retval = 0;
	int i;
	gpib_yyparse_private_t priv;

	if( ( infile = fopen( filename, "r" ) ) == NULL )
	{
		fprintf(stderr, "failed to open configuration file\n");
		setIberr( EDVR );
		setIbcnt( errno );
		return -1;
	}

	init_gpib_yyparse_private( &priv );
	priv.configs = configs;
	priv.configs_length = configs_length;
	priv.boards = boards;
	priv.boards_length = boards_length;
	for( i = 0; i < priv.configs_length; i++ )
	{
		init_ibconf( &priv.configs[ i ] );
	}
	for( i = 0; i < priv.boards_length; i++ )
	{
		init_ibboard( &priv.boards[ i ] );
	}
	gpib_yylex_init(&priv.yyscanner);
	gpib_yyrestart(infile, priv.yyscanner);
	if(gpib_yyparse(&priv, priv.yyscanner))
	{
		fprintf(stderr, "libgpib: failed to parse configuration file\n");
//XXX setIberr()
		retval = -1 ;
	}
	gpib_yylex_destroy(priv.yyscanner);
	fclose(infile);

	if( retval == 0 )
	{
		for(i = 0; i < priv.configs_length && priv.configs[ i ].defaults.board >= 0; i++)
		{
			priv.configs[ i ].settings = priv.configs[ i ].defaults;
		}
	}

	return retval;
}

static void gpib_conf_warn_missing_equals()
{
	fprintf(stderr, "WARNING: omitting \"=\" before a boolean value in gpib config file is deprecated.\n");
}


#line 186 "./ibConfYacc.c" /* yacc.c:339  */

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
   by #include "ibConfYacc.h".  */
#ifndef YY_GPIB_YY_IBCONFYACC_H_INCLUDED
# define YY_GPIB_YY_IBCONFYACC_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int gpib_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INTERFACE = 258,
    T_DEVICE = 259,
    T_NAME = 260,
    T_MINOR = 261,
    T_BASE = 262,
    T_IRQ = 263,
    T_DMA = 264,
    T_PAD = 265,
    T_SAD = 266,
    T_TIMO = 267,
    T_EOSBYTE = 268,
    T_BOARD_TYPE = 269,
    T_PCI_BUS = 270,
    T_PCI_SLOT = 271,
    T_REOS = 272,
    T_BIN = 273,
    T_INIT_S = 274,
    T_DCL = 275,
    T_XEOS = 276,
    T_EOT = 277,
    T_MASTER = 278,
    T_LLO = 279,
    T_EXCL = 280,
    T_INIT_F = 281,
    T_AUTOPOLL = 282,
    T_NUMBER = 283,
    T_STRING = 284,
    T_BOOL = 285,
    T_TIVAL = 286
  };
#endif
/* Tokens.  */
#define T_INTERFACE 258
#define T_DEVICE 259
#define T_NAME 260
#define T_MINOR 261
#define T_BASE 262
#define T_IRQ 263
#define T_DMA 264
#define T_PAD 265
#define T_SAD 266
#define T_TIMO 267
#define T_EOSBYTE 268
#define T_BOARD_TYPE 269
#define T_PCI_BUS 270
#define T_PCI_SLOT 271
#define T_REOS 272
#define T_BIN 273
#define T_INIT_S 274
#define T_DCL 275
#define T_XEOS 276
#define T_EOT 277
#define T_MASTER 278
#define T_LLO 279
#define T_EXCL 280
#define T_INIT_F 281
#define T_AUTOPOLL 282
#define T_NUMBER 283
#define T_STRING 284
#define T_BOOL 285
#define T_TIVAL 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 121 "ibConfYacc.y" /* yacc.c:355  */

int  ival;
char *sval;
char bval;
char cval;

#line 295 "./ibConfYacc.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif



int gpib_yyparse (void *parse_arg, void* yyscanner);

#endif /* !YY_GPIB_YY_IBCONFYACC_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 325 "./ibConfYacc.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   126

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  11
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

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
       2,     2,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    34,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
       0,   141,   141,   142,   143,   144,   151,   162,   172,   173,
     174,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     204,   211,   222,   223,   224,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   243,   244,   245,   246,
     247,   250,   251,   252,   255,   256,   257
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_INTERFACE", "T_DEVICE", "T_NAME",
  "T_MINOR", "T_BASE", "T_IRQ", "T_DMA", "T_PAD", "T_SAD", "T_TIMO",
  "T_EOSBYTE", "T_BOARD_TYPE", "T_PCI_BUS", "T_PCI_SLOT", "T_REOS",
  "T_BIN", "T_INIT_S", "T_DCL", "T_XEOS", "T_EOT", "T_MASTER", "T_LLO",
  "T_EXCL", "T_INIT_F", "T_AUTOPOLL", "T_NUMBER", "T_STRING", "T_BOOL",
  "T_TIVAL", "'{'", "'}'", "'='", "','", "$accept", "input", "interface",
  "minor", "parameter", "statement", "device", "option", "assign", "flags",
  "oneflag", YY_NULLPTR
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
     285,   286,   123,   125,    61,    44
};
# endif

#define YYPACT_NINF -79

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-79)))

#define YYTABLE_NINF -33

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      49,   -79,   -14,    -6,    41,    49,    49,    27,    18,   -79,
     -79,   -79,     9,    -1,   -79,    14,    29,    32,    35,    36,
      37,   -29,     4,    38,    39,    40,    42,   -79,    44,    18,
      47,   -79,    45,    46,    48,    50,    51,    52,    53,    54,
      55,    56,    57,    24,    25,    58,    59,    26,    61,    -1,
      66,    68,    69,    70,    33,    71,   -79,    72,   -79,    73,
      75,    76,    77,    22,   -79,   -79,   -79,    79,    81,    82,
      83,    84,    85,    34,    86,    87,    89,    90,   -79,    91,
     -79,    92,    93,    94,   -79,    95,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,    22,   -79,    22,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,   -79,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     5,     0,     0,     0,     0,     0,     0,     0,     1,
       4,     3,     0,     0,    34,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,     0,    42,     0,
       0,     0,     0,    51,    31,    33,     7,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
      15,     0,     0,     0,    27,     0,     6,     9,    47,    48,
      35,    36,    50,    49,    38,    40,    43,    37,    41,    44,
      55,    54,    56,    51,    46,    51,    30,    22,    23,    24,
      11,    12,    21,    20,    13,    29,    25,    26,    16,    18,
      17,    19,    28,    52,    53
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -79,    -3,   -79,   -79,    19,   -79,   -79,    97,   -79,   -78,
     -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,    13,    48,    49,     6,    28,    29,   104,
     105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      31,    56,    10,    11,    32,    57,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,     7,    14,
      45,    46,    47,    15,    16,   123,     8,   124,    17,    18,
      19,    20,    -8,    12,    58,    21,    22,    23,    59,    24,
      25,     9,   100,    30,    26,    27,   101,   102,    50,    -2,
       1,   -32,     2,     3,    78,    80,    84,   103,    79,    81,
      85,    92,   112,    51,    93,   113,    52,     0,    87,    53,
      54,    55,    60,    61,    62,    66,    63,    64,     0,    67,
      68,     0,    69,     0,    70,    71,    72,    73,    74,    75,
      76,    77,    82,    83,    86,    88,    89,    90,    91,    94,
       0,     0,    95,    96,    97,     0,    98,    99,   106,   107,
     108,   109,   110,   111,   114,     0,   115,   116,   117,     0,
       0,   118,   119,   120,   121,   122,    65
};

static const yytype_int8 yycheck[] =
{
       1,    30,     5,     6,     5,    34,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    32,     1,
      21,    22,    23,     5,     6,   103,    32,   105,    10,    11,
      12,    13,    33,     6,    30,    17,    18,    19,    34,    21,
      22,     0,    20,    34,    26,    27,    24,    25,    34,     0,
       1,    33,     3,     4,    30,    30,    30,    35,    34,    34,
      34,    28,    28,    34,    31,    31,    34,    -1,    49,    34,
      34,    34,    34,    34,    34,    28,    34,    33,    -1,    34,
      34,    -1,    34,    -1,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    33,    29,    28,    28,    28,    28,
      -1,    -1,    30,    30,    29,    -1,    30,    30,    29,    28,
      28,    28,    28,    28,    28,    -1,    29,    28,    28,    -1,
      -1,    30,    30,    30,    30,    30,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,    37,    38,    42,    32,    32,     0,
      37,    37,     6,    39,     1,     5,     6,    10,    11,    12,
      13,    17,    18,    19,    21,    22,    26,    27,    43,    44,
      34,     1,     5,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    21,    22,    23,    40,    41,
      34,    34,    34,    34,    34,    34,    30,    34,    30,    34,
      34,    34,    34,    34,    33,    43,    28,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    30,    34,
      30,    34,    34,    34,    30,    34,    33,    40,    29,    28,
      28,    28,    28,    31,    28,    30,    30,    29,    30,    30,
      20,    24,    25,    35,    45,    46,    29,    28,    28,    28,
      28,    28,    28,    31,    28,    29,    28,    28,    30,    30,
      30,    30,    30,    45,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    38,    39,    40,    40,
      40,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    42,    43,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    44,    44,    44,    44,    44,    44,
      44,    45,    45,    45,    46,    46,    46
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     5,     3,     0,     2,
       1,     3,     3,     3,     2,     2,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     4,     0,     2,     1,     3,     3,     3,     3,     2,
       3,     3,     2,     3,     3,     1,     3,     3,     3,     3,
       3,     0,     2,     2,     1,     1,     1
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
      yyerror (&yylloc, parse_arg, yyscanner, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, parse_arg, yyscanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *parse_arg, void* yyscanner)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (parse_arg);
  YYUSE (yyscanner);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, void *parse_arg, void* yyscanner)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, parse_arg, yyscanner);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, void *parse_arg, void* yyscanner)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , parse_arg, yyscanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, parse_arg, yyscanner); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, void *parse_arg, void* yyscanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (parse_arg);
  YYUSE (yyscanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void *parse_arg, void* yyscanner)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yychar = yylex (&yylval, &yylloc, yyscanner);
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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 145 "ibConfYacc.y" /* yacc.c:1646  */
    {
				fprintf(stderr, "input error on line %i of %s\n", gpib_yyget_lineno(priv(parse_arg)->yyscanner), DEFAULT_CONFIG_FILE);
				YYABORT;
			}
#line 1587 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 6:
#line 152 "ibConfYacc.y" /* yacc.c:1646  */
    {
				current_config( parse_arg )->is_interface = 1;
				if( ++( priv(parse_arg)->config_index ) >= priv(parse_arg)->configs_length )
				{
					fprintf(stderr, "too many devices in config file\n");
					YYERROR;
				}
			}
#line 1600 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 7:
#line 162 "ibConfYacc.y" /* yacc.c:1646  */
    {
				priv(parse_arg)->board_index = (yyvsp[0].ival);
				current_config(parse_arg)->defaults.board = (yyvsp[0].ival);
				if(priv(parse_arg)->board_index < priv(parse_arg)->boards_length )
					snprintf(current_board(parse_arg)->device, sizeof(current_board( parse_arg )->device), "/dev/gpib%i", priv(parse_arg)->board_index);
				else
					YYERROR;
			}
#line 1613 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 10:
#line 175 "ibConfYacc.y" /* yacc.c:1646  */
    {
				fprintf(stderr, "parameter error on line %i of %s\n", (yylsp[0]).first_line, DEFAULT_CONFIG_FILE);
				YYABORT;
			}
#line 1622 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 11:
#line 181 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.pad = (yyvsp[0].ival);}
#line 1628 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 12:
#line 182 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.sad = (yyvsp[0].ival) - sad_offset;}
#line 1634 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 13:
#line 183 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.eos = (yyvsp[0].ival);}
#line 1640 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 14:
#line 184 "ibConfYacc.y" /* yacc.c:1646  */
    { gpib_conf_warn_missing_equals(); current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * REOS;}
#line 1646 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 15:
#line 185 "ibConfYacc.y" /* yacc.c:1646  */
    { gpib_conf_warn_missing_equals(); current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * BIN;}
#line 1652 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 16:
#line 186 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * REOS;}
#line 1658 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 17:
#line 187 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * XEOS;}
#line 1664 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 18:
#line 188 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * BIN;}
#line 1670 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 19:
#line 189 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.send_eoi = (yyvsp[0].bval);}
#line 1676 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 20:
#line 190 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.usec_timeout = (yyvsp[0].ival); }
#line 1682 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 21:
#line 191 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.usec_timeout = timeout_to_usec( (yyvsp[0].ival) ); }
#line 1688 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 22:
#line 192 "ibConfYacc.y" /* yacc.c:1646  */
    { current_board( parse_arg )->base = (yyvsp[0].ival); }
#line 1694 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 23:
#line 193 "ibConfYacc.y" /* yacc.c:1646  */
    { current_board( parse_arg )->irq = (yyvsp[0].ival); }
#line 1700 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 24:
#line 194 "ibConfYacc.y" /* yacc.c:1646  */
    { current_board( parse_arg )->dma = (yyvsp[0].ival); }
#line 1706 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 25:
#line 195 "ibConfYacc.y" /* yacc.c:1646  */
    { current_board( parse_arg )->pci_bus = (yyvsp[0].ival); }
#line 1712 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 26:
#line 196 "ibConfYacc.y" /* yacc.c:1646  */
    { current_board( parse_arg )->pci_slot = (yyvsp[0].ival); }
#line 1718 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 27:
#line 197 "ibConfYacc.y" /* yacc.c:1646  */
    { gpib_conf_warn_missing_equals(); current_board( parse_arg )->is_system_controller = (yyvsp[0].bval); }
#line 1724 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 28:
#line 198 "ibConfYacc.y" /* yacc.c:1646  */
    { current_board( parse_arg )->is_system_controller = (yyvsp[0].bval); }
#line 1730 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 29:
#line 200 "ibConfYacc.y" /* yacc.c:1646  */
    {
				strncpy(current_board( parse_arg )->board_type, (yyvsp[0].sval),
					sizeof(current_board( parse_arg )->board_type));
			}
#line 1739 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 30:
#line 205 "ibConfYacc.y" /* yacc.c:1646  */
    {
				strncpy(current_config( parse_arg )->name, (yyvsp[0].sval),
					sizeof(current_config( parse_arg )->name));
			}
#line 1748 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 31:
#line 212 "ibConfYacc.y" /* yacc.c:1646  */
    {
				current_config( parse_arg )->is_interface = 0;
				if( ++( priv(parse_arg)->config_index ) >= priv(parse_arg)->configs_length )
				{
					fprintf(stderr, "too many devices in config file\n");
					YYERROR;
				}
			}
#line 1761 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 34:
#line 225 "ibConfYacc.y" /* yacc.c:1646  */
    {
 				fprintf(stderr, "option error on line %i of config file\n", (yylsp[0]).first_line );
				YYABORT;
			}
#line 1770 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 35:
#line 232 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.pad = (yyvsp[0].ival); }
#line 1776 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 36:
#line 233 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.sad = (yyvsp[0].ival) - sad_offset; }
#line 1782 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 37:
#line 234 "ibConfYacc.y" /* yacc.c:1646  */
    { strncpy(current_config( parse_arg )->init_string,(yyvsp[0].sval),60); }
#line 1788 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 38:
#line 235 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.eos = (yyvsp[0].ival); }
#line 1794 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 39:
#line 236 "ibConfYacc.y" /* yacc.c:1646  */
    { gpib_conf_warn_missing_equals(); current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * REOS;}
#line 1800 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 40:
#line 237 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * REOS;}
#line 1806 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 41:
#line 238 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * XEOS;}
#line 1812 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 42:
#line 239 "ibConfYacc.y" /* yacc.c:1646  */
    { gpib_conf_warn_missing_equals(); current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * BIN; }
#line 1818 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 43:
#line 240 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.eos_flags |= (yyvsp[0].bval) * BIN; }
#line 1824 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 44:
#line 241 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.send_eoi = (yyvsp[0].bval);}
#line 1830 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 45:
#line 242 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->flags |= CN_AUTOPOLL; }
#line 1836 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 47:
#line 244 "ibConfYacc.y" /* yacc.c:1646  */
    { strncpy(current_config( parse_arg )->name,(yyvsp[0].sval), sizeof(current_config( parse_arg )->name));}
#line 1842 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 48:
#line 245 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.board = (yyvsp[0].ival);}
#line 1848 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 49:
#line 246 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.usec_timeout = (yyvsp[0].ival); }
#line 1854 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 50:
#line 247 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->defaults.usec_timeout = timeout_to_usec( (yyvsp[0].ival) ); }
#line 1860 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 54:
#line 255 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->flags |= CN_SLLO; }
#line 1866 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 55:
#line 256 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->flags |= CN_SDCL; }
#line 1872 "./ibConfYacc.c" /* yacc.c:1646  */
    break;

  case 56:
#line 257 "ibConfYacc.y" /* yacc.c:1646  */
    { current_config( parse_arg )->flags |= CN_EXCLUSIVE; }
#line 1878 "./ibConfYacc.c" /* yacc.c:1646  */
    break;


#line 1882 "./ibConfYacc.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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
      yyerror (&yylloc, parse_arg, yyscanner, YY_("syntax error"));
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
        yyerror (&yylloc, parse_arg, yyscanner, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, parse_arg, yyscanner);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, parse_arg, yyscanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
  yyerror (&yylloc, parse_arg, yyscanner, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, parse_arg, yyscanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, parse_arg, yyscanner);
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
#line 260 "ibConfYacc.y" /* yacc.c:1906  */


