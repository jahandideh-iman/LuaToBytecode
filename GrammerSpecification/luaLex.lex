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
	
	#define printf qDebug
	void InsertToken(yytokentype type, string value, int numberLine, int columnLine)
	{
		LexicalAnalyzer::InsertToken(type,value,numberLine,columnLine);
	}

	int LineNumber = 1, ColumnNumber = 0;
%}

DIGIT    [0-9]
ID       [_a-zA-Z][_a-zA-Z0-9]*

ws 		 [ \t\n]

string        \"([^'\n]|\'\')+\"

comment		"--"(.*)


%%

{comment}\n					LineNumber++;/* eat up one-line comments */
							

"and"						InsertToken(Token_And, yytext, LineNumber, ColumnNumber);

"break"						InsertToken(Token_Break, yytext, LineNumber, ColumnNumber);

"do"						InsertToken(Token_Do, yytext, LineNumber, ColumnNumber);

"else"						InsertToken(Token_Else, yytext, LineNumber, ColumnNumber);

"elseif"					InsertToken(Token_ElseIf, yytext, LineNumber, ColumnNumber);

"end"						InsertToken(Token_End, yytext, LineNumber, ColumnNumber);

"false"						InsertToken(Token_False, yytext, LineNumber, ColumnNumber);

"for"						InsertToken(Token_For, yytext, LineNumber, ColumnNumber);

"function"					InsertToken(Token_Function, yytext, LineNumber, ColumnNumber);

"if"						InsertToken(Token_If, yytext, LineNumber, ColumnNumber);

"in"						InsertToken(Token_In, yytext, LineNumber, ColumnNumber);

"local"						InsertToken(Token_Local, yytext, LineNumber, ColumnNumber);

"nil"						InsertToken(Token_Nil, yytext, LineNumber, ColumnNumber);

"not"						InsertToken(Token_Not, yytext, LineNumber, ColumnNumber);

"or"						InsertToken(Token_Or, yytext, LineNumber, ColumnNumber);

"repeat"					InsertToken(Token_Repeat, yytext, LineNumber, ColumnNumber);

"return"					InsertToken(Token_Return, yytext, LineNumber, ColumnNumber);

"then"						InsertToken(Token_Then, yytext, LineNumber, ColumnNumber);

"true"						InsertToken(Token_True, yytext, LineNumber, ColumnNumber);

"until"						InsertToken(Token_Until, yytext, LineNumber, ColumnNumber);

"while"						InsertToken(Token_While, yytext, LineNumber, ColumnNumber);

"+"							InsertToken(Token_Plus, yytext, LineNumber, ColumnNumber);

"-"							InsertToken(Token_Minus, yytext, LineNumber, ColumnNumber);

"*"							InsertToken(Token_Asterisk, yytext, LineNumber, ColumnNumber);

"/"							InsertToken(Token_Slash, yytext, LineNumber, ColumnNumber);

"%"							InsertToken(Token_Percent, yytext, LineNumber, ColumnNumber);

"^"							InsertToken(Token_Caret, yytext, LineNumber, ColumnNumber);

"#"							InsertToken(Token_NumberSign, yytext, LineNumber, ColumnNumber);

"=="						InsertToken(Token_Equal, yytext, LineNumber, ColumnNumber);

"~="						InsertToken(Token_NotEqual, yytext, LineNumber, ColumnNumber);

"<="						InsertToken(Token_LesserEqual, yytext, LineNumber, ColumnNumber);

">="						InsertToken(Token_GreaterEqual, yytext, LineNumber, ColumnNumber);

"<"							InsertToken(Token_Lesser, yytext, LineNumber, ColumnNumber);

">"							InsertToken(Token_Greater, yytext, LineNumber, ColumnNumber);

"="							InsertToken(Token_Assign, yytext, LineNumber, ColumnNumber);

"("							InsertToken(Token_LeftParen, yytext, LineNumber, ColumnNumber);

")"							InsertToken(Token_RightParen, yytext, LineNumber, ColumnNumber);

"{"							InsertToken(Token_LeftBrace, yytext, LineNumber, ColumnNumber);

"}"							InsertToken(Token_RightBrace, yytext, LineNumber, ColumnNumber);

"["							InsertToken(Token_LeftBrack, yytext, LineNumber, ColumnNumber);

"]"							InsertToken(Token_RightBrack, yytext, LineNumber, ColumnNumber);

";"							InsertToken(Token_Semicolon, yytext, LineNumber, ColumnNumber);

":"							InsertToken(Token_Colon, yytext, LineNumber, ColumnNumber);

","							InsertToken(Token_Comma, yytext, LineNumber, ColumnNumber);

"."							InsertToken(Token_Dot, yytext, LineNumber, ColumnNumber);

".."						InsertToken(Token_Concat, yytext, LineNumber, ColumnNumber);

"..."						InsertToken(Token_Varag, yytext, LineNumber, ColumnNumber);

{DIGIT}+    				InsertToken(Token_IntNumber, yytext, LineNumber, ColumnNumber);

{DIGIT}+"."{DIGIT}*        	InsertToken(Token_FloatNumber, yytext, LineNumber, ColumnNumber);

{ID}        				InsertToken(Token_Identifier,yytext, LineNumber, ColumnNumber);

{string} 					InsertToken(Token_String, yytext, LineNumber, ColumnNumber);

{ws}         				{if(*yytext == '\n') LineNumber++;}






.           				 printf( "!!!!!!!!! Unrecognized character: %s\n", yytext );


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
