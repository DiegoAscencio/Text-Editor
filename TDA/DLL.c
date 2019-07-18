#include "DLL.h"
#include <stdlib.h>


DLL* CreateDLL(void)
{
	DLL* pList = (DLL*)malloc(sizeof(DLL));
	pList->nElements = 0;
	pList->Start.pBack = 0;
	pList->Start.pFront = 0;
	pList->Start.pFront = &pList->End;
	pList->End.pBack= &pList->Start;
	return pList;
}
void DestroyDLL(DLL* pList)
{
	while (pList->nElements)
		DLLErase(pList, pList->Start.pFront);
	free(pList);
}
void DLLInsertAfter(DLL* pList, DLLNODE* pWhere, TEXTO Value)
{
	DLLNODE* pNew = (DLLNODE*)malloc(sizeof(DLLNODE));
	pNew->Value = Value;
	pList->nElements++;
	pNew->pFront = pWhere->pFront;
	pNew->pBack = pWhere;
	pWhere->pFront = pNew;
	pNew->pFront->pBack = pNew;
}

void DLLInsertBefore(DLL* pList, DLLNODE* pWhere, TEXTO Value)
{
	DLLNODE* pNew = (DLLNODE*)malloc(sizeof(DLLNODE));
	pNew->Value = Value;
	pList->nElements++;
	pNew->pBack = pWhere->pBack;
	pNew->pFront = pWhere;
	pWhere->pBack = pNew;
	pNew->pBack->pFront = pNew;
}
DLLNODE* DLLNext(DLL* pList, DLLNODE* pWhere)
{
	if (pWhere->pFront != &pList->End)
		return pWhere->pFront;
	return 0;
}
DLLNODE* DLLBack(DLL* pList, DLLNODE* pWhere)
{
	if (pWhere->pBack != &pList->Start)
		return pWhere->pBack;
	return 0;
}

void DLLErase(DLL* pList, DLLNODE* pWhere)
{
	pWhere->pBack->pFront = pWhere->pFront;
	pWhere->pFront->pBack = pWhere->pBack;
	pList->nElements--;
	free(pWhere);
}