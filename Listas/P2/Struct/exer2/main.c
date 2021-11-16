#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 5
#define CARACTERES 100

typedef struct
{
    int cod;
    char doado;
    char nome[CARACTERES];
    char autor[CARACTERES];
    char editora[CARACTERES];
    int numPag;
} Livro;

void menu();
void menuAreas();
int lerCod();
void getDados(Livro *pontLivro[], int pos); //Também serve para alterar os dadaos de um livro existente
void armazenaDados(Livro *pontLivro[], int pos);
int buscarLivro(Livro *pontLivro[], int quant);
int buscarLivroNome(Livro *pontLivro[], int quant);
void excluirLivro(Livro *pontLivro[], int pos, int quant);
void mostrarLivro(Livro *pontLivro[], int pos);
void listarLivros(Livro *pontLivro[], int quant);

int main()
{
    Livro cienciasExatas[TAM], cienciasHumanas[TAM], cienciasBiomedicas[TAM];
    int op, pos;
    int ce, ch, cb;

    ce = cb = ch = 0;

    while (1)
    {

        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            while (op != 0)
            {
                menuAreas();
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    armazenaDados(&cienciasExatas, ce);
                    ce++;
                    break;

                case 2:
                    armazenaDados(&cienciasHumanas, ch);
                    ch++;
                    break;

                case 3:
                    armazenaDados(&cienciasBiomedicas, cb);
                    cb++;
                    break;

                case 0:
                    break;

                default:
                    printf("Opcao Invalida\n\n\n");
                    break;
                }
            }

            break;

        case 2:
            while (op != 0)
            {
                menuAreas();
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    pos = buscarLivro(&cienciasExatas, ce);
                    mostrarLivro(&cienciasExatas, pos);
                    break;

                case 2:
                    pos = buscarLivro(&cienciasHumanas, ch);
                    mostrarLivro(&cienciasHumanas, pos);
                    break;

                case 3:
                    pos = buscarLivro(&cienciasBiomedicas, cb);
                    mostrarLivro(&cienciasBiomedicas, pos);
                    break;

                case 0:
                    break;
                default:
                    break;
                }
            }

            break;

        case 3:
            while (op != 0)
            {
                menuAreas();
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    pos = buscarLivroNome(&cienciasExatas, ce);
                    mostrarLivro(&cienciasExatas, pos);
                    break;

                case 2:
                    pos = buscarLivroNome(&cienciasHumanas, ch);
                    mostrarLivro(&cienciasHumanas, pos);
                    break;

                case 3:
                    pos = buscarLivroNome(&cienciasBiomedicas, cb);
                    mostrarLivro(&cienciasBiomedicas, pos);
                    break;

                case 0:
                    break;
                default:
                    printf("Opção Inváida, tente novamente!!!!\n\n");
                    break;
                }
            }
            break;

        case 4:
            while (op != 0)
            {
                menuAreas();
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    pos = buscarLivro(&cienciasExatas, ce);
                    getDados(&cienciasExatas, pos);
                    break;

                case 2:
                    pos = buscarLivro(&cienciasHumanas, ch);
                    getDados(&cienciasHumanas, pos);
                    break;

                case 3:
                    pos = buscarLivro(&cienciasBiomedicas, cb);
                    getDados(&cienciasBiomedicas, pos);
                    break;

                case 0:
                    pos = -1;
                    break;

                default:
                    printf("Opção Inváida, tente novamente!!!!\n\n");
                    break;
                }

                if (pos >= 0)
                {
                    printf("As Informações do Livro foram salvas com sucesso\n\n\n");
                }
            }
            break;

        case 5:
            while (op != 0)
            {
                menuAreas();
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    pos = buscarLivro(&cienciasExatas, ce);
                    excluirLivro(&cienciasExatas, pos, ce);
                    ce--;
                    break;

                case 2:
                    pos = buscarLivro(&cienciasHumanas, ch);
                    excluirLivro(&cienciasHumanas, pos, ch);
                    ch--;
                    break;

                case 3:
                    pos = buscarLivro(&cienciasBiomedicas, cb);
                    excluirLivro(&cienciasBiomedicas, pos, cb);
                    cb--;
                    break;

                case 0:
                    pos = -1;
                    break;

                default:
                    printf("Opção Inváida, tente novamente!!!!\n\n");
                    break;
                }

                if (pos >= 0)
                {
                    printf("Livro deletado com sucesso\n\n\n");
                }
            }
            break;

        case 6:
            while (op != 0)
            {
                menuAreas();
                scanf("%d", &op);

                switch (op)
                {
                case 1:
                    listarLivros(&cienciasExatas, ce);
                    break;

                case 2:
                    listarLivros(&cienciasHumanas, ch);
                    break;

                case 3:
                    listarLivros(&cienciasBiomedicas, cb);
                    break;

                case 0:
                    pos = -1;
                    break;

                default:
                    printf("Opção Inváida, tente novamente!!!!\n\n");
                    break;
                }

                if (pos >= 0)
                {
                    printf("Livro deletado com sucesso\n\n\n");
                }
            }
            break;

        default:
            printf("Opção Inváida, tente novamente!!!!\n\n");
            break;
        }
    }

    return 0;
}

