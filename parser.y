%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "tablesymboles.c"
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int err_lex;
	extern int yylex();
	void yyerror();
%}

/* token definition */
%token CHAR INT FLOAT KSTRING STRUCT VOID 
%token MAIN IF ELSE WHILE BREAK RETURN ASSIGN
%token ADDOP SUBOP MULOP DIVOP MODOP 
%token OROP ANDOP NOTOP EQUOP NEQUOP SUPSOP INFSOP SUPOP INFOP
%token LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA 
%token ICONST FCONST CCONST STRING ID TABLE

%start program

/* expression priorities and rules */

%%

program: structure { printf("\n FIN DE PROGRAMME AVEC SUCCESS \n");};

structure: declarations fonctions MAIN LPAREN RPAREN LBRACE instructions RBRACE;


/* DECLARATION */
declarations: declarations declaration | declaration | /* vide */ ;

declaration: type names SEMI 				{printf(" declaration avec success a la ligne %d\n", lineno);}
	| STRUCT ID LBRACK declarations RBRACK SEMI	{printf(" \n struct declaration avec success a la ligne %d\n", lineno);}
;

type: INT 		{ printf("\n integer");}
	| CHAR 		{ printf("\n char");}
	| FLOAT 	{ printf("\n float");}
	| KSTRING 	{ printf("\n string");}
;

names: variable | names COMMA variable;

variable: ID | ID array ;

array: array LBRACK ICONST RBRACK | LBRACK ICONST RBRACK ;



/* FONCTIONS */
fonctions: fonctions fonction | fonction | /* vide */;

fonction: fonction_head fonction_tail  {printf("\n fin d'implementation d'une fonction a la ligne %d\n", lineno);};

fonction_head: return_type ID LPAREN parameters RPAREN;

fonction_tail: LBRACE declarations instructions RBRACE;

return_type: type 	{printf("  : type de retour d'une fonction qui termine a la ligne %d\n", lineno);};
	| VOID			{printf("  \n void : type de retour d'une fonction qui termine a la ligne %d\n", lineno);};
;

parameters: parameters SEMI parameter | parameter | /* vide */;

parameter : type input {printf("  parametre d'une fonction a la ligne %d\n", lineno);};;

input : input COMMA variable | variable ;


/* INSTRUCTIONS */
instructions: instructions instruction | instruction | /* vide */;

instruction:
	if_instruction		{printf("\n fin de if instruction a la ligne %d\n", lineno);}
	| while_instruction	{printf("\n fin de while instruction a la ligne %d\n", lineno);}
	| assigment 		{printf("\n assigment instruction a la ligne %d\n", lineno);}
	| BREAK	SEMI		{printf("\n break instruction a la ligne %d\n", lineno);}
	| RETURN type_return SEMI	 	{printf("\n return instruction a la ligne %d\n", lineno);}
	| fonction_call SEMI
;

if_instruction: IF LPAREN expression RPAREN tail else_part;

else_part: ELSE tail 	
	| /* vide */	
; 

while_instruction: WHILE LPAREN expression RPAREN tail ;

tail: instruction | LBRACE instructions RBRACE ;

expression:
    expression ADDOP expression 	
	|expression SUBOP expression 	
	|expression MULOP expression 	
	|expression DIVOP expression 	
	|expression MODOP expression 
	|expression OROP expression 
	|expression ANDOP expression 
	|NOTOP expression 
	|expression EQUOP expression 	
	|expression NEQUOP expression 
	|expression SUPSOP expression 
	|expression INFSOP expression 
	|expression SUPOP expression 
	|expression INFOP expression 
	|LPAREN expression RPAREN 
	|variable 						
	|sign constant 
	|fonction_call
;

sign: ADDOP | SUBOP | /* vide */ ; 

constant: ICONST | FCONST ;

type_return : ICONST | FCONST | CCONST | STRING;

assigment: variable ASSIGN expression SEMI ; 

fonction_call: ID LPAREN call_params RPAREN		{printf("\n Appel d'une fonction a la ligne %d\n", lineno);};

call_params: call_param | /* vide */;

call_param : call_param COMMA variable | variable ;


%%

void yyerror ()
{
  fprintf(stderr, "Syntax error at line %d\n", lineno);
  exit(1);
}

int main (int argc, char *argv[]){	


	// yyparse();
	// printf("Success");
	

	// initialize symbol table
	init_hash_table();

	// parsing
	int flag;
	yyin = fopen(argv[1], "r");
	flag = yyparse();

	// if(err_lex == 1){printf("err lexicale");}
	// else{printf("Success de l'analyse lexicale");}

	fclose(yyin);
	
	// symbol table dump
	yyout = fopen("table_symboles.txt", "w");
	affiche_table(yyout);
	fclose(yyout);	
	
	
	return flag;
}