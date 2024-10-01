#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_HASH 10

// Estrutura para representar um produto
typedef struct {
    int id;               // ID único do produto
    float preco;          // Preço do produto
    char nome[50];        // Nome do produto
    char disponibilidade[20]; // Status: "disponível" ou "esgotado"
    int ocupada;          // Flag para indicar se o slot está ocupado
} Produto;

// Estrutura da Tabela Hash
typedef struct {
    Produto tabela[TAMANHO_HASH];  // Array de produtos
} TabelaHash;

// Função Hash: Retorna o índice baseado no ID do produto
int funcao_hash(int id) {
    return id % TAMANHO_HASH;  // Usa módulo para determinar a posição na tabela
}

// Função hash para duplo hashing
int hash2(int id) {
    return 7 - (id % 7);  // Segunda função hash para duplo hashing
}

// Sondagem linear
int sondagem_linear(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);
    int tentativas = 0;

    while (tabela->tabela[indice].ocupada && tentativas < TAMANHO_HASH) {
        indice = (indice + 1) % TAMANHO_HASH;
        tentativas++;
    }

    return (tentativas < TAMANHO_HASH) ? indice : -1; 
}

// Sondagem quadrática
int sondagem_quadratica(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);
    int i = 1;
    int tentativas = 0;

    while (tabela->tabela[indice].ocupada && tentativas < TAMANHO_HASH) {
        indice = (funcao_hash(id) + i * i) % TAMANHO_HASH;  // Avança quadraticamente
        i++;
        tentativas++;
    }

    return (tentativas < TAMANHO_HASH) ? indice : -1;  // Retorna o índice ou -1 se a tabela estiver cheia
}

// Duplo hashing
int duplo_hashing(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);
    int step = hash2(id);
    int tentativas = 0;

    while (tabela->tabela[indice].ocupada && tentativas < TAMANHO_HASH) {
        indice = (indice + step) % TAMANHO_HASH;  // Usa duplo hashing
        tentativas++;
    }

    return (tentativas < TAMANHO_HASH) ? indice : -1;  // Retorna o índice ou -1 se a tabela estiver cheia
}

// Função para criar um novo produto
Produto criar_produto(int id, float preco, const char *nome, const char *disponibilidade) {
    Produto novo_produto;
    novo_produto.id = id;
    novo_produto.preco = preco;
    strcpy(novo_produto.nome, nome);
    strcpy(novo_produto.disponibilidade, disponibilidade);
    novo_produto.ocupada = 1;  // Marca o slot como ocupado
    return novo_produto;
}

// Função para inserir um produto na tabela hash usando sondagem linear
void inserir_linear(TabelaHash *tabela, Produto produto) {
    int indice = funcao_hash(produto.id);

    // Se não houver colisão, insere diretamente
    if (!tabela->tabela[indice].ocupada) {
        tabela->tabela[indice] = produto;
    } else {
        // Se houver colisão, chama a sondagem linear
        int novo_indice = sondagem_linear(tabela, produto.id);
        if (novo_indice != -1) {
            tabela->tabela[novo_indice] = produto;
        } else {
            printf("Erro: Tabela hash está cheia.\n");
        }
    }
}

// Função para inserir um produto na tabela hash usando sondagem quadrática
void inserir_quadratica(TabelaHash *tabela, Produto produto) {
    int indice = funcao_hash(produto.id);

    // Se não houver colisão, insere diretamente
    if (!tabela->tabela[indice].ocupada) {
        tabela->tabela[indice] = produto;
    } else {
        // Se houver colisão, chama a sondagem quadrática
        int novo_indice = sondagem_quadratica(tabela, produto.id);
        if (novo_indice != -1) {
            tabela->tabela[novo_indice] = produto;
        } else {
            printf("Erro: Tabela hash está cheia.\n");
        }
    }
}

// Função para inserir um produto na tabela hash usando duplo hashing
void inserir_duplo_hashing(TabelaHash *tabela, Produto produto) {
    int indice = funcao_hash(produto.id);

    // Se não houver colisão, insere diretamente
    if (!tabela->tabela[indice].ocupada) {
        tabela->tabela[indice] = produto;
    } else {
        // Se houver colisão, chama o duplo hashing
        int novo_indice = duplo_hashing(tabela, produto.id);
        if (novo_indice != -1) {
            tabela->tabela[novo_indice] = produto;
        } else {
            printf("Erro: Tabela hash está cheia.\n");
        }
    }
}

