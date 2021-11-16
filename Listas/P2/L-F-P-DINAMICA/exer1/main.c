#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    int valor;
    struct Elemento *prox;
} Elemento;

typedef struct Elemento *Lista;

Lista *criarLista();
int listaVazia(Lista *li);
int tamanhoLista(Lista *li);
void liberarLista(Lista *li);
int lerValor();
void inserirElementoFinal(Lista *li);
void igual(Lista *l1, Lista *l2);
Lista *copia(Lista *li);
void imprimirLista(Lista *li);

int main()
{
    Lista *l1 = criarLista();
    Lista *l2 = criarLista();

    for (int i = 1; i <= 5; i++)
    {
        inserirElementoFinal(l1);
    }

    printf("Tamanho lista 1: %d\n\n", tamanhoLista(l1));

    *l2 = copia(l1);
    imprimirLista(l2);

    igual(l1, l2);

    imprimirLista(l1);

    imprimirLista(l2);

    free(l1);
    free(l2);

    return 0;
}

Lista *criarLista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));

    if (li != NULL)
    {
        *li = NULL;
    }

    return li;
}

int listaVazia(Lista *li)
{
    if (li = NULL)
    {
        return 0;
    }

    if (*li == NULL)
    {
        return 1;
    }

    return 0;
}

int tamanhoLista(Lista *li)
{
    if (li == NULL)
    {
        return 0;
    }

    int cont = 0;
    Elemento *no = *li;

    while (no != NULL)
    {
        cont++;
        no = no->prox;
    }

    return cont;
}

void liberarLista(Lista *li)
{
    Elemento *no;

    while ((*li) != NULL)
    {
        no = *li;

        *li = (*li)->prox;
        free(no);
    }

    free(li);
}

int lerValor()
{
    int num;

    printf("Digite um numero: ");
    scanf("%d", &num);

    return num;
}

void inserirElementoFinal(Lista *li)
{
    Elemento *noNew = (Elemento *)malloc(sizeof(Elemento));

    if ((*li) == NULL)
    {
        noNew->valor = lerValor();
        noNew->prox = NULL;

        *li = noNew;
        return;
    }

    Elemento *no = *li;

    while (no->prox != NULL)
    {
        no = no->prox;
    }

    noNew->valor = lerValor();
    noNew->prox = NULL;

    no->prox = noNew;
}

void igual(Lista *l1, Lista *l2)
{
    Elemento *no1 = *l1;
    Elemento *no2 = *l2;
    int tamLista1 = tamanhoLista(l1);
    int tamLista2 = tamanhoLista(l2);

    if (tamLista1 != tamLista2)
    {
        printf("As listas sao diferentes\n\n");
        return;
    }

    while ((no1->prox != NULL) && (no2->prox != NULL))
    {

        if (no1->valor != no2->valor)
        {
            printf("As listas são diferentes\n\n");
            return;
        }
        no1 = no1->prox;
        no2 = no2->prox;
    }

    printf("As listas sao iguais\n\n");
}

Lista *copia(Lista *li)
{
    Elemento *no = *li;

    return no;
}

void imprimirLista(Lista *li)
{
    Elemento *no = *li;

    while (no != NULL)
    {
        printf("%d\t", no->valor);

        no = no->prox;
    }

    printf("\n\n");
}