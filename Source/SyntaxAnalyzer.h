#ifndef SYNTAXANALYZER_H
#define SYNTAXANALYZER_H

#include "Token.h"
#include "QDebug"
#include "CompilerMain.h"

class CompilerMain;
class SyntaxAnalyzer
{
public:
    SyntaxAnalyzer();
    void Analyze();
};

#endif // SYNTAXANALYZER_H
