#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 3

int* pilha;          
int tamanho = INITIAL_SIZE;
int topo = -1; 

// Função para verificar se a pilha está vazia
int esta_vazia() {
    return topo == -1;
}

// Função para expandir dinamicamente a pilha quando a capacidade máxima é atingida
void expandir_pilha() {
    tamanho *= 2;  
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
        return -1;
    } else {
        return pilha[topo--]; 
    }
}

// Função para obter o elemento do topo da pilha sem removê-lo
int top() {
    if (esta_vazia()) {
        printf("Pilha vazia!\n");
        return -1; 
    } else {
        return pilha[topo];
    }
}

// Função para imprimir todos os elementos da pilha
void imprimir() {
    printf("\nConteúdo da pilha: ");
    for (int i = topo; i >= 0; i--) {
        printf("%d ", pilha[i]); 
    }
    printf("\n");
}

int main() {
    pilha = malloc(INITIAL_SIZE * sizeof(int)); 
    if (pilha == NULL) {
        printf("Falha ao alocar memória!\n");
        return 1;
    }

    // Adiciona elementos à pilha
    push(10);
    push(20);
    push(30);
    // Imprime o conteúdo da pilha
    imprimir();

    // Mostra o elemento do topo
    printf("\nElemento no topo: %d\n", top());

    // Remove e mostra o elemento do topo
    printf("\nElemento removido: %d\n", pop());
    // Imprime o conteúdo da pilha após remoção
    imprimir();

    // Libera a memória alocada para a pilha
    free(pilha);
    return 0;
}
