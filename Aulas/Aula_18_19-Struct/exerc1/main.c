#include <stdio.h>
#include <stdlib.h>

#define TAM 5

struct ficha_funcionario
{
    char nome[30];
    char sexo;
    float peso;
    float altura;
    int idade;
};

int main()
{
    struct ficha_funcionario funcionarios[TAM];

    //Leitura dos Funcionários
    for (int i = 0; i < TAM; i++)
    {
        printf("Informacoes do Funcionario %d\n\n", i);

        printf("Nome: ");
        fflush(stdin); //Descarega o Buffer do teclado
        gets(funcionarios[i].nome);

        printf("Peso: ");
        scanf("%f", &funcionarios[i].peso);

        printf("Sexo (M/F/N): ");
        fflush(stdin);//Descarega o Buffer do teclado
        scanf("%c", &funcionarios[i].sexo);

        printf("Altura: ");
        scanf("%f", &funcionarios[i].altura);

        printf("Idade: ");
        scanf("%d", &funcionarios[i].idade);

        printf("\n\n");
    }

    //Escrita
    for (int i = 0; i < TAM; i++)
    {
        printf("Informacoes do Funcionario %d\n\n", i);

        printf("Nome: %s\n", funcionarios[i].nome);
        printf("Idade: %d\n", funcionarios[i].idade);
        printf("Sexo: %c\n", funcionarios[i].sexo);
        printf("Altura: %.2f\n", funcionarios[i].altura);
        printf("Peso: %.2f\n", funcionarios[i].peso);

        printf("\n\n");
    }

    return 0;
}