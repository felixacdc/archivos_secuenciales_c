#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void Crear();
void GrabarYLeer();

struct {
	int matricula;
	char nombre[30];
	int edad;
}alumno;

int main() {
	Crear();	
	GrabarYLeer();
	return 0;
}

void Crear() {
	FILE *archdisco;
	archdisco = fopen("alumnos.dat","w");
	fclose(archdisco);
	printf("ARCHIVO CREADO");
	cout<<endl;
}

void GrabarYLeer() {
	printf("dame matricula :");
	scanf("%d",&alumno.matricula);
	getchar();
	
	printf("dame nombre :");
	gets(alumno.nombre);
	
	printf("dame edad :");
	scanf("%d",&alumno.edad);
	
	FILE *archdisco;
	archdisco = fopen("alumnos.dat","at+");
	fwrite(&alumno,sizeof(alumno),1,archdisco);
	fclose(archdisco);
	
	printf("alumno insertado");
}
/*
“r” ? Lectura.

“w” ? Escritura.

“a” ? Append, si el archivo ya existe append empieza a añadir los nuevos datos al final del archivo ya existente.

“r+” ? Lectura y escritura, ya debe existir el archivo.

“w+” ? Crea para lectura y escritura y si ya existe, sobreescribe.

“a+” ? Crea o abre para lectura y append, sino existe el archivo sera creado. 
*/
