#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------------------AST NODE MANAGEMENT-------------------- */
/* The basic node */
AST_Node *new_ast_node(Node_Type type, AST_Node *left, AST_Node *right)
{
	// allocate memory
	AST_Node *v = malloc(sizeof(AST_Node));

	// set entries
	v->type = type;
	v->left = left;
	v->right = right;

	// return the result
	return v;
}

/* Declarations */

AST_Node *new_ast_decl_node(int data_type, list_t **names, int names_count)
{
	// allocate memory
	AST_Node_Decl *v = malloc(sizeof(AST_Node_Decl));

	// set entries
	v->type = DECL_NODE;
	v->data_type = data_type;
	v->names = names;
	v->names_count = names_count;

	// return type-casted result
	return (struct AST_Node *)v;
}

AST_Node *new_ast_const_node(int const_type, Value val)
{
	// allocate memory
	AST_Node_Const *v = malloc(sizeof(AST_Node_Const));

	// set entries
	v->type = CONST_NODE;
	v->const_type = const_type;
	v->val = val;

	// return type-casted result
	return (struct AST_Node *)v;
}

/* Statements */

AST_Node *new_ast_assign_node(list_t *entry, int ref, AST_Node *assign_val)
{
	// allocate memory
	AST_Node_Assign *v = malloc(sizeof(AST_Node_Assign));

	// set entries
	v->type = ASSIGN_NODE;
	v->entry = entry;
	v->ref = ref;
	v->assign_val = assign_val;

	// return type-casted result
	return (struct AST_Node *)v;
}

AST_Node *new_ast_arithm_node(enum Arithm_op op, AST_Node *left, AST_Node *right)
{
	// allocate memory
	AST_Node_Arithm *v = malloc(sizeof(AST_Node_Arithm));

	// set entries
	v->type = ARITHM_NODE;
	v->op = op;
	v->left = left;
	v->right = right;

	// set data type
	v->data_type = get_result_type(
			expression_data_type(left),	 /* data type of left expression */
			expression_data_type(right), /* data type of right expression */
			ARITHM_OP										 /* operation type */
	);

	// return type-casted result
	return (struct AST_Node *)v;
}

AST_Node *new_ast_bool_node(enum Bool_op op, AST_Node *left, AST_Node *right)
{
	// allocate memory
	AST_Node_Bool *v = malloc(sizeof(AST_Node_Bool));

	// set entries
	v->type = BOOL_NODE;
	v->op = op;
	v->left = left;
	v->right = right;

	// set data type
	if (v->op != NOT)
	{ /* AND or OR */
		v->data_type = get_result_type(
				expression_data_type(left),	 /* data type of left expression */
				expression_data_type(right), /* data type of right expression */
				BOOL_OP											 /* operation type */
		);
	}
	else
	{ /* NOT */
		v->data_type = get_result_type(
				expression_data_type(left), /* data type of left expression */
				UNDEF,											/* there is no right expression */
				NOT_OP											/* operation type */
		);
	}

	// return type-casted result
	return (struct AST_Node *)v;
}

AST_Node *new_ast_rel_node(enum Rel_op op, AST_Node *left, AST_Node *right)
{
	// allocate memory
	AST_Node_Rel *v = malloc(sizeof(AST_Node_Rel));

	// set entries
	v->type = REL_NODE;
	v->op = op;
	v->left = left;
	v->right = right;

	// set data type
	v->data_type = get_result_type(
			expression_data_type(left),	 /* data type of left expression  */
			expression_data_type(right), /* data type of right expression */
			REL_OP											 /* operation type */
	);

	// return type-casted result
	return (struct AST_Node *)v;
}

AST_Node *new_ast_equ_node(enum Equ_op op, AST_Node *left, AST_Node *right)
{
	// allocate memory
	AST_Node_Equ *v = malloc(sizeof(AST_Node_Equ));

	// set entries
	v->type = EQU_NODE;
	v->op = op;
	v->left = left;
	v->right = right;

	// set data type
	v->data_type = get_result_type(
			expression_data_type(left),	 /* data type of left expression  */
			expression_data_type(right), /* data type of right expression */
			EQU_OP											 /* operation type */
	);

	// return type-casted result
	return (struct AST_Node *)v;
}

AST_Node *new_ast_ref_node(list_t *entry, int ref)
{
	// allocate memory
	AST_Node_Ref *v = malloc(sizeof(AST_Node_Ref));

	// set entries
	v->type = REF_NODE;
	v->entry = entry;
	v->ref = ref;

	// return type-casted result
	return (struct AST_Node *)v;
}

