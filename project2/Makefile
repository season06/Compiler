all: lex.yy.cpp y.tab.cpp parser

lex.yy.cpp: lex.l
	lex lex.l

y.tab.cpp: yacc.y
	yacc -d yacc.y

parser: lex.yy.c y.tab.c symbol.cpp symbol.h
	g++ lex.yy.c y.tab.c symbol.cpp -o parser -ll -ly -std=c++11

clean:
	rm lex.yy.c scanner
