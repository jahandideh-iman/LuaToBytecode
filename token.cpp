#include "token.h"

Token::Token()
{
}

void Token::SetTokenType(TokenType newType)
{
    type = newType;
}

void Token::SetTokenValue(QString newValue)
{
    value = newValue;
}
