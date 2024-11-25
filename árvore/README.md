# **Corretor Ortográfico com Árvores Patricia**

Este projeto implementa um corretor ortográfico básico utilizando **Árvores Patricia** como estrutura de dados principal. Ele permite realizar operações eficientes de inserção, busca, sugestão de palavras e exibição de todas as palavras armazenadas.

---

## **Funcionalidades**

1. **Inserir palavras em um dicionário:** Adicione palavras ao dicionário durante a execução do programa.
2. **Buscar palavras no dicionário:** Verifique se uma palavra específica está presente no dicionário.
3. **Sugerir palavras com base em um prefixo:** Liste sugestões de palavras que começam com o prefixo digitado pelo usuário.
4. **Exibir todas as palavras armazenadas na árvore:** Visualize todas as palavras inseridas no dicionário.

---

## **Características do Projeto**

- **Eficiência:** Utiliza a estrutura Patricia para armazenamento otimizado e busca rápida.
- **Interatividade:** Oferece um menu interativo para facilitar a interação do usuário.
- **Customizável:** Permite carregar palavras iniciais a partir de um arquivo de texto (`dicionario.txt`).

---

## **Como Rodar o Projeto**

### **Pré-requisitos**

- Sistema com suporte ao compilador **GCC**.
- Arquivo `dicionario.txt` no mesmo diretório do código.

### **Passos para Executar**

1. **Clone o repositório**:
   ```bash
   git clone <URL_DO_REPOSITORIO>
   cd <PASTA_DO_REPOSITORIO>

2. **Compile o programa**:
   ```bash
   gcc corretor.c -o corretor
   
3. **Execute o programa**:
   ```bash
   ./corretor

---

##Uso do Programa##

Ao executar o programa, você verá o seguinte menu:

Copiar código
Escolha uma opção:
1. Inserir palavra
2. Buscar palavra
3. Autocompletar palavras
4. Exibir todas as palavras
0. Sair
   
Detalhes das Funcionalidades
Opção 1 - Inserir Palavra: Adicione manualmente uma palavra ao dicionário.
Opção 2 - Buscar Palavra: Verifique se uma palavra está presente no dicionário. Retorna "Encontrada" ou "Não encontrada".
Opção 3 - Autocompletar Palavras: Insira um prefixo e obtenha uma lista de palavras que começam com ele.
Opção 4 - Exibir Todas as Palavras: Liste todas as palavras atualmente armazenadas na Árvore Patricia.
Opção 0 - Sair: Encerre o programa.
