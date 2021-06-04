#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char ***matrix;
}Matrix;

char ***crear(int, int);
char ****array(int, int, int, int);
Matrix ***crearMatriz(int, int, int, int);
void mostrarMatrizDeMatrices(Matrix***, int, int, int, int);

int main(void)
{	
	int x, y, a, b;

	printf("Tamano filas matriz madre: ");
	scanf("%d", &x);
	printf("Tamano columnas matriz madre: ");
	scanf("%d", &y);
	printf("Tamano filas matriz hija: ");
	scanf("%d", &a);
	printf("Tamano columnas matriz hija: ");
	scanf("%d", &b);

	Matrix ***matriz = crearMatriz(x, y, a, b); 
	mostrarMatrizDeMatrices(matriz, x, y, a, b);
	
	return 0;
}

char ***crear(int x, int y)
{
	char ***mat = calloc(x, sizeof(char**));
	for(int i = 0; i < x; i++)
	{
		*(mat + i) = calloc(y, sizeof(char*));
		for(int j = 0; j < y; j++)
		{
			*(*(mat + i) + j) = calloc(x*y, sizeof(char));
			printf("Dato[%d][%d]: ", i, j);
			scanf("%s", *(*(mat + i) + j));
		}
	}

	return mat;
}

char ****array(int x, int y, int a, int b)
{
	char ****arrayM;

	arrayM = calloc(x * y, sizeof(***arrayM));
	for(int i = 0; i < x*y; i++)
	{
		*(arrayM + i) = crear(a, b);
	}	

	return arrayM;
}

Matrix ***crearMatriz(int x, int y, int a, int b)
{
	Matrix ***matriz;
	int cont = 0;

	char ****arrayM = array(x, y, a, b);

	matriz = calloc(x, sizeof(Matrix**));
	for(int i = 0; i < x; i++)
	{
		*(matriz + i) = calloc(y, sizeof(Matrix*));
		for(int j = 0; j < y; j++)
		{
			*(*(matriz + i)+ j) = calloc(x * y, sizeof(Matrix));
			(* *(*(matriz+i)+j) ).matrix = *(arrayM + cont);
			cont++;
		}
	}

	return matriz;
}

void mostrarMatrizDeMatrices(Matrix*** matriz, int x, int y, int a, int b)
{
	for(int i = 0; i < x; i++)
	{
		for(int i2 = 0; i2 < a; i2++)
		{
			for(int j = 0; j < y; j++)
			{
				for(int j2 = 0; j2 < b; j2++)
				{
					printf("| %s |", (* *(*(matriz+i)+j) ).matrix[i2][j2]);
				}
				printf("%s", (j == y - 1) ? " " : " -> ");
				free((* *(*(matriz+i)+j) ).matrix[i2]);
			}
			printf("\n");
		}
		printf("\n");
		free(*(matriz + i));
	}
	free(matriz);
}
