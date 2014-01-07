#ifndef LEXICALANALYZER_H
#define LEXICALANALYZER_H

#include <QFile>

enum ELexState
{
    LexState_Initial, LexState_Identifier , LexState_Number
};

class LexicalAnalyzer
{
public:
    LexicalAnalyzer();

    void StartLexingWithFile(QFile* file);
    void StartLexing();


private:
    ELexState lexState;
    QFile* sourceFile;
    QChar currentChar;

    void SetLexState(ELexState newState);

    bool IsWhiteSpace(QChar c);
    bool IsAlphabet(QChar c);
    bool IsDigit (QChar c);

    void ProcessLexState_Initial();
    void ProcessLexState_Identifier();

    void Fail();
};

#endif // LEXICALANALYZER_H
