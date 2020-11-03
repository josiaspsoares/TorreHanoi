#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include<locale.h>
#include<windows.h>
#include<math.h>
#include"../style/style.h"
#include "TorreHanoi.h"

Pilha *criaPilha(){
	Pilha *PilhaInicial;
	PilhaInicial = (Pilha*) malloc(sizeof(Pilha));

	PilhaInicial->quantidade = 0;
	PilhaInicial->primeiro = NULL;
	PilhaInicial->ultimo = NULL;

	return PilhaInicial;
}

void constroiPilhaInicial(Pilha *PilhaInicial){
    int i;
    char representacaoDiscos[15] = "==============";

    for(i = DISCOS_POR_PILHA; i >= 1; i--){
        TipoDisco *NovoDisco = (TipoDisco*) calloc(1, sizeof(TipoDisco));
        NovoDisco->tamanho = i;
        strncpy(NovoDisco->representacao, representacaoDiscos, i * 2);
        inserePilha(PilhaInicial, NovoDisco);
    }
}

int inserePilha(Pilha *PilhaHanoi, TipoDisco *DiscoAuxiliar){
    if(PilhaHanoi == NULL){
        return 0;
    }
    if(DiscoAuxiliar == NULL){
        return 0;
    }

	DiscoAuxiliar->above = NULL;

	if(PilhaHanoi->quantidade == 0){
		PilhaHanoi->primeiro = DiscoAuxiliar;
		DiscoAuxiliar->under = NULL;
	}
	else{
		PilhaHanoi->ultimo->above = DiscoAuxiliar;
		DiscoAuxiliar->under = PilhaHanoi->ultimo;
	}

	PilhaHanoi->ultimo = DiscoAuxiliar;
	PilhaHanoi->quantidade++;

    return 1;
}

void exibePilha(Pilha *PilhaExibir){
	if(PilhaExibir->quantidade == 0){
		printf("\t\t\t\t\t\t______________________\n\n");
		return;
	}

	TipoDisco *DiscoAuxiliar;
	DiscoAuxiliar = PilhaExibir->ultimo;
    
	while(DiscoAuxiliar != NULL){
        int i, tamanho = strlen(DiscoAuxiliar->representacao);

        fputs("\t\t\t\t\t\t     ", stdout);
        for (i=0; i<=((DISCOS_POR_PILHA * 2) - tamanho)/2; i++) {
            fputs(" ", stdout);
        }

        fputs(DiscoAuxiliar->representacao, stdout);

        // if(DiscoAuxiliar->tamanho == 1){
        //     printf(C_RED BOLD "%s" NONE, DiscoAuxiliar->representacao);
        // }
        // else if(DiscoAuxiliar->tamanho == 2){
        //     printf(C_GREEN BOLD "%s" NONE, DiscoAuxiliar->representacao);
        // }
        // else if(DiscoAuxiliar->tamanho == 3){
        //     printf(C_BLUE BOLD "%s" NONE, DiscoAuxiliar->representacao);
        // }
        // else if(DiscoAuxiliar->tamanho == 4){
        //     printf(C_YELLOW BOLD "%s" NONE, DiscoAuxiliar->representacao);
        // }
        

        i += tamanho;
        for (; i<= (DISCOS_POR_PILHA * 2); i++) {
            fputs(" ", stdout);
        }

		DiscoAuxiliar = DiscoAuxiliar->under;
        printf("\n");
	}

    printf("\t\t\t\t\t\t______________________\n\n");
    printf("\n\n");

}

void removeDisco(Pilha *PilhaRemover){
    if(PilhaRemover->quantidade == 0){
		printf("\t\t\t\t\t\t<<< NÃO HÁ DISCOS PARA REMOVER >>>\n\n");
		return;
	}

    TipoDisco *DiscoAuxiliar = PilhaRemover->ultimo;

    if(PilhaRemover->quantidade == 1){
		PilhaRemover->primeiro = NULL;
        PilhaRemover->ultimo = NULL;
    }
    else{
        PilhaRemover->ultimo->under->above = NULL;
        PilhaRemover->ultimo = PilhaRemover->ultimo->under;
    }
   
    PilhaRemover->quantidade--;
}

int menuOpcoes(){
	int opcao;

	printf("\n\t 1 - PI -> PA");
    printf("\t 2 - PI -> PF");
    printf("\t 3 - PA -> PI");
    printf("\t 4 - PA -> PF");
    printf("\t 5 - PF -> PI");
    printf("\t 6 - PF -> PA");
    printf("\t 0 - Sair\n\n");

    do{
        printf(C_GREEN "\t\t\t\t\t\t---> " NONE);
        fflush(stdin);
	    scanf("%d", &opcao);
    }while(opcao < 0 && opcao > 6);
	
    system("cls");
	return opcao;

}

