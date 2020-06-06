all: parser

lex.yy.cpp: lex.l
	lex -o lex.yy.cpp lex.l

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

parser: lex.yy.cpp y.tab.cpp symbol.hpp
	g++ y.tab.cpp symbol.hpp -o parser -ll -ly -std=c++11

clean:
	rm lex.yy.c scanner
