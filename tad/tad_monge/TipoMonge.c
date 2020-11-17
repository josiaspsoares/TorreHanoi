#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
#include"../../style/style.h"
#include"TipoMonge.h"

void registerMonge(TipoMonge *DadosMonge){
    printf(NONE BOLD "\n\n\t\t\t\t\t\t==============================================\n" NONE);
	printf(C_BLUE BOLD "\t\t\t\t\t\t  *** TORRE DE HANÓI - CADASTRO DE MONGES ***  \n" NONE);
    printf(NONE BOLD "\t\t\t\t\t\t==============================================\n\n" NONE);
	printf(C_YELLOW BOLD "\t\t\t\t\t\t\t > Nome: " NONE);
    fflush(stdin);
    gets(DadosMonge->nome);
    DadosMonge->movimentos = 0;
    DadosMonge->pontos = 0;
    DadosMonge->rodadas = 0;
    strcpy(DadosMonge->ultimoMovimento, "NULL");
}