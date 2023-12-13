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
void adicionarProduto(Estoque *estoque, int codigo, const char nome[], int quantidade, double preco) {
    // Verifica se há espaço suficiente no array
    if (estoque->tamanho == estoque->capacidade) {
        // Se não houver espaço suficiente, redimensiona o array com mais 10 posições
        estoque->capacidade += 10;
        estoque->produtos = (Produto *) realloc(estoque->produtos, estoque->capacidade * sizeof(Produto));
        if (estoque->produtos == NULL) {
            fprintf(stderr, "Erro na realocação de memória.\n");
            exit(EXIT_FAILURE);
        }

    }

    for (int i = 0; i < estoque->tamanho; ++i) {
        if (estoque->produtos[i].codigo == codigo) {
            printf("\n\033[1;31m[ ERRO ]: CÓDIGO JÁ CADASTRADO!\033[0m\n");
            printf("Código\t\tNome\t\t\t\tQuantidade\t\tPreço\n");
            printf("%.06d\t\t%s\t\t\t\t%.10d\t\t%.2lf\n\n", estoque->produtos[i].codigo, estoque->produtos[i].nome,
                   estoque->produtos[i].quantidade, estoque->produtos[i].preco);
            return;
        }

        if (preco < 0) {
            printf("\n\033[1;31m[ ERRO ]: PREÇO INVÁLIDO!\033[0m\n");
            return;
        }

        if (quantidade < 0) {
            printf("\n\033[1;31m[ ERRO ]: QUANTIDADE INVÁLIDA!\033[0m\n");
            return;
        }

        if (strlen(nome) > 50 || strlen(nome) < 1) {
            printf("\n\033[1;31m[ ERRO ]: NOME INVÁLIDO!\033[0m\n");
            return;
        }
    }



    // Adiciona o produto ao array
    estoque->produtos[estoque->tamanho].codigo = codigo;
    strncpy(estoque->produtos[estoque->tamanho].nome, nome, sizeof(estoque->produtos[estoque->tamanho].nome) - 1);
    estoque->produtos[estoque->tamanho].quantidade = quantidade;
    estoque->produtos[estoque->tamanho].preco = preco;
    estoque->tamanho++;
    printf("\033[1;32mPRODUTO CADASTRADO!\033[0m\n\n");
}

// Exibe o conteúdo do estoque
void exibirEstoque(Estoque *estoque) {
    printf("Código\t\tNome\t\t\t\tQuantidade\t\tPreço\n");
    for (int i = 0; i < estoque->tamanho; ++i) {
        printf("%.06d\t\t%s\t\t\t\t%.10d\t\t%.2lf\n", estoque->produtos[i].codigo, estoque->produtos[i].nome,
               estoque->produtos[i].quantidade, estoque->produtos[i].preco);
    }
    printf("\n");
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

// Busca a posição do produto desejado com base no codigo
int buscarPosicaoDoProduto(Estoque *estoque, int codigo) {
    int searchIndex = -1;
    for (int i = 0; i < estoque->tamanho; ++i) {
        if (estoque->produtos[i].codigo == codigo) {
            searchIndex = i;
            break;
        }
    }
    return searchIndex;
}

// Preenche com valores default a ultima posição do estoque
/*void nularUltimoProduto(Estoque *estoque) {
    estoque->produtos[estoque->tamanho - 1].codigo = USER_ADDR_NULL;

    char nome[50];
    stpcpy(estoque->produtos[estoque->tamanho - 1].nome, nome);

    estoque->produtos[estoque->tamanho - 1].quantidade = USER_ADDR_NULL;
    estoque->produtos[estoque->tamanho - 1].preco = USER_ADDR_NULL;

    printf("%s", estoque->produtos[estoque->tamanho - 1].nome);
}
*/
// Remove um produto com base no codigo informado
void removerProduto(Estoque *estoque, int codigo) {
    int searchIndex = buscarPosicaoDoProduto(estoque, codigo);
    if (searchIndex == -1) {
        printf("\n\033[1;31m[ ERRO ]: CÓDIGO NÃO ENCONTRADO!\033[0m\n\n");
        return;
    }

    for (int i = searchIndex; i < estoque->tamanho - 1; ++i) {
        estoque->produtos[i] = estoque->produtos[i + 1];
    }
    /*nularUltimoProduto(estoque);
    estoque->tamanho--;
*/
    printf("\033[1;32mPRODUTO REMOVIDO!\033[0m\n\n");
}

