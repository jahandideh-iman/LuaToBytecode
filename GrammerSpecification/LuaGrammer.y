%output "../Source/SyntaxAnalyzer.cpp"
%defines "../Source/ParserTokens.h"
%no-lines

%code requires
{
#include <string>
#define YYSTYPE std::string
}

%{
#include <string>
#include "SyntaxAnalyzer.h"
int GetNextToken (); 
int ParserLex();
#define yylex  GetNextToken
//#define YYERROR yyerror
void yyerror ( const char *);
void emptyPrint(YYSTYPE);
void fullPrint(YYSTYPE);
void AddScope();
std::string toString(int val);
void EmitLine(std::string str);
bool IsTemp(YYSTYPE val);
bool IsID(YYSTYPE val);
void EmitComparison(YYSTYPE comparisonVal);
void RemoveTemp();
YYSTYPE CreateTemp();
YYSTYPE CreateLabel();

void EmitLoadValue(YYSTYPE val);
YYSTYPE PopLabel();
void PushLabel(YYSTYPE label);

void ManageBinop(YYSTYPE binop, YYSTYPE firstOP, YYSTYPE secOP);
YYSTYPE GetStorage(YYSTYPE idName);
YYSTYPE FindVariableIndexInTable(YYSTYPE idName);
void AddEntry(YYSTYPE name, SymbolType type);
#define print emptyPrint
#define print1 fullPrint
#define GETINDEX FindVariableIndexInTable
%}



%token Token_EndOfFile 0
%token Token_Identifier
%token Token_IntNumber
%token Token_FloatNumber
%token Token_String
%left Token_And
%token Token_Break
%token Token_Do
%token Token_Else
%token Token_ElseIf
%token Token_End
%token Token_False
%token Token_For
%token Token_Function
%token Token_If
%token Token_In
%token Token_Local
%token Token_Nil
%right Token_Not
%left Token_Or
%token Token_Repeat
%token Token_Return
%token Token_Then
%token Token_True
%token Token_Until
%token Token_While
%left Token_Plus
%left Token_Minus
%left Token_Asterisk
%left Token_Slash
%left Token_Percent
%right Token_Caret
%right Token_NumberSign
%left Token_Equal
%left Token_NotEqual
%left Token_LesserEqual
%left Token_GreaterEqual
%left Token_Lesser
%left Token_Greater
%token Token_Assign
%token Token_LeftParen
%token Token_RightParen
%token Token_LeftBrace
%token Token_RightBrace
%token Token_LeftBrack
%token Token_RightBrack
%token Token_Semicolon
%token Token_Colon
%token Token_Comma
%token Token_Dot
%right Token_Concat
%token Token_Varag




