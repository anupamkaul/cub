#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symbols.h"

/* The hash function for converting
 * a string to an index
 */

int hash(char *s)
{
 int h= 0;
 for(; *s; s++)
 {
 h = h + 65991 + *s;
 }
 return (h % MAXINDEX);
}

/* Symbol - converts a string name to
 * a symbol structure. This symbol is
 * actually the index in the symbol table
 * of this name
 */

symbol Symbol(char *name)
{
 int index = hash(name);
 symbol sym;

 DBG("index in array = %d\n", index);

 for(sym = internal_array[index]; sym; sym=sym->next)
 {
	 if(strcmp(sym->name, name) == 0)
	 {
           DBG("[returning from lookup]\n");
	   return sym;
	 }
 }

 if(internal_array[index] != NULL)
 DBG("WARNING !!! SYMBOL COLLISION DETECTED !!!\n");
 
 sym = (symbol)malloc(sizeof(struct symbol_));
 if(sym==NULL) exit(1);
 sym->name = strdup(name);
 sym->next = internal_array[index];
 internal_array[index] = sym;

 return sym;
}

/* Function Name retrieves the name corresponding
 * to a given symbol.
 */

char *Name(symbol s)
{
 return s->name;
}

/* - TODO : Check that these are separate test suites for symbol conversion */

/*
main()
{
	symbol a;
	NULLIFY(internal_array, 0, MAXINDEX-1);

	a = Symbol("anupam");
	DBG("Symbol is 0x%x for %s\n", a, Name(a));

	a = Symbol("anupam1");
	DBG("Symbol is 0x%x for %s\n", a, Name(a));

	a = Symbol("anupam");
	DBG("Symbol is 0x%x\t%s\n", a, Name(a));

	a = Symbol("anupam2");
	DBG("Symbols is 0x%x\t%s\n", a, Name(a));

	a = Symbol("anupam");
	DBG("Symbol is 0x%x\t%s\n", a, Name(a));

	a = Symbol("anupam3");
	DBG("Symbol is 0x%x\t%s\n", a, Name(a));

	a = Symbol("anupam");
	DBG("Symbol is 0x%x\t%s\n", a, Name(a));

}
*/
