#ifndef TOKEN_H
#define TOKEN_H

#include <QString>
enum TokenType
{
    Token_Identifier, Token_IntNumber, Token_FloatNumber, Token_If, Token_While
};

class Token
{
public:
    Token(TokenType _type, QString _value);
    void SetTokenType(TokenType newType);
    void SetTokenValue(QString newValue);
private:
    TokenType type;
    QString value;
};

#endif // TOKEN_H
