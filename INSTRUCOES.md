# Trabalho 1

Nesta atividade, você deve implementar um sistema simplificado para gestão de um
dos problemas definidos abaixo.

1. Gestão de alunos;
2. Gestão de tarefas;
3. Gestão de estoque;
4. Gestão de biblioteca.

O sistema deve armazenar os dados cadastrados utilizando **alocação dinâmica de
memória e arquivos**. O sistema deve ser capaz de armazenar, inicialmente, 10 registros
(alunos, tarefas, produtos ou livros) e aumentar a capacidade em 10 novos registros
sempre que necessário com alocação dinâmica.

1. O sistema deve ter as funcionalidades descritas abaixo. **Cada funcionalidade deve
ser implementada usando uma função**. O código deve estar comentado, ter
tabulação correta e seguir boas praticas de programação. Além disso, deve-se definir
um arquivo .h para definição dos protótipos das funções.
1.1. Menu de opções - O menu imprime mensagens com opções das funcionalidades
descritas abaixo e o usuário selecionará o índice da opção desejada; - O menu será
apresentado sempre que o usuário finalizar uma funcionalidade; - O sistema
encerrará quando o usuário selecionar a opção de “Sair”; - Opções inválidas devem
gerar um alerta de erro;
1.2. Inserção - Funcionalidade para inserção de apenas um registro (aluno, tarefa,
produto ou livro). Cada registro deve possuir identificador único. O sistema deve
aumentar a capacidade de armazenamento em tempo de execução usando alocação
dinâmica de memoria; - Alertas de erro devem ser gerados (exemplos: registros com
matrículas iguais, valores inválidos, etc). Esta funcionalidade também deve ser
implementada de forma que os registros devem ser incluídos no fim do vetor;
1.3. Remoção – O identificador deve ser informado (remoção por valor); - Essa
funcionalidade disponibilizará espaço para um novo registro; - Alertas de erro
devem ser gerados (exemplos: identificador não encontrado, sistema sem registros
cadastrados). A remoção de um registro em uma determinada posição fará com que
todos os registros a direita da posição encontrada sejam deslocados uma posição a
esquerda;

1.4. Listagem - Exibir os registros ativos em um determinado momento. A depender do
sistema, outras funções para listagem devem ser consideradas. Para a gestão de
alunos, também é necessário ter funções para listar alunos aprovados, reprovados,
etc. Outro exemplo pode ser dado para a gestão de tarefas, onde a listagem também
pode ser feita para tarefas concluídas, tarefas em andamento, tarefas concluídas, etc.
No caso da gestão da biblioteca, deve ser possível listar os livros disponíveis,
emprestados, livros por editora e por ano. Outra possibilidade é a de exibir os dados
de um único registro a partir de seu identificador, caso este esteja cadastrado;
2. Arquivo texto: um arquivo de texto deverá ser criado e manipulado através das
funções. O arquivo terá que ser acessado em todas as funcionalidades que
necessitem inserir, alterar, remover ou apresentar os dados. Todas as informações
inseridas, alteradas ou removidas deverão estar refletidas no arquivo;
2.1. Requisitos mínimos: este projeto deverá usar obrigatoriamente constantes,
variáveis globais, variáveis locais, estruturas (struct), ponteiros, arquivo de texto e
módulos. As operações definidas para manipular a struct no vetor (inserção,
remoção, inicialização, listagem dos elementos, tamanho) devem ser definidas
no arquivo .h e implementadas no .c correspondente. A função main deverá ser
implementada em outro arquivo .c que irá apenas utilizar usar as funções através da
inclusão da biblioteca .h criada.
Prazo: Todos os alunos deverão enviar o código até o dia 23/12/2023 no ambiente
virtual da turma no Classroom. A atividade poderá ser feita em dupla ou
individualmente.
Política para Plágio: Alunos que forem flagrados compartilhando código com colegas
ou utilizando código de outros autores receberão nota 0 (ZERO) na atividade.
Observação: Abaixo são descritas algumas estruturas para modelar os registros de cada
problema. A critério dos alunos, as estruturas podem sofrer pequenas modificações.

