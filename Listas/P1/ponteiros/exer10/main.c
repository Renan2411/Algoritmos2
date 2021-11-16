#include <stdio.h>

int main()
{
    static int mat[] = {90, 80, 70};
    int i;

    for (i = 0; i < 3; i++)
        // printf("%d ", *(mat + i));
        printf("%d ", (mat + i));
        
    return 0;
}