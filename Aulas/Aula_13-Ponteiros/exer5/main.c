#include <stdio.h>
#include <stdlib.h>

int main(){
    char mensagem[] = "Aula";
    char *pont;

    pont = &mensagem;

    printf("%s\n", pont);

    return 0;
}