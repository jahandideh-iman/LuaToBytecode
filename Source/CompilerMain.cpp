#include "compilermain.h"

CompilerMain* CompilerMain::sharedCompiler;

CompilerMain::CompilerMain()
{
	if(QFile::exists("OutPut.txt"))
		QFile::remove("OutPut.txt");
	output = new QFile("OutPut.txt");
	output->open( QIODevice::WriteOnly);
	outStream = new QTextStream(output);
	
	
	nextIDIndex = 0;
	nextTemp = 0;
	nextLabel = 0;
	currentScope = nullptr;
	AddScope();
	SetSharedCompiler(this);
    nextTokenIndex= 0;
    qDebug ("Compiler Main");
    tokenList = new QVector<Token*>;
    InitialLexicalAnalyzer();
    InitialSyntaxAnalyzer();
   
}

CompilerMain::~CompilerMain()
{

}

void CompilerMain::EmitLine(std::string line)
{
	(*outStream)<<line.c_str()<<endl;
	outStream->flush();
}

void CompilerMain::AddScope()
{
	currentScope = new SymbolTable(currentScope);
}

YYSTYPE CompilerMain::CreateLabel()
{
	nextLabel++;
	std::string labelName = LABELNAME+std::to_string(nextLabel);
	return labelName;
}

YYSTYPE CompilerMain::CreateTemp()
{
	nextTemp++;

	std::string tempName = TEMPNAME+std::to_string(nextTemp);
	AddEntry(QString::fromStdString(tempName)
		, Type_None);
	return tempName;

	
}

bool CompilerMain::IsTemp(YYSTYPE val)
{
	return val[0]=='$';
}

void CompilerMain::RemoveTemp()
{
	nextTemp--;
}


void CompilerMain::AddEntry(QString name, SymbolType type)
{
	nextIDIndex++;

	SymbolEntry* entry = new SymbolEntry;
	entry->index = nextIDIndex;
	entry->name = name;
	entry->type = type;
	currentScope->AddEntry(entry);
}

int CompilerMain::FindVariableIndexInTable(YYSTYPE idName)
{
	SymbolTable * cScope;
	cScope = currentScope;
	int index;
	while(cScope!=nullptr)
	{
		index = cScope->FindVariableIndexInTable(QString::fromStdString(idName));
		if(index!=-1)
			return index;
		cScope = cScope->parent;
	}
	return -1;
}

void CompilerMain::InsertToken(Token *token)
{
    qDebug()<<token->GetValue();

    //qDebug()<<token->GetType();

    tokenList->push_back(token);
}

int CompilerMain::GetNextToken()
{
	
	Token* token = tokenList->at(nextTokenIndex);
	yylval = token->GetValue().toStdString();
	qDebug()<<("Next Token is " + token->GetValue());
    nextTokenIndex++;
    return token->GetType();
}


void CompilerMain::SetSharedCompiler(CompilerMain* compiler)
{
	sharedCompiler = compiler;
}

CompilerMain *CompilerMain::GetSharedCompiler()
{
    return sharedCompiler;
}

void CompilerMain::InitialLexicalAnalyzer()
{
    LexicalAnalyzer::SetTokenInsertHandler(this,InsertTokenSelector(CompilerMain::InsertToken));
    lexicalAnalyzer = new LexicalAnalyzer();
    //lexicalAnalyzer->SetTokenInsertHandler(this,InsertTokenSelector(CompilerMain::InsertToken));
    //lexicalAnalyzer->StartLexing("SampleText.txt");
    lexicalAnalyzer->StartLexing("Resources/SampleText_SimpleInt.txt");


}

void CompilerMain::InitialSyntaxAnalyzer()
{
    syntaxAnalyzer = new SyntaxAnalyzer();
    syntaxAnalyzer->Analyze();

}

void CompilerMain::PushLabel(YYSTYPE label)
{
	labelStack.push(label);
}

YYSTYPE CompilerMain::PopLabel()
{
	return labelStack.pop();
}