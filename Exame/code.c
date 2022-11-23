/****************************************************/
/* File: code.c                                     */
/* TM Code emitting utilities                       */
/****************************************************/

#include "globals.h"
#include "code.h"
#include "util.h"

char * itoa(int x) {
  char * str;
  int length = snprintf(NULL, 0, "%d", x);
  str = malloc(length + 1);
  snprintf(str, length + 1, "%d", x);
  return str;
}

char * getOpToken(TokenType t) {
  switch(t) {
  case PLUS: return "+"; break;
  case MINUS: return "-"; break;
  case MULT: return "*"; break;
  case DIV: return "/"; break;
  case LT: return "<"; break;
  case LTE: return "<="; break;
  case GT: return ">"; break;
  case GTE: return ">="; break;
  case EQ: return "=="; break;
  case DIF: return "!="; break;
  default: return "";
  }
}

void printTabs() {
  while (countTab < 2) {
    fprintf(code, "\t");
    countTab++;
  }
  countTab = 0;
}

char * buildOpCode(TreeNode * p, int isLeftReceive) {
  char * r, * aux0, * aux1, * token;
  TreeNode * q;
  int paramCount;
  if (p == NULL) return "";
  switch (p->kind.exp) {
    case NumK:
      r = itoa(p->attr.val);
      break;
    case IdK:
      if(p->idtype == Variable) {
        if (p->child[0] == NULL) {
          r = copyString(p->attr.name);
        } else {
          aux0 = buildOpCode(p->child[0], FALSE);
          printTabs();
          aux1 = copyString("r");
          strcat(aux1, itoa(registerNo++));
          fprintf(code, "%s = %s * 4\n", aux1, aux0);
          r = copyString(p->attr.name);
          strcat(r, "[");
          strcat(r, aux1);
          strcat(r, "]");
          if (!isLeftReceive) {
            printTabs();
            fprintf(code, "r%d = %s\n", registerNo, r);
            r = copyString("r");
            strcat(r, itoa(registerNo++));
          }
        }
      } else if (p->idtype == Ativation) {
        q = p->child[0];
        paramCount = 0;
        while (q != NULL) {
          paramCount ++;
          aux0 = buildOpCode(q, FALSE);
          printTabs();
          fprintf(code, "param %s\n", aux0);
          q = q->sibling;
        }
        r = copyString("r");
        strcat(r, itoa(registerNo++));
        printTabs();
        fprintf(code, "%s = call %s, %d\n", r, p->attr.name, paramCount);
      }
      break;
    case OpK:
      aux0 = buildOpCode(p->child[0], p->attr.op == ASSIGN);
      aux1 = buildOpCode(p->child[1], FALSE);
      if (p->attr.op != ASSIGN) {
        token = getOpToken(p->attr.op);
        r = copyString("r");
        strcat(r, itoa(registerNo++));
        printTabs();
        fprintf(code, "%s = %s %s %s\n", r, aux0, token, aux1);
      } else {
        printTabs();
        fprintf(code, "%s = %s\n", aux0, aux1);
        r = copyString(aux0);
      }
      break;
    default:
      break;
  }
  return r;
}
