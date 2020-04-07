#include <stdlib.h>
#include <stdio.h>

struct DinArray {
	int *a;
	int n, c;
};
typedef struct DinArray DinArray;

DinArray NewDinArray();
DinArray AppendDinArray_malloc( DinArray, int );
DinArray AppendDinArray( DinArray, int );
DinArray PopDinArray( DinArray );
DinArray InsertDinArray( DinArray, int, int);
DinArray DeleteDinArray( DinArray, int);
void PrintDinArray( DinArray );
void Scambia(int*, int, int);

DinArray NewDinArray(){
	DinArray d = {NULL, 0, 0};
	return d;
}

DinArray AppendDinArray_malloc( DinArray v, int e){
	int *t, i;
	if ( v.n < v.c ){
		v.a[v.n] = e;
		v.n++;
	} else {
		t = malloc(sizeof(int)*(2*v.c+1));
		for(i = 0; i < v.n; i++)
			t[i] = v.a[i];
		t[v.n] = e;
		v.n++;
		v.c = 1+2*v.c;
		free(v.a);
		v.a = t; 
	}
	return v;
}

DinArray AppendDinArray( DinArray v, int e){
	if ( v.n == v.c ){
		v.a = realloc( v.a,  (2*v.c+1)*sizeof(int));
		v.c = 2*v.c+1;
	}
	v.a[v.n] = e;
	v.n ++; 
	return v;
}

DinArray PopDinArray( DinArray v ){
	if( v.n == 0 )
		return v;
	if ( v.n < (v.c)/4 ){
		v.a = realloc( v.a,  sizeof(int)*(v.c)/2);
		v.c = (v.c)/2;
	}
	v.n --; 
	return v; 
}

/*
 * Inserisce e in posizione p di v traslando di una posizione
 * verso dx gli elementi dalla posizione p in poi
 *
 * Precondizione: p <= v.n
 * */
DinArray InsertDinArray( DinArray v, int e, int p){
	int i;
	v = AppendDinArray(v, e);
	i = v.n-1;
	while( i != p) {
		Scambia(v.a, i, i-1);
		i--;
	}
	return v;
}


/*
 * Elimina l'elemento posizione p di v traslando di una posizione
 * verso dsx gli elementi dalla posizione p+1 in poi
 *
 * Precondizione: p <= v.n
 * */
DinArray DeleteDinArray( DinArray v, int p){
	int i = p;
	while( i != v.n-1) {
		Scambia(v.a, i, i+1);
		i++;
	}
	v = PopDinArray(v);
	return v;
}

void PrintDinArray( DinArray v){
	int i;

	printf(" ---> ");
	for( i = 0; i < v.n; i++){
		printf("%d, ", v.a[i]); 
	}
	printf("\n");
}

void Scambia(int *a, int i, int j){
	int t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void main(){
	int i;
	DinArray v = NewDinArray();

	for (i = 0; i < 4; i++){
		v = AppendDinArray( v, i );
		printf("%d, %d\n", v.c, v.n);
		PrintDinArray(v);
	}

	v = InsertDinArray(v, 100, 0);
	PrintDinArray(v);
	v = DeleteDinArray(v, 0);
	PrintDinArray(v);


	while ( v.n > 0 ){
		v = PopDinArray( v );
		printf("%d, %d\n", v.c, v.n);
		PrintDinArray(v);
	}

}



