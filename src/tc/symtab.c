#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "symtab.h"

/** symtab.c - This module contains the implementation
 * of the symbol table implemented for the tiger
 * compiler.
 */

/* Symbol table - The table is a  list of table-entries. 
 * Table is dyanamically allocated consecutive mem chunks
 * for table expansion in case of too many collisions. 
 *
 * Each table entry is defined in symtab.h. It stores
 * the symbol and its binding. 
 *
 * The symbol structure (symbol.h) is converted to an index 
 * using its address. This index corresponds to an element
 * of the symbol table (symtab.h)
 *
 * This file contains the realization of the symbol table
 * and its manipulation functions for realizing symbol
 * insertions/lookup and scope/binding issues.
 *
 */

#define TableEntry(t,s)      Entry((t), sym2index((s)))

#define BeginScope           stackpush_internal(Symbol("__START_MARK"))
#define EndScope(t)          TAB_pop((t))

/* We keep a global stack in ram, to remember the recent symbols
 * that were inserted per scope. This helps in the destructive
 * update of the table per scope.
 *
 * Note - This stack must be deleted once its usage is over,
 * so include its initialization in a function.
 */

sym_stack_internal gbsym_stack=NULL;

/* 
 * Function declarations (internal)
 */

INDEX sym2index(symbol sym);
tableEntry Entry(table t, int index);

void stackpush_internal(symbol sym);
symbol stackpop_internal();

/* 
 * Function definitions
 */

/* Function sym2index converts the address
 * of the struct 'sym' (symbol.h/.c) to an
 * index which lies within our symbol table
 * (symtab.h, table)
 */

INDEX sym2index(symbol sym)
{
  fprintf(stderr, "sym2index = %d\n", (int)((int)sym % MAX_SYMBOLS));
  return (int)((int)sym % MAX_SYMBOLS);
}

/* Function Entry returns an element from
 * the symbol table, based on its index.
 *
 * The implementation treats the table
 * like an array of contiguously allocated
 * elements.
 */

tableEntry Entry(table t, int index)
{
	if((index==0) || (index>MAX_SYMBOLS)) exit(1);

	/* test address range */

        fprintf(stderr, "(Entry) ADDRESS OF INDEX %d = 0x%p (of table 0x%p)\n", index, (t + (index-1)) , t);
	
	//return (t + (index-1))->entry; why did this not work?
	return (tableEntry)(t + (index-1));
}

/* The first tableEntry for any index has to be a dummy start,
 * because it needs to always contain the fixed pointer
 * reference to the collision list generated for this
 * index. (Since we access index in a hardcoded way now)
 */

/* Enter a symbol and binding in a table */
void TAB_enter(table t, symbol s, bvalue b)
{
	/* create entry */
	tableEntry e = (tableEntry)malloc(sizeof(struct tableEntry_));
	e->s = s;
	e->b = b;

	fprintf(stderr, "Name, inserted = %s (or symbol 0x%p)\n", e->s->name, e->s);

	/* link with table */

	/* Get dummy start address for this index */
	/* the real list is pointed from d->next */
	tableEntry d = TableEntry(t, s);

	e->next = d->next;
	d->next = e; 

	/* update internal stack */
	stackpush_internal(s);
}

/* Create a new table */
table TAB_empty()
{
	/* allocate runtime array */
	/* is it contiguous? */

	table t = (table)malloc(MAX_SYMBOLS * sizeof(struct table_));
	if(t == NULL)
	{
	 exit(1);
	}

	t->L_Add = (unsigned int)t;
	t->H_Add = (unsigned int)(t + (MAX_SYMBOLS * sizeof(struct table_)));

	fprintf(stderr, "[symtab]: TABLE AREA ALLOCATED FROM LOW = 0x%x (0x%p) TO HIGH = 0x%x\n", t->L_Add, t, t->H_Add);
	fprintf(stderr, "[symtab]: No. of bytes allocated = %d\n", MAX_SYMBOLS * sizeof(struct table_));

	/* nullify all pointers before returning (shd be managed by client s/w) */
	return t;

	/* in order to test for contiguousness, let every
	 * table obj also contain 2 fields H_Add and L_Add,
	 * which can be filled up at this point, and should
	 * be checked at TableEntry, when linking a new
	 * entry with the table.
	 */
}

/* lookup a binding for a symbol in a table */
bvalue TAB_lookup(table t, symbol s)
{
	tableEntry d = TableEntry(t, s)->next;
	/* as the real list begins from d->next */

	while(d != NULL)
	{
		/* simple pointer comparison */
		if(d->s == s)
		{
		fprintf(stderr, "LOOKUP, symbol found 0x%p for name %s\n", d->s, d->s->name);
		return d->b;
		}
		d=d->next;
	}

	/* should not come here; wrong index calculation */
	fprintf(stderr, "[TAB_lookup] Wrong Index Calculation (or Symbol not Found): 0x%p !\n", s);
	//exit(0);
}

