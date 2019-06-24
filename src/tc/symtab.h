#ifndef symtab_h
#define symtab_h

#include "symbols.h"

/* Symtab.h - This module defines the interface
 * to the symbol table implemented for the
 * tiger compiler
 */

/**
 * There are various ways to implement the symbol
 * table. We will go progressively. We start with 
 * a table that is a runtime array containing a 
 * comfortable start number, and all symbol references
 * will map inside the array
 */

/**
 * Macros and definitions
 */

#define MAX_SYMBOLS	1009

/**
 * Typedefs
 */

typedef struct tableEntry_ *tableEntry;
typedef void*  bvalue;
typedef int    INDEX;

/**
 * Structure definitions
 */

struct tableEntry_
{
	symbol  s;
	bvalue  b; 
	tableEntry  next;
};

#if 0
tableEntry TAB_table[MAX_SYMBOLS];
#else
typedef struct table_* table;
struct table_
{
	tableEntry entry;
	table      next;

	unsigned int H_Add;  /* extra pads with every struct ! */
	unsigned int L_Add;
};
#endif

typedef struct sym_stack_internal_* sym_stack_internal;
struct sym_stack_internal_
{
	symbol s;
	sym_stack_internal next;
};

/**
 * Variable declarations (extern) 
 */

/**
 * Function prototypes
 */

void TAB_enter(table t, symbol s, bvalue b);
table TAB_empty();
bvalue TAB_lookup(table t, symbol s);
void TAB_desupdate(table t, symbol s);
void TAB_pop(table t);

#endif 
