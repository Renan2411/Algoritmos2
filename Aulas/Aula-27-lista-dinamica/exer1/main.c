#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento
{
    int dado;
    struct Elemento *prox;
} Elemento;

typedef struct Elemento *Lista;

void menu();
Lista *criarLista();
int listaVazia(Lista *li);
int tamanhoLista(Lista *li);
void liberar_lista(Lista *li);
void inserirELementoFinal(Lista *li);
void inserirELementoInicio(Lista *li);
void inserirElementoMeio(Lista *li);
void removerFinal(Lista *li);
void removerInicio(Lista *li);
void imprimirLista(Lista *li);
void removerMeio(Lista *li);

int main()
{
    Lista *li = criarLista();
    int op;

    while (1)
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:

            break;

        case 2:

        default:
            break;
        }
    }

    return 0;
}

void menu()
{
    printf("1- Insercao no Inicio\n");
    printf("2- Inserção no Fim\n");
    printf("3- Inserção no Meio\n");
    printf("4- Remoção no Inicio\n");
    printf("5- Remoção no Meio\n");
    printf("6- Remoção no Fim\n");
    printf("7- Busca por Elmento\n");
    printf("8- Busca por posição\n");
    printf("9- Imprimir\n");
    printf("0- Sair\n\n");

    printf("Escolha -> ");
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
    if (li == NULL)
        return 1;

    if (*li == NULL)
        return 1;

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

void liberar_lista(Lista *li)
{
    if (li != NULL)
    {
        Elemento *no;
        while ((*li) != NULL)
        {
            no = *li;

            *li = (*li)->prox;

            free(no);
        }
        free(li); //O mecanismo é liberado, não pra quem aponta
    }
}

void inserirELementoFinal(Lista *li)
{

    int num;

    Elemento *noNew = (Elemento *)malloc(sizeof(Elemento));
    Elemento *no = *li;

    if (no == NULL)
    {
        printf("Digite um numero: ");
        scanf("%d", &num);

        noNew->dado = num;
        noNew->prox = NULL;

        *li = noNew;

        return;
    }

    while (no->prox != NULL)
    {
        no = no->prox;
    }

    printf("Digite um numero: ");
    scanf("%d", &num);

    noNew->dado = num;
    noNew->prox = NULL;

    no->prox = noNew;
}

void inserirElementoInicio(Lista *li)
{

    if (li == NULL)
    {
        printf("Lista ainda não foi criada\n\n");
        return;
    }

    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);

    no->dado = num;
    no->prox = *li;

    *li = no;
}

void inserirElementoMeio(Lista *li)
{
    int pos, cont = 1;
    int num;
    Elemento *no = *li;
    Elemento *noNew = (Elemento *)malloc(sizeof(Elemento));

    if (no == NULL)
    {
        printf("Lista Vazia!!!\n\n");
        return;
    }

    imprimirLista(li);

    printf("Digite a posicao que deiseja inserir: ");
    scanf("%d", &pos);

    if(pos < 0 || pos > tamanhoLista(li)){
        printf("Posição Inválida\n\n");
        return;
    }

    if (pos == 1)
    {
        return inserirElementoInicio(li);
    }

    while (cont != (pos - 1))
    {
        cont++;
        no = no->prox;
    }

    printf("Digite o elemento: ");
    scanf("%d", &num);

    noNew->dado = num;
    noNew->prox = no->prox;

    no->prox = noNew;
}

void removerFinal(Lista *li)
{
    Elemento *no = *li;
    int fim = tamanhoLista(li);

    for (int i = 2; i < (fim); i++)
    {
        no = no->prox;
    }

    printf("Removendo %d\n\n", fim);

    free(no->prox);
    no->prox = NULL;
}

void removerInicio(Lista *li)
{
    Elemento *no = *li;

    *li = no->prox;

    free(no);
}

void removerMeio(Lista *li)
{
    int pos;
    Elemento *no = *li;
    Elemento *aux = *li;

    printf("Digite a posição a ser removida: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > tamanhoLista(li))
    {
        printf("Posicao Invalida!!!!");
        return;
    }

    for (int i = 2; i < pos; i++)
    {
        no = no->prox;
    }

    for (int i = 2; i <= pos; i++)
    {
        aux = aux->prox;
    }

    no->prox = aux->prox;

    free(aux);
}

int buscaValor(Lista *li){
    int num;
    int pos = 1;
    Elemento *no = *li;

    printf("Digite o Elemento que procura: ");
    scanf("%d", &num);

    while (no != NULL)
    {
        if(no->dado == num){
            return pos;
        }

        no = no->prox;
    }
    
    return -1;
}

void imprimirLista(Lista *li)
{
    if(listaVazia(li)){
        puts("Lista vazia");
        return;
    }   

    Elemento *no = *li;
    int cont = 0;

    if (no == NULL)
    {
        printf("Lista Vazia!!!\n\n");
        return;
    }

    while (no != NULL)
    {
        cont++;
        printf("Elemento %d = %d\n", cont, no->dado);
        no = no->prox;
    }

    printf("\n\n");
}