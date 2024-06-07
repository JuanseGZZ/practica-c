#include <stdio.h>
#include <conio.h>

int main(){
    int c, letras = 0, palabras=0;
    printf("Ingrese frase terminada en punto: ");
    c = getchar();
    while (c!='.'){
        while(c!=' ' && c!='.'){
            letras++;
            putchar(c);
            c=getchar();
        }
        if (letras >= 3){
            palabras++;
        }
        letras = 0;
        while(c==' '){
            putchar(c);
            c=getchar();
        }
        if (c!='.'){
            putchar(c);
            c=getchar();
        }
    }
    printf("\nLa cantidad de palabra con mas de 3 letras son: %d",palabras);
    c=getch();
    return 0;
}
