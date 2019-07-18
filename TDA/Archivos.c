#include<stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>

#include "..\TDA\SLL.h"
#include "..\TDA\Queue.h"
void txt(char* nombre)
{
	int nc;
	nc = strlen(nombre);
	nombre[nc] = '.';
	nc++;
	nombre[nc] = 't';
	nc++;
	nombre[nc] = 'x';
	nc++;
	nombre[nc] = 't';
	nc++;
	nombre[nc] = '\0';
}

int IniciarArchivo(DLL* pText,char* nombre,DLL* pDeshacer) {
	char taRenglones[500] = { 0 };
	int error,error2;
	FILE * fd;

	error = fopen_s(&fd, nombre, "r"); 
	if (error == 0)
	{
		printf("El archivo'%s' esta abierto\n", nombre);
	}
	else
	{
		printf("Se creara un archivo con el nombre'%s'\n", nombre);
		error2 = fopen_s(&fd, nombre, "w+");
		if (error2 == 0)
		{
			printf("Archivo '%s' creado y abierto con exito\n", nombre);
		}
		else
			printf("El archivo no se pudo crear'%s' \n", nombre);
	}
	int i=0;
	if (fd != 0)
	{
		TEXTO t;
		while (1)
		{
			fgets(taRenglones, 500, fd);
			strcpy_s(t.Data.szCadena, 500, taRenglones);
			if (feof(fd)) break;
			for (i = 0; i < 500; i++)
			{
				if (t.Data.szCadena[i] == '\n')
					t.Data.szCadena[i] = '\0';
			}

			DLLInsertBefore(pText, &pText->End, t);
		}
	}
	
	fclose(fd);
	return error2;
}

void AgregarRenglon(DLL* pText,char* nombre,DLL* pDeshacer) {
	DLLNODE *pWhere;
	//Deshacer
	TEXTO t;
	char espacio[120] = "CaDeNaSiGuiente";
	strcpy_s(t.Data.szCadena, 500, espacio);
	DLLInsertBefore(pDeshacer, &pDeshacer->End, t);
	for (pWhere = pText->Start.pFront; pWhere != &pText->End; pWhere = pWhere->pFront)
	{
		DLLInsertBefore(pDeshacer, &pDeshacer->End, pWhere->Value);
	}
	printf("Escriba renglon:\t");
	char Ttexto[500] = { 0 };
	gets(Ttexto);
	strcpy_s(t.Data.szCadena, 500, Ttexto);
	DLLInsertBefore(pText, &pText->End, t);
}

void EliminarRenglon(DLL* pText,char* nombre, DLL* pDeshacer)
{
	if (pText->nElements == 0)
	{
		printf("No hay renglones para eliminar\n");
	}
	else
	{
		//Deshacer
		TEXTO t;
		DLLNODE* pWhere;
		char espacio[500] = "CaDeNaSiGuiente";
		strcpy_s(t.Data.szCadena, 500, espacio);
		DLLInsertBefore(pDeshacer, &pDeshacer->End, t);
		for (pWhere = pText->Start.pFront; pWhere != &pText->End; pWhere = pWhere->pFront)
		{
			DLLInsertBefore(pDeshacer, &pDeshacer->End, pWhere->Value);
		}

		int i = 1;
		DLLNODE* pWhere2;
		for (pWhere2 = pText->Start.pFront; pWhere2 != &pText->End; pWhere2 = pWhere2->pFront)
		{
			printf(" \t\t [%d]\t%s\n", i, pWhere2->Value.Data.szCadena);
			i++;
		}
		int nRenglon = 0, c2 = 0;
		do {
			if (nRenglon<0 || nRenglon>i)
				printf("Ingresa un valor valido");
			printf("Numero de renglon [comensando en 1]:");
			scanf_s("%d", &nRenglon);
		} while (nRenglon<0 || nRenglon>i);
		pWhere2 = &pText->Start;
		while (c2 < nRenglon)
		{
			pWhere2 = DLLNext(pText, pWhere2);
			c2++;
		}
		DLLErase(pText, pWhere2);
	}
}

