#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "General.h"

void print (unsigned long int *v);
void preencher (unsigned long int *v);

void START (void);
int verificaSeExiste(unsigned long int v[], int pos, int valor);
void criaVetorSemRepeticao(unsigned long int v[]);

void criaVetorNoventaPorcentoIgual (unsigned long int v[]);
void verificaQuantidadeDeRepeticoes (unsigned long int v[]);

int crescente (int a, int b);
int decrescente (int a, int b);

void HeapSort (unsigned long int vet[], int inicio, int fim, int (*orderby) (int, int));
void QuickSort (unsigned long int vetor[], int inicio, int fim, int (*orderby) (int, int));
void RadixSort(unsigned long int vetor[], int inicio, int fim, int (*orderby) (int, int));
void ShellSort(unsigned long int vetor[], int inicio, int fim, int (*orderby) (int, int));

#include "../src/Sort.cpp"

#include "../src/SortImpl/HeapSort.cpp"
#include "../src/SortImpl/QuickSort.cpp"
#include "../src/SortImpl/RadixSort.cpp"
#include "../src/SortImpl/ShellSort.cpp"

#endif



