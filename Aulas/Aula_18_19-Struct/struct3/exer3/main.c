#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;  

int main(){
    Data date, *datas;
    char data[15];

    datas = &date;

    printf("Digite uma data (dd/mm/aaaa): ");
    fflush(stdin);
    gets(data);

    for(int i = 0; i < strlen(date)){

    }

    return 0;
}