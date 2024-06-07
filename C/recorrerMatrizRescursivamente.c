#include <stdio.h>

// Función recursiva para imprimir los elementos de la matriz
void imprimirMatrizRecursivamente(int matriz[][3], int filas, int columnas, int filaActual, int columnaActual) {
    // Condición base: si la fila actual es igual al número de filas, hemos terminado
    if (filaActual == filas) {
        return;
    }

    // Condición base: si la columna actual es igual al número de columnas, pasamos a la siguiente fila
    if (columnaActual == columnas) {
        printf("\n"); // Imprime una nueva línea al final de cada fila
        imprimirMatrizRecursivamente(matriz, filas, columnas, filaActual + 1, 0); // Pasamos a la siguiente fila
        return;
    }

    // Imprime el elemento actual y llama recursivamente para el siguiente elemento en la misma fila
    printf("%d ", matriz[filaActual][columnaActual]);
    imprimirMatrizRecursivamente(matriz, filas, columnas, filaActual, columnaActual + 1);
}

int main() {
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    imprimirMatrizRecursivamente(matriz, 2, 3, 0, 0);

    return 0;
}