%%

        chunk :  block                                                {$$= $1 ;}
                ;

        semi :                                                         { }
                | Token_Semicolon                        {print("semi"); }
                ; 

        block :  scope statlist                                {$$ = $1 + $2 ;  }
                | scope statlist laststat semi        {$$ = $1 + $2 + $3 + $4 ;  }
                ;

        unblock : block Token_Until exp                {}
                ;

        scope :                                                                {}
                | scope statlist binding semi        {  }
                ;

        statlist :                                                        { $$ = $0 ; }
                |  statlist stat semi                         {$$ = $1 + $2  ; }
                ;

        stat : Token_Do {print1("WTFFFFFFFFFFFFFF");} block Token_End                                                        { }
                | Token_While 
                                        {
                                                YYSTYPE whileBegin = CreateLabel();
                                                YYSTYPE whileEnd = CreateLabel();
                                                EmitLine(whileBegin + ":");
                                                PushLabel(whileBegin);
                                                PushLabel(whileEnd);
                                                print1("In While");
                                        }
                                        exp 
                                        {
                                                print1("EXP in while is " + $2);
                                                
                                                //if(!IsTemp($2))
                                                        //$2=CreateTemp();
                                                EmitLoadValue($2);
                                                YYSTYPE whileEnd = PopLabel();
                                                PushLabel(whileEnd);
                                                EmitLine("ifle " + whileEnd);

                                        }
                                        Token_Do { print1("In DOooooo");}block  {print1("new Block");} Token_End
                                        {
                                                YYSTYPE whileEnd = PopLabel();
                                                YYSTYPE whileBegin = PopLabel();
                                                EmitLine("goto " +whileBegin);
                                                EmitLine(whileEnd+ ":");

                                        }
                | repetition 
                | Token_Repeat unblock                                                                {}
                |        Token_If 
                                        {        
                                                PushLabel(CreateLabel());
                                        } 
                        conds Token_End 
                                        
                | Token_Function funcname funcbody                                        {}
                | setlist Token_Assign explist1                                                {        if(IsTemp($3))
                                                                                                                                {
                                                                                                                                        EmitLine("iload "+ GETINDEX ($3) ); 
                                                                                                                                        RemoveTemp();
                                                                                                                                }
                                                                                                                                else
                                                                                                                                        EmitLine("ldc " + $3);
                                                                                                                                EmitLine(";store in " + $$);
                                                                                                                                EmitLine("istore " +GETINDEX($1));        
                                                                                                                                }
                | functioncall                                                                                {}
                ;

        repetition : Token_For name Token_Assign exp Token_Comma exp 
                                                                                                {
                                                                                                        YYSTYPE forCond = CreateLabel();
                                                                                                        YYSTYPE        forEnd = CreateLabel();
                                                                                                        PushLabel(forEnd);
                                                                                                        PushLabel(forCond);
                                                                                                        AddEntry($2,Type_None);
                                                                                                        EmitLoadValue($4);
                                                                                                        EmitLine(";store in " + $2);  
                                                                                                        EmitLine("istore " + GETINDEX($2));

                                                                                                        EmitLine(forCond + ":");
                                                                                                        //TODO: semantic check: it must be variable
                                                                                                        EmitLoadValue($2);
                                                                                                        EmitLoadValue($6);
                                                                                                        EmitLine("if_icmpgt " +forEnd);
                                                                                                }
                                Token_Do block Token_End
                                                                                                {
                                                                                                        EmitLoadValue(toString(1));
                                                                                                        EmitLoadValue($2);
                                                                                                        EmitLine("iadd");
                                                                                                        EmitLine(";store in " + $2);  
                                                                                                        EmitLine("istore " + GETINDEX($2));
                                                                                                        EmitLine("goto " + PopLabel());
                                                                                                        EmitLine(PopLabel() + ":");
                                                                                                        //TODO: temp Removing 
                                                                                                }
                | Token_For name Token_Assign exp Token_Comma exp Token_Comma exp 
                                                                                                {
                                                                                                        YYSTYPE forCond = CreateLabel();
                                                                                                        YYSTYPE        forEnd = CreateLabel();
                                                                                                        PushLabel(forEnd);
                                                                                                        PushLabel(forCond);
                                                                                                        AddEntry($2,Type_None);
                                                                                                        EmitLoadValue($4);
                                                                                                        EmitLine(";store in " + $2);  
                                                                                                        EmitLine("istore " + GETINDEX($2));

                                                                                                        EmitLine(forCond + ":");
                                                                                                        //TODO: semantic check: it must be variable
                                                                                                        EmitLoadValue($2);
                                                                                                        EmitLoadValue($6);
                                                                                                        EmitLine("if_icmpgt " +forEnd);
                                                                                                }        
                                Token_Do block Token_End        
                                                                                                {
                                                                                                        EmitLoadValue($8);
                                                                                                        EmitLoadValue($2);
                                                                                                        EmitLine("iadd");
                                                                                                        EmitLine(";store in " + $2);  
                                                                                                        EmitLine("istore " + GETINDEX($2));
                                                                                                        EmitLine("goto " + PopLabel());
                                                                                                        EmitLine(PopLabel() + ":");
                                                                                                        //TODO: temp Removing 
                                                                                                }
                
                
                        
                | Token_For namelist Token_In explist1         Token_Do block Token_End                                {print("repetition");}
                ;

        conds : condlist {EmitLine(PopLabel()+":");}
                | condlist Token_Else {EmitLine(PopLabel()+":");} block
                ;

        condlist : cond 
                | condlist Token_ElseIf {EmitLine(PopLabel() +":");PushLabel(CreateLabel());} cond
                ;

        cond :        exp        {
                                        if(IsTemp($1))
                                        {
                                                
                                                EmitLine("iload " + GETINDEX($1));
                                                RemoveTemp(); 
                                        }
                                        else
                                                EmitLine("ldc" + $1);
                                        YYSTYPE label = PopLabel();
                                        PushLabel(label);
                                        EmitLine("ifle " + label);
                                }
                        Token_Then block                {$$ = $1;}
                ;

        laststat : Token_Break                                {}
                | Token_Return                                        {}
                | Token_Return explist1                        {}
                ;

        binding : Token_Local namelist                                                        {}
                | Token_Local namelist Token_Assign explist1                {}
                | Token_Local Token_Function name funcbody                        {}
                ;

        funcname : dottedname
                | dottedname Token_Colon name
                ;

        dottedname : name                                                {}
                | dottedname Token_Dot name                        {}
                ;

        namelist : name                                                        {}
                | namelist Token_Comma name                        {}
                ;

        explist1 : exp                                                        {$$ = $1 ;}
                | explist1 Token_Comma exp                        {}
                ;


        exp : Token_Nil                                {} 
                | Token_True                        {$$ = toString(1)} 
                | Token_False                        {$$ = toString(0)} 
                | number                                {$$ = $1 ;} 
                | Token_String                        {$$ = yylval;} 
                | Token_Varag                        {} 
                | function                                {} 
                | prefixexp                                {$$=$1} 
                | tableconstructor                {} 
                | exp binop exp                        {
                                                                        ManageBinop($2,$1,$3);
                                                                        $$ = CreateTemp();
                                                                        print1("in binop first exp : " +$1);
                                                                        print1("in binop second exp : "+ $3);
                                                                        print1("in binop operator : "+ $2);
                                                                        print1("in binop result : "+ $$);


                                                                        
                                                                        EmitLine(";store in " + $$);
                                                                        EmitLine("istore " + GETINDEX($$));
                                                                        

                                                                } 
                | uniop exp                                {} 
                ;

        setlist : var        {$$ = $1 ; AddEntry($$,Type_None); } 
                | setlist Token_Comma var                {print("setlist");} 
                ;

        var : name                                                                                                                {print("name : "); $$ = $1; } 
                | prefixexp Token_LeftBrack exp Token_RightBrack                        {print("var");}
                | prefixexp Token_Dot name                                                                        {print("var");}
                ;

        prefixexp : var                                                                                {}
                | functioncall                                                                        {print("prefixexp");}
                | Token_LeftParen exp Token_RightParen                        {print("prefixexp");}
                ;

        functioncall : prefixexp args                                                {print("functioncall");}
                | prefixexp Token_Colon name args                                {print("functioncall");}
                ;

        args : Token_LeftParen Token_RightParen                                        {print("args");}
                | Token_LeftParen explist1 Token_RightParen                        {print("args");}
                | tableconstructor                                                                        {print("args");}        
                | Token_String                                                                                {print("args");}
                ;

        function : Token_Function funcbody                                                {print("function");}
                ;

        funcbody : params block Token_End                                                {print("funcbody");}
                ;

        params : Token_LeftParen parlist Token_RightParen                {print("params");}
                ;

        parlist :                                                                        {print("parlist");}                
                | namelist                                                                {print("parlist");}
                | Token_Varag                                                        {print("parlist");}
                | namelist Token_Comma Token_Varag                {print("parlist");}
                ;

        tableconstructor : Token_LeftBrace Token_RightBrace                                {print("tableconstructor");}                
                | Token_LeftBrace fieldlist Token_RightBrace                                {print("tableconstructor");}
                | Token_LeftBrace fieldlist fieldsep Token_RightBrace                {print("tableconstructor");}
                ;

        fieldlist : field                                                {print("fieldlist");}
                | fieldlist fieldsep field                        {print("fieldlist");}
                ;

        fieldsep : Token_Comma                                {print("fieldsep");}
                | Token_Semicolon                                {print("fieldsep");}
                ;

        field : exp                                                                                                                        {print("field");}
                | name Token_Assign exp                                                                                        {print("field");}
                | Token_LeftBrack exp Token_RightBrack Token_Assign exp                        {print("field");}
                ;

        binop : Token_Plus                                {print("binop");}
                | Token_Minus                                {print("binop");}
                | Token_Asterisk                        {print("binop");}
                | Token_Slash                                {print("binop");}
                | Token_Caret                                {print("binop");}
                | Token_Percent                                {print("binop");}
                | Token_Concat                                {print("binop");}
                | Token_Lesser                                {print("binop");}
                | Token_LesserEqual                        {print("binop");}
                | Token_Greater                                {print("binop"); $$ = $1 }
                | Token_GreaterEqual                {print("binop");}
                | Token_Equal                                {}
                | Token_NotEqual                        {print("binop");}
                | Token_And                                        {print("binop");}
                | Token_Or                                        {print("binop");}
                ;

        uniop : Token_Minus                                {print("uniop");}
                | Token_Not                                        {print("uniop");}
                | Token_NumberSign                        {print("uniop");}
                ;

        number : Token_IntNumber                {$$ = $1}
                | Token_FloatNumber                        {$$ = $1;}
                ;

        name : Token_Identifier                        { $$=$1;}
                ;




        
