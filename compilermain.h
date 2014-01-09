#ifndef COMPILERMAIN_H
#define COMPILERMAIN_H

#include <QMainWindow>
#include "BaseObject.h"
#include "lexicalanalyzer.h"
#include <QtDebug>
#include "Token.h"
#include "QVector"


class LexicalAnalyzer;

class CompilerMain : public BaseObject
{

public:
    CompilerMain();
    ~CompilerMain();

    void InsertToken(Token* token);

private:
    QVector<Token*>* tokenList;
    LexicalAnalyzer* lexicalAnalyzer;

    void InitialLexicalAnalyzer();
};

#endif // COMPILERMAIN_H
