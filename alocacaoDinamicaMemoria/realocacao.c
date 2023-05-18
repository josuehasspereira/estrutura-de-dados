#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void mostra(int *p, int k);
void realoca(int **p, int *k);

int main(){
	srand(time(0));
	int n, i;
	printf("Digite o tamanho: ");
	scanf("%d", &n);
	int *v = malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++){
		v[i] = rand() % 100 + 1;
	}
	mostra(v, n);
	realoca(&v, &n);  //ponteiro v deve ser passado por referência
	mostra(v, n);
	free(v);
	
	return 0;
}

void mostra(int *p, int k){
	int i;
	for(i = 0; i < k; i++){
		printf("%d:%d\n", i, p[i]);
	}
	printf("\n\n");
}

void realoca(int **p, int*k){
	int x, i;
	printf("Quantos numeros a mais voce quer?: ");
	scanf("%d", &x);
	
	*p = realloc(*p, sizeof(int) * (*k + x)); 
	for(i = *k; i < *k + x; i++){
		(*p)[i] = i + 1;
	}
	*k += x; //Modifica o n para quando mostra() ser executada de novo, mostrar novos valores;
}
