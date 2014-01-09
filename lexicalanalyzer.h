#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <QFile>
#include <string>
#include "Token.h"
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

    static void InsertToken(ETokenType type, string value);
    static Token* CreateToken(ETokenType type, string value);


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
