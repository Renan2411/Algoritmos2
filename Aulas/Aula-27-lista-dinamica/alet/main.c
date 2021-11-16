#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 2

struct loja_carro
{
    char marca[15];
    int ano;
    char cor[10];
    float preco;
} vetcarro[TAM];

int main()
{
    int i;
    float precoBuscado;
    int quantidade;
    int menu, anoCarro;
    char marcaBuscada[15], marcaCarro, corCarro;

    for (i = 0; i < TAM; i++)
    {
        printf("\n\n\nRegistrando Carros...\n\n\n");

        printf("Digite a marca do carro: \n");
        fflush(stdin);
        fgets(vetcarro[i].marca, 15, stdin);

        printf("Digite o ano do carro: \n");
        scanf("%i", &vetcarro[i].ano);

        printf("Digite a cor do carro: \n");
        fflush(stdin);
        fgets(vetcarro[i].cor, 10, stdin);

        printf("Digite o preco do carro: \n");
        scanf("%f", &vetcarro[i].preco);
    }

    while (1)
    {
        printf("----MENU----\n\n\n 1 - Busca por preco\n 2 - Busca por marca\n 3- Consulta de carros\n 4-  Sair\n");
        scanf("%d", &menu);

        if (menu == 1)
        {
            printf("------ Buscando Carro ------ \n\n\n");
            printf("Informe uma faixa de PRECO de carro: \n");
            scanf("%f", &precoBuscado);

            quantidade = i;
            for (i = 0; i < quantidade; i++)
            {
                if (precoBuscado >= vetcarro[i].preco)
                {
                    printf("\n\n\n-------CARROS ENCONTRADOS POR PRECO-------\n\n\n");
                    printf("MARCA: %s\n", vetcarro[i].marca);
                    printf("COR: %s\n", vetcarro[i].cor);
                    printf("ANO: %d\n", vetcarro[i].ano);
                }
                else
                    puts("Nenhum carro encontrado por esse preco!!");
            }
        }
        if (menu == 2)
        {
            printf("------Buscando Carro ------\n\n\n");
            printf("Informe uma MARCA de carro: \n");
            fflush(stdin);
            // scanf("%s", &marcaBuscada);
            gets(marcaBuscada);

            quantidade = i;
            for (i = 0; i < TAM; i++)
            {
                printf("\n%d\n", strcmp( vetcarro[i].marca, marcaBuscada));
                if (strcmp(vetcarro[i].marca, marcaBuscada) == 0)
                {
                    printf("CARROS ENCONTRADOS DA MARCA %s", marcaBuscada);
                    printf("PRECO: %f", vetcarro[i].preco);
                    printf("ANO: %d", vetcarro[i].ano);
                    printf("COR: %s\n", vetcarro[i].cor);
                }
            }
        }
        if (menu == 3)
        {
            printf("\n-----Consulta de carros------\n");
            printf("Digite MARCA, ANO e COR do carro que procura:\n");
            scanf("%s", &marcaCarro);
            scanf("%d", &anoCarro);
            scanf("%s", &corCarro);

            quantidade = i;
            for (i = 0; i < quantidade; i++)
            {
                if (strcmp(marcaCarro, vetcarro[i].marca) == 0 && anoCarro == vetcarro[i].ano && strcmp(corCarro, vetcarro[i].cor) == 0)
                {
                    printf("Preco %d", vetcarro[i].preco);
                }
            }
        }
        if (menu == 4)
        {
            exit(1);
        }
    }
    return 0;
}