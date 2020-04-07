#include <stdio.h>

void main(){
	FILE *fpin, *fpout;
	int n, somma = 0;
	fpin = fopen("25-interi.csv", "r");
	fpout = fopen("25-interi-out.csv", "w");
	if ( fpin == NULL || fpout == NULL ){
			printf("Errore di apertura\n");
			return;
	}
	
	while( feof(fpin) == 0 ){  /* non siamo alla fine del file */
		if (fscanf(fpin, "%d;", &n) == 1 ) {
			somma += n;
			fprintf(fpout, "%d;%d;\n", n, somma); 
		}
	}
	printf("somma = %d\n", somma); 
	
	fclose(fpin);
	fclose(fpout);
}
