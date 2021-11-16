#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

int main(){
    int matriz[ROW][COL];
    int soma = 0;

    srand(time(NULL));

    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            matriz[i][j] = rand()%101;
            printf("[%d]\t", matriz[i][j]);

            if(i == j){
                soma += matriz[i][j];
            }
        }
        printf("\n");
    }

    printf("Soma da Diagonal Principal: %d", soma);

    return 0;
}