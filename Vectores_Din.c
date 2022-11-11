#include <stdlib.h>
#include <stdio.h>

int main()
{
    system("cls");
    int i;
    int cantidad;

    printf("Ingrese la cantidad de numeros a ingresar: ");
    scanf("%d",&cantidad);

    int *numeros = (int*)malloc(sizeof(int)*cantidad);

    for (i = 0; i < cantidad; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", (numeros+i));
    }

    printf("\nLos numeros ingresados son: \n");

    for (i = 0; i < cantidad; i++)
    {
        printf("El numero %d es %d en memoria: %x.\n", i, *(numeros+i), (numeros+i));
    }

    system("PAUSE");

    for (i = 0; i < cantidad; i++)
    {
        free((numeros+i));
    }

    return 0;
}