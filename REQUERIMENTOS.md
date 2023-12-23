# Requerimentos do projeto

## GERAL

1. Escolha um projeto:
   - [ ] Gestão de alunos;
   - [ ] Gestão de tarefas;
   - [x] Gestão de estoque;
   - [ ] Gestão de biblioteca.
2. O sistema deve armazenar os dados cadastrados utilizando:
   - [x] Alocação dinâmica de memória.
   - [-] Arquivos.
   - [x] Armazenar, inicialmente, 10 registros (alunos, tarefas, produtos ou livros).
   - [x] Aumentar a capacidade em 10 novos registros sempre que necessário com alocação dinâmica.
3. Cada funcionalidade deve ser implementada:
   - [x] Usando uma função.
   - [x] estar comentado
   - [x] ter tabulação correta
   - [x] seguir boas praticas de programação.
   - [x] definir um arquivo .h para definição dos protótipos das funções.
4. Deverá usar obrigatoriamente:
   - [x] constantes
   - [x] variáveis globais
   - [x] variáveis locais
   - [x] estruturas (struct)
   - [x] ponteiros
   - [x] arquivo de texto
   - [x] módulos.
   - [x] As operações definidas para manipular a struct no vetor (inserção, remoção, inicialização, listagem dos elementos, tamanho) devem ser definidas no arquivo .h e implementadas no .c correspondente.
   - [x] A função main deverá ser implementada em outro arquivo .c que irá apenas utilizar usar as funções através da inclusão da biblioteca .h criada.

## FUNCIONALIDADES

1. **Menu de opções**
    - [x] O menu imprime mensagens com opções das funcionalidades descritas abaixo e o usuário selecionará o índice da opção desejada.
    - [x] O menu será apresentado sempre que o usuário finalizar uma funcionalidade.
    - [x] O sistema encerrará quando o usuário selecionar a opção de “Sair”.
    - [x] Opções inválidas devem gerar um alerta de erro.
2. **Inserção**
   - [x] Funcionalidade para inserção de apenas um registro (aluno, tarefa, produto ou livro).
   - [x] Cada registro deve possuir identificador único. O sistema deve aumentar a capacidade de armazenamento em tempo de execução usando alocação dinâmica de memoria.
   - [x] Alertas de erro devem ser gerados (exemplos: registros com matrículas iguais, valores inválidos, etc).
   - [x] Esta funcionalidade também deve ser implementada de forma que os registros devem ser incluídos no fim do vetor;
3. **Remoção**
    - [x] O identificador deve ser informado (remoção por valor).
    - [x] Essa funcionalidade disponibilizará espaço para um novo registro.
    - [x] Alertas de erro devem ser gerados (exemplos: identificador não encontrado, sistema sem registros cadastrados).
    - [x] A remoção de um registro em uma determinada posição fará com que todos os registros a direita da posição encontrada sejam deslocados uma posição a esquerda;
4. **Listagem**
   - [x] Exibir os registros ativos em um determinado momento. A depender do sistema, outras funções para listagem devem ser consideradas.
     - [ ] Para a gestão de alunos, também é necessário ter funções para listar alunos aprovados, reprovados, etc.
     - [ ] Para a gestão de tarefas, onde a listagem também pode ser feita para tarefas concluídas, tarefas em andamento, tarefas concluídas, etc.
     - [ ] Para a gestão da biblioteca, deve ser possível listar os livros disponíveis, emprestados, livros por editora e por ano.
     - [x] Outra possibilidade é a de exibir os dados de um único registro a partir de seu identificador, caso este esteja cadastrado;
5. **Arquivo texto**
   - [x] um arquivo de texto deverá ser criado e manipulado através das funções.
   - [-] O arquivo terá que ser acessado em todas as funcionalidades que necessitem inserir, alterar, remover ou apresentar os dados.
   - [-] Todas as informações inseridas, alteradas ou removidas deverão estar refletidas no arquivo;
