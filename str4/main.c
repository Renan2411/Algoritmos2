#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 20

int main()
{
    char p1[TAM], p2[TAM], p3[TAM], frase[TAM * 5];
    int i = 0;

    printf("Digite uma palavra: ");
    gets(p1);

    printf("Digite uma palavra: ");
    gets(p2);

    printf("Digite uma palavra: ");
    gets(p3);

    p1[0] = toupper(p1[0]);
    p2[0] = toupper(p2[0]);
    p3[0] = toupper(p3[0]);

    for(int j = 0; j < strlen(p1); j++, i++){
        frase[i] = p1[j];
    }
   
    frase[i] = ' ';
    i++;
  
    for(int j = 0; j < strlen(p2); j++, i++){
        
        frase[i] = p2[j];
    }

    frase[i] = ' ';
    i++;
    
    for(int j = 0; j <= strlen(p3); j++, i++){
        frase[i] = p3[j];
    }

    printf("\nFrase: %s\n", frase);

    return 0;
}
