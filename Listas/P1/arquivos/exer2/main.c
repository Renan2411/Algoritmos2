#include <stdio.h>

#define TAM 100

int main(){
    FILE *fp = fopen("arq.txt", "rt");
    char frase[TAM];

    fgets(frase, TAM, fp);

    printf("\nFrase do arquivo: %s\n", frase);

    fp = fclose(fp);

    return 0;
}