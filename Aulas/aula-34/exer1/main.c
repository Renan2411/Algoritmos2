#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 11

void preencherVetor(char vet[]);
void bubbleSort(char vet[], int tam);

int main(){
    char vet[TAM];

    preencherVetor(vet);

    printf("%s\t", vet);

    bubbleSort(vet, TAM);

    // printf("%s\t", vet);

    for(int i = 0; i < strlen(vet); i++){
        printf("%c\t", vet[i]);
    }

    return 0;
}

void preencherVetor(char vet[]){
    printf("Preencha o Vetor\n\n");

    for(int i = 0; i < TAM; i++){
        printf("-> ");
        fflush(stdin);
       vet[i] = getchar();
    }
}

void bubbleSort(char vet[], int tam){
    char aux;
    int i;

    for( i = 0; i < tam - 1; i++){
        for(int j = 0; j < tam - 1 - i; j++){
            if(vet[j] < vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = aux;   
            }
        }
    }

}