void interfaceMovimentacao(TipoMonge DadosMonge, Pilha *PilhaInicial, Pilha *PilhaAuxiliar, Pilha *PilhaFinal){
    int controlador, pontos = 0, movimentos = 0, movimentosMinimos;
    movimentosMinimos = pow(2, DISCOS_POR_PILHA) - 1;
    TipoDisco *DiscoAuxiliar = (TipoDisco*) calloc(1, sizeof(TipoDisco));

    do{
        printf(C_GREEN BOLD "\t\t\t\t\t\t<<< TORRE DE HANOI >>\n\n");
        printf(C_BLACK BG_GRAY BOLD "\t\t<<< MONGE: %s  -  PONTOS: %d  -  MOVIMENTOS: %d  -  MÍNIMO: %d - ÚLTIMO: %s >>>\n\n" NONE, DadosMonge.nome, DadosMonge.pontos, DadosMonge.movimentos, movimentosMinimos, DadosMonge.ultimoMovimento);
        printf(NONE BOLD "\n\t\t\t\t\t\t*** PILHA INICIAL ***\n\n" C_MAGENTA);
        exibePilha(PilhaInicial);
        printf(NONE BOLD "\n\t\t\t\t\t\t*** PILHA AUXILIAR ***\n\n" C_RED);
        exibePilha(PilhaAuxiliar);
        printf(NONE BOLD "\n\t\t\t\t\t\t*** PILHA FINAL ***\n\n" C_YELLOW);
        exibePilha(PilhaFinal);
        printf(NONE "");

        controlador = menuOpcoes();

        if(controlador == 1 && PilhaInicial->ultimo != NULL && (PilhaAuxiliar->ultimo == NULL || (PilhaInicial->ultimo->tamanho < PilhaAuxiliar->ultimo->tamanho))){
            DiscoAuxiliar = PilhaInicial->ultimo;
            removeDisco(PilhaInicial);
            inserePilha(PilhaAuxiliar, DiscoAuxiliar);
            DadosMonge.movimentos++;
            strcpy(DadosMonge.ultimoMovimento, "PI -> PA");    
        }
        else if(controlador == 2 && PilhaInicial->ultimo != NULL && (PilhaFinal->ultimo == NULL || (PilhaInicial->ultimo->tamanho < PilhaFinal->ultimo->tamanho))){
            DiscoAuxiliar = PilhaInicial->ultimo;
            removeDisco(PilhaInicial);
            inserePilha(PilhaFinal, DiscoAuxiliar);
            DadosMonge.movimentos++;
            DadosMonge.pontos += 3;
            strcpy(DadosMonge.ultimoMovimento, "PI -> PF");   
        }
        if(controlador == 3 && PilhaAuxiliar->ultimo != NULL && (PilhaInicial->ultimo == NULL || (PilhaAuxiliar->ultimo->tamanho < PilhaInicial->ultimo->tamanho))){
            DiscoAuxiliar = PilhaAuxiliar->ultimo;
            removeDisco(PilhaAuxiliar);
            inserePilha(PilhaInicial, DiscoAuxiliar);
            DadosMonge.movimentos++;
            strcpy(DadosMonge.ultimoMovimento, "PA -> PI");     
        }
        else if(controlador == 4 && PilhaAuxiliar->ultimo != NULL && (PilhaFinal->ultimo == NULL || (PilhaAuxiliar->ultimo->tamanho < PilhaFinal->ultimo->tamanho))){
            DiscoAuxiliar = PilhaAuxiliar->ultimo;
            removeDisco(PilhaAuxiliar);
            inserePilha(PilhaFinal, DiscoAuxiliar);
            DadosMonge.movimentos++;
            DadosMonge.pontos += 3;
            strcpy(DadosMonge.ultimoMovimento, "PA -> PF");   
        }
        if(controlador == 5 && PilhaFinal->ultimo != NULL && (PilhaInicial->ultimo == NULL || (PilhaFinal->ultimo->tamanho < PilhaInicial->ultimo->tamanho))){
            DiscoAuxiliar = PilhaFinal->ultimo;
            removeDisco(PilhaFinal);
            inserePilha(PilhaInicial, DiscoAuxiliar);
            DadosMonge.movimentos++;
            DadosMonge.pontos -= 3;
            strcpy(DadosMonge.ultimoMovimento, "PF -> PI");     
        }
        else if(controlador == 6 && PilhaFinal->ultimo != NULL && (PilhaAuxiliar->ultimo == NULL || (PilhaFinal->ultimo->tamanho < PilhaAuxiliar->ultimo->tamanho))){
            DiscoAuxiliar = PilhaFinal->ultimo;
            removeDisco(PilhaFinal);
            inserePilha(PilhaAuxiliar, DiscoAuxiliar);
            DadosMonge.movimentos++;
            DadosMonge.pontos -= 3;
            strcpy(DadosMonge.ultimoMovimento, "PF -> PA");       
        }
        else if(controlador == 0){
            return;      
        }
            
    }while(controlador != 0);
    
}