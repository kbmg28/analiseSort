#ifndef TESTE_H_INCLUDED
#define TESTE_H_INCLUDED


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

int informaNomeArquivo (char*caminho);
int leArquivo (char* nomeArq);
void listaArquivosExistentes (char *caminho);

void fazTeste(int view);


#include "../src/TesteTempo.cpp"
#endif
