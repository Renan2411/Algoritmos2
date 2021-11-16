#include <stdio.h>
#include <stdlib.h>

int main(){
    int cont = 10, *temp, soma = 0;

    temp = &cont;
    *temp = 20;

    temp = &soma;
    *temp = cont;

    printf("cont = %d, *temp = %d, soma = %d\n", cont, *temp, soma);

    return 0;
}