#include <stdio.h>
#include <stdlib.h>

typedef struct Aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
} Aluno;

//Definindo elemento de um FILA
typedef struct Elemento
{
    Aluno dados;
    struct Elemento *prox;
} Elemento;

//Definição da FILA
typedef struct
{
    Elemento *inicio;
    Elemento *fim;
    int quantidade;
} Fila;

//Criando FILA
Fila *cria_fila()
{
    Fila *fi = (Fila *)malloc(sizeof(Fila));

    if (fi != NULL)
    {
        fi->fim = NULL;
        fi->inicio = NULL;
        fi->quantidade = 0;
    }

    return fi;
}

//Destruindo uma fila
void libera_fila(Fila *fi)
{
    if (fi != NULL)
    {
        Elemento *no;

        while (fi->inicio != NULL)
        {
            no = fi->inicio;
            fi->inicio = fi->inicio->prox;
            free(no);
        }
        free(fi);
    }
}

//Verificando se uma fila está vazia
int fila_vazia(Fila *fi)
{
    if (fi == NULL)
    {
        return 1;
    }

    if (fi->inicio == NULL)
    {
        return 1;
    }

    if (fi->quantidade == 0)
    {
        return 1;
    }

    return 0;
}

//inserindo elemento na fila
int insere_fila(Fila *fi, Aluno al)
{
    //verifica se existe a fila
    if (fi == NULL)
    {
        return 0;
    }

    Elemento *no = (Elemento *)malloc(sizeof(Elemento));

    //Verifica se conseguir alocar a memória
    if (no == NULL)
    {
        return 0;
    }

    no->dados = al;  //atribuindo as informações na fila
    no->prox = NULL; //fazendo o proximo da fila apontar para o chao (NULL)

    //Verifica se a fila está vazia
    if (fi->fim == NULL)
    {
        fi->inicio = no; //se sim, incializo ela com o endereço que acabei de alocar
    }
    else
    {
        fi->fim->prox = no; //se não, faço o elemento final apontar para o endereço alocado
    }

    fi->fim = no;     //atualizo o fim
    fi->quantidade++; //incremento a quantidade

    return 1;
}

//Remoção da fila
int remove_fila(Fila *fi)
{
    if (fila_vazia(fi))
    {
        return 0;
    }

    Elemento *no = fi->inicio;     //salvando o endereço do elemento que será removido
    fi->inicio = fi->inicio->prox; //ajustando o inicio da fila

    if (fi->inicio == NULL)
    { //fila ficou vazia
        fi->fim = NULL;
    }

    free(no); //liberando a memória alocada

    fi->quantidade--;

    return 1;
}

//Fazendo a busca na fila
struct Aluno busca_fila(Fila *fi)
{
    Aluno al;

    if (fila_vazia(fi))
    {
        al.matricula = 0; //se a fila está vazia retornamos o dado com matricula = 0
        return al;
    }

    al = fi->inicio->dados;
    return al;
}

//imprensão da fila
void imprime_fila(Fila *fi)
{
    if (fila_vazia(fi))
    {
        printf("Fila vazia");
        return;
    }

    Elemento *no = fi->inicio;

    while (no != NULL)
    {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas: %.2f %.2f %.2f\n\n", no->dados.n1, no->dados.n2, no->dados.n3);

        no = no->prox;
    }
}

void menu()
{
    printf("1 - Inserir Elemento\n");
    printf("2 - Remover Elemento\n");
    printf("3 - Buscar\n");
    printf("4 - Imprimir Fila\n");
    printf("5 - Tamanho da Fila\n");
    printf("0 - Sair\n\n");
    printf("Escolha -> ");
}

int main()
{
    Fila *fi = cria_fila();
    Aluno al;
    int op;

    while (1)
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            printf("Digite a matricula: ");
            scanf("%d", &al.matricula);

            printf("Digite o nome: ");
            fflush(stdin);
            gets(al.nome);

            printf("Digite a nota 1: ");
            scanf("%f", &al.n1);

            printf("Digite a nota 2: ");
            scanf("%f", &al.n2);

            printf("Digite a nota 3: ");
            scanf("%f", &al.n3);

            insere_fila(fi, al);

            break;

        case 2:
            op = remove_fila(fi);

            if (op == 0)
            {
                printf("A fila esta vazia\n\n");
            }
            else
            {
                printf("Elemento removido com sucesso\n\n");
            }

            break;

        case 3:
            al = busca_fila(fi);

            if (al.matricula == 0)
            {
                printf("Fila Vazia");
            }
            else
            {
                printf("Matricula: %d\n", al.matricula);
                printf("Nome: %s\n", al.nome);
                printf("Notas: %.2f %.2f %.2f\n\n", al.n1, al.n2, al.n3);
            }
            break;

        case 4:
            imprime_fila(fi);
            break;

        case 5:
            printf("Tamanho: %d\n\n", fi->quantidade);
            break;

        case 0:
            libera_fila(fi);
            return 0;
            break;

        default:
            printf("Opcao invalida");
            break;
        }
    }

    return 0;
}
