#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./ast/absyn_def.h"

/* **************************************************************
 * This is the main integrating module for the Tiger Compiler.
 *
 * All it does, is call the main() functions of each of the 
 * individual components like the Abstract Syntax Tree Generator,
 * the Type-Checker ... etc.
 *
 * The components could be run individually, by using their local 
 * Makefiles, and adding the <component>_main.c file to the Makefiles
 * (or using the make tparse option for e.g.)
 * ***************************************************************/

// externs to skip macbook compilation
extern void ast_main(int, char* );
extern void tc_main();

extern A_exp        AST_root=NULL;		/* Abstract Syntax Tree */

main (int argc, char *argv[]) {

    /* Generate Abstract Syntax Tree 
     * This should also report any syntax errors */
    fprintf(stderr, "[tiger]: phase1: Abstract Tree Generation .. start\n");
    ast_main(argc, argv);

    if (AST_root == NULL)
    {
	    fprintf(stderr, "[tiger] ERROR: NULL ABSTRACT SYNTAX TREE\n");
            exit(1);
    }

    fprintf(stderr, "[tiger]: phase1: Abstract Tree Generation .. completed\n");

    /* Type check the AST present in structure AST_root */
    fprintf(stderr, "[tiger]: phase2: Type check and IMT generation .. start\n");
    tc_main();
    fprintf(stderr, "[tiger]: phase2: Type check and IMT generation .. completed\n");

}


