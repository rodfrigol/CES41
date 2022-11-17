/****************************************************/
/* File: tiny.y                                     */
/* The TINY Yacc/Bison specification file           */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/
%{
#define YYPARSER /* distinguishes Yacc output from other code files */

#include "globals.h"
#include "util.h"
#include "scan.h"
#include "parse.h"

#define YYSTYPE TreeNode *
static char * savedName; /* for use in assignments */
static int savedLineNo;  /* ditto */
static TreeNode * savedTree; /* stores syntax tree for later return */
static int yylex(void);
int yyerror(char *s);

%}

%token ELSE IF INT RETURN VOID WHILE
%token ID NUM 
%token PLUS MINUS MULT DIV LT LTE GT GTE EQ DIF ASSIGN SEMI COMMA OP CP OB CB OBRACES CBRACES
%token ERROR 

%% /* Grammar for TINY */

program     : decl_list
                 { savedTree = $1;} 
            ;
decl_list   : decl_list decl
                 { 
                    YYSTYPE t = $1;
                    if (t != NULL)
                    { 
                      while (t->sibling != NULL)
                        t = t->sibling;
                      t->sibling = $2;
                      $$ = $1; 
                    }
                    else $$ = $2;
                 }
            | decl  { $$ = $1; }
            ;
decl        : var_decl { $$ = $1; }
            | fun_decl { $$ = $1; }
            | error  { $$ = NULL; }
            ;
var_decl    : tipo_esp ID { savedName = copyString(tokenString);
                            savedLineNo = lineno; }
              {
                $$ = $1;
                $$->child[0] = newExpNode(IdK);
                $$->child[0]->attr.name = savedName;
              }
              SEMI
            | tipo_esp ID { savedName = copyString(tokenString);
                            savedLineNo = lineno; }
              OB NUM { savedNum = atoi(tokenString); } CB
              {
                $$ = $1;
                $$->child[0] = newExpNode(IdK);
                $$->child[0]->attr.name = savedName;
                $$->child[0]->child[0] = newExpNode(NumK);
                $$->child[0]->child[0]->attr.val = savedNum;
              }
              SEMI
            ;
tipo_esp    : INT { $$ = newStmtNode(IntK); }
            | VOID { $$ = newStmtNode(VoidK); }
            ;
fun_decl    : tipo_esp ID { savedName = copyString(tokenString);
                            savedLineNo = lineno; }
              OP params CP comp_decl
              {
                $$ = $1;
                $$->child[0] = newExpNode(IdK);
                $$->child[0]->attr.name = savedName;
                $$->child[0]->child[0] = $5;
                $$->child[0]->child[1] = $7;
              }
            ;
params      : param_lista { $$ = $1; }
            | VOID { $$ = $NULL; }
            ;
param_lista : param_lista COMMA param
                 { 
                    YYSTYPE t = $1;
                    if (t != NULL)
                    { 
                      while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $3;
                     $$ = $1;
                    }
                     else $$ = $3;
                 }
            | param { $$ = $1; }
            ;
param       : tipo_esp ID
              {
                $$ = $1
                $$->child[0] = newExpNode(IdK);
                $$->child[0]->attr.name = copyString(tokenString);
              }
            | tipo_esp ID { savedName = copyString(tokenString);
                            savedLineNo = lineno; }
              OB CB
              {
                $$ = $1
                $$->child[0] = newExpNode(IdK);
                $$->child[0]->attr.name = copyString(tokenString);
              }
            ;
comp_decl   : OBRACES loc_decl stmt_list CBRACES
              { 
                YYSTYPE t = $2;
                if (t != NULL)
                { 
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $3;
                  $$ = $2;
                }
                else $$ = $3;
              }
            ;
loc_decl    : loc_decl var_decl
              { 
                YYSTYPE t = $1;
                if (t != NULL)
                { 
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $2;
                  $$ = $1; 
                }
                else $$ = $2;
              }
            | {$$ = NULL;}
            ;
