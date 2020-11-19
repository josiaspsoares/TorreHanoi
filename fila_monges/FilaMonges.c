#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<stdbool.h> 
#include"FilaMonges.h"

struct fila{
    int quantidade;
    No *inicio;
    No *fim;
};

Fila *create(){
    Fila *FilaMonges = (Fila*) malloc(sizeof(Fila));

    if(FilaMonges != NULL){
        FilaMonges->inicio = NULL;
        FilaMonges->fim = NULL;
        FilaMonges->quantidade = 0;
        return FilaMonges;
    }
    
    printf("\nErro: Não foi possível alocar memória para a Fila!\n");
    return NULL;
    
}

bool isEmpty(Fila *FilaMonges){
    if(FilaMonges == NULL){
        return true;
    }

    return(FilaMonges->inicio == NULL);
}

bool isFull(Fila *FilaMonges){
    return false;
}

bool enqueue(Fila *FilaMonges, TipoMonge *DadosMonge){
    if(!isFull(FilaMonges)){
        No *NoAuxiliar = (No*) malloc(sizeof(No));

        if(NoAuxiliar == NULL){
            return false;
        }

        NoAuxiliar->Dados = *DadosMonge;
        NoAuxiliar->PilhaInicial = criaPilha();
        NoAuxiliar->PilhaAuxiliar = criaPilha();
        NoAuxiliar->PilhaFinal = criaPilha();
        constroiPilhaInicial(NoAuxiliar->PilhaInicial);

        NoAuxiliar->proximo = NULL;

        if(FilaMonges->fim == NULL){
            FilaMonges->inicio = NoAuxiliar;
        }
        else{
            FilaMonges->fim->proximo = NoAuxiliar;
        }

        FilaMonges->fim = NoAuxiliar;
        FilaMonges->quantidade++;
        return true;

    }
    else{
        printf("\t<<< A FILA ESTÁ CHEIA >>>\n\n");
        return false;
    }
}

bool dequeue(Fila *FilaMonges){
    if(FilaMonges == NULL){
        return false;
    }

    if(!isEmpty(FilaMonges)){
        No *NoAuxiliar = FilaMonges->inicio;
        FilaMonges->inicio = FilaMonges->inicio->proximo;

        if(FilaMonges->inicio == NULL){
            FilaMonges->fim = NULL;
        }

        free(NoAuxiliar);
        FilaMonges->quantidade--;
        return true;
    }
    else{
        printf("\t<<< NÃO HÁ MONGES CADASTRADOS >>>\n\n");
        return false;
    }
}

void playGame(Fila *FilaMonges, Lista *ListaPontos){

    while(!isEmpty(FilaMonges) && FilaMonges->inicio->Dados.rodadas < RODADAS){
        interfaceMovimentacao(&FilaMonges->inicio->Dados, FilaMonges->inicio->PilhaInicial, FilaMonges->inicio->PilhaAuxiliar, FilaMonges->inicio->PilhaFinal);

        TipoPonto *DadosPontos = (TipoPonto*) calloc(1, sizeof(TipoPonto));
        strcpy(DadosPontos->nomeMonge, FilaMonges->inicio->Dados.nome);
        FilaMonges->inicio->Dados.totalPontos += FilaMonges->inicio->Dados.pontos;
        DadosPontos->pontos = FilaMonges->inicio->Dados.totalPontos;

        if(FilaMonges->inicio->Dados.rodadas == RODADAS){
            insereListaOrdenada(ListaPontos, *DadosPontos);
        }
        
        FilaMonges->inicio->Dados.pontos = 0;
        FilaMonges->inicio->Dados.movimentos = 0;
        strcpy(FilaMonges->inicio->Dados.ultimoMovimento, "NULL");
        
        if(FilaMonges->inicio->Dados.rodadas == RODADAS){
            dequeue(FilaMonges);
        }
        else{
            enqueue(FilaMonges, &FilaMonges->inicio->Dados);
            dequeue(FilaMonges);
        }

        system("cls");
    }
}