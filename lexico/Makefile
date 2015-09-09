all: fl comp

fl: tokenizer.lex
	flex tokenizer.lex

comp: lex.yy.c
	g++ lex.yy.c -lfl -std=c++11
