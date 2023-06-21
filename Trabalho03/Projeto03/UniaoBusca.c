#include "UniaoBusca.h"
#include <stdlib.h>
#include <stdio.h>

int compara(void *a, void *b) {
	int *x = a, *y = b;
	return (*x) - (*y);
}

void mostra_int(void *x) {
	int *a = x;
	printf("%d\n", *a);
}

void inicializa_conjunto(UniaoBusca *conjunto) {
	inicializa_lista(&conjunto->conjuntos, sizeof(Lista));
}

int busca_conjunto(UniaoBusca *conjunto, void *x) {
	Lista uni_bus_conjunto;
	inicializa_lista(&uni_bus_conjunto, sizeof(int));
	int i, j, found = 0, pos = -1;
	for (i = 0; i < conjunto->conjuntos.qtd && !found; i++) {
		le_valor(conjunto->conjuntos, &uni_bus_conjunto, i);
		pos = busca(&uni_bus_conjunto, x, compara);
		found = pos > -1 ? 1 : 0;
	}
	return conjunto->conjuntos.qtd > 0 && found ? i : -1;
}

int cria_conjunto(UniaoBusca *conjunto, void *x) {
	if (busca_conjunto(conjunto, x) > -1) {
		return ERRO_CONJUNTO_EXISTENTE;
	}

	Lista uni_bus_conjunto;
	inicializa_lista(&uni_bus_conjunto, sizeof(int));
	insere_fim(&uni_bus_conjunto, x);
	insere_fim(&conjunto->conjuntos, &uni_bus_conjunto);
	return 1;
}

void mostra_conjunto(UniaoBusca conjunto, int pos) {
	Lista uni_bus_conjunto;
	inicializa_lista(&uni_bus_conjunto, sizeof(int));
	le_valor(conjunto.conjuntos, &uni_bus_conjunto, pos);
	mostra_lista(uni_bus_conjunto, mostra_int);
}

void deleta_conjunto(UniaoBusca *conjunto, int pos) {
	Lista lista;
	remove_pos(&conjunto->conjuntos, &lista, pos);
}

int unir_conjuntos(UniaoBusca *conjunto, void *x, void *y) {
	int x_pos = busca_conjunto(conjunto, x);
	int y_pos = busca_conjunto(conjunto, y);
	if (x_pos < 0 || y_pos < 0) {
		return ERRO_CONJUNTO_INEXISTENTE;
	}

	Lista uni_bus_conjunto1, uni_bus_conjunto2;
	inicializa_lista(&uni_bus_conjunto1, sizeof(int));
	inicializa_lista(&uni_bus_conjunto2, sizeof(int));
	le_valor(conjunto->conjuntos, &uni_bus_conjunto1, x_pos - 1);
	le_valor(conjunto->conjuntos, &uni_bus_conjunto2, y_pos - 1);

	concatena(&uni_bus_conjunto1, &uni_bus_conjunto2);

	modifica_valor(conjunto->conjuntos, &uni_bus_conjunto1, x_pos - 1);
	deleta_conjunto(conjunto, y_pos-1);
	return 1;
}

void mostra_todos_conjuntos(UniaoBusca conjunto) {
	Lista uni_bus_conjunto;
	int i;
	for (i = 0; i < conjunto.conjuntos.qtd; i++) {
		mostra_conjunto(conjunto, i);
	}
}

void desaloca_conjunto(UniaoBusca *conjunto) {
	int i;
	for (i = 0; i < conjunto->conjuntos.qtd; i++) {
		deleta_conjunto(conjunto, i);
	}
	limpa_lista(&conjunto->conjuntos);
}