int lerCod()
{
    int cod;

    printf("Digite o codigo: ");
    scanf("%d", &cod);

    return cod;
}

void menu()
{
    printf("=======================MENU=======================\n\n");
    printf("1 - Registrar\n");
    printf("2 - Consultar por codigo\n");
    printf("3 - Consultar por nome\n");
    printf("4 - Editar Livro\n");
    printf("5 - Excluir Livro\n");
    printf("6 - listar Livros\n");
    printf("0 - Sair\n\n\n");

    printf("Escolha -> ");
}

void menuAreas()
{
    printf("========AREAS========\n\n");

    printf("1 - Ciencias Exatas\n");
    printf("2 - Ciencias Humanas\n");
    printf("3 - Ciencias Biomedicas\n");
    printf("0 - Sair\n\n");

    printf("Escolha -> ");
}

void armazenaDados(Livro *pontLivro[], int pos)
{
    if (pos == TAM)
    {
        printf("A quantidade maxima de livros foi atingida\n\n");
        return;
    }

    int cod = lerCod();

    (*pontLivro + pos)->cod = cod;

    getDados(pontLivro, pos);
}

int buscarLivro(Livro *pontLivro[], int quant)
{
    if (quant == 0)
    {
        printf("Nenhum livro cadastrado\n\n");
        return;
    }

    int cod = lerCod();

    for (int i = 0; i < quant; i++)
    {
        if (cod == (*pontLivro + i)->cod)
        {
            return i;
        }
    }

    return -1;
}

int buscarLivroNome(Livro *pontLivro[], int quant)
{
    if (quant == 0)
    {
        printf("Nenhum livro cadastrado\n\n");
        return;
    }

    char nome[CARACTERES];

    printf("Digite o nome buscado: ");
    fflush(stdin);
    gets(nome);

    for (int i = 0; i < quant; i++)
    {
        if (strcmp(nome, (*pontLivro + i)->nome))
        {
            return i;
        }
    }

    return -1;
}

void getDados(Livro *pontLivro[], int pos)
{
    if (pos < 0)
    {
        printf("Livro nao econtrado, tente novamente!!\n\n");
        return;
    }

    printf("Nome da Obra: ");
    fflush(stdin);
    gets((*pontLivro + pos)->nome);

    printf("Autor da Obra: ");
    fflush(stdin);
    gets((*pontLivro + pos)->autor);

    printf("Editora: ");
    fflush(stdin);
    gets((*pontLivro + pos)->editora);

    printf("Numero de paginas: ");
    scanf("%d", &(*pontLivro + pos)->numPag);

    printf("Livro Doado (S,N): ");
    fflush(stdin);
    (*pontLivro + pos)->doado = getchar();
}

void excluirLivro(Livro *pontLivro[], int pos, int quant)
{
    if (quant == 0)
    {
        printf("Nenhum livro cadastrado\n\n");
        return;
    }

    if (pos < 0)
    {
        printf("Livro nao econtrado, tente novamente!!\n\n");
        return;
    }

    for (int i = pos; i < (quant - 1); i++)
    {
        (*pontLivro + i)->cod = (*pontLivro + (i + 1))->cod;
        strcpy((*pontLivro + i)->nome, (*pontLivro + (i + 1))->nome);
        strcpy((*pontLivro + i)->editora, (*pontLivro + (i + 1))->editora);
        strcpy((*pontLivro + i)->autor, (*pontLivro + (i + 1))->autor);
        (*pontLivro + i)->doado = (*pontLivro + (i + 1))->doado;
        (*pontLivro + i)->numPag = (*pontLivro + (i + 1))->numPag;
    }
}

void listarLivros(Livro *pontLivro[], int quant)
{
    if (quant == 0)
    {
        printf("Nenhum livro cadastrado\n\n");
        return;
    }
    for (int i = 0; i < quant; i++)
    {
        mostrarLivro(pontLivro, i);
    }
}

void mostrarLivro(Livro *pontLivro[], int pos)
{

    if (pos < 0)
    {
        printf("Livro nao econtrado, tente novamente!!\n\n");
        return;
    }

    printf("\n=======================\n");
    printf("Codigo: %d\n", (*pontLivro + pos)->cod);

    printf("Nome: %s\n", (*pontLivro + pos)->nome);
    printf("Autor: %s\n", (*pontLivro + pos)->autor);
    printf("Editora: %s\n", (*pontLivro + pos)->editora);
    printf("Numero de Paginas: %d\n", (*pontLivro + pos)->numPag);
}