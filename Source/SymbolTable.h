#pragma once

#include <qvector.h>
#include <qstring.h>


enum SymbolType
{
	Type_None, Type_Int, Type_String, Type_Float,
};

struct SymbolEntry
{
	QString name;
	unsigned int index;
	SymbolType type;
};

class SymbolTable
{
public:
	~SymbolTable(void);
	SymbolTable(SymbolTable* parent);
	void AddEntry(SymbolEntry* entry);
	int FindVariableIndexInTable(QString idName);
	SymbolTable* parent;

private:
	
	QVector<SymbolEntry*> symbols;

	


};

