#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float base, alt;
    float area, per, diag;

    printf("Valor da Base: ");
    scanf("%f", &base);

    printf("Valor da Altura: ");
    scanf("%f", &alt);
    

    area = (base * alt);

    per = (base * 2) + (alt * 2);

    diag = sqrt(pow(alt, 2) + pow(base, 2));

    printf("Area do Retangulo: %.2f\n", area);
    printf("Perimetro do Retangulo: %.2f\n", per);
    printf("Diagonal do Retangulo: %.2f\n", diag);

    return 0;
}