#include <stdio.h>
#include <stdlib.h>

int main()
{
    int piso, teto;
    int quantidade = 0;
    int ver;

    printf("Digite um n�mero Inicial: ");
    scanf("%d", &piso);

    printf("Digite um n�mero Final: ");
    scanf("%d", &teto);

    for(int i = piso; i <= teto; i++){
        ver = 0;
        for(int j = 2; j < i; j++){
            if((i % j) == 0){
                ver++;
            }
        }

        if(ver == 0){
            printf("%d � um n�mero Primo\n", i);
            quantidade++;
        }
    }

    printf("Quantidade de N�meros Primos: %d\n", quantidade);

    return 0;
}
