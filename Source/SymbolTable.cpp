#include "SymbolTable.h"


SymbolTable::~SymbolTable(void)
{
}

SymbolTable::SymbolTable(SymbolTable* p)
{
	parent = p;
}


void SymbolTable::AddEntry(SymbolEntry* entry)
{
	symbols.append(entry);
}

int SymbolTable::FindVariableIndexInTable(QString idName)
{
	for( int i = 0 ; i<symbols.size(); i++)
	{
		if(symbols.at(i)->name == idName)
			return symbols.at(i)->index;
	}
	return -1;
}
