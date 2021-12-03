#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void quick_sort(int vet[], int inicio, int fim);

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

    quick_sort(vet, 0, TAM - 1);

    printf("\n\nVetor Ordenado\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("%d\t", vet[i]);
    }

    return 0;
}

void quick_sort(int vet[], int inicio, int fim)
{
    int esq, dir;
    int pivo;
    int aux;

    esq = inicio;
    dir = fim;
    pivo = vet[inicio];

    while (esq <= dir)
    {
        while (vet[esq] < pivo && esq < fim)
        {
            esq++;
        }

        while (vet[dir] > pivo && dir > inicio)
        {
            dir--;
        }

        if (esq <= dir)
        {
            aux = vet[esq];
            vet[esq] = vet[dir];
            vet[dir] = aux;

            esq++;
            dir++;
        }
    }

    if (dir > inicio)
    {
        quick_sort(vet, inicio, dir);
    }

    if (esq < fim)
    {
        quick_sort(vet, esq, fim);
    }
}