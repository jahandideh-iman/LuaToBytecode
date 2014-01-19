/* scanner for a toy Pascal-like language */
%option noyywrap
%option warn nodefault
%option never-interactive
%option   outfile="../Source/LexicalAnalyzer.cpp"



%{
	/* need this for the call to atof() below */
	#include "LexicalAnalyzer.h"
	BaseObject* LexicalAnalyzer::recieverObj;
    InsertTokenHandler LexicalAnalyzer::insertTokenHandler;
    bool LexicalAnalyzer::bHasInstance;

	int GetCharArrayLength(char* carray);
	void AddError(std::string msg,ErrorType type,int line, int column);
	
	#define printf qDebug
	void InsertToken(yytokentype type, string value, int numberLine, int columnLine)
	{
		LexicalAnalyzer::InsertToken(type,value,numberLine,columnLine);
	}

	int LineNumber = 1, ColumnNumber = 1;
%}

DIGIT    [0-9]
ID       [_a-zA-Z][_a-zA-Z0-9]*

ws 		 [ \t\n]

string        \"([^'\n]|\'\')+\"

comment		"--"(.*)


%%

{comment}\n					LineNumber++; ColumnNumber=1;/* eat up one-line comments */
							

"and"						InsertToken(Token_And, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"break"						InsertToken(Token_Break, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"do"						InsertToken(Token_Do, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"else"						InsertToken(Token_Else, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"elseif"					InsertToken(Token_ElseIf, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"end"						InsertToken(Token_End, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"false"						InsertToken(Token_False, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"for"						InsertToken(Token_For, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"function"					InsertToken(Token_Function, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"if"						InsertToken(Token_If, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"in"						InsertToken(Token_In, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"local"						InsertToken(Token_Local, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"nil"						InsertToken(Token_Nil, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"not"						InsertToken(Token_Not, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"or"						InsertToken(Token_Or, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"repeat"					InsertToken(Token_Repeat, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"return"					InsertToken(Token_Return, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"then"						InsertToken(Token_Then, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"true"						InsertToken(Token_True, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"until"						InsertToken(Token_Until, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"while"						InsertToken(Token_While, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"+"							InsertToken(Token_Plus, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"-"							InsertToken(Token_Minus, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"*"							InsertToken(Token_Asterisk, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"/"							InsertToken(Token_Slash, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"%"							InsertToken(Token_Percent, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"^"							InsertToken(Token_Caret, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"#"							InsertToken(Token_NumberSign, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"=="						InsertToken(Token_Equal, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"~="						InsertToken(Token_NotEqual, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"<="						InsertToken(Token_LesserEqual, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

">="						InsertToken(Token_GreaterEqual, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"<"							InsertToken(Token_Lesser, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

">"							InsertToken(Token_Greater, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"="							InsertToken(Token_Assign, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"("							InsertToken(Token_LeftParen, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

")"							InsertToken(Token_RightParen, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"{"							InsertToken(Token_LeftBrace, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"}"							InsertToken(Token_RightBrace, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"["							InsertToken(Token_LeftBrack, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"]"							InsertToken(Token_RightBrack, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

";"							InsertToken(Token_Semicolon, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

":"							InsertToken(Token_Colon, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

","							InsertToken(Token_Comma, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"."							InsertToken(Token_Dot, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

".."						InsertToken(Token_Concat, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

"..."						InsertToken(Token_Varag, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

{DIGIT}+    				InsertToken(Token_IntNumber, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

{DIGIT}+"."{DIGIT}*        	InsertToken(Token_FloatNumber, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

{ID}        				InsertToken(Token_Identifier,yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

{string} 					InsertToken(Token_String, yytext, LineNumber, ColumnNumber);ColumnNumber+= GetCharArrayLength(yytext);

{ws}         				{if(*yytext == '\n') {LineNumber++; ColumnNumber = 1 ;} else ColumnNumber++;}






.           				 printf( "!!!!!!!!! Unrecognized character: %s\n", yytext ); AddError(LEXERROR,Error_Lexical,LineNumber,ColumnNumber);ColumnNumber++;


%%


LexicalAnalyzer::LexicalAnalyzer()
{
	SetHasInstnace();
}

void LexicalAnalyzer::StartLexing(QString fileName)
{
    yyin = fopen(fileName.toStdString().c_str(), "r" );
    qDebug("file is open");

    yylex();
}

void LexicalAnalyzer::SetTokenInsertHandler(BaseObject* main,InsertTokenHandler handler)
{
    insertTokenHandler =handler;
    recieverObj = main;
}

void LexicalAnalyzer::InsertToken(yytokentype type, string value,int lineNum , int columnNum)
{
    if(HasInstance())
    {
		//qDebug("InsertToken");
        CALL_MEMBER_FN(recieverObj,insertTokenHandler)(CreateToken(type,value,lineNum, columnNum) );
    }
}

Token* LexicalAnalyzer::CreateToken(yytokentype type, string value, int line, int column)
{
	//qDebug("CreateToken");
    return new Token(type,QString::fromStdString(value),line,column);
}

bool LexicalAnalyzer::HasInstance()
{
    return bHasInstance;
}

void LexicalAnalyzer::SetHasInstnace()
{
    bHasInstance = true;
}

int GetCharArrayLength(char* carray)
{
	int i = 0;
	while(carray[i]!='\0')
		i++;
	return i;
}

void AddError(std::string msg,ErrorType type,int line, int column)
{
	CompilerMain::GetSharedCompiler()->AddError(msg, type, line,  column);
}