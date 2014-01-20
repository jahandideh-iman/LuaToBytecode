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
void EmitIntToString(YYSTYPE val);
void CheckSemantic(YYSTYPE val);
std::string toString(int val);

void EmitLine(std::string str);
void EmitStore(YYSTYPE val);
SymbolType GetType(YYSTYPE val);
bool IsTemp(YYSTYPE val);
bool IsID(YYSTYPE val);
bool IsConstString(YYSTYPE val);
bool IsConstInteger (YYSTYPE val);
void SetTypeByValueType(YYSTYPE val1,YYSTYPE val2);
void EmitComparison(YYSTYPE comparisonVal);
void RemoveTemp();
YYSTYPE CreateTemp(SymbolType type);
YYSTYPE CreateLabel();

void EmitPrint (YYSTYPE val);

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
%token Token_Print
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

        stat :		Token_Print Token_LeftParen exp Token_RightParen { EmitPrint($3);}
				|	Token_Do  block Token_End      
                |	Token_While 
                                        {
                                                YYSTYPE whileBegin = CreateLabel();
                                                YYSTYPE whileEnd = CreateLabel();
                                                EmitLine(whileBegin + ":");
                                                PushLabel(whileBegin);
                                                PushLabel(whileEnd);
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
                                        Token_Do block  Token_End
                                        {
                                                YYSTYPE whileEnd = PopLabel();
                                                YYSTYPE whileBegin = PopLabel();
                                                EmitLine("goto " +whileBegin);
                                                EmitLine(whileEnd+ ":");

                                        }
                |	repetition 
                |	Token_Repeat unblock                                                                {}
                |	Token_If 
                            {   
								YYSTYPE nextLabel = CreateLabel();
								YYSTYPE endLabel = CreateLabel();    
								PushLabel(endLabel);
								PushLabel(nextLabel);
                            } 
					conds Token_End {/*EmitLine(PopLabel()+ ":");*/} 
                                        
                | Token_Function funcname
					 { EmitLine( ".method public static "  + $2);}
					  funcbody        
				| lvar Token_Assign exp                
								{      
									EmitLoadValue($3);
									CheckSemantic($3);
									SetTypeByValueType($1,$3);
                                    EmitStore($1);      
                                }
                | functioncall                                                                                {}
                ;

        repetition : Token_For name Token_Assign exp Token_Comma exp 
                            {
                                    YYSTYPE forCond = CreateLabel();
                                    YYSTYPE forEnd = CreateLabel();
                                    PushLabel(forEnd);
                                    PushLabel(forCond);
                                    AddEntry($2,Type_Int);
                                    EmitLoadValue($4);
                                    EmitStore( $2);

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
									EmitStore($2);
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
                                        AddEntry($2,Type_Int);
                                        EmitLoadValue($4);
                                        EmitStore($2);

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
										EmitStore($2);
                                        EmitLine("goto " + PopLabel());
                                        EmitLine(PopLabel() + ":");
                                        //TODO: temp Removing 
                                }
                
                
                        
                | Token_For namelist Token_In explist1         Token_Do block Token_End                                {print("repetition");}
                ;

        conds :		condlist 
						{
							EmitLine(PopLabel()+":");
						}
                |	condlist Token_Else 
						{
							//EmitLine(PopLabel()+":");
						} 
					block
                ;

        condlist :	cond {
							
							EmitLine(PopLabel() +":");
							//PushLabel(CreateLabel());
						} 
                |	condlist Token_ElseIf 
					cond

                ;

        cond :		exp	
						{
                            EmitLoadValue($1);
                            YYSTYPE label = PopLabel();
                            PushLabel(label);
                            EmitLine("ifle " + label);

						}
                        Token_Then block                {
															YYSTYPE nextLabel = PopLabel();
															YYSTYPE endLabel = PopLabel();

															EmitLine("goto " + endLabel);
															PushLabel(endLabel);
															PushLabel(nextLabel);
														}
                ;

        laststat : Token_Break                                {}
                | Token_Return                                 {}
                | Token_Return explist1                        {}
                ;

        binding : Token_Local namelist                                      {}
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

        explist1 : exp							{$$ = $1 ;}
                | explist1 Token_Comma exp                        {}
                ;


        exp : Token_Nil                                {} 
                | Token_True                        {$$ = toString(1)} 
                | Token_False                        {$$ = toString(0)} 
                | number                                {$$ = $1 ;} 
                | Token_String                        {$$ = yylval;} 
                | Token_Varag                        {} 
                | function                                {} 
                | prefixexp									{$$=$1;} 
                | tableconstructor							{$$=$1;} 
                | exp binop exp
								{
                                    ManageBinop($2,$1,$3);
									CheckSemantic($1);
									CheckSemantic($3);

                                    $$ = CreateTemp(Type_Int);
                                   
									EmitStore($$);                                     
								} 
                | uniop exp                                {} 
                ;

		lvar : name                                                {$$ = $1 ;  } 
              | name Token_LeftBrack exp Token_RightBrack           
						{
							$$ = CreateTemp(Type_ArrayElement);
							EmitLoadValue($1);
							EmitLoadValue($3);
						}
                ;
        rvar :	name                                                {$$ = $1 ;  } 
              | name Token_LeftBrack exp Token_RightBrack           
						{
							$$ = CreateTemp(Type_Int);
							EmitLoadValue($1);
							EmitLoadValue($3);
							EmitLine("iaload");
							EmitStore($$);
						}
                ;

        prefixexp : rvar                                                      {}
                | functioncall                                                 {print("prefixexp");}
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

        tableconstructor : Token_LeftBrace exp Token_RightBrace 
										{
											$$ = CreateTemp(Type_Array);
											EmitLoadValue($2);
											EmitLine("newarray int");
											EmitStore($$);
										}                
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
	CompilerMain::GetSharedCompiler()->AddEntry(QString::fromStdString(name),type);
}

