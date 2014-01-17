#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <qfile.h>
#include <string>
#include "Token.h"
#include "ParserTokens.h"
#include "BaseObject.h"


using namespace std;

class BaseObject;

typedef void (BaseObject::*InsertTokenHandler)(Token*);

#define InsertTokenSelector(_SELECTOR) (InsertTokenHandler)(&_SELECTOR)


#define CALL_MEMBER_FN(object,ptrToMember)  ((object)->*(ptrToMember))

class LexicalAnalyzer
{
public:
    LexicalAnalyzer();
    //void StartLexingWithFile(QFile* file);
    void StartLexing(QString fileName);

    static void SetTokenInsertHandler(BaseObject *main, InsertTokenHandler handler);

    static void InsertToken(yytokentype type, string value);
    static Token* CreateToken(yytokentype type, string value);


private:
    static BaseObject* recieverObj;
    static InsertTokenHandler insertTokenHandler;
    static bool bHasInstance;

    static bool HasInstance();

    void SetHasInstnace();
    QFile* sourceFile;
    QChar currentChar;



};

#endif // LEXICALANALYZER_H