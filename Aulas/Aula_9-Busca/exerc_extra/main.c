#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int busca_binaria(int vet[], int inicio, int fim, int valor);

int main()
{
    int vet[TAM] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int valor;
    int pos;

    printf("Digite um valor: ");
    scanf("%d", &valor);

    pos = busca_binaria(vet, 0, (TAM - 1), valor);

    if(pos < 0){
        printf("Valor nao foi encontrado %d", pos);
    }else{
        printf("Valor encontrado na posicao %d", pos);
    }

    return 0;
}

int busca_binaria(int vet[], int inicio, int fim, int valor)
{

    int meio;
    int pos;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;
        
        if (valor = vet[meio])
        {
            printf("Achou\n");
            pos = busca_binaria(vet, inicio, meio - 1, valor);

            if (pos >= 0)
            {
                printf("achou de novo no inicio\n");
                printf("Foi encontrado na posicao: %d", pos);
            }

            pos = busca_binaria(vet, meio + 1, fim, valor);

            if (pos >= 0)
            {
                printf("achou de novo no fim\n");
                printf("Foi encontrado na posicao: %d", pos);
            }

            return meio;
        }
        else if (valor > vet[meio])
        {
            printf("Mexeu no início\n");
            inicio = meio + 1;
        }
        else if (valor < vet[meio])
        {
            printf("Mexeu no fim\n");
            fim = meio - 1;
        }
    }

    return -1;
}