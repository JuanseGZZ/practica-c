#include <string.h>

#include <stdio.h>

#include <stdlib.h>

typedef struct alumnos{

  int legajo;

  char nombre[40];

  int cantidad;

  struct alumnos *sig;

  }nodoa;

   

typedef struct alumnos1{

  int legajo;

  struct alumnos1 *sig;

  }nodoa1;   

   

   

void crearlista(nodoa *q){

  printf("Ingrese numero de legajo");

  scanf("%d",&q->legajo);

  if (q->legajo==0)

    q->sig=NULL;

  else{

    printf("Ingrese nombre y apellido");

    scanf("%s",q->nombre);

    printf("Ingrese la cantidad de materias cursadas");

    scanf("%d",&q->cantidad);

    q->sig=(nodoa*)malloc(sizeof(nodoa));

    crearlista(q->sig);

  }   

 }

void mostrarlista(nodoa *q){

  if(q->sig !=NULL){

    printf("%d \n",q->legajo);

    printf("%s\n",q->nombre);

    printf("%d\n",q->cantidad);

    mostrarlista(q->sig);

    }

} 

void mostrarlista1(nodoa1 *q){

  if(q->sig !=NULL){

    printf("%d \n",q->legajo);

    mostrarlista1(q->sig);

    }

}  

void generar(nodoa *q, nodoa *g){

  while (q->sig !=NULL){

    if(q->cantidad > 15){

      g->legajo=q->legajo;

      strcpy(g->nombre,q->nombre);

      g->cantidad=q->cantidad;

      g->sig=(nodoa*)malloc(sizeof(nodoa));

      g=g->sig;

      

    }

    q=q->sig;

  }

  g->sig=NULL;

     

} 

void generar1(nodoa *q, nodoa1 *j){

  while(q->sig!=NULL){

    if(q->cantidad == 0){

      j->legajo=q->legajo;

      j->sig=(nodoa1*)malloc(sizeof(nodoa1));

      j=j->sig;

      }

    q=q->sig;   

  }

  j->sig=NULL;

}



nodoa* insertarporcabeza(nodoa *q){

  nodoa *h=NULL;

  h=(nodoa*)malloc(sizeof(nodoa));

  h->legajo=5000;

  strcpy(h->nombre,"marcela");

  h->cantidad=23;

  h->sig=q;

  q=h;

  return q;
}



void insertarenlalista(nodoa *q){

  nodoa *k=NULL;

  while(q->sig!=NULL){

    if(q->cantidad % 2 ==0){

      k=(nodoa*)malloc(sizeof(nodoa));

      k->legajo=q->legajo;

      strcpy(k->nombre,q->nombre);

      k->cantidad= q->cantidad + 1;

      k->sig=q->sig;

      q->sig=k;

    }

    q=q->sig;

       

    }

}



nodoa* eliminarporcabeza(nodoa*q){

  nodoa*aux=NULL;

  while(q->cantidad %2 != 0){

    aux=q->sig;

    free(q);

    q=aux;

    }

  return q;   

 }



void eliminarenlalista(nodoa *q){

  nodoa* aux=NULL;

  while(q->sig !=NULL && q->sig->sig!=NULL){

    if(q->sig->cantidad % 2 !=0){

      aux=q->sig->sig;

      free(q->sig);

      q->sig=aux;

    }  

    else

      q=q->sig;

     

     

  }

}



int main() {

  nodoa *p =NULL;

  nodoa *k=NULL;

  nodoa1 *l=NULL;

  p=(nodoa*)malloc(sizeof(nodoa));

  crearlista(p);

  mostrarlista(p);

  k=(nodoa*)malloc(sizeof(nodoa));

  generar(p,k);

  printf("\nLa lista generada es\n");

  mostrarlista(k);

  l=(nodoa1*)malloc(sizeof(nodoa1));

  generar1(p,l);

  printf("\nLa lista generada es\n");

  mostrarlista1(l); 

  p=insertarporcabeza(p);

  insertarenlalista(p);

  printf("\nLa lista con insercion es\n");

  mostrarlista(p);

  p=eliminarporcabeza(p);

  printf("\nLa lista con eliminacion es\n");

  eliminarenlalista(p);

  mostrarlista(p);

  return 0;
  crearlista(p);
  mostrarlista(p);
  mostrarlista1(l);  
  generar(p,k);
  generar1(p,l);
  insertarenlalista(p); 
  eliminarenlalista(p);
  p=insertarporcabeza(p);
  p=eliminarporcabeza(p);
}