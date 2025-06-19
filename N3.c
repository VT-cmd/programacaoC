#include <stdio.h>

int main(){
    float temperatura, umidade;
    unsigned int estoque;
    unsigned int estoqueMinimo = 1000;

    printf("Qual a temperatura? \n");
    scanf("%f", &temperatura);

    printf("Qual a umidade? \n");
    scanf("%f", &umidade);

    printf("Qual o estoque? \n");
    scanf("%u", &estoque);

    if(temperatura > 30){
        printf("A temperatura está alta! \n");
    }
    else
        printf("A temperatura está dentro dos parâmetros. \n");

    if(umidade > 50){
        printf("umidade elevada! \n");
    }
    else
        printf("A umidade está dentro dos Parâmetros. \n");

    if (estoque <= estoqueMinimo){
        printf("Estoque abaixo do mínimo! \n");
    }
    else
        printf("Estoque normal. \n");


}