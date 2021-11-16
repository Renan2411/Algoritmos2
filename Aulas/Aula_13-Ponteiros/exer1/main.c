#include <stdio.h>
#include <stdlib.h>

int main(){
    int num = 50;
    int *pont;

    pont = &num;

    printf("Valor no Endereço: %d", *pont);

    return 0;
}