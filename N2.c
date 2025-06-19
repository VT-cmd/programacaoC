#include <stdio.h>

int main(){

    int numero1;
    int numero2;

printf("Primeiro Número: \n");
scanf("%d", &numero1);

printf("Segundo Número: \n");
scanf("%d", &numero2);

    if(numero1 >= numero2){
    printf("Número 1 é maior ou igual que o número 2\n");
}
    else
    printf("Número 2 é maior que o número 1\n");


return 0;

}