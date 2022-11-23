/****************************************************/
/* File: code.h                                     */
/* Code emitting utilities                          */
/****************************************************/

#ifndef _CODE_H_
#define _CODE_H_

extern int registerNo;
extern int gotoNo;
extern int countTab;

char * buildOpCode(TreeNode *, int);
void printTabs();

#endif
