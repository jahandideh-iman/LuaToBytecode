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
%left Token_And
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
%right Token_Not
%left Token_Or
%token Token_Repeat
%token Token_Return
%token Token_Then
%token Token_True
%token Token_Until
%token Token_While
%left Token_Plus
%left Token_Minus
%left Token_Asterisk
%left Token_Slash
%left Token_Percent
%right Token_Caret
%right Token_NumberSign
%left Token_Equal
%left Token_NotEqual
%left Token_LesserEqual
%left Token_GreaterEqual
%left Token_Lesser
%left Token_Greater
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
%right Token_Concat
%token Token_Varag




%%

	chunk : {qDebug("chunk");} block						
		;

	semi : 							{qDebug("semi");}
		| Token_Semicolon			{qDebug("semi");}
		; 

	block : scope statlist				{qDebug("block");}
		| scope statlist laststat semi	{qDebug("block");}
		;

	unblock : block Token_Until exp		{qDebug("unblock");}
		;

	scope :								{qDebug("scope");}
		| scope statlist binding semi	{qDebug("scope");}
		;

	statlist :							{qDebug("statlist");}
		| statlist stat semi			{qDebug("statlist");}
		;

	stat : Token_Do block Token_End							{qDebug("stat");}
		| Token_While exp Token_Do block Token_End			{qDebug("stat");}
		| repetition Token_Do block Token_End				{qDebug("stat");}
		| Token_Repeat unblock								{qDebug("stat");}
		| Token_If conds Token_End							{qDebug("stat");}
		| Token_Function funcname funcbody					{qDebug("stat");}
		| setlist Token_Assign explist1						{qDebug("stat");}
		| functioncall										{qDebug("stat");}
		;

	repetition : Token_For name Token_Assign explist23		{qDebug("repetition");}
		| Token_For namelist Token_In explist1				{qDebug("repetition");}
		;

	conds : condlist
		| condlist Token_Else block
		;

	condlist : cond
		| condlist Token_ElseIf cond
		;

	cond : exp Token_Then block
		;

	laststat : Token_Break				{qDebug("laststat");}
		| Token_Return					{qDebug("laststat");}
		| Token_Return explist1			{qDebug("laststat");}
		;

	binding : Token_Local namelist							{qDebug("binding");}
		| Token_Local namelist Token_Assign explist1		{qDebug("binding");}
		| Token_Local Token_Function name funcbody			{qDebug("binding");}
		;

	funcname : dottedname
		| dottedname Token_Colon name
		;

	dottedname : name						{qDebug("dottedName");}
		| dottedname Token_Dot name			{qDebug("dottedName");}
		;

	namelist : name							{qDebug("namelist");}
		| namelist Token_Comma name			{qDebug("namelist");}
		;

	explist1 : exp							{qDebug("explist1");}
		| explist1 Token_Comma exp			{qDebug("explist1");}
		;

	explist23 : exp Token_Comma exp					{qDebug("explist23");}
		| exp Token_Comma exp Token_Comma exp		{qDebug("explist23");}
		;


	exp : Token_Nil				{qDebug("exp");} 
		| Token_True			{qDebug("exp");} 
		| Token_False			{qDebug("exp");} 
		| number				{qDebug("exp");} 
		| Token_String			{qDebug("exp");} 
		| Token_Varag			{qDebug("exp");} 
		| function				{qDebug("exp");} 
		| prefixexp				{qDebug("exp");} 
		| tableconstructor		{qDebug("exp");} 
		| exp binop exp			{qDebug("exp");} 
		| uniop exp				{qDebug("exp");} 
		;

	setlist : var						{qDebug("setlist");} 
		| setlist Token_Comma var		{qDebug("setlist");} 
		;

	var : name														{qDebug("var");} 
		| prefixexp Token_LeftBrack exp Token_RightBrack			{qDebug("var");}
		| prefixexp Token_Dot name									{qDebug("var");}
		;

	prefixexp : var										{qDebug("prefixexp");}
		| functioncall									{qDebug("prefixexp");}
		| Token_LeftParen exp Token_RightParen			{qDebug("prefixexp");}
		;

	functioncall : prefixexp args						{qDebug("functioncall");}
		| prefixexp Token_Colon name args				{qDebug("functioncall");}
		;

	args : Token_LeftParen Token_RightParen					{qDebug("args");}
		| Token_LeftParen explist1 Token_RightParen			{qDebug("args");}
		| tableconstructor									{qDebug("args");}	
		| Token_String										{qDebug("args");}
		;

	function : Token_Function funcbody						{qDebug("function");}
		;

	funcbody : params block Token_End						{qDebug("funcbody");}
		;

	params : Token_LeftParen parlist Token_RightParen		{qDebug("params");}
		;

	parlist :									{qDebug("parlist");}		
		| namelist								{qDebug("parlist");}
		| Token_Varag							{qDebug("parlist");}
		| namelist Token_Comma Token_Varag		{qDebug("parlist");}
		;

	tableconstructor : Token_LeftBrace Token_RightBrace				{qDebug("tableconstructor");}		
		| Token_LeftBrace fieldlist Token_RightBrace				{qDebug("tableconstructor");}
		| Token_LeftBrace fieldlist fieldsep Token_RightBrace		{qDebug("tableconstructor");}
		;

	fieldlist : field						{qDebug("fieldlist");}
		| fieldlist fieldsep field			{qDebug("fieldlist");}
		;

	fieldsep : Token_Comma				{qDebug("fieldsep");}
		| Token_Semicolon				{qDebug("fieldsep");}
		;

	field : exp															{qDebug("field");}
		| name Token_Assign exp											{qDebug("field");}
		| Token_LeftBrack exp Token_RightBrack Token_Assign exp			{qDebug("field");}
		;

	binop : Token_Plus				{qDebug("binop");}
		| Token_Minus				{qDebug("binop");}
		| Token_Asterisk			{qDebug("binop");}
		| Token_Slash				{qDebug("binop");}
		| Token_Caret				{qDebug("binop");}
		| Token_Percent				{qDebug("binop");}
		| Token_Concat				{qDebug("binop");}
		| Token_Lesser				{qDebug("binop");}
		| Token_LesserEqual			{qDebug("binop");}
		| Token_Greater				{qDebug("binop");}
		| Token_GreaterEqual		{qDebug("binop");}
		| Token_Equal				{qDebug("binop");}
		| Token_NotEqual			{qDebug("binop");}
		| Token_And					{qDebug("binop");}
		| Token_Or					{qDebug("binop");}
		;

	uniop : Token_Minus				{qDebug("uniop");}
		| Token_Not					{qDebug("uniop");}
		| Token_NumberSign			{qDebug("uniop");}
		;

	number : Token_IntNumber		{qDebug("number");}
		| Token_FloatNumber			{qDebug("number");}
		;

	name : Token_Identifier			{qDebug("name");}
		;




	
%%



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