%output "../Source/SyntaxAnalyzer.cpp"
%defines "../Source/ParserTokens.h"
%no-lines
%{
	#include "SyntaxAnalyzer.h"
	#define YYSTYPE QString
	int GetNextToken (); 
	int ParserLex();
	#define yylex  GetNextToken
	void yyerror (char const *);
	#define YYTOKENTYPE ETokenType
%}

%token Token_EndOfFile 0
%token Token_Identifier
%token Token_IntNumber
%token Token_FloatNumber
%token Token_String
%token Token_And
%token Token_Break
%token Token_Do
%token Token_Else
%token Token_ElseIf
%token Token_End
%token Token_False
%token Token_For
%token Token_Function
%token Token_If
%token Token_In
%token Token_Local
%token Token_Nil
%token Token_Not
%token Token_Or
%token Token_Repeat
%token Token_Return
%token Token_Then
%token Token_True
%token Token_Until
%token Token_While
%token Token_Plus
%token Token_Minus
%token Token_Asterisk
%token Token_Slash
%token Token_Percent
%token Token_Caret
%token Token_NumberSign
%token Token_Equal
%token Token_NotEqual
%token Token_LesserEqual
%token Token_GreaterEqual
%token Token_Lesser
%token Token_Greater
%token Token_Assign
%token Token_LeftParen
%token Token_RightParen
%token Token_LeftBrace
%token Token_RightBrace
%token Token_LeftBrack
%token Token_RightBrack
%token Token_Semicolon
%token Token_Colon
%token Token_Comma
%token Token_Dot
%token Token_Concat
%token Token_Varag




%%
	chunk: block 
		;

	block : stats
		| stats retstat
		;

	stats : 
		|stat stats
		;

	stat : Token_Semicolon 
		| varlist Token_Assign explist
		| functioncall
		| label
		| Token_Break
		| Token_Do block Token_End
		| Token_Repeat block Token_Until exp
		| IfStat
		| Token_For name Token_Assign forexp Token_Do block Token_End
		| Token_For namelist Token_In explist Token_Do block TokenEnd
		| Token_Function funcname funcbody
		| Token_Local Token_Function name funcbody
		| Token_Local namelist 
		| Token_Local namelist Token_Assign explist
		;

	retstat : Token_Return
		| Token_Return Token_Semicolon
		;

	funcname : names
		| names Token_Colon name
		;

	varlist : var
		| var Token_Comma varlist
		;

	var : name
		| prefixexp Token_LeftBrack exp Token_RightBrak 
		| prefixexp Token_Dot name
		;

	namelist : name
		| name Token_Comma namelist
		;

	explist : exp
		| exp Token_Comma explist
		;

	exp : Token_Nil 
		| Token_False 
		| Token_True 
		| number
		| Token_String
		| Token_Varag
		| functiondef
		| prefixexp
		| tableconstructor
		| exp binop exp
		| unop exp
		;

	prefixexp : var 
		| functioncall
		| Token_LeftParen exp Token_RightParen
		;

	functioncall : prefixexp args
		| prefixexp Token_Colon  name args
		;

	args : Token_LeftParen Token_RightParen
		| Token_LeftParen explist Token_RightParen
		| tableconstructor
		| Token_String
		;

	functiondef : Token_Function funcbody
		;

	funcbody : Token_LeftParen Token_RightParen block Token_End
		| Token_LeftParen parlist Token_RightParen block Token_End
		;

	parlist : namelist 
		| namelist Token_Comma Token_Varag 
		| namelist Token_Varag
		;

	tableconstructor : Token_LeftBrace Token_RightBrace
		| Token_LeftBrace fieldlist Token_RightBrace

	fieldlist : field
		|	field fields
		| field fieldsep
		| field fields fieldsep
		;

	fields : fieldsep field
		| fieldsep field fields
		;

	field : Token_LeftBrack exp Token_RightBrack Token_Assign exp
		| name Token_Assign exp
		| exp

	fieldsep : Token_Comma
		| Token_Semicolon
		;

	binop : Token_Plus 
		| Token_Minus 
		| Token_Asterisk
		| Token_Slash
		| Token_Caret
		| Token_Percent
		| Token_Concat
		| Token_Lesser
		| Token_LesserEqual
		| Token_Greater
		| Token_GreaterEqual
		| Token_Equal
		| Token_NotEqual
		| Token_And
		| Token_Or
		;

	unop : Token_Minus 
		| Token_Not
		| Token_NumberSign
		;

	number : Token_IntNumber
		| Token_FloatNumber
		;

	forexp : exp Token_Comma exp
		|  exp Token_Comma exp Token_Comma exp
		;

	names : name
		| name Token_Dot names
		;
	name : Token_Identifier
		;

	
%%



int GetNextToken()
{
	qDebug("Get Next Token");
	
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