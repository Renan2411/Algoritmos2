#include <stdio.h>
#include <stdlib.h>

int achar_menor(int a, int b);
int MDC(int v1, int v2);

int main()
{
    int p, q;
    int aux, div = 1, resto, mdc;

    printf("Digite um valor: ");
    scanf("%d", &p);

    printf("Digite outro valor: ");
    scanf("%d", &q);

    mdc = MDC(p, q);
    printf("MDC = %d", mdc);

   
    return 0;
}

int MDC(int v1, int v2){
    int resto;

    if(v1 >= v2){
        resto = v1 % v2;
    }else{
        resto = v2 % v1;
    }
    
    if(resto == 0){
        return achar_menor(v1, v2);
    }

    return MDC(achar_menor(v1, v2), resto);
}

int achar_menor(int a, int b){
   if(a > b){
       return b;
   }else{
       return a;
   }
}

// Resolução em Interação
 // if (p >= q)
    // {
    //     resto = p % q;
    // }
    // else
    // {
    //     resto = q % p;
    // }

    // div = achar_menor(p, q);
    
    // while(resto != 0){
    //     aux = resto; // 22
    //     resto = div % resto; // 120 / 22 = 
    //     div = aux; //
    // }    

    // printf("O MDC: %d", div);
