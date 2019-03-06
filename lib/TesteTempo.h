#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED


void tempo_gasto (double tempo[][4]);

void Sort_crescente (int *v, int N,   double *tempo, int pos, void (*type_sort) (int *, int, int, int (*ordem) (int, int)));
void Sort_decrescente_crescente (int *v, int N,  double *tempo, void (*type_sort) (int *, int, int, int (*ordem) (int, int)));
void Sort_crescente_meio_decrescente (int *v, int N,  double *tempo, void (*type_sort) (int *, int, int, int (*ordem) (int, int)));
void Sort_decrescente_meio_crescente (int *v, int N,  double *tempo, void (*type_sort) (int *, int, int, int (*ordem) (int, int)));


void carregaTamanhoArrayPadrao();
void testePadrao ();

void testeComArquivo();
void testeComArquivoView();
int informaNomeArquivo ();
int leArquivo (char* nomeArq);
void listaArquivosExistentes ();

void fazTeste(int view);


#include "../src/TesteTempo.cpp"
#endif
