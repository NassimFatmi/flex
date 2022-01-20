%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symtab.h"
	#include "semantics.h"
	#include "ast.h"
	#include "parser.tab.h"

    // #ifndef BOOL
    // # define BOOL
    // enum bool {false, true};
    // #endif

    int lineno = 1; // initialize to 1
    int err_lex = 0;
    // void ret_print(char *token_type);
    void yyerror();
	extern FILE *yyin;
	extern FILE *yyout;

    
%}

%option noyywrap

%x ML_COMMENT 

alpha       [a-zA-Z]
number       [0-9]
alnum       {alpha}|{number}
print       [ -~]
ICONST      {number}+
FCONST      {number}+"."{number}+
CCONST      (\'{print}\')|(\'\\[nftrbv]\')
STRING      \"{print}*\"
TYPE        "char"|"integer"|"string"|"float"
ID          {alpha}+{alnum}*
%%
 
"!!".*                  { printf(" \n commentaire a la ligne %d\n", lineno); } 
 
"!*"                    { printf(" \n commentaire de la ligne %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*!"        { printf(" a la ligne %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+     
<ML_COMMENT>"*"         
<ML_COMMENT>"\n"        { lineno += 1; }
 
 
"char"        { return (CHAR);}
"integer"     { return (INT) ;}
"float"       { return(FLOAT);}
"string"      { return(KSTRING);}
"struct"      { return(STRUCT);}
"void"        { return(VOID);}
"main"        { return(MAIN);}



"if"           { return(IF);}
"else"         { return(ELSE);}
"while"        { return(WHILE);}
"break"        { return(BREAK);}
"return"       { return(RETURN);}
"="            { return(ASSIGN);}
 
 
"+"                     { yylval.val.ival = ADD; return ADDOP; }
"-"                     { yylval.val.ival = SUB; return ADDOP; }
"*"                     { return(MULOP);}
"/"                     { return(DIVOP);}
"%"                     { return(MODOP);}


"||"                    { return(OROP);}
"&&"                    { return(ANDOP);}
"!"                     { return(NOTOP);}


"=="				    { yylval.val.ival = EQUAL; return EQUOP; }
"!="				    { yylval.val.ival = NOT_EQUAL; return NEQUOP; }
">"						{ yylval.val.ival = GREATER; return SUPSOP; }
"<"						{ yylval.val.ival = LESS; return INFSOP; }
">="					{ yylval.val.ival = GREATER_EQUAL; return SUPOP; }
"<="					{ yylval.val.ival = LESS_EQUAL; return INFOP; }
 
 
"("             { return(LPAREN);}
")"             { return(RPAREN);}
"["             { return(LBRACK);}
"]"             { return(RBRACK);}
"{"             { return(LBRACE);}
"}"             { return(RBRACE);}
";"             { return(SEMI);}
"."             { return(DOT);}
","             { return(COMMA);}


{ID}            {
                    // insert identifier into symbol table
                    insert(yytext, strlen(yytext), UNDEF, lineno);
                    yylval.symtab_item = lookup(yytext);
                    return ID;
                }
{ICONST} 	    { yylval.val.ival = atoi(yytext); return ICONST; }
{FCONST} 		{ yylval.val.fval = atof(yytext); return FCONST; }
{CCONST} 		{ yylval.val.cval = yytext[0];    return CCONST; }
{STRING} 		{ 
				   yylval.val.sval = malloc(yyleng * sizeof(char));
				   strcpy(yylval.val.sval, yytext);  return STRING;
				}
{ID}"[]"        { return(TABLE);}
 
 
"\n"            { lineno += 1; }
[ \t\r\f]+          
.               { printf("Lexeme inconnu a la ligne %d\n", lineno); err_lex=1; return 1;}
 
%%