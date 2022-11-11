#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

// Codigo Generado en 2020 por:
// Juan Javier Valdiviezo
// Alberto Soriano
// Juan Javier Malo

/*
    Este programa es un ejemplo de como se puede
    utilizar la memoria dinamica para crear una
    aplicacion para una farcia. Que ingresa medicamentos a su sistema.
*/

typedef struct MEDICINAS{
    char nombre[25];
    struct ing *ingre;
    struct med *sig;
}med;

typedef struct INGREDIENTES{
    struct comp *compo;
    double cantidad;
    struct uni *unidad;
    struct ing *sig;
}ing;

typedef struct COMPONENTES{
    char descripcion[20];
    char origen[15];
    struct comp *sig;
}comp;

typedef struct UNIDADES{
    char descripcion[15];
    struct uni *sig;
}uni;

med *cabezamed = NULL;
med *nuevomed = NULL;

ing *nuevoing = NULL;

comp *cabezacomp = NULL;
comp *nuevocomp = NULL;

uni *cabezauni = NULL;
uni *nuevouni = NULL;

void nuevaMed(){
    nuevomed = NULL;
    nuevomed = (med*)malloc(sizeof(med));
}

void nuevoIngre(){
    nuevoing = NULL;
    nuevoing = (ing*)malloc(sizeof(ing));
}

void nuevoCompo(char *des, char *ori){
    int i;
    nuevocomp =  NULL;
    nuevocomp = (comp*)malloc(sizeof(comp));

    for(i=0;i<=strlen(des);i++){
        nuevocomp->descripcion[i] = des[i];
    }
    
    for(i=0;i<=strlen(ori);i++){
        nuevocomp->origen[i] = ori[i];
    }

    nuevocomp->sig = cabezacomp;
    cabezacomp = nuevocomp;
    des =NULL;
    ori =NULL;
}

void nuevaUnid(char des[]){
    int i;
    nuevouni = NULL;
    nuevouni = (uni*)malloc(sizeof(uni));

    for(i=0;i<=strlen(des);i++){
        nuevouni->descripcion[i] = des[i];
    }

    nuevouni->sig = cabezauni;
    cabezauni = nuevouni;
    des = NULL;
}

//Prototipos
void ingresoDatos();
void ingresarMed();
void listarMed();
void borrarMed();
void borrarTodo();
comp *elegirComp();
uni *elegirUni();

int main(){

    int sel;
    ingresoDatos();

    do{
        system("CLS");
        printf("Sistema de Datos de Farmacia\n\n");
        printf("1) Ingresar nueva medicina\n");
        printf("2) Listar Medicina\n");
        printf("3) Borrar una Medicina\n");
        printf("4) Salir\n\n");
        printf("Opcion:   ");
        scanf("%d",&sel);
		
        switch(sel){
            case 1:{
                system("CLS");
                ingresarMed();
                system("CLS");
                break;
            }
            case 2:{
                system("CLS");
                listarMed();
                system("CLS");
                break;
            }
            case 3:{
                system("CLS");
                borrarMed();
                system("CLS");
                break;
            }
            case 4:{
                system("CLS");
                printf("Programa Finalizado\n\n");
				break;
			}
            
            default: printf("Ingrese una opcion valida\n");
            Sleep(1000);
            break;
        }

    }while(sel != 4);

    borrarTodo();

    system("PAUSE");
    return 0;
}

void ingresoDatos(){
    nuevoCompo("Cloroxin","EEUU");
    nuevoCompo("Oxigenol","Brazil");
    nuevoCompo("Calsina","China");
    nuevoCompo("Amoxisilina","Peru");
    nuevoCompo("Clonoxiferol","Inglaterra");
    nuevoCompo("Metronoxina","Brazil");
    nuevaUnid("Litro");
    nuevaUnid("Miligramo");
    nuevaUnid("Mililitro");
    nuevaUnid("Gramo");
}

