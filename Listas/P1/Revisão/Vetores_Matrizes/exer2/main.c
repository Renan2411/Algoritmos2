#include <stdio.h>
#include <stdlib.h>

#define ROW 10
#define COL 7

int main()
{
    int matriz[ROW][COL];

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            matriz[i][j] = i * j;
            printf("[%d]\t", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}