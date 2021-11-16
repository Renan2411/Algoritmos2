#include <stdio.h>
#include <stdlib.h>

unsigned int fibonacci(unsigned int N);
void fibo(unsigned int N);

int main()
{
    unsigned int N;

    printf("Digite a quantidade de termos: ");
    scanf("%d", &N);

    printf("\n\nSequência Fibonacci para %d Termos\n\n", N);

    //printf("0\t1\t");

    for(unsigned int i = 1; i <= N; i++){
        printf("%d\t", fibonacci(i));
    }

    //fibo(N);

    printf("\n\n");

    return 0;
}

void fibo(unsigned int N){
    int atual, aux, ant;

    atual = ant = 1;

    for(int i = 3; i<= N; i++){
        aux = atual;
        atual += ant;
        ant = aux;

        printf("%d\t", atual);
    }
}

unsigned int fibonacci(unsigned int N)
{

    if (N == 1)
    {
        return 0;
    }

    if (N == 2)
    {
        return 1;
    }

    return fibonacci(N - 2) + fibonacci(N - 1);
}