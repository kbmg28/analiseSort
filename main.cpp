#include "lib/Sort.h"
#include "lib/TesteTempo.h"

/** Analise de Ordenacao

	* @author Kevin Gomes
	* @version 2.0
	* @since 2018
*/

int main(){
	void (*MENU[])() = {  testePadrao, testeComArquivoSemView, testeComArquivoView };
	int x; // indicador de menu
	int input;
	
	system("cls");
	while(1){
		x=1;
		printf ("\n\n\t\t\t\tSort Menu\n");
		printf ("\n\t\t Escolha: \n"
			"\t\t\t 1) Executar teste padrao\n"
			"\t\t\t 2) Escolher da pasta de testes\n"
			"\t\t\t 3) Escolher da pasta de testes com vizualizacao\n"
			"\n\t\t (Digite qualquer tecla para Sair)\n");
	
		printf ("\n\n\t\tDigite uma opcao: ");
		
		if (!scanf (" %d",&input))	break;
		
		x = --input;	printf ("\n\n");
		
		if (x>=0 && x<3) {
			system ("cls");	
			//printf ("\n\n\t\t\t\tHeapSort Menu\n");
			(*MENU[x])();
			printf ("\n\n\n");
		}
		else 	break;
		system("PAUSE");	system ("cls");
	} 
	free(original);
	printf ("\n\n\t\t\t\t\t Analise de Algoritmos Encerrado!!\n\n"); 	system ("PAUSE"); 	return 0;
}

