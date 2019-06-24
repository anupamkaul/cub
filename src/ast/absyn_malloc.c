/* Some general utilities
 * for the compiler
 */

#include <stdio.h>
#include <stdlib.h>
#include "absyn.h"

A_var Vmalloc(int c)
{
	A_var  x = (A_var)malloc(sizeof(struct a_var_));
	if(x==NULL) 
	{
		switch(c) {

		case 1:
		printf("AST: no memory to allocate simple var\n");
		exit(1);
		break;

		case 2:
		printf("AST: no memory to allocate simple var\n");
		exit(1);
		break;

		case 3:
		printf("AST: no memory to allocate simple var\n");
		exit(1);
		break;
			
		default:
		printf("AST: var: unknown type\n");
		break;
		}
	}
	return x;
}

A_exp Emalloc()
{
	A_exp x = (A_exp)malloc(sizeof(struct a_exp_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate expression\n");
		exit(1);
	}
	//printf("size of struct exp = %d\n", sizeof(struct a_exp_)); 
	return x;
}

A_decList decListmalloc()
{
	A_decList x = (A_decList)malloc(sizeof(struct a_decList_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_decList\n");
		exit(1);
	}
	return x;
}

A_dec decmalloc()
{
	A_dec x = (A_dec)malloc(sizeof(struct a_dec_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_dec\n");
		exit(1);
	}
	return x;
}

A_fundecList FundecListmalloc()
{
	A_fundecList x = (A_fundecList)malloc(sizeof(struct a_fundecList_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_fundecList\n");
		exit(1);
	}
	return x;
}

A_fundec fundecmalloc()
{
	A_fundec x = (A_fundec)malloc(sizeof(struct a_fundec_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_fundec\n");
		exit(1);
	}
	return x;
}

A_field fieldmalloc()
{
	A_field x = (A_field)malloc(sizeof(struct a_field_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_field\n");
		exit(1);
	}
	return x;
}

A_fieldList fieldListmalloc()
{
	A_fieldList x = (A_fieldList)malloc(sizeof(struct a_fieldList_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_fieldList\n");
		exit(1);
	}
	return x;
}

A_ty tymalloc()
{
	A_ty x = (A_ty)malloc(sizeof(struct a_ty_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_ty\n");
		exit(1);
	}
	return x;
}

A_namety nametymalloc()
{
	A_namety x = (A_namety)malloc(sizeof(struct a_namety_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_namety\n");
		exit(1);
	}
	return x;
}

A_nametyList nametyListmalloc()
{
	A_nametyList x = (A_nametyList)malloc(sizeof(struct a_nametylist_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_nametyList\n");
		exit(1);
	}
	return x;
}
A_explist explistmalloc()
{
	A_explist x = (A_explist)malloc(sizeof(struct a_explist_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_explist\n");
		exit(1);
	}
	return x;
}

A_efieldList efieldListmalloc()
{
	A_efieldList x = (A_efieldList)malloc(sizeof(struct a_efieldList_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate E_fieldList\n");
		exit(1);
	}
	return x;
}

A_efield efieldmalloc()
{
	A_efield x = (A_efield)malloc(sizeof(struct a_efield_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate E_field\n");
		exit(1);
	}
	return x;
}

A_pos  aposmalloc()
{
	A_pos x = (A_pos)malloc(sizeof(struct a_pos_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate A_pos\n");
		exit(1);
	}
	//printf("size of pos struct: %d bytes\n", sizeof(struct a_pos_));
	return x;
}

A_expstack estackmalloc()
{
	A_expstack x = (A_expstack)malloc(sizeof(struct a_expstack_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate expression-pointer stack\n");
		exit(1);
	}
	return x;

}

A_varstack vstackmalloc()
{
	A_varstack x = (A_varstack)malloc(sizeof(struct a_varstack_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate variable-pointer stack\n");
		exit(1);
	}
	return x;

}


int* A_intdup(int s)
{
	int* x = (int *)malloc(sizeof(int));
	if(x==NULL)
	{
		printf("AST: no memory for A_intdup\n");
		exit(1);
	}
	*x=s;
	return x;
}

A_tylistStack tylist_Stackmalloc()
{
	A_tylistStack x = (A_tylistStack)malloc(sizeof(struct a_tylistStack_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate tyList-pointer stack\n");
		exit(1);
	}
	return x;
}

A_vardecStack vardec_Stackmalloc()
{
	A_vardecStack x = (A_vardecStack)malloc(sizeof(struct a_vardecStack_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate vardec-pointer stack\n");
		exit(1);
	}
	return x;
}

A_explistStack A_explistStack_malloc()
{
	A_explistStack x = (A_explistStack)malloc(sizeof(struct a_explistStack_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate explist-pointer stack\n");
		exit(1);
	}
	return x;
}

A_mutrecFnstate   A_mutrecFnstate_malloc()
{
	A_mutrecFnstate x = (A_mutrecFnstate)malloc(sizeof(struct a_mutrecFnstate_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate mutrecFnstate stack\n");
		exit(1);
	}
	return x;


}

A_fundeclistStack   fundeclist_Stackmalloc()
{
	A_fundeclistStack x = (A_fundeclistStack)malloc(sizeof(struct a_fundeclistStack_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate mutrecFnstate stack\n");
		exit(1);
	}
	return x;


}

A_declistStack A_declistStack_malloc()
{
	A_declistStack x = (A_declistStack)malloc(sizeof(struct a_declistStack_));
	if(x==NULL)
	{
		printf("AST: no memory to allocate mutrecFnstate stack\n");
		exit(1);
	}
	return x;


}
  
/* End of absyn_malloc.c */
