# Requerimentos do projeto

## GERAL

1. Escolha um projeto:
   - [ ] Gestão de alunos;
   - [ ] Gestão de tarefas;
   - [x] Gestão de estoque;
   - [ ] Gestão de biblioteca.
2. O sistema deve armazenar os dados cadastrados utilizando:
   - [ ] Alocação dinâmica de memória.
   - [ ] Arquivos.
   - [ ] Armazenar, inicialmente, 10 registros (alunos, tarefas, produtos ou livros).
   - [ ] Aumentar a capacidade em 10 novos registros sempre que necessário com alocação dinâmica.
3. Cada funcionalidade deve ser implementada:
   - [ ] Usando uma função.
   - [ ] estar comentado
   - [ ] ter tabulação correta
   - [ ] seguir boas praticas de programação.
   - [ ] definir um arquivo .h para definição dos protótipos das funções.
4. Deverá usar obrigatoriamente:
   - [ ] constantes
   - [ ] variáveis globais
   - [ ] variáveis locais
   - [ ] estruturas (struct)
   - [ ] ponteiros
   - [ ] arquivo de texto
   - [ ] módulos.
   - [ ] As operações definidas para manipular a struct no vetor (inserção, remoção, inicialização, listagem dos elementos, tamanho) devem ser definidas no arquivo .h e implementadas no .c correspondente.
   - [ ] A função main deverá ser implementada em outro arquivo .c que irá apenas utilizar usar as funções através da inclusão da biblioteca .h criada.

## FUNCIONALIDADES

1. **Menu de opções**
    - [ ] O menu imprime mensagens com opções das funcionalidades descritas abaixo e o usuário selecionará o índice da opção desejada.
    - [ ] O menu será apresentado sempre que o usuário finalizar uma funcionalidade.
    - [ ] O sistema encerrará quando o usuário selecionar a opção de “Sair”.
    - [ ] Opções inválidas devem gerar um alerta de erro.
2. **Inserção**
   - [ ] Funcionalidade para inserção de apenas um registro (aluno, tarefa, produto ou livro).
   - [ ] Cada registro deve possuir identificador único. O sistema deve aumentar a capacidade de armazenamento em tempo de execução usando alocação dinâmica de memoria.
   - [ ] Alertas de erro devem ser gerados (exemplos: registros com matrículas iguais, valores inválidos, etc).
   - [ ] Esta funcionalidade também deve ser implementada de forma que os registros devem ser incluídos no fim do vetor;
3. **Remoção**
    - [ ] O identificador deve ser informado (remoção por valor).
    - [ ] Essa funcionalidade disponibilizará espaço para um novo registro.
    - [ ] Alertas de erro devem ser gerados (exemplos: identificador não encontrado, sistema sem registros cadastrados).
    - [ ] A remoção de um registro em uma determinada posição fará com que todos os registros a direita da posição encontrada sejam deslocados uma posição a esquerda;
4. **Listagem**
   - [ ] Exibir os registros ativos em um determinado momento. A depender do sistema, outras funções para listagem devem ser consideradas.
     - [ ] Para a gestão de alunos, também é necessário ter funções para listar alunos aprovados, reprovados, etc.
     - [ ] Para a gestão de tarefas, onde a listagem também pode ser feita para tarefas concluídas, tarefas em andamento, tarefas concluídas, etc.
     - [ ] Para a gestão da biblioteca, deve ser possível listar os livros disponíveis, emprestados, livros por editora e por ano.
     - [ ] Outra possibilidade é a de exibir os dados de um único registro a partir de seu identificador, caso este esteja cadastrado;
5. **Arquivo texto**
   - [ ] um arquivo de texto deverá ser criado e manipulado através das funções.
   - [ ] O arquivo terá que ser acessado em todas as funcionalidades que necessitem inserir, alterar, remover ou apresentar os dados.
   - [ ] Todas as informações inseridas, alteradas ou removidas deverão estar refletidas no arquivo;
