#include <stdio.h>

void main(){
	float x, y, z = 0, w;
	double xx, yy, zz = 1;
	
	x = 3.1415;
	xx = 2.716463536535663;
	
	printf("%f\n", x);
	printf("%.4f\n", x);
	printf("%.8f\n", xx);
	
	printf("Inserisci valore di y: ");
	scanf("%f", &y);
	printf("Inserisci valore di yy: ");
	scanf("%lf", &yy);

	printf("y = %.10f e yy = %.20f\n", y, yy);
	
	printf("Inserisci i valori di z e zz separati");
	printf(" da virgola e senza spazi: ");
	if ( scanf("%f,%lf", &z, &zz) != 2){
		printf("Qualcosa e' andata storta\n");
	}

	printf("z = %f e zz = %.10f\n", z, zz);

	printf("Inserisci valore di w: ");
	while ( scanf("%f", &w) != 1){
		printf("Inserisci valore di w: ");
	}
	printf("w = %f\n", w);
}
