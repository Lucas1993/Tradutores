all: fl comp 

fl: tokenizer.lex
	flex tokenizer.lex

comp:  lex.yy.o list_error.o
	gcc list_error.o lex.yy.o -lfl 

lex.yy.o:
	gcc lex.yy.c -lfl -c

list_error.o: 
	gcc -Wall list_error.c -c 

clean:
	rm *.o *.out
