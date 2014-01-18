%output "../Source/SyntaxAnalyzer.cpp"
%defines "../Source/ParserTokens.h"
%no-lines

%code requires
{
#include <string>
#define YYSTYPE std::string
}

%{
#include <string>
#include "SyntaxAnalyzer.h"
int GetNextToken (); 
int ParserLex();
#define yylex  GetNextToken
void yyerror ( const char *);
void emptyPrint(YYSTYPE);
void fullPrint(YYSTYPE);
void AddScope();
void EmitLine(std::string str);
bool IsTemp(YYSTYPE val);
bool IsID(YYSTYPE val);
void RemoveTemp();
YYSTYPE CreateTemp();
YYSTYPE CreateLabel();

YYSTYPE PopLabel();
void PushLabel(YYSTYPE label);

void ManageBinop(YYSTYPE binop, YYSTYPE firstOP, YYSTYPE secOP);
YYSTYPE GetStorage(YYSTYPE idName);
YYSTYPE FindVariableIndexInTable(YYSTYPE idName);
void AddEntry(YYSTYPE name, SymbolType type);
#define print emptyPrint
#define print1 fullPrint
#define GETINDEX FindVariableIndexInTable
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

	chunk :  block						{$$= $1 ; print1($$);}
		;

	semi : 							{print1("semi Y"); }
		| Token_Semicolon			{print("semi"); }
		; 

	block :  scope statlist				{$$ = $1 + $2 ;print1("block1 " + $2 );  }
		| scope statlist laststat semi	{$$ = $1 + $2 + $3 + $4 ;print1("block2" + $$);  }
		;

	unblock : block Token_Until exp		{print("unblock"); }
		;

	scope :								{print1("scope Y");}
		| scope statlist binding semi	{print1("scope N");   }
		;

	statlist :							{ $$ = $0 ;print1("statlist Y" + $$); }
		|  statlist stat semi 			{$$ = $1 + $2  ;print1("statlist N " + $$); }
		;

	stat : Token_Do block Token_End							{print1("stat"); }
		| Token_While exp Token_Do block Token_End			{print1("stat");}
		| repetition Token_Do block Token_End				{print("stat");}
		| Token_Repeat unblock								{print("stat");}
		|	Token_If 
					{	
						PushLabel(CreateLabel());
					} 
			conds Token_End 
					
		| Token_Function funcname funcbody					{print("stat");}
		| setlist Token_Assign explist1						{	if(IsTemp($3))
																{
																	EmitLine("iload "+ GETINDEX ($3) ); 
																	RemoveTemp();
																}
																else
																	EmitLine("ipush " + $3);
																EmitLine("istore " +GETINDEX($1));	
																}
		| functioncall										{print("stat");}
		;

	repetition : Token_For name Token_Assign explist23		{print1("numeric");}
		| Token_For namelist Token_In explist1				{print("repetition");}
		;

	conds : condlist {EmitLine(PopLabel()+":");}
		| condlist Token_Else {EmitLine(PopLabel()+":");} block
		;

	condlist : cond 
		| condlist Token_ElseIf {EmitLine(PopLabel() +":");PushLabel(CreateLabel());} cond
		;

	cond :	exp	{
					if(IsTemp($1))
					{
						
						EmitLine("iload " + GETINDEX($1));
						RemoveTemp(); 
					}
					else
						EmitLine("ipush" + $1);
					YYSTYPE label = PopLabel();
					PushLabel(label);
					EmitLine("ifle " + label);
				}
			Token_Then block		{$$ = $1;}
		;

	laststat : Token_Break				{print("laststat");}
		| Token_Return					{print("laststat");}
		| Token_Return explist1			{print("laststat");}
		;

	binding : Token_Local namelist							{print("binding");}
		| Token_Local namelist Token_Assign explist1		{print("binding");}
		| Token_Local Token_Function name funcbody			{print("binding");}
		;

	funcname : dottedname
		| dottedname Token_Colon name
		;

	dottedname : name						{print("dottedName");}
		| dottedname Token_Dot name			{print("dottedName");}
		;

	namelist : name							{print("namelist");}
		| namelist Token_Comma name			{print("namelist");}
		;

	explist1 : exp							{$$ = $1 ;print1("explist " + $$);}
		| explist1 Token_Comma exp			{print("explist1");}
		;

	explist23 : exp Token_Comma exp					{print("explist23");}
		| exp Token_Comma exp Token_Comma exp		{print("explist23");}
		;


	exp : Token_Nil				{print("exp");} 
		| Token_True			{print("exp");} 
		| Token_False			{print("exp");} 
		| number				{$$ = $1 ; print1("exp " + $$);} 
		| Token_String			{print("exp");} 
		| Token_Varag			{print("exp");} 
		| function				{print("exp");} 
		| prefixexp				{print("exp");} 
		| tableconstructor		{print("exp");} 
		| exp binop exp			{
									ManageBinop($2,$1,$3);
									$$ = CreateTemp();
									EmitLine("istore " + GETINDEX($$));

								} 
		| uniop exp				{print("exp");} 
		;

	setlist : var	{$$ = $1 ; AddEntry($$,Type_None); } 
		| setlist Token_Comma var		{print("setlist");} 
		;

	var : name														{print("name : "); $$ = $1;} 
		| prefixexp Token_LeftBrack exp Token_RightBrack			{print("var");}
		| prefixexp Token_Dot name									{print("var");}
		;

	prefixexp : var										{print("prefixexp");}
		| functioncall									{print("prefixexp");}
		| Token_LeftParen exp Token_RightParen			{print("prefixexp");}
		;

	functioncall : prefixexp args						{print("functioncall");}
		| prefixexp Token_Colon name args				{print("functioncall");}
		;

	args : Token_LeftParen Token_RightParen					{print("args");}
		| Token_LeftParen explist1 Token_RightParen			{print("args");}
		| tableconstructor									{print("args");}	
		| Token_String										{print("args");}
		;

	function : Token_Function funcbody						{print("function");}
		;

	funcbody : params block Token_End						{print("funcbody");}
		;

	params : Token_LeftParen parlist Token_RightParen		{print("params");}
		;

	parlist :									{print("parlist");}		
		| namelist								{print("parlist");}
		| Token_Varag							{print("parlist");}
		| namelist Token_Comma Token_Varag		{print("parlist");}
		;

	tableconstructor : Token_LeftBrace Token_RightBrace				{print("tableconstructor");}		
		| Token_LeftBrace fieldlist Token_RightBrace				{print("tableconstructor");}
		| Token_LeftBrace fieldlist fieldsep Token_RightBrace		{print("tableconstructor");}
		;

	fieldlist : field						{print("fieldlist");}
		| fieldlist fieldsep field			{print("fieldlist");}
		;

	fieldsep : Token_Comma				{print("fieldsep");}
		| Token_Semicolon				{print("fieldsep");}
		;

	field : exp															{print("field");}
		| name Token_Assign exp											{print("field");}
		| Token_LeftBrack exp Token_RightBrack Token_Assign exp			{print("field");}
		;

	binop : Token_Plus				{print("binop");}
		| Token_Minus				{print("binop");}
		| Token_Asterisk			{print("binop");}
		| Token_Slash				{print("binop");}
		| Token_Caret				{print("binop");}
		| Token_Percent				{print("binop");}
		| Token_Concat				{print("binop");}
		| Token_Lesser				{print("binop");}
		| Token_LesserEqual			{print("binop");}
		| Token_Greater				{print("binop"); $$ = $1 }
		| Token_GreaterEqual		{print("binop");}
		| Token_Equal				{print("binop");}
		| Token_NotEqual			{print("binop");}
		| Token_And					{print("binop");}
		| Token_Or					{print("binop");}
		;

	uniop : Token_Minus				{print("uniop");}
		| Token_Not					{print("uniop");}
		| Token_NumberSign			{print("uniop");}
		;

	number : Token_IntNumber		{$$ = $1}
		| Token_FloatNumber			{$$ = $1;}
		;

	name : Token_Identifier			{ $$=$1;}
		;




	
%%



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
	return CompilerMain::GetSharedCompiler()->AddEntry(QString::fromStdString(name),type);
}

