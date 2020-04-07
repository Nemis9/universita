#include <stdlib.h>
#include <stdio.h>

struct nodo {
	int valore;
	struct nodo *succ;
	struct nodo *prec;
};
typedef struct nodo nodo;

nodo *ListaVuota();
nodo *ListaIn0(nodo*, int );
nodo *ListaIn1(nodo*, int );
nodo *ListaIn(nodo *, int , int );
void ListaPrint(nodo *);
nodo *ListaSearch(nodo *, int );
nodo *ListaAppend(nodo*, int );


/*
 * Restituisce una nuova lista vuota
 * */
nodo *ListaVuota(){
	return NULL;
}

/*
 * Aggiunge un nuovo nodo, con info v, in testa alla lista
 * */
nodo *ListaIn0(nodo *a, int v){
	nodo *n = malloc(sizeof(nodo));
	n->valore = v;
	n->succ = a;
	n->prec = NULL;
	if ( a != NULL )
		(*a).prec = n;
	a = n;
	return a;
}

/*
 * Aggiunge un nuovo nodo, con info v, in pos 1 della lista
 * */
nodo *ListaIn1(nodo *p, int v){
	nodo *n;
	if ( p == NULL )
		return p;
	n = malloc(sizeof(nodo));
	n->valore = v;
	n->prec = p;
	n->succ = p->succ;
	if( p->succ != NULL)
		p->succ->prec = n;
	p->succ = n;
	return p;
}

/*
 * Inserisce nuovo nodo con info v  in posizione pos di a
 * 
 * */
nodo *ListaIn(nodo *a, int v, int pos){
	nodo *p;
	if( pos < 0 )
		return a;
	if( pos == 0 )
		a = ListaIn0(a, v);
	else {
		p = ListaSearch(a, pos-1);
		if (p != NULL ){
			p = ListaIn1(p, v);
		}
	}
	return a;
}

/*
 * Restituisce l'indirizzo del nodo in posizione pos di a
 * oppure NULL se la lista non contiene tale nodo.
 * */
nodo *ListaSearch(nodo *a, int pos){
	nodo *p = a;
	int i = 0;
	while( i < pos && p != NULL ){
		i++;
		p = p->succ;
	}
	return p;
}

/*
 * Inserisce un nuovo nodo in fondo alla lista a
 * */
nodo *ListaAppend(nodo *a, int v){
	nodo *p = a;
	if( a == NULL)
		a = ListaIn0(a,v);
	else {
		while( p->succ != NULL)
			p = p->succ;
		p = ListaIn1(p, v);
	}
	return a;
}

/*
 * Stampa tutti gli elementi della lista.
 * */
void ListaPrint(nodo *a){
	nodo *p = a;
	while( p != NULL ){
		printf("%d, ", p->valore);
		p = p->succ;
	}
	printf("\n");
}

void main(){
	int i;
	nodo *a = ListaVuota(), *p;
	for(i = 10; i < 100; i += 10){
		a = ListaIn0(a, i);
	}
	
	ListaPrint(a);
	
	a = ListaAppend(a, 999);

	ListaPrint(a);
}
