#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("arq.txt", "rt");
    char x;
    int quant = 0;

    while(!feof(fp)){
        x = fgetc(fp);

        quant++;
    }

    printf("Quantidade de Caracteres no arquivo: %d\n", quant);

    return 0;
}