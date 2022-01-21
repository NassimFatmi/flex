#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "semantics.h"

// verifier la compatibilité des opérateurs
// type1 operateur type2
int get_result_type(int type_1, int type_2, int op_type)
{
	switch (op_type)
	{
	// pour les opérations d'affectation
	case NONE:
		if (type_1 == INT_TYPE)
		{
			if (type_2 == INT_TYPE || type_2 == CHAR_TYPE)
			{
				return 1;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		else if (type_1 == FLOAT_TYPE)
		{
			if (type_2 == INT_TYPE || type_2 == FLOAT_TYPE || type_2 == CHAR_TYPE)
			{
				return 1;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		// first type CHAR
		else if (type_1 == CHAR_TYPE)
		{
			// second type INT or CHAR
			if (type_2 == INT_TYPE || type_2 == CHAR_TYPE)
			{
				return 1;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		break;
	/* ---------------------------------------------------------- */
	case ARITHM_OP: /* arithmetic operator */
		// first type INT
		if (type_1 == INT_TYPE)
		{
			// second type INT or CHAR
			if (type_2 == INT_TYPE || type_2 == CHAR_TYPE)
			{
				return INT_TYPE;
			}
			// second type REAL
			else if (type_2 == FLOAT_TYPE)
			{
				return FLOAT_TYPE;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		// first type REAL
		else if (type_1 == FLOAT_TYPE)
		{
			// second type INT, REAL or CHAR
			if (type_2 == INT_TYPE || type_2 == FLOAT_TYPE || type_2 == CHAR_TYPE)
			{
				return FLOAT_TYPE;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		// first type CHAR
		else if (type_1 == CHAR_TYPE)
		{
			// second type INT or CHAR
			if (type_2 == INT_TYPE || type_2 == CHAR_TYPE)
			{
				return CHAR_TYPE;
			}
			// second type REAL
			else if (type_2 == FLOAT_TYPE)
			{
				return FLOAT_TYPE;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		else
		{
			type_error(type_1, type_2, op_type);
		}
		break;
	/* ---------------------------------------------------------- */
	case NOT_OP: /* special case of NOTOP */
		// type INT
		if (type_1 == INT_TYPE)
		{
			return INT_TYPE;
		}
		// type CHAR
		else if (type_1 == CHAR_TYPE)
		{
			return INT_TYPE;
		}
		else
		{
			type_error(type_1, type_2, op_type);
		}
		break;
	/* ---------------------------------------------------------- */
	case REL_OP: /* Relational operator */
		// first type INT
		if (type_1 == INT_TYPE)
		{
			// second type INT, REAL or CHAR
			if (type_2 == INT_TYPE || type_2 == FLOAT_TYPE || type_2 == CHAR_TYPE)
			{
				return INT_TYPE;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		else if (type_1 == FLOAT_TYPE)
		{
			// second type INT, REAL or CHAR
			if (type_2 == INT_TYPE || type_2 == FLOAT_TYPE || type_2 == CHAR_TYPE)
			{
				return INT_TYPE;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		// first type CHAR
		else if (type_1 == CHAR_TYPE)
		{
			// second type INT, REAL or CHAR
			if (type_2 == INT_TYPE || type_2 == FLOAT_TYPE || type_2 == CHAR_TYPE)
			{
				return INT_TYPE;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		else
		{
			type_error(type_1, type_2, op_type);
		}
		break;
	/* ---------------------------------------------------------- */
	case EQU_OP: /* Equality operator */
		// first type INT
		if (type_1 == INT_TYPE)
		{
			// second type INT or CHAR
			if (type_2 == INT_TYPE || type_2 == CHAR_TYPE)
			{
				return INT_TYPE;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		else if (type_1 == FLOAT_TYPE)
		{
			// second type REAL
			if (type_2 == FLOAT_TYPE)
			{
				return INT_TYPE;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		// first type CHAR
		else if (type_1 == CHAR_TYPE)
		{
			// second type INT or CHAR
			if (type_2 == INT_TYPE || type_2 == CHAR_TYPE)
			{
				return INT_TYPE;
			}
			else
			{
				type_error(type_1, type_2, op_type);
			}
		}
		else
		{
			type_error(type_1, type_2, op_type);
		}
		break;
	/* ---------------------------------------------------------- */
	default: /* wrong choice case */
		fprintf(stderr, "Error in operator selection!\n");
		exit(1);
	}
}

void type_error(int type_1, int type_2, int op_type)
{ /* print type error */
	fprintf(stderr, "Type conflict between %d and %d using op type %d\n", type_1, type_2, op_type);
	exit(1);
}