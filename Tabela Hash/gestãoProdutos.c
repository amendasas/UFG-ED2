#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10

// Estrutura para representar um produto (transação financeira no exemplo anterior)
typedef struct {
    int id;               // ID único do produto
    float preco;          // Preço do produto
    char nome[50];        // Nome do produto
    char disponibilidade[20]; // Status: "disponível" ou "esgotado"
} Produto;

// Estrutura da Tabela Hash
typedef struct {
    Produto *tabela[TAMANHO_HASH];  // Array de ponteiros para armazenar produtos
} TabelaHash;

// Função Hash: Retorna o índice baseado no ID do produto
int funcao_hash(int id) {
    return id % TAMANHO_HASH;  // Usa módulo para determinar a posição na tabela
}

// Função para inserir um produto na tabela hash
void inserir(TabelaHash *tabela, Produto *produto) {
    int indice = funcao_hash(produto->id);  // Calcula o índice baseado no ID
    tabela->tabela[indice] = produto;  // Insere o produto na tabela
}

// Função para buscar um produto na tabela hash pelo ID
Produto *buscar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice para busca
    return tabela->tabela[indice];  // Retorna o produto encontrado
}

// Função para exibir produtos esgotados
void exibir_esgotados(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        if (tabela->tabela[i] != NULL && strcmp(tabela->tabela[i]->disponibilidade, "esgotado") == 0) {
            printf("Produto ID: %d, Preço: %.2f, Nome: %s, Disponibilidade: %s\n",
                   tabela->tabela[i]->id,
                   tabela->tabela[i]->preco,
                   tabela->tabela[i]->nome,
                   tabela->tabela[i]->disponibilidade);
        }
    }
}

// Função para deletar um produto da tabela hash
void deletar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice do produto a ser deletado
    if (tabela->tabela[indice] != NULL && tabela->tabela[indice]->id == id) {
        tabela->tabela[indice] = NULL;  // Remove o produto da tabela
        printf("Produto ID %d deletado com sucesso.\n", id);
    } else {
        printf("Produto com ID %d não encontrado.\n", id);
    }
}

// Função principal para demonstrar o uso da tabela hash com produtos de um e-commerce
int main() {
    // Inicializa a tabela hash
    TabelaHash tabela = {NULL};

    // Criação de alguns produtos
    Produto produto1 = {101, 1000.50, "Smartphone", "disponível"};
    Produto produto2 = {102, 250.75, "Fone de Ouvido", "esgotado"};
    Produto produto3 = {103, 500.00, "Smartwatch", "disponível"};

    // Insere os produtos na tabela hash
    inserir(&tabela, &produto1);
    inserir(&tabela, &produto2);
    inserir(&tabela, &produto3);

    // Busca por um produto específico
    Produto *p = buscar(&tabela, 102);
    if (p != NULL) {
        printf("Produto encontrado: ID: %d, Preço: %.2f, Nome: %s, Disponibilidade: %s\n",
               p->id, p->preco, p->nome, p->disponibilidade);
    } else {
        printf("Produto não encontrado.\n");
    }

    // Exibir todos os produtos esgotados
    printf("\nProdutos esgotados:\n");
    exibir_esgotados(&tabela);

    // Deletar um produto da tabela hash
    deletar(&tabela, 102);

    // Tentar buscar o produto deletado
    p = buscar(&tabela, 102);
    if (p != NULL) {
        printf("Produto encontrado: ID: %d, Preço: %.2f, Nome: %s, Disponibilidade: %s\n",
               p->id, p->preco, p->nome, p->disponibilidade);
    } else {
        printf("Produto não encontrado após deleção.\n");
    }

    return 0;
}
