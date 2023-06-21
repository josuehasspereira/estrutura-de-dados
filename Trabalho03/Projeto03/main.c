#include <stdio.h>
#include <stdlib.h>
#include "UniaoBusca.h"

void componentes_conexos(int size, int mat[size][size]) {
    UniaoBusca conjunto;
    inicializa_conjunto(&conjunto);
    int i, j;

    for (i = 0; i < size; i++) {
        int x = i + 1;
        cria_conjunto(&conjunto, &x);
    }

    for (i = 0; i < size; i++) {
        int x = i + 1;

        for (j = 0; j < size; j++) {
            int y = j + 1;

            if (mat[i][j] && busca_conjunto(&conjunto, &x) != busca_conjunto(&conjunto, &y)) {
                unir_conjuntos(&conjunto, &x, &y);
            }
        }
    }

    mostra_todos_conjuntos(conjunto);
    desaloca_conjunto(&conjunto);
}

int main(int argc, char *argv[]) {
    FILE *entrada = fopen("matriz.txt", "r");
    int size, i, j, t;

    fscanf(entrada, "%d", &t);

    while (t--) {
        fscanf(entrada, "%d", &size);
        int m[size][size];

        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                fscanf(entrada, "%d", &m[i][j]);
            }
        }

        componentes_conexos(size, m);
        system("PAUSE");
    }

    fclose(entrada);
    return 0;
}
