
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


#include <string>
#include "SyntaxAnalyzer.h"
int GetNextToken (); 
int ParserLex();
#define yylex  GetNextToken
//#define YYERROR yyerror
void yyerror ( const char *);
void emptyPrint(YYSTYPE);
void fullPrint(YYSTYPE);
void AddScope();
void EmitIntToString(YYSTYPE val);
std::string toString(int val);

void EmitLine(std::string str);
void EmitStore(YYSTYPE val);
SymbolType GetType(YYSTYPE val);
bool IsTemp(YYSTYPE val);
bool IsID(YYSTYPE val);
bool IsConstString(YYSTYPE val);
bool IsConstInteger (YYSTYPE val);
void SetTypeByValueType(YYSTYPE val1,YYSTYPE val2);
void EmitComparison(YYSTYPE comparisonVal);
void RemoveTemp();
YYSTYPE CreateTemp(SymbolType type);
YYSTYPE CreateLabel();

void EmitPrint (YYSTYPE val);

void EmitLoadValue(YYSTYPE val);
YYSTYPE PopLabel();
void PushLabel(YYSTYPE label);

void ManageBinop(YYSTYPE binop, YYSTYPE firstOP, YYSTYPE secOP);
YYSTYPE GetStorage(YYSTYPE idName);
YYSTYPE FindVariableIndexInTable(YYSTYPE idName);
void AddEntry(YYSTYPE name, SymbolType type);
#define print emptyPrint
#define print1 fullPrint
#define GETINDEX FindVariableIndexInTable



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

/* "%code requires" blocks.  */


#include <string>
#define YYSTYPE std::string




