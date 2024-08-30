#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 3 // Tamanho inicial da pilha

int* pilha;          // Ponteiro para a pilha
int tamanho = INITIAL_SIZE; // Tamanho atual da pilha
int topo = -1;      // Índice do topo da pilha

// Função para verificar se a pilha está vazia
int esta_vazia() {
    return topo == -1;
}

// Função para expandir dinamicamente a pilha quando a capacidade máxima é atingida
void expandir_pilha() {
    tamanho *= 2;  // Dobra o tamanho da pilha
    pilha = realloc(pilha, tamanho * sizeof(int));  // Realoca a memória
    if (pilha == NULL) {
        printf("Falha ao realocar memória!\n");
        exit(1);
    }
}

// Função para inserir um elemento na pilha
void push(int elemento) {
    // Verifica se a pilha está cheia e expande se necessário
    if (topo == tamanho - 1) {
        expandir_pilha();
    }
    pilha[++topo] = elemento;
}

// Função para remover um elemento do topo da pilha
int pop() {
    if (esta_vazia()) {
        printf("Pilha vazia!\n");
        return -1; // Retorna um valor indicador de erro
    } else {
        return pilha[topo--]; // Retorna o elemento do topo e decrementa o topo
    }
}

// Função para obter o elemento do topo da pilha sem removê-lo
int top() {
    if (esta_vazia()) {
        printf("Pilha vazia!\n");
        return -1; // Retorna um valor indicador de erro
    } else {
        return pilha[topo]; // Retorna o elemento do topo
    }
}

// Função para imprimir todos os elementos da pilha
void imprimir() {
    printf("\nConteúdo da pilha: ");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]); // Imprime cada elemento do topo para a base
    }
    printf("\n");
}

int main() {
    pilha = malloc(INITIAL_SIZE * sizeof(int)); // Aloca memória inicial para a pilha
    if (pilha == NULL) {
        printf("Falha ao alocar memória!\n");
        return 1;
    }

    push(10); // Adiciona elementos à pilha
    push(20);
    push(30);
    imprimir(); // Imprime o conteúdo da pilha

    printf("\nElemento no topo: %d\n", top()); // Mostra o elemento do topo

    printf("\nElemento removido: %d\n", pop()); // Remove e mostra o elemento do topo
    imprimir(); // Imprime o conteúdo da pilha após remoção

    free(pilha); // Libera a memória alocada para a pilha
    return 0;
}
