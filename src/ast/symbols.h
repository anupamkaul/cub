/* Symbols.h
 *
 * Header for implementing symbols
 * as hash tables for easy insertion
 * and lookup
 *
 * Hash Table with External Chaining
 */
#ifndef SYMB_H
#define SYMB_H

/* export these */
typedef char* STR;
typedef struct S_symbol_* S_symbol;
S_symbol S_Symbol(STR); 

/* end */
#endif
