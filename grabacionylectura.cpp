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
	printf("dame matricula :");scanf("%d",&alumno.matricula);getchar();
	printf("dame nombre :");gets(alumno.nombre);
	printf("dame edad :");scanf("%d",&alumno.edad);
	return 0;
}
