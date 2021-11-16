#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct
{
    int quantidade;
    int topo;
    int elemento[TAM];
} Pilha;

void menu();
int lerElemento();
void push(Pilha *pontPilha);
void buscarPilha(Pilha *pontPilha);
void imprimirPilha(Pilha *pontPilha);
void pop(Pilha *pontPilha);

int main()
{
    Pilha pilha;
    int op;

    pilha.topo = -1;
    pilha.quantidade = 0;

    while (1)
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            push(&pilha);
            break;

        case 2:
            pop(&pilha);
            break;

        case 3:
            buscarPilha(&pilha);
            break;

        case 4:
            imprimirPilha(&pilha);
            break;

        case 0:
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}

void menu()
{
    printf("==========MENU==========\n\n");
    printf("1 - Push\n");
    printf("2 - Pop\n");
    printf("3 - Buscar\n");
    printf("4 - Imprimir\n");
    printf("0 - Sair\n\n");

    printf("Escolha-> ");
}

int lerElemento()
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    return num;
}

void push(Pilha *pontPilha)
{
    if (pontPilha->quantidade == TAM)
    {
        printf("Pilha Cheia\n\n");
        return;
    }

    pontPilha->elemento[pontPilha->quantidade] = lerElemento();
    pontPilha->quantidade++;
    pontPilha->topo++;
}

void pop(Pilha *pontPilha)
{
    if (pontPilha->topo < 0)
    {
        printf("Pilha Vazia\n\n");
        return;
    }

    pontPilha->topo--;
    pontPilha->quantidade--;
}

void buscarPilha(Pilha *pontPilha)
{
    int num;

    if (pontPilha->topo < 0)
    {
        printf("Pilha Vazia\n\n");
        return;
    }

    num = lerElemento();

    if (pontPilha->elemento[pontPilha->topo] == num)
    {
        printf("Este elemento esta na pilha\n\n");
    }
    else
    {
        printf("Este elemento nao esta na pilha\n\n");
    }
}

void imprimirPilha(Pilha *pontPilha)
{

    if (pontPilha->topo < 0)
    {
        printf("Pilha Vazia\n\n");
        return;
    }

    for (int i = pontPilha->topo; i >= 0; i--)
    {
        printf("[%d]\n", pontPilha->elemento[i]);
    }

    printf("\n\n");
}