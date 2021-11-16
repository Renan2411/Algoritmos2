#include <stdio.h>
#include <stdlib.h>

#define TAM 20

struct infos
{
    char sexo;
    int idade;
    float salario;
    int filhos;
};

struct infos preencherInfos();
float mediaSalarial(struct infos habitantes[], int tam);
int quantidadeMulheres(struct infos habitantes[], int tam);
int maiorIdade(struct infos habitantes[], int tam);
int menorIdade(struct infos habitantes[], int tam);
void salvarDados(struct infos habitantes[], int tam);
void imprimirDados(struct infos habitantes[], int tam);

int main()
{
    struct infos habitantes[TAM];
    int i;

    for (i = 0; i < TAM; i++)
    {
        printf("\n=================\n");
        habitantes[i] = preencherInfos();

        if (habitantes[i].idade == 0)
        {
            break;
        }
    }

    imprimirDados(habitantes, i);

    return 0;
}

struct infos preencherInfos()
{
    struct infos habitante;

    printf("Digite a idade: ");
    scanf("%d", &habitante.idade);

    if(habitante.idade == 0){
        return habitante;
    }

    printf("Digite o sexo (F/M): ");
    fflush(stdin);
    scanf("%c", &habitante.sexo);

    printf("Digite o salario: ");
    scanf("%f", &habitante.salario);

    printf("Digite a quantidade de filhos: ");
    scanf("%d", &habitante.filhos);

    return habitante;
}

float mediaSalarial(struct infos habitantes[], int tam)
{
    printf("%d\n\n", tam);
    float media = 0;

    for (int i = 0; i < tam; i++)
    {
        media += habitantes[i].salario;
    }

    return (media / (float) (tam));
}
float mediaIdade(struct infos habitantes[], int tam)
{

    float idade = 0;

    for (int i = 0; i < tam; i++)
    {
        idade += habitantes[i].idade;
    }

    return (idade / (float) tam);
}

int quantidadeMulheres(struct infos habitantes[], int tam)
{
    int quant = 0;

    for (int i = 0; i < tam; i++)
    {
        if (habitantes[i].sexo == 'f' || habitantes[i].sexo == 'F')
        {
            if (habitantes[i].filhos == 3 && habitantes[i].salario <= 1000)
            {
                quant++;
            }
        }
    }

    return quant;
}

int maiorIdade(struct infos habitantes[], int tam)
{
    int maior = habitantes[0].idade;

    for (int i = 1; i < tam; i++)
    {
        if (habitantes[i].idade > maior)
        {
            maior = habitantes[i].idade;
        }
    }

    return maior;
}

int menorIdade(struct infos habitantes[], int tam)
{
    int menor = habitantes[0].idade;

    for (int i = 1; i < tam; i++)
    {
        if (habitantes[i].idade < menor)
        {
            menor = habitantes[i].idade;
        }
    }

    return menor;
}

void salvarDados(struct infos habitantes[], int tam)
{
    FILE *arq = fopen("habitantes.txt", "wt");

    if (arq == NULL)
    {
        printf("Erro ao salvar dados, por favor cadastre novamente");
        exit(1);
    }

    for (int i = 0; i < tam; i++)
    {
        fputs("================\n", arq);
        fprintf(arq, "HABITANTE %d\n\n", i);

        fprintf(arq, "IDADE: %d\n", habitantes[i].idade);
        fprintf(arq, "SEXO: %c\n", habitantes[i].sexo);
        fprintf(arq, "FILHOS: %d\n", habitantes[i].filhos);
        fprintf(arq, "SALARIO: %f\n\n", habitantes[i].salario);
    }
}

void imprimirDados(struct infos habitantes[], int tam)
{
    printf("\n============================\n");
    printf("Media Salarial do Grupo: %.2f\n", mediaSalarial(habitantes, tam));
    printf("Maior Idade do Grupo: %d\n", maiorIdade(habitantes, tam));
    printf("Menor Idade do Grupo: %d\n", menorIdade(habitantes, tam));
    printf("Média de Idade do Grupo: %.0f\n", mediaIdade(habitantes, tam));
    printf("Quantidade de Mulheres com 3 filhos e com Salário de até 1000: %d\n\n", quantidadeMulheres(habitantes, tam));

    salvarDados(habitantes, tam);
}