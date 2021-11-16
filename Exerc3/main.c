#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 4
#define COL 5

int main()
{
    int matriz[ROW][COL];
    int impar, par;

    par = impar = 0;

    srand(time(NULL));

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){

            matriz[i][j] = 1 + (rand() % 200);

            if((matriz[i][j] % 2) == 0){
                par++;
            }else{
                impar ++;
            }
             printf("[%d]\t", matriz[i][j]);
        }
        printf("\n");
    }


    printf("\nQuantidade de Numeros Pares: %d\n", par);
    printf("\nQuantidade de Números Impares: %d\n", impar);

    return 0;
}
