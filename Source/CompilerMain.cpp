#include "compilermain.h"

CompilerMain* CompilerMain::sharedCompiler;

CompilerMain::CompilerMain()
{
	SetSharedCompiler(this);
    nextTokenIndex= 0;
    qDebug ("Compiler Main");
    tokenList = new QVector<Token*>;
    InitialLexicalAnalyzer();
    InitialSyntaxAnalyzer();
    
	

}

CompilerMain::~CompilerMain()
{

}

void CompilerMain::InsertToken(Token *token)
{
    qDebug()<<token->GetValue();

    //qDebug()<<token->GetType();

    tokenList->push_back(token);
}

int CompilerMain::GetNextToken()
{
	qDebug()<<("Get Next Token");
	Token* token = tokenList->at(nextTokenIndex);
    nextTokenIndex++;
    return token->GetType();
}


void CompilerMain::SetSharedCompiler(CompilerMain* compiler)
{
	sharedCompiler = compiler;
}

CompilerMain *CompilerMain::GetSharedCompiler()
{
    return sharedCompiler;
}

void CompilerMain::InitialLexicalAnalyzer()
{
    LexicalAnalyzer::SetTokenInsertHandler(this,InsertTokenSelector(CompilerMain::InsertToken));
    lexicalAnalyzer = new LexicalAnalyzer();
    //lexicalAnalyzer->SetTokenInsertHandler(this,InsertTokenSelector(CompilerMain::InsertToken));
    //lexicalAnalyzer->StartLexing("SampleText.txt");
    lexicalAnalyzer->StartLexing("Resources/SampleText_SimpleInt.txt");


}

void CompilerMain::InitialSyntaxAnalyzer()
{
    syntaxAnalyzer = new SyntaxAnalyzer();
    syntaxAnalyzer->Analyze();

}

