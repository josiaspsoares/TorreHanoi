#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include"TipoMonge.h"

void registerMonge(TipoMonge *DadosMonge){
    printf("\t*** CADASTRO DE MONGE ***\n\n");
	printf(" > Nome: ");
    fflush(stdin);
    gets(DadosMonge->nome);
    DadosMonge->movimentos = 0;
    DadosMonge->pontos = 0;
    strcpy(DadosMonge->ultimoMovimento, "NULL");
}