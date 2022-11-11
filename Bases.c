#include <stdio.h>
#include <stdlib.h>

int main(){

    int num1, num2;
    int *ptr1, *ptr2;

    ptr1 = &num1;
    ptr2 = &num2;

    num1 = 10;
    num2 = 20;

    *ptr1 = 30;
    *ptr2 = 40;

    ptr2 = ptr1;

    printf("El puntero 1 es %d, y el puntero 2 es %d.\n",*ptr1,*ptr2);
    
    system("PAUSE");

    return 0;
}