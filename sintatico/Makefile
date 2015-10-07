all: comp 

comp: bis parser.tab.o list_error.o sym_table.o
	gcc list_error.o sym_table.o parser.tab.o -g -lfl -ly 

parser.tab.o: fl bis
	gcc parser.tab.c -ly -g -c

list_error.o: 
	gcc -Wall list_error.c -g -c 

sym_table.o: 
	gcc -Wall sym_table.c -g -c 

fl: tokenizer.lex
	flex tokenizer.lex

bis: parser.y
	bison parser.y -d -v -t 

clean:
	rm -rf *.o *.out parser.tab.* *.yy.c *.output
