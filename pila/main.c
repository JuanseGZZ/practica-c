#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 4



typedef struct tiponodo
{
	int dato;
    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *cont,int primero, int *cont1)

{ 
     	printf("%d \n", aux.dato);
     	if(aux.dato %2 ==0)
     	    *cont=*cont+1;
     	if (aux.dato > primero  && aux.dato!=primero)
     	   *cont1=*cont1+1; 
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");


  	u->siguiente = *p;
  	printf("%d p=%p u=%p\n", u->dato, *p, u);
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{


   int i,num,cont=0,primero,cont1=0;
   nodo* p=NULL;


   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
   	if (i==0)
   	    primero=num;
   	apilar(&p, crear_nodo(num));
   }


   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p),&cont,primero,&cont1);
   }
   printf("\n la cantidad de numeros pares es %d",cont);
   printf("\n la cantidad de numeros mayores al primero es %d",cont1);
   return 0;
}