# **Corretor Ortográfico com Árvores Patricia**

Este projeto implementa um corretor ortográfico básico utilizando **Árvores Patricia** como estrutura de dados principal. O programa é capaz de:

1. **Inserir palavras em um dicionário.**
2. **Buscar palavras no dicionário.**
3. **Sugerir palavras com base em um prefixo (autocompletar).**
4. **Exibir todas as palavras armazenadas na árvore.**

## **Características do Projeto**
- **Eficiência:** Utiliza a estrutura Patricia para armazenamento otimizado e busca eficiente.
- **Interatividade:** Oferece um menu interativo para facilitar a interação do usuário.
- **Customizável:** Permite carregar palavras a partir de um arquivo de texto (`dicionario.txt`).

---

## **Como Rodar o Projeto**

### **Pré-requisitos**
- Sistema com suporte ao compilador **GCC**.
- Arquivo `dicionario.txt` no mesmo diretório do código.

### **Passos**
1. **Clone o repositório**:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <PASTA_DO_REPOSITORIO>

2. **Compile o programa**:
   ```bash
   gcc corretor.c -o corretor
   
2. **Execute o programa**:
   ```bash
   ./corretor

## **Uso**
Ao executar o programa, você verá o seguinte menu:
   Copiar código
   Escolha uma opção:
   1. Inserir palavra
   2. Buscar palavra
   3. Autocompletar palavras
   4. Exibir todas as palavras
   0. Sair

Funcionalidades
**Opção 1**: Inserir uma palavra no dicionário.
**Opção 2**: Buscar uma palavra no dicionário.
**Opção 3**: Digitar um prefixo para obter sugestões de palavras.
**Opção 4**: Exibir todas as palavras atualmente armazenadas na Árvore Patricia.
**Opção 0**: Encerrar o programa.
