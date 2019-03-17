#include "../lib/General.h"
#include "../lib/Sort.h"
/* Funcao: tempo_gasto
	Objetivo:
		Apresenta o tempo de cada ordenacao 
		
		* A linha representa a ordenacao analisada
			-> HeapSort
			-> QuickSort
			-> RadixSort
			-> ShellSort
		
		* As colunas representam os tempos de cada ordenacao
			*	Tempo 1: Ordena crescente
			*	Tempo 2: Ordena crescente com ele ja ordenado
			*	Tempo 3: Ordena decrescente depois crescente seguido
			*	Tempo 4: Ordena crescente ate o meio e decrescente ate o fim
			*	Tempo 5: Ordena decrescente ate o meio e crescente ate o fim 
*/
void tempo_gasto (double tempo[][4]){ //inicio da funcao de tempo_gasto
	
	int i, j;
	const char nome[QTD_ORDENACOES][15] = {"HeapSort", "QuickSort", "RadixSort", "ShellSort"}; /*Se for analisar mais de uma ordenacao, acrescentar o
															nome dela nesta matriz de caracteres e a funcao que 
															corresponde	no pacote seguindo o padrao especificado */
	const char nomeTempos[4][60] = { "Ordena crescente",  
									"Ordena crescente com ele ja ordenado",
									"Ordena decrescente",
									"Ordena decrescente depois crescente seguido"};
	for (i=0; i<QTD_ORDENACOES; i++){ 
		printf ("\n\n\n\n\t\t%s\n", nome[i]);	//Nome de cada ordenacao
		for (j=0; j<4; j++){ //Os 4 tempos descritos acima
			printf ("\n Tempo %d -->   %-55s--> ", j+1, nomeTempos[j]);
			if (tempo[i][j] == -1.0){
				puts ("Stack Overflow");
				continue;	
			}
			else printf ("%.3f s", tempo[i][j]); 
			
			if (!tempo[i][j]) printf ("\t Tempo menor que um microsegundo"); // Se o tempo for exatamente igual a 0
			printf ("\n");
		}
	}
} //fim da funcao tempo_gasto


/* As funcoes para definir o tempo das ordenacoes possuem o mesmo prototipo
	com excessao da primeira que para reduzir o tempo de criacao do codigo
	foi definida com o parametro int pos para referir ao tempo 1 e ao tempo 2
 	
	* Prototipo: void *nome* (unsigned long int *v, double *tempo, void (*type_sort) (unsigned long int *, int, int, int (*ordem) (int, int)));
		* unsigned long int v: vetor analisado
		* double *tempo: ponteiro para matriz do tempo gasto para ordenar
		* void (*type_sort): ponteiro para funcao do tipo de ordenacao utilizada
*/
void Sort_crescente (unsigned long int *v, int N, double *tempo, int pos, void (*type_sort) (unsigned long int *, int, int, int (*ordem) (unsigned long int, unsigned long int))){
	clock_t tp1, tp2;
	
	tp1 = clock();
	type_sort (v, 0, N, &crescente);
	tp2 = clock();
	
	tempo[pos] = (double) (tp2 - tp1) / CLOCKS_PER_SEC;	// Registra o tempo exato de execucao
}

void Sort_decrescente (unsigned long int *v, int N, double *tempo, void (*type_sort) (unsigned long int *, int, int, int (*ordem) (unsigned long int, unsigned long int))){
	clock_t tp1, tp2;
	
	preencher (v);	// Volta ao vetor original
	tp1 = clock();
	type_sort (v, 0, N, &decrescente);
	tp2 = clock();
	
	tempo[2] = (double) (tp2 - tp1) / CLOCKS_PER_SEC;	// Registra o tempo exato de execucao
}

void Sort_decrescente_crescente (unsigned long int *v, int N, double *tempo, void (*type_sort) (unsigned long int *, int, int, int (*ordem) (unsigned long int,unsigned long  int))){
	clock_t tp1, tp2;
	preencher (v);	// Volta ao vetor original
	
	tp1 = clock();
	type_sort (v, 0, N, &decrescente);
	type_sort (v, 0, N, &crescente);
	tp2 = clock();
	
	tempo[3] = (double) (tp2 - tp1) / CLOCKS_PER_SEC;
}

