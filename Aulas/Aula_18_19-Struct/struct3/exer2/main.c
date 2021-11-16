#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int cod;
    char marca[50];
    char modelo[50];
    float consumo;
} Geladeira;

void escreverStruct(Geladeira *geladeira);

int main()
{
    Geladeira geladeira;
    Geladeira *pont = &geladeira;

    // printf("Digite o codigo: ");
    // scanf("%d", pont->cod);

    pont->cod = 12;
    printf("%d", geladeira.cod);

    printf("Digite a marca: ");
    fflush(stdin);
    gets(pont->marca);

    printf("Digite o modelo: ");
    fflush(stdin);
    gets(pont->modelo);

    printf("Diigte o consumo: ");
    scanf("%f", &pont->consumo);

    escreverStruct(&geladeira);

    return 0;
}

void escreverStruct(Geladeira *geladeira)
{
    printf("Codigo: %d\n", geladeira->cod);
    printf("Marca: %s\n", geladeira->marca);
    printf("Modelo: %s\n", geladeira->modelo);
    printf("Consumo: %.2f\n", geladeira->consumo);
}