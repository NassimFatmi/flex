/* ---------------------NODE TYPES-------------------------- */

typedef enum Node_Type
{
	BASIC_NODE, // no special usage (for roots only)
	// declarations
	DECL_NODE,	// declaration
	CONST_NODE, // constant
	// statements
	IF_NODE,		 // if statement
	WHILE_NODE,	 // while statement
	ASSIGN_NODE, // assigment
	// expressions
	ARITHM_NODE, // arithmetic expression
	BOOL_NODE,	 // boolean expression
	REL_NODE,		 // relational expression
	EQU_NODE,		 // equality expression
} Node_Type;

/* --------------------OPERATOR TYPES----------------------- */

typedef enum Arithm_op
{
	ADD, // + operator
	SUB, // - operator
	MUL, // * operator
	MOD, // % operator
	DIV, // / operator
	INC, // ++ operator
	DEC, // -- operator
} Arithm_op;

typedef enum Bool_op
{
	OR,	 // || operator
	AND, // && operator
	NOT	 // ! operator
} Bool_op;

typedef enum Rel_op
{
	GREATER,			 // > operator
	LESS,					 // < operator
	GREATER_EQUAL, // >= operator
	LESS_EQUAL		 // <= operator
} Rel_op;

typedef enum Equ_op
{
	EQUAL,		// == operator
	NOT_EQUAL // != operator
} Equ_op;

/* -----------------------AST NODES------------------------- */

/* The basic node */
typedef struct AST_Node
{
	enum Node_Type type;		// node type
	struct AST_Node *left;	// left child
	struct AST_Node *right; // right child
} AST_Node;

/* Declarations */
typedef struct AST_Node_Decl
{
	enum Node_Type type; // node type

	// data type
	int data_type;

	// symbol table entries of the variables
	list_t **names;
	int names_count;
} AST_Node_Decl;

typedef struct AST_Node_Const
{
	enum Node_Type type; // node type

	// data type
	int const_type;

	// constant value
	Value val;
} AST_Node_Const;

/* Statements */
typedef struct AST_Node_If
{
	enum Node_Type type; // node type

	// condition
	struct AST_Node *condition;

	// if branch
	struct AST_Node *if_branch;

	// else if branches
	struct AST_Node **elsif_branches;
	int elseif_count;

	// else branch
	struct AST_Node *else_branch;
} AST_Node_If;

typedef struct AST_Node_While
{
	enum Node_Type type; // node type

	// condition
	struct AST_Node *condition;

	// branch
	struct AST_Node *while_branch;
} AST_Node_While;

typedef struct AST_Node_Assign
{
	enum Node_Type type; // node type

	// symbol table entry
	list_t *entry;

	// assignment value
	struct AST_Node *assign_val;
} AST_Node_Assign;

/* Expressions */
typedef struct AST_Node_Arithm
{
	enum Node_Type type; // node type

	// operator
	enum Arithm_op op;

	struct AST_Node *left;	// left child
	struct AST_Node *right; // right child
} AST_Node_Arithm;

typedef struct AST_Node_Bool
{
	enum Node_Type type; // node type

	// operator
	enum Bool_op op;

	struct AST_Node *left;	// left child
	struct AST_Node *right; // right child
} AST_Node_Bool;

typedef struct AST_Node_Rel
{
	enum Node_Type type; // node type

	// operator
	enum Rel_op op;

	struct AST_Node *left;	// left child
	struct AST_Node *right; // right child
} AST_Node_Rel;

typedef struct AST_Node_Equ
{
	enum Node_Type type; // node type

	// operator
	enum Equ_op op;

	struct AST_Node *left;	// left child
	struct AST_Node *right; // right child
} AST_Node_Equ;
/* ------------------AST NODE MANAGEMENT-------------------- */

/* The basic node */
AST_Node *new_ast_node(Node_Type type, AST_Node *left, AST_Node *right); // simple nodes

/* Declarations */
AST_Node *new_ast_decl_node(int data_type, list_t **names, int names_count); // declaration
AST_Node *new_ast_const_node(int const_type, Value val);										 // constant

/* Statements */
AST_Node *new_ast_if_node(AST_Node *condition, AST_Node *if_branch, AST_Node **elsif_branches,
													int elseif_count, AST_Node *else_branch);
AST_Node *new_ast_while_node(AST_Node *condition, AST_Node *while_branch);
AST_Node *new_ast_assign_node(list_t *entry, AST_Node *assign_val);
AST_Node *new_ast_simple_node(int statement_type);																	 // continue, break or "main" return

/* Expressions */
AST_Node *new_ast_arithm_node(enum Arithm_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_bool_node(enum Bool_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_rel_node(enum Rel_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_equ_node(enum Equ_op op, AST_Node *left, AST_Node *right);

/* Tree Traversal */
void ast_print_node(AST_Node *node); // print information of node
void ast_traversal(AST_Node *node);	 // tree traversal (for testing right now)