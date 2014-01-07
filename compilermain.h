#ifndef COMPILERMAIN_H
#define COMPILERMAIN_H

#include <QMainWindow>
#include "lexicalanalyzer.h"
#include <QtDebug>



class CompilerMain
{

public:
    CompilerMain();
    ~CompilerMain();

private:
    LexicalAnalyzer* lexicalAnalyzer;
};

#endif // COMPILERMAIN_H
