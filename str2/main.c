#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define TAM 20

int main()
{
    char p1[TAM * 3] ,p2[TAM], p3[TAM];

    printf("Digite uma palavra: ");
    gets(p1);

    printf("Digite uma palavra: ");
    gets(p2);

    printf("Digite uma palavra: ");
    gets(p3);

    p1[0] = toupper(p1[0]);
    p2[0] = toupper(p2[0]);
    p3[0] = toupper(p3[0]);
    
    strcat(p1, " ");
    strcat(p1, p2);
    strcat(p1, " ");
    strcat(p1, p3);

    printf("\nAs palavras difitadas foram: %s ", p1);

    return 0;
}
