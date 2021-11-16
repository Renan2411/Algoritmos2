#include <stdio.h>
#include <stdlib.h>

#define N 5
//PILHA

typedef struct PILHA
{
    int dados[N];
    int topo;
} PILHA;

void inicializaPilha(PILHA *p)
{
    int i;
    for (i = 0; i < N; i++)
    {
        p->dados[i] = 0;
    }
    p->topo = 0;
}

void empilha(PILHA *p)
{ //push
    int dado;
    if (p->topo == N - 1)
    { //
        printf("A Pilha esta cheia\n");
        return;
    }
    else
    {
        printf("Digite o elemento a inserir na PILHA:\n");
        scanf("%d", &dado);
        p->dados[p->topo] = dado;
        p->topo++;
        return;
    }
}

int desempilha(PILHA *p)
{ //pop
    if (p->topo == 0)
    {
        printf("Pilha vazia\n");
        return;
    }
    else
    {
        p->topo--;
        return p->dados[p->topo];
    }
}

void imprimePilha(PILHA *p)
{
    int i;
    printf("Imprimindo PILHA...\n");
    for (i = (p->topo - 1); i >= 0; i++)
    {
        printf("%d ", p->dados[i]);
    }
}

void imprimeInvertido(PILHA *p)
{
    if (p->topo == 0)
    {
        printf("Pilha vazia\n");
        return;
    }
}

int main()
{
    PILHA pilha;  

    inicializaPilha(&pilha);

    printf("\n\nPILHAS\n\n");

    empilha(&pilha);

    imprimePilha(&pilha);

    imprimeInvertido(&pilha);
}