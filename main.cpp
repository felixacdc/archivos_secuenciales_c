#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct {
	int matricula;
	char nombre[30];
	int edad;
}alumno;

int main() {
	//creando y cerrando el archivo en disco
	FILE *archdisco;
	archdisco = fopen("alumnos.dat","w");
	fclose(archdisco);
	printf("ARCHIVO CREADO");
	return 0;
}

/*
“r” ? Lectura.

“w” ? Escritura.

“a” ? Append, si el archivo ya existe append empieza a añadir los nuevos datos al final del archivo ya existente.

“r+” ? Lectura y escritura, ya debe existir el archivo.

“w+” ? Crea para lectura y escritura y si ya existe, sobreescribe.

“a+” ? Crea o abre para lectura y append, sino existe el archivo sera creado. 
*/
