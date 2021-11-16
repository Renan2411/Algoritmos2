#include <stdio.h>
#include <stdlib.h>

int main(){
    int var = 50;
    int *ptrvar;

    ptrvar = &var;

    *ptrvar = *ptrvar / 10;

    printf("%d", *ptrvar);

    return 0;
}