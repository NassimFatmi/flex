
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "symtab.c"
	#include "ast.h"
	#include "ast.c"
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int err_lex;
	extern int yylex();
	void yyerror();

	// for declarations
	void add_to_names(list_t *entry);
	list_t **names;
	int nc = 0; // nombre des declaration de meme type
	
	// for the initializations of arrays
	void add_to_vals(Value val);
	Value *vals;
	int vc = 0;


/* Line 189 of yacc.c  */
#line 99 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     INT = 259,
     FLOAT = 260,
     KSTRING = 261,
     STRUCT = 262,
     VOID = 263,
     MAIN = 264,
     IF = 265,
     ELSE = 266,
     WHILE = 267,
     BREAK = 268,
     RETURN = 269,
     ASSIGN = 270,
     ADDOP = 271,
     SUBOP = 272,
     MULOP = 273,
     DIVOP = 274,
     MODOP = 275,
     OROP = 276,
     ANDOP = 277,
     NOTOP = 278,
     EQUOP = 279,
     NEQUOP = 280,
     SUPSOP = 281,
     INFSOP = 282,
     SUPOP = 283,
     INFOP = 284,
     LPAREN = 285,
     RPAREN = 286,
     LBRACK = 287,
     RBRACK = 288,
     LBRACE = 289,
     RBRACE = 290,
     SEMI = 291,
     DOT = 292,
     COMMA = 293,
     ICONST = 294,
     FCONST = 295,
     CCONST = 296,
     STRING = 297,
     ID = 298,
     TABLE = 299
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 27 "parser.y"

	// different types of values
	Value val;   
	
	// structures
	list_t* symtab_item;
	AST_Node* node;
	
	// for declarations
	int data_type;
	int const_type;



