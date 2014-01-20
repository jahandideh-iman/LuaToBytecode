#include "compilermain.h"

CompilerMain* CompilerMain::sharedCompiler;

std::string toString(int val)
{
	return QString::number(val).toStdString();
}

CompilerMain::CompilerMain()
{
    SetSharedCompiler(this);
    mainwindow =new CompilerView;
    mainwindow->show();
	


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
	std::string labelName = LABELNAME+toString(nextLabel);
	return labelName;
}

YYSTYPE CompilerMain::CreateTemp(SymbolType type)
{
	std::string tempName = TEMPNAME+toString(nextTemp);
	if(AddEntry(QString::fromStdString(tempName), type))
		nextTemp++;
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


bool CompilerMain::AddEntry(QString name, SymbolType type)
{
	if(IsInTable(name))
	{
		SetTempType(name,type);
		return false;
	}
	nextIDIndex++;
	qDebug()<<("Entry " + name + " is added to index " )<<nextIDIndex;
	//qDebug()<<("Next Token is " + name);

	SymbolEntry* entry = new SymbolEntry;
	entry->index = nextIDIndex;
	entry->name = name;
	entry->type = type;
	currentScope->AddEntry(entry);
	return true;
}

bool CompilerMain::IsInTable(QString name)
{
	return currentScope->FindVariableIndexInTable(name)!=-1;
}

int CompilerMain::FindVariableIndexInTable(YYSTYPE idName)
{
	SymbolTable * cScope;
	cScope = currentScope;
	int index;
    while(cScope!=NULL)
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
	//qDebug()<<("Next Token is " + token->GetValue());
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
    //lexicalAnalyzer->StartLexing("Resources/SampleText_SimpleInt.txt");
	


}

void CompilerMain::InitialSyntaxAnalyzer()
{
    syntaxAnalyzer = new SyntaxAnalyzer();

	
	

}

void CompilerMain::PushLabel(YYSTYPE label)
{
	qDebug()<<"Pushed Label " << QString::fromStdString(label);
	labelStack.push(label);
}

YYSTYPE CompilerMain::PopLabel()
{
	YYSTYPE label;
	if(!labelStack.isEmpty())
		label= labelStack.pop();
	else 
		label =  "";
	qDebug()<<"Poped Label " << QString::fromStdString(label);
	return label;


}

void CompilerMain::SetEditor(TextEditor *_editor)
{
    editor=_editor;
}

void CompilerMain::Compile()
{
	if(QFile::exists("OutPut.j"))
		QFile::remove("OutPut.j");
	output = new QFile("OutPut.j");
	output->open( QIODevice::WriteOnly);
	outStream = new QTextStream(output);

	nextIDIndex = 0;
	nextTemp = 0;
	nextLabel = 0;
    currentScope = NULL;
	AddScope();

    nextTokenIndex= 0;
    qDebug ("Compiler Main");
    tokenList = new QVector<Token*>;

	if(QFile::exists("TEMPFILE"))
		QFile::remove("TEMPFILE");
	QFile input("TEMPFILE");
	input.open(QIODevice::WriteOnly);
	QTextStream inputStream(&input);
	inputStream<<editor->toPlainText();
	inputStream.flush();
	input.close();

	lexicalAnalyzer->StartLexing("TEMPFILE");


	syntaxAnalyzer->StartParsing();

	if(QFile::exists("TEMPFILE"))
		QFile::remove("TEMPFILE");

}

void CompilerMain::AddError(std::string msg,ErrorType type,int line, int column)
{
	Error* error = new Error;
	error->msg = QString::fromStdString(msg);
	error->type = type;
	error->lineNumber = line;
	error->columnNumber = column;

	errorList.append(error);

}

void CompilerMain::AddSyntaxError()
{
	Token* errorToken = tokenList->at(nextTokenIndex-1);
	AddError(SYNERROR,Error_Syntax, errorToken->lineNumber, errorToken->columnNumber);

}

void CompilerMain::SetTempType(QString name, SymbolType type)
{
	SymbolEntry* tempSymbol = FindSymbolByName(name);
	tempSymbol->type = type;
}

SymbolEntry* CompilerMain::FindSymbolByName(QString name)
{
	SymbolTable * cScope;
	cScope = currentScope;
	SymbolEntry* entry;
    while(cScope!=NULL)
	{
		entry = cScope->FindSymbolByName(name);
		if(entry!=NULL)
			return entry;
		cScope = cScope->parent;
	}
	return NULL;

}

SymbolType CompilerMain::GetType(YYSTYPE val)
{
	SymbolEntry * symbol = FindSymbolByName(QString::fromStdString(val));
	if(symbol!=NULL)
		return symbol->type;

	return Type_None;
}