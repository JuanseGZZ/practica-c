#include <stdio.h>

int invertir(int c);

int main(){
    int c;
    printf("Digite: ");
    c = getchar();
    invertir(c);
    putchar(c);
}

int invertir(int c){
    if (c=='.')
        return 1;
    c = getchar();
    invertir(c);
    putchar(c);
    return 1;
}
