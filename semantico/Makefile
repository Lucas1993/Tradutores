.PHONY: clean all comp pre

all: clean comp 
	mv src/a.out ./compiler

comp: parser.tab.o list_error.o sym_table.o
	cd src && gcc list_error.o sym_table.o parser.tab.o -g -lfl -ly 

parser.tab.o: lex.yy.c parser.tab.c
	cd src && gcc parser.tab.c -ly -g -c

list_error.o: 
	cd src && gcc -Wall list_error.c -g -c 

sym_table.o: 
	cd src && gcc -Wall sym_table.c -g -c 

lex.yy.c:
	cd src && flex tokenizer.lex

parser.tab.c:
	cd src && bison parser.y -d -v -t 

clean:
	rm -rf compiler && cd src && rm -rf *.o *.out parser.tab.* *.yy.c *.output
