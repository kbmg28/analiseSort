	#########################
	#	HEAPSORT	#
	#########################

## Análise em tempo de execucao do algoritmo HeapSort aplicando testes em tamanho e casos diferentes.

# É possível adicionar novos testes na pasta "testes" no formato ".txt" e com a primeira linha informando
 	a quantidade de numeros que será lido. 

# Também pode ser criado novos testes em "CriarNovosTestes.exe" 
	localizada dentro da pasta "lib" informando o nome do arquivo, a quantidade de numeros para serem 
	lidos e o tamanho máximo de cada número (semente).

# Pré-requisitos
	Linguagem de Programação: C/C++
	Compilador: TDM-GCC 4.9.2 64-bits
	IDE: DevC++
	Bibliotecas: 		Nome				Usado em

					#include<stdio.h> 	//entrada e saida padrao
					#include<stdlib.h> 	//biblioteca padrao
					#include<math.h> 	//calculos matematicos	
					#include<time.h> 	//Geracao de semente aleatoria
					#include<string.h> 	//manipulacao de strings
					#include <dirent.h> // recuperar arquivos de uma pasta
					#include <unistd.h> //buscar diretorio atual
					#include <limits.h> //saber tamanho da PATH
	
	Sistemas Operacionais Testados: Windows 10 (x64) e Linux 4.19.16-1-MANJARO (x64) 

# Informacoes #

	* @author Kevin Gomes
	* @contribuitors: Enio Gama, Luiz Henrich
	* @version 2.0
	* @since 2018

	* Baseado na aula do Canal "Linguagem C Programação Descomplicada"]
		link: <https://www.youtube.com/watch?v=zSYOMJ1E52A&list=PL8iN9FQ7_jt6VF821P5sPbg4plqpWKn0x&index=7>

# Testes aplicados:

	* Tempo 1: Ordena crescente
	* Tempo 2: Ordena crescente com ele ja ordenado
	* Tempo 3: Ordena decrescente depois crescente seguido
	* Tempo 4: Ordena crescente ate o meio e decrescente ate o fim
	* Tempo 5: Ordena decrescente ate o meio e crescente ate o fim

