#define MAX 4
#define ERRO_FILA_VAZIA -1
#define ERRO_FILA_CHEIA -2

typedef struct {
	int dados[MAX];
	int inicio, n;
}Fila;

void inicializa_fila(Fila *f);
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int inserir(Fila *f, int info);
int remover(Fila *f, int *info);
void mostra_fila(Fila f);
