#include <stdio.h>
#include <stdlib.h>

#define TAM 100

typedef struct
{
    int elementos[TAM];
    int quantidade;
} Lista;

void menuEscolha();
void preencherLista(Lista *pontLista);
void mostrarElementos(Lista *pontLista);
int lerValor();
void inserirElementoInicio(Lista *pontLista);
void inserirElementoFinal(Lista *pontLista);
void inserirEntreElementos(Lista *pontLista, int fim);
void removerElementoInicio(Lista *pontLista);
void removerEntreElementos(Lista *pontLista, int inicio);
int buscarElemento(Lista *pontLista);

int main()
{
    Lista lista, *pontLista;
    int op = 1;
    int ini, fim;
    int pos;

    pontLista = &lista;
    pontLista->quantidade = 0;

    while (1)
    {

        mostrarElementos(&lista);

        printf("\nQauntidade: %d\n", lista.quantidade);

        menuEscolha();
        scanf("%d", &op);

        if (op != 1 && op != 2 && op != 3 && op != 0 && pontLista->quantidade == 0)
        {
            printf("Precisa Preencher a lista\n\n");
            preencherLista(&lista);
        }
        else
        {
            switch (op)
            {
            case 1:
                preencherLista(&lista);
                break;
            case 2:
                inserirElementoInicio(&lista);
                break;

            case 3:
                inserirElementoFinal(&lista);
                break;

            case 4:
                printf("Digite o valor inicial: ");
                scanf("%d", &ini);

                printf("Diige o valor final: ");
                scanf("%d", &fim);

                if (fim == (ini + 1) && ini < fim)
                {
                    inserirEntreElementos(&lista, fim);
                }
                else
                {
                    printf("Valores não aceitos, tente novamente\n\n");
                }

                break;

            case 5:
                removerElementoInicio(&lista);
                break;

            case 6:
                lista.quantidade--;
                break;

            case 7:
                printf("Diige a posicao a ser removida: ");
                scanf("%d", &fim);

                if (fim == (ini + 1) && ini < fim)
                {
                    removerEntreElementos(&lista, fim);
                }
                else
                {
                    printf("Valores não aceitos, tente novamente\n\n");
                }
                break;

            case 8:
                break;

            case 9:
                pos = buscarElemento(&lista);

                if (pos < 0)
                {
                    printf("Valor não encontrado\n\n");
                }
                else
                {
                    printf("Valor encontrado na posicao %d\n\n", pos);
                }
                break;

            case 0:
                return 0;

            default:
                printf("Opção Desconhecida, tente novamente\n\n");
                break;
            }
        }
    }

    return 0;
}

void menuEscolha()
{
    printf("============== MENU ============== \n");
    printf("1- Preencher Lista\n");
    printf("2- Inserção de elemento no início\n");
    printf("3- Inserção de elemento no final\n");
    printf("4- Inserção de elemento entre elementos\n");
    printf("5- Remoção de elemento inicial\n");
    printf("6- Remoção de elemento final\n");
    printf("7- Remoção de elemento entre elementos\n");
    printf("8- Impressão de Lista\n");
    printf("9- Buscar Elemento na Lista\n");
    printf("0- Sair\n\n");
    printf("Escolha uma opção -> ");
}

void preencherLista(Lista *pontLista)
{

    if (pontLista->quantidade == TAM)
    {
        printf("Lista Cheia\n\n");
        return;
    }

    int inicio = pontLista->quantidade;
    int op, ver = 0;

    for (int i = inicio; i < TAM; i++)
    {
        if (i % 10 == 0 && i != 0 && ver != 0)
        {
            printf("\n0 - Sair\n");
            printf("1- Continuar Preenchendo Lista\n");
            printf("Escolha um opcao -> ");
            scanf("%d", &op);

            if (op == 0)
            {
                break;
            }
        }

        ver++;

        printf("Digite um número: ");
        scanf("%d", &pontLista->elementos[i]);

        pontLista->quantidade++;
    }
}

void mostrarElementos(Lista *pontLista)
{
    printf("Lista: \n");
    for (int i = 0; i < pontLista->quantidade; i++)
    {
        printf("[%d]\t", pontLista->elementos[i]);
    }
    printf("\n");
}

int lerValor()
{
    int num;

    printf("Digite o valor: ");
    scanf("%d", &num);

    return num;
}

void inserirElementoInicio(Lista *pontLista)
{
    if (pontLista->quantidade == TAM)
    {
        printf("Lista Cheia\n\n");
        return;
    }

    int i;

    for (i = pontLista->quantidade; i > 0; i--)
    {
        pontLista->elementos[i] = pontLista->elementos[i - 1];
    }
    pontLista->elementos[i] = lerValor();
    pontLista->quantidade++;
}

void inserirElementoFinal(Lista *pontLista)
{
    if (pontLista->quantidade == TAM)
    {
        printf("Lista Cheia\n\n");
        return;
    }

    pontLista->elementos[pontLista->quantidade] = lerValor();
    pontLista->quantidade++;
}

void inserirEntreElementos(Lista *pontLista, int fim)
{

    if (pontLista->quantidade == TAM)
    {
        printf("Lista Cheia\n\n");
        return;
    }

    if (pontLista->quantidade == 0)
    {
        printf("Necessário preencher lista\n\n");
        preencherLista(pontLista);
        mostrarElementos(pontLista);
    }

    int i;

    for (i = pontLista->quantidade; i > fim; i--)
    {
        pontLista->elementos[i] = pontLista->elementos[i - 1];
    }

    pontLista->elementos[i] = lerValor();
    pontLista->quantidade++;
}

void removerElementoInicio(Lista *pontLista)
{

    for (int i = 1; i < pontLista->quantidade; i++)
    {
        pontLista->elementos[i - 1] = pontLista->elementos[i];
    }

    pontLista->quantidade--;
}

void removerEntreElementos(Lista *pontLista, int inicio)
{

    for (int i = (inicio + 1); i < pontLista->quantidade; i++)
    {
        pontLista->elementos[i - 1] = pontLista->elementos[i];
    }

    pontLista->quantidade--;
}

int buscarElemento(Lista *pontLista)
{

    int valor = lerValor();

    for (int i = 0; i < pontLista->quantidade; i++)
    {
        if (pontLista->elementos[i] == valor)
        {
            return i;
        }
    }

    return -1;
}