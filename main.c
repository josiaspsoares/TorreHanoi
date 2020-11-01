#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<locale.h>
#include"TorreHanoi.h"
#include"style.h"

int menu();

int main(){

    setlocale(LC_ALL, "ptb");

    Pilha *PilhaInicial = NULL;
    Pilha *PilhaAuxiliar = NULL;
    Pilha *PilhaFinal = NULL;
    
    int opcao;

    PilhaInicial = criaPilha();
    PilhaAuxiliar = criaPilha();
    PilhaFinal = criaPilha();

    if(PilhaInicial == NULL){
        printf("\nErro: Não foi possível alocar memória para a Lista!\n");
        exit(1);
    }
    constroiPilhaInicial(PilhaInicial);

    do{
        opcao = menu();
        switch (opcao){
            case 1:
                interfaceMovimentacao(PilhaInicial, PilhaAuxiliar, PilhaFinal);
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            default: break;
        }

    }while(opcao != 0);

    return 0;
}

int menu(){
	int opcao;

	system("cls");

	printf(NONE "\t*** MENU ***\n\n");
	printf("-> Informe a opção desejada:\n");
	printf("\n 1 - Costruir Torre");
    printf("\n 2 - Exibir Torre");
    printf("\n 3 - Remover Disco");
	printf("\n 0 - Sair");
	printf("\n\n  ---> ");
	scanf("%d", &opcao);

	if(opcao >= 0 && opcao < 4){
        system("cls");
		return opcao;
	}
	else{
		return menu();
	}

}