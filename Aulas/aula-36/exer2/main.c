#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void selectionRecursivo(int vet[], int tam, int pos, int atual, int menor);

int main()
{

    int vet[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; i++)
    {
        vet[i] = rand() % 1000;
    }

    selectionRecursivo(vet, TAM, 1, 0, 0);

    for (int i = 0; i < TAM; i++)
    {
        printf("[%d]\t", vet[i]);
    }

    return 0;

    return 0;
}

void selectionRecursivo(int vet[], int tam, int pos, int atual, int menor)
{

    if (atual > tam - 2)
    {
        return;
    }

    if (pos > (tam - 1))
    {
        if (menor != atual)
        {
            int troca = vet[menor];
            vet[menor] = vet[atual];
            vet[atual] = troca;
        }

        return selectionRecursivo(vet, tam, atual + 2, atual + 1, atual + 1);
    }

    if (vet[menor] > vet[pos])
    {
        menor = pos;
    }

     return selectionRecursivo(vet, tam, pos + 1, atual, menor);
}