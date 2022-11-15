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
                 { YYSTYPE t = $1;
                   if (t != NULL)
                   { while (t->sibling != NULL)
                        t = t->sibling;
                     t->sibling = $2;
                     $$ = $1; }
                     else $$ = $2;
                 }
            | decl  { $$ = $1; }
            ;
decl        : var_decl { $$ = $1; }
            | fun_decl { $$ = $1; }
            | error  { $$ = NULL; }
            ;
var_decl    : tipo_esp ID SEMI
            | tipo_esp ID OB NUM CB SEMI
            ;
tipo_esp    : INT
            | VOID
            ;
fun_decl    : tipo_esp ID OP params CP comp_decl
            ;
params      : param_lista
            | VOID
            ;
param_lista : param_lista COMMA param
            | param
            ;
param       : tipo_esp ID
            | tipo_esp ID OB CB
            ;
comp_decl   : OBRACES loc_decl stmt_list CBRACES
            ;
loc_decl    : loc_decl var_decl
            | "vazio"
            ;
stmt_list   : stmt_list stmt
            | "vazio"
            ;
stmt        : exp_decl
            | comp_decl
            | sel_decl
            | it_decl
            | ret_decl
            ;
exp_decl    : exp SEMI
            | SEMI
            ;
sel_decl    : IF OP exp CP stmt
            | IF OP exp CP stmt ELSE stmt
            ;
it_decl     : WHILE OP exp CP stmt
            ;
ret_decl    : RETURN SEMI
            | RETURN exp SEMI
            ;
exp         : var ASSIGN exp
            | simp_exp
            ;
var         : ID
            | ID OB exp CB
            ;
simp_exp    : soma_exp LTE soma_exp
            | soma_exp LT soma_exp
            | soma_exp GT soma_exp
            | soma_exp GTE soma_exp
            | soma_exp EQ soma_exp
            | soma_exp DIF soma_exp
            | soma_exp
            ;
soma_exp    : soma_exp PLUS termo
            | soma_exp MINUS termo
            | termo
            ;
termo       : termo MULT fator
            | soma_exp DIV fator
            | fator
            ;
fator       : OP exp CP
            | var
            | ativ
            | NUM
            | error  { $$ = NULL; }
            ;
ativ        : ID OP args CP
            ;
args        : arg_lista
            | "vazio"
            ;
arg_lista   : arg_lista COMMA exp
            | exp
            ;

if_stmt     : IF exp THEN stmt_seq END
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $2;
                   $$->child[1] = $4;
                 }
            | IF exp THEN stmt_seq ELSE stmt_seq END
                 { $$ = newStmtNode(IfK);
                   $$->child[0] = $2;
                   $$->child[1] = $4;
                   $$->child[2] = $6;
                 }
            ;
repeat_stmt : REPEAT stmt_seq UNTIL exp
                 { $$ = newStmtNode(RepeatK);
                   $$->child[0] = $2;
                   $$->child[1] = $4;
                 }
            ;
assign_stmt : ID { savedName = copyString(tokenString);
                   savedLineNo = lineno; }
              ASSIGN exp
                 { $$ = newStmtNode(AssignK);
                   $$->child[0] = $4;
                   $$->attr.name = savedName;
                   $$->lineno = savedLineNo;
                 }
            ;
read_stmt   : READ ID
                 { $$ = newStmtNode(ReadK);
                   $$->attr.name =
                     copyString(tokenString);
                 }
            ;
write_stmt  : WRITE exp
                 { $$ = newStmtNode(WriteK);
                   $$->child[0] = $2;
                 }
            ;
exp         : simple_exp LT simple_exp 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = LT;
                 }
            | simple_exp EQ simple_exp
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = EQ;
                 }
            | simple_exp { $$ = $1; }
            ;
simple_exp  : simple_exp PLUS term 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = PLUS;
                 }
            | simple_exp MINUS term
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = MINUS;
                 } 
            | term { $$ = $1; }
            ;
term        : term TIMES factor 
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = TIMES;
                 }
            | term OVER factor
                 { $$ = newExpNode(OpK);
                   $$->child[0] = $1;
                   $$->child[1] = $3;
                   $$->attr.op = OVER;
                 }
            | factor { $$ = $1; }
            ;
factor      : LPAREN exp RPAREN
                 { $$ = $2; }
            | NUM
                 { $$ = newExpNode(ConstK);
                   $$->attr.val = atoi(tokenString);
                 }
            | ID { $$ = newExpNode(IdK);
                   $$->attr.name =
                         copyString(tokenString);
                 }
            | error { $$ = NULL; }
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

