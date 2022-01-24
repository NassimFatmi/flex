%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include "semantics.c"
	#include "symtab.c"
	#include "ast.h"
	#include "ast.c"
	extern FILE *yyin;
	extern FILE *yyout;
	extern int lineno;
	extern int yylex();
	void yyerror();

	// for declarations
	void add_to_names(list_t *entry);
	list_t **names;
	int nc = 0; // nombre des declaration de meme type
	
	// for the initializations of arrays
	void add_to_vals(Value val);
	Value *vals;
	int vc = 0;
%}

/* YYSTYPE union */
%union{
	// different types of values
	Value val;   
	
	// structures
	list_t* symtab_item;
	AST_Node* node;
	
	// for declarations
	int data_type;
	int const_type;
}

/* token definition */
%token<val> CHAR INT FLOAT KSTRING STRUCT VOID 
%token<val> MAIN IF ELSE WHILE BREAK RETURN ASSIGN
%token<val> ADDOP SUBOP MULOP DIVOP MODOP 
%token<val> OROP ANDOP NOTOP EQUOP NEQUOP SUPSOP INFSOP SUPOP INFOP
%token<val> LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE SEMI DOT COMMA 
%token <val> 	 ICONST
%token <val>  FCONST
%token <val> 	 CCONST
%token <val>     STRING
%token <symtab_item> ID
%token TABLE

/* rule (non-terminal) definitions */
%type <node> program
%type <node> declarations declaration
%type <data_type> type
%type <symtab_item> variable
%type <node> constant
%type <val> sign
%type <node> expression var_ref
%type <node> assigment

%start program

/* expression priorities and rules */

%%

program: structure { printf("\n FIN DE PROGRAMME AVEC SUCCESS \n");};

structure: declarations fonctions MAIN LPAREN RPAREN LBRACE {printf("\n Debut du programme principale a la ligne %d\n", lineno-1);} instructions RBRACE;


/* DECLARATION */
declarations: declarations declaration | declaration | /* vide */;

declaration: type { declare = 1; } names { declare = 0; } SEMI
    {
        int i;
        $$ = new_ast_decl_node($1, names, nc);
        nc = 0;

        AST_Node_Decl *temp = (AST_Node_Decl*) $$;

        // declare types of the names
        for(i=0; i < temp->names_count; i++){
            // variable
            if(temp->names[i]->st_type == UNDEF){
                set_type(temp->names[i]->st_name, temp->data_type, UNDEF);
            }
        }
        ast_traversal($$); /* pour tester les noeuds */
    }
	| STRUCT ID LBRACK declarations RBRACK SEMI	{printf(" \n Fin de declaration d'un enregistrement a la ligne %d\n", lineno);};

type: INT 		{  $$ = INT_TYPE;}
	| CHAR 		  { $$ = CHAR_TYPE;}
	| FLOAT 	  { $$ = FLOAT_TYPE;}
	| KSTRING 	{ $$ = STR_TYPE;}
;

names: 
	names COMMA variable
	{
		add_to_names($3);
	}
	| variable
	{
		add_to_names($1);
	}
;

variable: ID { $$ = $1; } | ID array;

array: array LBRACK ICONST RBRACK | LBRACK ICONST RBRACK ;

/* FONCTIONS */
fonctions: fonctions fonction | fonction | /* vide */;

fonction: fonction_head fonction_tail  {printf("\n Fin d'implementation d'une fonction a la ligne %d\n", lineno);};

// Pour incrementer le scope lors la déclaration d'une fonction
fonction: { incr_scope(); } fonction_head fonction_tail { hide_scope(); } ;

fonction_head: return_type ID LPAREN parameters RPAREN;

fonction_tail: LBRACE declarations instructions RBRACE;

return_type: type | VOID;

parameters: parameters SEMI parameter | parameter | /* vide */;

parameter : type input ;;

input : input COMMA variable | variable ;


/* INSTRUCTIONS */
instructions: instructions instruction | instruction | /* vide */;

