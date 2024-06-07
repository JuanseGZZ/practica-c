#include <stdio.h>

int cargar(int arr[]);
int cantMultiplos(int arr[], int tam);
int promedioMultiplos(int arr[], int tam);
int incertar(int arr[], int tam);
int eliminar(int arr[], int tam);
int ordenar(int arr[], int tam);

int main()
{
    int arr[50];
    int tam = cargar(arr);
}

int cargar(int arr[])
{
    short i = 0, num;
    printf("Ingrese numeros enteros| 0 para salir: ");
    scanf("%d", &num);
    while (num != 0)
    {
        if (num > 0)
        {
            arr[i] = num;
            printf("Ingrese numeros excepto -1");
            scanf("%d", &num);
            i++;
        }
        else // ojo aca
        printf("El numero no fue entero y no fue incertado. ");
    }
    return i;
}

int cantMultiplos(int arr[], int tam)
{
    int multiplos = 0;
    for (short i = 0; i <= tam; i++)
    {
        if (arr[i] % 5 == 0)
        {
            multiplos++;
        }
    }
    return multiplos;
}

int promedioMultiplos(int arr[], int tam)
{
    int multiplos = 0;
    int cantidad = 0;
    for (short i = 0; i <= tam; i++)
    {
        if (arr[i] % 3 == 0)
        {
            multiplos += 3;
            cantidad++;
        }
        if (arr[i] % 7 == 0)
        {
            multiplos += 3;
            cantidad++;
        }
    }
    return (multiplos / cantidad);
}

int incertar(int arr[], int tam)
{
    for (short i = 0; i <= tam; i++)
    {
        if (arr[i] % 5 == 0)
        {
            for (short j = tam; j >= i; j--)
            {
                arr[j + 1] = arr[j];
            }
            arr[i] = -1;
        }
    }
    tam++;
    return tam;
}

int eliminar(int arr[], int tam)
{
    for (short i = 0; i <= tam; i++)
    {
        if (arr[i] % 3 == 0)
        {
            for (short j = i+1; j >= tam; j++)
            {
                arr[j-1] = arr[j];
            }
        }
    }
    tam--;
    return tam;
}