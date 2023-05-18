#include <stdio.h>
#include <stdlib.h>

//função retorna vetor alocado dinamicamente com os índices em que a chave se encontra (terminando com -1)

int *busca (int v[], int length, int chave, int *aparicoes);

int main(){
	
	int *v, tamanho, chave, i;
	printf("Digite o tamanho do vetor: ");
	scanf("%d", &tamanho);
	
	v = malloc( sizeof(int) * tamanho);
	int aparicoes = 0;
	for(i = 0; i < tamanho; i++){
		printf("%d: ", i);
		scanf("%d", v + i);
	}
	printf("\nDigite a chave(valor) buscada: ");
	scanf("%d", &chave);
	int *resultadoBusca = busca(v, tamanho, chave, &aparicoes);
	
	
	if(aparicoes > 1){
		printf("\nVetor resultante:\n");
		for(i = 0; i < aparicoes;i++){
			printf("%d: %d\n", i, resultadoBusca[i]);
		}
	}else{
		printf("\nNenhuma correspondencia da chave requerida");
	}
	
	free(resultadoBusca);
	
	return 0;
}


int* busca (int v[], int length, int chave, int *aparicoes){
	int i, count = 0;
	for(i = 0; i < length; i++){
		if(v[i] == chave){
			(*aparicoes)++;
		}
	}
	(*aparicoes)++;		//isso é para incluir o -1
	int *resultado = malloc(sizeof(int) * (*aparicoes));
	for(i = 0; i < length; i++){
		if(v[i] == chave){
			resultado[count] = i;
			count++;
		}
	}
	resultado[count] = -1;
	return resultado;
}
