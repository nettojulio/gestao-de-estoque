//
// Created by Julio Neto on 11/12/23.
//

#ifndef GESTAO_DE_ESTOQUE_PRODUTO_H
#define GESTAO_DE_ESTOQUE_PRODUTO_H

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    double preco;
} Produto;

// Estrutura que representa o estoque
typedef struct {
    Produto *produtos;          // Ponteiro para o array dinâmico de produtos
    int capacidade;             // Número máximo de produtos que o array pode armazenar
    int tamanho;                // Número atual de produtos no array
} Estoque;

// Protótipos das funções
void inicializarEstoque(Estoque *estoque);

void adicionarProduto(Estoque *estoque, int codigo, const char nome[], int quantidade, double preco);

void exibirEstoque(Estoque *estoque);

void liberarEstoque(Estoque *estoque);

int tamanhoEstoque(Estoque *estoque);

int capacidadeEstoque(Estoque *estoque);

#endif //GESTAO_DE_ESTOQUE_PRODUTO_H
