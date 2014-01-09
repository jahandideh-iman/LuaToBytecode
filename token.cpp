#include "token.h"

Token::Token(ETokenType _type, QString _value)
{
    type = _type;
    value = _value;
}

void Token::SetTokenType(ETokenType newType)
{
    type = newType;
}

void Token::SetTokenValue(QString newValue)
{
    value = newValue;
}

QString Token::GetValue()
{
    return value;
}

ETokenType Token::GetType()
{
    return type;
}
