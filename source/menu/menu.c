//
// Created by Julio Neto on 11/12/23.
//

#include "menu.h"
#include <stdio.h>

void listagemDeOpcoes();

void escolherOpcao();

int opcao;

void menu() {
    listagemDeOpcoes();
    escolherOpcao();
    while (opcao != 0) {
        switch (opcao) {
            case 1:
                printf("\n\nLISTAR\n\n");
                break;
            case 2:
                printf("\n\nINSERIR\n\n");
                break;
            case 3:
                printf("\n\nREMOVER\n\n");
                break;
            case 4:
                printf("\n\nPROCURAR\n\n");
                break;
            case 5:
                printf("\n\nTAMANHO\n\n");
                break;
            default:
                printf("\n\nOPÇÃO INVÁLIDA\n\n");
        }
        escolherOpcao();
    }
    printf("Encerrando o programa...\n");
}

void listagemDeOpcoes() {
    printf("1 - Listar produtos\n");
    printf("2 - Inserir produto\n");
    printf("3 - Remover produto\n");
    printf("4 - Procurar produto\n");
    printf("5 - Tamanho do estoque\n");
    printf("0 - SAIR\n");
}

void escolherOpcao() {
    printf("Digite uma das opções acima: ");
    scanf("%d", &opcao);
}