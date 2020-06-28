# Compiler Project

- for Scala

## project1 - Scanner
- yylex()
- Regular Expression

## project2 - Parser
- add "return" in lex.l
- move main() to yacc.y
- use yyparse() instead of yylex()
- use %union pass common variables between lex.l and yacc.y
- rewrite SymbolTable

- remember there must be **main** function here.

## project 3
- fix SymbolTable: add **isGlobal()**
- In parser
	- use **fstream** to write the **.jasm**
	- record **nowStack** and **nowLabel**
	- for IF ELSE, use vector to store **elseLabel**
	- for WHILE, add union to store **beginLabel** and **exitLabel**
- add **javaa** in file
