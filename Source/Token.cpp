#include "token.h"

Token::Token(yytokentype _type, QString _value, int _lineNumber, int _columnNumber)
{

    type = _type;
    value = _value;
	lineNumber = _lineNumber;
	columnNumber = _columnNumber;
}

void Token::SetTokenType(yytokentype newType)
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

yytokentype Token::GetType()
{
    return type;
}
