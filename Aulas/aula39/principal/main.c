#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void quickSort(int vet[], int inicio, int fim);
int particiona(int vet[], int inicio, int fim);

int main()
{

    int vet[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; i++)
    {
        vet[i] = rand() % 100;
    }

    printf("\n\nVetor Original\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d\t", vet[i]);
    }

    quickSort(vet, 0, TAM);

    printf("\n\nVetor Ordenado\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d\t", vet[i]);
    }

    return 0;

    return 0;
}

void quickSort(int vet[], int inicio, int fim)
{
    int pivo;

    if (fim > inicio)
    {
        pivo = particiona(vet, inicio, fim);

        quickSort(vet, inicio, pivo - 1);
        quickSort(vet, pivo + 1, fim);
    }
}

int particiona(int vet[], int inicio, int fim)
{
    int esq, dir, pivo, aux;

    esq = inicio;
    dir = fim;
    pivo = vet[inicio];

    while (esq < dir)
    {
        while (vet[esq] <= pivo)
            esq++;

        while (vet[dir] > pivo)
            dir--;

        if (esq < dir)
        {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }

    vet[inicio] = vet[dir];
    vet[dir] = pivo;
    return dir;
}