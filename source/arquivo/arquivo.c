//
// Created by gabriel on 12/12/23.
//

#include <stdio.h>
#include "arquivo.h"

void armazenarDados(const char *nomeArquivo, const char *dados) {
    FILE *arquivo = fopen(nomeArquivo,
                          "a");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(arquivo, "%s\n", dados);
    fclose(arquivo);
    printf("Dados armazenados com sucesso no arquivo: %s\n", nomeArquivo);
}

void lerDadosDoArquivo(const char *nomeArquivo, Estoque *estoque) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("Conteúdo do arquivo %s:\n", nomeArquivo);

    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int codigo;
        char nome[50];
        char tipo[50];
        int quantidade;
        float preco;

        sscanf(linha, "%d;%49[^;];%49[^;];%f;%d", &codigo, nome, tipo, &preco, &quantidade);

        if (buscarPosicaoDoProduto(estoque, codigo) == -1) {
            adicionarProduto(estoque, codigo, nome, tipo, preco, quantidade, 'r');
        }
    }

    fclose(arquivo);
}