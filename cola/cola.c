#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define CANT 10




typedef struct tiponodo
{
	int dato;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux,int *cont, int *max, int *i, int *pos,int *prim, int *productoria,int *sumatoria)
{
    (*i)++;
  	printf("%d \n", aux.dato);
    if (aux.dato % 2 !=0){
        (*cont) ++;
    }
    if(aux.dato > max){
        (*max) = aux.dato;
        (*pos) = i;
    }
    if (prim < 0){
        (*productoria) *= aux.dato;
    }else{
        (*sumatoria) += aux.dato;
    }
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->dato = dato;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  	printf("%02d p=%X u=%X\n", q->dato, *p, *u);
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

int main()
{

   int i,num, cont,max, pos, prim, productoria,sumatoria;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
       prim = max = num;
        acolar(&p, &u, crear_nodo(num));

   }


   printf("\nVamos a desacolar todo\n");
   i = 0;
	while(p!=NULL)
   {
    	mostrar(desacolar(&p), &cont, &max, &i ,&pos,&prim,&productoria,&sumatoria);
   }
    printf("elementos imares en la cola: %d",cont);
    printf("El mayor elemento es: %d en la posición: %d\n", max, pos);
    // aca con un if va
    printf("Productoria de elementos si el primer elemento es negativo: %d\n", productoria);
    printf("Sumatoria de elementos si el primer elemento no es negativo: %d\n", sumatoria);
   return 0;
}
