#include <stdio.h>

void cargar(int mat[][5],int dim); // [5] para que sepa c cuando cortar el vector en filas
void mostrar(int mat[][5],int dim);
void primos(int mat[][5],int dim);
void maximo(int mat[][5],int dim);
int divisores(int num);

int main()
{
    int mat[5][5],dim; // matriz en c
    printf("Ingrese cantidad de filas: ");
    scanf("%d",&dim);
    cargar(mat,dim);
    mostrar(mat,dim);
    primos(mat,dim);
    maximo(mat,dim);

    return 0;
}

void cargar(int mat[][5],int dim){
    unsigned short i,j;
    for(i=0;i<dim;i++){
        for(j=0;j<dim;j++){
            printf("\nIngrese valor en posiciones y[%d]x[%d]: ",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
}

void mostrar(int mat[][5], int dim){
    unsigned short i,j;
    for(i=0;i<dim;i++){
        printf("\n");
        for(j=0;j<dim;j++){
            printf("\t %d ",mat[i][j]);
        }
    }
}

int divisores(int num){
    unsigned short i,primo=0;
    for(i=2;i<num;i++){
        if(num%i==0){
            primo++;
        }
    }
    return primo;
}

void primos(int mat[][5],int dim){
    unsigned short i,j,cont,p;
    for(i=0;i<dim;i++){
        printf("\n");
        for(j=0;j<dim;j++){
            p = divisores(mat[i][j]);
            if(p==0){
                cont++;
            }
        }
    }
    printf("\n Cantidad de num primos es %d ",cont);
}

void maximo(int mat[][5],int dim){
    unsigned short i,j,max=mat[0][0],pos[2];
    for(i=0;i<dim;i++){
        printf("\n");
        for(j=0;j<dim;j++){
            if(max<mat[i][j]){
                max=mat[i][j];
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
    printf("El maximo es %d en la posicion %d %d",max,pos[0],pos[1]);
}
