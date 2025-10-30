//Ponteiros guardam o endereco da variavel que esta na memoria
//Como se a memoria fosse a casa e o ponteiro o endereco da casa

#include <stdio.h>
#include <stdlib.h>


int main(){
    char ch = 'G';
    int num = 120;
    float mult = 2.6;
    char * ptr = &ch;


        printf("%d\n", *ptr); //vai printar o edereco do conteudo da variavel de ch ('G')



        // para apontar o conteudo do ponteiro cout<< ptr; (vai apontar o endereco)
        // para apontar o 'G', cout << *ptr (vai apontar o conteudo de ch, ja que "ptr" é um ponteiro de ch)
}
