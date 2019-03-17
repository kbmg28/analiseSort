#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED

#include "General.h"

void tempo_gasto (double tempo[][4]);

void Sort_crescente (unsigned long int *v, int N,   double *tempo, int pos, void (*type_sort) (unsigned long int *, int, int, int (*ordem) (unsigned long int, unsigned long int)));
void Sort_decrescente_crescente (unsigned long int *v, int N,  double *tempo, void (*type_sort) (unsigned long int *, int, int, int (*ordem) (unsigned long int,unsigned long  int)));
void Sort_crescente_meio_decrescente (unsigned long int *v, int N,  double *tempo, void (*type_sort) (unsigned long int *, int, int, int (*ordem) (unsigned long int, unsigned long int)));
void Sort_decrescente_meio_crescente (unsigned long int *v, int N,  double *tempo, void (*type_sort) (unsigned long int *, int, int, int (*ordem) (unsigned long int,unsigned long  int)));


void carregaTamanhoArrayPadrao();
void testePadrao ();

void testeArquivo(int view);
void testeComArquivoSemView();
void testeComArquivoView();
void testeComTodasAsOrdenacoes();

int informaNomeArquivo (char*caminho);
int leArquivo (char* nomeArq);
void listaArquivosExistentes (char *caminho);

void fazTeste(int view);


tempoListPtr cria_no_listaTempo (long qtdElementos, double tempoUsado, int status);
void printTempo (tempoListPtr lista, FILE *arq);
void addTempo (tempoListPtr *lista, tempoListPtr novo);
void libera_listaTempo (tempoListPtr *lista);
analiseListPtr cria_no_Analise (const char* nomeOrdenacao);
void addAnalise (analiseListPtr *lista, analiseListPtr novo);
void addTempoOnAnalise (analiseListPtr *lista, const char* ordenacao, tempoListPtr novo);
void print_lista (analiseListPtr lista, const char* tipoDoTeste);
void libera_lista (analiseListPtr *lista);
void fazTesteComLista(analiseListPtr* listAnalise);
void testaTodosOsArquivos (const char*caminho, const char* tipoDoTeste);


#include "../src/TesteTempo.cpp"
#endif
