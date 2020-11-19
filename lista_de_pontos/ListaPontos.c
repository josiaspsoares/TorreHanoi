#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<windows.h>
#include"../style/style.h"
#include"ListaPontos.h"

Lista* criaLista(){
    Lista* ListaPontos = (Lista*) malloc(sizeof(Lista));

    if(ListaPontos != NULL){
        ListaPontos->primeiro = NULL;
        ListaPontos->ultimo = NULL;
        ListaPontos->quantidade = 0;
    }

    return ListaPontos;
}

void liberaLista(Lista* ListaPontos){
    if(ListaPontos != NULL){
        Elemento* no;

        while(ListaPontos->primeiro != NULL){
            no = ListaPontos->primeiro;
            ListaPontos->primeiro = ListaPontos->primeiro->proximo;
            free(no);
        }

        free(ListaPontos);
    }
}

int insereListaOrdenada(Lista* ListaPontos, TipoPonto DadosPontos){
    if(ListaPontos == NULL) return 0;
    
    Elemento* no = (Elemento*) malloc(sizeof(Elemento));
    if(no == NULL) return 0;
    no->Dados = DadosPontos;

    if(ListaPontos->quantidade == 0){
        ListaPontos->primeiro = no;
		ListaPontos->ultimo = no;
        ListaPontos->quantidade++;
        return 1;
    }
    else{
		Elemento *anterior, *atual = ListaPontos->primeiro;

		while(atual != NULL && atual->Dados.pontos >= DadosPontos.pontos){
			anterior = atual;
			atual = atual->proximo;
		}

		if(atual == ListaPontos->primeiro){
			no->anterior = NULL;
			ListaPontos->primeiro->anterior = no;
			no->proximo = ListaPontos->primeiro;
			ListaPontos->primeiro = no;
		}
        else if(atual == ListaPontos->ultimo){
			no->proximo = NULL;
			ListaPontos->ultimo->proximo = no;
			no->anterior = ListaPontos->ultimo;
			ListaPontos->ultimo = no;
		}
		else{
			no->proximo = anterior->proximo;
			no->anterior = anterior;
			anterior->proximo = no;

			if(atual != NULL)
				atual->anterior = no;
		}

        ListaPontos->quantidade++;
        return 1;
	}
}

void exibeRanking(Lista *ListaPontos){
    if(ListaPontos->quantidade == 0){
        printf(C_RED BOLD"\n\n\t\t\t\t<<< PARTIDA NÃO REALIZADA! JOGUE E TENTE NOVAMENTE! >>>\n\n" NONE);
        Sleep(2000);
        return;
    }

    Elemento *NoAuxiliar = ListaPontos->primeiro;
    printf(NONE BOLD "\n\n\t\t\t\t\t\t====================================\n" NONE);
	printf(C_BLUE BOLD "\t\t\t\t\t\t  *** TORRE DE HANÓI - RANKING ***  \n" NONE);
    printf(NONE BOLD "\t\t\t\t\t\t====================================\n\n" NONE);
    while(NoAuxiliar != NULL){
        printf(C_GREEN BOLD "\n\t\t\t\t\t\t\t > Nome: %s" NONE, NoAuxiliar->Dados.nomeMonge);
        printf("\n\t\t\t\t\t\t\t > Pontos: %d\n", NoAuxiliar->Dados.pontos);
        NoAuxiliar = NoAuxiliar->proximo;
    }
    Sleep(6000);
}

