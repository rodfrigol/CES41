%{
#include "globals.h"
#include "util.h"
#include "scan.h"
/* lexeme of identifier or reserved word */
char tokenString[MAXTOKENLEN+1];
static int yylex(void);
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
                if(c == '\n') lineno++;
                last = c;
                c = input();
              }
            }
{number}    { return NUM; }
{id}        { return ID; }
{ws}        {}
\n          { lineno++; }
<<EOF>>     { return EOF; }
.           { return ERROR; }

%%

TokenType getToken(void)
{ static int firstTime = TRUE;
  TokenType currentToken;
  if (firstTime)
  { firstTime = FALSE;
    lineno++;
    yyin = source;
    yyout = listing;
  }
  currentToken = yylex();
  strncpy(tokenString,yytext,MAXTOKENLEN);
  if (TraceScan) {
    fprintf(listing,"\t%d: ",lineno);
    printToken(currentToken,tokenString);
  }
  return currentToken;
}