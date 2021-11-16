#include <stdio.h>
#include <stdlib.h>

int main(){
    float balanco = 10.5;
    float *pont;

    pont = &balanco;

    printf("Endereco de memoria %d tem o valor %f", pont, *pont);

    return 0;
}