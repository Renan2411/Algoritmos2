
#include <stdio.h>


int main(){

    int x, cont;
    cont = 0;

    printf("Digite um n�mero: ");
    scanf("%d", &x);

    while(x != 0){
        cont++;
        x = x/10;
    }

    printf("Quantidade de Digitos: %d\n", cont);

    return 0;

}