void ingresarMed(){
    nuevaMed();
    double cantidad;
    char nombre[25];
    ing *inicio = nuevomed->ingre;
    int i,n;

    printf("Ingresando Medicina\n");
    Sleep(1000);
    system("CLS");
    printf("Ingrese el nombre de la medicina\n");
    scanf("%s",nombre);
    for(i=0;nombre[i]!='\0';i++){
        nuevomed->nombre[i] = nombre[i];
    }

    do{
        system("CLS");
        printf("Numero de Ingredientes de la Medicina\n");
        scanf("%d",&n);
        if(n<=0){
            printf("Ingrese una cantidad mayor a 0\n");
            Sleep(300);
        }
    }while(n<=0);

    inicio = NULL;
    
    for(i=1;i<=n;i++){
        system("CLS");
        printf("Ingresando Ingrediente #%d\n",i);
        Sleep(1000);
        nuevoIngre();
        nuevoing->compo = elegirComp();
        nuevoing->unidad = elegirUni();
        printf("\nIngrese la cantidad a usar\n");
        scanf("%lf",&cantidad);
        nuevoing->cantidad = cantidad;

        nuevoing->sig = inicio;
        inicio = nuevoing;

        printf("\nIngrediente Ingresado\n");
        Sleep(500);
    }

    nuevomed->ingre = inicio;

    nuevomed->sig = cabezamed;
    cabezamed = nuevomed;

    printf("\nIngredientes Ingresados\n");
    Sleep(300);
}

comp *elegirComp(){
    int i=1,sel;
    comp *aux;
    do{
        system("CLS");
        i=1;
        aux = cabezacomp;
        printf("\nElija un Componete\n\n");

        while(aux!=NULL){
            printf("%d) %s\n",i,aux->descripcion);
            i++;
            aux = aux->sig;
        }
        printf("\nElejir:  ");
        scanf("%d",&sel);
        if(sel<1 || sel>=i){
            printf("Ingrese un valor valido\n");
            Sleep(300);
		}

    }while(sel<1 || sel>=i);

    aux = cabezacomp;
    
    for(i=1;i<sel;i++){
        aux = aux->sig;
    }
    return aux;
}

uni *elegirUni(){
    int i=1,sel;
    uni *aux;
    do{
        system("CLS");
        i=1;
        aux = cabezauni;
        printf("\nElija una Unidad\n\n");

        while(aux!=NULL){
            printf("%d) %s\n",i,aux->descripcion);
            i++;
            aux = aux->sig;
        }
        printf("\nElejir:  ");
        scanf("%d",&sel);
        
        if(sel<1 || sel>=i){
            printf("Ingrese un valor valido\n");
            Sleep(300);
		}
    }while(sel<1 || sel>=i);

    aux = cabezauni;
    
    for(i=1;i<sel;i++){
        aux = aux->sig;
    }
    return aux;
}

void listarMed(){
    med *auxmed = cabezamed;
    ing *auxing;
    comp *auxcomp;
    uni *auxuni;
    int i=0;

    printf("|   Medicina   |   Ingredientes   |   Origen   |   Cantidad  |   Unidad  |\n");
    printf("--------------------------------------------------------------------------\n");

    while(auxmed!=NULL){
        i=0;
        printf("|%14.14s",auxmed->nombre);
        auxing = auxmed->ingre;
        while(auxing != NULL){
            auxcomp = auxing->compo;
            auxuni = auxing->unidad;
            if(i==0){
            i=1;
                printf("|%18.18s",auxcomp->descripcion);
            }
            else{
                printf("|\t       |%18.18s",auxcomp->descripcion);
            }
            //printf("|%12.12s","Brazil");
            printf("|%12.12s",auxcomp->origen);
            printf("|%13.2f",auxing->cantidad);
            printf("|%11.11s|\n",auxuni->descripcion);
            auxing = auxing->sig;
        }
        auxmed = auxmed->sig;
        printf("--------------------------------------------------------------------------\n");
    }
    
    printf("\n\n");
    system("PAUSE");
}

void borrarMed(){
}

void borrarTodo(){
    med *auxmed = cabezamed, *auxmed2;
    ing *auxing, *auxing2;
    comp *auxcomp = cabezacomp, *auxcomp2;
    uni *auxuni = cabezauni, *auxuni2;

    while(auxmed!=NULL){
        auxing = auxmed->ingre;
        while(auxing!=NULL){
            auxing2 = auxing->sig;
            free(auxing);
            auxing = auxing2;
        }
        auxmed2 = auxmed->sig;
        free(auxmed);
        auxmed =auxmed2;
    }
    while(auxcomp!=NULL){
        auxcomp2 = auxcomp->sig;
        free(auxcomp);
        auxcomp = auxcomp2;
    }
    while(auxuni!=NULL){
        auxuni2 = auxuni->sig;
        free(auxuni);
        auxuni = auxuni2;
    }
}


