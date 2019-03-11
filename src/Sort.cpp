#include "../lib/General.h"

// Funcao para auxiliar a ordenacao crescente
int crescente (unsigned long int a, unsigned long  int b){
	if (a > b)	return 1;
	else	return 0;
}
// Funcao para auxiliar a ordenacao decrescente
int decrescente (unsigned long int a, unsigned long  int b){
	if (a < b)	return 1;
	else	return 0;
}


				// FAZER FUNCAO DE TROCA


void print (unsigned long int *v){		//Funcao exclusiva para mostrar o vetor caso necessario
	for (unsigned long i=0; i<TAM; i++){
		printf ("%10lu ", v[i]);	// " %10lu reserva dez espacos para os numeros
		if ( (i+1) % 10 == 0) printf ("\n"); // organiza de 10 em 10
	}
	printf ("\n");
} //fim da fun��o print

void preencher (unsigned long int *v){ // funcao preencher
	for (unsigned long i=0; i<TAM; i++)
		v[i] = original[i]; // sempre insere os mesmos valores carregados em original
} // fim da funcao preencher


/* Gerar numeros para o vetor randomicamente 
	* Ex: rand() % size
	* rand(): Definido em stdlib.h
	* size: Tamanho maximo onde os elementos podem ser gerados
	
	* Para que haja trocas de valores a cada chamada de inicio de programa 
		e necessario usar: srand (time(NULL)); para trocar o valor da semente
		no qual calcula os numeros
*/
void START (void){ // funcao start
	for (unsigned long int i=0; i<TAM; i++)
		original[i] = 1 + rand() % 100000; // soma com 1 para retirar o 0 da randomizacao
} // fim da funcao start

///////////////////////////// Vetor sem repeticao /////////////////////////////

/* Analisa se o proximo elemento ja existe no vetor 
	
	Tipos de retornos
		'1': elemento existe, nao insere
		'0': elemento pode ser inserido		*/
int verificaSeExiste(unsigned long int v[], unsigned long  int pos, unsigned long int valor){
    unsigned long int i;
    for (i=0; i<pos;i++)	if(v[i] == valor)	return 1;
    return 0;
}

/* Gera aleatoriamente um vetor sem elementos repetidos
	com um tamanho maximo de 100 000 numeros */
void criaVetorSemRepeticao(unsigned long int v[]){
    for ( unsigned long i=0 ; i < TAM; ){
        v[i] = 1+ rand()%100000;
        if (!verificaSeExiste(v, i, v[i]))  i++;
    }
}
///////////////////////////// Fim da criaco de vetor sem repeticao /////////////////////////////

///////////////////////////// Vetor 90% igual /////////////////////////////

void criaVetorNoventaPorcentoIgual (unsigned long int v[]){
    unsigned long int valor = 1 + rand()%100000;
    unsigned long int tamDistribuicao = TAM * 0.1;
    unsigned long int intervaloDeInsercaoAleatoria = TAM/tamDistribuicao;
	
    for (unsigned long int i=0, posAleatoria=0 ; i < TAM; i++){
    	if (i==posAleatoria){
    		v[i] = 1 + rand() % 100000;
			posAleatoria+= intervaloDeInsercaoAleatoria; 
		}
		else
			v[i] = valor;
	}
}


void verificaQuantidadeDeRepeticoes (unsigned long int v[]){
	unsigned long int i, valorIgual = v[1];
	unsigned long int rep=0;
	unsigned long int noventaPorCento = TAM * 0.9;
	
	for (i=0; i<TAM; i++)	if (v[i] == valorIgual)		rep++;
	
	printf ("\n\nNo tamanho %lu, 90%% e: %lu, no vetor existem %lu elementos repetidos\n\n ", TAM, noventaPorCento, rep);
}
///////////////////////////// Fim da criaco de vetor com 90% de elementos iguais /////////////////////////////
