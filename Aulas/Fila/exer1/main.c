#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    int elementos[TAM];
    int inicio, fim;
    int quantidade;
}Fila;

void menu();
void inserirElemento(Fila *pontFila);
void removerElemento(Fila *pontFila);
void buscarValor(Fila *pontFila);
void imprimirFila(Fila *pontFila);

int main(){
    Fila fila;
    int op;

    fila.quantidade = fila.fim = fila.inicio = 0;

    while(1){

        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            return 0;
            break;
        
        case 1:
            inserirElemento(&fila);
            break;

        case 2:
            removerElemento(&fila);
            break;

        case 3:
            buscarValor(&fila);
            break;

        case 4:
            imprimirFila(&fila);
            break;

        default:
            printf("Opção invalida, tente novamente\n\n");
            break;
        }
    }
}

void menu(){
    printf("=============MENU=============\n\n");
    printf("1 - Inserir elemento\n");
    printf("2 - Remover elemento\n");
    printf("3 - Buscar elemento\n");
    printf("4 - Imprimir Fila\n");
    printf("0 - Sair\n\n");

    printf("Escolha -> ");
}

void inserirElemento(Fila *pontFila){
    int valor;

    if(pontFila->fim == TAM){
        printf("Fila cheia\n\n");
        return;
    }    

    printf("Digite um valor: ");
    scanf("%d", &valor);

    pontFila->elementos[pontFila->fim] = valor;

    pontFila->quantidade++;
    pontFila->fim++; 
}

void removerElemento(Fila *pontFila){
    if(pontFila->quantidade == 0){
        printf("Fila vazia\n\n");
        return;
    }

    pontFila->inicio++;
    pontFila->quantidade--;
}

void buscarValor(Fila *pontFila){
    int valor;

     if(pontFila->quantidade == 0){
        printf("Fila vazia\n\n");
        return;
    }

    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    if(pontFila->inicio == valor){
        return 1;
    }

    return -1;
}

void imprimirFila(Fila *pontFila){
    for(int i = pontFila->inicio; i < pontFila->fim; i++){
        printf("[%d]\t", pontFila->elementos[i]);
    }

    printf("\n\n");
}
