#include <stdio.h>
#include <stdlib.h>  // Necessário para usar malloc

int main() {
    int n, i, j, soma = 0;
    int **matriz;

    // Solicita ao usuário o tamanho da matriz (n x n)
    printf("Insira o tamanho da matriz (n x n): ");
    scanf("%d", &n);

    // Alocação dinâmica de memória para a matriz 2D
    matriz = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++) {
        matriz[i] = (int *)malloc(n * sizeof(int));
    }

    // Solicita ao usuário para inserir os elementos da matriz
    printf("Insira os elementos da matriz %dx%d:\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matriz[i][j]);
            if (i == j) {
                soma += matriz[i][j];  // Soma os elementos da diagonal principal
            }
        }
    }

    // Exibe a soma da diagonal principal
    printf("Soma dos elementos da diagonal principal: %d\n", soma);

    // Liberação da memória alocada dinamicamente
    for (i = 0; i < n; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
