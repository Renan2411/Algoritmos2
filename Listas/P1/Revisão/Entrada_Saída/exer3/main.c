#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14

int main()
{
    float r;
    float vol, area, comp;

    printf("Valor do Raio: ");
    scanf("%f", &r);

    area = PI * pow(r, 2);

    vol = (4 * PI * pow(r, 3)) / 3;

    comp = 2 * PI * r;

    printf("Area do Circulo: %.2f\n", area);
    printf("Volume do Circulo: %.2f\n", vol);
    printf("Comprimento do Circulo: %.2f\n", comp);

    return 0;
}