/////////////////////////////  FIIIM DAS COMPARACOES E CALCULO DE TEMPO ////////////////////////////////


/* Indepentente se for do arquivo ou padrao, vai executar
	os testes 
	
	*Parametros
		view : Vizualizar vetor na tela (1: nao, 2: sim)	*/
void fazTeste(int view){
	
	unsigned long int *v = (unsigned long int*) malloc (TAM * sizeof(unsigned long int));
	double tempo[4][4];
  	
  	printf ("\nCalculando tempo de ordenacao para vetor de %lu posicoes...\n\n", TAM);

	preencher(v);
	if (view == 2){
		puts ("\n\n\n\t\t\tHeapSort");
		puts ("\n\t Original \n");
		print(v);
	}
	Sort_crescente (v, TAM, &tempo[0][0], 0, &HeapSort);
	Sort_crescente (v, TAM, &tempo[0][0], 1, &HeapSort);
	if (view == 2){
		puts ("\n\t Ordem Crescente \n");
		print(v);
	}
	Sort_decrescente (v, TAM, &tempo[0][0], &HeapSort);
	if (view == 2){
		puts ("\n\t Ordem Decrescente \n");
		print(v);
	}
//	puts("Heap 4");
	Sort_decrescente_crescente (v, TAM, &tempo[0][0], &HeapSort);
	
	
		
	if (TAM <= 25000){
		preencher(v);
		Sort_crescente (v, TAM-1, &tempo[1][0], 0, &QuickSort);
		Sort_crescente (v, TAM-1, &tempo[1][0], 1, &QuickSort);
		if (view == 2){
			puts ("\n\n\n\t\t\tQuickSort");
			puts ("\n\t Ordem Crescente \n");
			print(v);
		}
		Sort_decrescente (v, TAM-1, &tempo[1][0], &QuickSort);
		if (view == 2){
			puts ("\n\t Ordem Decrescente \n");
			print(v);
		}
		Sort_decrescente_crescente (v, TAM-1, &tempo[1][0], &QuickSort);
		
	}
	else	tempo[1][0] = tempo[1][1] = tempo[1][2] = tempo[1][3] = -1.0;
	
	preencher(v);
	Sort_crescente (v,TAM, &tempo[2][0], 0, &RadixSort);
	Sort_crescente (v,TAM, &tempo[2][0], 1, &RadixSort);
	if (view == 2){
		puts ("\n\n\n\t\t\tRadixSort");
		puts ("\n\t Ordem Crescente \n");
		print(v);
	}
	//Sort_decrescente (v, TAM, &tempo[2][0], &RadixSort);
	tempo[2][2]=-1;
	
	Sort_decrescente_crescente (v, TAM, &tempo[2][0], &RadixSort);
	
	
	preencher(v);
	Sort_crescente (v, TAM, &tempo[3][0], 0, &ShellSort);
	Sort_crescente (v, TAM, &tempo[3][0], 1, &ShellSort);
	if (view == 2){
		puts ("\n\n\n\t\t\tShellSort");
		puts ("\n\t Ordem Crescente \n");
		print(v);
	}
	Sort_decrescente (v, TAM, &tempo[3][0], &ShellSort);
	if (view == 2){
		puts ("\n\t Ordem Decrescente \n");
		print(v);
	}
	Sort_decrescente_crescente (v, TAM, &tempo[3][0], &ShellSort);

	tempo_gasto(tempo);
	free(v);
}

/* Se no menu o usuario optar pelo teste padrao, executara
	com o valor definido por TAM_PADRAO */
void carregaTamanhoArrayPadrao (){
	TAM = TAM_PADRAO;
	MEIO = MEIO_PADRAO;
	
	original = (unsigned long int *) malloc(TAM * sizeof(unsigned long int));
}

