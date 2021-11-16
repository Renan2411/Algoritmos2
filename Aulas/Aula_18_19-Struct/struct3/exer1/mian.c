#include <stdio.h>
#include <stdlib.h>

#define TAM 5

//Declarando um novo tipo
typedef struct
{
    char nome[30];
    char sexo;
    float peso;
    float altura;
    int idade;
} Funcionario;

Funcionario ler_funcionario(Funcionario funcionario);

int main()
{
    Funcionario funcionario[TAM];

    for (int i = 0; i < TAM; i++)
    {
        puts("===========================");
        funcionario[i] = ler_funcionario(funcionario[i]);
        puts("===========================");
    }

    for (int i = 0; i < TAM; i++)
    {
        puts("=================================");
        printf("Informacoes do Funcionario %d\n\n", i);
        printf("Nome: %s\n", funcionario[i].nome);
        printf("Sexo: %c\n", funcionario[i].sexo);
        printf("Idade: %d\n", funcionario[i].idade);
        printf("Altura: %.2f\n", funcionario[i].altura);
        printf("Peso: %.2f\n", funcionario[i].peso);
        puts("=================================");

    }

    return 0;
}

Funcionario ler_funcionario(Funcionario funcionario)
{
    printf("Digite o nome: ");
    fflush(stdin);
    gets(funcionario.nome);

    printf("Digite o Sexo (F/M/N): ");
    fflush(stdin);
    scanf("%c", &funcionario.sexo);

    printf("Digite a idade: ");
    scanf("%d", &funcionario.idade);

    printf("Digite a Altura: ");
    scanf("%f", &funcionario.altura);

    printf("Digite o Peso: ");
    scanf("%f", &funcionario.peso);

    return funcionario;
}