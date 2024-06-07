#include <stdlib.h>

int prestamo(int cantidad,int c,int s);

int main(){
    int cantidad = 100000;
    printf("%d",prestamo(cantidad,cantidad*.1,0));
    return 1;
}

int prestamo(int cantidad,int c,int s){
    if (cantidad <= 0){
        return s;
    } else {
        int nuevaS = s + cantidad;
        return prestamo(cantidad - c, c, nuevaS);
    }
}
