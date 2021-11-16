#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>>

#define TAM 20

int main()
{
    char frase[TAM];
    char letras[TAM] = {' '};

    int cont;
    int quant[TAM] = {0};
    int k = 0;

    

    printf("Digite uma frase: ", TAM);
    gets(frase);

    for (int i = 0; i < strlen(frase); i++)
    {
        frase[i] = tolower(frase[i]);
    }

    for (int i = 0; i < strlen(frase); i++)
    {
        cont = 0;

        for (int j = 0; j < strlen(frase); j++)
        {

            if (frase[i] == frase[j])
            {
                cont++;
            }
        }

        if (cont > quant)
        {
            quant = cont;
            
            if(){

            }
            letras[k] = frase[i];
            k++
        }
    }

    if (quant == 1)
    {

        printf("\nCada uma das letras aparece apenas 1 vez\n");
    }
    else
    {

        for (int i = 0; i < strlen(frase); i++)
        {

            if (frase[i] == l)
            {

                frase[i] = '*';
            }
        }

        printf("\nA letra com maior ocorrencia na frase foi %c, aparecendo %d vezes", l, quant);
        printf("\nFrase Digitada: %s\n", frase);
    }

    return 0;
}
