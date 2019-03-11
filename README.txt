	#################################
	#     ANALISE DE ALGORITMOS     #
	#################################

## Análise em tempo de execucao dos algoritmos: HeapSort, QuickSort, RadixSort, ShellSort aplicando testes em tamanho e casos diferentes.

# É possível adicionar novos testes na pasta "testes" no formato ".txt" e com a primeira linha informando
 	a quantidade de numeros que será lido. 

# Também pode ser criado novos testes em "CriarNovosTestes.exe" 
	localizada dentro da pasta "lib" informando primeiramente o tipo de Array a ser adicionado,
	o nome do arquivo, a quantidade de numeros para serem lidos e o tamanho máximo de cada número (semente).

# Executar via console
	$ gcc -Wall main.cpp -o main
	$ ./main (linux)
	$ main (windows)

# Pré-requisitos
	Linguagem de Programação: C/C++
	Compilador: TDM-GCC 4.9.2 64-bits
	IDE: DevC++
	Bibliotecas: 		Nome				Usado em

					#include<stdio.h>   //entrada e saida padrao
					#include<stdlib.h>  //biblioteca padrao
					#include<math.h>    //calculos matematicos	
					#include<time.h>    //Geracao de semente aleatoria
					#include<string.h>  //manipulacao de strings
					#include <dirent.h> // recuperar arquivos de uma pasta
					#include <unistd.h> //buscar diretorio atual
					#include <limits.h> //saber tamanho da PATH
	
	Sistemas Operacionais Testados: Windows 10 (x64) e Linux 4.19.16-1-MANJARO (x64) 

# Informacoes #

	* @author Kevin Gomes
	* @contribuitors: Enio Gama, Luiz Henrich, Victor Fellype;
	* @version 2.0
	* @since 2018

	* Fontes:
		Ordenacoes:
	 		Canal "Linguagem C Programação Descomplicada"]
				HeapSort: https://www.youtube.com/watch?v=zSYOMJ1E52A&list=PL8iN9FQ7_jt6VF821P5sPbg4plqpWKn0x&index=7
				QuickSort: https://www.youtube.com/watch?v=spywQ2ix_Co
	
			RadixSort: Victor Fellype via email (victor.fellype.a@gmail.com) | Git: https://github.com/victufell 
											 | Linkedin: https://www.linkedin.com/in/victor-fellype-a06717149/
			ShellSort: https://gist.github.com/nirocfz/3794605		
	
		Listar arquivos de uma pasta: 	https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program
						https://www.hardware.com.br/comunidade/arquivos-varrer/1103524/

# Testes aplicados:

	* Tempo 1: Ordena crescente
	* Tempo 2: Ordena crescente com ele ja ordenado
	* Tempo 3: Ordena decrescente
	* Tempo 4: Ordena decrescente depois crescente seguido

#Estrutura do Software

│   executarViaConsole.txt
│   main.cpp
│   main.exe
│   README.txt
│
├───lib
│       General.h
│       Sort.h
│       TesteTempo.h
│
├───src
│   │   CriarNovosTestes.cpp
│   │   Sort.cpp
│   │   TesteTempo.cpp
│   │
│   └───SortImpl
│           HeapSort.cpp
│           QuickSort.cpp
│           RadixSort.cpp
│           ShellSort.cpp
│
└───testes
    │
    ├───noventa-porcento-igual
    │       t1.txt
    │       t2.txt
    │       t3.txt
    │       t4.txt
    │       t5.txt
    │       t6.txt
    │
    └───sem-repeticao
            t1.txt
            t2.txt
            t3.txt
            t4.txt
            t5.txt
            t6.txt
