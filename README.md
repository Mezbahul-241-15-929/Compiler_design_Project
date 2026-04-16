flex lexer.l
bison -d parser.y
gcc lex.yy.c parser.tab.c -o compiler.exe
.\compiler.exe test1.c
