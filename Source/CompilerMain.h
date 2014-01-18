#ifndef COMPILERMAIN_H
#define COMPILERMAIN_H

#include <QMainWindow>
#include "BaseObject.h"
#include "LexicalAnalyzer.h"
#include "SyntaxanAlyzer.h"
#include "ParserTokens.h"
#include <QtDebug>
#include "Token.h"
#include "QVector"
#include "SymbolTable.h"
#include "qfile.h"
#include "qtextstream.h"




class LexicalAnalyzer;
class SyntaxAnalyzer;

class CompilerMain : public BaseObject
{

public:
    CompilerMain();
    ~CompilerMain();

	
    void InsertToken(Token* token);
    int GetNextToken( );

    static CompilerMain* GetSharedCompiler();

	void EmitLine(std::string line);

	void AddScope();

	void AddEntry(QString name,SymbolType type);

	int FindVariableIndexInTable(YYSTYPE idName);
	

private:
    QVector<Token*>* tokenList;
    LexicalAnalyzer* lexicalAnalyzer;
    SyntaxAnalyzer* syntaxAnalyzer;

	int nextIDIndex;
	QFile * output;
	QTextStream * outStream;

    void InitialLexicalAnalyzer();
    void InitialSyntaxAnalyzer();

	static void SetSharedCompiler(CompilerMain* compiler);


    static CompilerMain* sharedCompiler;

    int nextTokenIndex;

	SymbolTable* currentScope;



};

#endif // COMPILERMAIN_H