%%



int GetNextToken()
{
        //qDebug("Get Next Token");
        
        return CompilerMain::GetSharedCompiler()->GetNextToken();
}

void AddScope()
{
        return CompilerMain::GetSharedCompiler()->AddScope();
}

void AddEntry(std::string name, SymbolType type)
{
        return CompilerMain::GetSharedCompiler()->AddEntry(QString::fromStdString(name),type);
}

void yyerror(const char  *)
{
	CompilerMain::GetSharedCompiler()->AddSyntaxError();
}


void EmitLine(std::string str)
{
        return CompilerMain::GetSharedCompiler()->EmitLine(str);
}
YYSTYPE GetStorage(YYSTYPE idName)
{
        YYSTYPE idIndex = FindVariableIndexInTable(idName);
        return "istore "+idIndex;
}

YYSTYPE FindVariableIndexInTable(YYSTYPE idName)
{
        return toString(CompilerMain::GetSharedCompiler()->FindVariableIndexInTable(idName));
}

bool IsTemp(YYSTYPE val)
{
        return CompilerMain::GetSharedCompiler()->IsTemp(val);
}

bool IsID(YYSTYPE val)
{
        return ( (val[0]>='a' &&  val[0]<= 'z')
                        || (val[0]>='A' &&  val[0]<= 'Z')
                        || (val[0]=='_') );
}

