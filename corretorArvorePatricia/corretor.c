#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do nó da Árvore Patricia
typedef struct PatriciaNode {
    char *key;                     // Chave armazenada (palavra ou parte dela)
    int isEndOfWord;               // Indica se é o final de uma palavra
    struct PatriciaNode *left;     // Filhos para prefixos diferentes
    struct PatriciaNode *right;    // Filhos para prefixos iguais
} PatriciaNode;

// Função para criar um novo nó
PatriciaNode* createNode(const char *key, int isEndOfWord) {
    PatriciaNode *node = (PatriciaNode *)malloc(sizeof(PatriciaNode));
    node->key = strdup(key); // Copia a chave
    node->isEndOfWord = isEndOfWord;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Função para encontrar o primeiro índice onde duas strings divergem
int findMismatchIndex(const char *str1, const char *str2) {
    int i = 0;
    while (str1[i] && str2[i] && str1[i] == str2[i]) {
        i++;
    }
    return i;
}

// Função para inserir uma palavra na Árvore Patricia
PatriciaNode* insertPatricia(PatriciaNode *root, const char *word) {
    if (!root) {
        return createNode(word, 1); // Novo nó para palavra
    }

    int mismatchIndex = findMismatchIndex(root->key, word);

    // Caso 1: A palavra é um prefixo do nó atual
    if (mismatchIndex == strlen(root->key)) {
        if (mismatchIndex == strlen(word)) {
            // Palavra já existe
            root->isEndOfWord = 1;
        } else {
            // Inserir a parte restante na subárvore direita
            root->right = insertPatricia(root->right, word + mismatchIndex);
        }
        return root;
    }

    // Caso 2: O nó atual é um prefixo da palavra
    if (mismatchIndex == strlen(word)) {
        PatriciaNode *newNode = createNode(word, 1);
        newNode->right = root;
        return newNode;
    }

    // Caso 3: Há um ponto de divergência
    PatriciaNode *splitNode = createNode(root->key + mismatchIndex, root->isEndOfWord);
    splitNode->left = root->left;
    splitNode->right = root->right;

    root->key[mismatchIndex] = '\0'; // Divide a chave do nó atual
    root->isEndOfWord = 0;
    root->left = splitNode;
    root->right = createNode(word + mismatchIndex, 1);

    return root;
}

// Função para buscar uma palavra na Árvore Patricia
int searchPatricia(PatriciaNode *root, const char *word) {
    if (!root) {
        return 0; // Palavra não encontrada
    }

    int mismatchIndex = findMismatchIndex(root->key, word);

    // Palavra é prefixo do nó atual
    if (mismatchIndex == strlen(word) && mismatchIndex <= strlen(root->key)) {
        return root->isEndOfWord;
    }

    // Ir para a subárvore direita
    if (mismatchIndex == strlen(root->key)) {
        return searchPatricia(root->right, word + mismatchIndex);
    }

    return 0; // Palavra não encontrada
}

// Função para exibir todas as palavras na Árvore Patricia
void printPatricia(PatriciaNode *root, char *buffer, int depth) {
    if (!root) {
        return;
    }

    strncpy(buffer + depth, root->key, strlen(root->key));
    depth += strlen(root->key);

    if (root->isEndOfWord) {
        buffer[depth] = '\0';
        printf("%s\n", buffer);
    }

    printPatricia(root->left, buffer, depth);
    printPatricia(root->right, buffer, depth);
}

// Função para sugerir palavras com base em um prefixo
void suggestWords(PatriciaNode *root, const char *prefix, char *buffer, int depth) {
    if (!root) return;

    int mismatchIndex = findMismatchIndex(root->key, prefix);

    if (mismatchIndex == strlen(prefix)) {
        strncpy(buffer + depth, root->key, strlen(root->key));
        depth += strlen(root->key);
        printPatricia(root, buffer, depth);
        return;
    }

    if (mismatchIndex == strlen(root->key)) {
        suggestWords(root->right, prefix + mismatchIndex, buffer, depth + mismatchIndex);
    }
}

// Função para carregar o dicionário a partir de um arquivo
void loadDictionary(PatriciaNode **root, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char word[100];
    while (fscanf(file, "%99s", word) == 1) {
        *root = insertPatricia(*root, word);
    }

    fclose(file);
}

// Menu interativo
int main() {
    PatriciaNode *root = NULL;
    char buffer[100];
    char word[100], prefix[100];
    int choice;

    loadDictionary(&root, "dicionario.txt");

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Inserir palavra\n");
        printf("2. Buscar palavra\n");
        printf("3. Autocompletar palavras\n");
        printf("4. Exibir todas as palavras\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Digite a palavra para inserir: ");
                scanf("%s", word);
                root = insertPatricia(root, word);
                printf("Palavra '%s' inserida!\n", word);
                break;
            case 2:
                printf("Digite a palavra para buscar: ");
                scanf("%s", word);
                printf("Busca por '%s': %s\n", word, searchPatricia(root, word) ? "Encontrada" : "Não encontrada");
                break;
            case 3:
                printf("Digite o prefixo para autocompletar: ");
                scanf("%s", prefix);
                printf("Sugestões para '%s':\n", prefix);
                suggestWords(root, prefix, buffer, 0);
                break;
            case 4:
                printf("Palavras na árvore:\n");
                printPatricia(root, buffer, 0);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (choice != 0);

    return 0;
}
