#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatena(char *str, char *str2);

int main(){
	
	char str[30], str2[30];
	printf("Digite a primeira palavra: ");
	scanf("%[^\n]", str);					//%[^\n] recebe qualquer coisa menos o \n, ^ é negação na expressão regular
	getchar();	
	printf("Digite a segunda palavra: ");
	scanf("%[^\n]", str2);
	
	char *resultante = concatena(str, str2);
	printf("%s", resultante);
	
	free(resultante);
	
	return 0;
}

char *concatena(char *str, char *str2){
	int n = strlen(str) + strlen(str2);
	char *novaString = malloc( n );
	novaString = strcat(str, str2);
	
	return novaString;
}

