#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para strcspn()

// ---Constantes Globais---
#define MAX_LIVROS 50
#define TAM_STRING 100

// --- Estrutura (Struct) ---
struct Livro{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};


// ---LIMPA BUFFER ---
void limpabuffentrada(){
    int c;
    while (getchar() != '\n' && c != EOF);
}

// --- Função principal (main) --- 
int main(){
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros= 0;
    int opcao;

// --- Laço principal ---
do{

     // --- Menu de opções ---
    printf("===============================\n");
    printf("      Biblioteca - Parte 1     \n");
    printf("===============================\n");
    printf("1 - Cadastrar novo Livron\n");
    printf("2 - Listar todos os Livros\n");
    printf("0 - sair do programa");
    printf("-------------------------------\n");
    printf("Escolha uma opção:");

    // --- lê a opção do usuário ---
    scanf("d%", &opcao);
    limpabuffentrada();



    // --- processamento da opção ---
    switch (opcao) {
        case 1:
            printf("--- Cadastro de Novo Livro ---\n\n");

            if (totalLivros < MAX_LIVROS) {
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

                printf("Digite o nome do autor: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

                printf("Digite a editora: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);


                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

                printf("Digite a edição: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limpabuffentrada();

                totalLivros++;


            }

    }
    








}


}