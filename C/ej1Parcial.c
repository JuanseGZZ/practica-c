 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>


 typedef struct list{
    short a�o;
    char nombre[30];
    short peso;
    short altura;
    struct list *sig;
 }list;

 typedef struct list2{
    short a�o;
    short grasa;
 }list2;

 void cargaCabeza(list *q){
    printf("Agrega el a�o de nacimiento: ");
    scanf("%d",&q->a�o);
    if (q->a�o == 0){
        q->sig = NULL;
    }else{
    printf("Nombre: ");
    scanf("%s",q->nombre);
    printf("Carga el peso: ");
    scanf("%hd",&q->peso);
    printf("Carga atura: ");
    scanf("%hd",&q->altura);
    q->sig = (list*)malloc(sizeof(list));
    cargaCabeza(q->sig);
    }
 }

 void generar(list *q,list2 *g){
    if(q->sig!=NULL){
        g->a�o = q-> a�o;
        g->sig = (list2*)malloc(sizeof(list2));
        g=g->sig;
        q=q->sig;
        generar(q,g);
    }else{
        g->a�o = q->a�o;
        g->sig = NULL;
    }
 }

 void sobrePeso(list2 *q, list2 *g){
    if(q->sig != NULL){
        if(q->grasa >24.9){
            g->grasa = q->grasa;
            g->sig = (list2*)malloc(sizeof(list2));
            g=g->sig;
        }
        q=q->sig;
        sobrePeso(q,g),
    }else{
        g->sig=NULL;
    }
 }

 void agregar(list2 *q){
    if(q->sig!=NULL){
        list2 *a = (list2*)malloc(sizeof(list2));
        if(q->grasa >24.9){
            a->a�o = 1;
            a->grasa = 1;
        }else{
            a->a�o = 0;
            a->grasa = 0;
        }
        a->sig = q->sig;
        q->sig = a;
        agregar(q->sig->sig);
    }
 }

 void quitar(list2 *q){
    if(q->sig!=NULL){
        list2 *aux = (list2*)malloc(sizeof(list2));
        if(q->sig->a�o==1960||q->sig->a�o==1970){
            aux = q->sig->sig;
            free(q->sig);
            q->sig=aux;
        }
        quitar(q->sig);
    }
 }


 int main(){
    list *p = NULL;
    p = (list*)malloc(sizeof(list));

    list2 *r =NULL;
    r =(list2*)malloc(sizeof(list2));

    cargaCabeza(p);
    generar(p,r);
    sobrePeso(p,r);
    agregar(p,r);

 }
