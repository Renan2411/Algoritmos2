#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b;
    int *p1, *p2;

    p1 = &a;
    p2 = &b;

    printf("Digite um número: ");
    scanf("%d", p1);

    printf("Digite outro número: ");
    scanf("%d", p2);

    printf("\n%d + %d = %d", *p1, *p2, (*p1 + *p2));

    return 0;
}