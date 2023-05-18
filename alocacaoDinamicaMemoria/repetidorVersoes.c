#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *repetidor_v1(char *s, int n);
char *repetidor_v2(char *s, int n);
char *repetidor_v3(char *s, int n);

int main(){
	
	char str[30];
	printf("Digite uma string: ");
	scanf("%[^\n]", str);
	int n;
	printf("Digite o numero de vezes que a string vai se repetir: ");
	scanf("%d", &n);
	
	char *nova = repetidor_v3(str, n); 
	
	printf("'%s'\n", nova);
	free(nova);
		
	return 0;
}

char *repetidor_v1(char *s, int n){
	int cap = strlen(s) * n + 1;
	char *p = malloc(cap);
	p[0] = '\0';
	int i;
	for(i = 0; i < n; i++){
		strcat(p, s);
	}
	return p;
}

char *repetidor_v2(char *s, int n){
	int t = strlen(s);
	int cap = t * n + 1;
	char *p = malloc(cap);
	
	int i;
	for(i = 0; i < n; i++){
		strcpy(p + i*t, s); //Aritmética de ponteiros!
	}
	//diferente do strconcat, strcopy faz uma cópia, substituindo. Como queremos concatenar
	//se faz a aritmética de ponteiros para substituir os espaços vazios da string destino, não os já ocupados.
	return p;
}
char *repetidor_v3(char *s, int n){
	int t;
	for(t = 0; s[t] != '\0'; t++); //Faz o mesmo que o strlen()
	
	int cap = t * n + 1;
	char *p = malloc(cap);
	
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0; j < t; j++){
			p[j + i*t] = s[j];
		}
	}
	p[cap - 1] = '\0';
	
	return p;
}
