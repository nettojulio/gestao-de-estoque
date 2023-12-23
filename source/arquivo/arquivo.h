//
// Created by gabriel on 12/12/23.
//

#ifndef GESTAO_DE_ESTOQUE_ARQUIVO_H
#define GESTAO_DE_ESTOQUE_ARQUIVO_H

#include "../produto/produto.h"

void armazenarDados(const char *nomeArquivo, const char *dados);

void lerDadosDoArquivo(const char *nomeArquivo, Estoque *estoque);

#endif //GESTAO_DE_ESTOQUE_ARQUIVO_H
