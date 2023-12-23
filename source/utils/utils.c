//
// Created by Julio Neto on 12/12/23.
//

#include "utils.h"
#include <stdio.h>

// Imprime o cabeçalho da tabela de produtos
void imprimirCabecalho() {
    printf("\n\033[1;32m");
    printf("=====================================================================================================\n");
    printf("\033[0m");
    printf("Código\t\tDescrição\t\t\t\t\t\t\t\t\t\t\tCategoria\t\tQuantidade\t\tPreço\n");
    printf("\033[1;32m");
    printf("=====================================================================================================\n");
    printf("\033[0m");
}

// Imprime os dados de um produto
void imprimirProduto(unsigned int codigo, char *descricao, char *categoria, unsigned int quantidade, double preco) {
    printf("%-6d\t\t%-50s\t%-15s\t%-10d\t\t%.2lf\n", codigo, descricao, categoria, quantidade, preco);
}


void limparBufferEntrada() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}