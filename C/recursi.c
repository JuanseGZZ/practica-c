#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct alumno{
    int documento;
    char nombre[20];
    char apellido[20];
    int nota;
    struct alumno *sig;
}nodo;

void crear(nodo *registro);

int main(){
    int i = 0;
    nodo *prin;
    prin = (nodo*)malloc(sizeof(nodo)); // crear la cabeza en el main porque si la creo en la funcion voy a perder la cabeza
    crear(prin);
    mostrar(prin);

    return 0;
}

void crear(nodo *registro){ // lo crea recursivamente
    printf("Ingrese documento");
    scanf("%d",&registro->documento);

    if(registro->documento==0){
        registro->sig=NULL;
    }
    else{
        registro->sig=(nodo*) malloc(sizeof(nodo));
        crear(registro->sig);
    }
}


void mostrar(nodo *registro){ // tambien muestra recursivamente
    if (registro->sig !=NULL){
        printf("%d\n",registro->documento);
        mostrar(registro->sig);
    }
    return;
}
