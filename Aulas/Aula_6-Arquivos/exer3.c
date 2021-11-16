#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq, *fp;
    int i = 0;
    char x;

    arq = fopen("codifica.txt", "rt");
    if (arq == NULL)
    {
        puts("Nao foi possivel ler o arquivo!");
        exit(1);
    }
    

    while (!feof(arq))
    {
        x = fgetc(arq);

        if(x == EOF){
            break;
        }

        if (x == 'A' || x == 'a')
        {
            x = '#';
        }
        else if (x == 'E' || x == 'e')
        {
            x = '@';
        }
        else if (x == 'i' || x == 'i')
        {
            x = '$';
        }
        else if (x == 'O' || x == 'o')
        {
            x = '&';
        }
        else if (x == 'U' || x == 'u')
        {
            x = '*';
        }

        if (i == 0)
        {

            fp = fopen("codifica.txt", "rt");

            if (fp == NULL)
            {
                fp = fclose(fp);

                fp = fopen("codifica.txt", "at");
            }
            else
            {
                fp = fclose(fp);

                fp = fopen("codifica.txt", "wt");
            }

            i = 1;
        }
        else
        {
            fp = fopen("codifica.txt", "at");
        }

        putc(x, fp);

        fclose(fp);
    }

    arq = fclose(arq);

    fp = fopen("codifica.txt", "rt");

    printf("\n");

    while (!feof(fp))
    {
        x = getc(fp);

        printf("%c", x);
    }

    printf("\n");

    fp = fclose(fp);

    return 0;
}