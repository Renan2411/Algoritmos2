#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int exp);

int main(){
    int exp, base;
    int res;

    printf("Digite a base da potencia: ");
    scanf("%d", &base);

    printf("Digite o expoente: ");
    scanf("%d", &exp);

    res = potencia(base, exp);

    printf("Resultado da Potencia: %d", res);

    return 0;
}

int potencia(int base, int exp){
    int res = 1;

    if(exp == 0){
        return 1;
    }else if(base == 1){
        return base;
    }

    for(int i = 1; i <= exp; i++){
        res *= base;
    }

    return res;
}