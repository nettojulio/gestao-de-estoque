//
// Created by Julio Neto on 12/12/23.
//

#include "utils.h"
#include <stdio.h>

void imprimirCabecalho() {
    printf("\n\033[1;32m");
    printf("=====================================================================================================\n");
    printf("\033[0m");
    printf("Código\t\tDescrição\t\t\t\t\t\t\t\t\t\t\tCategoria\t\tQuantidade\t\tPreço\n");
    printf("\033[1;32m");
    printf("=====================================================================================================\n");
    printf("\033[0m");
}

void imprimirProduto(unsigned int codigo, char *descricao, char *categoria, unsigned int quantidade, double preco) {
    printf("%.06d\t\t%-50s\t%-15s\t%.10d\t\t%.2lf\n", codigo, descricao, categoria, quantidade, preco);
}