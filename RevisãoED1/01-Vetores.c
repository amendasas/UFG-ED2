#include <stdio.h>

int main() {
    int i, n, temp;

    // Solicita ao usuário o tamanho do vetor e armazena na variável 'n'
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &n);
    
    // Declara um vetor de tamanho 'n'
    int vetor[n];
    
    // Solicita ao usuário para inserir os elementos do vetor
    printf("\nInsira os elementos do vetor: ");
    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]); // Armazena cada elemento no vetor
    }
    
    // Loop para inverter o vetor. Percorre metade do vetor.
    for (i = 0; i < n/2; i++){
        // Troca o elemento atual (vetor[i]) com o elemento correspondente do final (vetor[n - 1 - i])
        temp = vetor[i];
        vetor[i] = vetor[n - 1 - i];
        vetor[n - 1 - i] = temp;
    }
   
    // Imprime o vetor na ordem invertida
    printf("Vetor invertido:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]); // Exibe cada elemento do vetor invertido
    }

    return 0;
}
