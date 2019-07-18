#pragma once
#include "DLL.h"

typedef struct tagNode{
	TEXTO Value;
	struct tagNode* pNext;
}SLLNODE;

typedef struct {
	SLLNODE* pStart; //Puntero al nodo incial de la lista
	int nElements; // Computo de nodos
}SLL;

SLL* CreateSLL(void);
void DestroySLL(SLL* pList);
void InsertAfter(SLL* pList, SLLNODE* pWhere, TEXTO* pWhat);
void Remove(SLL* pList, SLLNODE* pWhere);
SLLNODE* Adelante(SLL* pList, SLLNODE* pCurrent);
SLLNODE* Atras(SLL* pList, SLLNODE* pCurrent);
