#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[3][3];
    int *pont;

    pont = mat;

    for (int i = 0; i < (3 * 3); i++)
    {
        *(pont + i) = i;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("[%d]\t", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < 3 * 3; i++)
    {
        printf("[%d]\t", *(pont + i));
    }

    return 0;
}