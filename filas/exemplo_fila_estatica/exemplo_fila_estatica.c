#include <stdio.h>
#include <stdlib.h>
#include "../../libs/FilaEstatica.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Fila f1;
	
	inicializa_fila(&f1);
	mostra_fila(f1);
	
	inserir(&f1, 3);
	mostra_fila(f1);
	
	inserir(&f1, 6);
	mostra_fila(f1);
	
	inserir(&f1, 9);
	mostra_fila(f1);
	
	inserir(&f1, 12);
	mostra_fila(f1);
	
	int x;
	remover(&f1, &x);
	printf("X = %d\n", x);
	mostra_fila(f1); 		// percebe-se que começa a printar como indice 1, pois i começa com f.inicio.
	remover(&f1, &x);
	printf("X = %d\n", x);
	mostra_fila(f1);
	
	inserir(&f1, 15);
	inserir(&f1, 18);		// nota-se como o vetor é circular, uma vez que os novos valores forma para os índices 0 e 1.
	mostra_fila(f1);
	
	return 0;
}
