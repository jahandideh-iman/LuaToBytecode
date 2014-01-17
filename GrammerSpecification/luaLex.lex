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
	void InsertToken(yytokentype type, string value)
	{
		LexicalAnalyzer::InsertToken(type,value);
	}
%}

DIGIT    [0-9]
ID       [_a-zA-Z][_a-zA-Z0-9]*

ws 		 [ \t\n]

string        \"([^'\n]|\'\')+\"

%%

"--"(.*)\n					/* eat up one-line comments */


"and"						InsertToken(Token_And, yytext);

"break"						InsertToken(Token_Break, yytext);

"do"						InsertToken(Token_Do, yytext);

"else"						InsertToken(Token_Else, yytext);

"elseif"					InsertToken(Token_ElseIf, yytext);

"end"						InsertToken(Token_End, yytext);

"false"						InsertToken(Token_False, yytext);

"for"						InsertToken(Token_For, yytext);

"function"					InsertToken(Token_Function, yytext);

"if"						InsertToken(Token_If, yytext);

"in"						InsertToken(Token_In, yytext);

"local"						InsertToken(Token_Local, yytext);

"nil"						InsertToken(Token_Nil, yytext);

"not"						InsertToken(Token_Not, yytext);

"or"						InsertToken(Token_Or, yytext);

"repeat"					InsertToken(Token_Repeat, yytext);

"return"					InsertToken(Token_Return, yytext);

"then"						InsertToken(Token_Then, yytext);

"true"						InsertToken(Token_True, yytext);

"until"						InsertToken(Token_Until, yytext);

"while"						InsertToken(Token_While, yytext);

"+"							InsertToken(Token_Plus, yytext);

"-"						InsertToken(Token_Minus, yytext);

"*"							InsertToken(Token_Asterisk, yytext);

"/"							InsertToken(Token_Slash, yytext);

"%"							InsertToken(Token_Percent, yytext);

"^"							InsertToken(Token_Caret, yytext);

"#"							InsertToken(Token_NumberSign, yytext);

"=="						InsertToken(Token_Equal, yytext);

"~="						InsertToken(Token_NotEqual, yytext);

"<="						InsertToken(Token_LesserEqual, yytext);

">="						InsertToken(Token_GreaterEqual, yytext);

"<"							InsertToken(Token_Lesser, yytext);

">"							InsertToken(Token_Greater, yytext);

"="							InsertToken(Token_Assign, yytext);

"("							InsertToken(Token_LeftParen, yytext);

")"							InsertToken(Token_RightParen, yytext);

"{"							InsertToken(Token_LeftBrace, yytext);

"}"							InsertToken(Token_RightBrace, yytext);

"["							InsertToken(Token_LeftBrack, yytext);

"]"							InsertToken(Token_RightBrack, yytext);

";"							InsertToken(Token_Semicolon, yytext);

":"							InsertToken(Token_Colon, yytext);

","							InsertToken(Token_Comma, yytext);

"."							InsertToken(Token_Dot, yytext);

".."						InsertToken(Token_Concat, yytext);

"..."						InsertToken(Token_Varag, yytext);

{DIGIT}+    				InsertToken(Token_IntNumber, yytext);

{DIGIT}+"."{DIGIT}*        	InsertToken(Token_FloatNumber, yytext);

{ID}        				InsertToken(Token_Identifier,yytext);

{string} 					InsertToken(Token_String, yytext);

{ws}+          				/* eat up whitespace */






.           				printf( "!!!!!!!!! Unrecognized character: %s\n", yytext );


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

void LexicalAnalyzer::InsertToken(yytokentype type, string value)
{
    if(HasInstance())
    {
		//qDebug("InsertToken");
        CALL_MEMBER_FN(recieverObj,insertTokenHandler)(CreateToken(type,value) );
    }
}

Token* LexicalAnalyzer::CreateToken(yytokentype type, string value)
{
	//qDebug("CreateToken");
    return new Token(type,QString::fromStdString(value));
}

bool LexicalAnalyzer::HasInstance()
{
    return bHasInstance;
}

void LexicalAnalyzer::SetHasInstnace()
{
    bHasInstance = true;
}
