#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

char encontrarRecursivo(char str[], int i);

int main(){
    char str[10] = "megAzord";
    int i;

    i = encontrarRecursivo(str, 0);

    if(i < 0){
        printf("A string nao possui letra maiuscula");
    }else{
        printf("A primeira letra maiuscula da string e %c", str[i]);
    }

    return 0;
}

char encontrarRecursivo(char str[], int i){
    int tam = strlen(str);

    if((str[i] >= 65) && (str[i] <= 90)){
        return i;
    }else if(i == tam){
        return -1;
    }

    return encontrarRecursivo(str, (i + 1));

}