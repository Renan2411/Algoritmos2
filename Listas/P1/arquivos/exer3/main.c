#include <stdio.h>
#include <stdlib.h>

#define TAM 20

int main()
{
    FILE *arq;
    char frase[TAM];
    int ver = 1;

    arq = fopen("arq.txt", "wt");

    while (ver == 1)
    {

        printf("Digite uma frase: ");
        scanf(" %[^\n]", frase);
        //fgets(frase, TAM, stdin);

        fprintf(arq, "%s", frase);

        printf("Continuar Digitando: \n1 - SIM\n0 - NAO\n->");
        scanf("%d", &ver);
    }

    arq = fclose(arq);

    return 0;
}