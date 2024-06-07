#include <stdio.h>

void inter(int *n,int *n2);

int main(){
    int n,n2;
    printf("Digite n1: ");
    scanf("%d",&n);
    printf("Digite n2: ");
    scanf("%d",&n2);
    inter(&n,&n2);
    printf("n1: %d , n2: %d",n,n2);

}

void inter(int *n,int *n2){
    int aux = *n;
    *n = *n2;
    *n2 = aux;
}
