all: comp 

comp: bis parser.tab.o list_error.o
	gcc list_error.o parser.tab.o -lfl -ly 

parser.tab.o: fl bis
	gcc parser.tab.c -ly -c

list_error.o: 
	gcc -Wall list_error.c -c 

fl: tokenizer.lex
	flex tokenizer.lex

bis: parser.y
	bison parser.y -d -t 

clean:
	rm -rf *.o *.out parser.tab.* *.yy.c *.output
