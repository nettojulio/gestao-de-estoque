//
// Created by Julio Neto on 12/12/23.
//

#ifndef GESTAO_DE_ESTOQUE_UTILS_H
#define GESTAO_DE_ESTOQUE_UTILS_H

// Protótipos das funções do cabeçalho
void imprimirCabecalho();

// Imprime os dados de um produto
void imprimirProduto(unsigned int codigo, char *descricao, char *categoria, unsigned int quantidade, double preco);

// Limpa o buffer de entrada
void limparBufferEntrada();

#endif //GESTAO_DE_ESTOQUE_UTILS_H
