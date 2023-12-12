//
// Created by Julio Neto on 11/12/23.
//

#include "menu.h"
#include <stdio.h>
#include "../produto/produto.h"

void executeMenu();

void insertMenu();

int opcao;
Estoque estoque;
Produto produto;

/* Menu pricipal com as opcoes disponiveis */
void menu() {
    inicializarEstoque(&estoque);
    executeMenu();
    while (opcao != 0) {
        switch (opcao) {
            case 1:
                printf("\nLISTAR\n\n");
                exibirEstoque(&estoque);
                break;
            case 2:
                printf("\nINSERIR\n\n");
                insertMenu();
                break;
            case 3:
                printf("\nREMOVER\n\n");
                int codigo;
                printf("Digite o código do produto que deseja remover: ");
                scanf("%d", &codigo);
                removerProduto(&estoque, codigo);
                break;
            case 4:
                printf("\nPROCURAR\n\n");
                break;
            case 5:
                printf("\nTAMANHO\n\n");
                printf("Tamanho atual: %d\nCapacidade Total: %d\n", tamanhoEstoque(&estoque),
                       capacidadeEstoque(&estoque));
                break;
            default:
                printf("\n\033[1;31m[ ERRO ]: OPÇÃO INVÁLIDA!\033[0m\n\n");
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
    printf("0 - SAIR\n\n");
}

void escolherOpcao() {
    printf("Digite uma das opções acima: ");
    scanf("%d", &opcao);
}

void executeMenu() {
    listagemDeOpcoes();
    escolherOpcao();
}

void insertMenu() {
    printf("Insira o código:");
    scanf("%d", &produto.codigo);
    printf("Insira o nome:");
    scanf("%s", produto.nome);
    printf("Insira a quantidade:");
    scanf("%d", &produto.quantidade);
    printf("Insira o preço:");
    scanf("%lf", &produto.preco);
    adicionarProduto(&estoque, produto.codigo, produto.nome, produto.quantidade, produto.preco);
}