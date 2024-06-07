#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
} treenode;

void crear(treenode **hoja ,int *menora);
void insertar(treenode **hoja, int elem);
void mostrar(treenode *hoja);

int main()
{
    int menora = 0;
    printf("arboles\n");
    treenode *arbol = NULL;
    crear(&arbol,&menora);
    printf("**************\n");
    printf("mostrar arbol\n");
    printf("***************\n");
    mostrar(arbol);
    mostrariz(arbol,menora);
    printf("menor numero: %d",menora);
    return 0;
}
void crear(treenode **hoja,int *menora)
{
    int numero;
    printf("ingrese numero\n");
    scanf("%d", &numero);
    *menora = numero;
    while (numero != -1)
    {
        insertar(&(*hoja), numero);
        printf("ingrese numero\n");
        scanf("%d", &numero);
        if (*menora > numero && numero != -1){
            *menora = numero;
        }
    }
}
void insertar(treenode **hoja, int elem)
{
    int numero = elem;
    if (elem == -1)
        return;
    if (*hoja == NULL)
    {
        // creo la hoja vacia
        (*hoja) = (treenode *)malloc(sizeof(treenode));
        (*hoja)->dato = elem;
        (*hoja)->der = NULL;
        (*hoja)->izq = NULL;
    }
    else
    {
        if (numero > (*hoja)->dato)
        {
            insertar(&(*hoja)->der, elem);
        }
        else
        {
            insertar(&(*hoja)->izq, elem);
        }
    }
    return;
}
void mostrar(treenode *hoja)
{
    if (hoja != NULL)
    {
        mostrar(hoja->izq);
        printf("%d ", hoja->dato);
        mostrar(hoja->der);
        if(hoja->izq == NULL && hoja->der == NULL){
            printf("\nHoja valor: %d\n",hoja->dato);
        }
    }
    return;
}

void mostrariz(treenode *hoja,int menora)
{
    if (hoja != NULL)
    {
        mostrar(hoja->izq);
        if (hoja->dato <= menora){
            printf("%d ", hoja->dato);
        }
        mostrar(hoja->der);
    }
    return;
}
