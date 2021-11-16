#include <stdio.h>
#include <stdlib.h>

int soma_recursiva(int num, int soma);

int main(){
    int num, soma = 0;

    printf("Digite um Numero: ");
    scanf("%d", &num);

    soma = soma_recursiva(num, soma);

    printf("Soma dos Digitos: %d\n", soma);

    return 0;
}

int soma_recursiva(int num, int soma){

    if(num < 10){
        soma += num;
        return soma;
    }

    soma += num % 10;
    return soma_recursiva((num / 10), soma);
}






//Com String
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <string.h>

// #define TAM 100

// int soma_recursiva(int num, int tam, int soma);

// int main(){
//     char num[100];
//     int soma = 0;

//     printf("Digite um numero: ");
//     gets(num);

//     soma = soma_recursiva(atoi(num), pow(10, strlen(num)), soma);

//     printf("Soma dos Dígitos: %d\n", soma);

//     return 0;
// }

// int soma_recursiva(int num, int tam, int soma){

//     if(tam == 0){
//         return soma;
//     }

//     soma += num / tam;
//     return soma_recursiva((num % tam), (tam / 10), soma);
// }