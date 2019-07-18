#pragma once
#define TAM 150

typedef struct
{
	int nType;
	union V
	{
		float f; int i; char c; double d; long l; short s;
		unsigned int ui; unsigned char uc; unsigned long ul; unsigned short us;
		char szCadena[512];
		void * p;
	}Data;
}TEXTO;

typedef struct tagDLLNODE
{
	TEXTO Value;
	struct tagDLLNODE* pBack;
	struct tagDLLNODE* pFront;
}DLLNODE;

typedef struct DLL
{
	int nElements;
	DLLNODE Start;
	DLLNODE End;
}DLL;

DLL* CreateDLL(void);
void DestroyDLL(DLL*);
void DLLInsertAfter(DLL*,DLLNODE*, TEXTO);
void DLLInsertBefore(DLL*, DLLNODE*, TEXTO);
DLLNODE* DLLNext(DLL*, DLLNODE*);
DLLNODE* DLLBack(DLL*, DLLNODE*);
void DLLErase(DLL*,DLLNODE*);

