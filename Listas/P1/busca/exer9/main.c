#include <stdio.h>
#include <stdlib.h>

int binario_decrescente(int vet[], int tam, int valor);

int main(){
    int vet[] = {5,4,3,2,1};
    int valor, pos;

    valor = 6;

    pos = binario_decrescente(vet, 5, valor);

    if(pos < 0){
        printf("O valor nao consta no vetor\n");
    }else{
        printf("O valor esta na posicao %d\n", pos);
    }

    return 0;
}

int binario_decrescente(int vet[], int tam, int valor){

    int inicio, meio, fim;
    
    inicio = 0;
    fim = tam - 1;

    while(inicio <= fim){
        meio = (inicio + fim) / 2;
        
        if(vet[meio] == valor){
            return meio;
        }else if(vet[meio] > valor){
            inicio = meio + 1;
        }else if(vet[meio] < valor){
            fim = meio - 1;
        }
    }

    return -1;
}