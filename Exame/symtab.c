/****************************************************/
/* File: symtab.c                                   */
/* Symbol table implementation for the C- compiler  */
/* (allows only one symbol table)                   */
/* Symbol table is implemented as a chained         */
/* hash table                                       */
/* Compiler Construction: Principles and Practice   */
/* Kenneth C. Louden                                */
/****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* SIZE is the size of the hash table */
#define SIZE 211

/* SHIFT is the power of two used as multiplier
   in hash function  */
#define SHIFT 4

/* the hash function */
static int hash ( char * key )
{ int temp = 0;
  int i = 0;
  while (key[i] != '\0')
  { temp = ((temp << SHIFT) + key[i]) % SIZE;
    ++i;
  }
  return temp;
}

/* the list of line numbers of the source 
 * code in which a variable is referenced
 */
typedef struct LineListRec
   { int lineno;
     struct LineListRec * next;
   } * LineList;

/* The record in the bucket lists for
 * each variable, including name, 
 * assigned memory location, and
 * the list of line numbers in which
 * it appears in the source code
 */
typedef struct BucketListRec
   { char * name;
     LineList lines;
     int memloc ; /* memory location for variable */
     char * scope;
     ExpType type;
     IdType idtype;
     struct BucketListRec * next;
   } * BucketList;

/* the hash table */
static BucketList hashTable[SIZE];

static void typeError(int lineno, char * message)
{ fprintf(listing,"Type error at line %d: %s\n",lineno,message);
  Error = TRUE;
}

/* Procedure st_insert inserts line numbers and
 * memory locations into the symbol table
 * loc = memory location is inserted only the
 * first time, otherwise ignored
 */
void st_insert( char * name, int lineno, int loc, char * scope, ExpType type, DeclType decltype, IdType idtype)
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) /* variable not yet in table */
  { 
    if (decltype == -1 && idtype == Variable) typeError(lineno,"Erro 1: variável não declarada");
    else if (decltype == -1 && idtype == Ativation && strcmp(name, "input") != 0 && strcmp(name, "output") != 0)
      typeError(lineno,"Erro 5: chamada de função não declarada");
    else if (type == Void && idtype == Variable) typeError(lineno,"Erro 3: declaração inválida de variável");
    if (strcmp(name,"output") == 0 || strcmp(name, "input") == 0) {
      decltype = FuncT;
    }
    if (decltype == FuncT || decltype == VarT) { //CORRIGIR
      l = (BucketList) malloc(sizeof(struct BucketListRec));
      l->name = name;
      l->lines = (LineList) malloc(sizeof(struct LineListRec));
      l->lines->lineno = lineno;
      l->memloc = loc;
      l->lines->next = NULL;
      l->scope = scope;
      l->type = type;
      l->idtype = idtype;
      l->next = hashTable[h];
      hashTable[h] = l; 
    }
  }
  else /* found in table, so just add line number */
  { 
    if (decltype == VarT && strcmp(name,l->name) == 0 && l->idtype == idtype)
      typeError(lineno,"Erro 4: declaração inválida de variável");
    if (strcmp(name,l->name) == 0 && l->idtype == Function && idtype == Variable && decltype == VarT)
      typeError(lineno,"Erro 7: declaração inválida de variável");
    LineList t = l->lines;
    while (t->next != NULL) t = t->next;
    t->next = (LineList) malloc(sizeof(struct LineListRec));
    t->next->lineno = lineno;
    t->next->next = NULL;
  }
} /* st_insert */

/* Function st_lookup returns the memory 
 * location of a variable or -1 if not found
 */
int st_lookup ( char * name )
{ int h = hash(name);
  BucketList l =  hashTable[h];
  while ((l != NULL) && (strcmp(name,l->name) != 0))
    l = l->next;
  if (l == NULL) return -1;
  else return l->memloc;
}

/* Procedure printSymTab prints a formatted 
 * listing of the symbol table contents 
 * to the listing file
 */
void printSymTab(FILE * listing)
{ 
  if (st_lookup("main") == -1) typeError(lineno,"Erro 6: função main não declarada\n");
  int i;
  fprintf(listing,"Variable Name  Tipo  Escopo  Line Numbers\n");
  fprintf(listing,"-------------  ----  ------  ------------\n");
  for (i=0;i<SIZE;++i)
  { if (hashTable[i] != NULL)
    { BucketList l = hashTable[i];
      while (l != NULL)
      { LineList t = l->lines;
        fprintf(listing,"%-15s",l->name);
        switch (l->type) {
          case Integer:
            fprintf(listing,"%-6s","int");
            break;
          case Void:
            fprintf(listing,"%-6s","void");
            break;
        }
        fprintf(listing,"%-8s",l->scope);
        while (t != NULL)
        { fprintf(listing,"%4d ",t->lineno);
          t = t->next;
        }
        fprintf(listing,"\n");
        l = l->next;
      }
    }
  }
} /* printSymTab */
