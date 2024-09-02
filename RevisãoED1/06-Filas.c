#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó na fila
typedef struct Node {
    int data;           
    struct Node* next;  
} Node;

// Estrutura da fila
typedef struct Queue {
    Node* front;        
    Node* rear;         
} Queue;

// Função para criar uma nova fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue)); 
    if (q == NULL) {
        printf("Falha na alocação de memória para a fila.\n");
        return NULL; 
    }
    q->front = q->rear = NULL; 
    return q; 
}

// Função para adicionar um elemento ao final da fila
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (newNode == NULL) {
        printf("Falha na alocação de memória para o novo nó.\n");
        return;
    }
    newNode->data = value; 
    newNode->next = NULL;  
    if (q->rear == NULL) { 
        q->front = q->rear = newNode;
    } else { 
        q->rear->next = newNode; 
        q->rear = newNode; 
    }
}

// Função para remover um elemento do início da fila
int dequeue(Queue* q) {
    if (q->front == NULL) { 
        printf("Fila está vazia.\n");
        return -1; 
    }
    Node* temp = q->front; 
    int data = temp->data; 
    q->front = q->front->next;
    if (q->front == NULL) { 
        q->rear = NULL; 
    }
    free(temp); 
    return data;
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL; 
}

// Função para imprimir todos os elementos da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front; 
    printf("Elementos da fila: ");
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next;
    }
    printf("\n");
}

// Função para contar o número de elementos na fila
int countElements(Queue* q) {
    int count = 0; 
    Node* temp = q->front; 
    while (temp != NULL) { 
        count++; 
        temp = temp->next; 
    }
    return count; 
}

// Função para limpar todos os elementos da fila e liberar memória
void clearQueue(Queue* q) {
    Node* temp;
    while (q->front != NULL) { 
        temp = q->front; 
        q->front = q->front->next; 
        free(temp); 
    }
    q->rear = NULL; 
    free(q); 
}

int main() {
    Queue* q = createQueue(); 
    enqueue(q, 10); // Adiciona elementos à fila
    enqueue(q, 20);
    enqueue(q, 30);
    printQueue(q); // Imprime o conteúdo da fila

    printf("Número de elementos na fila: %d\n", countElements(q)); // Conta e exibe o número de elementos

    printf("Desenfileirado: %d\n", dequeue(q)); // Remove e mostra o elemento do início
    printQueue(q); // Imprime o conteúdo da fila após remoção

    printf("Número de elementos na fila: %d\n", countElements(q)); // Conta e exibe o número de elementos

    clearQueue(q); // Limpa todos os elementos da fila e libera memória
    return 0;
}
