#include <stdio.h>
#include <stdlib.h>

int cargar(int arr[]);
void mostrar(int arr[],int dim);

void cargaRec(int arr[],int dim,int i);

int main(){
    int *p = NULL;
    p = (int *)malloc(sizeof(int)); // reserva memoria en memoria dinamica y lo caste a puntero para que lo entienda p
    *p = 200;
    int *array = NULL;
    array = (int *)malloc(sizeof(int)*20); // reserva byte para un entero multiplicado por 20, o sea un array. hace el puntero arr y apunta a la primer posicion de la memoria reservada con malloc
//    int dim = cargar(array);
//    mostrar(array,dim);
    free(p);
    free(array); // livera la memoria

    int *arr = NULL;
    arr = (int *)malloc(10 * sizeof(int));
    cargaRec(arr,3,0);
    free(arr);
}

int cargar(int arr[]){
    printf("Digite dimension: ");
    int dim = 0,a;
    scanf("%d",&dim);
    unsigned short i = 0;
    for (i=0;i<dim;i++){
        printf("Cargar pos[%d]: ",i);
        scanf("%d",&a);
        *(arr+i) = a;
    }
    return dim;
}

void mostrar(int arr[],int dim){
    unsigned short i = 0;
    for (i=0;i<dim;i++){
        printf("\npos[%d] : valor:[%d] ",i,*(arr+i));
    }
}
void cargaRec(int arr[],int dim,int i){
    if (i==dim){
        return;
    }
    printf("Cargar pos[%d]: ",i);
    int a = 0;
    scanf("%d",&a);
    *(arr+i) = a;

    cargaRec(arr,dim,i+1);
}