void testePadrao (){
	srand(time(NULL)); //A cada escolha novos numeros
	carregaTamanhoArrayPadrao(); // aloca o original por default
	START();	//define valores do original
	fazTeste(1); //executa o teste sem vizualizacao
	free(original);
}
///////////////////// FIM DO TESTE PADRAO /////////////////////

/* Busca arquivo na pasta de testes */
int leArquivo (char* nomeArq){
	FILE *arq = fopen (nomeArq, "r"); //abre somente para leitura
	
	/* Erro na abertura */
	if (!arq)	return 0;
	
	//Se retornar eh porque o tamanho nao eh um numero
	if (!fscanf (arq, "%lu\n", &TAM))
		return 0; //erro
	
	MEIO = TAM/2; //define meio do vetor
	original = (unsigned long int *) malloc(TAM * sizeof(unsigned long int)); //aloca posicoes suficientes
	
	for (unsigned long int i=0; i < TAM; i++){ //carrega numero por numero do arquivo
		if (!fscanf (arq, " %lu", &original[i])) //alguma parte da leitura nao eh um numero
			return 0; //erro
	}
	fclose (arq); //fecha arquivo
	return 1; //numeros carregados no vetor original com sucesso!!
}

/* Fontes:
			https://stackoverflow.com/questions/298510/how-to-get-the-current-directory-in-a-c-program
			https://www.hardware.com.br/comunidade/arquivos-varrer/1103524/ */
