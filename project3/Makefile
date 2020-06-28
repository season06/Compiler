testFile = ./testFile/example.txt

all: parser executeParser javaBytecode

lex.yy.cpp: lex.l
	lex -o lex.yy.cpp lex.l

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

parser: lex.yy.cpp y.tab.cpp symbol.hpp
	g++ y.tab.cpp symbol.hpp -o parser -ll -ly -std=c++11

executeParser: $(testFile)
	./parser $(testFile)

javaBytecode: output.jasm
	javaa/javaa output.jasm

executeJava: output.class
	java output

clean:
	rm lex.yy.cpp y.tab.cpp y.tab.h *.o *.exe *.class *.jasm
