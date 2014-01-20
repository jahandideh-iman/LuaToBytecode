#pragma once

#include <qvector.h>
#include <qstring.h>


enum SymbolType
{
	Type_None, Type_Int, Type_String, Type_Float, Type_Array,Type_ArrayElement
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
	SymbolEntry* FindSymbolByName(QString idName);
	SymbolTable* parent;

private:
	
	QVector<SymbolEntry*> symbols;

	


};

