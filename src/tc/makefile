all:
	gcc -c -g -DRUN_AND_TEST_TC symbols.c symtab.c types.c env.c semant.c semant_utils.c
	gcc -o typecheck symbols.o symtab.o types.o env.o semant.o semant_utils.o

clean:
	rm -f symbols.o symtab.o types.o env.o semant.o semant_utils.o typecheck

