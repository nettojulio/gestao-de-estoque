//
// Created by Julio Neto on 11/12/23.
//

#include "produto.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/utils.h"
#include "../arquivo/arquivo.h"

#define TAMANHO_INICIAL 10

#define NOME_DO_ARQUIVO "dados.txt"

const char *nomeArquivo = NOME_DO_ARQUIVO;

// Inicializa o estoque com valores padrão
void inicializarEstoque(Estoque *estoque) {
    // Aloca memória para o array de produtos dinamicamente
    estoque->produtos = (Produto *) malloc(TAMANHO_INICIAL * sizeof(Produto));
    // Caso a alocação falhe, exibe uma mensagem de erro e encerra o programa
    if (estoque->produtos == NULL) {
        fprintf(stderr, "Erro na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }

    estoque->capacidade = TAMANHO_INICIAL;
    estoque->tamanho = 0;
}

// Adiciona um produto ao estoque
void
adicionarProduto(Estoque *estoque, unsigned int codigo, const char descricao[], const char categoria[15], double preco,
                 int quantidade, char operacao) {
    // Verifica se há espaço suficiente no array
    if (estoque->tamanho == estoque->capacidade) {
        // Se não houver espaço suficiente, redimensiona o array com mais 10 posições
        estoque->capacidade += 10;
        estoque->produtos = (Produto *) realloc(estoque->produtos, estoque->capacidade * sizeof(Produto));

        // Caso o realloc falhe, exibe uma mensagem de erro e encerra o programa
        if (estoque->produtos == NULL) {
            fprintf(stderr, "Erro na realocação de memória.\n");
            exit(EXIT_FAILURE);
        }

    }

    // Verifica se o código já foi cadastrado
    for (int i = 0; i < estoque->tamanho; ++i) {
        if (estoque->produtos[i].codigo == codigo) {
            printf("\n\033[1;31m[ ERRO ]: CÓDIGO JÁ CADASTRADO!\033[0m\n");
            imprimirCabecalho();
            imprimirProduto(estoque->produtos[i].codigo,
                            estoque->produtos[i].descricao,
                            estoque->produtos[i].categoria, estoque->produtos[i].quantidade,
                            estoque->produtos[i].preco);
            printf("\n");
            return;
        }
    }

    // Verifica se todos os dados informados são válidos

    if (codigo <= 0) {
        printf("\n\033[1;31m[ ERRO ]: CÓDIGO INVÁLIDO!\033[0m\n");
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

    if (strlen(descricao) > 50 || strlen(descricao) < 1) {
        printf("\n\033[1;31m[ ERRO ]: DESCRIÇÃO INVÁLIDA!\033[0m\n");
        return;
    }

    if (strlen(categoria) > 15 || strlen(categoria) < 1) {
        printf("\n\033[1;31m[ ERRO ]: CATEGORIA INVÁLIDA!\033[0m\n");
        return;
    }

    // Adiciona o produto ao array
    estoque->produtos[estoque->tamanho].codigo = codigo;
    strncpy(estoque->produtos[estoque->tamanho].descricao, descricao,
            sizeof(estoque->produtos[estoque->tamanho].descricao) - 1);
    strncpy(estoque->produtos[estoque->tamanho].categoria, categoria,
            sizeof(estoque->produtos[estoque->tamanho].categoria) - 1);
    estoque->produtos[estoque->tamanho].preco = preco;
    estoque->produtos[estoque->tamanho].quantidade = quantidade;
    estoque->tamanho++;

    if (operacao != 'r') {
        char resultado[100];

        sprintf(resultado, "%u;%s;%s;%.2lf;%u", codigo, descricao, categoria, preco, quantidade);

        armazenarDados(nomeArquivo, resultado);
        printf("\033[1;32mPRODUTO CADASTRADO!\033[0m\n\n");
    }

}

// Exibe o conteúdo do estoque
void exibirEstoque(Estoque *estoque) {
    imprimirCabecalho();
    for (int i = 0; i < estoque->tamanho; ++i) {
        imprimirProduto(estoque->produtos[i].codigo,
                        estoque->produtos[i].descricao,
                        estoque->produtos[i].categoria, estoque->produtos[i].quantidade, estoque->produtos[i].preco);
    }
    printf("\n");
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

// Busca um produto com base no codigo informado
void buscarProduto(Estoque *estoque, int codigo) {
    int index = buscarPosicaoDoProduto(estoque, codigo);
    if (index == -1) {
        printf("\n\033[1;31m[ ERRO ]: CÓDIGO NÃO ENCONTRADO!\033[0m\n\n");
        return;
    }
    imprimirCabecalho();
    imprimirProduto(estoque->produtos[index].codigo, estoque->produtos[index].descricao,
                    estoque->produtos[index].categoria,
                    estoque->produtos[index].quantidade, estoque->produtos[index].preco);
    printf("\n");

}

// Preenche com valores default a ultima posição do estoque
void nularUltimoProduto(Estoque *estoque) {
    estoque->produtos[estoque->tamanho - 1].codigo = USER_ADDR_NULL;

    char descricao[50];
    stpcpy(estoque->produtos[estoque->tamanho - 1].descricao, descricao);

    char categoria[15];
    stpcpy(estoque->produtos[estoque->tamanho - 1].categoria, categoria);

    estoque->produtos[estoque->tamanho - 1].quantidade = USER_ADDR_NULL;
    estoque->produtos[estoque->tamanho - 1].preco = USER_ADDR_NULL;
}

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
    nularUltimoProduto(estoque);
    estoque->tamanho--;

    printf("\033[1;32mPRODUTO REMOVIDO!\033[0m\n\n");
}

void recuperarProdutos(Estoque *estoque) {
    lerDadosDoArquivo(nomeArquivo, estoque);
}