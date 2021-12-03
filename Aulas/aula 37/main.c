#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000

void bubbleSort(int vet[], int tam);
void insertionSort(int vet[], int tam);
void selectionSort(int vet[], int tam);

int main()
{
    int vet[TAM];

    srand(time(NULL));

    for (int i = 0; i < TAM; i++)
    {
        vet[i] = rand() % 5000;
    }

    // printf("Vetor Original\n\n");
    // for (int i = 0; i < TAM; i++)
    // {
    //     printf("[%d]\t", vet[i]);
    // }

    //bubbleSort(vet, TAM);
    //insertionSort(vet, TAM);
    selectionSort(vet, TAM);

    //printf("\n\nVetor Ordenado pelo bubble\n\n");
    //printf("\n\nVetor Ordenado pelo insertion\n\n");
    printf("\n\nVetor Ordenado pelo selection\n\n");
    for (int i = 0; i < TAM; i++)
    {
        printf("[%d]\t", vet[i]);
    }

    return 0;
}

void bubbleSort(int vet[], int tam)
{
    int aux, i;

    for (i = 0; i < TAM - 1; i++)
    {
        for (int j = 0; j < TAM - 1 - i; j++)
        {
            if (vet[j] > vet[j + 1])
            {
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;
            }
        }
    }
}

void insertionSort(int vet[], int tam){
    int i, j;
    int aux;

    for(i = 1; i < tam; i++){
        aux = vet[i];
        for(j = i; (j > 0) && (aux < vet[j - 1]); j--){
            vet[j] = vet[j - 1];
        }

        vet[j] = aux;
    }
}

void selectionSort(int vet[], int tam){
    int i, j;
    int aux, menor;

    for(i = 0; i < tam - 1; i++){
        menor = i;
        for(j = i + 1; j <= tam - 1; j++){
            if(vet[menor] > vet[j]){
                menor = j;
            }
        }

        if(menor != i){
            aux = vet[menor];
            vet[menor] = vet[i];
            vet[i] = aux; 
        }
    }

}