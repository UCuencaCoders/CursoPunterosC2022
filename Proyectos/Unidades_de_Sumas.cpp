#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

// Codigo Generado en 2020 por:
// Juan Javier Valdiviezo
// Alberto Soriano
// Juan Javier Malo

/*El objetivo del codigo es mejorar el manejo de punteros.
El Codigo pide al usuario un numero par, genera un vector de enteros del tamanio ingresado
Luego genera un vector de la suma de cada uno de sus extremos de afuera hacia adentro.
Divide los numeros por unidad y los muestra en una tabla.
Finalmente muestra la misma tabla pero de forma ordenada.*/

using namespace std;
struct misCifras
{
    int u;
    int d;
    int c;
    int um;
    int dm;
    int *elemento;
};

void gotoxy(int x, int y)
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void ordenar(int tam, int *sumas, int **sumasOrden)
{

    int i, j, *aux;

    for (i = 0; i < tam; i++)
    {
        sumasOrden[i] = (sumas + i);
    }

    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam - 1; j++)
        {
            if (*sumasOrden[j] > *sumasOrden[j + 1])
            {
                aux = sumasOrden[j];
                sumasOrden[j] = sumasOrden[j + 1];
                sumasOrden[j + 1] = aux;
            }
        }
    }
}

void extremos(int *numeros, int n, int *sumas)
{
    int i, j, h, k;
    k = n / 2;
    j = 0;
    h = n - 1;
    for (i = 0; i < k; i++)
    {
        *(sumas + i) = numeros[j] + numeros[h];
        j++;
        h--;
    }
}

int validacion()
{
    int s, y, i;
    char x[50];
    do
    {
        system("cls");

        do
        {
            gotoxy(0, 0);
            system("cls");
            cout << "Ingrese un numero par \n";
            gotoxy(11, 2);
            printf("%c", 196);
            gotoxy(10, 2);
            printf("%c", 192);
            gotoxy(12, 2);
            printf("%c", 217);
            gotoxy(11, 1);
            cin >> x;
            system("cls");
            i = 0;
            y = 0;
            do
            {
                i++;
                if (isalpha(x[i]))
                {
                    y = 1;
                };

            } while (x[i] != '\0');

        } while (y == 1);

        s = atoi(x);

        if ((s > 0) && (s % 2 == 0))
        {
            y = 1;
        }
    } while (y == 0);
    gotoxy(0, 0);
    return s;
}

void mostrarv(int *vectorh, int len)
{
    int d;
    d = 0;
    for (int i = 0; i < len; i++)
    {
        printf("[ %5d ]", *(vectorh + i));
        d++;
        if (d == 10)
        {
            printf("\n");
            d = 0;
        }
    }
}

void cifras(int *sumas, int tam, misCifras *vect)
{

    misCifras mc;
    int i, j, h, f, l, num;

    float k;

    // Tabla

    for (i = 0; i < tam; i++)
    {
        h = 10000;
        mc.elemento = (sumas + i);
        for (j = 0; j < 5; j++)
        {

            if (j == 0)
            {
                num = *(sumas + i);
                k = num;
            }
            k = num;
            k = k / h;

            if (k >= 1)
            {
                l = k;
                switch (j)
                {
                case 0:
                    mc.dm = l;
                    break;
                case 1:
                    mc.um = l;
                    break;
                case 2:
                    mc.c = l;
                    break;
                case 3:
                    mc.d = l;
                    break;
                case 4:
                    mc.u = l;
                    break;
                }

                f = k;
                f *= h;
                num -= f;
            }

            else
            {
                switch (j)
                {
                case 0:
                    mc.dm = 0;
                    break;
                case 1:
                    mc.um = 0;
                    break;
                case 2:
                    mc.c = 0;
                    break;
                case 3:
                    mc.d = 0;
                    break;
                case 4:
                    mc.u = 0;
                    break;
                }
            }
            h = h / 10;
        }
        vect[i].elemento = mc.elemento;
        vect[i].u = mc.u;
        vect[i].d = mc.d;
        vect[i].c = mc.c;
        vect[i].um = mc.um;
        vect[i].dm = mc.dm;
    }
}

