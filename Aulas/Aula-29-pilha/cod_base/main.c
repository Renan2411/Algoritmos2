#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int valor;
    char naipe[10];
} Carta;

typedef struct Elemento
{
    Carta dados;
    struct Elemento *prox;
} Elemento;

typedef struct Elemento* Pilha;

Pilha* criarPilha();
void liberarPilha(Pilha *pi);
int tamanhoPilha(Pilha *pi);
int pilhaVazia(Pilha *pi);
int push(Pilha *pi, Carta dado);
int pop(Pilha *pi);
int top(Pilha *pi, Carta *topo);
int imprimirPilha(Pilha *pi);

int main()
{
    return 0;
}

Pilha* criarPilha(){
    Pilha* pi = (Pilha*) malloc(sizeof (Pilha));

    if(pi != NULL){
        *pi = NULL;
    }

    return pi;
}

void liberarPilha(Pilha *pi){
    if(pi != NULL){
        Elemento *no;

        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->prox;
            free(no);
        }

        free(pi);
    }
}

int tamanhoPilha(Pilha *pi){
    if(pi == NULL){
        return 0;
    }

    int cont = 0;
    Elemento *no = *pi;

    while(no != NULL){
        cont++;
        no = no->prox;
    }

    return cont;
}

int pilhaVazia(Pilha *pi){
    if(pi == NULL){
        return 1;
    }

    if(*pi == NULL){
        return 1;
    }

    return 0;
}

int push(Pilha *pi, Carta dado){
    if(pi == NULL){
        return -1;
    }

    Elemento *no = (Elemento*) malloc(sizeof(Elemento));

    if(no == NULL){
        return -1;
    }

    no->dados = dado;
    no->prox = (*pi);
    *pi = no;

    return 0;
}

int pop(Pilha *pi){
    if(pilhaVazia(pi)){
        return -1;
    }

    Elemento *no = *pi;

    *pi = no->prox;
    free(no);

    return 0;
}

int top(Pilha *pi, Carta *topo){
    if(pilhaVazia(pi)){
        return -1;
    }

    *topo = (*pi)->dados;

    return 0;
}

int imprimirPilha(Pilha *pi){
    if(pilhaVazia(pi)){
        return -1;
    }

    Elemento *no = *pi;

    while(no != NULL){
        printf("Valor da carta: %d || Naipe da Carta: %s\n", no->dados.valor, no->dados.naipe);
    }

    return 0;
}