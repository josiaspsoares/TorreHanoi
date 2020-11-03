typedef struct{
    char nome[100];
    char ultimoMovimento[15];
    int movimentos;
    int pontos;
}TipoMonge;

typedef struct no{
    TipoMonge Dados;
    struct no *proximo;
}No;

typedef struct fila Fila;

Fila *create();
bool isEmpty(Fila *FilaMonges);
bool isFull(Fila *FilaMonges);
bool enqueue(Fila *FilaMonges, TipoMonge DadosMonge);
bool dequeue(Fila *FilaMonges);
TipoMonge front(Fila *FilaMonges);
void display(Fila *FilaMonges);