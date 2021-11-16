#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

void procurarIntervalo(int intervalos[], int x, int tam);
void criarIntervalos(int vet[], int tam);

int main()
{
    int vet[TAM];
    int x;

    srand(time(NULL));

    criarIntervalos(vet, TAM);

    printf("\nDigite um valor: ");
    scanf("%d", &x);

    procurarIntervalo(vet, x, TAM);

    return 0;
}

void procurarIntervalo(int intervalos[], int x, int tam){
    int cont;

    cont = 0;

    for(int i = 0; i < tam; i += 2){
        if(x >= intervalos[i] && x <= intervalos[i + 1]){
            printf("%d Pertence ao intervalo %d\n", x, (i/2) + 1);
            cont++;
        }
    }

    if(cont == 0){
        printf("%d nao pertence a nenhum intervalo\n", x);
    }
}

void criarIntervalos(int vet[], int tam)
{

    for (int i = 0; i < tam; i += 2)
    {
        vet[i] = rand() % 10000 + 1;
        vet[i + 1] = rand() % 10000 + 1;

        while (vet[i + 1] <= vet[i])
        {
            vet[i + 1] = rand() % 10000 + 1;
        }

        printf("[%d]\t[%d]\t", vet[i], vet[i + 1]);
    }
}