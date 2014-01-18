#ifndef SYNTAXANALYZER_H
#define SYNTAXANALYZER_H

#include "ParserTokens.h"
#include "QDebug"
#include "CompilerMain.h"
#include <string>
#include "SymbolTable.h"


class CompilerMain;
class SyntaxAnalyzer
{
public:
    SyntaxAnalyzer();
    void Analyze();
};

#endif // SYNTAXANALYZER_H
