#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10

int main()
{
    int vet[TAM];
    int cont;

    srand(time(NULL));

    for(int i = 0; i < TAM; i++){
        vet[i] = rand()%11;
    }

    for(int i = 0; i < TAM; i++){
        cont = 0;
        for(int j = 0; j < TAM; j++){
            if(vet[i] == vet[j]){
                cont++;
            }
        }

        if(cont > 2){
            printf("O %d aparece mais de 2 vezes\n", vet[i]);
        }
    }

    return 0;
}