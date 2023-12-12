//
// Created by Julio Neto on 11/12/23.
//

#include "menu.h"
#include <stdio.h>
#include "../produto/produto.h"

void executeMenu();

int opcao;

/* Menu pricipal com as opcoes disponiveis */
void menu() {
    Estoque *estoque;
    inicializarEstoque(estoque);
    executeMenu();
    while (opcao != 0) {
        switch (opcao) {
            case 1:
                printf("\nLISTAR\n\n");
                exibirEstoque(estoque);
                break;
            case 2:
                printf("\nINSERIR\n\n");
                adicionarProduto(estoque, 1, "Banana", 2, 1999.99);
                break;
            case 3:
                printf("\nREMOVER\n\n");
                break;
            case 4:
                printf("\nPROCURAR\n\n");
                break;
            case 5:
                printf("\nTAMANHO\n\n");
                printf("Tamanho atual: %d\nCapacidade Total: %d\n", tamanhoEstoque(estoque),
                       capacidadeEstoque(estoque));
                break;
            default:
                printf("\nOPÇÃO INVÁLIDA\n\n");
        }
        executeMenu();
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

void executeMenu() {
    listagemDeOpcoes();
    escolherOpcao();
}