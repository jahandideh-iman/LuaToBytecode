#include "compilermain.h"
CompilerMain::CompilerMain()
{
   qDebug ("Compiler Main");
   tokenList = new QVector<Token*>;
   InitialLexicalAnalyzer();

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

void CompilerMain::InitialLexicalAnalyzer()
{
    LexicalAnalyzer::SetTokenInsertHandler(this,InsertTokenSelector(CompilerMain::InsertToken));
    lexicalAnalyzer = new LexicalAnalyzer();
    //lexicalAnalyzer->SetTokenInsertHandler(this,InsertTokenSelector(CompilerMain::InsertToken));
    //lexicalAnalyzer->StartLexing("SampleText.txt");

}

