#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct multilista{
    int dato;
    struct multilista *sig;
    struct sublista *next;
}multilista;

typedef struct sublista{
    char nombre[10];
    char apellido[10];
    struct sublista *sig;
}sublista;

void generar(multilista *q);
void generarSub(sublista *q);

void mostrar(multilista *q);
void mostrarSub(sublista *q);

void save(multilista *q);
void load(multilista *q);

int main()
{
    multilista *p = NULL;
    p = (multilista*)malloc(sizeof(multilista));
    //generar(p);

    //mostrar(p);
    //save(p);

    load(p);
    mostrar(p);
    return 0;
}

void generarSub(sublista *q){
    printf("Ingrese su nombre !=0: ");
    scanf("%s",q->nombre);
    if(strcmp(q->nombre,"0")==0){
        q->sig = NULL;
        strcpy(q->apellido,"0");
        return;
    }else{
        printf("Ingrese su apellido: ");
        scanf("%s",q->apellido);
        q->sig = (sublista*)malloc(sizeof(sublista));
        generarSub(q->sig);
    }
}

void generar(multilista *q){
    printf("Dato!=0: ");
    scanf("%d",&q->dato);
    if(q->dato==0){
        q->sig = NULL;
        return;
    }else{
        q->next = (sublista*)malloc(sizeof(sublista));
        generarSub(q->next);
        q->sig = (multilista*)malloc(sizeof(multilista));
        generar(q->sig);
    }
}

void mostrarSub(sublista *q){
    if (q->sig != NULL){
        printf("\nNombre: %s",q->nombre);
        printf("\nApellido: %s",q->apellido);
        mostrarSub(q->sig);
    }
}

void mostrar(multilista *q){
    if(q->sig != NULL){
        printf("\n---------------------\n    Legajo: [%d] \n",q->dato);
        mostrarSub(q->next);
        q = q->sig;
        mostrar(q);
    }
}

void save(multilista *q){
    FILE *h;
    if((h = fopen("multilista.txt","w"))!=NULL){
        while(q->sig != NULL){
            while(q->next->sig != NULL){
                fprintf(h,"%d %s %s\n",q->dato,q->next->nombre,q->next->apellido);
                q->next = q->next->sig;
            }
            q = q->sig;
        }
    }else{
        printf("No se pudo abrir el file! ");
    }
}

void load(multilista *q){
    FILE *h;
    int fdato;
    char fnombre[10],fapellido[10];
    if((h = fopen("multilista.txt","r"))!=NULL){
        if(feof(h)){
            printf("El archivo no tiene nada");
        }
        else{
            printf("El archivo abrio \n\n  lectura del archivo:\n");

            fscanf(h,"%d %s %s\n",&fdato,fnombre,fapellido);
            printf("%d %s %s\n",fdato,fnombre,fapellido);

            q->dato = fdato;
            q->next = (sublista*)malloc(sizeof(sublista));
            strcpy(q->next->nombre,fnombre);
            strcpy(q->next->apellido,fapellido);

            q->next->sig = (sublista*)malloc(sizeof(sublista));
            q->sig = (multilista*)malloc(sizeof(multilista));

            while(!feof(h)){
                fdato = 0;
                strcpy(fnombre,"0");
                strcpy(fapellido,"0");
                fscanf(h,"%d %s %s\n",&fdato,fnombre,fapellido);
                printf("%d %s %s\n",fdato,fnombre,fapellido);
                if(fdato == 0){             // el file no tiene mas nada
                    q->sig->sig = NULL;
                    q->sig->dato = 0;
                    q->next->sig->sig = NULL;
                    strcpy(q->next->sig->nombre,"0");
                    strcpy(q->next->sig->apellido,"0");
                }
                if (fdato != q->dato && fdato != 0){      // el nodo es distinto
                    q->next->sig->sig = NULL;
                    strcpy(q->next->sig->nombre,"0");
                    strcpy(q->next->sig->apellido,"0");
                    q = q->sig;
                    q->dato = fdato;
                    q->next = (sublista*)malloc(sizeof(sublista));
                    strcpy(q->next->nombre,fnombre);
                    strcpy(q->next->apellido,fapellido);
                    q->sig = (multilista*)malloc(sizeof(multilista));
                    q->next->sig = (sublista*)malloc(sizeof(sublista));
                }
                if(fdato == q->dato && fdato != 0) {      // es el mismo nodo
                    q->next = q->next->sig;
                    strcpy(q->next->nombre,fnombre);
                    strcpy(q->next->apellido,fapellido);
                    q->next->sig = (sublista*)malloc(sizeof(sublista));
                }
            }
        }
    }
    else{
        printf("No se pudo abrir el archivo");
    }
}
