#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 20

int main()
{
    int vet[TAM], pares[TAM], impares[TAM];
    int *pont, *par, *impar;
    int contPar, contImpar;

    contPar = contImpar = 0;
    pont = vet;

    srand(time(NULL));

    printf("vetor\n");
    for (int i = 0; i < TAM; i++)
    {
        *(pont + i) = (rand() % 100) + 1;
        printf("[%d]\t", *(pont + i));
    }

    par = pares;
    impar = impares;

    for (int i = 0; i < TAM; i++)
    {

        if ((*(pont + i) % 2) == 0) //Se for par
        {
            *(par + contPar) = *(pont + i);
            contPar++;
        }
        else //Se for ímpar
        {
            *(impar + contImpar) = *(pont + i);
            contImpar++;
        }
    }

    printf("\nValores Pares\n");
    for (int i = 0; i < contPar; i++)
    {
        printf("[%d]\t", *(par + i));
    }

    printf("\nValores Impares\n");
    for (int i = 0; i < contImpar; i++)
    {
        printf("[%d]\t", *(impar + i));
    }

    return 0;
}
