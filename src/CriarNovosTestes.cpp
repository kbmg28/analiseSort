#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

char nomeArquivo[20];
int tamArray, limitePossivel;

void gravaEmArquivo (){
	char caminho[40] = "../testes/";
	if ( !strstr(nomeArquivo, ".txt"))
		strcat (nomeArquivo, ".txt");
	
	strcat (caminho, nomeArquivo);
	
	
	FILE *arq = fopen (caminho, "w");
	
	if (!arq){
		puts ("\t\t\t\tErro de criacao!!");
		exit (1);
	}
	fprintf (arq, "%d\n", tamArray);
	
	for (int i=0; i < tamArray; i++){
		fprintf (arq, " %d", (1+rand()%limitePossivel));
		if (((i+1)%10) == 0)	fprintf (arq, "\n");
	}
	printf ("\n\n\t\t\t\tTeste \"%s\" criado com sucesso!!\n\n\n", nomeArquivo);
	fclose (arq);
}

void valida (int type){
	switch(type){
		case 1:
			if(!scanf("%s", &nomeArquivo)){
				puts ("--Erro de precessamento--");
				exit(0);
			}; break;
		
		case 2:
			if(!scanf("%d", &tamArray)){
				puts ("--Erro de precessamento--");
				exit(0);
			}; break;
		
		case 3:
			if(!scanf("%d", &limitePossivel)){
				puts ("--Erro de precessamento--");
				exit(0);
			}; break;
	}
}
int main ()	{
	
	srand(time(NULL));
	
	printf ("\n\n\t\t\t\t$$ Informe os dados abaixo $$ \n\n\t\t\t[Nome do Arquivo]: ");
	valida (1);
	printf ("\t\t\t[Tamanho do Array]: ");
	valida (2);
	printf ("\t\t\t[Limite Possivel]: ");
	valida (3);
	
	gravaEmArquivo();
	system("PAUSE");
}