void listaArquivosExistentes (char*caminho){
    DIR *dir;
    struct dirent *lsdir;
    char cwd[PATH_MAX];
 
    if (!getcwd(cwd, sizeof(cwd)))
       return;
	
	strcat (cwd, "/");	strcat (cwd, caminho);    dir = opendir(cwd);
    printf ("\n\nArquivos da pasta \"%s\" \n", caminho);
    
    /* print all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL )
        printf ("\t\t\t%s\n", lsdir->d_name);
    puts("\n\n");
    closedir(dir);
}

/* Se existir o arquivo desejado retorna 1, caso contrario 0 */
int informaNomeArquivo (char *caminho){
	char nomeArquivo[20];
	printf ("\n\n## Informe o nome do arquivo para testar ##\n\t\t"
			"(Lembre-se que a primeira linha do arquivo deve especificar a quantidade de numeros a serem lidos!!)\n\n");
	listaArquivosExistentes(caminho);
	printf("\t\t> ");
	scanf (" %s", nomeArquivo); //le via teclado o nome do arquivo
	
	if ( !strstr(nomeArquivo, ".txt"))//verifica se existe a extensao .txt
		strcat (nomeArquivo, ".txt");//se nao houver, coloca
	
	strcat (caminho, nomeArquivo); //indica o caminho da pasta
	if ( !leArquivo(caminho) ) { //verifica se o arquivo eh valido
		puts ("\n\n--->> Arquivo nao existe na pasta de testes ou nao contem somente numeros <<---");
		return 0; //erro
	}
	return 1; //original carregado com sucesso		
}

void escolheQualTipoDeTeste(int *op){
	printf ("\n\n\t\t\t\tTESTES\n");
	printf ("\n\t\t Escolha: \n"
			"\t\t\t 1) Sem repeticao\n"
			"\t\t\t 2) 90%% dos elementos iguais\n"
			"\n\t\t (Digite qualquer tecla para Sair)\n");
	                printf ("\n\n\t\tDigite uma opcao: ");
	if(!scanf("%d", op)) *op = -1;
}

/* Por padrao a pasta de carregamento fica em .../lib/testes */
void testeArquivo(int view){ //Apresenta apenas o resultado do teste
	char caminho[60];
	int op;
	escolheQualTipoDeTeste(&op);
	if (op == 1){
		strcpy (caminho, "testes/sem-repeticao/");
		if (informaNomeArquivo(caminho)) //Tenta encontrar o arquivo digitado
			fazTeste(view);
	} 
	else if (op == 2){
		strcpy(caminho, "testes/noventa-porcento-igual/");
		if (informaNomeArquivo(caminho)) //Tenta encontrar o arquivo digitado
			fazTeste(view); 
	}
		
	else
		puts ("\n\t-----Opcao Invalida!!-----\n");
		
	free(original);
	original = NULL;
}


void testeComArquivoSemView(){ // Calcula sem mostrar os numeros
	testeArquivo(1);
}
void testeComArquivoView(){ // Mostra no console os numeros usados
	testeArquivo(2);
}

///////////////////// FIM DO TESTE DE ARQUIVO /////////////////////



///////////////////// TESTE DE TODOS OS ARQUIVOS /////////////////////

tempoListPtr cria_no_listaTempo (long qtdElementos, double tempoUsado, int status){
	tempoListPtr novo = (tempoListPtr) malloc(sizeof(no_tempo));
	novo->qtdElementos = qtdElementos;
    novo->tempoUsado = tempoUsado;
    novo->status = status;
	novo->prox = NULL;
	return novo;
}


void printTempo (tempoListPtr lista, FILE *arq){	
	if (!lista)	return;
	printf ("\n\t%-15s  |  %-10s\n", "Quantidade lida", "Tempo usado");
	while (lista){
		printf ("\n\t %15li --> %.3f s", lista->qtdElementos, lista->tempoUsado);
		fprintf (arq, "%15li;%.3f\n", lista->qtdElementos, lista->tempoUsado);
		lista = lista->prox;
	}
	printf ("\n\n");
}

void addTempo (tempoListPtr *lista, tempoListPtr novo){
	tempoListPtr atual, anterior;

	if (!*lista)	*lista = novo;
	else{
		atual = *lista;
		anterior = NULL;

		while (atual->prox != NULL && (atual->qtdElementos < novo->qtdElementos)){
			anterior = atual;
			atual = atual->prox;
		}

		if (anterior == NULL){
			if (novo->qtdElementos < atual->qtdElementos){
				novo->prox = atual;
				*lista = novo;
			}
			else
				atual->prox = novo;
		}
		else if (atual->prox == NULL){
			if (novo->qtdElementos < atual->qtdElementos){
				novo->prox = atual;
				anterior->prox = novo;
			}
			 else
			 	atual->prox = novo;
		}
		else{
			if (novo->qtdElementos < atual->qtdElementos){
				anterior->prox = novo;
				novo->prox = atual;
			}
			else{
				novo->prox = atual->prox;
				atual->prox = novo;
			}
		}
	}
}

void libera_listaTempo (tempoListPtr *lista){
	tempoListPtr atual;
	
	while(*lista){
		atual = *lista;
		*lista = (*lista)->prox;
		free (atual);
	}
	free (*lista);
	
	*lista = NULL;
}



analiseListPtr cria_no_Analise (const char* nomeOrdenacao){
	analiseListPtr novo = (analiseListPtr) malloc(sizeof(no_analise));
	strcpy(novo->nomeOrdenacao, nomeOrdenacao);
    novo->listTemposTestes = NULL;
	novo->prox = NULL;
	return novo;
}

void addAnalise (analiseListPtr *lista, analiseListPtr novo){
	analiseListPtr atual;
	
	if (!*lista)	*lista = novo;
	else{
		atual = *lista;
		
		while (atual->prox)
			atual = atual->prox;
		atual->prox = novo;
	}
}

void addTempoOnAnalise (analiseListPtr *lista, const char* ordenacao, tempoListPtr novo){
	analiseListPtr atual;
	
	if (!*lista)	return;
	else{
		atual = *lista;
		
		while (atual->prox && strcmp(atual->nomeOrdenacao, ordenacao))
			atual = atual->prox;

		if (!strcmp(atual->nomeOrdenacao, ordenacao))
			addTempo(&(atual->listTemposTestes), novo);
	}
}


void print_lista (analiseListPtr lista, const char* tipoDoTeste){	
	char caminho[30] = "testes/";
	FILE *arq;
	
	strcat(caminho, tipoDoTeste); strcat(caminho, ".txt");
	arq = fopen(caminho, "w");
	
	if (!lista || !arq)	return;
	
	puts ("\n\t---------------Lista---------------\n");
	while (lista){
		printf ("-> %s \n", lista->nomeOrdenacao);
		fprintf (arq, "\n\n%15s;Tempo\n", lista->nomeOrdenacao);
		
        if (lista->listTemposTestes)
            printTempo(lista->listTemposTestes, arq);
		lista = lista->prox;
	}
	printf ("\n\n");
	fclose(arq);
}

void libera_lista (analiseListPtr *lista){
	analiseListPtr atual;
	
	while(*lista){
		atual = *lista;
		libera_listaTempo(&(atual->listTemposTestes));
		*lista = (*lista)->prox;
		free (atual);
	}
	free (*lista);
	
	*lista = NULL;
}

void fazTesteComLista(analiseListPtr* listAnalise){
	
	unsigned long int *v = (unsigned long int*) malloc (TAM * sizeof(unsigned long int));
	double tempo[4][4];
  	
  	//printf ("\nCalculando tempo de ordenacao para vetor de %lu posicoes...\n\n", TAM);

	preencher(v);                        
	//printf("\t\tHeap ");
	Sort_crescente (v, TAM, &tempo[0][0], 0, &HeapSort);    addTempoOnAnalise(listAnalise, "HeapSort", cria_no_listaTempo(TAM, tempo[0][0], 1));
	//puts ("\tok");
    
	if (TAM<=25000){
		preencher(v);
	//	printf("\t\tQuick ");
		Sort_crescente (v, TAM-1, &tempo[1][0], 0, &QuickSort); addTempoOnAnalise(listAnalise, "QuickSort", cria_no_listaTempo(TAM, tempo[1][0], 1));
	//	puts ("\tok");
	}
    preencher(v);
	//printf("\t\tRadix ");
	Sort_crescente (v,TAM, &tempo[2][0], 0, &RadixSort);     addTempoOnAnalise(listAnalise, "RadixSort", cria_no_listaTempo(TAM, tempo[2][0], 1));
	//puts ("\tok");
	
	preencher(v);
	//printf("\t\tShell ");
	Sort_crescente (v, TAM, &tempo[3][0], 0, &ShellSort);   addTempoOnAnalise(listAnalise, "ShellSort", cria_no_listaTempo(TAM, tempo[3][0], 1));
	//puts ("\tok");

	free(v);
}

void testaTodosOsArquivos (const char*caminho, const char* tipoDoTeste){
    DIR *dir;
    struct dirent *lsdir;       
    char cwd[PATH_MAX];
    char arqLido[100];
    analiseListPtr list = NULL;
    analiseListPtr* listAnalise = &list;
    
	if (!getcwd(cwd, sizeof(cwd)))
       return;      
	
	strcat (cwd, "/");	strcat (cwd, caminho);    dir = opendir(cwd);
    //printf ("\n\nArquivos da pasta \"%s\" \n", caminho);
    printf ("\n\n\t\tCalculando os tempos para %s...\n", tipoDoTeste);
    addAnalise(listAnalise, cria_no_Analise("HeapSort"));
    addAnalise(listAnalise, cria_no_Analise("QuickSort"));
    addAnalise(listAnalise, cria_no_Analise("RadixSort"));
    addAnalise(listAnalise, cria_no_Analise("ShellSort"));
    
    /* reading all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL ){
        //printf ("\t\t\t%s\n", lsdir->d_name);
        
        strcpy (arqLido, cwd);  strcat (arqLido, "/");  strcat(arqLido, lsdir->d_name);
        if (strstr(arqLido, ".txt")){
            if (leArquivo(arqLido)){
                //printf ("\n\tCarregou o arquivo \"%s\" com o tamanho: %lu\n", lsdir->d_name, TAM);
                fazTesteComLista(listAnalise);
                free(original);
                original = NULL;
            }
        }
    }
    
    print_lista(list, tipoDoTeste);
  //  puts ("ok");
    libera_lista(listAnalise);
}

void testeComTodasAsOrdenacoes(){
	
    testaTodosOsArquivos("testes/noventa-porcento-igual", "noventa-por-cento-igual");
    testaTodosOsArquivos("testes/sem-repeticao", "sem-repeticao");
	
	puts ("\n\t\t Os tempos foram salvos na pasta de teste!!\n");
}
