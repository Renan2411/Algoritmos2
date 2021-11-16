#include <stdio.h>
#include <stdlib.h>

void identificarRecursivo(int inicio, int fim);

int main()
{
    int inicio, fim;

    printf("Digite um número: ");
    scanf("%d", &inicio);

    printf("Digite outro numero: ");
    scanf("%d", &fim);

    if (inicio >= fim)
    {
        identificarRecursivo(fim, inicio);
    }
    else
    {
        identificarRecursivo(inicio, fim);
    }

    return 0;
}

void identificarRecursivo(int inicio, int fim)
{

    if (inicio == fim)
    {
        if ((fim % 2) == 0)
        {
            printf("%d e par\n", fim);
        }
    }
    else
    {
        if ((inicio % 2) == 0)
        {
            printf("%d e par\n", inicio);
            identificarRecursivo((inicio + 1), fim);
        }
        else
        {
            identificarRecursivo((inicio + 1), fim);
        }
    }
}