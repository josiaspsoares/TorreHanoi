typedef struct{
    char nome[100];
    char ultimoMovimento[15];
    int movimentos;
    int pontos;
    int rodadas;
}TipoMonge;

void registerMonge(TipoMonge *DadosMonge);