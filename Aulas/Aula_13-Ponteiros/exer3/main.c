#include <stdio.h>
#include <stdlib.h>

int main()
{
    char letra;
    char *pont;

    pont = &letra;
    *pont = 'W';

    printf("%c", letra);

    return 0;
}