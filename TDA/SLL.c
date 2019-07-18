#include "SLL.h"
#include <stdio.h>

SLL* CreateSLL(void)
{
	SLL* pList = (SLL*)malloc(sizeof(SLL));
	pList->pStart = NULL;
	pList->nElements = 0;
	return pList;
}

void DestroySLL(SLL* pList)
{
	while (pList->pStart)
	{
		SLLNODE* pToDelete = pList->pStart;
		pList->pStart = pList->pStart->pNext;
		free(pToDelete);
	}
	free(pList);
}

void InsertAfter(SLL* pList, SLLNODE* pWhere, TEXTO* pWhat)
{ //Lista vacia o instertar desde el inicio
	SLLNODE* pNew = (SLLNODE*)malloc(sizeof(SLLNODE));
	pNew->Value = *pWhat;
	if (NULL == pList->pStart) //Caso 0 Lista vacia 
	{
		pNew->pNext = NULL;
		pList->pStart = pNew;
	}
	else					   //Caso 1 Lista no vacia 
	{
		pNew->pNext = pWhere->pNext;
		pWhere->pNext = pNew;
	}
}

void Remove(SLL* pList, SLLNODE* pWhere) 
{
	if (pWhere == pList->pStart)
	{
		pList->pStart = pWhere->pNext;
	}
	else
	{
		SLLNODE* pBack = pList->pStart;
		while (pBack->pNext != pWhere)
				pBack = pBack->pNext;
		pBack->pNext = pWhere->pNext;
	}
	free(pWhere);
}

SLLNODE*Atras(SLL* pList, SLLNODE* pCurrent)
{

}

SLLNODE* Adelante(SLL* pList, SLLNODE* pCurrent)
{
	return pCurrent->pNext;
}