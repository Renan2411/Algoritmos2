#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B;
    int n;

    A = 1;
    B = 0;

    n = 0;

    while (A > B)
    {
        n++;

        A = 8 * n * n;
        B = n * n * n;
    }

    printf("Valor de N máximo é de %d\nCom A = %d e B = %d", n, (8*n*n), (n*n*n));

    return 0;
}