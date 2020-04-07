#include <stdio.h>

struct punto {
		char nome;
		float x;
		float y;
};
typedef struct punto punto;

float PI = 3.1415;

punto nw(punto[],  int);

void main(){
	int i;
	struct punto a;
	punto b = {'B', 0, 6};
	
	punto P[3];
	
	a.nome = 'A';
	a.x = 1.0;
	a.y = 2;
	
	/*
	printf("%c: (%.1f, %.1f)\n", a.nome, a.x, a.y);
	printf("%c: (%.1f, %.1f)\n", b.nome, b.x, b.y);
	*/
	
	P[0] = a;
	P[1] = b;
	P[2].nome = 'C';
	P[2].x = PI;
	P[2].y = -0.1;
	
	for(i = 0; i < 3; i++){
		printf("%c: (%.1f, %.1f)\n", P[i].nome, P[i].x, P[i].y);
	}
	
	int n = sizeof(P)/sizeof(punto);
	punto c = nw(P, n);
	printf("%c: (%.1f, %.1f)\n", c.nome, c.x, c.y);
}


punto nw(punto a[], int n){
	punto r = a[0];
	int i;
	
	for(i = 1; i < n; i += 1){
		if( a[i].x <= r.x && a[i].y >= r.y)
			r = a[i];
	}
	
	return r;
	
}
