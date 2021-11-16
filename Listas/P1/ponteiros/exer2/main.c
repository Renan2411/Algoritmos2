#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mat[3] = {5, 9, 11};
    int *ptr;

    ptr = mat;

    printf(" %d", *ptr + 1); //mostrar (mat[0] + 1) == 6

    printf(" %d", *(ptr + 1)); //mostrar mat[1] == 9

    printf(" %d", *(ptr)); //mostra mat[0]

    printf(" %d", *(ptr + 2)); //mostra mat[2]

    return 0;
}