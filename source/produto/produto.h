//
// Created by Julio Neto on 11/12/23.
//

#ifndef GESTAO_DE_ESTOQUE_PRODUTO_H
#define GESTAO_DE_ESTOQUE_PRODUTO_H

// Estrutura que representa um produto
typedef struct {
    unsigned int codigo;        // Código do produto (Identificador único)
    char descricao[50];         // Descrição do produto
    char categoria[15];         // Categoria do produto
    double preco;               // Preço do produto
    unsigned int quantidade;    // Quantidade de produtos no estoque
} Produto;

// Estrutura que representa o estoque
typedef struct {
    Produto *produtos;          // Ponteiro para o array dinâmico de produtos
    int capacidade;             // Número máximo de produtos que o array pode armazenar
    int tamanho;                // Número atual de produtos no array
} Estoque;

// Protótipos das funções

void inicializarEstoque(Estoque *estoque);

void adicionarProduto(Estoque *estoque, unsigned int codigo, const char descricao[], const char categoria[15], double preco, int quantidade);

void exibirEstoque(Estoque *estoque);

int tamanhoEstoque(Estoque *estoque);

int capacidadeEstoque(Estoque *estoque);

void buscarProduto(Estoque *estoque, int codigo);

int buscarPosicaoDoProduto(Estoque *estoque, int codigo);

void removerProduto(Estoque *estoque, int codigo);

#endif //GESTAO_DE_ESTOQUE_PRODUTO_H
