//
// Created by gabriel on 12/12/23.
//

#include <stdio.h>
#include "arquivo.h"


// Armazena os dados no arquivo dados.txt
void armazenarDados(const char *nomeArquivo, const char *dados) {
    // Abre o arquivo para escrita
    FILE *arquivo = fopen(nomeArquivo,
                          "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    // Escreve os dados no arquivo
    fprintf(arquivo, "%s\n", dados);
    fclose(arquivo);
    printf("Dados armazenados com sucesso no arquivo: %s\n", nomeArquivo);
}

// Lê os dados do arquivo dados.txt
void lerDadosDoArquivo(const char *nomeArquivo, Estoque *estoque) {
// Abre o arquivo para leitura
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    printf("Conteúdo do arquivo %s:\n", nomeArquivo);

    // Lê os dados do arquivo
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        int codigo;
        char nome[50];
        char tipo[50];
        int quantidade;
        float preco;

        // Lê os dados da linha
        sscanf(linha, "%d;%49[^;];%49[^;];%f;%d", &codigo, nome, tipo, &preco, &quantidade);

        // Verifica se o produto já existe no estoque
        if (buscarPosicaoDoProduto(estoque, codigo) == -1) {
            adicionarProduto(estoque, codigo, nome, tipo, preco, quantidade, 'r');
        }
    }

    fclose(arquivo);
}