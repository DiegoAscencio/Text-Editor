#include<stdio.h>

void crearArchivo() {
	FILE* archivo;
	char texto[501];
	int i = 0;
	archivo = fopen_s("Archivo.txt", "w+");//Abre el archivo para escritura
	/*printf("Introduzca lo que dira el archivo\n");
	scanf(" %[^\n]s", texto);
	while (texto[i] != '\0') {//Escribe el arreglo que acaba de recibir en el archivo
		fwrite(&texto[i], sizeof(char), 1, archivo);
		i++;
	}*/
	fclose(archivo);//Cierra archivo
}