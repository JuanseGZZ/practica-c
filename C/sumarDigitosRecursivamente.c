#include <stdio.h>

int sumar(int a);

int main(){
    int num = 123;
    printf("%d",sumar(num));
}

int sumar(int a){
    if(a/10==0){
        return a;
    }
    return (sumar(a/10)+a%10);
}
