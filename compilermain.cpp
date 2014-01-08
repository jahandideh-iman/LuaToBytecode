#include "compilermain.h"
CompilerMain::CompilerMain()
{
   qDebug ("Compiler Main");
   lexicalAnalyzer = new LexicalAnalyzer();
   //lexicalAnalyzer->StartLexing();
}

CompilerMain::~CompilerMain()
{

}

