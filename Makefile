# The main makefile for creating the tiger compiler

COMP=tiger

# Src files for component AST
PATH_AST= ./src/ast/
SRC_AST= $(PATH_AST)lex.yy.c \
         $(PATH_AST)y.tab.c \
         $(PATH_AST)absyn.c \
         $(PATH_AST)absyn_malloc.c \
         $(PATH_AST)prn_exp.c 

# Src files for component TC
PATH_TC= ./src/tc/
SRC_TC=  $(PATH_TC)symbols.c \
	 $(PATH_TC)symtab.c \
	 $(PATH_TC)types.c \
	 $(PATH_TC)env.c \
	 $(PATH_TC)semant.c \
	 $(PATH_TC)semant_utils.c 

#Options for Src files for component AST
# These options are to enable/disable various logs 
# generated in semantic analysis phase
OPT_AST= -DYDUMPVAR -DYDUMPTXT -DYDUMPEXP -DYDUMPMRC -DYDUMPMRCF -DYDUMP_TYLIST -DYDUMP_VLIST -DYASNEXP -DYDUMPIF -DYDUMPFOR -DYDUMPFN

# Make the main target
tiger:   clean tagit lexit yaccit  
	 echo Creating ast source ..
	 gcc -o $(COMP) $(SRC_AST) $(SRC_TC) $(OPT_AST) ./src/main.c -lfl 1>dbg 2>dbg  
	 rm -f dbg # works only if gcc was successful

#	/bin/sh -c 'if [ -s dbg ]; then  \
#		     echo Error messages for <> in file dbg   \
#                     exit  \
#              	fi'
	
clean:
	rm -f $(COMP) *.o y.* lex.* ldump.txt ydump.txt dbg

tagit:
	echo Making tiger ..
	

lexit:  
	echo Lexing ..

        # note that a single cmd is exec'd as 1 shell instance
	cd ./src/ast/; \
	lex tig.lex 1>dbg 2>dbg 


yaccit:  
	echo Yaccing ..
	cd ./src/ast/; \
	yacc -d -v tig.yac 1>dbg 2>dbg 

