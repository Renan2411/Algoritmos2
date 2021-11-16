#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 80

void selectionSort(float vet[], int tamanho);

int main()
{
    float vet[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; i++)
    {
        vet[i] = rand()%1000 + 0.01;
    }

    selectionSort(vet, TAM);

    for (int i = 0; i < TAM; i++)
    {
        printf("[%.2f]\t", vet[i]);
    }

    return 0;
}

void selectionSort(float vet[], int tamanho)
{
    int i, j, maior;
    float troca;

    for (i = 0; i <= tamanho - 2; i++)
    {
        maior = i;

        for (j = i + 1; j <= tamanho - 1; j++)
        {
            if (vet[j] > vet[maior])
            {
                maior = j;
            }
        }

        if (maior != i)
        {
            troca = vet[i];
            vet[i] = vet[maior];
            vet[maior] = troca;
        }
    }
}