void yyerror(const char  *)
{
	CompilerMain::GetSharedCompiler()->AddSyntaxError();
}


void EmitLine(std::string str)
{
        return CompilerMain::GetSharedCompiler()->EmitLine(str);
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

YYSTYPE CreateTemp(SymbolType type)
{
        return CompilerMain::GetSharedCompiler()->CreateTemp(type);
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

void SyntaxAnalyzer::StartParsing()
{

	EmitLine(".class public OutPut");
	EmitLine(".super java/lang/Object");
	EmitLine(".method public static main([Ljava/lang/String;)V");
	EmitLine(".limit stack 250");
	EmitLine(".limit locals 300");

	
        qDebug("Start Syntax Analyzer");
    if(yyparse()== 0)
                qDebug("Success");
    else
	{
		qDebug("Parse Failed");
		//yyerror("");
	}

	EmitLine("   return");
	EmitLine(".end method");

                
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
        EmitLine("goto " + endLabel);
        EmitLine(trueLabel + ":");
        EmitLoadValue(toString(1));
        EmitLine(endLabel + ":");
}

void EmitLoadValue(YYSTYPE val)
{
	if(val=="")
		return;
	SymbolType type =GetType(val);
	EmitLine(";load  " + val); 
	if(type == Type_Int)
	{
		EmitLine("iload "+ GETINDEX(val));
	}
	else if( type == Type_Array) 
	{
		EmitLine("aload "+ GETINDEX(val));
	}
    else if (type == Type_None) // const
        EmitLine("ldc "+ val);

	else if( type ==Type_ArrayElement)
		EmitLine("iaload");

	//if(IsTemp(val))	
		//RemoveTemp();

        
}

void EmitStore(YYSTYPE val)
{
	
	if(val=="")
		return;

	SymbolType type = GetType(val);
	EmitLine(";store in " + val); 
	if(type == Type_Int)
		EmitLine("istore " +GETINDEX(val)); 
	else if(type == Type_Array)
		EmitLine("astore " +GETINDEX(val));
	else if(type == Type_ArrayElement)
	{
		EmitLine("iastore ");

	}
		
}

SymbolType GetType(YYSTYPE var)
{
	return CompilerMain::GetSharedCompiler()->GetType(var);
}


void EmitPrint (YYSTYPE val)
{
	
	EmitLine("getstatic java/lang/System/out Ljava/io/PrintStream;");

	if(!IsConstString(val))
		EmitIntToString(val);
	else
		EmitLine(std::string("ldc ") + std::string(val));

	EmitLine("invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V");
}

bool IsConstString(YYSTYPE val)
{
	return val[0]=='\"';
}

void EmitIntToString(YYSTYPE val)
{
	EmitLoadValue(val);
	EmitLine("invokestatic java/lang/Integer/toString(I)Ljava/lang/String;");
}
void fullPrint(YYSTYPE str)
{
        qDebug(str.c_str());
}

void SetTypeByValueType(YYSTYPE val1,YYSTYPE val2)
{

	if(val1=="" || val2=="")
		return;
	SymbolType type1 = GetType(val1);
	SymbolType type2 = GetType(val2);
	
	if(type1 == Type_ArrayElement)
		return;
	if(type2 == Type_Int || IsConstInteger(val2))
		AddEntry(val1,Type_Int);
	else if( type2 == Type_Array)
		AddEntry(val1,Type_Array);
	else if( type2 = Type_ArrayElement)
		AddEntry(val1,Type_Int);
}

bool IsConstInteger (YYSTYPE val)
{
	return (val[0]>='0' && val[0]<='9');
}


void CheckSemantic(YYSTYPE val)
{
	if(IsConstInteger(val) || IsConstString(val))
		return;
	
	if(GETINDEX(val)=="-1")
		CompilerMain::GetSharedCompiler()->AddSemanticError();
		
}