int expression_data_type(AST_Node *node)
{
	/* temp nodes */
	AST_Node_Arithm *temp_arithm;
	AST_Node_Bool *temp_bool;
	AST_Node_Rel *temp_rel;
	AST_Node_Equ *temp_equ;
	AST_Node_Ref *temp_ref;
	AST_Node_Const *temp_const;

	/* return type depends on the AST node type */
	switch (node->type)
	{
	case ARITHM_NODE: /* arithmetic expression */
		temp_arithm = (AST_Node_Arithm *)node;
		return temp_arithm->data_type;
		break;

	case BOOL_NODE: /* boolean expression */
		temp_bool = (AST_Node_Bool *)node;
		return temp_bool->data_type;
		break;

	case REL_NODE: /* relational expression */
		temp_rel = (AST_Node_Rel *)node;
		return temp_rel->data_type;
		break;

	case EQU_NODE: /* equality expression */
		temp_equ = (AST_Node_Equ *)node;
		return temp_equ->data_type;
		break;

	case REF_NODE: /* identifier reference */
		temp_ref = (AST_Node_Ref *)node;
		/* if "simple" type */
		int type = temp_ref->entry->st_type;
		if (type == INT_TYPE || type == FLOAT_TYPE || type == CHAR_TYPE)
		{
			return temp_ref->entry->st_type;
		}
		/* if array or pointer */
		else
		{
			return temp_ref->entry->inf_type;
		}
		break;

	case CONST_NODE: /* constant */
		temp_const = (AST_Node_Const *)node;
		return temp_const->const_type; /* constant data type */
		break;

	default: /* wrong choice case */
		fprintf(stderr, "Error in node selection!\n");
		exit(1);
	}
}

/* Tree Traversal */
void ast_print_node(AST_Node *node)
{
	/* temp nodes */
	AST_Node_Decl *temp_decl;
	AST_Node_Const *temp_const;
	AST_Node_Assign *temp_assign;
	AST_Node_Arithm *temp_arithm;
	AST_Node_Bool *temp_bool;
	AST_Node_Rel *temp_rel;
	AST_Node_Equ *temp_equ;
	AST_Node_Ref *temp_ref;

	switch (node->type)
	{
	case BASIC_NODE:
		printf("Basic Node\n");
		break;
	case DECL_NODE:
		temp_decl = (struct AST_Node_Decl *)node;
		printf("\n Declaration d'un noeud de type %d avec %d variables\n",
					 temp_decl->data_type, temp_decl->names_count);
		break;
	case CONST_NODE:
		temp_const = (struct AST_Node_Const *)node;
		printf("\n Un noeud constant  avec la valeur ");
		switch (temp_const->const_type)
		{
		case INT_TYPE:
			printf("%d\n", temp_const->val.ival);
			break;
		case FLOAT_TYPE:
			printf("%.2f\n", temp_const->val.fval);
			break;
		case CHAR_TYPE:
			printf("%c\n", temp_const->val.cval);
			break;
		case STR_TYPE:
			printf("%s\n", temp_const->val.sval);
			break;
		}
		break;
	case ASSIGN_NODE:
		temp_assign = (struct AST_Node_Assign *)node;
		printf("\n Assigner un noeud d'une entree %s\n", temp_assign->entry->st_name);
		break;
	case ARITHM_NODE:
		temp_arithm = (struct AST_Node_Arithm *)node;
		printf("\n Arithmetic Node of operator %d with result type %d\n", temp_arithm->op, temp_arithm->data_type);
		break;
	case BOOL_NODE:
		temp_bool = (struct AST_Node_Bool *)node;
		printf("\n Boolean Node of operator %d\n", temp_bool->op);
		break;
	case REL_NODE:
		temp_rel = (struct AST_Node_Rel *)node;
		printf("\n Relational Node of operator %d\n", temp_rel->op);
		break;
	case EQU_NODE:
		temp_equ = (struct AST_Node_Equ *)node;
		printf("\n Equality Node of operator %d\n", temp_equ->op);
		break;
	case REF_NODE:
		temp_ref = (struct AST_Node_Ref *)node;
		printf("\n Reference Node of entry %s\n", temp_ref->entry->st_name);
		break;
	default: /* wrong choice case */
		fprintf(stderr, "Error in node selection!\n");
		exit(1);
	}
}

void ast_traversal(AST_Node *node)
{
	int i;

	/* check if empty */
	if (node == NULL)
	{
		return;
	}

	/* left and right child cases */
	if (node->type == BASIC_NODE || node->type == ARITHM_NODE || node->type == BOOL_NODE || node->type == REL_NODE || node->type == EQU_NODE)
	{
		//ast_traversal(node->left);
		//ast_traversal(node->right);
		ast_print_node(node); // postfix
	}
	/* assign case */
	else if (node->type == ASSIGN_NODE)
	{
		AST_Node_Assign *temp_assign = (struct AST_Node_Assign *)node;
		ast_print_node(node);
		printf("\n Assigning:\n");
		ast_traversal(temp_assign->assign_val);
	}
	/* others */
	else
	{
		ast_print_node(node);
	}
}
