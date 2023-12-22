//
// Created by gabriel on 12/12/23.
//

#include "arquivo.h"
#include <stdio.h>
#include <stdlib.h>
#include "../produto/produto.h"

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
        fprintf(pont_arq, "Descrição do produto:%s\n", estoque->produtos->descricao);
        fprintf(pont_arq, "Categoria do produto:%s\n", estoque->produtos->categoria);
        fprintf(pont_arq, "Preço do produto:%lf\n", estoque->produtos->preco);
        fprintf(pont_arq, "Quantidade do produto:%d\n", estoque->produtos->quantidade);
        fprintf(pont_arq, "Código do produto:%d\n", estoque->produtos->codigo);
    }

     //usando fclose para fechar o arquivo
    fclose(pont_arq);
}
