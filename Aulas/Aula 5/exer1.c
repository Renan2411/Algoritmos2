#include <stdio.h>
#include <stdlib.h>

#define TAM 10

void lerVetor(int vet[]);
int acharVetor(int vet[], int valor);

int main(){
    int vet[TAM];
    int quant, valor;

    lerVetor(vet);

    printf("Digite um valor: ");
    scanf("%d", &valor);

    quant = acharVetor(vet, valor);

    printf("Quantidade de Ocorrências do valor no vetor: %d", quant);
    
    return 0;
}

void lerVetor(int vet[]){

    for(int i = 0; i < TAM; i++){
        printf("-> ");
        scanf("%d", &vet[i]);
    }
}

int acharVetor(int vet[], int valor){

    int quant = 0;

    for(int i = 0; i < TAM; i++){
        if(vet[i] == valor){
            quant++;
        }
    }

    return quant;
}