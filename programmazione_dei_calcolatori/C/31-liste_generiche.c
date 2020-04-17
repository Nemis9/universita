#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

union union_valore {
	float union_float;
	char *union_str;
};
typedef union union_valore union_valore;

struct nodo {
	union_valore valore;
	struct nodo *succ;
	struct nodo *prec;
	char campo_union; /* 'f' per union_float, 's' per union_str */
};
typedef struct nodo nodo;

nodo *ListaVuota();
nodo *ListaIn0(nodo*, union_valore, char );
void ListaPrint(nodo *);


/*
 * Restituisce una nuova lista vuota
 * */
nodo *ListaVuota(){
	return NULL;
}

/*
 * Aggiunge un nuovo nodo, con info v, in testa alla lista
 * 
 * tipo = 'f' o 's' ci dice quale campo di v considerare
 * */
nodo *ListaIn0(nodo *a, union_valore v, char tipo){
	int lv;
	nodo *n = malloc(sizeof(nodo));
	
	n->campo_union = tipo;
	if ( tipo == 'f' ){
		 n->valore.union_float = v.union_float;
	} else {
		lv = strlen(v.union_str);
		n->valore.union_str = malloc((lv+1)*sizeof(char));
		strcpy(n->valore.union_str, v.union_str);
	}
	n->succ = a;
	n->prec = NULL;
	if ( a != NULL )
		(*a).prec = n;
	a = n;
	return a;
}


/*
 * Stampa tutti gli elementi della lista.
 * */
void ListaPrint(nodo *a){
	nodo *p = a;
	while( p != NULL ){
		if( p->campo_union == 's')
			printf("%s, ", p->valore.union_str);
		else
			printf("%f, ", p->valore.union_float);
		p = p->succ;
	}
	printf("\n");
}



void main(int n, char *args[]){
	nodo *a = ListaVuota();
	int i;
	float f;
	union_valore v;
	
	for( i = n-1; i >= 1; i-- ){
		if ( sscanf(args[i], "%f", &f) == 1 ){
			v.union_float = f;
			a = ListaIn0(a, v, 'f');
		} else {
			v.union_str = args[i];
			a = ListaIn0(a, v, 's');
		}
	} 
	ListaPrint(a);
}
