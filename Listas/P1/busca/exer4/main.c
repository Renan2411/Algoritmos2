#include <stdio.h>
#include <stdlib.h>

int main(){
    int inicio, fim, meio;
    int cont = 0;

    inicio = 0;
    fim = 50000;
    meio = (inicio + fim) / 2;

    while(inicio <= fim){

        // inicio = meio + 1;
        fim = meio - 1;
         meio = (inicio + fim) / 2;
         cont++;

    }

    printf("Quantidade %d", cont);

    return 0;
}