#ifndef COMPILERMAIN_H
#define COMPILERMAIN_H

#include <QMainWindow>
#include "BaseObject.h"
#include "LexicalAnalyzer.h"
#include "SyntaxanAlyzer.h"
#include <QtDebug>
#include "Token.h"
#include "QVector"



class LexicalAnalyzer;
class SyntaxAnalyzer;

class CompilerMain : public BaseObject
{

public:
    CompilerMain();
    ~CompilerMain();

	
    void InsertToken(Token* token);
    int GetNextToken();

    static CompilerMain* GetSharedCompiler();
	

private:
    QVector<Token*>* tokenList;
    LexicalAnalyzer* lexicalAnalyzer;
    SyntaxAnalyzer* syntaxAnalyzer;

    void InitialLexicalAnalyzer();
    void InitialSyntaxAnalyzer();

	static void SetSharedCompiler(CompilerMain* compiler);


    static CompilerMain* sharedCompiler;

    int nextTokenIndex;



};

#endif // COMPILERMAIN_H
