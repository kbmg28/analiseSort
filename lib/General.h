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


int TAM; //Pode ser tanto o padrao como de um arquivo
int MEIO; //Metade de TAM

int *original; // Vetor default para caso base da analise

//#include "../src/sort.cpp"

#endif



