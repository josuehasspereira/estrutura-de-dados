#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int *p, n, i;
	printf("Quantos valores? ");
	scanf("%d", &n);
	p = malloc( sizeof(int) * n); //alocando dinamicamente
	
	for(i = 0; i < n; i++){
		printf("P[%d] = ", i);
		scanf("%d", p+i); //mesma coisa que &p[i]
	}
	
	printf("\n");
	
	for(i = 0; i < n; i++){
		printf("P[%d]: %d\n", i, *(p + i)); //ou p[i]
	}
	
	free(p);
		
	return 0;
}
