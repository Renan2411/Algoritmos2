#include <stdio.h>
#include <stdlib.h>

#define TAM 100

void escreverArquivo(char nomeArquivo[]);

int main()
{
    FILE *arq = fopen("teste.txt", "rt");
    FILE *newArq;
    char frase[TAM], linha[TAM];
    int contLinhas = 0;

    if (arq == NULL)
    {
        printf("Houve um erro ao ler o arquivo\n");
        exit(1);
    }

    printf("Digite uma frase: ");
    gets(frase);

    while (!feof(arq))
    {
        fgets(linha, TAM, arq);
        contLinhas++;

        if(contLinhas == 1){
            newArq = fopen("novoTexto.txt", "wt");
        }else if(contLinhas == 2){
            fclose(newArq);

            newArq = fopen("novoTexto.txt", "at");
        }

        if (contLinhas == 4)
        {
            fprintf(newArq, "%s\n", frase);
        }

        fprintf(newArq, "%s", linha);
    }

    fclose(arq);
    fclose(newArq);

    printf("Texto do Arquivo Antigo:\n\n");
    escreverArquivo("teste.txt");

    printf("\n\nTexto do Novo Arquivo:\n\n");
    escreverArquivo("novoTexto.txt");

    return 0;
}

void escreverArquivo(char nomeArquivo[]){
    FILE *arq  = fopen(nomeArquivo, "rt");
    char linha[TAM];

    while (!feof(arq))
    {
        fgets(linha, TAM, arq);
        printf("%s", linha);
    }
    
    fclose(arq);
}