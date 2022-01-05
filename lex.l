%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "parser.tab.h"

    // #ifndef BOOL
    // # define BOOL
    // enum bool {false, true};
    // #endif

    int lineno = 1; // initialize to 1
    int err_lex = 0;
    // void ret_print(char *token_type);
    // void yyerror();
	// FILE *yyin;
	// FILE *yyout;

    
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
 
 
"+"                     { return(ADDOP);}
"-"                     { return(SUBOP);}
"*"                     { return(MULOP);}
"/"                     { return(DIVOP);}
"%"                     { return(MODOP);}


"||"                    { return(OROP);}
"&&"                    { return(ANDOP);}
"!"                     { return(NOTOP);}


"=="                    {return(EQUOP);}
"#"                     { return(NEQUOP);}
">"                     { return(SUPSOP);}
"<"                     { return(INFSOP);}
">="                    { return(SUPOP);}
"<="                    { return(INFOP);}
 
 
"("             { return(LPAREN);}
")"             { return(RPAREN);}
"["             { return(LBRACK);}
"]"             { return(RBRACK);}
"{"             { return(LBRACE);}
"}"             { return(RBRACE);}
";"             { return(SEMI);}
"."             { return(DOT);}
","             { return(COMMA);}


{ICONST}        { return(ICONST);}
{FCONST}        { return(FCONST);}
{CCONST}        { return(CCONST);}
{STRING}        { return(STRING);}
{ID}            { return(ID);}
{ID}"[]"        { return(TABLE);}
 
 
"\n"            { lineno += 1; }
[ \t\r\f]+          
.               { fprintf(stderr, "Lexeme inconnu a la ligne %d\n", lineno); err_lex=1;}
 
%%