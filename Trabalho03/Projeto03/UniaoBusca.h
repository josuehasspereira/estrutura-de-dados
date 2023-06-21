#include "Lista.h"

#define ERRO_COORD_INVALIDA -1
#define ERRO_CONJUNTO_EXISTENTE -1
#define ERRO_CONJUNTO_INEXISTENTE -1

typedef struct {
	Lista conjuntos;
} UniaoBusca;

int compara(void *a, void *b);
void mostra_int(void *x);
void inicializa_conjunto(UniaoBusca *conjunto);
int busca_conjunto(UniaoBusca *conjunto, void *x);
int cria_conjunto(UniaoBusca *conjunto, void *x);
void mostra_conjunto(UniaoBusca conjunto, int pos);
void deleta_conjunto(UniaoBusca *conjunto, int pos);
int unir_conjuntos(UniaoBusca *conjunto, void *x, void *y);
void mostra_todos_conjuntos(UniaoBusca conjunto);
void desaloca_conjunto(UniaoBusca *conjunto);
