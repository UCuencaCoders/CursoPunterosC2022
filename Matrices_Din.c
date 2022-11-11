#include <stdlib.h>
#include <stdio.h>

int main(){

    system("cls");
    
    int i, j;
    int **matriz;
    int filas, columnas;

    printf("Ingrese el numero de filas: ");
    scanf("%d",&filas);

    printf("Ingrese el numero de columnas: ");
    scanf("%d",&columnas);

    matriz = (int**)malloc(sizeof(int*)*filas);

    for (i = 0; i < filas; i++)
    {
        printf("Crea Fila %d.\n",i+1);
        *(matriz+i) = (int*)malloc(sizeof(int)*columnas);
    }

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("Ingrese un numero: ");
            scanf("%d",(*(matriz+i)+j));
        }
    }

    printf("\nLos numeros ingresados son: \n");

    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("La celda [%d][%d] es %d en memoria: %x.\n", i, j, *(*(matriz+i)+j), (*(matriz+i)+j));
        }
    }

    system("PAUSE");

    for (i = 0; i < filas; i++)
    {
        free(*(matriz+i));
    }

    free(matriz);

    return 0;
}