#include "../lib/TesteTempo.h"
#include "../lib/Sort.h"

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


tempoListPtr cria_no_listaTempo (long qtdElementos, double tempoUsado, int status){
	tempoListPtr novo = (tempoListPtr) malloc(sizeof(no_tempo));
	novo->qtdElementos = qtdElementos;
    novo->tempoUsado = tempoUsado;
    novo->status = status;
	novo->prox = NULL;
	return novo;
}

void addTempo (tempoListPtr *lista, tempoListPtr novo){
	tempoListPtr atual;
	
//	system ("cls");
//	puts ("\n\t\t--Inserir na lista--\n");
	if (!*lista)	*lista = novo;
	else{
		atual = *lista;
		
		while (atual->prox)
			atual = atual->prox;
		atual->prox = novo;
	}
//	printf ("\n\tElemento inserido no fim com sucesso!!\n\n");
}


void printTempo (tempoListPtr lista){	
	if (!lista)	return;
	//puts ("\n\t--Lista--\n");
	while (lista){
		printf ("\n\t Para %li elementos, gastou --> %G s", lista->qtdElementos, lista->tempoUsado);
		lista = lista->prox;
	}
	printf ("\n\n");
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
//    addTempo(&(novo->listTemposTestes), novoTempo);
    novo->listTemposTestes = NULL;
	novo->prox = NULL;
	return novo;
}

void addAnalise (analiseListPtr *lista, analiseListPtr novo){
	analiseListPtr atual;
	
//	system ("cls");
	//puts ("\n\t\t--Inserir na lista analise--\n");
	if (!*lista)	*lista = novo;
	else{
		atual = *lista;
		
		while (atual->prox)
			atual = atual->prox;
		atual->prox = novo;
	}
	//printf ("\n\tElemento inserido no fim com sucesso!!\n\n");
}

void addTempoOnAnalise (analiseListPtr *lista, const char* ordenacao, tempoListPtr novo){
	analiseListPtr atual;
	
//	system ("cls");
	//puts ("\n\t\t--Inserir na lista analise--\n");
	if (!*lista)	return;
	else{
		atual = *lista;
		
		while (atual->prox || !strcmp(atual->nomeOrdenacao, ordenacao))
			atual = atual->prox;
		if (!strcmp(atual->nomeOrdenacao, ordenacao))
            addTempo(&atual->listTemposTestes, novo);
	}
	//printf ("\n\tElemento inserido no fim com sucesso!!\n\n");
}

void print_lista (analiseListPtr lista){	
	if (!lista)	return;
	puts ("\n\t--Lista--\n");
	while (lista){
		printf ("-> %s \n", lista->nomeOrdenacao);
        if (lista->listTemposTestes)
            printTempo(lista->listTemposTestes);
		lista = lista->prox;
	}
	printf ("\n\n");
}

void libera_lista (analiseListPtr *lista){
	analiseListPtr atual;
	
	while(*lista){
		atual = *lista;
		*lista = (*lista)->prox;
		free (atual);
	}
	free (*lista);
	
	*lista = NULL;
}




int leArquivo2 (char* nomeArq){
	FILE *arq = fopen (nomeArq, "r"); //abre somente para leitura
	
	/* Erro na abertura */
	if (!arq)	return 0;
	
	//Se retornar eh porque o tamanho nao eh um numero
	if (!fscanf (arq, "%lu\n", &TAM))
		return 0; //erro
	
	MEIO = TAM/2; //define meio do vetor
	original = (unsigned long int *) malloc(TAM * sizeof(unsigned long int)); //aloca posicoes suficientes
	
	for (unsigned long int i=0; i < TAM; i++){ //carrega numero por numero do arqLido[60];
		if (!fscanf (arq, " %lu", &original[i])) //alguma parte da leitura nao eh um numero
			return 0; //erro
	}
	fclose (arq); //fecha arqLido[60];
	return 1; //numeros carregados no vetor original com sucesso!!
}


