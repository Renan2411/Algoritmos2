#include <stdio.h>

int main(){
    int n1,n2,primos, p;

    primos = 0;

    printf("Digite um n�mero: ");
    scanf("%D", &n1);

    printf("Digite um n�mero: ");
    scanf("%D", &n2);

    for(int i = n1; i <=n2; i++){
        p = 0;
        for(int j = 2; j < i; j++){
            if((i % j) == 0){
                p = 1;
            }
        }
        if(p == 0){
            printf("N�mero Primo: %d\n", i);
            primos++;
        }
    }

    printf("Quantidade de N�meros Primos: %d", primos);
}
