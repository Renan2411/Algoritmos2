#include <stdio.h>
#include <stdlib.h>

#define TAM 3

typedef struct{
    int cod;
    char telefone[15];
    char nome[50];
    char endereco[150];
    int rg;
    int cpf;
}Cliente;

void cadastroCliente(Cliente *pontCliente);
void gerarRelatorio(Cliente *pontCliente);

int main(){
    Cliente clientes[TAM];

    cadastroCliente(&clientes);
    gerarRelatorio(&clientes);

    return 0;
}

void cadastroCliente(Cliente *pontCliente){
    for(int i = 0; i < TAM; i++){
        printf("\n===========================\n");

        printf("Digite o codigo: ");
        scanf("%d", &pontCliente->cod);

        printf("Digite o nome: ");
        fflush(stdin);
        gets(pontCliente->nome);

        printf("Digite o endereco: ");
        fflush(stdin);
        gets(pontCliente->endereco);

        printf("Digite o telefone: ");
        fflush(stdin);
        gets(pontCliente->telefone);

        printf("Digite o CPF: ");
        scanf("%d", &pontCliente->cpf);

        printf("Digite o RG: ");
        scanf("%d", &pontCliente->rg);
    }
}

void gerarRelatorio(Cliente *pontCliente){
    FILE *arq = fopen("clientes.txt", "wt");

    for(int i = 0; i < TAM; i++){
        fprintf(arq, "Codigo: %d \t\t Telefone %s\n", pontCliente->cod, pontCliente->telefone);
        fprintf(arq, "Nome: %s\n", pontCliente->nome);
        fprintf(arq, "Endereco: %s\n", pontCliente->endereco);
        fprintf(arq, "RG: %d \t\t CPF: %d\n", pontCliente->rg, pontCliente->cpf);

        fputs("\n===========================\n", arq);
    }

    fclose(arq);
}