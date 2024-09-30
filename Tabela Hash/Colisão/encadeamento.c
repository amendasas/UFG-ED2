#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10

// Estrutura para representar um produto
typedef struct Produto {
    int id;               // ID único do produto
    float preco;          // Preço do produto
    char nome[50];        // Nome do produto
    char disponibilidade[20]; // Status: "disponível" ou "esgotado"
    struct Produto *proximo;  // Ponteiro para o próximo produto (lista ligada)
} Produto;

// Estrutura da Tabela Hash
typedef struct {
    Produto *tabela[TAMANHO_HASH];  // Array de ponteiros para o início da lista ligada
} TabelaHash;

// Função Hash: Retorna o índice baseado no ID do produto
int funcao_hash(int id) {
    return id % TAMANHO_HASH;  // Usa módulo para determinar a posição na tabela
}

// Função para criar um novo produto
Produto *criar_produto(int id, float preco, const char *nome, const char *disponibilidade) {
    Produto *novo_produto = (Produto *)malloc(sizeof(Produto));
    if (novo_produto == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    novo_produto->id = id;
    novo_produto->preco = preco;
    strcpy(novo_produto->nome, nome);
    strcpy(novo_produto->disponibilidade, disponibilidade);
    novo_produto->proximo = NULL;
    return novo_produto;
}

// Função para inserir um produto na tabela hash (usando listas ligadas para colisões)
void inserir(TabelaHash *tabela, Produto *produto) {
    int indice = funcao_hash(produto->id);  // Calcula o índice baseado no ID
    produto->proximo = tabela->tabela[indice];  // Insere no início da lista ligada
    tabela->tabela[indice] = produto;
}

// Função para buscar um produto na tabela hash pelo ID
Produto *buscar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice para busca
    Produto *atual = tabela->tabela[indice];
    
    while (atual != NULL) {
        if (atual->id == id) {
            return atual;  // Retorna o produto se encontrado
        }
        atual = atual->proximo;  // Vai para o próximo produto na lista ligada
    }
    return NULL;  // Retorna NULL se não for encontrado
}

// Função para exibir todos os produtos esgotados
void exibir_esgotados(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        Produto *atual = tabela->tabela[i];
        while (atual != NULL) {
            if (strcmp(atual->disponibilidade, "esgotado") == 0) {
                printf("Produto ID: %d, Preço: %.2f, Nome: %s, Disponibilidade: %s\n",
                       atual->id, atual->preco, atual->nome, atual->disponibilidade);
            }
            atual = atual->proximo;  // Vai para o próximo produto
        }
    }
}

// Função para deletar um produto da tabela hash
void deletar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice do produto a ser deletado
    Produto *atual = tabela->tabela[indice];
    Produto *anterior = NULL;

    while (atual != NULL) {
        if (atual->id == id) {
            // Se o produto a ser removido for o primeiro da lista
            if (anterior == NULL) {
                tabela->tabela[indice] = atual->proximo;  // Remove o primeiro elemento
            } else {
                anterior->proximo = atual->proximo;  // Remove o elemento no meio ou fim
            }
            free(atual);  // Libera a memória do produto
            printf("Produto com ID %d deletado com sucesso.\n", id);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Produto com ID %d não encontrado.\n", id);
}

// Função principal para demonstrar o uso da tabela hash com produtos de um e-commerce
int main() {
    // Inicializa a tabela hash
    TabelaHash tabela = {NULL};

    // Criação de alguns produtos
    Produto *produto1 = criar_produto(101, 1000.50, "Smartphone", "disponível");
    Produto *produto2 = criar_produto(102, 250.75, "Fone de Ouvido", "esgotado");
    Produto *produto3 = criar_produto(103, 500.00, "Smartwatch", "disponível");

    // Insere os produtos na tabela hash
    inserir(&tabela, produto1);
    inserir(&tabela, produto2);
    inserir(&tabela, produto3);

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
