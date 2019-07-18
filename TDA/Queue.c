#include "Queue.h"

QUEUE* CreateQueue(void)
{
	QUEUE* pQueue = (QUEUE*)malloc(sizeof(QUEUE));
	pQueue->pList = CreateDLL();
	return pQueue;
}
void QPush(QUEUE* pQueue, TEXTO V)
{
	DLLInsertBefore(pQueue->pList, &pQueue->pList->End, V);
}
TEXTO QPull(QUEUE* pQueue)
{
	TEXTO V = pQueue->pList->Start.pFront->Value;
	DLLErase(pQueue->pList, pQueue->pList->Start.pFront);
	return V;
}
QUEUE DestroyQueue(QUEUE* pQueue)
{
	DestroyDLL(pQueue->pList);
	free(pQueue);
}