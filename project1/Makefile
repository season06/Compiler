all:
	lex lex.l
	cc -o scanner lex.yy.c -ll

lex:
	lex lex.l

cc:
	cc -o scanner lex.yy.c -ll

clean:
	rm -f lex.yy.c
	rm -f scanner