/* remove the symbol's last binding from this table */
void TAB_desupdate(table t, symbol s)
{
	tableEntry d = TableEntry(t, s);
	tableEntry e;

	/* note - the real list begins from d->next */

	/* remove 2nd ele from list, if it exists */
	/* do we need to check for the NULL case, replace by assert? */

	if(d->next != NULL)
	{
		e = d->next;
		d->next = e->next;
		free(e); /* prob. a hole now */
	}
	else
	{
	fprintf(stderr, "WARNING !! REMOVING A SYMBOL (0x%p) THAT DOES NOT EXIST !!\n", s);
	}
}

/* remove the recent bindings in this table */
void TAB_pop(table t)
{
	symbol s, start=Symbol("__START_MARK");
	while((s = stackpop_internal()) != start)
	{
		TAB_desupdate(t, s);
	}
}

/* functions for the movement of the internal symbol stack */
void stackpush_internal(symbol s)
{
	sym_stack_internal n = (sym_stack_internal)malloc(sizeof(struct sym_stack_internal_));
        n->s = s;
	n->next = gbsym_stack;
	gbsym_stack = n;
}

symbol stackpop_internal()
{
	symbol s;
	if(gbsym_stack == NULL) 
	{	
		DBG("!!internal stack empty!!\n");
		exit(1);
	}
	s = gbsym_stack->s;
	gbsym_stack = gbsym_stack->next;
	return s;
}

#if 0

/* revive main.c to check this file
 * or include in a test.
 */

main()
{

	 /* 1. Tests from the main of symbol.c: */

	int i;
	bvalue b;
	symbol a, c[10] = {
		Symbol("TastyPizza"), Symbol("TatsyPienza"),
		Symbol("TumpyPiaza"), Symbol("DumplingDumpling"),
		Symbol("Vanarsena"), Symbol("Dhanarashi"),
		Symbol("Kadambari"), Symbol("VastuShashtra"),
		Symbol("Aayojana"), Symbol("Vidhambana")
	};

	/* Note - need to call this array for symbols ? */
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

	 /* 2. Tests from the main of symtab.c */

	 table test1 = TAB_empty();
	 printf("ADDRESS RANGE OF test1 = 0x%x to 0x%x\n", test1->L_Add, test1->H_Add);

	 /* enter some elements */
	 BeginScope;
	 TAB_enter(test1, Symbol("TastyPizza"), (void*)0);
	 TAB_enter(test1, Symbol("TatsyPinza"), (void*)0);
	 TAB_enter(test1, Symbol("TastiPimza"), (void*)0);
	 TAB_enter(test1, Symbol("TsatyPidza"), (void*)0);
	 TAB_enter(test1, Symbol("TastePalza"), (void*)0);
	 TAB_enter(test1, Symbol("TartyPurza"), (void*)0);
	 TAB_enter(test1, Symbol("TratyPleza"), (void*)0);
	 TAB_enter(test1, Symbol("TaslyPiaza"), (void*)0);
	 TAB_enter(test1, Symbol("TeatyPeaza"), (void*)0);
	 TAB_enter(test1, Symbol("TrotyPraza"), (void*)0);

	 /* enter some more elements */
	 BeginScope;
	 for(i=0;i<=9;i++)
	 TAB_enter(test1, c[i], (void*)0);

	 printf("starting tests for TABLE test1\n");

	 /* test TableEntry */
	 printf("Inserted Symbol = 0x%x\n", TableEntry(test1, Symbol("TastyPizza"))->next->s );
	 printf("Inserted Name = %s\n", TableEntry(test1, Symbol("TastyPizza"))->next->s->name );

	 /* test lookup */
	 a = Symbol("TastyPizza");
	 b = TAB_lookup(test1, a);

	 for(i=9;i>=0;i--)
	 b = TAB_lookup(test1, c[i]);

	 b = TAB_lookup(test1, c[5]);
	 b = TAB_lookup(test1, c[5]);

	 /* test the des update */
	 /* note, exc only the desupdate w/o updating the stack */
	 TAB_desupdate(test1, a);
	 TAB_desupdate(test1, a);
	 b = TAB_lookup(test1, a);

	 TAB_enter(test1, a, (void*)0);
	 b = TAB_lookup(test1, a);

	 /* Test BeginScope and EndScope */
	 printf("Executing endscope\n");
	 EndScope(test1);
	 b = TAB_lookup(test1, c[5]);
	 b = TAB_lookup(test1, Symbol("TaslyPiaza"));

	 printf("Executing endscope\n");
	 EndScope(test1);
	 b = TAB_lookup(test1, c[5]);
	 b = TAB_lookup(test1, Symbol("TaslyPiaza"));

	 return(1);
}
#endif

