# Gestão de Produtos com Tabela Hash

## Tema do Estudo de Caso

**Ordenação de Produtos em um E-commerce durante a Black Friday**

### Descrição do Problema

Durante grandes promoções, como a Black Friday, um site de e-commerce enfrenta o desafio de organizar rapidamente suas listas de produtos. A necessidade de um sistema que possa processar e exibir produtos de forma eficiente se torna crucial, especialmente considerando fatores como preço, popularidade e disponibilidade. O sistema deve ser capaz de lidar com picos de acessos e garantir que os usuários encontrem as melhores ofertas rapidamente.

### Objetivo

O objetivo deste projeto é desenvolver um sistema que utilize uma tabela hash para gerenciar produtos em um e-commerce. Isso permite a inserção, busca e remoção de produtos de forma eficiente, garantindo que as listas de produtos sejam atualizadas em tempo real, conforme novos produtos são adicionados ou removidos do estoque.

### Funcionalidades do Código

- **Inserção de Produtos**: Permite adicionar novos produtos à tabela hash, garantindo acesso rápido a informações sobre cada item.
- **Busca de Produtos**: Possibilita a busca eficiente de produtos pelo ID, garantindo que os usuários possam localizar rapidamente o que desejam.
- **Exibição de Produtos Esgotados**: Exibe uma lista de produtos que estão esgotados, ajudando na gestão do estoque e na comunicação com os clientes.
- **Remoção de Produtos**: Permite a exclusão de produtos da tabela hash, atualizando o sistema em tempo real.

### Estrutura do Código

O código é composto pelas seguintes partes:

- **Definição das Estruturas**: Estruturas `Produto` e `TabelaHash` para representar produtos e a tabela hash, respectivamente.
- **Funções de Manipulação**: Funções para inserir, buscar, exibir e deletar produtos na tabela hash.
- **Função Principal**: Demonstração do uso das funcionalidades, incluindo a criação de produtos e operações na tabela hash.

### Como Usar

1. **Compilar o Código**: Use um compilador C (como `gcc`) para compilar o código.
2. **Executar o Programa**: Após a compilação, execute o programa para ver as funcionalidades em ação.
3. **Adicionar/Remover Produtos**: Você pode modificar o código para adicionar ou remover produtos conforme necessário.

### Conclusão

Este código serve como uma base para um sistema mais complexo que pode ser expandido para atender a requisitos adicionais, como a ordenação dos produtos por diferentes critérios (preço, popularidade, etc.) e a gestão de acessos simultâneos durante eventos de alta demanda como a Black Friday.
