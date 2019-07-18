#include "bTree.h"
#include <stdio.h>

BTREE* CreateTree(void)
{
	BTREE* pT = (BTREE*)malloc(sizeof(BTREE));
	pT->pRoot = 0;
	pT->nElements = 0;
	return pT;
}

BNODE* BTSearch(BTREE* pTree, VARIANT V)
{
	BNODE* pTarget = pTree->pRoot;
	while (pTarget)
	{
		switch (BTCompare(pTarget->V, V))
		{
		case -1: //<
			pTarget = pTarget->pLeft;
			break;
		case 0: //==
			return pTarget;
		case 1: //>
			pTarget = pTarget->pRight;
			break;
		}
	}
	return NULL;
}
void BTInsert(BTREE* pTree, VARIANT V)
{
	//1 Crear nodo
	BNODE* pNew = (BNODE*)malloc(sizeof(BNODE));
	pNew->V = V;
	pNew->pLeft = 0;
	pNew->pRight = 0;

	//2 Verificar que el arbol esta vacio
	if (pTree->pRoot)
	{
		pTree->pRoot = pNew;
		return;
	}

	//3 Sino, entonce busca rel ugar inserccion
	BNODE* pTarget = pTree->pRoot;
	BNODE* pParent = 0;
	while (pTarget)
	{
		pParent = pTarget;
		switch (BTCompare(V, pTarget->V))
		{
		case -1:
			pTarget = pTarget->pLeft;
			break;
		case 0:
		case 1:
			pTarget = pTarget->pRight;
		}
	}

	//4 color el nodo
	if (BTCompare(V, pParent->V) == 1)
		pParent->pLeft = pNew;
	else
		pParent->pRight = pNew;
}

void DestroyTree(BTREE* pTree);

int BTCompare(VARIANT A, VARIANT B)
{
	if (A.nType == B.nType)
	{
		switch (A.nType)
		{
		case 0: //float
			((A.Data.f < B.Data.f) ? -1:
				((A.Data.f == B.Data.f) ? 0 : 1));
			break;		
		case 1:
				break;
		case 2:
			break;
		}
	}
}

void BTRemove(BTREE* pTree, VARIANT V); //Tarea