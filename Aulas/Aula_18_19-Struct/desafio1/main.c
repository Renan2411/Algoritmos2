#include <stdio.h>
#include <stdlib.h>

#define CARACTERES 200
#define MAX 200

struct mercadoria
{
    int cod;
    char description[CARACTERES];
    float price;
    int inventory;
};

void menu();
// int lerArquivo(struct mercadoria p[]);
void salvarInfos(struct mercadoria p[], int tam);

int main()
{
    struct mercadoria produtos[MAX];
    int op = 1;
    int cod = 1;
    int inicio = 0;
    int quant = 0;
    int ver; //Flag

    // inicio = lerArquivo(produtos);

    while (op != 0)
    {
        menu();
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            while (cod > 0)
            {
                for (int i = inicio; i < MAX; i++)
                {
                    printf("=======================\n");
                    printf("Codigo do Produto: ");
                    scanf("%d", &cod);

                    if (cod > 0)
                    {
                        produtos[i].cod = cod;

                        printf("Descricao: ");
                        fflush(stdin);
                        gets(produtos[i].description);

                        printf("Preco: ");
                        scanf("%f", &produtos[i].price);

                        printf("Estoque: ");
                        scanf("%d", &produtos[i].inventory);
                    }
                    else
                    {
                        salvarInfos(produtos, i);
                        quant = i;
                        break;
                    }
                }
            }

            break;

        case 2:

            while(1){
                ver = 0;

                printf("=======================\n");
                puts("Buscando Produtos...");
                printf("Digite o Código do Produto (-1 para encerrar): ");
                scanf("%d", &cod);
                
                if(cod == -1){
                    break;
                }

                for(int i = 0; i < quant; i++){
                    if(cod == produtos[i].cod){
                        ver = 1;

                        printf("=======================\n");
                        puts("Dados do Produto");
                        printf("Descricao: %s\n", produtos[i].description);
                        printf("Preco: %.2f\n", produtos[i].price);
                        printf("Estoque: %d\n", produtos[i].inventory);
                    }
                }

                if(ver == 0){
                    printf("=======================\n");
                    printf("Produto nao encontrado\n");
                }
               
            }

            break;
        }
    }

    return 0;
}

void menu()
{
    printf("=======================\n");
    printf("1 - Cadastrar Produto\n");
    printf("2 - Buscar Produto\n");
    printf("0 - Sair\n\n");
    printf("Escolha uma opcao -> ");
}

// int lerArquivo(struct mercadoria produtos[])
// {
//     FILE *arq = fopen("produtos.txt", "rt");
//     int cont = 0;

//     if (arq == NULL)
//     {
//         return 0;
//     }
//     else
//     {
//         while (!feof(arq))
//         {
//             fflush(stdin);
//            // fscanf(arq, "%d %s %f %d\n", &p[cont].cod, &p[cont].description, &p[cont].price, &p[cont].inventory);

//            fscanf(arq,"%d", &p[cont].cod);
//            printf("%d\n", p[cont].cod);
//             cont++;
//         }
//         return cont;
//     }
// }

void salvarInfos(struct mercadoria p[], int tam)
{
    FILE *arq = fopen("produtos.txt", "wt");

    if(arq == NULL){
        printf("ERRO AO SALVAR DADOS, TENTE NOVAMENTE");
        exit(1);
    }

    for (int i = 0; i < tam; i++)
    {
        fputs("===========================================",arq);
        fprintf(arq, "\nPRODUTO %d\n", (i + 1));
        fprintf(arq, "CODIGO: %d \nDESCRICAO: %s \nPRECO: %f \nESTOQUE: %d\n", p[i].cod, p[i].description, p[i].price, p[i].inventory);
        fputs("===========================================",arq);
    }

    fclose(arq);
}

void buscarMercadoria(struct mercadoria p[], int cod, int tam){

    for(int i = 0; i < tam; i++){

    }

}