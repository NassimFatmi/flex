/* ---------------------NODE TYPES-------------------------- */

typedef enum Node_Type
{
	BASIC_NODE, // no special usage (for roots only)
	// declarations
	DECL_NODE,	// declaration
	CONST_NODE, // constant
	// statements
	ASSIGN_NODE, // assigment
	// expressions
	ARITHM_NODE, // arithmetic expression
	BOOL_NODE,	 // boolean expression
	REL_NODE,		 // relational expression
	EQU_NODE,		 // equality expression
	REF_NODE,
} Node_Type;

/* --------------------OPERATOR TYPES----------------------- */

typedef enum Arithm_op
{
	ADD, // + operator
	SUB, // - operator
	MUL, // * operator
	MOD, // % operator
	DIV, // / operator
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

typedef struct AST_Node_Assign
{
	enum Node_Type type; // node type

	// symbol table entry
	list_t *entry;

	// reference or not
	int ref; // 0: not reference, 1: reference

	// assignment value
	struct AST_Node *assign_val;
} AST_Node_Assign;
/* Expressions */
typedef struct AST_Node_Arithm
{
	enum Node_Type type; // node type

	// data type of result
	int data_type;

	// operator
	enum Arithm_op op;

	struct AST_Node *left;	// left child
	struct AST_Node *right; // right child
} AST_Node_Arithm;

typedef struct AST_Node_Bool
{
	enum Node_Type type; // node type

	// data type of result
	int data_type;

	// operator
	enum Bool_op op;

	struct AST_Node *left;	// left child
	struct AST_Node *right; // right child
} AST_Node_Bool;

typedef struct AST_Node_Ref
{
	enum Node_Type type; // node type

	// symbol table entry
	list_t *entry;

	// reference or not1
	int ref; // 0: not reference, 1: reference
} AST_Node_Ref;

typedef struct AST_Node_Rel
{
	enum Node_Type type; // node type

	// data type of result
	int data_type;

	// operator
	enum Rel_op op;

	struct AST_Node *left;	// left child
	struct AST_Node *right; // right child
} AST_Node_Rel;

typedef struct AST_Node_Equ
{
	enum Node_Type type; // node type

	// data type of result
	int data_type;

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

/* Expressions */
AST_Node *new_ast_arithm_node(enum Arithm_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_bool_node(enum Bool_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_rel_node(enum Rel_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_equ_node(enum Equ_op op, AST_Node *left, AST_Node *right);
AST_Node *new_ast_ref_node(list_t *entry, int ref);
int expression_data_type(AST_Node *node);

/* Tree Traversal */
void ast_print_node(AST_Node *node); // print information of node
void ast_traversal(AST_Node *node);	 // tree traversal (for testing right now)