// Função para exibir todos os produtos
void exibir_todos(TabelaHash *tabela) {
    for (int i = 0; i < TAMANHO_HASH; i++) {
        if (tabela->tabela[i].ocupada) {
            printf("Produto ID: %d, Preço: %.2f, Nome: %s, Disponibilidade: %s (Índice: %d)\n",
                   tabela->tabela[i].id, tabela->tabela[i].preco, tabela->tabela[i].nome, tabela->tabela[i].disponibilidade, i);
        }
    }
}


// Função para buscar um produto na tabela hash
Produto *buscar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice inicial baseado na função hash
    int tentativas = 0;

    // Continua procurando até encontrar o produto ou até esgotar as tentativas
    while (tabela->tabela[indice].ocupada && tentativas < TAMANHO_HASH) {
        if (tabela->tabela[indice].id == id) {
            return &tabela->tabela[indice];  // Produto encontrado
        }
        indice = (indice + 1) % TAMANHO_HASH;  // Avança para o próximo índice (sondagem linear)
        tentativas++;
    }

    return NULL;  // Produto não encontrado
}

// Função para deletar um produto da tabela hash
void deletar(TabelaHash *tabela, int id) {
    int indice = funcao_hash(id);  // Calcula o índice inicial baseado na função hash
    int tentativas = 0;

    // Continua procurando o produto até esgotar as tentativas
    while (tabela->tabela[indice].ocupada && tentativas < TAMANHO_HASH) {
        if (tabela->tabela[indice].id == id) {
            tabela->tabela[indice].ocupada = 0;  // Marca o slot como desocupado
            printf("Produto com ID %d removido.\n", id);
            return;
        }
        indice = (indice + 1) % TAMANHO_HASH;  // Avança para o próximo índice (sondagem linear)
        tentativas++;
    }

    printf("Erro: Produto com ID %d não encontrado.\n", id);  // Produto não encontrado para exclusão
}


// Função principal para demonstrar o uso da tabela hash com sondagem
int main() {
    // Inicializa a tabela hash
    TabelaHash tabela_linear = {0};  // Todos os slots começam desocupados

    // Inserir produtos na tabela hash usando sondagem linear
    printf("\nInserção com Sondagem Linear:\n");
    inserir_linear(&tabela_linear, criar_produto(101, 9999.99, "Placa de Vídeo NVIDIA RTX 4090", "disponível"));
    inserir_linear(&tabela_linear, criar_produto(102, 4999.99, "Processador Intel Core i9 13900K", "esgotado"));
    inserir_linear(&tabela_linear, criar_produto(103, 1499.99, "Mouse Gamer Logitech G Pro X", "disponível"));

    exibir_todos(&tabela_linear);

    // Inserir produtos na tabela hash usando sondagem quadrática
    printf("\nInserção com Sondagem Quadrática:\n");
    TabelaHash tabela_quadratica = {0};
    inserir_quadratica(&tabela_quadratica, criar_produto(104, 1999.99, "Teclado Mecânico Corsair K95", "disponível"));
    inserir_quadratica(&tabela_quadratica, criar_produto(105, 999.99, "Headset HyperX Cloud Alpha", "esgotado"));
    inserir_quadratica(&tabela_quadratica, criar_produto(106, 7999.99, "Monitor 4K ASUS ROG Swift", "disponível"));


    exibir_todos(&tabela_quadratica);

    // Inserir produtos na tabela hash usando duplo hashing
    printf("\nInserção com Duplo Hashing:\n");
    TabelaHash tabela_duplo = {0};
    inserir_duplo_hashing(&tabela_duplo, criar_produto(107, 599.99, "SSD NVMe 1TB Samsung 980 Pro", "disponível"));
    inserir_duplo_hashing(&tabela_duplo, criar_produto(108, 3499.99, "Gabinete NZXT H510 Elite", "esgotado"));
    inserir_duplo_hashing(&tabela_duplo, criar_produto(109, 1999.99, "Fonte Corsair RM850x 850W", "disponível"));


    exibir_todos(&tabela_duplo);

    return 0;
}
