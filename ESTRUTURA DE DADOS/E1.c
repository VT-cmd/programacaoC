#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float media;

} aluno;

int main(){

aluno aluno1 = {"Alberto", 15, 9.5};

printf("Aluno: %s\n", aluno1.nome);
printf("Idade: %d\n", aluno1.idade);
printf("Média: %.2f\n", aluno1.media);




}



