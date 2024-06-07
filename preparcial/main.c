#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
int num;
struct lista *sig;
}nodo;

void crear(nodo *pt);
void mostrar(nodo *pt);

void buscarIncertar(nodo *pt,int valor);

nodo* eliminarh(nodo *pt);
void eliminarb(nodo *pt);

void generar(nodo *pt, nodo *tp);

int main()
{
    nodo *prin=NULL;
    prin=(nodo*)malloc(sizeof(nodo));
    crear(prin);
    printf("\n------------------\n");
    mostrar(prin);
    printf("\n------------------\n");

    int valor = 0;

    printf("Buscar un valor: ");
    scanf("%d",&valor);
    buscarIncertar(prin,valor);
    mostrar(prin);
    printf("\n------------------\n");

    prin = eliminarh(prin);
    eliminarb(prin);
    mostrar(prin);
    printf("\n------------------\n");

    nodo *tp = (nodo*)malloc(sizeof(nodo));
    generar(prin, tp);
    mostrar(tp);
    printf("\n------------------\n");

    return 0;
}

void crear (nodo *registro){
    scanf("%d",&registro->num);
    if (registro->num==-1)
        registro->sig=NULL;
    else{
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear(registro->sig);
    }
    return;
}

void mostrar (nodo *registro){
    if (registro->sig !=NULL){
        printf ("%d\n",registro->num);
        mostrar (registro->sig);
    }
    return;
}


void buscarIncertar(nodo *pt,int valor){
    nodo *aux = NULL;
    int numero = valor;
    while (pt->sig != NULL){
        if (pt->num == valor){
                aux = pt->sig;
            while(numero != 0){
                pt->sig = (nodo*)malloc(sizeof(nodo));
                pt->sig->num = numero -1;
                numero--;
                pt = pt->sig;
            }
            pt->sig = aux;
            numero = valor;
        }
        pt = pt->sig;
    }
}

nodo* eliminarh(nodo *pt){
    nodo *aux = NULL;
    while(pt->num % 2 == 0){
        aux = pt->sig;
        free(pt);
        pt = aux;
    }
    return pt;
}

void eliminarb(nodo *pt){
    nodo *aux = NULL;
    while(pt->sig != NULL && pt->sig->sig !=NULL){
        if (pt->sig->num % 2==0){
            aux = pt->sig->sig;
            free(pt->sig);
            pt->sig = aux;
        }
        else{
            pt = pt->sig;
        }
    }
}

void generar(nodo *pt, nodo *tp){
    while(pt->sig!=NULL){
        tp->num = (pt->num/2);
        tp->sig = (nodo*)malloc(sizeof(nodo));
        tp = tp->sig;
        pt = pt->sig;
    }
    tp->sig = NULL;
}
