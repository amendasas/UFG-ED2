#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10  // Define o tamanho da tabela hash

// Estrutura para representar um produto
typedef struct Produto {
    int id;               // ID único do produto
    float preco;          // Preço do produto
    char nome[50];        // Nome do produto
    char disponibilidade[20]; // Status: "disponível" ou "esgotado"
    struct Produto *proximo;  // Ponteiro para o próximo produto na lista ligada (para tratamento de colisões)
} Produto;

// Estrutura da Tabela Hash
typedef struct {
    Produto *tabela[TAMANHO_HASH];  // Array de ponteiros para o início das listas ligadas
} TabelaHash;

// Função Hash: Retorna o índice na tabela baseado no ID do produto
int funcao_hash(int id) {
    return id % TAMANHO_HASH;  // Calcula o índice usando o módulo do ID pelo tamanho da tabela
}

// Função para criar um novo produto
Produto *criar_produto(int id, float preco, const char *nome, const char *disponibilidade) {
    Produto *novo_produto = (Produto *)malloc(sizeof(Produto));  // Aloca memória para o novo produto
    if (novo_produto == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);  // Sai do programa em caso de erro
    }
    novo_produto->id = id;
    novo_produto->preco = preco;
    strcpy(novo_produto->nome, nome);  
    strcpy(novo_produto->disponibilidade, disponibilidade);  
    novo_produto->proximo = NULL;
    return novo_produto;  // Retorna o ponteiro para o novo produto
}

// Função para inserir um produto na tabela hash (com tratamento de colisões usando listas ligadas)
void inserir(TabelaHash *tabela, Produto *produto) {
    int indice = funcao_hash(produto->id);  // Calcula o índice da tabela hash
    produto->proximo = tabela->tabela[indice];  // Adiciona o produto na lista ligada
    tabela->tabela[indice] = produto;
}

// Função para buscar um produto na tabela hash pelo ID
Produto *buscar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice para o ID fornecido
    Produto *atual = tabela->tabela[indice];
    
    // Percorre a lista ligada para encontrar o produto
    while (atual != NULL) {
        if (atual->id == id) {
            return atual;  // Retorna o produto encontrado
        }
        atual = atual->proximo;  // Vai para o próximo produto na lista
    }
    return NULL;  // Retorna NULL se não encontrar o produto
}

// Função para exibir todos os produtos da tabela hash
void exibir_todos(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        Produto *atual = tabela->tabela[i];
        while (atual != NULL) {
            printf("Produto ID: %d, Preço: %.2f, Nome: %s, Disponibilidade: %s\n",
                   atual->id, atual->preco, atual->nome, atual->disponibilidade);
            atual = atual->proximo;
        }
    }
}

// Função para deletar um produto pelo ID
void deletar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);
    Produto *atual = tabela->tabela[indice];
    Produto *anterior = NULL;

    while (atual != NULL) {
        if (atual->id == id) {
            if (anterior == NULL) {
                tabela->tabela[indice] = atual->proximo;  // Remove o primeiro produto da lista
            } else {
                anterior->proximo = atual->proximo;  // Remove o produto do meio ou fim da lista
            }
            free(atual);  // Libera a memória alocada
            printf("Produto com ID %d deletado com sucesso.\n", id);
            return;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    printf("Produto com ID %d não encontrado para exclusão.\n", id);
}

// Função para contar o número total de produtos na tabela hash
int contar_elementos(TabelaHash *tabela) {
    int total = 0;

    for (int i = 0; i < TAMANHO_HASH; i++) {
        Produto *atual = tabela->tabela[i];
        while (atual != NULL) {
            total++;
            atual = atual->proximo;
        }
    }
    return total;
}

// Função para inserir produtos predefinidos no e-commerce de tecnologia
void inserir_dados_predefinidos(TabelaHash *tabela) {
    inserir(tabela, criar_produto(101, 9999.99, "Placa de Vídeo NVIDIA RTX 4090", "disponível"));
    inserir(tabela, criar_produto(102, 4999.99, "Processador Intel Core i9 13900K", "esgotado"));
    inserir(tabela, criar_produto(103, 1499.99, "Mouse Gamer Logitech G Pro X", "disponível"));
    inserir(tabela, criar_produto(104, 1999.99, "Teclado Mecânico Corsair K95", "disponível"));
    inserir(tabela, criar_produto(105, 999.99, "Headset HyperX Cloud Alpha", "esgotado"));
    inserir(tabela, criar_produto(106, 7999.99, "Monitor 4K ASUS ROG Swift", "disponível"));
    inserir(tabela, criar_produto(107, 599.99, "SSD NVMe 1TB Samsung 980 Pro", "disponível"));
    inserir(tabela, criar_produto(108, 3499.99, "Gabinete NZXT H510 Elite", "esgotado"));
    inserir(tabela, criar_produto(109, 1999.99, "Fonte Corsair RM850x 850W", "disponível"));

    printf("Os produtos foram inseridos com sucesso.\n");
}

// Função principal para demonstrar o uso da tabela hash com produtos de tecnologia
int main() {
    // Inicializa a tabela hash
    TabelaHash tabela = {NULL};

    // Inserir os dados predefinidos na tabela hash
    inserir_dados_predefinidos(&tabela);

    // Exibir todos os produtos inseridos
    printf("\nTotal de produtos inseridos: %d\n\n", contar_elementos(&tabela));
    exibir_todos(&tabela);

    // Busca por um produto específico
    Produto *p = buscar(&tabela, 102);
    if (p != NULL) {
        printf("\nProduto encontrado: ID: %d, Preço: %.2f, Nome: %s, Disponibilidade: %s\n",
               p->id, p->preco, p->nome, p->disponibilidade);
    } else {
        printf("Produto não encontrado.\n");
    }

    // Deletar um produto da tabela hash
    deletar(&tabela, 102);

    // Tentar buscar o produto deletado
    p = buscar(&tabela, 102);
    if (p != NULL) {
        printf("Produto encontrado: ID: %d, Preço: %.2f, Nome: %s, Disponibilidade: %s\n",
               p->id, p->preco, p->nome, p->disponibilidade);
    } else {
        printf("\nO produto não foi encontrado após a exclusão.\n");
    }

    return 0;  // Encerra o programa
}
