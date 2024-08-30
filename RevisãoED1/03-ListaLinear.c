#include <stdio.h>
#define MAX_SIZE 10

int lista[MAX_SIZE];
int tamanho = 0;

// Função para inserir um elemento na lista
void inserir(int elemento) {
    if (tamanho < MAX_SIZE) {
        lista[tamanho] = elemento;
        tamanho++;
    } else {
        printf("Lista cheia!\n");
    }
}

// Função para remover um elemento da lista pelo índice
void remover(int index) {
    if (index < 0 || index >= tamanho) {
        printf("Índice inválido!\n");
    } else {
        for (int i = index; i < tamanho - 1; i++) {
            lista[i] = lista[i + 1];
        }
        tamanho--;
    }
}

// Função para imprimir todos os elementos da lista
void imprimir() {
    printf("Elementos da lista: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

// Função para buscar um elemento na lista e retornar seu índice
int buscar(int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (lista[i] == elemento) {
            return i; // Retorna a posição do elemento encontrado
        }
    }
    return -1; // Retorna -1 se o elemento não for encontrado
}

// Função para inverter a lista
void inverter() {
    for (int i = 0; i < tamanho / 2; i++) {
        int temp = lista[i];
        lista[i] = lista[tamanho - 1 - i];
        lista[tamanho - 1 - i] = temp;
    }
}

// Função para encontrar o valor máximo na lista
int encontrar_maximo() {
    int max = lista[0];
    for (int i = 1; i < tamanho; i++) {
        if (lista[i] > max) {
            max = lista[i];
        }
    }
    return max;
}

// Função para encontrar o valor mínimo na lista
int encontrar_minimo() {
    int min = lista[0];
    for (int i = 1; i < tamanho; i++) {
        if (lista[i] < min) {
            min = lista[i];
        }
    }
    return min;
}

// Função para ordenar a lista em ordem crescente usando Bubble Sort
void ordenar() {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (lista[j] > lista[j + 1]) {
                int temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Inserir elementos
    inserir(30);
    inserir(10);
    inserir(20);
    printf("Após inserir elementos na lista:\n");
    imprimir();
    
    // Buscar um elemento
    printf("\nÍndice do elemento 20: %d\n", buscar(20));
    
    // Remover o primeiro elemento
    remover(0);
    printf("\nApós remoção do elemento no índice 0:\n");
    imprimir();
    
    // Inverter a lista
    inverter();
    printf("\nLista invertida:\n");
    imprimir();
    
    // Inserir mais elementos
    inserir(50);
    inserir(5);
    inserir(25);
    printf("\nApós inserir mais elementos:\n");
    imprimir();
    
    // Ordenar a lista
    ordenar();
    printf("\nLista ordenada:\n");
    imprimir();
    
    // Encontrar e imprimir máximo e mínimo
    printf("\nMáximo: %d\n", encontrar_maximo());
    printf("Mínimo: %d\n", encontrar_minimo());

    return 0;
}
