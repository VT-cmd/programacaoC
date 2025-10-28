#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_LIVROS 50
#define TAM_STRING 100

struct Livro{
    char nome[TAM_STRING];
    char autora[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

void limpabuffentrada(){
int c;
while (getchar() != '\n' && c != EOF);                  //LIMPA BUFFER
}

int main(){
    struct Livro biblioteca[MAX_LIVROS];
    int totalLivros= 0;
    int opcao;

do{

    printf("===============================\n");
    printf("      Biblioteca - Parte 1     \n");
    printf("===============================\n");
    printf("1 - Cadastrar novo Livron\n");
    printf("2 - Listar todos os Livros\n");
    printf("0 - sair do programa");
    printf("-------------------------------\n");
    printf("Escolha uma opção:");

    scanf("d%", &opcao);
    limpabuffentrada();


}






}