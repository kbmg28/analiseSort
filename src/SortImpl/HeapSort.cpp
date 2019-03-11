#include<stdio.h>
#include<stdlib.h>

void criaHeap (unsigned long int*, int, int, int (*orderby) (int, int));

//Ordenacao que simula uma arvore binaria completa
void HeapSort (unsigned long int vet[], int inicio, int fim, int (*orderby) (int, int)){ //inicio da funcao HeapSort
	int i, aux;
	
	//Define quem eh filho de quem
	for (i = (fim-1)/2; i>=0; i--){
		criaHeap (vet, i, fim-1, orderby);
	}
	
	/* Ordena baseado na funcao orderby da seguinte forma:
		(1) Se for crescente, a raiz atual (MAIOR elemento) vai para o fim passado como parametro
		(1) Se for decrescente, a raiz atual (MENOR elemento) vai para o fim passado como parametro */
	for (i=fim-1; i >= 1; i--){
		aux = vet[0];
		vet[0] = vet[i];
		vet[i] = aux;
		criaHeap(vet, 0, i-1, orderby);
	}
}//fim da funcao HeapSort


/* Funcao: criaHeap
	Objetivo:
		Define para cada posicao do vetor quem sera seu filho
		
		Lembrando: 
					(1) Cada pai possui dois filhos
					(2) O valor do pai deve ser maior que seus filhos */			
void criaHeap (unsigned long int vetor[], int inicio, int fim, int (*orderby) (int, int)){ //inicio da funcao criaHeap
	int aux = vetor[inicio];
	int j = inicio*2 + 1; //calcula o filho
	
	while(j <= fim){
		if(j < fim)
			if( !orderby(vetor[j], vetor[j+1]) )//compara dois elementos
				j = j + 1; // vai para o proximo filho
				
		if( !orderby(aux, vetor[j]) ){ //compara dois elementos
			vetor[inicio] = vetor[j];
			inicio = j;
			j = inicio*2 + 1; //calcula o proximo filho
		} else{
			j = fim + 1;
		}
	}
	vetor[inicio] = aux;
}//fim da funcao criaHeap
