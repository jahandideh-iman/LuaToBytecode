#include "token.h"

Token::Token(TokenType _type, QString _value)
{
    type = _type;
    value = _value;
}

void Token::SetTokenType(TokenType newType)
{
    type = newType;
}

void Token::SetTokenValue(QString newValue)
{
    value = newValue;
}
