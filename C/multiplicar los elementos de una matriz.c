#include <stdlib.h>


void cargar(int m[][10],int t);
void mostrar(int m[][10],int t);
int sumar(int m[][10],int t,int f,int c);

int main(){
    int matriz[10][10],d=0;
    printf("Distancia de la matriz: ");
    scanf("%d",&d);
    cargar(matriz,d);
    mostrar(matriz,d);
    printf("\n%d",sumar(matriz,d,0,0));
    return 0;
}

void cargar(int m[][10],int t){
    unsigned short int i,j;
    for(i=0;i<t;i++){
        for(j=0;j<t;j++){
            printf("Agregar valor a [%d][%d]: ",i,j);
            scanf("%d",&m[i][j]);
        }
    }
}

void mostrar(int m[][10],int t){
    unsigned short int i,j;
    for(i=0;i<t;i++){
        for(j=0;j<t;j++){
            printf("\nMatriz en{[%d][%d]}: %d",i,j,m[i][j]);
        }
    }
}


int sumar(int m[][10], int t, int f, int c) {
    if (f == t) {
        return 0;
    }
    if (c == t) {
        return sumar(m, t, f + 1, 0);
    }
    return m[f][c] + sumar(m, t, f, c + 1);
}
