#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 5

void insertionRecursivo(int quant, int pos, int valor, int atual, int vet[]);

int main()
{
    int vet[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; i++)
    {
        vet[i] = rand() % 1000;
    }

    for (int i = 0; i < TAM; i++)
    {
        printf("%d\t", vet[i]);
    }

    insertionRecursivo(TAM - 1, 1, vet[1], 1, vet);
    printf("\n\n");

    for (int i = 0; i < TAM; i++)
    {
        printf("%d\t", vet[i]);
    }
    return 0;
}

void insertionRecursivo(int quant, int pos, int valor, int atual, int vet[])
{

    if (quant == 0)
    {
        return;
    }

    if ((pos - 1) < 0)
    {
        vet[pos] = valor;

        return insertionRecursivo(quant - 1, atual + 1, vet[atual + 1], atual + 1, vet);
    }

    if (valor < vet[pos - 1])
    {
        vet[pos] = vet[pos - 1];

        return insertionRecursivo(quant, pos - 1, valor, atual, vet);
    }

    vet[pos] = valor;

    return insertionRecursivo(quant - 1, atual + 1, vet[atual + 1], atual + 1, vet);
}