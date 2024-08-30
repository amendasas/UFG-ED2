#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó para a lista duplamente ligada
typedef struct Node {
    int data;             // Dados armazenados no nó
    struct Node* next;    // Ponteiro para o próximo nó
    struct Node* prev;    // Ponteiro para o nó anterior
} Node;

Node* head = NULL; // Ponteiro para o início da lista

// Função para inserir um valor no início da lista
void insertFront(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Aloca memória para o novo nó
    newNode->data = value;                       // Atribui o valor ao nó
    newNode->next = head;                        // O próximo nó do novo nó é o antigo início da lista
    newNode->prev = NULL;                        // O novo nó não tem nó anterior
    if (head != NULL)
        head->prev = newNode;                     // Atualiza o ponteiro do antigo início para o novo nó
    head = newNode;                              // Atualiza o início da lista para o novo nó
}

// Função para deletar um nó específico da lista
void deleteNode(Node* node) {
    if (node == head)                           // Se o nó a ser removido é o início
        head = node->next;                     // Atualiza o início da lista
    if (node->next != NULL)
        node->next->prev = node->prev;         // Atualiza o ponteiro do próximo nó para o nó anterior
    if (node->prev != NULL)
        node->prev->next = node->next;         // Atualiza o ponteiro do nó anterior para o próximo nó
    free(node);                                // Libera a memória do nó
}

// Função para imprimir todos os elementos da lista
void printList() {
    Node* temp = head; // Inicia no início da lista
    while (temp != NULL) {  // Percorre a lista até o fim
        printf("%d ", temp->data);  // Imprime o dado do nó
        temp = temp->next;         // Move para o próximo nó
    }
    printf("\n"); // Quebra de linha após a impressão da lista
}

// Função para buscar um valor na lista e exibir detalhes dos vizinhos
void searchValue(int value) {
    Node* temp = head; // Inicia no início da lista
    while (temp != NULL) {  // Percorre a lista até o fim
        if (temp->data == value) {  // Verifica se o valor do nó é igual ao valor procurado
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
            return;  // Sai da função após encontrar o valor
        }
        temp = temp->next; // Move para o próximo nó
    }
    printf("Valor %d não encontrado.\n", value); // Mensagem se o valor não for encontrado
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
