all: comp 

comp: bis lex.yy.o parser.tab.o list_error.o
	gcc list_error.o lex.yy.o parser.tab.o -lfl -ly 

lex.yy.o: fl
	gcc lex.yy.c -lfl -c

parser.tab.o: bis
	gcc parser.tab.c -ly -c

list_error.o: 
	gcc -Wall list_error.c -c 

fl: tokenizer.lex
	flex tokenizer.lex

bis: parser.y
	bison parser.y -d -t 

clean:
	rm -rf *.o *.out parser.tab.* *.yy.c *.output
