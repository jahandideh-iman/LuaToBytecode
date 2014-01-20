
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;


