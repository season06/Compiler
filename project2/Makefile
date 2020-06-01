all:
	lex lex.l
	cc -o scanner lex.yy.c -ll
	yacc yacc.y
	cc -o parser y.tab.c
	cc -o compiler scanner parser -ll
lex:
	lex lex.l
scanner:
	cc -o scanner lex.yy.c -ll
yacc:
	yacc yacc.y
parser:
	cc -o parser y.tab.c
compiler:
	cc -o compiler scanner parser -ll
clean:
	rm -f lex.yy.c
	rm -f scanner
