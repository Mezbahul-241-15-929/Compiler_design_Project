/* =========================
   Full C Compiler Project
   Lexer (lexer.l)
   ========================= */

%{
#include "parser.tab.h"
#include <string.h>
extern FILE *yyin;

int yylineno = 1;
%}

%%
"int"           { return INT; }
"float"         { return FLOAT; }
"char"          { return CHAR; }
"string"        { return STRING; }
"return"        { return RETURN; }
"if"            { return IF; }
"else"          { return ELSE; }
"for"           { return FOR; }
"printf"        { yylval.str = strdup(yytext); return PRINTF; }
"input"         { yylval.str = strdup(yytext); return INPUT; }
"void"          { return VOID; }
[0-9]+\.[0-9]+  { yylval.str = strdup(yytext); return FLOAT_NUM; }
[0-9]+          { yylval.str = strdup(yytext); return NUMBER; }
\"([^\"\\\n]|\\.)*\"  { yylval.str = strdup(yytext); return STRING_LIT; }
\'([^\'\\\n]|\\.)*\'  { yylval.str = strdup(yytext); return CHAR_LIT; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.str = strdup(yytext); return ID; }
"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MUL; }
"/"             { return DIV; }
"%"             { return MOD; }
"="             { return ASSIGN; }
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"\""            { return QUOTE; }
"<"             { return LT; }
">"             { return GT; }
"<="            { return LE; }
">="            { return GE; }
"=="            { return EQ; }
"!="            { return NE; }
"!"             { return NOT; }
"&&"            { return AND; }
"||"            { return OR; }
"++"            { return INC; }
"--"            { return DEC; }
[ \t]           ;
"\n"            { yylineno++; }
.               ;
%%

int yywrap() { return 1; }
