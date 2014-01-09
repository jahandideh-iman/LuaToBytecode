#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
enum ETokenType
{
    Token_Identifier, Token_IntNumber, Token_FloatNumber, Token_String,

    /*************************** Reserved Words *************************/
    Token_And, Token_Break, Token_Do, Token_Else, Token_ElseIf, Token_End,
    Token_False, Token_For, Token_Function, Token_If, Token_In, Token_Local,
    Token_Nil, Token_Not, Token_Or, Token_Repeat, Token_Return, Token_Then,
    Token_True, Token_Until, Token_While,
    /*************************** /Reserved Words *************************/

    Token_Plus, Token_Minus, Token_Asterisk, Token_Slash, Token_Percent,
    Token_Caret, Token_NumberSign, Token_Equal, Token_NotEqual, Token_LesserEqual,
    Token_GreaterEqual, Token_Lesser, Token_Greater, Token_Assign, Token_LeftParen,
    Token_RightParen, Token_LeftBrace, Token_RightBrace, Token_LeftBrack, Token_RightBrack,
    Token_Semicolon, Token_Colon, Token_Comma , Token_Dot, Token_Concat, Token_Varag,
};

class Token
{
public:
    Token(ETokenType _type, QString _value);
    void SetTokenType(ETokenType newType);
    void SetTokenValue(QString newValue);

    QString GetValue();
    ETokenType GetType();
private:
    ETokenType type;
    QString value;
};

#endif // TOKEN_H
