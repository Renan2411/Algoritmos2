#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int busca_sequencial_ordenada(char valor, char vet[], int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        if(vet[i] == valor){
            return i;
        }else if(vet[i] > valor){
            return -1;
        }
    }

    return -1;
}

int main(){
    char vet[TAM];
    char valor;
    int i, posicao;

    for(i = 0; i < TAM; i++){
        vet[i] = 'a' + i;
    }

    printf("Digite um valor de caracter a buscar no vetor\n");
    scanf("%c", &valor);

    posicao = busca_sequencial_ordenada(valor, vet, TAM);

    if(posicao < 0){
        printf("Valor nao encontrado\n\n");
    }else{
        printf("Valor encontrado na posicao %d\n\n", posicao);
    }

    return 0;
}