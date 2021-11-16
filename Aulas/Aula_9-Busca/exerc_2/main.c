#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void preencherVetor(double vet[], int tam);
int procurarVetor(double vet[], int tam, double valor);

int main()
{
    double vet[TAM];
    int pos;
    double val;

    preencherVetor(vet, TAM);

    printf("Digite um valor para procurarmos no vetor: ");
    scanf("%lf", &val);

    pos = procurarVetor(vet, TAM, val);

    printf("\n%d\n", pos);

    if (pos < 0)
    {
        printf("O valor não foi encontrado \n");
    }
    else
    {
        printf("Valor encontrado na posicao %d\n", pos);
    }

    return 0;
}

int procurarVetor(double vet[], int tam, double valor)
{

    int inicio, meio, fim;
    inicio = 0;
    fim = tam - 1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        if (vet[meio] < valor)
        {
            inicio = meio + 1;
        }
        else if (vet[meio] > valor)
        {
            fim = meio - 1;
        }
        else
        {
            return meio;
        }
    }

    return -1;
}

void preencherVetor(double vet[], int tam)
{

    for (int i = 0; i < tam; i++)
    {
        vet[i] = i + 1.1;
        printf("%lf\t", vet[i]);
    }
}