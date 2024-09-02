#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó para a lista duplamente ligada
typedef struct Node {
    int data;         
    struct Node* next;  
    struct Node* prev;    
} Node;

Node* head = NULL; 

// Função para inserir um valor no início da lista
void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;         
    newNode->next = head;            
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

// Função para deletar um nó específico da lista
void deleteNode(Node* node) {
    if (node == head)                          
        head = node->next;                     
    if (node->next != NULL)
        node->next->prev = node->prev;         
    if (node->prev != NULL)
        node->prev->next = node->next;         
    free(node);                                
}

// Função para imprimir todos os elementos da lista
void printList() {
    Node* temp = head; 
    while (temp != NULL) {  
        printf("%d ", temp->data); 
        temp = temp->next;
    }
    printf("\n");
}

// Função para buscar um valor na lista e exibir detalhes dos vizinhos
void searchValue(int value) {
    Node* temp = head; 
    while (temp != NULL) {  
        if (temp->data == value) { 
            printf("Valor %d encontrado!\n", value);
            printf("Detalhes do nó:\n");
            printf("Valor: %d\n", temp->data);
            if (temp->prev != NULL)
                printf("Vizinho anterior: %d\n", temp->prev->data);  // Exibe o valor do nó anterior, se existir
            else
                printf("Nenhum vizinho anterior.\n");
            if (temp->next != NULL)
                printf("Vizinho próximo: %d\n", temp->next->data);  // Exibe o valor do próximo nó, se existir
            else
                printf("Nenhum vizinho próximo.\n");
            return;
        }
        temp = temp->next; 
    }
    printf("Valor %d não encontrado.\n", value);
}



int main() {
    int choice, value;

    while (1) {
        // Menu de opções
        printf("Escolha uma opção:\n");
        printf("1. Inserir valor na lista\n");
        printf("2. Buscar valor na lista\n");
        printf("3. Imprimir lista\n");
        printf("4. Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Inserir valor na lista
                printf("Digite o valor para inserir: ");
                scanf("%d", &value);
                insertFront(value);
                break;
            case 2:
                // Buscar valor na lista
                printf("Digite o valor para buscar: ");
                scanf("%d", &value);
                searchValue(value);
                break;
            case 3:
                // Imprimir lista
                printf("\nLista atual:");
                printList();
                break;
            case 4:
                // Sair do programa
                printf("Saindo...\n");
                exit(0);
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    }

    return 0;
}
