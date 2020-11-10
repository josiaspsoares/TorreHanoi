#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h> 
#include<locale.h>
#include"fila_monges/FilaMonges.h"
#include"style/style.h"

int menuInicial();
int menu();

int main(){

    setlocale(LC_ALL, "ptb");

    Fila *FilaMonges = create();
    Lista *ListaPontos = criaLista();
    int opcao;

    DISCOS_POR_PILHA = menuInicial();

    do{
        opcao = menu();
        switch (opcao){
            case 1:
                enqueue(FilaMonges);
                break;
            case 2:
                playGame(FilaMonges, ListaPontos);
                break;
            case 3:
                exibeRanking(ListaPontos);
                break;
            default: break;
        }

    }while(opcao != 0);

    return 0;
}

int menuInicial(){
	int opcaoDiscos;

    do{
        system("cls");
        printf(NONE BOLD "\n\n\t\t\t\t\t\t==================================\n" NONE);
	    printf(C_GREEN BOLD "\n\n\t\t\t\t\t\t*** BEM-VINDO À TORRE DE HANÓI ***\n" NONE);
        printf(NONE BOLD "\n\n\t\t\t\t\t\t==================================\n\n" NONE);
	    printf(C_MAGENTA BOLD"\n\n\t\t\t\t\t 1 - Informe o número de discos (MAX = 7): " NONE);
	    scanf("%d", &opcaoDiscos);
    }while(opcaoDiscos <= 0 || opcaoDiscos > 7);	

    return opcaoDiscos;
}

int menu(){
	int opcao;

	system("cls");

    printf(NONE BOLD "\n\n\t\t\t\t\t\t===================================\n\n" NONE);
	printf(C_RED BOLD "\t\t\t\t\t\t  *** TORRE DE HANÓI - MENU ***  \n\n" NONE);
    printf(NONE BOLD "\t\t\t\t\t\t===================================\n\n" NONE);
	printf(C_YELLOW "\t\t\t\t\t\t-> Informe a opção desejada:\n" NONE);
	printf("\n\t\t\t\t\t\t 1 - Cadastrar Monge");
    printf("\n\t\t\t\t\t\t 2 - Iniciar Jogo");
    printf("\n\t\t\t\t\t\t 3 - Ranking");
	printf("\n\t\t\t\t\t\t 0 - Sair");
	printf(C_GREEN "\n\n\n\t\t\t\t\t\t  ---> " NONE);
	scanf("%d", &opcao);

	if(opcao >= 0 && opcao < 4){
        system("cls");
		return opcao;
	}
	else{
		return menu();
	}

}