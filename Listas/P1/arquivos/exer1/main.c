#include <stdio.h>

#define TAM 20

int main(){
    char nome[TAM], sexo;
    int idade;
    float alt;
    FILE *arq;

    printf("Digite seu nome: ");
    gets(nome);

    printf("Sexo (F/M/NA): ");
    sexo = getchar();

    printf("Digite sua idade: ");
    scanf("%d", &idade);

    printf("Digite sua altura: ");
    scanf("%f", &alt);

    arq = fopen("infos.txt", "wt");

    fprintf(arq, "Nome: %s, Idade: %d, Sexo: %c, Altura: %.2f", nome, idade, sexo, alt);

    arq = fclose(arq);

    printf("\nSuas informações foram salvas com sucesso!!\n");

    return 0;
}