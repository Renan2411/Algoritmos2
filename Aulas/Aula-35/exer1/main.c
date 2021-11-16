#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int insertionSort(int vet[], int tam);

int main(){
    int vet[TAM];

    srand(time(NULL));

    for(int i = 0; i < TAM; i++){
        vet[i] = rand()%1000;
    }

    for(int i = 0; i < TAM; i++){
        printf("%d\t", vet[i]);
    }

    
    printf("Total de trocas: %d\n\n", insertionSort(vet, TAM));
    
     for(int i = 0; i < TAM; i++){
        printf("%d\t", vet[i]);
    }

    return 0;
}

int insertionSort(int vet[], int tam){
    int i, j;
    int aux;
    int cont = 0;

    for(i = 1; i < tam; i++){
        aux = vet[i];
        for(j = i; (j > 0) && (aux < vet[j - 1]); j--){
            vet[j] = vet[j - 1];
        }

        vet[j] = aux;

        if(j != i){
            cont++;
        }
    }

    return cont;
}