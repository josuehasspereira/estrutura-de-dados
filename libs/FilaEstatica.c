#include <stdio.h>
#include "FilaEstatica.h"

void inicializa_fila(Fila *f){
	f->inicio = f->n = 0;
}

int fila_vazia(Fila f){
	return f.n == 0;
}

int fila_cheia(Fila f){
	return f.n == MAX;
}

int inserir( Fila *f, int info ){
	if( fila_cheia( *f ) )
		return ERRO_FILA_CHEIA;
	
	int fim = ( f->inicio + f->n ) % MAX;
	f->dados[fim] = info;
	f->n++;
	return 1; // Sucesso.
}


int remover( Fila *f, int *info ){
	if( fila_vazia( *f ) )
		return ERRO_FILA_VAZIA;
	
	*info = f->dados[f->inicio];
	f->inicio = ( f->inicio + 1 ) % MAX;
	f->n--;
	return 1; // Sucesso.
}

void mostra_fila( Fila f ){
	if( fila_vazia( f ) )
		printf("Fila Vazia!\n");
	else{
		printf("Dados da Fila:\n");
		int cont, i;
		for( cont = 0, i = f.inicio ; cont < f.n ; cont++, i = ( i + 1) % MAX )
			printf("[%d] %d\n", i, f.dados[i]);
	}
	printf("---------------\n\n");
}

