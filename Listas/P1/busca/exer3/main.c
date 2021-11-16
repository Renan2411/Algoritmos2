#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int sequencial_recursivo(int vet[], int valor, int tam, int pos);
void preencherVetor(int vet[], int tam);

int main()
{
    int vet[TAM];
    int valor, pos;

    srand(time(NULL));
    preencherVetor(vet, TAM);

    printf("\nDigite um valor: ");
    scanf("%d", &valor);

    pos = sequencial_recursivo(vet, valor, TAM, 0);

    if (pos < 0)
    {
        printf("Valor nao existe no vetor\n");
    }
    else
    {
        printf("Valor encontrado na posicao %d", pos);
    }

    return 0;
}

int sequencial_recursivo(int vet[], int valor, int tam, int pos)
{

    if ((pos == tam))
    {
        if (vet[pos] == valor)
        {
            return (pos + 1);
        }
        else
        {
            return -1;
        }
    }

    if (vet[pos] == valor)
    {
        return (pos + 1);
    }

    return sequencial_recursivo(vet, valor, tam, (pos + 1));
}

void preencherVetor(int vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        // printf("-> ");
        // scanf("%d", &vet[i]);
        vet[i] = ((rand() % 100) + 1);
        printf("[%d]\t", vet[i]);
    }
}