#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

#include<stdio.h>
#include<stdlib.h>	
#include<time.h>
#include<string.h>	

//Recuperar arquivos do diretorio
#include <dirent.h>
#include <unistd.h>
#include <limits.h>


#define TAM_PADRAO 10000	// Tamanho default do vetor criado
#define MEIO_PADRAO TAM_PADRAO / 2	// Calcula o meio default do vetor
#define QTD_ORDENACOES 4 //Expansivel para analisar mais de uma ordenacao


unsigned long int TAM; //Pode ser tanto o padrao como de um arquivo
unsigned long int MEIO; //Metade de TAM

unsigned long int *original; // Vetor default para caso base da analise

typedef struct marcacaoTempo{
    long qtdElementos;
    double tempoUsado;
    int status;
    struct marcacaoTempo *prox;
} no_tempo;

typedef no_tempo* tempoListPtr;

typedef struct analiseOrdenacao{
    char nomeOrdenacao[30];
    tempoListPtr listTemposTestes;
    struct analiseOrdenacao *prox;
} no_analise;

typedef no_analise* analiseListPtr;


#endif



