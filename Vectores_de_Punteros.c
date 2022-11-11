#include <stdlib.h>
#include <stdio.h>

int main(){

    system("cls");

    int i, j;
    int *numeros[5];

    for (i = 0; i < 5; i++)
    {
        numeros[i] = (int*)malloc(sizeof(int));
        printf("Ingrese un numero: ");
        scanf("%d",numeros[i]);
    }

    printf("\nLos numeros ingresados son: \n");

    for (i = 0; i < 5; i++)
    {
        printf("El numero %d es %d en memoria: %x.\n",i,*numeros[i], numeros[i]);
    }

    system("PAUSE");

    for (i = 0; i < 5; i++)
    {
        free(numeros[i]);
    }

    return 0;
}