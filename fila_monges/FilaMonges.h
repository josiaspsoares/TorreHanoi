#include"../pilha_hanoi/TorreHanoi.h"
#include"../lista_de_pontos/ListaPontos.h"

typedef struct no{
    TipoMonge Dados;
    Pilha *PilhaInicial;
    Pilha *PilhaAuxiliar;
    Pilha *PilhaFinal;
    struct no *proximo;
}No;

typedef struct fila Fila;

Fila *create();
bool isEmpty(Fila *FilaMonges);
bool isFull(Fila *FilaMonges);
bool enqueue(Fila *FilaMonges);
bool dequeue(Fila *FilaMonges);
void display(Fila *FilaMonges);
void playGame(Fila *FilaMonges, Lista *ListaPontos);