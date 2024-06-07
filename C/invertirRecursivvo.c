#include <stdio.h>

int invertir(int num);

int main(){
    int numero;
    printf("Digite un numero: ");
    scanf("%d",&numero);
    invertir(numero);
    return 1;
}

int invertir(int num){
    if ((num/10) == 0){
        printf("%d",num);
        return 1;
    }
    printf("%d",(num%10));
    invertir(num/10);
    return 1;
}
