#include "../lib/General.h"

// Funcao para auxiliar a ordenacao crescente
int crescente (int a, int b){
	if (a > b)	return 1;
	else	return 0;
}
// Funcao para auxiliar a ordenacao decrescente
int decrescente (int a, int b){
	if (a < b)	return 1;
	else	return 0;
}


				// FAZER FUNCAO DE COMPARACAO


void print (int *v){		//Funcao exclusiva para mostrar o vetor caso necessario
	int i;
	for (i=0; i<TAM; i++){
		printf ("%6d ", v[i]);	// " %6d reserva seis espacos para os numeros
		if ( (i+1) % 10 == 0) printf ("\n"); // organiza de 10 em 10
	}
	printf ("\n");
}

void preencher (int *v){ // funcao preencher
	int i;
	for (i=0; i<TAM; i++)
		v[i] = original[i]; // sempre insere os mesmos valores carregados em original
} // fim da funcao preencher

