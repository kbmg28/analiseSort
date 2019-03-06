#include<stdio.h>
#include<stdlib.h>

//FALTA TESTAR COM O MODELO PADRAO DAS OUTRAS ORDENACOES !!!!!!!!


void RadixSort(int vetor[], int inicio,  int fim, int (*orderby) (int, int)){
	int i, t=0;		
	int *b;
	int maior = vetor[0];	
	int exp = 1;		
	
	b = (int *) calloc(fim, sizeof(int)); 
	
	for (i = 0; i < fim; i++) { 
		if (orderby(vetor[i], maior))
			maior = vetor[i];
	}
	
	while (maior/exp > 0) {
		t++;
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
