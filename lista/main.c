#include <stdio.h>
#include <stdlib.h>

typedef struct NODO{
    int dato;
    struct NODO *sig;
}NODO;

void cargar(NODO *q);
void mostrar(NODO *q,int i);

NODO* incertarCabeza(NODO *q);
void incertarCuerpo(NODO *q);

NODO* eliminarCabeza(NODO *q);
void eliminarCuerpo(NODO *q);

int main()
{
    NODO *p = NULL;
    p = (NODO*)malloc(sizeof(NODO));

    cargar(p);
    mostrar(p,0);

    incertarCuerpo(p);
    p = incertarCabeza(p);
    mostrar(p,0);

    p = eliminarCabeza(p);
    eliminarCuerpo(p);
    mostrar(p,0);

    return 0;
}


void cargar(NODO *q){
    if(q->sig == NULL){
        printf("\nSe salio de la carga");
        return 0;
    }else{
        printf("\nAgregue un dato !=0: ");
        scanf("%d",&q->dato);
        if (q->dato == 0){
            q->sig = NULL;
        }else{
            q->sig = (NODO*)malloc(sizeof(NODO));
            cargar(q->sig);
        }
    }
}

void mostrar(NODO *q,int i){
    if(q->sig == NULL){
        printf("\nSe mostro todo");
        return 0;
    }else{
        printf("\nNodo valor:%d | Nodo posicion: [%d]",q->dato,i);
        mostrar(q->sig,i+1);
    }
}

NODO* incertarCabeza(NODO *q){
    NODO *aux = NULL;
    if(q->dato == 3){
        aux = (NODO*)malloc(sizeof(NODO));
        aux->dato = 6;
        aux->sig = q;
        q = aux;
    }
    return q;
}

void incertarCuerpo(NODO *q){
    NODO *aux = NULL;
    while(q->sig != NULL && q->sig->sig != NULL){
        if (q->sig->dato == 3)
        {
            aux = (NODO*)malloc(sizeof(NODO));
            aux->dato = 6;
            aux->sig = q->sig;
            q->sig = aux;
            q=q->sig->sig; // ponele 5 3 agrega 5 6 3 y saltea al 6 y se para en el 3
        }
        q=q->sig;
    }
}


NODO* eliminarCabeza(NODO *q){
    NODO *aux = NULL;
    while(q->dato == 5){
        aux = q->sig;
        free(q);
        q = aux;
    }
    return q;
}

void eliminarCuerpo(NODO *q){
    NODO *aux = NULL;
    while(q->sig != NULL && q->sig->sig != NULL){
        if(q->sig->dato == 5){
            aux = q->sig->sig;
            free(q->sig);
            q->sig = aux;
        }
        else{
            q = q->sig;
        }
    }
}