void RemoveTemp()
{
        CompilerMain::GetSharedCompiler()->RemoveTemp();
}

YYSTYPE CreateTemp()
{
        return CompilerMain::GetSharedCompiler()->CreateTemp();
}


YYSTYPE CreateLabel()
{
        return CompilerMain::GetSharedCompiler()->CreateLabel();
}

YYSTYPE PopLabel()
{
        return CompilerMain::GetSharedCompiler()->PopLabel();
}

void PushLabel(YYSTYPE label)
{
        return CompilerMain::GetSharedCompiler()->PushLabel(label);
}


SyntaxAnalyzer::SyntaxAnalyzer()
{
    
}

void SyntaxAnalyzer::Analyze()
{
        qDebug("Start Syntax Analyzer");
    if(yyparse()== 0)
                qDebug("Success");
    else
		yyerror("");

                
}

void emptyPrint(YYSTYPE str)
{
        
}

void ManageBinop(YYSTYPE binop, YYSTYPE firstOP, YYSTYPE secOP)
{
        EmitLoadValue(firstOP);
        EmitLoadValue(secOP);

        if(binop == ">")
                EmitComparison("if_icmpgt");

        else if (binop==">=")
                EmitComparison("if_icmpge");

        else if (binop=="<")
                EmitComparison("if_icmplt");

        else if (binop == "<=")
                EmitComparison("if_icmple");

        else if (binop == "==")
                EmitComparison("if_icmpeq");

        else if (binop == "~=")
                EmitComparison("if_icmpne");

        else if (binop == "+")
                EmitLine("iadd");
        else if (binop == "-")
                EmitLine("isub");
        else if (binop == "/")
                EmitLine("idiv");
        else if (binop == "*")
                EmitLine("imul");
        else if (binop == "^")
                EmitLine("ishl");
        
        



}

void EmitComparison(YYSTYPE comparisonVal)
{
        YYSTYPE trueLabel = CreateLabel();
        YYSTYPE endLabel =  CreateLabel();
        EmitLine(comparisonVal+" "+trueLabel);
        EmitLoadValue(toString(0));
        EmitLoadValue("goto " + endLabel);
        EmitLoadValue(trueLabel + ":");
        EmitLoadValue(toString(1));
        EmitLoadValue(endLabel + ":");
}

void EmitLoadValue(YYSTYPE val)
{
        if(IsTemp(val))
        {
                EmitLine("iload "+ GETINDEX(val));
                RemoveTemp();
        }
        else if(IsID(val))
        {
                EmitLine("iload "+ GETINDEX(val));
        }
        else
                EmitLine("ldc "+ val);
        
}

void fullPrint(YYSTYPE str)
{
        qDebug(str.c_str());
}

