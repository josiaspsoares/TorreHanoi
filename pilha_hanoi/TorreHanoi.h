#include"../tad/TipoMonge.h"
#define DISCOS_POR_PILHA 4

typedef struct disco{
    int tamanho;
    char representacao[15];

    struct disco *under;
    struct disco *above;
}TipoDisco;

typedef struct pilha{
	int quantidade;
	TipoDisco *primeiro;
	TipoDisco *ultimo;
}Pilha;

Pilha *criaPilha();
int inserePilha(Pilha *PilhaHanoi, TipoDisco *DiscoAuxiliar);
void constroiPilhaInicial(Pilha *PilhaInicial);
void exibePilha(Pilha *PilhaExibir);
void removeDisco(Pilha *PilhaRemover);
void interfaceMovimentacao(TipoMonge DadosMonge, Pilha *PilhaInicial, Pilha *PilhaAuxiliar, Pilha *PilhaFinal);