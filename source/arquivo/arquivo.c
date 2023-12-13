//
// Created by gabriel on 12/12/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "../produto/produto.h"
#include "arquivo.h"

void adicionar(Estoque *estoque){
    //abrindo o arquivo com tipo de abertura w
    FILE *pont_arq = fopen("arquivo.txt", "a");

    //testando se o arquivo foi realmente criado
    if( pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo!");
    }else{
        printf("\n");
        //usando fprintf para armazenar a string no arquivo
        fprintf(pont_arq, "Nome do produto:%s\n", estoque->produtos->nome);
        fprintf(pont_arq, "Preço do produto:%lf\n", estoque->produtos->preco);
        fprintf(pont_arq, "Quantidade do produto:%d\n", estoque->produtos->quantidade);
        fprintf(pont_arq, "Código do produto:%d\n", estoque->produtos->codigo);
        printf("\033[1;32mDADOS GRAVADOS COM SUCESSO!\033[0m\n\n");
    }

     //usando fclose para fechar o arquivo
    fclose(pont_arq);
}
