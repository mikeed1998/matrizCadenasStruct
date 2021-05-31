#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct MatrizCadena
{
	int x;
	int y;
	char ***matriz;
};

typedef struct
{
	struct MatrizCadena matrizCadena;
}ListaMatrices;

ListaMatrices *insertarDatos(int, int);
void mostrarDatos(ListaMatrices*);

int main(int argc, char *argv[])
{
	int posX, posY;

	printf("Ingresa la cantidad de filas: ");
	scanf("%d", &posX);
	printf("Ingresa la cantidad de columnas: ");
	scanf("%d", &posY);

	ListaMatrices *(*ptrInsertarDatos)(int, int) = &insertarDatos;
	ListaMatrices *_lista = ptrInsertarDatos(posX, posY);
	
	mostrarDatos(_lista);

	return 0;
}

ListaMatrices *insertarDatos(int _x, int _y)
{
	ListaMatrices *lista = (ListaMatrices*)malloc(sizeof(ListaMatrices));
	
	lista->matrizCadena.x = _x;
	lista->matrizCadena.y = _y;
	
	lista->matrizCadena.matriz = calloc(lista->matrizCadena.x, sizeof(char**));
	for(int i = 0; i < lista->matrizCadena.x; i++)
	{
		*(lista->matrizCadena.matriz + i) = calloc(lista->matrizCadena.y, sizeof(char*));
		for(int j = 0; j < lista->matrizCadena.y; j++)
		{
			*(*(lista->matrizCadena.matriz + i) + j) = malloc(sizeof(char) * (lista->matrizCadena.x * lista->matrizCadena.y) );
			printf("Dato [%d][%d]: ", i, j);
			getchar();
			scanf("%10[0-9a-zA-Z ]", *(*(lista->matrizCadena.matriz + i) + j));
		}
	}

	return lista;
}

void mostrarDatos(ListaMatrices* lista)
{
	for(int i = 0; i < lista->matrizCadena.x; i++)
	{
		printf("|");
		for(int j = 0; j < lista->matrizCadena.y; j++)
		{
			printf(" %s |", *(*(lista->matrizCadena.matriz + i) + j));
		}	
		printf("\n");
		free(*(lista->matrizCadena.matriz + i));
	}
	free(lista->matrizCadena.matriz);
	free(lista);
}
