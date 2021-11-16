#include <stdio.h>

int main()
{
    static char st[] = "Hello World";
    printf("%s ", st);//Imprime tudo
    printf("%s \n", &st[0]);//Imprime tudo
    printf("%s ", st + 6);//Imprime tudo a partir da sexta posição
    return 0;
}