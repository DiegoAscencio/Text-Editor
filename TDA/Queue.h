#pragma once
#include "DLL.h"

typedef struct tagQUEUE
{
	DLL* pList;
}QUEUE;

QUEUE* CreateQueue(void);
void QPush(QUEUE* pQueue, TEXTO v);
TEXTO QPull(QUEUE* pQueue);
QUEUE DestroyQueue(QUEUE* pQueue);