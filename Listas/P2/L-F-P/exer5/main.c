#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    int elementos[TAM];
    int inicio;
    int fim;
    int quantidade;
} Fila;

void menu();
void inserir(Fila *pontFila);
void imprimirFila(Fila *pontFila);
void removerElemento(Fila *pontFila);
void buscarElemento(Fila *pontFila);
void inverterFila(Fila *pontFila);

int main()
{
    Fila fila;
    fila.quantidade = fila.inicio = fila.fim = 0;
    int op;

    while (1)
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            inserir(&fila);
            break;

        case 2:
            removerElemento(&fila);
            break;

        case 3:
            buscarElemento(&fila);
            break;

        case 4:
            imprimirFila(&fila);
            break;

        case 5:
            inverterFila(&fila);
            break;

        case 0:
            return 0;
            break;

        default:
            printf("Opcao Invalida!!\n\n");
            break;
        }
    }

    return 0;
}

void menu()
{
    printf("1 - Inserir\n");
    printf("2- Remover\n");
    printf("3 - Buscar\n");
    printf("4 - Imprimir\n");
    printf("5 - Inverter Fila\n");
    printf("0 - Sair\n\n");

    printf("Escolha -> ");
}

void inserir(Fila *pontFila)
{
    if (pontFila->fim == TAM)
    {
        printf("Fila Cheia\n\n");
        return;
    }

    printf("Digite um numero: ");
    scanf("%d", &pontFila->elementos[pontFila->fim]);

    pontFila->fim++;
    pontFila->quantidade++;
}

void imprimirFila(Fila *pontFila)
{

    if (pontFila->quantidade == 0)
    {
        printf("Lista Vazia\n\n");
        return;
    }

    for (int i = pontFila->inicio; i < pontFila->fim; i++)
    {
        printf("[%d]\t", pontFila->elementos[i]);
    }

    printf("\n\n");
}

void removerElemento(Fila *pontFila)
{
    if (pontFila->quantidade == 0)
    {
        printf("Lista Vazia\n\n");
        return;
    }

    pontFila->quantidade--;
    pontFila->inicio++;
}

void buscarElemento(Fila *pontFila)
{
    if (pontFila->quantidade == 0)
    {
        printf("Lista Vazia\n\n");
        return;
    }

    printf("Elemento: [%d]\n\n", pontFila->elementos[pontFila->inicio]);
}

void inverterFila(Fila *pontFila)
{
    if (pontFila->quantidade == 0)
    {
        printf("Lista Vazia\n\n");
        return;
    }

    int aux, fim;

    fim = pontFila->fim - 1;

    if(pontFila->quantidade == 1){
        return;
    }

    if (pontFila->inicio > (fim / 2))
    {
        for (int i = pontFila->inicio; i < (fim); i++)
        {
            aux = pontFila->elementos[i];
            pontFila->elementos[i] = pontFila->elementos[(fim)];
            pontFila->elementos[fim] = aux;
        }
    }
    else
    {
        for (int i = pontFila->inicio; i <= ((fim) / 2); i++)
        {
            aux = pontFila->elementos[i];
            pontFila->elementos[i] = pontFila->elementos[(fim - i + pontFila->inicio)];
            pontFila->elementos[fim - i + pontFila->inicio] = aux;
        }
    }
}