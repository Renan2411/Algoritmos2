#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CARACTERES 100
#define TAM 5

typedef struct
{
    int numSocio;
    char nome[CARACTERES];
    char endereco[CARACTERES];
    char bairro[CARACTERES];
    char cidade[CARACTERES];
    char estado[CARACTERES];
} Socio;

void menu();
void imprimir(Socio *pontSocio, int quant);
void incluirRegistro(Socio *pontSocio, int pos);
int alterarRegistro(Socio *pontSocio, int cod, int quant);
void getDados(Socio *pontSocio, int pos);

int main()
{
    Socio socios[TAM];
    int quant = 0;
    int op, cod;

    while (1)
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            incluirRegistro(&socios, quant);
            quant++;

            printf("Socio registrado\n\n");
            break;

        case 2:
            printf("Digite o codigo do socio: ");
            scanf("%d", &cod);
            cod = alterarRegistro(&socios, cod, quant);

            if (cod == 2)
            {
                printf("Nenhum socio foi registrado\n\n");
            }
            else if (cod < 0)
            {
                printf("Nenhum Registro foi encontrado\n\n");
            }
            else
            {
                printf("Alteração realizada com sucesso\n\n");
            }

            break;

        case 3:
            printf("Digite o codigo do socio: ");
            scanf("%d", &cod);
            cod = excluirRegistro(&socios, cod, quant);

            if (cod == 2)
            {
                printf("Nenhum socio foi registrado\n\n");
            }
            else if (cod < 0)
            {
                printf("Nenhum Registro foi encontrado\n\n");
            }
            else
            {
                quant--;
                printf("Exclusao realizada com sucesso\n\n");
            }
            break;

        case 4:
            imprimir(&socios, quant);
            break;

        case 0:
            return 0;
            break; 

        default:
            printf("Opcao Invalida\n\n");
            break;
        }
    }

    return 0;
}

void menu()
{
    printf("1- Incluir\n");
    printf("2- Alterar\n");
    printf("3- Excluir\n");
    printf("4- Imprimir Socios\n");
    printf("0- Sair\n\n");

    printf("Escolha -> ");
}

void imprimir(Socio *pontSocio, int quant)
{

    if (quant == 0)
    {
        printf("Nenhum Sócio Cadastrado\n\n");
        return;
    }

    for (int i = 0; i < quant; i++)
    {
        printf("Numero de Socio: %d\n", (pontSocio + i)->numSocio);
        printf("Nome: %s\n", (pontSocio + i)->nome);
        printf("Edereco: %s\n", (pontSocio + i)->endereco);
        printf("Bairro: %s\n", (pontSocio + i)->bairro);
        printf("Cidade: %s\n", (pontSocio + i)->cidade);
        printf("Estado %s\n", (pontSocio + i)->estado);
        printf("=============================\n\n");
    }
}

void incluirRegistro(Socio *pontSocio, int pos)
{
    if (pos == TAM)
    {
        printf("Quantidade Máxima de Registros Atingida\n\n");
        return;
    }

    printf("Digite o Número do Sócio: ");
    scanf("%d", &(pontSocio + pos)->numSocio);

    getDados(pontSocio, pos);
}

int alterarRegistro(Socio *pontSocio, int cod, int quant)
{

    if (quant == 0)
    {
        return 2;
    }

    for (int i = 0; i < quant; i++)
    {
        if ((pontSocio + i)->numSocio == cod)
        {
            getDados(pontSocio, i);
            return 1;
        }
    }

    return -1;
}

int excluirRegistro(Socio *pontSocio, int cod, int quant)
{
    if (quant == 0)
    {
        return 2;
    }

    for (int i = 0; i < quant; i++)
    {
        if ((pontSocio + i)->numSocio == cod)
        {

            if (i == (quant - 1))
            {
                return 1;
            }

            for (int j = i; j < quant; j++)
            {
                (pontSocio + j)->numSocio = (pontSocio + j + 1)->numSocio;
                strcpy((pontSocio + j)->nome, (pontSocio + j + 1)->nome);
                strcpy((pontSocio + j)->endereco, (pontSocio + j + 1)->endereco);
                strcpy((pontSocio + j)->bairro, (pontSocio + j + 1)->bairro);
                strcpy((pontSocio + j)->cidade, (pontSocio + j + 1)->cidade);
                strcpy((pontSocio + j)->estado, (pontSocio + j + 1)->estado);
            }

            return 1;
        }
    }

    return -1;
}

void getDados(Socio *pontSocio, int pos)
{
    printf("Digite o nome: ");
    fflush(stdin);
    gets((pontSocio + pos)->nome);

    printf("Digite o endereco: ");
    fflush(stdin);
    gets((pontSocio + pos)->endereco);

    printf("Digite o bairro: ");
    fflush(stdin);
    gets((pontSocio + pos)->bairro);

    printf("Digite a cidade: ");
    fflush(stdin);
    gets((pontSocio + pos)->cidade);

    printf("Digite o Estado: ");
    fflush(stdin);
    gets((pontSocio + pos)->estado);
}