void fazTeste2(analiseListPtr* listAnalise){
	
	unsigned long int *v = (unsigned long int*) malloc (TAM * sizeof(unsigned long int));
	double tempo[4][4];
  	
  	printf ("\nCalculando tempo de ordenacao para vetor de %lu posicoes...\n\n", TAM);

	preencher(v);                        
	puts("Heap ");
	Sort_crescente (v, TAM, &tempo[0][0], 0, &HeapSort);    addTempoOnAnalise(listAnalise, "HeapSort", cria_no_listaTempo(TAM, tempo[0][0], 1));
	
    
	preencher(v);
	puts("Quick ");
	Sort_crescente (v, TAM-1, &tempo[1][0], 0, &QuickSort); addTempoOnAnalise(listAnalise, "QuickSort", cria_no_listaTempo(TAM, tempo[1][0], 1));
	
    preencher(v);
	puts("Radix ");
	Sort_crescente (v,TAM, &tempo[2][0], 0, &RadixSort);     addTempoOnAnalise(listAnalise, "RadixSort", cria_no_listaTempo(TAM, tempo[2][0], 1));
/*
	preencher(v);
	puts("Shell ");
	Sort_crescente (v, TAM, &tempo[3][0], 0, &ShellSort);   addTempoOnAnalise(listAnalise, "ShellSort", cria_no_listaTempo(TAM, tempo[3][0], 1));
*/	
    puts ("opa");

//	tempo_gasto(tempo);
	free(v);
}

void testaTodosOsArquivos (char*caminho, analiseListPtr* listAnalise){
    DIR *dir;
    struct dirent *lsdir;       
    char cwd[PATH_MAX];
    char arqLido[100];
    if (!getcwd(cwd, sizeof(cwd)))
       return;      
	
	strcat (cwd, "/");	strcat (cwd, caminho);    dir = opendir(cwd);
    //printf ("\n\nArquivos da pasta \"%s\" \n", caminho);
    
    addAnalise(listAnalise, cria_no_Analise("HeapSort"));
    addAnalise(listAnalise, cria_no_Analise("QuickSort"));
    addAnalise(listAnalise, cria_no_Analise("RadixSort"));
    addAnalise(listAnalise, cria_no_Analise("ShellSort"));
    
    /* reading all the files and directories within directory */
    while ( ( lsdir = readdir(dir) ) != NULL ){
        //printf ("\t\t\t%s\n", lsdir->d_name);
        
        strcpy (arqLido, cwd);  strcat (arqLido, "/");  strcat(arqLido, lsdir->d_name);
        
        if (strstr(arqLido, ".txt")){
            if (leArquivo2(arqLido)){
                printf ("\n\tCarregou o arquivo \"%s\" com o tamanho: %lu", lsdir->d_name, TAM);

                fazTeste2(listAnalise);
                //print_lista(*listAnalise);
                free(original);
            }
        }
    }
}


int main (){
    char caminho[] = "../testes/sem-repeticao";
    analiseListPtr listAnalise = NULL;
    testaTodosOsArquivos(caminho, &listAnalise);

/*    analiseListPtr listAnalise = NULL;
    tempoListPtr listTempo = NULL;

    addAnalise(&listAnalise, cria_no_Analise("HeapSort"));
    addAnalise(&listAnalise, cria_no_Analise("QuickSort"));
    addAnalise(&listAnalise, cria_no_Analise("RadixSort"));
    addAnalise(&listAnalise, cria_no_Analise("ShellSort"));
    
    
    addTempo(&listTempo, cria_no_listaTempo(100, 0.0004, 1));
    addTempo(&listTempo, cria_no_listaTempo(1000, 0.0002, 1));
    addTempo(&listTempo, cria_no_listaTempo(10000, 0.0001, 1));

    listAnalise->prox->listTemposTestes = listTempo;

    print_lista(listAnalise);
    libera_lista(&listAnalise);
    libera_listaTempo(&listTempo);
*/

    print_lista(listAnalise);
    puts ("ok");

    
    libera_lista(&listAnalise);
    
}