/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     Token_EndOfFile = 0,
     Token_Print = 258,
     Token_Identifier = 259,
     Token_IntNumber = 260,
     Token_FloatNumber = 261,
     Token_String = 262,
     Token_And = 263,
     Token_Break = 264,
     Token_Do = 265,
     Token_Else = 266,
     Token_ElseIf = 267,
     Token_End = 268,
     Token_False = 269,
     Token_For = 270,
     Token_Function = 271,
     Token_If = 272,
     Token_In = 273,
     Token_Local = 274,
     Token_Nil = 275,
     Token_Not = 276,
     Token_Or = 277,
     Token_Repeat = 278,
     Token_Return = 279,
     Token_Then = 280,
     Token_True = 281,
     Token_Until = 282,
     Token_While = 283,
     Token_Plus = 284,
     Token_Minus = 285,
     Token_Asterisk = 286,
     Token_Slash = 287,
     Token_Percent = 288,
     Token_Caret = 289,
     Token_NumberSign = 290,
     Token_Equal = 291,
     Token_NotEqual = 292,
     Token_LesserEqual = 293,
     Token_GreaterEqual = 294,
     Token_Lesser = 295,
     Token_Greater = 296,
     Token_Assign = 297,
     Token_LeftParen = 298,
     Token_RightParen = 299,
     Token_LeftBrace = 300,
     Token_RightBrace = 301,
     Token_LeftBrack = 302,
     Token_RightBrack = 303,
     Token_Semicolon = 304,
     Token_Colon = 305,
     Token_Comma = 306,
     Token_Dot = 307,
     Token_Concat = 308,
     Token_Varag = 309
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
#define YYLAST   359

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  170

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    16,    20,    21,
      26,    27,    31,    36,    40,    41,    42,    50,    52,    55,
      56,    61,    65,    69,    71,    72,    83,    84,    97,   105,
     107,   108,   113,   115,   116,   121,   122,   127,   129,   131,
     134,   137,   142,   147,   149,   153,   155,   159,   161,   165,
     167,   171,   173,   175,   177,   179,   181,   183,   185,   187,
     189,   193,   196,   198,   203,   205,   210,   212,   214,   217,
     222,   225,   229,   231,   233,   236,   240,   244,   245,   247,
     249,   253,   257,   259,   261,   263,   265,   267,   269,   271,
     273,   275,   277,   279,   281,   283,   285,   287,   289,   291,
     293,   295,   297
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    58,    -1,    -1,    49,    -1,    60,    61,
      -1,    60,    61,    75,    57,    -1,    58,    27,    81,    -1,
      -1,    60,    61,    76,    57,    -1,    -1,    61,    62,    57,
      -1,     3,    43,    81,    44,    -1,    10,    58,    13,    -1,
      -1,    -1,    28,    63,    81,    64,    10,    58,    13,    -1,
      66,    -1,    23,    59,    -1,    -1,    17,    65,    69,    13,
      -1,    16,    77,    88,    -1,    82,    42,    81,    -1,    85,
      -1,    -1,    15,    95,    42,    81,    51,    81,    67,    10,
      58,    13,    -1,    -1,    15,    95,    42,    81,    51,    81,
      51,    81,    68,    10,    58,    13,    -1,    15,    79,    18,
      80,    10,    58,    13,    -1,    71,    -1,    -1,    71,    11,
      70,    58,    -1,    73,    -1,    -1,    71,    12,    72,    73,
      -1,    -1,    81,    74,    25,    58,    -1,     9,    -1,    24,
      -1,    24,    80,    -1,    19,    79,    -1,    19,    79,    42,
      80,    -1,    19,    16,    95,    88,    -1,    78,    -1,    78,
      50,    95,    -1,    95,    -1,    78,    52,    95,    -1,    95,
      -1,    79,    51,    95,    -1,    81,    -1,    80,    51,    81,
      -1,    20,    -1,    26,    -1,    14,    -1,    94,    -1,     7,
      -1,    54,    -1,    87,    -1,    84,    -1,    91,    -1,    81,
      92,    81,    -1,    93,    81,    -1,    95,    -1,    95,    47,
      81,    48,    -1,    95,    -1,    95,    47,    81,    48,    -1,
      83,    -1,    85,    -1,    84,    86,    -1,    84,    50,    95,
      86,    -1,    43,    44,    -1,    43,    80,    44,    -1,    91,
      -1,     7,    -1,    16,    88,    -1,    89,    58,    13,    -1,
      43,    90,    44,    -1,    -1,    79,    -1,    54,    -1,    79,
      51,    54,    -1,    45,    81,    46,    -1,    29,    -1,    30,
      -1,    31,    -1,    32,    -1,    34,    -1,    33,    -1,    53,
      -1,    40,    -1,    38,    -1,    41,    -1,    39,    -1,    36,
      -1,    37,    -1,     8,    -1,    22,    -1,    30,    -1,    21,
      -1,    35,    -1,     5,    -1,     6,    -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   114,   114,   117,   118,   121,   122,   125,   128,   129,
     132,   133,   136,   137,   139,   147,   138,   166,   167,   169,
     168,   174,   175,   181,   185,   184,   211,   210,   239,   242,
     247,   246,   253,   255,   254,   263,   262,   272,   273,   274,
     277,   278,   279,   282,   283,   286,   287,   290,   291,   294,
     295,   299,   300,   301,   302,   303,   304,   305,   306,   307,
     308,   318,   321,   322,   329,   330,   340,   341,   344,   345,
     348,   349,   350,   351,   354,   357,   360,   363,   364,   365,
     366,   369,   380,   381,   382,   383,   384,   385,   386,   387,
     388,   389,   390,   391,   392,   393,   394,   397,   398,   399,
     402,   403,   406
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "Token_EndOfFile", "error", "$undefined", "Token_Print",
  "Token_Identifier", "Token_IntNumber", "Token_FloatNumber",
  "Token_String", "Token_And", "Token_Break", "Token_Do", "Token_Else",
  "Token_ElseIf", "Token_End", "Token_False", "Token_For",
  "Token_Function", "Token_If", "Token_In", "Token_Local", "Token_Nil",
  "Token_Not", "Token_Or", "Token_Repeat", "Token_Return", "Token_Then",
  "Token_True", "Token_Until", "Token_While", "Token_Plus", "Token_Minus",
  "Token_Asterisk", "Token_Slash", "Token_Percent", "Token_Caret",
  "Token_NumberSign", "Token_Equal", "Token_NotEqual", "Token_LesserEqual",
  "Token_GreaterEqual", "Token_Lesser", "Token_Greater", "Token_Assign",
  "Token_LeftParen", "Token_RightParen", "Token_LeftBrace",
  "Token_RightBrace", "Token_LeftBrack", "Token_RightBrack",
  "Token_Semicolon", "Token_Colon", "Token_Comma", "Token_Dot",
  "Token_Concat", "Token_Varag", "$accept", "chunk", "semi", "block",
  "unblock", "scope", "statlist", "stat", "@1", "$@2", "$@3", "repetition",
  "$@4", "$@5", "conds", "$@6", "condlist", "$@7", "cond", "$@8",
  "laststat", "binding", "funcname", "dottedname", "namelist", "explist1",
  "exp", "lvar", "rvar", "prefixexp", "functioncall", "args", "function",
  "funcbody", "params", "parlist", "tableconstructor", "binop", "uniop",
  "number", "name", 0
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
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    56,    57,    57,    58,    58,    59,    60,    60,
      61,    61,    62,    62,    63,    64,    62,    62,    62,    65,
      62,    62,    62,    62,    67,    66,    68,    66,    66,    69,
      70,    69,    71,    72,    71,    74,    73,    75,    75,    75,
      76,    76,    76,    77,    77,    78,    78,    79,    79,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    86,    86,    87,    88,    89,    90,    90,    90,
      90,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    93,    93,    93,
      94,    94,    95
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     4,     3,     0,     4,
       0,     3,     4,     3,     0,     0,     7,     1,     2,     0,
       4,     3,     3,     1,     0,    10,     0,    12,     7,     1,
       0,     4,     1,     0,     4,     0,     4,     1,     1,     2,
       2,     4,     4,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     2,     1,     4,     1,     4,     1,     1,     2,     4,
       2,     3,     1,     1,     2,     3,     3,     0,     1,     1,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       8,     0,     2,    10,     1,     5,     0,   102,    37,     8,
       0,     0,    19,     0,     8,    38,    14,     3,    17,     3,
       3,     0,    66,     0,    23,    64,     0,     0,     0,    47,
       0,    43,    45,     0,     0,    40,    47,     0,    18,   100,
     101,    55,    53,     0,    51,    98,    52,    97,    99,     0,
      56,    39,    49,    58,    67,    57,    59,     0,    54,    64,
       0,     4,    11,     6,     9,     0,    73,     0,     0,    68,
      72,     0,     0,    13,     0,     0,     0,    77,    21,     8,
       0,     0,     0,    29,    32,    35,     0,     0,     0,    74,
       0,     0,    95,    96,    82,    83,    84,    85,    87,    86,
      93,    94,    90,    92,    89,    91,    88,     0,    61,     0,
      15,    22,    70,     0,     0,     0,    12,     0,    48,     0,
      79,    78,     0,     0,    44,    46,    20,    30,    33,     0,
      42,    41,     7,    81,    50,    60,     0,     0,    71,    69,
      65,     8,     0,     0,    76,    75,     8,     0,     8,    65,
       8,     0,    24,    80,    31,    34,    36,     0,    28,     0,
       0,    16,    26,     8,     0,     0,     8,    25,     0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    62,     2,    38,     3,     5,    17,    60,   137,
      33,    18,   160,   164,    82,   146,    83,   147,    84,   129,
      19,    20,    30,    31,    28,    51,    52,    21,    22,    53,
      54,    69,    55,    78,    79,   122,    56,   107,    57,    58,
      59
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -52
static const yytype_int16 yypact[] =
{
     -52,    29,   -52,   -52,   -52,   331,   -11,   -52,   -52,   -52,
      34,    34,   -52,     2,   -52,    82,   -52,   -10,   -52,   -10,
     -10,     5,   -52,    56,    68,   -30,    82,    33,     4,    16,
      24,   -22,   -52,    82,    34,   -27,   -52,    41,   -52,   -52,
     -52,   -52,   -52,    24,   -52,   -52,   -52,   -52,   -52,    82,
     -52,    18,   292,    56,   -52,   -52,   -52,    82,   -52,    35,
      82,   -52,   -52,   -52,   -52,    82,   -52,    36,    34,   -52,
     -52,    82,   130,   -52,    82,    34,    82,     0,   -52,   -52,
      34,    34,    70,    14,   -52,   292,    24,    82,    82,   -52,
     157,    82,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,    82,   292,    82,
     292,   292,   -52,   -24,     6,   184,   -52,     9,   -52,   211,
     -52,    40,    48,    71,   -52,   -52,   -52,   -52,   -52,    60,
     -52,    18,   292,   -52,   292,   292,   238,    83,   -52,   -52,
      58,   -52,    82,     7,   -52,   -52,   -52,    82,   -52,   -52,
     -52,    91,   265,   -52,   -52,   -52,   -52,    92,   -52,    82,
      97,   -52,   292,   -52,    99,   101,   -52,   -52,   102,   -52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,    15,    -9,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -37,   -52,
     -52,   -52,   -52,   -52,    -4,   -51,   -12,   -52,   -52,   111,
     114,     8,   -52,   -42,   -52,   -52,   -20,   -52,   -52,   -52,
      -3
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -68
static const yytype_int16 yytable[] =
{
      27,    89,    25,    70,     7,    37,     7,    29,    32,    35,
      36,     7,   -62,    66,    72,    87,   113,    71,    34,   141,
     138,    85,    74,   117,    75,   127,   128,    91,    80,     4,
      81,    86,    26,    70,    63,    64,   131,    90,     7,    61,
       7,    39,    40,    41,   130,   108,    73,    65,   110,    67,
      42,    49,    43,   111,   120,    75,    44,    45,    76,   115,
      91,   153,    46,    66,   119,   114,    47,    77,    88,    91,
     123,    48,   118,   121,    36,   -67,   132,   124,   125,   134,
     112,    49,   109,   126,   145,   148,     7,    39,    40,    41,
      50,   143,   144,   150,    70,   135,    42,   136,    43,    67,
     -63,    49,    44,    45,   158,   161,    68,   163,    46,   166,
     155,   -67,    47,   -67,   167,   169,    23,    48,   -67,    24,
       0,     0,   139,     0,     0,     0,     0,    49,     0,     0,
     152,     0,   151,     0,     0,    85,    50,   154,    92,   156,
     118,   157,     0,     0,     0,     0,     0,   162,     0,     0,
       0,     0,    93,     0,   165,     0,     0,   168,     0,    94,
      95,    96,    97,    98,    99,    92,   100,   101,   102,   103,
     104,   105,     0,     0,   116,     0,     0,     0,     0,    93,
       0,     0,     0,   106,     0,     0,    94,    95,    96,    97,
      98,    99,    92,   100,   101,   102,   103,   104,   105,     0,
       0,     0,     0,   133,     0,     0,    93,     0,     0,     0,
     106,     0,     0,    94,    95,    96,    97,    98,    99,    92,
     100,   101,   102,   103,   104,   105,     0,     0,     0,     0,
       0,     0,   140,    93,     0,     0,     0,   106,     0,     0,
      94,    95,    96,    97,    98,    99,    92,   100,   101,   102,
     103,   104,   105,     0,     0,     0,     0,     0,     0,     0,
      93,     0,   142,     0,   106,     0,     0,    94,    95,    96,
      97,    98,    99,    92,   100,   101,   102,   103,   104,   105,
       0,     0,     0,     0,     0,     0,   149,    93,     0,     0,
       0,   106,     0,     0,    94,    95,    96,    97,    98,    99,
      92,   100,   101,   102,   103,   104,   105,     0,     0,     0,
       0,     0,     0,     0,    93,     0,   159,     0,   106,     0,
       0,    94,    95,    96,    97,    98,    99,     0,   100,   101,
     102,   103,   104,   105,     6,     7,     0,     0,     0,     0,
       8,     9,     0,     0,     0,   106,    10,    11,    12,     0,
      13,     0,     0,     0,    14,    15,     0,     0,     0,    16
};

static const yytype_int16 yycheck[] =
{
       9,    43,     5,    23,     4,    14,     4,    10,    11,    13,
      13,     4,    42,     7,    26,    42,    67,    47,    16,    10,
      44,    33,    18,    74,    51,    11,    12,    51,    50,     0,
      52,    34,    43,    53,    19,    20,    87,    49,     4,    49,
       4,     5,     6,     7,    86,    57,    13,    42,    60,    43,
      14,    45,    16,    65,    54,    51,    20,    21,    42,    71,
      51,    54,    26,     7,    76,    68,    30,    43,    27,    51,
      79,    35,    75,    77,    77,     7,    88,    80,    81,    91,
      44,    45,    47,    13,    13,    25,     4,     5,     6,     7,
      54,    51,    44,    10,   114,   107,    14,   109,    16,    43,
      42,    45,    20,    21,    13,    13,    50,    10,    26,    10,
     147,    43,    30,    45,    13,    13,     5,    35,    50,     5,
      -1,    -1,   114,    -1,    -1,    -1,    -1,    45,    -1,    -1,
     142,    -1,   141,    -1,    -1,   147,    54,   146,     8,   148,
     143,   150,    -1,    -1,    -1,    -1,    -1,   159,    -1,    -1,
      -1,    -1,    22,    -1,   163,    -1,    -1,   166,    -1,    29,
      30,    31,    32,    33,    34,     8,    36,    37,    38,    39,
      40,    41,    -1,    -1,    44,    -1,    -1,    -1,    -1,    22,
      -1,    -1,    -1,    53,    -1,    -1,    29,    30,    31,    32,
      33,    34,     8,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    46,    -1,    -1,    22,    -1,    -1,    -1,
      53,    -1,    -1,    29,    30,    31,    32,    33,    34,     8,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    48,    22,    -1,    -1,    -1,    53,    -1,    -1,
      29,    30,    31,    32,    33,    34,     8,    36,    37,    38,
      39,    40,    41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      22,    -1,    51,    -1,    53,    -1,    -1,    29,    30,    31,
      32,    33,    34,     8,    36,    37,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    -1,    -1,    48,    22,    -1,    -1,
      -1,    53,    -1,    -1,    29,    30,    31,    32,    33,    34,
       8,    36,    37,    38,    39,    40,    41,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    22,    -1,    51,    -1,    53,    -1,
      -1,    29,    30,    31,    32,    33,    34,    -1,    36,    37,
      38,    39,    40,    41,     3,     4,    -1,    -1,    -1,    -1,
       9,    10,    -1,    -1,    -1,    53,    15,    16,    17,    -1,
      19,    -1,    -1,    -1,    23,    24,    -1,    -1,    -1,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    56,    58,    60,     0,    61,     3,     4,     9,    10,
      15,    16,    17,    19,    23,    24,    28,    62,    66,    75,
      76,    82,    83,    84,    85,    95,    43,    58,    79,    95,
      77,    78,    95,    65,    16,    79,    95,    58,    59,     5,
       6,     7,    14,    16,    20,    21,    26,    30,    35,    45,
      54,    80,    81,    84,    85,    87,    91,    93,    94,    95,
      63,    49,    57,    57,    57,    42,     7,    43,    50,    86,
      91,    47,    81,    13,    18,    51,    42,    43,    88,    89,
      50,    52,    69,    71,    73,    81,    95,    42,    27,    88,
      81,    51,     8,    22,    29,    30,    31,    32,    33,    34,
      36,    37,    38,    39,    40,    41,    53,    92,    81,    47,
      81,    81,    44,    80,    95,    81,    44,    80,    95,    81,
      54,    79,    90,    58,    95,    95,    13,    11,    12,    74,
      88,    80,    81,    46,    81,    81,    81,    64,    44,    86,
      48,    10,    51,    51,    44,    13,    70,    72,    25,    48,
      10,    58,    81,    54,    58,    73,    58,    58,    13,    51,
      67,    13,    81,    10,    68,    58,    10,    13,    58,    13
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

    {(yyval)= (yyvsp[(1) - (1)]) ;;}
    break;

  case 3:

    { ;}
    break;

  case 4:

    {print("semi"); ;}
    break;

  case 5:

    {(yyval) = (yyvsp[(1) - (2)]) + (yyvsp[(2) - (2)]) ;  ;}
    break;

  case 6:

    {(yyval) = (yyvsp[(1) - (4)]) + (yyvsp[(2) - (4)]) + (yyvsp[(3) - (4)]) + (yyvsp[(4) - (4)]) ;  ;}
    break;

  case 7:

    {;}
    break;

  case 8:

    {;}
    break;

  case 9:

    {  ;}
    break;

  case 10:

    { (yyval) = (yyvsp[(0) - (0)]) ; ;}
    break;

  case 11:

    {(yyval) = (yyvsp[(1) - (3)]) + (yyvsp[(2) - (3)])  ; ;}
    break;

  case 12:

    { EmitPrint((yyvsp[(3) - (4)]));;}
    break;

  case 14:

    {
                                                YYSTYPE whileBegin = CreateLabel();
                                                YYSTYPE whileEnd = CreateLabel();
                                                EmitLine(whileBegin + ":");
                                                PushLabel(whileBegin);
                                                PushLabel(whileEnd);
                                        ;}
    break;

  case 15:

    {
                                                print1("EXP in while is " + (yyvsp[(2) - (3)]));
                                                
                                                //if(!IsTemp($2))
                                                        //$2=CreateTemp();
                                                EmitLoadValue((yyvsp[(2) - (3)]));
                                                YYSTYPE whileEnd = PopLabel();
                                                PushLabel(whileEnd);
                                                EmitLine("ifle " + whileEnd);

                                        ;}
    break;

  case 16:

    {
                                                YYSTYPE whileEnd = PopLabel();
                                                YYSTYPE whileBegin = PopLabel();
                                                EmitLine("goto " +whileBegin);
                                                EmitLine(whileEnd+ ":");

                                        ;}
    break;

  case 18:

    {;}
    break;

  case 19:

    {        
								PushLabel(CreateLabel());
                            ;}
    break;

  case 21:

    {;}
    break;

  case 22:

    {      
									EmitLoadValue((yyvsp[(3) - (3)]));
									SetTypeByValueType((yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));
                                    EmitStore((yyvsp[(1) - (3)]));      
                                ;}
    break;

  case 23:

    {;}
    break;

  case 24:

    {
                                    YYSTYPE forCond = CreateLabel();
                                    YYSTYPE        forEnd = CreateLabel();
                                    PushLabel(forEnd);
                                    PushLabel(forCond);
                                    AddEntry((yyvsp[(2) - (6)]),Type_Int);
                                    EmitLoadValue((yyvsp[(4) - (6)]));
                                    EmitStore( (yyvsp[(2) - (6)]));

                                    EmitLine(forCond + ":");
                                    //TODO: semantic check: it must be variable
                                    EmitLoadValue((yyvsp[(2) - (6)]));
                                    EmitLoadValue((yyvsp[(6) - (6)]));
                                    EmitLine("if_icmpgt " +forEnd);
                            ;}
    break;

  case 25:

    {
                                    EmitLoadValue(toString(1));
                                    EmitLoadValue((yyvsp[(2) - (10)]));
                                    EmitLine("iadd");
									EmitStore((yyvsp[(2) - (10)]));
                                    EmitLine("goto " + PopLabel());
                                    EmitLine(PopLabel() + ":");
                                    //TODO: temp Removing 
                            ;}
    break;

  case 26:

    {
                                        YYSTYPE forCond = CreateLabel();
                                        YYSTYPE        forEnd = CreateLabel();
                                        PushLabel(forEnd);
                                        PushLabel(forCond);
                                        AddEntry((yyvsp[(2) - (8)]),Type_Int);
                                        EmitLoadValue((yyvsp[(4) - (8)]));
                                        EmitStore((yyvsp[(2) - (8)]));

                                        EmitLine(forCond + ":");
                                        //TODO: semantic check: it must be variable
                                        EmitLoadValue((yyvsp[(2) - (8)]));
                                        EmitLoadValue((yyvsp[(6) - (8)]));
                                        EmitLine("if_icmpgt " +forEnd);
                                ;}
    break;

  case 27:

    {
                                        EmitLoadValue((yyvsp[(8) - (12)]));
                                        EmitLoadValue((yyvsp[(2) - (12)]));
                                        EmitLine("iadd");
										EmitStore((yyvsp[(2) - (12)]));
                                        EmitLine("goto " + PopLabel());
                                        EmitLine(PopLabel() + ":");
                                        //TODO: temp Removing 
                                ;}
    break;

  case 28:

    {print("repetition");;}
    break;

  case 29:

    {
							EmitLine(PopLabel()+":");
						;}
    break;

  case 30:

    {
							EmitLine(PopLabel()+":");
						;}
    break;

  case 33:

    {
							EmitLine(PopLabel() +":");
							PushLabel(CreateLabel());
						;}
    break;

  case 35:

    {
                            EmitLoadValue((yyvsp[(1) - (1)]));
                            YYSTYPE label = PopLabel();
                            PushLabel(label);
                            EmitLine("ifle " + label);
						;}
    break;

  case 36:

    {(yyval) = (yyvsp[(1) - (4)]);;}
    break;

  case 37:

    {;}
    break;

  case 38:

    {;}
    break;

  case 39:

    {;}
    break;

  case 40:

    {;}
    break;

  case 41:

    {;}
    break;

  case 42:

    {;}
    break;

  case 45:

    {;}
    break;

  case 46:

    {;}
    break;

  case 47:

    {;}
    break;

  case 48:

    {;}
    break;

  case 49:

    {(yyval) = (yyvsp[(1) - (1)]) ;;}
    break;

  case 50:

    {;}
    break;

  case 51:

    {;}
    break;

  case 52:

    {(yyval) = toString(1);}
    break;

  case 53:

    {(yyval) = toString(0);}
    break;

  case 54:

    {(yyval) = (yyvsp[(1) - (1)]) ;;}
    break;

  case 55:

    {(yyval) = yylval;;}
    break;

  case 56:

    {;}
    break;

  case 57:

    {;}
    break;

  case 58:

    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 59:

    {(yyval)=(yyvsp[(1) - (1)]);;}
    break;

  case 60:

    {
                                    ManageBinop((yyvsp[(2) - (3)]),(yyvsp[(1) - (3)]),(yyvsp[(3) - (3)]));
                                    (yyval) = CreateTemp(Type_Int);
                                    print1("in binop first exp : " +(yyvsp[(1) - (3)]));
                                    print1("in binop second exp : "+ (yyvsp[(3) - (3)]));
                                    print1("in binop operator : "+ (yyvsp[(2) - (3)]));
                                    print1("in binop result : "+ (yyval));
									EmitStore((yyval));                                     
								;}
    break;

  case 61:

    {;}
    break;

  case 62:

    {(yyval) = (yyvsp[(1) - (1)]) ;  ;}
    break;

  case 63:

    {
							(yyval) = CreateTemp(Type_ArrayElement);
							EmitLoadValue((yyvsp[(1) - (4)]));
							EmitLoadValue((yyvsp[(3) - (4)]));
						;}
    break;

  case 64:

    {(yyval) = (yyvsp[(1) - (1)]) ;  ;}
    break;

  case 65:

    {
							(yyval) = CreateTemp(Type_Int);
							EmitLoadValue((yyvsp[(1) - (4)]));
							EmitLoadValue((yyvsp[(3) - (4)]));
							EmitLine("iaload");
							EmitStore((yyval));
						;}
    break;

  case 66:

    {;}
    break;

  case 67:

    {print("prefixexp");;}
    break;

  case 68:

    {print("functioncall");;}
    break;

  case 69:

    {print("functioncall");;}
    break;

  case 70:

    {print("args");;}
    break;

  case 71:

    {print("args");;}
    break;

  case 72:

    {print("args");;}
    break;

  case 73:

    {print("args");;}
    break;

  case 74:

    {print("function");;}
    break;

  case 75:

    {print("funcbody");;}
    break;

  case 76:

    {print("params");;}
    break;

  case 77:

    {print("parlist");;}
    break;

  case 78:

    {print("parlist");;}
    break;

  case 79:

    {print("parlist");;}
    break;

  case 80:

    {print("parlist");;}
    break;

  case 81:

    {
											(yyval) = CreateTemp(Type_Array);
											EmitLoadValue((yyvsp[(2) - (3)]));
											EmitLine("newarray int");
											EmitStore((yyval));
										;}
    break;

  case 82:

    {print("binop");;}
    break;

  case 83:

    {print("binop");;}
    break;

  case 84:

    {print("binop");;}
    break;

  case 85:

    {print("binop");;}
    break;

  case 86:

    {print("binop");;}
    break;

  case 87:

    {print("binop");;}
    break;

  case 88:

    {print("binop");;}
    break;

  case 89:

    {print("binop");;}
    break;

  case 90:

    {print("binop");;}
    break;

  case 91:

    {print("binop"); (yyval) = (yyvsp[(1) - (1)]) ;}
    break;

  case 92:

    {print("binop");;}
    break;

  case 93:

    {;}
    break;

  case 94:

    {print("binop");;}
    break;

  case 95:

    {print("binop");;}
    break;

  case 96:

    {print("binop");;}
    break;

  case 97:

    {print("uniop");;}
    break;

  case 98:

    {print("uniop");;}
    break;

  case 99:

    {print("uniop");;}
    break;

  case 100:

    {(yyval) = (yyvsp[(1) - (1)]);}
    break;

  case 101:

    {(yyval) = (yyvsp[(1) - (1)]);;}
    break;

  case 102:

    { (yyval)=(yyvsp[(1) - (1)]);;}
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

void AddScope()
{
        return CompilerMain::GetSharedCompiler()->AddScope();
}

void AddEntry(std::string name, SymbolType type)
{
	CompilerMain::GetSharedCompiler()->AddEntry(QString::fromStdString(name),type);
}

void yyerror(const char  *)
{
	CompilerMain::GetSharedCompiler()->AddSyntaxError();
}


void EmitLine(std::string str)
{
        return CompilerMain::GetSharedCompiler()->EmitLine(str);
}


YYSTYPE FindVariableIndexInTable(YYSTYPE idName)
{
        return toString(CompilerMain::GetSharedCompiler()->FindVariableIndexInTable(idName));
}

bool IsTemp(YYSTYPE val)
{
        return CompilerMain::GetSharedCompiler()->IsTemp(val);
}

bool IsID(YYSTYPE val)
{
        return ( (val[0]>='a' &&  val[0]<= 'z')
                        || (val[0]>='A' &&  val[0]<= 'Z')
                        || (val[0]=='_') );
}

void RemoveTemp()
{
        CompilerMain::GetSharedCompiler()->RemoveTemp();
}

YYSTYPE CreateTemp(SymbolType type)
{
        return CompilerMain::GetSharedCompiler()->CreateTemp(type);
}


YYSTYPE CreateLabel()
{
        return CompilerMain::GetSharedCompiler()->CreateLabel();
}

YYSTYPE PopLabel()
{
        return CompilerMain::GetSharedCompiler()->PopLabel();
}

void PushLabel(YYSTYPE label)
{
        return CompilerMain::GetSharedCompiler()->PushLabel(label);
}


SyntaxAnalyzer::SyntaxAnalyzer()
{
    
}

void SyntaxAnalyzer::StartParsing()
{
	EmitLine(".class public OutPut");
	EmitLine(".super java/lang/Object");
	EmitLine(".method public static main([Ljava/lang/String;)V");
	EmitLine(".limit stack 250");
	EmitLine(".limit locals 300");

	
        qDebug("Start Syntax Analyzer");
    if(yyparse()== 0)
                qDebug("Success");
    else
		yyerror("");

	EmitLine("   return");
	EmitLine(".end method");

                
}

void emptyPrint(YYSTYPE str)
{
        
}

void ManageBinop(YYSTYPE binop, YYSTYPE firstOP, YYSTYPE secOP)
{
        EmitLoadValue(firstOP);
        EmitLoadValue(secOP);

        if(binop == ">")
                EmitComparison("if_icmpgt");

        else if (binop==">=")
                EmitComparison("if_icmpge");

        else if (binop=="<")
                EmitComparison("if_icmplt");

        else if (binop == "<=")
                EmitComparison("if_icmple");

        else if (binop == "==")
                EmitComparison("if_icmpeq");

        else if (binop == "~=")
                EmitComparison("if_icmpne");

        else if (binop == "+")
                EmitLine("iadd");
        else if (binop == "-")
                EmitLine("isub");
        else if (binop == "/")
                EmitLine("idiv");
        else if (binop == "*")
                EmitLine("imul");
        else if (binop == "^")
                EmitLine("ishl");
        
        



}

void EmitComparison(YYSTYPE comparisonVal)
{
        YYSTYPE trueLabel = CreateLabel();
        YYSTYPE endLabel =  CreateLabel();
        EmitLine(comparisonVal+" "+trueLabel);
        EmitLoadValue(toString(0));
        EmitLoadValue("goto " + endLabel);
        EmitLoadValue(trueLabel + ":");
        EmitLoadValue(toString(1));
        EmitLoadValue(endLabel + ":");
}

void EmitLoadValue(YYSTYPE val)
{
	if(val=="")
		return;
	SymbolType type =GetType(val);
	EmitLine(";load  " + val); 
	if(type == Type_Int)
	{
		EmitLine("iload "+ GETINDEX(val));
	}
	else if( type == Type_Array) 
	{
		EmitLine("aload "+ GETINDEX(val));
	}
    else if (type == Type_None) // const
        EmitLine("ldc "+ val);

	else if( type ==Type_ArrayElement)
		EmitLine("iaload");

	//if(IsTemp(val))	
		//RemoveTemp();

        
}

void EmitStore(YYSTYPE val)
{
	
	if(val=="")
		return;

	SymbolType type = GetType(val);
	EmitLine(";store in " + val); 
	if(type == Type_Int)
		EmitLine("istore " +GETINDEX(val)); 
	else if(type == Type_Array)
		EmitLine("astore " +GETINDEX(val));
	else if(type == Type_ArrayElement)
	{
		EmitLine("iastore ");

	}
		
}

SymbolType GetType(YYSTYPE var)
{
	return CompilerMain::GetSharedCompiler()->GetType(var);
}


void EmitPrint (YYSTYPE val)
{
	
	EmitLine("getstatic java/lang/System/out Ljava/io/PrintStream;");

	if(!IsConstString(val))
		EmitIntToString(val);
	else
		EmitLine(std::string("ldc ") + std::string(val));

	EmitLine("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
}

bool IsConstString(YYSTYPE val)
{
	return val[0]=='\"';
}

void EmitIntToString(YYSTYPE val)
{
	EmitLoadValue(val);
	EmitLine("invokestatic java/lang/Integer/toString(I)Ljava/lang/String;");
}
void fullPrint(YYSTYPE str)
{
        qDebug(str.c_str());
}

void SetTypeByValueType(YYSTYPE val1,YYSTYPE val2)
{

	if(val1=="" || val2=="")
		return;
	SymbolType type1 = GetType(val1);
	SymbolType type2 = GetType(val2);
	
	if(type1 == Type_ArrayElement)
		return;
	if(type2 == Type_Int || IsConstInteger(val2))
		AddEntry(val1,Type_Int);
	else if( type2 == Type_Array)
		AddEntry(val1,Type_Array);
	else if( type2 = Type_ArrayElement)
		AddEntry(val1,Type_Int);
}

bool IsConstInteger (YYSTYPE val)
{
	return (val[0]>='0' && val[0]<='9');
}
