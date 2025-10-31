/*MALLOC ALOCA UM ESPAÇO TEMPORÁRIO PARA UM PONTEIRO NA MEMÓRIA DO COMPUTADOR CONFORME SUA NECESSIDADE
(ALOCAÇÃO DINÂMICA)*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int *batata;

    //batata = malloc(sizeof(int));
    batata = calloc(1, sizeof(int));
    
     //batata != NULL
    if (batata){
        printf("memoria alocada\n");
        printf("batata: %d\n", *batata);
        *batata= 50;
        printf("batata: %d\n", *batata);


    }

    else{
        printf("erro ao alocar memoria\n");
    }

return 0;



}

int main(){

    int *a, b;                  //declaracao das variaveis *a tipo ponteiro
    b = 50;
    a = malloc(sizeof(int));    //alocacao da memoria do tamanho de um inteiro para 'a'
    *a = 20;                    //*a aponta para 'a' que recebe o valor de 20
    printf("a: %d\n", *a);
    free(a);                    //limpa o armazenamento ('a' deixou de ser 20)
    a = &b;                     //'a' agora recebe o endereco de 'b'
    printf("a: %d\n", *a);




}