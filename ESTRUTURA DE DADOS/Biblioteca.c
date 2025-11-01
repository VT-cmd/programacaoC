#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

// ---Constantes Globais---
#define MAX_LIVROS 50
#define MAX_EMPRETIMOS 100
#define TAM_STRING 100

// --- Estrutura (Struct) ---
struct Livro{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para sim, 0 para nao.
};

// --- Nova struct para armazenar informações dos empréstimos ---
struct Emprestimo {
    int indiceLivro; // Para saber qual livro do array 'biblioteca' foi emprestado.
    char nomeUsuario[TAM_STRING];
};


// ---LIMPA BUFFER ---
void limpabuffentrada(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// --- Função principal (main) --- 
int main() {
    // 1. ALOCAÇÃO DINÂMICA DE MEMÓRIA
    // Agora, em vez de array estáticos, usamos ponteiros.
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    // Usamos calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento)
    // Vantagem: inicializa toda memória com zeros. Isso significa que 'dispónível' já começa com o valor zerado
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));
   
    // Usamos malloc para o array de empréstimos. malloc(tamanho_total_em_bytes)
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRETIMOS * sizeof(struct Emprestimo));

    // VERIFICAÇÃO: é crucial verificar se alocação de memória deu certo.
    if (biblioteca == NULL || emprestimos == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1; // Retorna 1 para indicar um erro.
    }
   
    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

// --- Laço principal ---
do{

     // --- Menu de opções ---
    printf("===============================\n");
    printf("      Biblioteca - Parte 2     \n");
    printf("===============================\n");
    printf("1 - Cadastrar novo Livro\n");
    printf("2 - Listar todos os Livros\n");
    printf("3 - Realizar empréstimo\n");
    printf("4 - Listar empréstimos\n");
    printf("0 - sair do programa\n");
    printf("-------------------------------\n");
    printf("Escolha uma opção:");

    // --- lê a opção do usuário ---
    scanf("%d", &opcao);
    limpabuffentrada();



    // --- processamento da opção ---
    switch (opcao) {
        case 1:
            printf("\n--- Cadastro de Novo Livro ---\n\n");

            if (totalLivros < MAX_LIVROS) {
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf("Digite o nome do autor: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                printf("Digite a editora: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';
                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';  

                printf("Digite a edição: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limpabuffentrada();

                biblioteca[totalLivros].disponivel = 1; // Define o livro como disponível

                totalLivros++;

                printf("\nLivro cadastrado com sucesso! \n");

            } else{
                    printf("Biblioteca cheia! Não é possível cadastrar mais livros. \n");
            }

            printf("pressione Enter para continuar...\n");
            getchar(); // Pausa para ler a mensagem
            break;

        case 2: //Listagem dos livros
            printf("\n=== LISTA DE LIVROS CADASTRADOS ===\n");
            
            if(totalLivros == 0) {
                printf("Nenhum livro cadastrado. \n");

            } else {
                for (int i = 0; i < totalLivros; i++) {
                    printf("----------------------------------\n");
                    printf("LIVRO %d\n", i + 1);
                    printf("Nome: %s\n", biblioteca[i].nome);
                    printf("Autor(a): %s\n", biblioteca[i].autor);
                    printf("Status: %s\n", biblioteca[i].disponivel ? "Disponível" : "Emprestado");   
                }
                 printf("-----------------------------------\n");
            }

            printf("pressione Enter para continuar...\n");
            getchar();
            break;

        case 3: // REALIZAR EMPRESTIMO 
            printf("\n--- Realizar Empréstimo ---\n");

            if (totalEmprestimos >= MAX_EMPRETIMOS) {
                printf("Limite de empréstimos atingido!\n");

            }else {
                printf("Livros disponíveis:\n");
                int disponiveis = 0;
                for (int i = 0; i <totalLivros; i++) {
                    if (biblioteca[i].disponivel) {
                        printf("%d - %s\n", i + 1, biblioteca[i].nome);
                        disponiveis++;
                    }
                }

                if (disponiveis == 0) {
                    printf("Nenhum Livro disponível para empréstimo.\n");
                } else {
                    printf("\nDigite o número do livro que deseja: ");
                    int numLivro;
                    scanf("%d", &numLivro);
                    limpabuffentrada();

                    int indice = numLivro - 1;  // Converte para o índice do array (0 a N-1).

                    // Validação de escolha do usuário.
                    if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel) {
                        printf("Digite o nome do usuário que está pegando o livro: ");
                        fgets (emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                        emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';
                        
                        // Registra empréstimo
                        emprestimos[totalEmprestimos].indiceLivro = indice;

                        // Atualiza o status do Livro para disponível.
                        biblioteca[indice].disponivel = 0;
                
                        totalEmprestimos++;
                        printf("\nEmpréstimo realizado com sucesso!\n");
                    } else{
                        printf("\nNúmero de livro inválido ou livro indisponível.\n");
                    }
                
                }
            }
            printf("\npressione Enter para continuar...");
            getchar();
            break;

        case 4: // Listar Empréstimos.
            printf("--- Lista de Empréstimos ---\n\n");
            if (totalEmprestimos == 0) {
                printf("Nenhum empréstimo realizado.\n");
            } else {
                for (int i = 0; i < totalEmprestimos; i++) {
                    int indiceLivro = emprestimos[i].indiceLivro;
                    printf("----------------------------------\n");
                    printf("EMPRÉSTIMO %d\n", i + 1);
                    printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                    printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
                }
                printf("----------------------------------\n");
            }
            printf("\npressione Enter para continuar...");
            getchar();
            break;


        case 0: //SAIR 
            printf("Saindo do Sistema...\n");
            break;

        default: //Opção Invalida
            printf("\nOpção inválida! Tente novamente.\n");
            printf("pressione Enter para continuar...\n");
            getchar();
            break;
    }
    

} while (opcao != 0);

//2. LIBERAÇÃO DA MEMÓRIA
// Antes de terminar, é ESSENCIAl liberar a memória que foi alocada dinâmicamente.
// Isso evita "memory leaks" (vazamento de memória).
free (biblioteca);
free (emprestimos);

printf("Memória liberada com sucesso!\n");

return 0; //Fim do programa.
}