void yyerror(const char  *)
{
}


void EmitLine(std::string str)
{
	return CompilerMain::GetSharedCompiler()->EmitLine(str);
}
YYSTYPE GetStorage(YYSTYPE idName)
{
	YYSTYPE idIndex = FindVariableIndexInTable(idName);
	return "istore "+idIndex;
}

YYSTYPE FindVariableIndexInTable(YYSTYPE idName)
{
	return std::to_string(CompilerMain::GetSharedCompiler()->FindVariableIndexInTable(idName));
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

YYSTYPE CreateTemp()
{
	return CompilerMain::GetSharedCompiler()->CreateTemp();
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

void SyntaxAnalyzer::Analyze()
{
	qDebug("Start Syntax Analyzer");
    if(yyparse()== 0)
		qDebug("Success");
	else
		qDebug("WTFFFFFFFFF");
}

void emptyPrint(YYSTYPE str)
{
	
}

void ManageBinop(YYSTYPE binop, YYSTYPE firstOP, YYSTYPE secOP)
{
	if(binop == ">")
	{
		if(IsTemp(firstOP))
		{
			EmitLine("iload " + GETINDEX(firstOP));
			RemoveTemp();			
		}
		else
		{
			if(IsID(firstOP))
				EmitLine("iload " + GETINDEX(firstOP));
			else
				EmitLine("ldc " + firstOP);
		}
		if(IsTemp(secOP))
		{
			EmitLine("iload " + GETINDEX(secOP));
			RemoveTemp();
		}
		else
		{
			if(IsID(secOP))
				EmitLine("iload " + GETINDEX(secOP));
			else
				EmitLine("ldc " + secOP);
		}
		EmitLine( "isub ");
		 

		

	}
}

void fullPrint(YYSTYPE str)
{
	qDebug(str.c_str());
}

