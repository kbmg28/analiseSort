#include<stdio.h>
#include<stdlib.h>

//https://gist.github.com/nirocfz/3794605

void ShellSort(unsigned long int vetor[], int inicio, int fim, int (*orderby) (int, int)){
    int gap, i, j, temp;
	
	for (gap = fim / 2; gap > inicio; gap /= 2){
		for (i = gap; i < fim; i++){
			for (j = i - gap; j >= inicio && orderby(vetor[j], vetor[j + gap]); j -= gap) {
				temp = vetor[j];
				vetor[j] = vetor[j + gap];
				vetor[j + gap] = temp;
			}   
		}   
	}   
}