void ImprimirRenglones(DLL*pText)
{
	DLLNODE *pWhere;
	if (pText->nElements != 0)
	{
		for (pWhere = pText->Start.pFront; pWhere != &pText->End; pWhere = pWhere->pFront)
		{
			printf("\t\t\t%s\n", pWhere->Value.Data.szCadena);
		}
	}
	else
	{
		printf("No hay renglones guardados\n");
	}
}

void BorrarSaltoLinea(DLL*pText)
{
	DLLNODE* pWhere;
	int nRenglon = 1, c2 = 0;
	pWhere = &pText->End;
	while (c2 < nRenglon)
	{
		pWhere=DLLBack(pText, pWhere);
		//pWhere = DLLNext(pText, pWhere);
		c2++;
	}
	DLLErase(pText, pWhere);
}

void Deshacer(DLL* pText, char* nombre, DLL* pDeshacer,DLL* pRehacer)
{
	if (pDeshacer->nElements != 0)
	{
		if (strcmp(pDeshacer->End.pBack->Value.Data.szCadena, pDeshacer->Start.pFront->Value.Data.szCadena) != 0)
		{
			//Rehacer
			TEXTO t;
			DLLNODE* pWhere;
			char espacio[500] = "CaDeNaSiGuiente";
			strcpy_s(t.Data.szCadena, 500, espacio);
			DLLInsertBefore(pRehacer, &pRehacer->End, t);
			for (pWhere = pText->Start.pFront; pWhere != &pText->End; pWhere = pWhere->pFront)
			{
				DLLInsertBefore(pRehacer, &pRehacer->End, pWhere->Value);
			}

			DestroyDLL(pText);
			pText = CreateDLL();
			do
			{
				DLLInsertAfter(pText, &pText->Start, pDeshacer->End.pBack->Value);
				DLLErase(pDeshacer, pDeshacer->End.pBack);
			} while (strcmp(pDeshacer->End.pBack->Value.Data.szCadena, espacio) != 0);
			DLLErase(pDeshacer, pDeshacer->End.pBack);
		}
		else
			printf("No hay elementos almacenados para deshacer\n");
	}
	else
		printf("No hay elementos almacenados para deshacer\n");
}

void Rehacer(DLL* pText, char* nombre,  DLL* pDeshacer,DLL* pRehacer)
{
	if (pRehacer->nElements != 0)
	{
		if (strcmp(pRehacer->End.pBack->Value.Data.szCadena, pRehacer->Start.pFront->Value.Data.szCadena) != 0)
		{
			//Deshacer
			TEXTO t;
			DLLNODE* pWhere;
			char espacio[500] = "CaDeNaSiGuiente";
			strcpy_s(t.Data.szCadena, 500, espacio);
			DLLInsertBefore(pDeshacer, &pDeshacer->End, t);
			for (pWhere = pText->Start.pFront; pWhere != &pText->End; pWhere = pWhere->pFront)
			{
				DLLInsertBefore(pDeshacer, &pDeshacer->End, pWhere->Value);
			}

			DestroyDLL(pText);
			pText = CreateDLL();
			do
			{
				DLLInsertAfter(pText, &pText->Start, pRehacer->End.pBack->Value);
				DLLErase(pRehacer, pRehacer->End.pBack);
			} while (strcmp(pRehacer->End.pBack->Value.Data.szCadena, espacio) != 0);
			DLLErase(pRehacer, pRehacer->End.pBack);
		}
		else
			printf("No hay elementos almacenados para rehacer\n");
	}
	else
		printf("No hay elementos almacenados para rehacer\n");
}

void guardarArchivo(DLL* pText, char* nombre)
{
	DLLNODE* pWhere;
	FILE * fd;
	fopen_s(&fd, nombre, "w+");
	for (pWhere = pText->Start.pFront; pWhere != &pText->End; pWhere = pWhere->pFront)
	{
		fputs(pWhere->Value.Data.szCadena, fd);
		fputc('\n', fd);
	}

	fclose(fd);
}