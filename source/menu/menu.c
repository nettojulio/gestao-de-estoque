//
// Created by Julio Neto on 11/12/23.
//

#include "menu.h"
#include <stdio.h>
#include <string.h>
#include "../produto/produto.h"
#include "../arquivo/arquivo.h"

void execucaoMenu();

void menuExibir();

void menuInserir();

void menuRemover();

void menuProcurar();

void menuTamanho();

int opcao;
Estoque estoque;
Produto produto;
Arquivo arquivo;

// Menu pricipal com as opcoes disponiveis
void menu() {
    inicializarEstoque(&estoque);
    execucaoMenu();
    while (opcao != 0) {
        switch (opcao) {
            case 1:
                printf("\nLISTAR\n\n");
                menuExibir();
                break;
            case 2:
                printf("\nINSERIR\n\n");
                menuInserir();
                break;
            case 3:
                printf("\nREMOVER\n\n");
                menuRemover();
                break;
            case 4:
                printf("\nPROCURAR\n\n");
                menuProcurar();
                break;
            case 5:
                printf("\nTAMANHO\n\n");
                menuTamanho();
                break;
            case 6:
                break;
            default:
                printf("\n\033[1;31m[ ERRO ]: OPÇÃO INVÁLIDA!\033[0m\n\n");
        }
        execucaoMenu();
    }
    printf("Encerrando o programa...\n");
}

// Listagem das principais opções
void listagemDeOpcoes() {
    printf("1 - Listar produtos\n");
    printf("2 - Inserir produto\n");
    printf("3 - Remover produto\n");
    printf("4 - Procurar produto\n");
    printf("5 - Tamanho do estoque\n");
    printf("0 - SAIR\n\n");
}

// Escolha da opção
void escolherOpcao() {
    printf("Digite uma das opções acima: ");
    scanf("%d", &opcao);
}

// Execução do menu
void execucaoMenu() {
    listagemDeOpcoes();
    escolherOpcao();
}

// Exibição do estoque
void menuExibir() {
    exibirEstoque(&estoque);
}

// Inserção de um produto
void menuInserir() {

    printf("Insira o código: ");
    scanf("%d", &produto.codigo);
    limparBufferEntrada();
    printf("Insira o descricao: ");
    fgets(produto.descricao, 50, stdin);
    produto.descricao[strcspn(produto.descricao, "\n")] = '\0'; // Remove a quebra de linha
    printf("Insira o categoria: ");
    fgets(produto.categoria, 15, stdin);
    produto.categoria[strcspn(produto.categoria, "\n")] = '\0'; // Remove a quebra de linha
    printf("Insira a quantidade: ");
    scanf("%d", &produto.quantidade);
    limparBufferEntrada();
    printf("Insira o preço: ");
    scanf("%lf", &produto.preco);
    limparBufferEntrada();
    adicionarProduto(&estoque, produto.codigo, produto.descricao, produto.categoria, produto.preco, produto.quantidade);
    adicionar(&estoque);
}

// Remoção de um produto
void menuRemover() {
    int codigo;
    printf("Digite o código do produto que deseja remover: ");
    scanf("%d", &codigo);
    removerProduto(&estoque, codigo);
}

// Busca de um produto
void menuProcurar() {
    int codigo;
    printf("Digite o código do produto que deseja buscar: ");
    scanf("%d", &codigo);
    buscarProduto(&estoque, codigo);
}

// Tamanho do estoque e capacidade total
void menuTamanho() {
    printf("Tamanho atual: %d\nCapacidade Total: %d\n", tamanhoEstoque(&estoque),
           capacidadeEstoque(&estoque));
}