void mostraC(misCifras *vect, int tam)
{
    int i, j, y, xgot, l;
    bool cero;

    // Tabla
    gotoxy(3, 9);
    printf("Numeros");
    for (y = 0; y < tam + 1; y++)
    {
        gotoxy(12, 9 + y);
        printf("%c", 179);
    }
    gotoxy(14, 9);
    printf("  U  D  C  um dm ");

    for (i = 0; i < tam; i++)
    {
        gotoxy(3, 10 + i);
        printf("%5d", *vect[i].elemento);
        xgot = 28;
        cero = false;
        for (j = 0; j < 5; j++)
        {
            switch (j)
            {
            case 0:
                l = vect[i].dm;
                break;
            case 1:
                l = vect[i].um;
                break;
            case 2:
                l = vect[i].c;
                break;
            case 3:
                l = vect[i].d;
                break;
            case 4:
                l = vect[i].u;
                break;
            }
            if (l >= 1)
            {
                cero = true;
                gotoxy(xgot, 10 + i);
                printf("%d", l);
            }
            else
            {
                if (cero == true)
                {
                    gotoxy(xgot, 10 + i);
                    printf("0");
                }
            }

            xgot -= 3;
        }
    }
    gotoxy(0, 9 + tam + 1);
}

int main()
{
    system("color F1");
    // Ingreso de n
    int n, j, i, y, tam, l, xgot, f;
    bool cero;
    n = validacion();

    // Valores
    int numeros[n]; // Stack
    int *sumas;
    int **miPuntero;
    tam = n / 2;

    // Random
    srand(time(NULL));

    sumas = (int *)malloc(sizeof(int) * (n / 2)); // Heap

    // Llenar vector principal con random
    for (i = 0; i < n; i++)
    {
        numeros[i] = rand();
    }

    // Imprimir el vector original
    printf("Vector numeros= \n");
    mostrarv(numeros, n);

    // Se suman los extremos
    extremos(numeros, n, sumas);

    // Imprime las sumas
    printf("\n Vector sumas= \n");
    mostrarv(sumas, (n / 2));

    // Calcula la estructura de las cifras
    misCifras detalleCifras[(n / 2)];
    cifras(sumas, (n / 2), detalleCifras);

    // Muestra las cifras
    for (i = 0; i < 40; i++)
    {
        gotoxy(0 + i, 6);
        printf("-");
    }
    printf("\n Cifras de Sumas \n");

    mostraC(detalleCifras, (n / 2));
    printf("\n");

    // Ordenar vect sumas
    int *sumasOrden[n / 2];
    ordenar(n / 2, sumas, sumasOrden);

    // Punto 8
    miPuntero = &sumasOrden[0];
    // Tabla
    for (i = 0; i < 40; i++)
    {
        gotoxy(0 + i, 11 + tam);
        printf("-");
    }
    printf("\n Numeros Ordenados \n");

    gotoxy(3, 14 + tam);
    printf("Numeros");
    for (y = 0; y < (tam + 1); y++)
    {
        gotoxy(12, 14 + y + (n / 2));
        printf("%c", 179);
    }
    gotoxy(14, 14 + tam);
    printf("  U  D  C  um dm ");

    int linea = 14 + tam;

    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < tam; j++)
        {
            if (detalleCifras[j].elemento == *(miPuntero + i))
            {

                gotoxy(3, linea + 1 + i);
                printf("%5d", *detalleCifras[j].elemento);
                xgot = 28;
                cero = false;

                for (f = 0; f < 5; f++)
                {

                    switch (f)
                    {
                    case 0:
                        l = detalleCifras[j].dm;
                        break;
                    case 1:
                        l = detalleCifras[j].um;
                        break;
                    case 2:
                        l = detalleCifras[j].c;
                        break;
                    case 3:
                        l = detalleCifras[j].d;
                        break;
                    case 4:
                        l = detalleCifras[j].u;
                        break;
                    }

                    if (l >= 1)
                    {
                        cero = true;
                        gotoxy(xgot, linea + 1 + i);
                        printf("%d", l);
                    }

                    else
                    {
                        if (cero == true)
                        {
                            gotoxy(xgot, linea + 1 + i);
                            printf("0");
                        }
                    }

                    xgot -= 3;
                }
            }
        }
    }
    gotoxy(0, linea + tam + 2);

    free(sumas);

    system("PAUSE");

    return 0;
}
