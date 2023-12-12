//
// Created by Julio Neto on 11/12/23.
//

#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_INICIAL 10

// Inicializa o estoque com valores padrão
void inicializarEstoque(Estoque *estoque) {
    estoque->produtos = (Produto *) malloc(TAMANHO_INICIAL * sizeof(Produto));
    if (estoque->produtos == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    estoque->capacidade = TAMANHO_INICIAL;
    estoque->tamanho = 0;
}

// Adiciona um produto ao estoque
void adicionarProduto(Estoque *estoque, int codigo, const char nome[], int quantidade, float preco) {
    // Verifica se há espaço suficiente no array
    if (estoque->tamanho == estoque->capacidade) {
        // Se não houver espaço suficiente, redimensiona o array
        estoque->capacidade += 10;
        estoque->produtos = (Produto *) realloc(estoque->produtos, estoque->capacidade * sizeof(Produto));
        if (estoque->produtos == NULL) {
            fprintf(stderr, "Erro na realocação de memória.\n");
            exit(EXIT_FAILURE);
        }
    }

    // Adiciona o produto ao array
    estoque->produtos[estoque->tamanho].codigo = codigo;
    strncpy(estoque->produtos[estoque->tamanho].nome, nome, sizeof(estoque->produtos[estoque->tamanho].nome) - 1);
    estoque->produtos[estoque->tamanho].quantidade = quantidade;
    estoque->produtos[estoque->tamanho].preco = preco;
    estoque->tamanho++;
}

// Exibe o conteúdo do estoque
void exibirEstoque(Estoque *estoque) {
    printf("Código\t\tNome\t\t\t\tQuantidade\t\tPreço\n");
    for (int i = 0; i < estoque->tamanho; ++i) {
        printf("%.06d\t\t%s\t\t\t\t%.10d\t\t%.2f\n", estoque->produtos[i].codigo, estoque->produtos[i].nome,
               estoque->produtos[i].quantidade, estoque->produtos[i].preco);
    }
}

// Libera a memória alocada para o array de produtos
void liberarEstoque(Estoque *estoque) {
    free(estoque->produtos);
}

// Informa o tamanho do estoque
int tamanhoEstoque(Estoque *estoque) {
    return estoque->tamanho;
}

// Informa a capacidade total do estoque
int capacidadeEstoque(Estoque *estoque) {
    return estoque->capacidade;
}