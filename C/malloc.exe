#include <stdio.h>

int main() {
    int c,cont=0,aux;
    printf("Ingrese la frase terminada en punto\n");
    c=getchar();
    while (c!='.'){
        while(c!=' ' && c!='.'){
            putchar(c);
             c=getchar();
        }
        while (c==' '){
            //putchar(c);
           c=getchar();
        } 
        putchar(' ');
        putchar(' ');
        putchar(' ');
        
        cont++;
       if (c!='.'){
           putchar(c);
          c=getchar();
       }  
    }
    printf("\n la cantidad de palabras es %d",cont);

    return 0;
}