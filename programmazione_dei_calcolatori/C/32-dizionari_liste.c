#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct chiave_valore {
	char *k;
	int v;
};
typedef struct chiave_valore chiave_valore; 

struct nodo {
	chiave_valore valore;
	struct nodo *succ;
	struct nodo *prec;
};
typedef struct nodo nodo;

nodo *DizionarioVuoto();
nodo *DizionarioIn(nodo*, chiave_valore );
nodo *DizionarioCanc(nodo *, char*);
void DizionarioPrint(nodo *);
nodo *DizionarioSearch(nodo *, char* );


nodo *ListaIn0(nodo*, chiave_valore);

/*
 * Restituisce una nuova lista vuota
 * */
nodo *DizionarioVuoto(){
	return NULL;
}

/*
 * Restituisce il puntatore al nodo contenente la coppia
 * con chiave k, NULL se tale coppia non esiste.
 * */
nodo *DizionarioSearch(nodo *a, char *k){
	nodo *p = a;
	
	while( p != NULL ){
		if ( strcmp(p->valore.k, k) == 0 )
			return p;
		p = p->succ;
	}
	
	return NULL;
}

/*
 * Restituisce 1 se k appartiene al dizionario a, 0 altrimenti
 * */
int DizionarioTest( nodo *a, char *k ){
	if (DizionarioSearch(a, k) != NULL)
		return 1;
	else
		return 0;
}

/*
 * Restituisce il valore associato alla chiave k
 * 
 * Pre. k e' una chiave del dizionario.
 * 
 * */
int DizionarioGet( nodo *a, char *k){
	nodo *p = DizionarioSearch(a, k);
	
	return p->valore.v;
}


/*
 * Aggiunge al dizionario una nuova coppia kv se la chiave
 * kv.k non e' presente nel dizionario, altrimenti aggiorna
 * ne aggiorna il valore con quello di kv.v.
 * 
 * */
nodo *DizionarioIn(nodo *a, chiave_valore kv){
	nodo *p = DizionarioSearch(a, kv.k);
	
	if (p != NULL )
		p->valore.v = kv.v;
	else{
		a = ListaIn0(a, kv);
	}
	
	return a;
}


/*
 * Aggiunge un nuovo nodo, con info v, in testa alla lista
 * */
nodo *ListaIn0(nodo *a, chiave_valore v){
	int lk;
	nodo *n = malloc(sizeof(nodo));
	lk = strlen(v.k);
	
	n->valore.k = malloc((lk+1)*sizeof(char));
	strcpy(n->valore.k, v.k);
	n->valore.v = v.v;
	
	n->succ = a;
	n->prec = NULL;
	if ( a != NULL )
		a->prec = n;
	a = n;
	return a;
}


/*
 * Elimina dal dizionario il nodo contenente la coppia con chiave k.
 * Restituisce il dizionario modificato. Se tale nodo non esiste
 * la funzione restituisce il dizionario non modificato.
 * 
 * */
 nodo *DizionarioCanc(nodo *a, char *k ){
	/*
	 * TODO
	 * */
 }
 

/*
 * Stampa tutti gli elementi della lista.
 * */
void DizionarioPrint(nodo *a){
	nodo *p = a;
	while( p != NULL ){
		printf("%s: %d, ", p->valore.k, p->valore.v);
		p = p->succ;
	}
	printf("\n");
}



/*
 * Crea un dizionario contenente coppie (k, v) dove k e' una 
 * parola nel file resa minuscola e v e' il numero di occorrenze di
 * v nel file.
 * 
 * Per parola si intende una sequenze di lettere.
 * 
 * Restituisce il dizionario creato dopo averlo ordinato
 * in modo decrescente rispoetto alle occorrenze.
 * 
 * */
nodo *ContaOccorrenza(char *filename){
	/*
	 * TODO
	 * */
}

void main(int n, char *args[]){
	chiave_valore kv;
	int i;
	nodo *d = DizionarioVuoto();
	
	/*
	 * Crea un dizionario con valori (k, v) dove
	 * k e' una stringa in args e v e' l'ultima
	 * posizione in args in cui compare k.
	 * 
	 * */
	
	for(i = 1; i < n; i++) {
		kv.k = args[i];
		if ( DizionarioTest(d, kv.k ) == 0 ){
			kv.v = 1;
		} else {
			/*
			 * La chiave e' nel dizionario
			 * */
			 kv.v = DizionarioGet(d, kv.k) + 1;
		}
		
		d = DizionarioIn(d, kv);
	}
	
	DizionarioPrint(d);
	
}
