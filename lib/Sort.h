#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "General.h"

void print (unsigned long int *v);
void preencher (unsigned long int *v);

void START (void);
int verificaSeExiste(unsigned long int v[],unsigned long  int pos,unsigned long  int valor);
void criaVetorSemRepeticao(unsigned long int v[]);

void criaVetorNoventaPorcentoIgual (unsigned long int v[]);
void verificaQuantidadeDeRepeticoes (unsigned long int v[]);

int crescente (unsigned long int a,unsigned long  int b);
int decrescente (unsigned long int a,unsigned long  int b);

void HeapSort (unsigned long int vet[], int inicio, int fim, int (*orderby) (unsigned long int,unsigned long  int));
void QuickSort (unsigned long int vetor[], int inicio, int fim, int (*orderby) (unsigned long int,unsigned long  int));
void RadixSort(unsigned long int vetor[], int inicio, int fim, int (*orderby) (unsigned long int,unsigned long  int));
void ShellSort(unsigned long int vetor[], int inicio, int fim, int (*orderby) (unsigned long int,unsigned long  int));

#include "../src/Sort.cpp"

#include "../src/SortImpl/HeapSort.cpp"
#include "../src/SortImpl/QuickSort.cpp"
#include "../src/SortImpl/RadixSort.cpp"
#include "../src/SortImpl/ShellSort.cpp"

#endif



