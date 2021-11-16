#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    char elementos[TAM];
    int topo;
    int quantidade;
} Pilha;

void push(Pilha *pontPilha);
void imprime(Pilha *pontPilha);

int main()
{
    Pilha pilha;

    pilha.quantidade = 0;
    pilha.topo = -1;

    push(&pilha);
    imprime(&pilha);

    return 0;
}

void push(Pilha *pontPilha)
{   
    for (int i = 0; i < TAM; i++)
    {
        printf("Digite um caracter: ");
        fflush(stdin);
        scanf("%c", &pontPilha->elementos[i]);

        pontPilha->topo++;
        pontPilha->quantidade++;
    }
}

void imprime(Pilha *pontPilha){
    printf("Sequencia em Ordem Invertida: ");
    for(int i = pontPilha->topo; i >= 0; i--){
        printf("%c\t", pontPilha->elementos[i]);
    }
}