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
#include "qstack.h"
#include "TextEditor.h"

#include "CompilerView.h"

#define TEMPNAME "$TEMP"
#define LABELNAME "label"


class LexicalAnalyzer;
class SyntaxAnalyzer;
class CompilerView;

#define LEXERROR "lex Error "

enum ErrorType
{
	Error_Lexical,Error_Syntax,
};

struct Error
{
	QString msg;
	int lineNumber;
	int columnNumber;
	ErrorType type;
};

class CompilerMain : public BaseObject
{

public:
    CompilerMain();
    ~CompilerMain();



    CompilerView* mainwindow;
	
    void InsertToken(Token* token);
    int GetNextToken( );

    static CompilerMain* GetSharedCompiler();

	void EmitLine(std::string line);
	
	void AddError();

	YYSTYPE CreateTemp();
	YYSTYPE CreateLabel();
	bool IsTemp(YYSTYPE val);
	void RemoveTemp();

	bool IsInTable(QString idName);

	void AddScope();

	void AddEntry(QString name,SymbolType type);



	int FindVariableIndexInTable(YYSTYPE idName);

	void PushLabel(YYSTYPE label);
	YYSTYPE PopLabel();

    void SetEditor(TextEditor* _editor);
    void Compile();
	

private:
    TextEditor* editor;

    QVector<Token*>* tokenList;
    LexicalAnalyzer* lexicalAnalyzer;
    SyntaxAnalyzer* syntaxAnalyzer;

	QVector<QString> errorList;

	QStack<YYSTYPE> labelStack;

	int nextIDIndex;
	int nextTemp;
	int nextLabel;
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
