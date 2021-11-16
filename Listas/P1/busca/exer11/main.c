#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int buscarValor(int vet[], int valor, int tam);
void preencherVetor(int vet[], int tam);

int main()
{
    int vet[TAM];
    int x, ind;

    preencherVetor(vet, TAM);

    printf("\nDigite um valor para a busca: ");
    scanf("%d", &x);

    ind = buscarValor(vet, x, TAM);

    if(ind < 0){
        printf("Valor nao encontrado\n");
    }else{
        printf("Valor encontrado na posicao %d\n", ind);
    }

    return 0;
}

int buscarValor(int vet[], int valor, int tam)
{

    for (int j = 0; j < tam - 1; j++)
    {
        if ((vet[j] <= valor) && (vet[j + 1] > valor))
        {
            return j;
        }
    }

    return -1;
}

void preencherVetor(int vet[], int tam)
{

    for (int i = 0; i < tam; i++)
    {
        vet[i] = i + 2;
        printf("[%d]\t", vet[i]);
    }
}