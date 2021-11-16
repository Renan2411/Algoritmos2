#include <stdio.h>
#include <stdlib.h>


int main(){
    float base, alt;
    float area;

    printf("Digite o Valor da Base: ");
    scanf("%f", &base);

    printf("Digite o Valor da Altura: ");
    scanf("%f", &alt);

    area = (base * alt) / 2;

    printf("Área do Triângulo: %.2f", area);

    return 0;
}