STD = -std=c99

OPTIONS = -Wall -Wpedantic -Wno-unused-result -O0 -g

LIBRARIES = -lm

main : main.c pilha_hanoi/TorreHanoi.c fila_monges/FilaMonges.c lista_de_pontos/ListaPontos.c tad/tad_monge/TipoMonge.c
	gcc $(STD) $(OPTIONS) main.c pilha_hanoi/TorreHanoi.c fila_monges/FilaMonges.c lista_de_pontos/ListaPontos.c tad/tad_monge/TipoMonge.c -o main $(LIBRARIES)

