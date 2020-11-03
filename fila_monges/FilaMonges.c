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

void registerMonge(TipoMonge *DadosMonge){
    printf("\t*** CADASTRO DE MONGE ***\n\n");
	printf(" > Nome: ");
    fflush(stdin);
    gets(DadosMonge->nome);
    DadosMonge->movimentos = 0;
    DadosMonge->pontos = 0;
    strcpy(DadosMonge->ultimoMovimento, "NULL");
}

bool enqueue(Fila *FilaMonges){
    if(!isFull(FilaMonges)){
        TipoMonge *DadosMonge = (TipoMonge*) malloc(sizeof(TipoMonge));
        No *NoAuxiliar = (No*) malloc(sizeof(No));

        if(NoAuxiliar == NULL){
            return false;
        }

        registerMonge(DadosMonge);

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

void display(Fila *FilaMonges){
    if(FilaMonges == NULL){
        printf("\t<<< NÃO HÁ MONGES CADASTRADOS >>>\n\n");
    }

    No *NoAuxiliar = FilaMonges->inicio;
    while(NoAuxiliar != NULL){
        printf("\nNome: %s", NoAuxiliar->Dados.nome);
        printf("\nPontos: %d", NoAuxiliar->Dados.pontos);
        printf("\nMovimentos: %d\n", NoAuxiliar->Dados.movimentos);
        NoAuxiliar = NoAuxiliar->proximo;
    }
    system("pause");
}

TipoMonge front(Fila *FilaMonges){
    if(!isEmpty(FilaMonges)){
        return FilaMonges->inicio->Dados;
    }
    else{
        printf("\t<<< NÃO HÁ MONGES CADASTRADOS >>>\n\n");
        return;
    }
}

void playGame(Fila *FilaMonges){
    while(!isEmpty(FilaMonges)){
        interfaceMovimentacao(FilaMonges->inicio->Dados, FilaMonges->inicio->PilhaInicial, FilaMonges->inicio->PilhaAuxiliar, FilaMonges->inicio->PilhaFinal);
        dequeue(FilaMonges);
        system("cls");
    }
}