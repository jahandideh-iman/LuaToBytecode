
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


	#include "SyntaxAnalyzer.h"
	#define YYSTYPE QString
	int GetNextToken (); 
	int ParserLex();
	#define yylex  GetNextToken
	void yyerror (char const *);
	#define YYTOKENTYPE ETokenType



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
     Token_EndOfFile = 0,
     Token_Identifier = 258,
     Token_IntNumber = 259,
     Token_FloatNumber = 260,
     Token_String = 261,
     Token_And = 262,
     Token_Break = 263,
     Token_Do = 264,
     Token_Else = 265,
     Token_ElseIf = 266,
     Token_End = 267,
     Token_False = 268,
     Token_For = 269,
     Token_Function = 270,
     Token_If = 271,
     Token_In = 272,
     Token_Local = 273,
     Token_Nil = 274,
     Token_Not = 275,
     Token_Or = 276,
     Token_Repeat = 277,
     Token_Return = 278,
     Token_Then = 279,
     Token_True = 280,
     Token_Until = 281,
     Token_While = 282,
     Token_Plus = 283,
     Token_Minus = 284,
     Token_Asterisk = 285,
     Token_Slash = 286,
     Token_Percent = 287,
     Token_Caret = 288,
     Token_NumberSign = 289,
     Token_Equal = 290,
     Token_NotEqual = 291,
     Token_LesserEqual = 292,
     Token_GreaterEqual = 293,
     Token_Lesser = 294,
     Token_Greater = 295,
     Token_Assign = 296,
     Token_LeftParen = 297,
     Token_RightParen = 298,
     Token_LeftBrace = 299,
     Token_RightBrace = 300,
     Token_LeftBrack = 301,
     Token_RightBrack = 302,
     Token_Semicolon = 303,
     Token_Colon = 304,
     Token_Comma = 305,
     Token_Dot = 306,
     Token_Concat = 307,
     Token_Varag = 308
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */



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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   489

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  105
/* YYNRULES -- Number of states.  */
#define YYNSTATES  174

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    12,    17,    21,    22,
      27,    28,    32,    36,    42,    47,    50,    54,    58,    62,
      64,    69,    74,    76,    80,    82,    86,    90,    92,    94,
      97,   100,   105,   110,   112,   116,   118,   122,   124,   128,
     130,   134,   138,   144,   146,   148,   150,   152,   154,   156,
     158,   160,   162,   166,   169,   171,   175,   177,   182,   186,
     188,   190,   194,   197,   202,   205,   209,   211,   213,   216,
     220,   224,   225,   227,   229,   233,   236,   240,   245,   247,
     251,   253,   255,   257,   261,   267,   269,   271,   273,   275,
     277,   279,   281,   283,   285,   287,   289,   291,   293,   295,
     297,   299,   301,   303,   305,   307
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      55,     0,    -1,    57,    -1,    48,    -1,    51,    -1,    59,
      60,    -1,    59,    60,    66,    56,    -1,    57,    26,    73,
      -1,    -1,    59,    60,    67,    56,    -1,    -1,    60,    61,
      56,    -1,     9,    57,    12,    -1,    27,    73,     9,    57,
      12,    -1,    62,     9,    57,    12,    -1,    22,    58,    -1,
      16,    63,    12,    -1,    15,    68,    80,    -1,    74,    41,
      71,    -1,    77,    -1,    14,    90,    41,    72,    -1,    14,
      70,    17,    71,    -1,    64,    -1,    64,    10,    57,    -1,
      65,    -1,    64,    11,    65,    -1,    73,    24,    57,    -1,
       8,    -1,    23,    -1,    23,    71,    -1,    18,    70,    -1,
      18,    70,    41,    71,    -1,    18,    15,    90,    80,    -1,
      69,    -1,    69,    49,    90,    -1,    90,    -1,    69,    51,
      90,    -1,    90,    -1,    70,    50,    90,    -1,    73,    -1,
      71,    50,    73,    -1,    73,    50,    73,    -1,    73,    50,
      73,    50,    73,    -1,    19,    -1,    25,    -1,    13,    -1,
      89,    -1,     6,    -1,    53,    -1,    79,    -1,    76,    -1,
      83,    -1,    73,    87,    73,    -1,    88,    73,    -1,    75,
      -1,    74,    50,    75,    -1,    90,    -1,    76,    46,    73,
      47,    -1,    76,    51,    90,    -1,    75,    -1,    77,    -1,
      42,    73,    43,    -1,    76,    78,    -1,    76,    49,    90,
      78,    -1,    42,    43,    -1,    42,    71,    43,    -1,    83,
      -1,     6,    -1,    15,    80,    -1,    81,    57,    12,    -1,
      42,    82,    43,    -1,    -1,    70,    -1,    53,    -1,    70,
      50,    53,    -1,    44,    45,    -1,    44,    84,    45,    -1,
      44,    84,    85,    45,    -1,    86,    -1,    84,    85,    86,
      -1,    50,    -1,    48,    -1,    73,    -1,    90,    41,    73,
      -1,    46,    73,    47,    41,    73,    -1,    28,    -1,    29,
      -1,    30,    -1,    31,    -1,    33,    -1,    32,    -1,    52,
      -1,    39,    -1,    37,    -1,    40,    -1,    38,    -1,    35,
      -1,    36,    -1,     7,    -1,    21,    -1,    29,    -1,    20,
      -1,    34,    -1,     4,    -1,     5,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    75,    76,    79,    80,    83,    86,    87,
      90,    91,    94,    95,    96,    97,    98,    99,   100,   101,
     104,   105,   108,   109,   112,   113,   116,   119,   120,   121,
     124,   125,   126,   129,   130,   133,   134,   137,   138,   141,
     142,   145,   146,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   163,   164,   167,   168,   169,   172,
     173,   174,   177,   178,   181,   182,   183,   184,   187,   190,
     193,   196,   197,   198,   199,   202,   203,   204,   207,   208,
     211,   212,   215,   216,   217,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     237,   238,   239,   242,   243,   246
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "Token_EndOfFile", "error", "$undefined", "Token_Identifier",
  "Token_IntNumber", "Token_FloatNumber", "Token_String", "Token_And",
  "Token_Break", "Token_Do", "Token_Else", "Token_ElseIf", "Token_End",
  "Token_False", "Token_For", "Token_Function", "Token_If", "Token_In",
  "Token_Local", "Token_Nil", "Token_Not", "Token_Or", "Token_Repeat",
  "Token_Return", "Token_Then", "Token_True", "Token_Until", "Token_While",
  "Token_Plus", "Token_Minus", "Token_Asterisk", "Token_Slash",
  "Token_Percent", "Token_Caret", "Token_NumberSign", "Token_Equal",
  "Token_NotEqual", "Token_LesserEqual", "Token_GreaterEqual",
  "Token_Lesser", "Token_Greater", "Token_Assign", "Token_LeftParen",
  "Token_RightParen", "Token_LeftBrace", "Token_RightBrace",
  "Token_LeftBrack", "Token_RightBrack", "Token_Semicolon", "Token_Colon",
  "Token_Comma", "Token_Dot", "Token_Concat", "Token_Varag", "$accept",
  "chunk", "semi", "block", "unblock", "scope", "statlist", "stat",
  "repetition", "conds", "condlist", "cond", "laststat", "binding",
  "funcname", "dottedname", "namelist", "explist1", "explist23", "exp",
  "setlist", "var", "prefixexp", "functioncall", "args", "function",
  "funcbody", "params", "parlist", "tableconstructor", "fieldlist",
  "fieldsep", "field", "binop", "uniop", "number", "name", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    59,    59,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    66,    66,    66,
      67,    67,    67,    68,    68,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    74,    74,    75,    75,    75,    76,
      76,    76,    77,    77,    78,    78,    78,    78,    79,    80,
      81,    82,    82,    82,    82,    83,    83,    83,    84,    84,
      85,    85,    86,    86,    86,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      88,    88,    88,    89,    89,    90
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     2,     4,     3,     0,     4,
       0,     3,     3,     5,     4,     2,     3,     3,     3,     1,
       4,     4,     1,     3,     1,     3,     3,     1,     1,     2,
       2,     4,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     1,     3,     1,     4,     3,     1,
       1,     3,     2,     4,     2,     3,     1,     1,     2,     3,
       3,     0,     1,     1,     3,     2,     3,     4,     1,     3,
       1,     1,     1,     3,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     2,    10,     1,     5,   105,    27,     8,     0,
       0,     0,     0,     8,    28,     0,     0,     0,     0,     0,
       0,     0,    59,     0,    60,    56,     0,     0,    37,     0,
      33,    35,   103,   104,    47,    45,     0,    43,   101,    44,
     100,   102,     0,    48,     0,    22,    24,     0,    59,    50,
      60,    49,    51,     0,    46,     0,    30,    37,     0,    15,
      29,    39,     0,     0,     3,     4,    11,     8,     6,     9,
       0,     0,    67,     0,     0,     0,     0,    62,    66,    12,
       0,     0,     0,    71,    17,     8,     0,     0,    68,    75,
       0,    82,     0,    78,    56,    16,     8,     0,    98,    99,
       8,    85,    86,    87,    88,    90,    89,    96,    97,    93,
      95,    92,    94,    91,     0,    53,     0,     0,     0,     0,
       8,    61,     0,    18,    59,    64,     0,     0,     0,    58,
      21,    38,    20,     0,    73,    72,     0,     0,    34,    36,
       0,    76,    81,    80,     0,     0,    23,    25,    26,    52,
      32,    31,     7,    40,     0,    14,    65,    57,    63,     0,
       0,    70,    69,     0,    77,    79,    83,    13,    41,    74,
       0,     0,    84,    42
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    66,     2,    59,     3,     5,    17,    18,    44,
      45,    46,    19,    20,    29,    30,    27,    60,   132,    61,
      21,    48,    49,    50,    77,    51,    84,    85,   136,    52,
      92,   144,    93,   114,    53,    54,    25
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -49
static const yytype_int16 yypact[] =
{
     -49,    53,   -49,   -49,   -49,   447,   -49,   -49,   -49,    62,
      62,   193,    14,   -49,   193,   193,   193,   -25,    61,   -25,
     -25,   -17,    -5,    48,    -1,   -49,    79,    -2,    52,    56,
       7,   -49,   -49,   -49,   -49,   -49,    56,   -49,   -49,   -49,
     -49,   -49,    15,   -49,    83,    91,   -49,   212,   -49,    48,
     -49,   -49,   -49,   193,   -49,    62,    -4,   -49,    84,   -49,
      59,   408,   246,   273,   -49,   -49,   -49,   -49,   -49,   -49,
     193,    13,   -49,   161,   193,    62,    62,   -49,   -49,   -49,
     193,    62,   193,     9,   -49,   -49,    62,    62,   -49,   -49,
     193,   408,    -7,   -49,    70,   -49,   -49,   193,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   193,   408,    56,   193,   193,   193,
     -49,   -49,   100,    59,    25,   -49,    38,   300,    45,   -49,
      59,   -49,   -49,   327,   -49,    67,    75,   107,   -49,   -49,
     354,   -49,   -49,   -49,   110,   193,   -49,   -49,   -49,   408,
     -49,    59,   408,   408,   109,   -49,   -49,   -49,   -49,   193,
      11,   -49,   -49,    81,   -49,   -49,   408,   -49,   381,   -49,
     193,   193,   408,   408
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,    85,     0,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,    27,   -49,   -49,   -49,   -49,    -9,   -48,   -49,   -11,
     -49,     5,     6,   121,     3,   -49,   -34,   -49,   -49,   -22,
     -49,   -49,   -16,   -49,   -49,   -49,    -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int16 yytable[] =
{
      47,    78,    88,    56,    62,    63,    28,    31,    26,    57,
      22,    23,     6,    58,     6,    80,     6,     6,     6,    32,
      33,    34,   123,    64,    70,   126,    65,    78,    35,    55,
      36,    91,   130,    71,    37,    38,   -54,   117,   141,    94,
      39,   142,   115,   143,    40,   -54,    81,   -19,    81,    41,
     -19,    72,   116,     4,    72,    16,    86,    16,    87,    42,
      89,    90,   134,   127,   169,     6,   -55,   122,    43,   151,
      67,   133,   128,   129,   135,   -55,   124,    23,   131,   140,
      57,   156,   150,   138,   139,   137,    47,    73,   119,    42,
      73,    79,    42,    82,    74,    95,   146,    75,    83,    76,
     148,    96,    97,   149,    68,    69,    78,   152,   153,   119,
     118,   145,   155,     6,    32,    33,    34,   160,   161,   162,
     154,   167,   170,    35,   147,    36,    24,     0,   165,    37,
      38,   158,     0,    91,   166,    39,     0,     0,     0,    40,
       0,    94,     0,     0,    41,     0,     0,     0,   168,     0,
       0,     0,    16,     0,    42,   164,    90,   131,     0,   172,
     173,     0,     0,    43,     6,    32,    33,    34,     0,     0,
       0,     0,     0,     0,    35,     0,    36,     0,     0,     0,
      37,    38,     0,     0,     0,     0,    39,     0,     0,     0,
      40,     0,     0,     0,     0,    41,     6,    32,    33,    34,
       0,     0,     0,    16,   125,    42,    35,     0,    36,     0,
       0,     0,    37,    38,    43,     0,     0,     0,    39,    98,
       0,     0,    40,     0,     0,     0,     0,    41,     0,     0,
       0,     0,     0,    99,     0,    16,   100,    42,     0,     0,
     101,   102,   103,   104,   105,   106,    43,   107,   108,   109,
     110,   111,   112,    98,     0,   120,     0,     0,     0,     0,
       0,     0,     0,     0,   113,     0,     0,    99,     0,     0,
       0,     0,     0,     0,   101,   102,   103,   104,   105,   106,
      98,   107,   108,   109,   110,   111,   112,     0,     0,     0,
       0,     0,     0,     0,    99,     0,     0,     0,   113,     0,
       0,   101,   102,   103,   104,   105,   106,    98,   107,   108,
     109,   110,   111,   112,     0,     0,   121,     0,     0,     0,
       0,    99,     0,     0,     0,   113,     0,     0,   101,   102,
     103,   104,   105,   106,    98,   107,   108,   109,   110,   111,
     112,     0,     0,     0,     0,     0,     0,   157,    99,     0,
       0,     0,   113,     0,     0,   101,   102,   103,   104,   105,
     106,    98,   107,   108,   109,   110,   111,   112,     0,     0,
       0,     0,     0,     0,     0,    99,     0,   159,     0,   113,
       0,     0,   101,   102,   103,   104,   105,   106,    98,   107,
     108,   109,   110,   111,   112,     0,     0,     0,     0,     0,
       0,   163,    99,     0,     0,     0,   113,     0,     0,   101,
     102,   103,   104,   105,   106,    98,   107,   108,   109,   110,
     111,   112,     0,     0,     0,     0,     0,     0,     0,    99,
       0,   171,     0,   113,     0,     0,   101,   102,   103,   104,
     105,   106,     0,   107,   108,   109,   110,   111,   112,     0,
       6,     0,     0,     0,     0,     7,     8,     0,     0,     0,
     113,     9,    10,    11,     0,    12,     0,     0,     0,    13,
      14,     0,     0,     0,    15,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    16
};

static const yytype_int16 yycheck[] =
{
      11,    23,    36,    12,    15,    16,     9,    10,     8,    12,
       5,     5,     3,    13,     3,    17,     3,     3,     3,     4,
       5,     6,    70,    48,    41,    73,    51,    49,    13,    15,
      15,    42,    80,    50,    19,    20,    41,    41,    45,    42,
      25,    48,    53,    50,    29,    50,    50,    48,    50,    34,
      51,     6,    55,     0,     6,    42,    49,    42,    51,    44,
      45,    46,    53,    74,    53,     3,    41,    67,    53,   117,
       9,    82,    75,    76,    83,    50,    71,    71,    81,    90,
      83,    43,   116,    86,    87,    85,    97,    42,    50,    44,
      42,    12,    44,    41,    46,    12,    96,    49,    42,    51,
     100,    10,    11,   114,    19,    20,   128,   118,   119,    50,
      26,    41,    12,     3,     4,     5,     6,    50,    43,    12,
     120,    12,    41,    13,    97,    15,     5,    -1,   144,    19,
      20,   128,    -1,   144,   145,    25,    -1,    -1,    -1,    29,
      -1,   144,    -1,    -1,    34,    -1,    -1,    -1,   159,    -1,
      -1,    -1,    42,    -1,    44,    45,    46,   160,    -1,   170,
     171,    -1,    -1,    53,     3,     4,     5,     6,    -1,    -1,
      -1,    -1,    -1,    -1,    13,    -1,    15,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
      29,    -1,    -1,    -1,    -1,    34,     3,     4,     5,     6,
      -1,    -1,    -1,    42,    43,    44,    13,    -1,    15,    -1,
      -1,    -1,    19,    20,    53,    -1,    -1,    -1,    25,     7,
      -1,    -1,    29,    -1,    -1,    -1,    -1,    34,    -1,    -1,
      -1,    -1,    -1,    21,    -1,    42,    24,    44,    -1,    -1,
      28,    29,    30,    31,    32,    33,    53,    35,    36,    37,
      38,    39,    40,     7,    -1,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    28,    29,    30,    31,    32,    33,
       7,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    52,    -1,
      -1,    28,    29,    30,    31,    32,    33,     7,    35,    36,
      37,    38,    39,    40,    -1,    -1,    43,    -1,    -1,    -1,
      -1,    21,    -1,    -1,    -1,    52,    -1,    -1,    28,    29,
      30,    31,    32,    33,     7,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    -1,    -1,    47,    21,    -1,
      -1,    -1,    52,    -1,    -1,    28,    29,    30,    31,    32,
      33,     7,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    50,    -1,    52,
      -1,    -1,    28,    29,    30,    31,    32,    33,     7,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    21,    -1,    -1,    -1,    52,    -1,    -1,    28,
      29,    30,    31,    32,    33,     7,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      -1,    50,    -1,    52,    -1,    -1,    28,    29,    30,    31,
      32,    33,    -1,    35,    36,    37,    38,    39,    40,    -1,
       3,    -1,    -1,    -1,    -1,     8,     9,    -1,    -1,    -1,
      52,    14,    15,    16,    -1,    18,    -1,    -1,    -1,    22,
      23,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    55,    57,    59,     0,    60,     3,     8,     9,    14,
      15,    16,    18,    22,    23,    27,    42,    61,    62,    66,
      67,    74,    75,    76,    77,    90,    57,    70,    90,    68,
      69,    90,     4,     5,     6,    13,    15,    19,    20,    25,
      29,    34,    44,    53,    63,    64,    65,    73,    75,    76,
      77,    79,    83,    88,    89,    15,    70,    90,    57,    58,
      71,    73,    73,    73,    48,    51,    56,     9,    56,    56,
      41,    50,     6,    42,    46,    49,    51,    78,    83,    12,
      17,    50,    41,    42,    80,    81,    49,    51,    80,    45,
      46,    73,    84,    86,    90,    12,    10,    11,     7,    21,
      24,    28,    29,    30,    31,    32,    33,    35,    36,    37,
      38,    39,    40,    52,    87,    73,    90,    41,    26,    50,
       9,    43,    57,    71,    75,    43,    71,    73,    90,    90,
      71,    90,    72,    73,    53,    70,    82,    57,    90,    90,
      73,    45,    48,    50,    85,    41,    57,    65,    57,    73,
      80,    71,    73,    73,    57,    12,    43,    47,    78,    50,
      50,    43,    12,    47,    45,    86,    73,    12,    73,    53,
      41,    50,    73,    73
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

    {qDebug("chunk");;}
    break;

  case 3:

    {qDebug("semi");;}
    break;

  case 4:

    {qDebug("semi");;}
    break;

  case 5:

    {qDebug("block");;}
    break;

  case 6:

    {qDebug("block");;}
    break;

  case 7:

    {qDebug("unblock");;}
    break;

  case 8:

    {qDebug("scope");;}
    break;

  case 9:

    {qDebug("scope");;}
    break;

  case 10:

    {qDebug("statlist");;}
    break;

  case 11:

    {qDebug("statlist");;}
    break;

  case 12:

    {qDebug("stat");;}
    break;

  case 13:

    {qDebug("stat");;}
    break;

  case 14:

    {qDebug("stat");;}
    break;

  case 15:

    {qDebug("stat");;}
    break;

  case 16:

    {qDebug("stat");;}
    break;

  case 17:

    {qDebug("stat");;}
    break;

  case 18:

    {qDebug("stat");;}
    break;

  case 19:

    {qDebug("stat");;}
    break;

  case 20:

    {qDebug("repetition");;}
    break;

  case 21:

    {qDebug("repetition");;}
    break;

  case 27:

    {qDebug("laststat");;}
    break;

  case 28:

    {qDebug("laststat");;}
    break;

  case 29:

    {qDebug("laststat");;}
    break;

  case 30:

    {qDebug("binding");;}
    break;

  case 31:

    {qDebug("binding");;}
    break;

  case 32:

    {qDebug("binding");;}
    break;

  case 35:

    {qDebug("dottedName");;}
    break;

  case 36:

    {qDebug("dottedName");;}
    break;

  case 37:

    {qDebug("namelist");;}
    break;

  case 38:

    {qDebug("namelist");;}
    break;

  case 39:

    {qDebug("explist1");;}
    break;

  case 40:

    {qDebug("explist1");;}
    break;

  case 41:

    {qDebug("explist23");;}
    break;

  case 42:

    {qDebug("explist23");;}
    break;

  case 43:

    {qDebug("exp");;}
    break;

  case 44:

    {qDebug("exp");;}
    break;

  case 45:

    {qDebug("exp");;}
    break;

  case 46:

    {qDebug("exp");;}
    break;

  case 47:

    {qDebug("exp");;}
    break;

  case 48:

    {qDebug("exp");;}
    break;

  case 49:

    {qDebug("exp");;}
    break;

  case 50:

    {qDebug("exp");;}
    break;

  case 51:

    {qDebug("exp");;}
    break;

  case 52:

    {qDebug("exp");;}
    break;

  case 53:

    {qDebug("exp");;}
    break;

  case 54:

    {qDebug("setlist");;}
    break;

  case 55:

    {qDebug("setlist");;}
    break;

  case 56:

    {qDebug("var");;}
    break;

  case 57:

    {qDebug("var");;}
    break;

  case 58:

    {qDebug("var");;}
    break;

  case 59:

    {qDebug("prefixexp");;}
    break;

  case 60:

    {qDebug("prefixexp");;}
    break;

  case 61:

    {qDebug("prefixexp");;}
    break;

  case 62:

    {qDebug("functioncall");;}
    break;

  case 63:

    {qDebug("functioncall");;}
    break;

  case 64:

    {qDebug("args");;}
    break;

  case 65:

    {qDebug("args");;}
    break;

  case 66:

    {qDebug("args");;}
    break;

  case 67:

    {qDebug("args");;}
    break;

  case 68:

    {qDebug("function");;}
    break;

  case 69:

    {qDebug("funcbody");;}
    break;

  case 70:

    {qDebug("params");;}
    break;

  case 71:

    {qDebug("parlist");;}
    break;

  case 72:

    {qDebug("parlist");;}
    break;

  case 73:

    {qDebug("parlist");;}
    break;

  case 74:

    {qDebug("parlist");;}
    break;

  case 75:

    {qDebug("tableconstructor");;}
    break;

  case 76:

    {qDebug("tableconstructor");;}
    break;

  case 77:

    {qDebug("tableconstructor");;}
    break;

  case 78:

    {qDebug("fieldlist");;}
    break;

  case 79:

    {qDebug("fieldlist");;}
    break;

  case 80:

    {qDebug("fieldsep");;}
    break;

  case 81:

    {qDebug("fieldsep");;}
    break;

  case 82:

    {qDebug("field");;}
    break;

  case 83:

    {qDebug("field");;}
    break;

  case 84:

    {qDebug("field");;}
    break;

  case 85:

    {qDebug("binop");;}
    break;

  case 86:

    {qDebug("binop");;}
    break;

  case 87:

    {qDebug("binop");;}
    break;

  case 88:

    {qDebug("binop");;}
    break;

  case 89:

    {qDebug("binop");;}
    break;

  case 90:

    {qDebug("binop");;}
    break;

  case 91:

    {qDebug("binop");;}
    break;

  case 92:

    {qDebug("binop");;}
    break;

  case 93:

    {qDebug("binop");;}
    break;

  case 94:

    {qDebug("binop");;}
    break;

  case 95:

    {qDebug("binop");;}
    break;

  case 96:

    {qDebug("binop");;}
    break;

  case 97:

    {qDebug("binop");;}
    break;

  case 98:

    {qDebug("binop");;}
    break;

  case 99:

    {qDebug("binop");;}
    break;

  case 100:

    {qDebug("uniop");;}
    break;

  case 101:

    {qDebug("uniop");;}
    break;

  case 102:

    {qDebug("uniop");;}
    break;

  case 103:

    {qDebug("number");;}
    break;

  case 104:

    {qDebug("number");;}
    break;

  case 105:

    {qDebug("name");;}
    break;



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







int GetNextToken()
{
	//qDebug("Get Next Token");
	
	return CompilerMain::GetSharedCompiler()->GetNextToken();
}

void yyerror(char const *)
{
}

SyntaxAnalyzer::SyntaxAnalyzer()
{
    
}
void SyntaxAnalyzer::Analyze()
{
	qDebug("Start Syntax Analyzer");
    if(yyparse()== 0)
		qDebug("Success");
	else
		qDebug("WTFFFFFFFFF");
}
