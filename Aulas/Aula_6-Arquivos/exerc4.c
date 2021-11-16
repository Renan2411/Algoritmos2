#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 100

void esvaziarString(char str[]);
void removerPontuacao(char str[]);

int main()
{
    FILE *arq = fopen("teste.txt", "rt");
    char teste[TAM];
    char palavra[TAM], search[TAM];
    int i, j;
    int quant, ver;

    char x;

    quant =  j = 0;
    ver = 1;

    printf("Digite uma palavra: ");
    gets(palavra);

    /*for (i = 0; i < strlen(palavra); i++)
    {
        palavra[i] = toupper(palavra[i]);
    }*/

    while (!feof(arq))
    {

        fscanf(arq, "%s", search);

        removerPontuacao(search);

        if (fgetc(arq) == '\n')
        {
            ver++;
        }

        if (strcmp(palavra, search) == 0)
        {
            quant++;
            printf("Aparece na linha %d\n", ver);
        }

        /*fgets(teste, 100, arq);

        ver++;
        for (i = 0; i < strlen(teste); i++)
        {
            if ((teste[i] != ',') && (teste[i] != ' ') && (teste[i] != '\n') && (teste[i] != '?') && (teste[i] != '!'))
            {

                search[j] = toupper(teste[i]);
                j++;
            }
            else
            {
                search[j] = '\0';

                if (strcmp(palavra, search) == 0)
                {
                    quant++;
                    printf("Aparece na linha %d\n", ver);
                }
                j = 0;

                esvaziarString(search);
            }
        }*/
    }

    printf("\nA palavra %s aparece %d vezes\n\n", palavra, quant);

    arq = fclose(arq);

    return 0;
}

void esvaziarString(char str[])
{
    int i;

    for (i = 0; i < strlen(str); i++)
    {
        str[i] = ' ';
    }
    str[i] = ' ';
}

void removerPontuacao(char str[])
{
    int ind = strlen(str) - 1;

    switch (str[ind])
    {
    case '.':
    case ',':
    case '!':
    case '?':
    case ';':
    case '"':
    case '(':
    case ')':
    case '\'':
    case ':':
        str[ind] = '\0';
        break;
    }
}