#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char nomeArquivo[20];
unsigned long int tamArray, limitePossivel;

enum tipo { SEM_REPETICAO, NOVENTA_POR_CENTO_IGUAL } tipoDeArray;


///////////////////////////// Vetor sem repeticao /////////////////////////////

/* Analisa se o proximo elemento ja existe no vetor 
	
	Tipos de retornos
		'1': elemento existe, nao insere
		'0': elemento pode ser inserido		*/
unsigned long int verificaSeExiste(unsigned long int v[], unsigned long int pos, unsigned long int valorParaSerInserido){
    unsigned long int i;
    
    for (i=0; i<pos;i++)
    	if(v[i] == valorParaSerInserido)	return 1;
    	
    return 0;
}

/* Gera aleatoriamente um vetor sem elementos repetidos
	com um tamanho maximo de 30 000 numeros */
void criaVetorSemRepeticao(unsigned long int v[], unsigned long int tamArray){
    unsigned long int i;
    for ( i=0 ; i < tamArray; ){
        v[i] = 1+ rand()%limitePossivel;
        if (!verificaSeExiste(v, i, v[i]))  i++;
    }
}
///////////////////////////// Fim da criaco de vetor sem repeticao /////////////////////////////

///////////////////////////// Vetor 90% igual /////////////////////////////

void criaVetorNoventaPorcentoIgual (unsigned long int v[]){
    unsigned long int i, j=0;
    unsigned long int valor = 1 + rand()%limitePossivel;
    unsigned long int tamDistribuicao = tamArray * 0.1;
    unsigned long int *vetorSemRepeticao = (unsigned long int*) malloc(tamDistribuicao * sizeof(unsigned long int));
    unsigned long int intervaloDeInsercaoAleatoria = tamArray/tamDistribuicao;
	unsigned long int posAleatoria;
	
	criaVetorSemRepeticao(vetorSemRepeticao, tamDistribuicao);
	
    for ( i=0, posAleatoria=0 ; i < tamArray; i++){
    	if (i==posAleatoria){
    		v[i] = vetorSemRepeticao[j];	j++;
			posAleatoria+= intervaloDeInsercaoAleatoria;  
		}
		else
			v[i] = valor;
	}
	free(vetorSemRepeticao);
}


void verificaQuantidadeDeRepeticoes (unsigned long int v[]){
	unsigned long int rep=0, valorIgual = v[1], i;
	unsigned long int noventaPorCento = tamArray * 0.9;
	
	for (i=0; i<tamArray; i++)	if (v[i] == valorIgual)		rep++;
	
	printf ("\n\nNo tamanho %lu, 90\% e: %lu, no vetor existem %lu elementos repetidos\n\n ", tamArray, noventaPorCento, rep);
}


void gravaEmArquivo (int opcao){
	char caminho[60] = "" ;
	unsigned long int* v = (unsigned long int *) malloc(tamArray * sizeof(unsigned long int)); //aloca posicoes suficientes
	
	(opcao == SEM_REPETICAO) ?	(strcpy(caminho,"../testes/sem-repeticao/")) :
								(strcpy(caminho,"../testes/noventa-porcento-igual/"));
	
	if ( !strstr(nomeArquivo, ".txt"))
		strcat (nomeArquivo, ".txt");
	
	strcat (caminho, nomeArquivo);
	
	(opcao == SEM_REPETICAO)?	criaVetorSemRepeticao(v, tamArray) : criaVetorNoventaPorcentoIgual(v);
	
	FILE *arq = fopen (caminho, "w");
	
	if (!arq){
		puts ("\t\t\t\tErro de criacao!!");
		exit (1);
	}
	fprintf (arq, "%lu\n", tamArray);
	
	for (unsigned long int i=0; i < tamArray; i++){
		fprintf (arq, " %10lu", v[i]);
		if (((i+1)%10) == 0)	fprintf (arq, "\n");
	}
	printf ("\n\n\t\t\t\tTeste \"%s\" criado com sucesso!!\n\n\n", nomeArquivo);
	fclose (arq);
	free(v);
}

void msgErro (int* res){	puts ("--Erro de precessamento--");		*res = 0; }

int valida (int var, int typeArray){
	int res = 1;
	
	switch(var){
		case 1:
				if(!scanf("%s", nomeArquivo)) { msgErro(&res);	}	 break;
		
		case 2:
				if(!scanf("%lu", &tamArray)) msgErro(&res);
				if(typeArray == NOVENTA_POR_CENTO_IGUAL && tamArray < 10){
					msgErro(&res);
					puts ("\t\t---Tamanho minimo: 10!!---");
				}	 break;
		case 3:
				if(!scanf("%lu", &limitePossivel)) msgErro(&res);
				if (typeArray == SEM_REPETICAO && tamArray > limitePossivel){
					msgErro(&res);
					puts ("\t\t---Tamanho do Array deve ser maior que o limite possivel!!---");
				}	 
				if (typeArray == NOVENTA_POR_CENTO_IGUAL && (limitePossivel - 1) < (tamArray*0.10)){
					msgErro(&res);
					puts ("\t\t---Limite possivel deve ser maior que 10\% do tamanho do array!!---");
				}	 
				break;
	}
	return res;
}

int main ()	{
	int x; // indicador de menu
	int input;
	srand(time(NULL));
	
	while(1){
		x=1;
		input=2;
		printf ("\n\n\t\t\t\tCriacao de Testes\n");
		printf ("\n\t\t Escolha: \n"
			"\t\t\t 1) Sem repeticao\n"
			"\t\t\t 2) 90%% dos elementos iguais\n"
			"\n\t\t (Digite qualquer tecla para Sair)\n");
	
		printf ("\n\n\t\tDigite uma opcao: ");
		
		if (!scanf (" %d",&input))	break;
		
		x = --input;	printf ("\n\n");
		
		if ( x==SEM_REPETICAO || x==NOVENTA_POR_CENTO_IGUAL) {
			system ("cls");	
			printf ("\n\n\t\t\t%-40s \n", (x==SEM_REPETICAO) ? ("Criacao de vetor teste sem repeticao") : ("Criacao de vetor teste com 90%% igual"));
			printf ("\n\n\t\t\t\t$$ Informe os dados abaixo $$ \n\n\t\t\t[Nome do Arquivo]: ");	
			if ( !valida (1, x) ) continue;
			printf ("\t\t\t[Tamanho do Array]: ");
			if ( !valida (2, x) ) continue;
			printf ("\t\t\t[Limite Possivel]: ");
			if ( !valida (3, x) ) continue;
			
			gravaEmArquivo(x);
			
			printf ("\n\n\n");
		}
		else 	break;
		system("PAUSE");	system ("cls");
	} 
	system("PAUSE");
}
