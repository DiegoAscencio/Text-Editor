#pragma once
#include "SLL.h"

typedef struct tagBNode 
{
	VARIANT V;
	struct tagBNode* pLeft;
	struct tagBNode* pRight;
}BNODE;

typedef struct tagBTREE
{
	BNODE* pRoot;
	int nElements;
}BTREE;

BTREE* CreateTree(void);
void DestroyTree(BTREE* pTree);
BNODE* BTSearch(BTREE* pTree,VARIANT V);
int BTCompare(VARIANT A, VARIANT B);
void BTInsert(BTREE* pTree, VARIANT V);
void BTRemove(BTREE* pTree, VARIANT V); //Tarea
