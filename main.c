#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<stdbool.h> 
#include<locale.h>
#include"fila_monges/FilaMonges.h"
#include"style/style.h"
#include"style/menus.h"

int main(){

    setlocale(LC_ALL, "ptb");

    Fila *FilaMonges = create();
    Lista *ListaPontos = criaLista();
    TipoMonge *DadosMonge = (TipoMonge*) malloc(sizeof(TipoMonge));
    int opcao;

    DISCOS_POR_PILHA = menuInicial();
    MAX_PONTOS = DISCOS_POR_PILHA * 3;
    RODADAS = menuRodadas();

    do{
        opcao = menu();
        switch (opcao){
            case 1:
                registerMonge(DadosMonge);
                enqueue(FilaMonges, DadosMonge);
                break;
            case 2:
                if(isEmpty(FilaMonges)){
                    printf(C_RED BOLD"\n\n\t\t\t\t<<< NENHUM MONGE CADASTRADO PARA JOGAR! >>>\n\n" NONE);
                    Sleep(2000);
                }
                else{
                    ListaPontos = criaLista();
                    playGame(FilaMonges, ListaPontos);
                }
                break;
            case 3:
                exibeRanking(ListaPontos);
                break;
            default: break;
        }

    }while(opcao != 0);

    liberaLista(ListaPontos);
    return 0;
}