/* Line 214 of yacc.c  */
#line 194 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 206 "parser.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  86
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,    14,    17,    19,    20,    21,    22,
      28,    30,    32,    34,    36,    40,    42,    44,    47,    52,
      56,    59,    61,    62,    65,    66,    70,    76,    81,    83,
      85,    89,    91,    92,    95,    99,   101,   104,   106,   107,
     109,   111,   113,   116,   120,   123,   130,   133,   134,   140,
     142,   146,   150,   154,   158,   162,   166,   170,   174,   177,
     181,   185,   189,   193,   197,   201,   205,   207,   210,   212,
     214,   216,   218,   219,   221,   223,   225,   227,   229,   231,
     233,   238,   243,   245,   246,   250,   252
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    -1,    48,    56,     9,    30,    31,
      34,    65,    35,    -1,    48,    49,    -1,    49,    -1,    -1,
      -1,    -1,    52,    50,    53,    51,    36,    -1,     4,    -1,
       3,    -1,     5,    -1,     6,    -1,    53,    38,    54,    -1,
      54,    -1,    43,    -1,    43,    55,    -1,    55,    32,    39,
      33,    -1,    32,    39,    33,    -1,    56,    57,    -1,    57,
      -1,    -1,    59,    60,    -1,    -1,    58,    59,    60,    -1,
      61,    43,    30,    62,    31,    -1,    34,    48,    65,    35,
      -1,    52,    -1,     8,    -1,    62,    36,    63,    -1,    63,
      -1,    -1,    52,    64,    -1,    64,    38,    54,    -1,    54,
      -1,    65,    66,    -1,    66,    -1,    -1,    67,    -1,    69,
      -1,    75,    -1,    13,    36,    -1,    14,    74,    36,    -1,
      76,    36,    -1,    10,    30,    71,    31,    70,    68,    -1,
      11,    70,    -1,    -1,    12,    30,    71,    31,    70,    -1,
      66,    -1,    34,    65,    35,    -1,    71,    16,    71,    -1,
      71,    17,    71,    -1,    71,    18,    71,    -1,    71,    19,
      71,    -1,    71,    20,    71,    -1,    71,    21,    71,    -1,
      71,    22,    71,    -1,    23,    71,    -1,    71,    24,    71,
      -1,    71,    25,    71,    -1,    71,    26,    71,    -1,    71,
      27,    71,    -1,    71,    28,    71,    -1,    71,    29,    71,
      -1,    30,    71,    31,    -1,    54,    -1,    72,    73,    -1,
      76,    -1,    79,    -1,    16,    -1,    17,    -1,    -1,    39,
      -1,    40,    -1,    41,    -1,    39,    -1,    40,    -1,    41,
      -1,    42,    -1,    54,    15,    71,    36,    -1,    43,    30,
      77,    31,    -1,    78,    -1,    -1,    78,    38,    54,    -1,
      54,    -1,    43,    37,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    69,    69,    71,    75,    75,    75,    77,    77,    77,
      96,    97,    98,    99,   103,   107,   113,   113,   115,   115,
     118,   118,   118,   120,   123,   123,   125,   127,   129,   130,
     133,   133,   133,   135,   137,   137,   141,   141,   141,   144,
     145,   146,   147,   148,   149,   152,   154,   155,   158,   160,
     160,   163,   168,   173,   178,   183,   188,   193,   198,   203,
     208,   213,   218,   223,   228,   233,   237,   241,   242,   243,
     246,   246,   246,   249,   250,   251,   254,   254,   254,   254,
     256,   258,   260,   260,   262,   262,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "INT", "FLOAT", "KSTRING",
  "STRUCT", "VOID", "MAIN", "IF", "ELSE", "WHILE", "BREAK", "RETURN",
  "ASSIGN", "ADDOP", "SUBOP", "MULOP", "DIVOP", "MODOP", "OROP", "ANDOP",
  "NOTOP", "EQUOP", "NEQUOP", "SUPSOP", "INFSOP", "SUPOP", "INFOP",
  "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE", "SEMI",
  "DOT", "COMMA", "ICONST", "FCONST", "CCONST", "STRING", "ID", "TABLE",
  "$accept", "program", "structure", "declarations", "declaration", "$@1",
  "$@2", "type", "names", "variable", "array", "fonctions", "fonction",
  "$@3", "fonction_head", "fonction_tail", "return_type", "parameters",
  "parameter", "input", "instructions", "instruction", "if_instruction",
  "else_part", "while_instruction", "tail", "expression", "sign",
  "constant", "type_return", "assigment", "fonction_call", "call_params",
  "call_param", "struct_call", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    48,    50,    51,    49,
      52,    52,    52,    52,    53,    53,    54,    54,    55,    55,
      56,    56,    56,    57,    58,    57,    59,    60,    61,    61,
      62,    62,    62,    63,    64,    64,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    67,    68,    68,    69,    70,
      70,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    73,    73,    73,    74,    74,    74,    74,
      75,    76,    77,    77,    78,    78,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     8,     2,     1,     0,     0,     0,     5,
       1,     1,     1,     1,     3,     1,     1,     2,     4,     3,
       2,     1,     0,     2,     0,     3,     5,     4,     1,     1,
       3,     1,     0,     2,     3,     1,     2,     1,     0,     1,
       1,     1,     2,     3,     2,     6,     2,     0,     5,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     3,     3,     1,     2,     1,     1,
       1,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     1,     0,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    11,    10,    12,    13,     0,     2,    22,     5,     7,
       1,    29,     4,     7,     0,    21,     0,     0,     0,     0,
       0,    28,    20,     0,     6,    23,     0,    16,     8,    15,
       0,    25,    38,    32,     0,    17,     0,     0,     0,     0,
       0,     0,     0,    16,     0,     0,    37,    39,    40,    41,
       0,     0,     0,    31,     0,     0,    14,     9,    38,    72,
      72,    42,    76,    77,    78,    79,     0,    83,    72,    27,
      36,    44,    35,    33,    26,     0,    19,     0,     0,    70,
      71,    72,    72,    16,    66,     0,     0,    68,    69,     0,
      43,    85,     0,    82,     0,     0,    30,    18,     3,    58,
       0,     0,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,     0,    73,    74,    75,    67,
       0,    81,     0,    80,    34,    65,    86,    51,    52,    53,
      54,    55,    56,    57,    59,    60,    61,    62,    63,    64,
      38,    49,    47,    48,    84,     0,     0,    45,    50,    46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     5,     6,     7,     8,    19,    37,     9,    28,    84,
      35,    14,    15,    16,    17,    25,    18,    52,    53,    73,
      45,    46,    47,   147,    48,   142,    85,    86,   119,    66,
      49,    87,    92,    93,    88
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -116
static const yytype_int16 yypact[] =
{
      47,  -116,  -116,  -116,  -116,    22,  -116,   172,  -116,  -116,
    -116,  -116,  -116,  -116,   148,  -116,   172,   -28,   -14,     2,
       8,  -116,  -116,   -28,    47,  -116,    27,    24,    31,  -116,
      40,  -116,    30,    47,    36,    45,     2,    42,    38,    50,
      51,    56,    71,    33,    72,     6,  -116,  -116,  -116,  -116,
      57,     2,   -24,  -116,    62,    63,  -116,  -116,   106,   125,
     125,  -116,  -116,  -116,  -116,  -116,    70,     2,   125,  -116,
    -116,  -116,  -116,    52,  -116,    47,  -116,    84,    11,  -116,
    -116,   125,   125,   -22,  -116,   166,    59,  -116,  -116,   182,
    -116,  -116,    91,    85,   145,     2,  -116,  -116,  -116,   214,
     198,     2,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   125,   125,   125,    54,  -116,  -116,  -116,  -116,
      54,  -116,     2,  -116,  -116,  -116,  -116,   214,   214,   214,
     214,   214,   214,   214,   214,   214,   214,   214,   214,   214,
     106,  -116,   113,  -116,  -116,    48,    54,  -116,  -116,  -116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,  -116,   101,    23,  -116,  -116,    -5,  -116,   -19,
    -116,  -116,   129,  -116,   128,   122,  -116,  -116,    75,  -116,
     -55,   -41,  -116,  -116,  -116,  -115,    26,  -116,  -116,  -116,
    -116,   -31,  -116,  -116,  -116
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      29,    50,    13,    78,    70,   143,    24,    74,    67,    21,
      34,    21,    75,    44,    50,   101,    39,    56,    40,    41,
      42,    39,    10,    40,    41,    42,    44,    50,    51,    26,
      12,   149,    72,     1,     2,     3,     4,    70,    30,    44,
      39,    69,    40,    41,    42,    27,    98,    50,    91,    43,
       1,     2,     3,     4,    43,    12,    34,    33,    39,    44,
      40,    41,    42,    67,    39,    34,    40,    41,    42,    36,
      51,    38,    58,    43,   141,    54,   124,    55,    57,   141,
      59,    60,   126,   148,    50,   145,    89,    68,   140,    50,
      95,    43,    61,    71,    94,    76,    44,    43,   116,   117,
     118,    44,    77,   144,    70,   141,    90,    99,   100,    50,
      62,    63,    64,    65,    50,    50,    39,    97,    40,    41,
      42,    44,   121,   122,   146,    32,    44,    44,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,    79,    80,    22,    23,    31,     0,     0,    81,    43,
      96,     1,     2,     3,     4,    82,    11,    20,     0,     0,
       0,   102,   103,   104,   105,   106,   107,   108,    83,   109,
     110,   111,   112,   113,   114,     1,     2,     3,     4,     0,
      11,   123,   102,   103,   104,   105,   106,   107,   108,     0,
     109,   110,   111,   112,   113,   114,     0,   115,   102,   103,
     104,   105,   106,   107,   108,     0,   109,   110,   111,   112,
     113,   114,     0,   120,   102,   103,   104,   105,   106,   107,
     108,     0,   109,   110,   111,   112,   113,   114,     0,   125,
     102,   103,   104,   105,   106,   107,   108,     0,   109,   110,
     111,   112,   113,   114
};

