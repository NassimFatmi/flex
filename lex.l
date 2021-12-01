%option noyywrap
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "tablesymboles.c"

    int lineno = 1; // initialize to 1
    void ret_print(char *token_type);
    void yyerror();

	FILE *yyin;
	FILE *yyout;
    

%}
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
 
"!!".*                  { printf("Eat up comment at line %d\n", lineno); } 
 
"!*"                    { printf("Eat up comment from line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*!"        { printf("to line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+     
<ML_COMMENT>"*"         
<ML_COMMENT>"\n"        { lineno += 1; }
 
 
"char"        { ret_print("KEYWORD_CHAR"); }
"intger"      { ret_print("KEYWORD_INT"); }
"float"       { ret_print("KEYWORD_FLOAT"); }
"void"        { ret_print("KEYWORD_VOID"); }
"string"      { ret_print("KEYWORD_STRING"); }
"struct"      { ret_print("KEYWORD_STRUCT"); }
{TYPE}"[]"    { ret_print("KEYWORD_TABLE");}



"if"           { ret_print("KEYWORD_IF"); }
"else"         { ret_print("KEYWORD_ELSE"); }
"while"        { ret_print("KEYWORD_WHILE"); }
"break"        { ret_print("KEYWORD_BREAK"); }
"return"       { ret_print("KEYWORD_RETURN"); }
"="            { ret_print("ASSIGN"); }
 
 
"+"                     { ret_print("SUBOP"); }
"-"                     { ret_print("ADDOP"); }
"*"                     { ret_print("MULOP"); }
"/"                     { ret_print("DIVOP"); }
"%"                     { ret_print("MODOP"); }


"||"                    { ret_print("OROP"); }
"&&"                    { ret_print("ANDOP"); }
"!"                     { ret_print("NOTOP"); }


"=="                    { ret_print("EQUOP"); }
"#"                     { ret_print("NEQUOP"); }
">"                     { ret_print("SUPSOP"); }
"<"                     { ret_print("INFSOP"); }
">="                    { ret_print("SUPOP"); }
"<="                    { ret_print("INFOP"); }
 
 
"("             { ret_print("LPAREN"); }
")"             { ret_print("RPAREN"); }
"]"             { ret_print("LBRACK"); }
"["             { ret_print("RBRACK"); }
"{"             { ret_print("LBRACE"); }
"}"             { ret_print("RBRACE"); }
";"             { ret_print("SEMI"); }
"."             { ret_print("DOT"); }
","             { ret_print("COMMA"); }


{ICONST}        { ret_print("ICONST"); insert(yytext, strlen(yytext), INT_TYPE, lineno); yyout = fopen("table_symboles.txt", "a");affiche_table(yyout);}
{FCONST}        { ret_print("FCONST"); insert(yytext, strlen(yytext), FLOAT_TYPE, lineno); yyout = fopen("table_symboles.txt", "a");affiche_table(yyout);}
{CCONST}        { ret_print("CCONST");insert(yytext, strlen(yytext), CHAR_TYPE, lineno); yyout = fopen("table_symboles.txt", "a");affiche_table(yyout);}
{STRING}        { ret_print("STRING"); insert(yytext, strlen(yytext), STR_TYPE, lineno); yyout = fopen("table_symboles.txt", "a");affiche_table(yyout);}
{ID}            { ret_print("ID"); insert(yytext, strlen(yytext), UNDEF, lineno); yyout = fopen("table_symboles.txt", "a");affiche_table(yyout);}

 
"\n"            { lineno += 1; }
[ \t\r\f]+          
.               { yyerror("Unrecognized character"); }
 
%%
 
void ret_print(char *token_type){
    printf("yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}
 
void yyerror(char *message){
    printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
    exit(1);
}

 
int main(int argc, char *argv[]){

	init_hash_table();

	yyin = fopen(argv[1], "r");
	
	yylex();
	fclose(yyin);
	fclose(yyout);
	
	return 0;
}


