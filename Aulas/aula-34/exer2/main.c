#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void bubbleRecursivo(int vet[], int pos, int tam);

int main()
{
    int vet[TAM];

    for (int i = 0; i < TAM; i++)
    {
        printf("-> ");
        scanf("%d", &vet[i]);
    }

    bubbleRecursivo(vet, 0, TAM - 1);

    for (int i = 0; i < TAM; i++)
    {
        printf("-> %d\t", vet[i]);
        
    }

    return 0;
}

void bubbleRecursivo(int vet[], int pos, int tam)
{

    if (tam == 0)
    {
        return;
    }

    int aux;

    if (vet[pos] > vet[pos + 1])
    {
        aux = vet[pos + 1];
        vet[pos + 1] = vet[pos];
        vet[pos] = aux;
    }

    if (pos == tam - 1)
    {
        return bubbleRecursivo(vet, 0, tam - 1);
    }

    return bubbleRecursivo(vet, pos + 1, tam);
}