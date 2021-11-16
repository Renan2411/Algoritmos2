#include <stdio.h>
#include <stdlib.h>

int main()
{
    int piso, teto;
    int quantidade = 0;
    int ver;

    printf("Digite um número Inicial: ");
    scanf("%d", &piso);

    printf("Digite um número Final: ");
    scanf("%d", &teto);

    for(int i = piso; i <= teto; i++){
        ver = 0;
        for(int j = 2; j < i; j++){
            if((i % j) == 0){
                ver++;
            }
        }

        if(ver == 0){
            printf("%d é um número Primo\n", i);
            quantidade++;
        }
    }

    printf("Quantidade de Números Primos: %d\n", quantidade);

    return 0;
}
