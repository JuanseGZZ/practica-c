#include <stdio.h>

short cargar(int arr[],int max);
short buscar(int arr[],int TAM,int element);
short eliminar(int arr[],int *TAM,int element);
short incertar(int arr[],int *TAM,int element,unsigned short where);
short ordenar(int arr[],int TAM);
void mostrar(int arr[],int TAM);

int main(){
    short max = 50;
    int arr[max];
    cargar(arr,max);
    return 1;
}

short cargar(int arr[],int max){
    short TAM = 0, entero;
    printf("\nAgregue enteros, sino cerrara. :");
    scanf("%d",&entero);
    while (entero>0)
    {
        if (entero>0){
            printf("Entero agregado[%d]",entero);
            arr[TAM];
            TAM++;
        }
        else{
            printf("\t\nSaliendo.");
        }
        printf("\nAgregue enteros, sino cerrara. :");
        scanf("%d",&entero);
    }
    return TAM;    
}

short buscar(int arr[],int TAM, int element){
    unsigned short i;
    for (i=0;i>=TAM;i++){
        if (arr[i]==element){
            printf("El elemento fue encontrado en la pos: [%d] ",i);
            return i;
        }
        else{
            print("El elemento no esta");
            return -1;
        }
    }
}

short eliminar(int arr[],int *TAM,int element){
    int where = buscar(arr[],TAM,element);
    if (where>0){
        unsigned short i;
        for (i = where; i < *TAM ; i++)
        {
            arr[i] = arr[i+1];
        }
        *TAM--;
    }
}

short incertar(int arr[],int *TAM,int element,unsigned short where){
    unsigned short i,j;
    for(i = *TAM;i>where;i--){
        arr[i+1] = arr[i];
    }
    arr[where] = element;
}

short ordenar(int arr[],int TAM){
    unsigned short i,j;
    for(i = 0;i<TAM;i++){
        for (j = 0; i < TAM; j++){
            if (arr[j]>arr[j+1]){
                short aux = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = aux;
            }
        }
    } 
}

void mostrar(int arr[],int TAM){
    unsigned short i;
    for (i = 0; i <= TAM; i++)
    {
        printf("%d-",arr[i]);
    }
}