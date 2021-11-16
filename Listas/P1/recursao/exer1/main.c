#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int busca_binaria(int inicio, int fim, int vet[], int valor);

int main()
{
    int vet[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num, pos;

    srand(time(NULL));

    for(int i = 0; i < TAM; i++){

        printf("[%d]", vet[i]);
    }

    printf("\nDigite um valor: ");
    scanf("%d", &num);

    pos = busca_binaria(0, 9, vet, num);

    if (pos < 0)
    {
        printf("Valor não encontrado\n\n");
    }
    else
    {
        printf("Valor encontrado na posição %d\n\n", pos);
    }

    return 0;
}

int busca_binaria(int inicio, int fim, int vet[], int valor)
{

    int meio = (inicio + fim) / 2;

    if (inicio > fim)
    {
        return -1;
    }
    else if (meio == valor)
    {
        return meio;
    }
    else if (vet[meio] < valor)
    {
        return busca_binaria((meio + 1), fim, vet, valor);
    }
    else if (vet[meio] > valor)
    {
        return busca_binaria(inicio, (meio - 1), vet, valor);
    }
    
}