1. Gestão de alunos
Os dados abaixo devem ser informados e armazenados sobre cada aluno. Deve-se criar
um struct para representar o aluno contendo as variáveis descritas abaixo.

Tipo Variável Descrição
Inteiro matrícula Formato: 20230XX
Ex: 2023001, 2023002,etc.
Real notas Médias do aluno em 7 disciplinas
String nome Nome do aluno
Inteiro código Código da turma
Inteiro faltas Quantidade de faltas nas 7 disciplinas

Exemplos de estruturas para o aluno e turma de alunos:
typedef struct{
int matricula;
float notas[7];
char nome[50];
int codTurma;
int faltas[7];
}aluno;

typedef struct{
aluno *alunos;
int qtdAlunos;
int id;
}turma;

2. Gestão de biblioteca

Os dados abaixo devem ser informados e armazenados sobre cada livro. Deve-se criar
um struct para representar o livro contendo as variáveis descritas abaixo.

Tipo Variável Descrição
Inteiro id Identificador do livro
String autores Autores do livro
String título Título do livro

String editora Editora do livro
Inteiro ano Ano de lançamento
Inteiro situação Livro disponível

Exemplos de estruturas para o livro e biblioteca:
typedef struct{
int id;
char autores[100];
char titulo[50];
char editora;
int ano;
int situacao;
}livro;

typedef struct{
livro *livros;
int qtdLivros;
}biblioteca;

3. Gestão de tarefas

Os dados abaixo devem ser informados e armazenados sobre cada livro. Deve-se criar
um struct para representar cada tarefa contendo as variáveis descritas abaixo.

Tipo Variável Descrição
Inteiro id Identificador
String descrição Descrição da tarefa
Inteiro status Status da tarefa (pendente, em
progresso, concluída, cancelada)

String prazo Prazo da tarefa

Exemplos de estruturas para tarefa e gerenciador de tarefas:
typedef struct{
int id;
char descricao[50];
int status;
char prazo[11]; //Formato DD-MM-AAAA

typedef struct{
tarefa *tarefas;
int qtdTarefas;
}gerenciador;

}tarefa;

4. Gestão de estoque
Os dados abaixo devem ser informados e armazenados sobre cada livro. Deve-se criar
um struct para representar o livro contendo as variáveis descritas abaixo.

Tipo Variável Descrição
Inteiro id Identificador
String descrição Descrição do produto
Inteiro categoria Categoria do produto
Inteiro quantidade Quantidade disponível
Real valor Valor do produto

Exemplos de estruturas para o produto e estoque de produtos:
typedef struct{
int id;
char descricao[50];
int categoria;
float valor;
int quantidade;
}produto;

typedef struct{
produto *produtos;
int qtdProdutos;
}estoque;

Menu sugerido
Opção Função Detalhes
1 inserir Recebe como parâmetros um registro contendo os novos dados a
serem inseridos, retorna o valor 0 ou 1, indicando se o registro foi
inserido com sucesso. Essa função deve inserir no fim do vetor.
4 listar Imprime cada elemento por linha, onde cada linha deve apresentar os

dados do registro.

6 remover Recebe como parâmetros um número inteiro(identificador), retorna o
valor 0 ou 1, indicando se o registro foi removido com sucesso.

Caso o valor passado como parâmetro exista, todos os registros à
direita da posição do registro removido devem ser deslocados uma
posição à esquerda.

7 procurar Recebe como parâmetros um identificador (id) e retorna a posição na
vetor em que o valor id se encontra. Caso o id não exista, a função
deve retornar o valor -1.

8 tamanho Retorna a quantidade de elementos armazenados no sistema.
-1 sair Encerrar a execução.

Observação: outras funcionalidades do sistema de gestão devem ser consideradas a
depender do problema escolhido. Por exemplo, a função de listagem deve envolver
outro menu para listar de acordo com um filtro a ser escolhido.
