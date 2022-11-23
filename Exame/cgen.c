/****************************************************/
/* File: cgen.c                                     */
/* The code generator implementation                */
/****************************************************/

#include "globals.h"
#include "code.h"
#include "cgen.h"
#include "cm.tab.h"

/* prototype for internal recursive code generator */
static void cGen (TreeNode * tree);

int registerNo = 1;
int gotoNo = 1;
int countTab = 0;

/* Procedure genStmt generates code at a statement node */
static void genStmt( TreeNode * tree) {
  char * aux;
  int initialGoto;
  switch (tree->kind.stmt) {
    case VoidK:
    case IntK:
      if (tree->child[0]->idtype == Function)
        cGen(tree->child[0]);
      break;
    case ReturnK:
      aux = buildOpCode(tree->child[0], FALSE);
      printTabs();
      fprintf(code, "return %s\n", aux);
      free(aux);
      break;
    case IfK:
      initialGoto = gotoNo;
      gotoNo += 2;
      aux = buildOpCode(tree->child[0], FALSE);
      printTabs();
      fprintf(code, "if_true %s goto L%d\n", aux, initialGoto);
      cGen(tree->child[2]);
      printTabs();
      fprintf(code, "goto L%d\n", initialGoto + 1);
      fprintf(code, "\tL%d:\t", initialGoto);
      countTab = 2;
      cGen(tree->child[1]);
      fprintf(code, "\tL%d:\t", initialGoto + 1);
      countTab = 2;
      free(aux);
      break;
    case WhileK:
      initialGoto = gotoNo;
      gotoNo += 3;
      fprintf(code, "\tL%d:\t", initialGoto);
      countTab = 2;
      aux = buildOpCode(tree->child[0], FALSE);
      printTabs();
      fprintf(code, "if_true %s goto L%d\n", aux, initialGoto + 1);
      printTabs();
      fprintf(code, "goto L%d\n", initialGoto + 2);
      fprintf(code, "\tL%d:\t", initialGoto + 1);
      countTab = 2;
      cGen(tree->child[1]);
      printTabs();
      fprintf(code, "goto L%d\n", initialGoto);
      fprintf(code, "\tL%d:\t", initialGoto + 2);
      countTab = 2;
      free(aux);
      break;
    default:
      break;
  }
}

/* Procedure genExp generates code at an expression node */
static void genExp( TreeNode * tree ) {
  switch (tree->kind.exp) {
      case IdK:
        if (tree->idtype == Function) {
          fprintf(code, "\n%s:", tree->attr.name);
          countTab = 0;
          cGen(tree->child[1]);
        } else {
          buildOpCode(tree, FALSE);
        }
        break;
      case OpK:
        buildOpCode(tree, FALSE);
        break;
      default:
        break;
  }
} /* genExp */

/* Procedure cGen recursively generates code by
 * tree traversal
 */
static void cGen( TreeNode * tree)
{ if (tree != NULL)
  { switch (tree->nodekind) {
      case StmtK:
        genStmt(tree);
        break;
      case ExpK:
        genExp(tree);
        break;
      default:
        break;
    }
    registerNo = 1;
    cGen(tree->sibling);
  }
}

/**********************************************/
/* the primary function of the code generator */
/**********************************************/
/* Procedure codeGen generates code to a code
 * file by traversal of the syntax tree
 */
void codeGen(TreeNode * syntaxTree) {
  cGen(syntaxTree);
  fprintf(code, "\n\n* End of code generation\n");
}
