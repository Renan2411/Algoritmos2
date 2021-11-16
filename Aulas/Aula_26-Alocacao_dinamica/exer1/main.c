#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int *pont;
    int quant;

    printf("Qauntidade de elementos: ");
    scanf("%d", &quant);

    pont = (int*) malloc(quant * sizeof(int));

    if(!pont){
        printf("Deu algum error meu amigo\n\n");
        exit(1);
    }

    printf("Digite os valores\n\n");
    for(int i = 0; i < quant; i++){
        printf("-> ");
        scanf("%d", (pont + i)); //Dessa forma consigo usar ponteiro no scanf, visto que isso mostra o espaço da memória para que ele está apontando
    }

    printf("Valores ao quadrado\n\n");
    for(int i = 0; i < quant; i++){
        //Aqui eu uso o (*) para acessar o valor do espaço em que ele aponta;
        printf("%d\n", (*(pont + i)) * (*(pont + i)));
    }

    return 0;
}