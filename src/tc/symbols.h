#ifndef symbols_h
#define symbols_h

/**
 * Symbols.h - Interface to the symbols module
 *
 * Strings are converted to symbols (struct) and
 * addresses of these structs are used as hash entries
 * to the symbol table.
 */

/**
 * Macros and definitions
 */

#define DEBUG 1
#define MAXINDEX 109

/**
 * Typedefs
 */

typedef struct symbol_* symbol;

/**
 * Structure definitions
 */

struct symbol_
{
char *name;
symbol next;
};

/**
 * Variable declarations
 */

// TODO: If this is our definition of the symbol table then it is weak (linear lookup?) and 
// not evident here from lack of comments

symbol internal_array[MAXINDEX];

/**
 * Function prototypes
 */

int hash(char *s);

symbol Symbol(char *);
char * Name(symbol);

#define NULLIFY(a, st, end)     { int i; for( i=(st) ; i<=(end); i++ ) \
				{ a[i] = NULL; } } 

/// TODO : This definition should be bumped to a higher hierarchy..
#define _NODBG(s, ...) ;
	
#ifdef DEBUG
#define DBG  printf
#else
#define DBG _NODBG
#endif

#endif 
