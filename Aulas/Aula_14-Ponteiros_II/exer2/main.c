#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vet[5];
    int *pont = vet;

    printf("Preencha o Vetor\n");

    for (int i = 0; i < 5; i++)
    {
        printf("-> ");
        scanf("%d", (pont + i)); //Isso me mostra o endereço de memória pra onde irá o valor lido
    }

    printf("\nImprimindo o vetor normal\n");
    for (int i = 0; i < 5; i++)
    {
        if (vet[i] % 2 == 0)
        {
            printf("%d\t", &vet[i]);
        }
    }

    printf("\nImprimindo o vetor com Ponteiro\n");
    for (int i = 0; i < 5; i++)
    {
        if (pont[i] % 2 == 0)
        {
            printf("%d\t", pont[i]);
        }
    }

    printf("\nImprimindo o vetor com Aritimética Ponteiro\n");
    for (int i = 0; i < 5; i++)
    {
        if (*(pont + i) % 2 == 0)
        {
            printf("%d\t", (pont + i));
        }
    }

    return 0;
}