#include <stdio.h>
#include <stdlib.h>

void criarArquivo(int num);
void lerConteudo();

int main(){
    int num;

    printf("Digite um número: ");
    scanf("%d", &num);
    
    criarArquivo(num);
    lerConteudo();

    return 0;
}

void criarArquivo(int num){
    FILE *arq;

    arq = fopen("teste.txt", "wt");

    fprintf(arq, "%d", num);

     fclose(arq);
}

void lerConteudo(){
    FILE *arq;
    int num;

    arq = fopen("teste.txt", "rt");

    fscanf(arq, "%d", &num);

    printf("%d\n", num);

    fclose(arq);
    
}