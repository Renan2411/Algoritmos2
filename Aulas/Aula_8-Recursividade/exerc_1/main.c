#include <stdio.h>
#include <stdlib.h>

int somaNaturais(unsigned int N);

int main(){
    unsigned int N, soma;

    printf("Digite um numero: ");
    scanf("%d", &N);

    soma = somaNaturais(N);

    printf("Soma de Todos os numeros ate %d = %d", N, soma);

    return 0;
}


int somaNaturais(unsigned int N){

    if (N == 0){
        return 0;
    }

    return (N + somaNaturais(N - 1));

}