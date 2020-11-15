#include"style.h"
#include"stdio.h"
#include"stdlib.h"

int menuInicial(){
	int opcaoDiscos;

    do{
        system("cls");
        printf(NONE BOLD "\n\n\t\t\t\t\t\t==================================\n" NONE);
	    printf(C_GREEN BOLD "\n\t\t\t\t\t\t*** BEM-VINDO À TORRE DE HANÓI ***\n" NONE);
        printf(NONE BOLD "\n\t\t\t\t\t\t==================================\n\n" NONE);
	    printf(C_MAGENTA BOLD"\n\t\t\t\t\t 1 - Informe o número de discos (MAX = 7): " NONE);
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