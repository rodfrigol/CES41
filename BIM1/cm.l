%{
#include "globals.h"
int nline = 1;
%}
digit       [0-9]
number      {digit}+
letter      [a-zA-Z]
id          {letter}+
ws          [ \t]+
%%
"else"      { return ELSE; }
"if"        { return IF; }
"int"       { return INT; }
"return"    { return RETURN; }
"void"      { return VOID; }
"while"     { return WHILE; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MULT; }
"/"         { return DIV; }
"<"         { return LT; }
"<="        { return LTE; }
">"         { return GT; }
">="        { return GTE; }
"=="        { return EQ; }
"!="        { return DIF; }
"="         { return ASSIGN; }
";"         { return SEMI; }
","         { return COMMA; }
"("         { return OP; }
")"         { return CP; }
"["         { return OB; }
"]"         { return CB; }
"{"         { return OBRACES; }
"}"         { return CBRACES; }
"/*"        { char c = input(), last = '\0';
              while(1) {
                if(c == '/' && last == '*') break;
                if(c == EOF || c == '\0') return EOF;
                if(c == '\n') nline++;
                last = c;
                c = input();
              }
            }
{number}    { return NUM; }
{id}        { return ID; }
{ws}        {}
\n          { nline++; }
<<EOF>>     { return EOF; }
.           { return ERROR; }
%%
void printToken(TokenType tok, char *word) {
    switch (tok) {
        case ELSE: case IF: case INT: case RETURN: case VOID: case WHILE:
            printf("palavra reservada: %s\n", word); break;
        case PLUS: case MINUS: case MULT: case DIV: case LT: case LTE: case GT: case GTE: case EQ: case DIF: 
        case ASSIGN: case SEMI: case COMMA: case OP: case CP: case OB: case CB: case OBRACES: case CBRACES:
            printf("operador: %s\n", word); break;
        case NUM:
            printf("numero: %s\n", word); break;
        case ID:
            printf("identificador: %s\n", word); break;
        case ERROR:
            printf("ERRO: %s\n", word); break;
        case EOF:
            printf("END\n"); break;
    }
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        FILE *fin = fopen(argv[1], "r");
        if (fin != NULL) yyin = fin;
        else {
            perror(argv[0]);
            return 1;
        }
    }
    printf("Análise léxica\n\n");
    TokenType tok;
    do {
        tok = yylex();
        printf("linha %d - ", nline);
        printToken(tok, yytext);
    } while (tok != EOF);
    return 0;
}