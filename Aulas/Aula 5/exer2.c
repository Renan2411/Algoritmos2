#include <stdio.h>
#include <stdlib.h>

void alterarValor(float *valor){

    *valor *= 1.10;

}

int main(){
    float valor;

    printf("Digite um valor: ");
    scanf("%f", &valor);

    alterarValor(&valor);

    printf("\nAcréscimo de 10 por cento : %.2f", valor);

    return 0;
}