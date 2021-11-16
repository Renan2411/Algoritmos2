#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

int main()
{
    char p1[TAM], p2[TAM];

    printf("Digite uma Palavra: ");
    gets(p1);

    printf("Digite outra Palavra: ");
    gets(p2);

    if (strcmp(p1, p2) == 0){
        printf("\nAs palavras sao iguais\n");
    }
    else{
        printf("\nAs palavras sao diferentes\n");
    }

    return 0;
}