instruction:
	if_instruction		{printf("\n fin de if instruction a la ligne %d\n", lineno);}
	| while_instruction	{printf("\n fin de while instruction a la ligne %d\n", lineno);}
	| assigment 		
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
	{ 
	  $$ = new_ast_arithm_node($2.ival, $1, $3);
		ast_traversal($$); /* just for testing */
	}	
	|expression SUBOP expression
	{
		$$ = new_ast_arithm_node(SUB, $1, $3);
		ast_traversal($$); /* just for testing */
	}
	|expression MULOP expression
	{
	  $$ = new_ast_arithm_node(MUL, $1, $3);
		ast_traversal($$); /* just for testing */
	} 	
	|expression DIVOP expression
	{
		$$ = new_ast_arithm_node(DIV, $1, $3);
		ast_traversal($$); /* just for testing */
	} 	
	|expression MODOP expression
	{
		$$ = new_ast_arithm_node(MOD, $1, $3);
		ast_traversal($$); /* just for testing */
	}
	|expression OROP expression
	{
		$$ = new_ast_bool_node(OR, $1, $3);
		ast_traversal($$); /* just for testing */
	}
	|expression ANDOP expression
	{
		$$ = new_ast_bool_node(AND, $1, $3);
		ast_traversal($$); /* just for testing */
	}
	|NOTOP expression
	{
	  $$ = new_ast_bool_node(NOT, $2, NULL);
		ast_traversal($$); /* just for testing */
	}
	|expression EQUOP expression 
	{
		$$ = new_ast_equ_node($2.ival, $1, $3);
		ast_traversal($$); /* just for testing */
	}	
	|expression NEQUOP expression
	 {
		$$ = new_ast_rel_node($2.ival, $1, $3);
		ast_traversal($$); /* just for testing */
	}
	|expression SUPSOP expression
	{
		$$ = new_ast_rel_node($2.ival, $1, $3);
		ast_traversal($$); /* just for testing */
	} 
	|expression INFSOP expression
	{
		$$ = new_ast_rel_node($2.ival, $1, $3);
		ast_traversal($$); /* just for testing */
	}
	|expression SUPOP expression
	{
		$$ = new_ast_rel_node($2.ival, $1, $3);
		ast_traversal($$); /* just for testing */
	}
	|expression INFOP expression
	{
		$$ = new_ast_rel_node($2.ival, $1, $3);
		ast_traversal($$); /* just for testing */
	}
	|LPAREN expression RPAREN
	{
		$$ = $2; /* just pass information */
	}
	|var_ref 
	{
		$$ = $1;
	}					
	|sign constant
	{
		{
		/* sign */
		if($1.ival == 1){
			AST_Node_Const *temp = (AST_Node_Const*) $2;

			/* inverse value depending on the constant type */
			switch(temp->const_type){
				case INT_TYPE:
					temp->val.ival *= -1;
					break;
				case FLOAT_TYPE:
					temp->val.fval *= -1;
					break;
				case CHAR_TYPE:
					/* sign before char error */
					fprintf(stderr,
					    "Error having sign before character constant!\n");
					exit(1);
					break;
			}
			$$ = (AST_Node*) temp;
		}
		/* no sign */
		else{
			$$ = $2;
		}
	    ast_traversal($$); /* just for testing */
	}
	}
	|fonction_call
	|struct_call	{printf("\n Acceder a un champ d'un enregistrement a la ligne %d\n", lineno);};
;

sign: ADDOP
	{ 
		/* plus sign error */
		if($1.ival == ADD){
			fprintf(stderr, "Error having plus as a sign!\n");
			exit(1);
		}
		else{
			$$.ival = 1; /* sign */
		}
	}
	| /* empty */
	{ 
		$$.ival = 0; /* no sign */
	} 
;

constant: 
		ICONST   { $$ = new_ast_const_node(INT_TYPE, $1);  }
	| FCONST { $$ = new_ast_const_node(FLOAT_TYPE, $1); }
	| CCONST { $$ = new_ast_const_node(CHAR_TYPE, $1); }
;

type_return : ICONST | FCONST | CCONST | STRING;

assigment: var_ref ASSIGN expression SEMI {
	AST_Node_Ref *temp = (AST_Node_Ref*) $1;
	$$ = new_ast_assign_node(temp->entry, temp->ref, $3);
	ast_traversal($$);

	// check assignment semantics
  get_result_type(
    get_type(temp->entry->st_name), /* variable datatype */
    expression_data_type($3),       /* expression datatype */
    NONE  /* checking compatibility only (no operator) */
  );
};

var_ref: variable
	{
		$$ = new_ast_ref_node($1, 0); /* no reference */
	}
; 

fonction_call: ID LPAREN call_params RPAREN		{printf("\n Appel d'une fonction a la ligne %d\n", lineno);};

call_params: call_param | /* vide */;

call_param : call_param COMMA variable | variable ;

struct_call : ID DOT variable;

%%

void yyerror ()
{
  fprintf(stderr, "Syntax error at line %d\n", lineno);
  exit(1);
}

void add_to_names(list_t *entry){
	// first entry
	if(nc == 0){
		nc = 1;
		names = (list_t **) malloc( 1 * sizeof(list_t *));
		names[0] = entry;
	}
	// general case
	else{
		nc++;
		names = (list_t **) realloc(names, nc * sizeof(list_t *));
		names[nc - 1] = entry;		
	}
}

void add_to_vals(Value val){
	// first entry
	if(vc == 0){
		vc = 1;
		vals = (Value *) malloc(1 * sizeof(Value));
		vals[0] = val;
	}
	// general case
	else{
		vc++;
		vals = (Value *) realloc(vals, vc * sizeof(Value));
		vals[vc - 1] = val;
	}
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
	fclose(yyin);

	// if(err_lex == 1){printf("err lexicale");}
	// else{printf("Success de l'analyse lexicale");}

	fclose(yyin);
	// printf("Parsing finished!");
	
	// symbol table dump
	yyout = fopen("table_symboles.out", "w");
	afficher_table(yyout);
	fclose(yyout);	
	
	
	return flag;
}