stmt_list   : stmt_list stmt
              { 
                YYSTYPE t = $1;
                if (t != NULL)
                { 
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $2;
                  $$ = $1; 
                }
                else $$ = $2;
              }
            | {$$ = NULL;}
            ;
stmt        : exp_decl { $$ = $1; }
            | comp_decl { $$ = $1; }
            | sel_decl { $$ = $1; }
            | it_decl { $$ = $1; }
            | ret_decl { $$ = $1; }
            ;
exp_decl    : exp SEMI { $$ = $1; }
            | SEMI { $$ = $1; }
            ;
sel_decl    : IF OP exp CP stmt
              { 
                $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5;
              }
            | IF OP exp CP stmt ELSE stmt
              { 
                $$ = newStmtNode(IfK);
                $$->child[0] = $3;
                $$->child[1] = $5;
                $$->child[2] = $7;
              }
            ;
it_decl     : WHILE OP exp CP stmt
              {
                $$ = newStmtNode(WhileK);
                $$->child[0] = $3;
                $$->child[1] = $5;
              }
            ;
ret_decl    : RETURN SEMI
              {
                $$ = newStmtNode(ReturnK);
              }
            | RETURN exp SEMI
              {
                $$ = newStmtNode(ReturnK);
                $$->child[0] = $2;
              }
            ;
exp         : var ASSIGN exp
              {
                $$ = newExpNode(OpK);
                $$->attr.op = ASSIGN;
                $$->child[0] = $1;
                $$->child[1] = $3;
              }
            | simp_exp { $$ = $1; }
            ;
var         : ID
              {
                $$ = newExpNode(IdK);
                $$->attr.name = copyString(tokenString);
              }
            | ID { savedName = copyString(tokenString);
                            savedLineNo = lineno; }
              OB exp CB
              {
                $$ = newExpNode(IdK);
                $$->attr.name = savedName;
                $$->child[0] = $4;
              }
            ;
simp_exp    : soma_exp LTE soma_exp
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = LTE;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | soma_exp LT soma_exp
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = LT;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | soma_exp GT soma_exp
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = GT;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | soma_exp GTE soma_exp
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = GTE;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | soma_exp EQ soma_exp
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = EQ;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | soma_exp DIF soma_exp
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = DIF;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | soma_exp { $$ = $1; }
            ;
soma_exp    : soma_exp PLUS termo
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = PLUS;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | soma_exp MINUS termo
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = MINUS;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | termo { $$ = $1; }
            ;
termo       : termo MULT fator
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = MULT;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | soma_exp DIV fator
              {
                  $$ = newExpNode(OpK);
                  $$->attr.op = DIV;
                  $$->child[0] = $1;
                  $$->child[1] = $3;
              }
            | fator { $$ = $1; }
            ;
fator       : OP exp CP { $$ = $2; }
            | var { $$ = $1; }
            | ativ { $$ = $1; }
            | NUM { $$ = newExpNode(NumK);
                    $$->attr.val = atoi(tokenString); }
            ;
ativ        : ID { savedName = copyString(tokenString);
                            savedLineNo = lineno; }
              OP args CP
              {
                $$ = newExpNode(IdK);
                $$->attr.name = savedName;
                $$->child[0] = $4
              }
            ;
args        : arg_lista { $$ = $1;}
            | {$$ = NULL;}
            ;
arg_lista   : arg_lista COMMA exp
              { 
                YYSTYPE t = $1;
                if (t != NULL)
                { 
                  while (t->sibling != NULL)
                    t = t->sibling;
                  t->sibling = $3;
                  $$ = $1; 
                }
                else $$ = $3;
              }
            | exp { $$ = $1;}
            ;

%%

int yyerror(char * message)
{ fprintf(listing,"Syntax error at line %d: %s\n",lineno,message);
  fprintf(listing,"Current token: ");
  printToken(yychar,tokenString);
  Error = TRUE;
  return 0;
}

/* yylex calls getToken to make Yacc/Bison output
 * compatible with ealier versions of the TINY scanner
 */
static int yylex(void)
{ return getToken(); }

TreeNode * parse(void)
{ yyparse();
  return savedTree;
}

