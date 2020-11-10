#include<stdlib.h>
#include<stdio.h>
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

		while(atual != NULL && atual->Dados.pontos > DadosPontos.pontos){
			anterior = atual;
			atual = atual->proximo;
		}

		if(atual == ListaPontos->primeiro){
			no->anterior = NULL;
			ListaPontos->primeiro->anterior = no;
			no->proximo = ListaPontos->primeiro;
			ListaPontos->primeiro = no;
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
        printf("\t<<< PARTIDA NÃO REEALIZADA! JOGUE E TENTE NOVAMENTE! >>>\n\n");
    }

    Elemento *NoAuxiliar = ListaPontos->primeiro;
    printf("\t*** RANKING ***\n\n");
    while(NoAuxiliar != NULL){
        printf("\n > Nome: %s", NoAuxiliar->Dados.nomeMonge);
        printf("\n > Pontos: %d\n", NoAuxiliar->Dados.pontos);
        NoAuxiliar = NoAuxiliar->proximo;
    }
    system("pause");
}