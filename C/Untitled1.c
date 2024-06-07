#include <stdio.h>

void cargar(int vec[], int a){
   int i;
   for (i=0;i<a;i++){
       printf("Ingrese elemento ");
       scanf("%d",&vec[i]);
   }

}
void mostrar (int vec[], int a){
   int i;
   for (i=0;i<a;i++){
       printf("%d \n",vec[i]);
   }

}
int suma(int vec[],int a){
    if (a==0)
        return vec[0];
    return suma(vec,a-1)+vec[a];

}






int main(){
    int vec[30],dim;
    printf("Ingrese dimesion");
    scanf("%d",&dim);
    cargar(vec,dim);
    mostrar(vec,dim);
    printf(" la suma es %d\n",suma(vec,dim-1));

}
