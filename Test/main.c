#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <string.h>
#include "..\TDA\DLL.h"
#include "..\TDA\SLL.h"
#include "..\TDA\Queue.h"
#include "..\TDA\Archivos.c"

void main(void) {

	/*/TEXTO V;
	//DLL* pDll=CreateDLL();
	//DLL* pQ = CreateDLL();
	V.nType = -1;
	V.Data.p = pDll;
	DLLInsertAfter(pQ, &pQ->Start, V);
	QPush(pQ, V);
	V=QPull(pQ);

	TEXTO V;
	DLL* pDll = CreateDLL();
	QUEUE* pQ = CreateQueue();
	V.nType = -1;
	V.Data.p = pDll;
	QPush(pQ, V);
	V = QPull(pQ);
	DLL* pQ = CreateDLL();*/
	DLL* pRehacer = CreateDLL();
	DLL* pDeshacer = CreateDLL();
	DLL* pText=CreateDLL();
	int opcion = 0;
	char nombre[50];

	printf("Ingresar el nombre del archivo (si no se encuentra en la ruta se creara uno nuevo)\n");
	scanf_s("%[^\n]s", nombre, sizeof(nombre));
	getchar();
	txt(nombre);


	if (!IniciarArchivo(pText, nombre,pDeshacer))
		BorrarSaltoLinea(pText);

	printf("EDITOR DE TEXTO V1.0\n\n");
	printf(" [1] Añadir Renglon\n");
	printf(" [2] Eliminar Renglon\n");
	printf(" [3] Mostrar texto\n");
	printf(" [4] Deshacer\n");
	printf(" [5] Rehacer\n");
	printf(" [6] Limpiar pantalla\n");
	printf(" [7] Guardar\n");
	printf(" [8] Salir\n");
	do
	{
		
			printf(" \nSeleccione una opción:  ");
			scanf_s("%d", &opcion);
			getchar();
			if (opcion < 1 || opcion>8)
				printf("Favor de ingresar valor valido\n");

		switch (opcion)
		{
		case 1:
			AgregarRenglon(pText, nombre, pDeshacer);
			break;
		case 2:
			EliminarRenglon(pText, nombre, pDeshacer);
			break;
		case 3:
			ImprimirRenglones(pText);
			break;
		case 4: 
			Deshacer(pText, nombre,pDeshacer,pRehacer);
			break;
		case 5: 
			Rehacer(pText, nombre, pDeshacer, pRehacer);
			break;
		case 6:
			system("cls");
			{
				printf("EDITOR DE TEXTO V1.0\n\n");
				printf(" [1] Añadir Renglon\n");
				printf(" [2] Eliminar Renglon\n");
				printf(" [3] Mostrar texto\n");
				printf(" [4] Deshacer\n");
				printf(" [5] Rehacer\n");
				printf(" [6] Limpiar pantalla\n");
				printf(" [7] Guardar\n");
				printf(" [8] Salir\n");
			}
			break;
		case 7:
			DestroyDLL(pDeshacer);
			DestroyDLL(pRehacer);
			pRehacer = CreateDLL();
			pDeshacer = CreateDLL();
			printf("Se guardo el archivo %s\n", nombre);
			guardarArchivo(pText,nombre);
			break;
		case 8:
			DestroyDLL(pText);
			DestroyDLL(pDeshacer);
			DestroyDLL(pRehacer);
			break;
		}
	} while (opcion != 8);
}


