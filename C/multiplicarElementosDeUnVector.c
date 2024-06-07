#include <stdio.h>

void cargar(int vec[], int tam){
    unsigned short i;
    for(i=0;i<tam;i++){
        printf("\nCargar dato: ");
        scanf("%d",&vec[i]);
    }
}

int multiplicar(int vec[],int tam,int i){
    if (i==tam){
        return 1;
    }
    return vec[0+i] * multiplicar(vec,tam,i+1);
}

int main(){
    int vec[10], tam = 3;
    cargar(vec,tam);
    printf("%d",multiplicar(vec,tam,0));
}
