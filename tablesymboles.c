#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNDEF 0
#define INT_TYPE 1
#define FLOAT_TYPE 2
#define STR_TYPE 3
#define CHAR_TYPE 4
#define ARRAY_TYPE 5
#define FUNCTION_TYPE 6

typedef struct RefList{ 
    int lineno;
    struct RefList *next;
}RefList;

typedef struct list_t{
	char st_name[40];
    int st_size;
    RefList *lines;
    int st_type;
	struct list_t *next;
}list_t;

static list_t **hash_table;

void init_hash_table(); 
unsigned int hash(char *key); 
void insert(char *name, int len, int type, int lineno); 
void affiche_table(FILE *of);

//////////////////////////////////////////////////

void init_hash_table(){
	int i; 
	hash_table = malloc(200 * sizeof(list_t*));
	for(i = 0; i < 200; i++) hash_table[i] = NULL;
}

unsigned int hash(char *key){
	unsigned int hashval = 0;
	for(;*key!='\0';key++) hashval += *key;
	hashval += key[0] % 11 + (key[0] << 3) - key[0];
	return hashval % 200;
}

void insert(char *name, int len, int type, int lineno){
	unsigned int hashval = hash(name);
	list_t *l = hash_table[hashval];
	
	while ((l != NULL) && (strcmp(name,l->st_name) != 0)) l = l->next;
	
	if (l == NULL){
		l = (list_t*) malloc(sizeof(list_t));
		strcpy(l->st_name, name);  
		l->st_type = type;
		l->lines = (RefList*) malloc(sizeof(RefList));
		l->lines->lineno = lineno;
		l->lines->next = NULL;
		l->next = hash_table[hashval];
		hash_table[hashval] = l; 
		printf("Inserted < %s > for the first time with linenumber %d!\n", name, lineno); 
	}
	else{
		RefList *t = l->lines;
		while (t->next != NULL) t = t->next;
		t->next = (RefList*) malloc(sizeof(RefList));
		t->next->lineno = lineno;
		t->next->next = NULL;
		printf("Found %s again at line %d!\n", name, lineno);
	}
}

void affiche_table(FILE * of){  
  int i;
  fprintf(of,"------------ ------ ------------\n");
  fprintf(of,"Name         Type   Line Numbers\n");
  fprintf(of,"------------ ------ -------------\n");
  for (i=0; i < 200; ++i){ 
	if (hash_table[i] != NULL){ 
		list_t *l = hash_table[i];
		while (l != NULL){ 
			RefList *t = l->lines;
			printf(l->st_name);
			fprintf(of,"%-12s ",l->st_name);
			if (l->st_type == INT_TYPE) fprintf(of,"%-7s","int");
			else if (l->st_type == FLOAT_TYPE) fprintf(of,"%-7s","float");
			else if (l->st_type == STR_TYPE) fprintf(of,"%-7s","string");
			else if (l->st_type == CHAR_TYPE) fprintf(of,"%-7s","char");
			else if (l->st_type == UNDEF) fprintf(of,"%-7s","ID"); 
			while (t != NULL){
				fprintf(of,"%4d ",t->lineno);
			t = t->next;
			}
			fprintf(of,"\n");
			l = l->next;
		}
    }
  }
}
