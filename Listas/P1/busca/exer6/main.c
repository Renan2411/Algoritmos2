#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARACTERES 50
#define TAM 3

struct aluno
{
    int number;
    char name[CARACTERES];
};

int busca_binaria(struct aluno vet[], int valor, int tam);
void preencherVetor(struct aluno vet[], int tam);

int main()
{
    struct aluno dados[TAM];
    int valor, pos;

    preencherVetor(dados, TAM);

    printf("Digite o numero do aluno buscado: ");
    scanf("%d", &valor);

    pos = busca_binaria(dados, valor, TAM);

    if (pos < 0)
    {
        printf("Aluno não encontrado\n");
    }
    else
    {
        printf("O aluno chama %s\n", dados[pos].name);
    }

    return 0;
}

int busca_binaria(struct aluno vet[], int valor, int tam)
{
    int inicio, meio, fim;
    inicio = 0;
    fim = tam - 1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (vet[meio].number == valor)
        {
            return meio;
        }
        else if (vet[meio].number < valor)
        {
            inicio = meio + 1;
        }
        else if (vet[meio].number > valor)
        {
            fim = meio - 1;
        }
    }

    return -1;
}

void preencherVetor(struct aluno vet[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("Digite o Nome do aluno: ");
        fflush(stdin);
        scanf("%s", &vet[i].name);

        vet[i].number = i + 1;
    }
}