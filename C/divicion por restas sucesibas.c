#include <stdio.h>

int dividir(int a,int b);

int main(){
    int a,b;
    printf("%d",dividir(20,5));
    return 1;
}

int dividir(int a,int b){
    if((a-b)<0){
        return 0;
    }
    return dividir(a-b,b)+1;
}
