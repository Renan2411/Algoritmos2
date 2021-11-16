#include <stdio.h>
#include <stdlib.h>

#define TAM 2

struct corpo
{
   float peso;
   float altura;
};


struct ficha_funcionario
{
    char nome[30];
    char sexo;
    struct corpo info;
    int idade;
};

void imprimir(struct ficha_funcionario funcionario[])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("Informacoes do Funcionario %d\n\n", i);

        printf("Nome: %s\n", funcionario[i].nome);
        printf("Idade: %d\n", funcionario[i].idade);
        printf("Sexo: %c\n", funcionario[i].sexo);
        printf("Altura: %.2f\n", funcionario[i].info.altura);
        printf("Peso: %.2f\n", funcionario[i].info.peso);

        printf("\n\n");
    }
}

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
        scanf("%f", &funcionarios[i].info.peso);

        printf("Sexo (M/F/N): ");
        fflush(stdin); //Descarega o Buffer do teclado
        scanf("%c", &funcionarios[i].sexo);

        printf("Altura: ");
        scanf("%f", &funcionarios[i].info.altura);

        printf("Idade: ");
        scanf("%d", &funcionarios[i].idade);

        printf("\n\n");
    }

    //Escrita
    imprimir(funcionarios);

    return 0;
}