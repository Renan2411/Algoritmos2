#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>>

#define TAM 10

int main()
{
    char frase[TAM];
    char letras[TAM];
    char l;

    int i, k = 0, quant = 0;
    int cont[26] = {0};
    int quantidade[TAM] = {0};

    printf("Digite uma frase: ");
    gets(frase);

    //FOR para verificar a quantidade de cada letra
    for (i = 0; i < strlen(frase); i++)
    {
        frase[i] = toupper(frase[i]);

        if (frase[i] >= 'A' && frase[i] <= 'Z')
        {
            cont[frase[i] - 'A']++;
        }
    }

    //FOR para verificar qual a letra com maior ocorrencia
    for (i = 0; i < 26; i++)
    {
        if (quant < cont[i])
        {
            quant = cont[i];
            quantidade[k] = quant;
            letras[k] = (char)i + 'A';
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (quantidade[k] == cont[i])
        {
            l = (char)i + 'A';

            if (letras[k] != l)
            {
                k++;
                quantidade[k] = cont[i];
                letras[k] = (char)i + 'A';
            }
        }
    }

    letras[k + 1] = '\0';

    //FOR para substituir a letra de maior ocorrencia por *
    for (int i = 0; i < strlen(letras); i++)
    {
        for (int j = 0; j < strlen(frase); j++)
        {
            if (frase[j] == letras[i])
            {
                frase[j] = '*';
            }
        }
        printf("\nA letra %c apareceu %d\n", letras[i], quantidade[i]);
    }

    printf("\nFrase Digitada: %s\n", frase);
    return 0;
}
