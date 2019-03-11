#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include "General.h"

void print (int *v, int TAM);
void preencher (int *v, int TAM, int original[]);

int crescente (int a, int b);
int decrescente (int a, int b);

void HeapSort (int vet[], int inicio, int fim, int (*orderby) (int, int));
void QuickSort (int vetor[], int inicio, int fim, int (*orderby) (int, int));
void RadixSort(int vetor[], int inicio, int fim, int (*orderby) (int, int));
void ShellSort(int vetor[], int inicio, int fim, int (*orderby) (int, int));

#include "../src/Sort.cpp"

#include "../src/SortImpl/HeapSort.cpp"
#include "../src/SortImpl/QuickSort.cpp"
#include "../src/SortImpl/RadixSort.cpp"
#include "../src/SortImpl/ShellSort.cpp"

#endif



