/* Symbols.c
 *
 * Implementation of hashing 
 * of symbols (strings)
 *
 */

#include <stdio.h>
#include "symbols.h"

typedef unsigned int HASHVAL;

struct S_symbol_ {
STR name;
S_symbol next;
};

/* inserts new symbol to leftmost (start) of the chain (LIFO) */
S_symbol mkSymbol(STR name, S_symbol next)
{
	S_symbol s = (struct S_symbol_ *)malloc(sizeof(struct S_symbol_));
        if(s==NULL) exit();
	s->name=name;
	s->next=next;
	return s;
}

#define SIZE 109
static S_symbol hashtable[SIZE];

/* calculates an unsigned int val from a string (hash index to table) */
static HASHVAL hash(char*  s0)
{
	HASHVAL h=0;
	char* s;

	for(s=s0; *s; s++)
	{
		h = h*65599 + *s;
	}

return (h%SIZE);
}

/* The 'constructor' function for this DO.
 * It does both hash-insertion and
 * hash-lookup for a 'Symbol' ...
 */

S_symbol S_Symbol(STR name)
{
	HASHVAL index = hash(name);

        /* ptr to list */
	S_symbol syms=hashtable[index];
	S_symbol sym;

	/*lookup in linear list of table*/
        for(sym=syms; sym; sym=sym->next)
	{
		if(0==strcmp(name, sym->name))
		return sym;
	}

	/*insert new element at this list*/
	sym = mkSymbol(name, syms);
	hashtable[index]=sym;
	return sym;
}

/*test*/

main()
{
S_symbol test = S_Symbol("Anupam");
}











