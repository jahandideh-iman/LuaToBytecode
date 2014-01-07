#include "lexicalanalyzer.h"

LexicalAnalyzer::LexicalAnalyzer()
{
}

void LexicalAnalyzer::StartLexingWithFile(QFile *file)
{
    sourceFile = file;
    StartLexing();

}

void LexicalAnalyzer::StartLexing()
{
    SetLexState(LexState_Initial);
    while( !sourceFile->atEnd())
    {

        switch (lexState) {
        case LexState_Initial:
            ProcessLexState_Initial();
            break;
        case LexState_Number:
            break;
        case LexState_Identifier:
            ProcessLexState_Identifier();
            break;
        default:
            break;

        }
    }
}

void LexicalAnalyzer::SetLexState(ELexState newState)
{
    lexState = newState;
}

bool LexicalAnalyzer::IsWhiteSpace(QChar c)
{
    return ( c == ' '
             || c == '\t '
             || c == '\n'
             || c ==  '\r');
}

bool LexicalAnalyzer::IsAlphabet(QChar c)
{
    return ( (c>= 'a' && c<='z')
             || (c>= 'A' && c<= 'Z') );
}

bool LexicalAnalyzer::IsDigit(QChar c)
{
    return ( c>= '0' && c<='9');
}

void LexicalAnalyzer::ProcessLexState_Initial()
{
    if(IsWhiteSpace(currentChar))
        return;

    else if (IsAlphabet(currentChar))
        SetLexState(LexState_Identifier);

    else if (IsDigit(currentChar))
        SetLexState(LexState_Number);

    else
        Fail();

}

void LexicalAnalyzer::ProcessLexState_Identifier()
{

}

void LexicalAnalyzer::Fail()
{

}
