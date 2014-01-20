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
#define LEXERROR "Lex Error: " 
#define SYNERROR "Syntax Error: "
#define SYMANERROR "Symantic ERROR: "


class LexicalAnalyzer;
class SyntaxAnalyzer;
class CompilerView;

#define LEXERROR "lex Error "



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

	void AddSyntaxError();
	
	void AddError(std::string msg,ErrorType type,int line, int column);

	YYSTYPE CreateTemp(SymbolType type);
	YYSTYPE CreateLabel();
	bool IsTemp(YYSTYPE val);
	void RemoveTemp();

	void SetTempType(QString name, SymbolType type);

	bool IsInTable(QString idName);

	void AddScope();

	bool AddEntry(QString name,SymbolType type);

	SymbolEntry* FindSymbolByName(QString name);

	SymbolType GetType(YYSTYPE val);



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

	QVector<Error*> errorList;

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
