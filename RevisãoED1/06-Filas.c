#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó na fila
typedef struct Node {
    int data;           // Dados armazenados no nó
    struct Node* next;  // Ponteiro para o próximo nó
} Node;

// Estrutura da fila
typedef struct Queue {
    Node* front;        // Ponteiro para o início da fila
    Node* rear;         // Ponteiro para o fim da fila
} Queue;

// Função para criar uma nova fila
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue)); // Aloca memória para a fila
    if (q == NULL) {
        printf("Falha na alocação de memória para a fila.\n");
        return NULL; // Retorna NULL se não conseguir alocar memória
    }
    q->front = q->rear = NULL; // Inicializa os ponteiros front e rear como NULL
    return q; // Retorna a fila criada
}

// Função para adicionar um elemento ao final da fila
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Aloca memória para o novo nó
    if (newNode == NULL) {
        printf("Falha na alocação de memória para o novo nó.\n");
        return; // Retorna se não conseguir alocar memória
    }
    newNode->data = value; // Define o valor do nó
    newNode->next = NULL;  // O novo nó não aponta para nenhum próximo nó
    if (q->rear == NULL) { // Se a fila estiver vazia
        q->front = q->rear = newNode; // O novo nó é o início e o fim da fila
    } else { 
        q->rear->next = newNode; // O antigo fim aponta para o novo nó
        q->rear = newNode;       // Atualiza o fim da fila para o novo nó
    }
}

// Função para remover um elemento do início da fila
int dequeue(Queue* q) {
    if (q->front == NULL) { // Se a fila estiver vazia
        printf("Fila está vazia.\n");
        return -1; // Retorna -1 como indicador de erro
    }
    Node* temp = q->front; // Armazena o nó do início da fila
    int data = temp->data; // Obtém o dado do nó
    q->front = q->front->next; // Move o início da fila para o próximo nó
    if (q->front == NULL) { // Se a fila ficar vazia após a remoção
        q->rear = NULL; // Atualiza o fim da fila para NULL
    }
    free(temp); // Libera a memória do nó removido
    return data; // Retorna o dado do nó removido
}

// Função para verificar se a fila está vazia
int isEmpty(Queue* q) {
    return q->front == NULL; // Retorna 1 se a fila estiver vazia, 0 caso contrário
}

// Função para imprimir todos os elementos da fila
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("A fila está vazia.\n");
        return;
    }
    Node* temp = q->front; // Inicia do início da fila
    printf("Elementos da fila: ");
    while (temp != NULL) { // Percorre a fila até o fim
        printf("%d ", temp->data); // Imprime o dado do nó
        temp = temp->next; // Move para o próximo nó
    }
    printf("\n");
}

// Função para contar o número de elementos na fila
int countElements(Queue* q) {
    int count = 0; // Inicializa o contador
    Node* temp = q->front; // Inicia do início da fila
    while (temp != NULL) { // Percorre a fila até o fim
        count++; // Incrementa o contador
        temp = temp->next; // Move para o próximo nó
    }
    return count; // Retorna o número de elementos
}

// Função para limpar todos os elementos da fila e liberar memória
void clearQueue(Queue* q) {
    Node* temp;
    while (q->front != NULL) { // Enquanto houver elementos na fila
        temp = q->front; // Armazena o início da fila
        q->front = q->front->next; // Move o início da fila para o próximo nó
        free(temp); // Libera a memória do nó
    }
    q->rear = NULL; // Atualiza o fim da fila para NULL
    free(q); // Libera a memória da estrutura da fila
}

int main() {
    Queue* q = createQueue(); // Cria uma nova fila
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