static const yytype_int16 yycheck[] =
{
      19,    32,     7,    58,    45,   120,    34,    31,    30,    14,
      32,    16,    36,    32,    45,    37,    10,    36,    12,    13,
      14,    10,     0,    12,    13,    14,    45,    58,    33,    43,
       7,   146,    51,     3,     4,     5,     6,    78,    30,    58,
      10,    35,    12,    13,    14,    43,    35,    78,    67,    43,
       3,     4,     5,     6,    43,    32,    32,    30,    10,    78,
      12,    13,    14,    30,    10,    32,    12,    13,    14,    38,
      75,    31,    34,    43,   115,    39,    95,    32,    36,   120,
      30,    30,   101,    35,   115,   140,    60,    15,    34,   120,
      38,    43,    36,    36,    68,    33,   115,    43,    39,    40,
      41,   120,    39,   122,   145,   146,    36,    81,    82,   140,
      39,    40,    41,    42,   145,   146,    10,    33,    12,    13,
      14,   140,    31,    38,    11,    24,   145,   146,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,    16,    17,    14,    16,    23,    -1,    -1,    23,    43,
      75,     3,     4,     5,     6,    30,     8,     9,    -1,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    43,    24,
      25,    26,    27,    28,    29,     3,     4,     5,     6,    -1,
       8,    36,    16,    17,    18,    19,    20,    21,    22,    -1,
      24,    25,    26,    27,    28,    29,    -1,    31,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    25,    26,    27,
      28,    29,    -1,    31,    16,    17,    18,    19,    20,    21,
      22,    -1,    24,    25,    26,    27,    28,    29,    -1,    31,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    25,
      26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    46,    47,    48,    49,    52,
       0,     8,    49,    52,    56,    57,    58,    59,    61,    50,
       9,    52,    57,    59,    34,    60,    43,    43,    53,    54,
      30,    60,    48,    30,    32,    55,    38,    51,    31,    10,
      12,    13,    14,    43,    54,    65,    66,    67,    69,    75,
      76,    52,    62,    63,    39,    32,    54,    36,    34,    30,
      30,    36,    39,    40,    41,    42,    74,    30,    15,    35,
      66,    36,    54,    64,    31,    36,    33,    39,    65,    16,
      17,    23,    30,    43,    54,    71,    72,    76,    79,    71,
      36,    54,    77,    78,    71,    38,    63,    33,    35,    71,
      71,    37,    16,    17,    18,    19,    20,    21,    22,    24,
      25,    26,    27,    28,    29,    31,    39,    40,    41,    73,
      31,    31,    38,    36,    54,    31,    54,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      34,    66,    70,    70,    54,    65,    11,    68,    35,    70
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 69 "parser.y"
    { printf("\n FIN DE PROGRAMME AVEC SUCCESS \n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    { declare = 1; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 77 "parser.y"
    { declare = 0; ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    {
        int i;
        (yyval.node) = new_ast_decl_node((yyvsp[(1) - (5)].data_type), names, nc);
        nc = 0;

        AST_Node_Decl *temp = (AST_Node_Decl*) (yyval.node);

        // declare types of the names
        for(i=0; i < temp->names_count; i++){
            // variable
            if(temp->names[i]->st_type == UNDEF){
                set_type(temp->names[i]->st_name, temp->data_type, UNDEF);
            }
        }
        ast_traversal((yyval.node)); /* pour tester les noeuds */
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {  (yyval.data_type) = INT_TYPE;;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    { (yyval.data_type) = CHAR_TYPE;;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    { (yyval.data_type) = FLOAT_TYPE;;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    { (yyval.data_type) = STR_TYPE;;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {
		add_to_names((yyvsp[(3) - (3)].symtab_item));
	;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 108 "parser.y"
    {
		/* add_to_names($1); */
	;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    { (yyval.symtab_item) = (yyvsp[(1) - (1)].symtab_item); ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {printf("\n fin d'implementation d'une fonction a la ligne %d\n", lineno);;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { incr_scope(); ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    { hide_scope(); ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {printf("  : type de retour d'une fonction qui termine a la ligne %d\n", lineno);;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {printf("  \n void : type de retour d'une fonction qui termine a la ligne %d\n", lineno);;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {printf("  parametre d'une fonction a la ligne %d\n", lineno);;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 144 "parser.y"
    {printf("\n fin de if instruction a la ligne %d\n", lineno);;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 145 "parser.y"
    {printf("\n fin de while instruction a la ligne %d\n", lineno);;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {printf("\n assigment instruction a la ligne %d\n", lineno);;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 147 "parser.y"
    {printf("\n break instruction a la ligne %d\n", lineno);;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 148 "parser.y"
    {printf("\n return instruction a la ligne %d\n", lineno);;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    { 
	  (yyval.node) = new_ast_arithm_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {
		(yyval.node) = new_ast_arithm_node(SUB, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {
	  (yyval.node) = new_ast_arithm_node(MUL, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {
		(yyval.node) = new_ast_arithm_node(DIV, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 184 "parser.y"
    {
		(yyval.node) = new_ast_arithm_node(MOD, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {
		(yyval.node) = new_ast_bool_node(OR, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {
		(yyval.node) = new_ast_bool_node(AND, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {
	  (yyval.node) = new_ast_bool_node(NOT, (yyvsp[(2) - (2)].node), NULL);
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {
		(yyval.node) = new_ast_equ_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {
		(yyval.node) = new_ast_rel_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {
		(yyval.node) = new_ast_rel_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {
		(yyval.node) = new_ast_rel_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {
		(yyval.node) = new_ast_rel_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 229 "parser.y"
    {
		(yyval.node) = new_ast_rel_node((yyvsp[(2) - (3)].val).ival, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));
		ast_traversal((yyval.node)); /* just for testing */
	;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    {
		(yyval.node) = (yyvsp[(2) - (3)].node); /* just pass information */
	;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {
		(yyval.node) = (yyvsp[(1) - (1)].symtab_item);
	;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 243 "parser.y"
    {printf("\n Acceder a un champ d'un enregistrement a la ligne %d\n", lineno);;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 249 "parser.y"
    { (yyval.node) = new_ast_const_node(INT_TYPE, (yyvsp[(1) - (1)].val));  ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 250 "parser.y"
    { (yyval.node) = new_ast_const_node(FLOAT_TYPE, (yyvsp[(1) - (1)].val)); ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    { (yyval.node) = new_ast_const_node(CHAR_TYPE, (yyvsp[(1) - (1)].val)); ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {printf("\n Appel d'une fonction a la ligne %d\n", lineno);;}
    break;



/* Line 1455 of yacc.c  */
#line 1921 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 266 "parser.y"


void yyerror ()
{
  fprintf(stderr, "Syntax error at line %d\n", lineno);
  exit(1);
}

void add_to_names(list_t *entry){
	// first entry
	if(nc == 0){
		nc = 1;
		names = (list_t **) malloc( 1 * sizeof(list_t *));
		names[0] = entry;
	}
	// general case
	else{
		nc++;
		names = (list_t **) realloc(names, nc * sizeof(list_t *));
		names[nc - 1] = entry;		
	}
}

void add_to_vals(Value val){
	// first entry
	if(vc == 0){
		vc = 1;
		vals = (Value *) malloc(1 * sizeof(Value));
		vals[0] = val;
	}
	// general case
	else{
		vc++;
		vals = (Value *) realloc(vals, vc * sizeof(Value));
		vals[vc - 1] = val;
	}
}

int main (int argc, char *argv[]){	


	// yyparse();
	// printf("Success");
	

	// initialize symbol table
	init_hash_table();

	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();
	fclose(yyin);

	// if(err_lex == 1){printf("err lexicale");}
	// else{printf("Success de l'analyse lexicale");}

	fclose(yyin);
	printf("Parsing finished!");
	
	// symbol table dump
	yyout = fopen("table_symboles.out", "w");
	afficher_table(yyout);
	fclose(yyout);	
	
	
	return flag;
}
