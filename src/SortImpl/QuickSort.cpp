#include<stdio.h>
#include<stdlib.h>

int particiona (int*, int, int, int (*orderby) (int, int));

	/* Ordenacao por troca de particoes */
void QuickSort (int vetor[], int inicio, int fim, int (*orderby) (int, int)){
	int pivo;	// Base para calculo de troca
	
	if (fim > inicio){
		pivo = particiona(vetor, inicio, fim, orderby);	//Separa os dados em duas particoes
		QuickSort (vetor, inicio, pivo-1, orderby);	//Passo recursivo para a esquerda
		QuickSort (vetor, pivo+1, fim, orderby);	//Passo recursivo para a direita
	}

}

int particiona (int *vetor, int inicio, int fim, int (*orderby) (int, int)){
	int esq, dir, pivo, aux;
	
	esq = inicio;	// Inicializacao para a esquerda
	dir = fim;	//Definicao para a direita
	pivo = vetor[inicio]; // Base para troca
	
	while (esq < dir){
		while (!orderby(vetor[esq], pivo))	esq ++;
		while (orderby(vetor[dir], pivo))	dir--;
		
		/* Troca esq e dir */
		if (esq < dir){
			aux = vetor[esq];
			vetor[esq] = vetor[dir];
			vetor[dir] = aux;
		}
	}
	vetor[inicio] = vetor[dir];
	vetor[dir] = pivo;
	return dir;
}
