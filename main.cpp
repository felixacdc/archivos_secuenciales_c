#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void Crear();
void GrabarYLeer();
void Busqueda();
void Eliminar();

struct {
	int matricula;
	char nombre[30];
	int edad;
}alumno;

int main() {
	Crear();	
	GrabarYLeer();
	Busqueda();
	Eliminar();
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
	cout<<endl;	

	archdisco = fopen("alumnos.dat","at+");
	
	while(fread(&alumno,sizeof(alumno),1,archdisco)==1) {
		printf("MATRICULA =%d ",alumno.matricula); 
		printf(" NOMBRE =%s ",alumno.nombre); 
		printf(" MESES =%d ",alumno.edad); 
		printf("\n"); 
	};
	
	fclose(archdisco);
}

void Busqueda() {
	printf("\n");
	printf("dame matricula buscar:");
	int clave; 
	scanf("%d",&clave);
	getchar();
	
	FILE *archdisco;
	archdisco = fopen("alumnos.dat","at+");
	while(fread(&alumno,sizeof(alumno),1,archdisco)==1)
	{
		if ( clave == alumno.matricula)
		{ 
			printf("MATRICULA =%d ",alumno.matricula);
			printf(" NOMBRE =%s ",alumno.nombre);
			printf(" MESES =%d ",alumno.edad);
			printf("\n");
		};
	};
	
	fclose(archdisco);
}

void Eliminar() {
	printf("dame matricula eliminar:");
	int clave; scanf("%d",&clave);getchar();
	
	FILE *arch1;
	FILE *arch2;
	arch1 = fopen("alumnos.dat","r+");
	arch2 = fopen("temporal.dat","at+");
	
	while(fread(&alumno,sizeof(alumno),1,arch1)==1)
	{
		if ( clave != alumno.matricula) 
			fwrite(&alumno,sizeof(alumno),1,arch2);
	};
	
	fclose(arch1);
	fclose(arch2);
	remove("alumnos.dat");
	rename("temporal.dat","alumnos.dat ");
	puts("registro eliminado");
}
/*
“r” ? Lectura.

“w” ? Escritura.

“a” ? Append, si el archivo ya existe append empieza a añadir los nuevos datos al final del archivo ya existente.

“r+” ? Lectura y escritura, ya debe existir el archivo.

“w+” ? Crea para lectura y escritura y si ya existe, sobreescribe.

“a+” ? Crea o abre para lectura y append, sino existe el archivo sera creado. 
*/
