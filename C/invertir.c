#include <stdio.h>


int main(){
    int numero;
    printf("Digite un numero");
    scanf("%d",&numero);
    while((numero/10) != 0){
        printf("%d",numero%10);
        numero /= 10;
    }
    printf("%d",numero);
    return 0;
}
