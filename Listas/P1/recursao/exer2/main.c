#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char inverterString(int tam, char str[]);

int main()
{
    char str[] = "celulares errados";
    int controle;

    printf("String Normal: %s\n", str);
    controle = inverterString(strlen(str), str);
    printf("String Invertida: %s", str);

    return 0;
}

char inverterString(int tam, char str[])
{
    int pos;
    char aux;
    int elem = strlen(str);

    pos = elem - tam;

    if (pos == ((elem) / 2))
    {
        return 0;
    }

    aux = str[pos];
    str[pos] = str[(elem - 1) - pos];
    str[(elem - 1) - pos] = aux;

    return inverterString((tam - 1), str);
}
