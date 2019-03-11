#include<stdio.h>
#include<stdlib.h>

//FALTA TESTAR COM O MODELO PADRAO DAS OUTRAS ORDENACOES !!!!!!!!


void RadixSort(unsigned long int vetor[], int inicio,  int fim, int (*orderby) (int, int)){
	int i;
	unsigned long int *b;
	unsigned long int maior = vetor[0];	
	unsigned long int exp = 1;		
	
	b = (unsigned long int *) calloc(fim, sizeof(unsigned long int)); 
	
	for (i = 0; i < fim; i++) { 
		if (orderby(vetor[i], maior))
			maior = vetor[i];
	}
	
	while (maior/exp > 0) {
		int bucket[10] = { 0 }; 
		
		for (i = 0; i < fim; i++)
			bucket[(vetor[i] / exp) % 10]++;   
		
		for(i = 1; i < 10; i++) 
			bucket[i] += bucket[i - 1];
		
		for (i = fim - 1; i >= 0; i--)
			b[--bucket[(vetor[i] / exp) % 10]] = vetor[i]; 
		
		for (i = 0; i < fim; i++)
			vetor[i] = b[i];
		exp *= 10;	   
	}
	
	free(b); 
}
