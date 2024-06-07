#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo *siguiente;  // Correcto: Uso de 'struct Nodo'
} Nodo;

typedef struct ListaEnlazada {
    Nodo *cabeza;             // Correcto: Uso de un puntero a 'Nodo'
} ListaEnlazada;

void inicializarLista(ListaEnlazada *lista) {
    lista->cabeza = NULL;
}

void agregarNodo(ListaEnlazada *lista, int dato) {
    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = lista->cabeza;
    lista->cabeza = nuevoNodo;
}

void imprimirLista(ListaEnlazada *lista) {
    Nodo *actual = lista->cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
}

int main() {
    ListaEnlazada lista;
    inicializarLista(&lista);

    agregarNodo(&lista, 10);
    agregarNodo(&lista, 20);
    agregarNodo(&lista, 30);


    imprimirLista(&lista);

    // Limpieza de memoria
    Nodo *temp;
    while (lista.cabeza != NULL) {
        temp = lista.cabeza;
        lista.cabeza = lista.cabeza->siguiente;
        free(temp);
    }

    return 0;
}

