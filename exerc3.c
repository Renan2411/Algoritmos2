#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 5
#define ROW 4

int main(){
    int matriz[ROW][COL], pares, impares;

    pares = impares = 0;


    srand(time(NULL));

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            matriz[i][j] = rand()%100;
            if((matriz[i][j] % 2 == 0)){
                pares++;
            }else{
                impares++;
            }
        }
    }

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
                printf("[%d]\t", matriz[i][j]);
        }
        printf("\n");
    }

    printf("Quantidade de Números Pares: %d\n", pares);
    printf("Qauntidade de Números Ímpares: %d\n", impares);
}
