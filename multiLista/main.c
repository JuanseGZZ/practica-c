// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct alumno
{
    int legajo;
    char nombre[40];
    struct alumno *sig;
    struct materia *mat;
} nodoa;

typedef struct materia
{
    int codigo;
    char nombre[40];
    struct materia *sig;
} nodom;

void crearlistamateria(nodom *h)
{
    printf("Ingrese codigo de materia");
    scanf("%d", &h->codigo);
    if (h->codigo == 0)
        h->sig = NULL;
    else
    {
        printf("Ingrese nombre de la materia");
        scanf("%s", h->nombre);
        h->sig = (nodom *)malloc(sizeof(nodom));
        crearlistamateria(h->sig);
    }
}
void cargar(nodoa *h)
{
    printf("Ingrese legajo");
    scanf("%d", &h->legajo);
    if (h->legajo == 0)
        h->sig = NULL;
    else
    {
        printf("Ingrese nombre y apellido");
        scanf("%s", h->nombre);
        h->mat = (nodom *)malloc(sizeof(nodom));
        crearlistamateria(h->mat);
        h->sig = (nodoa *)malloc(sizeof(nodoa));
        cargar(h->sig);
    }
}
void mostrarmaterias(nodom *h)
{
    if (h->sig != NULL)
    {
        printf("\n codigo %d", h->codigo);
        printf("\n nombre de la materia %s", h->nombre);
        mostrarmaterias(h->sig);
    }
}
void mostrar(nodoa *h)
{
    if (h->sig != NULL)
    {
        printf("\n legajo %d", h->legajo);
        printf("\n nombre y apellido %s", h->nombre);
        mostrarmaterias(h->mat);
        mostrar(h->sig);
    }
}
int main()
{
    nodoa *p = NULL;
    p = (nodoa *)malloc(sizeof(nodoa));
    cargar(p);
    mostrar(p);
    return 0;
}
