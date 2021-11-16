#include <stdio.h>
#include <stdlib.h>

int calcularPotencia(int base, int exp, int i, int res);

int main()
{
    int base, exp;
    int res;

    printf("Digite a Base: ");
    scanf("%d", &base);

    printf("Digite o Expoente: ");
    scanf("%d", &exp);

    res = calcularPotencia(base, exp, 1, 1);

    printf("%d elevado a %d e igual a", base, exp);

    if (exp < 0)
    {
        printf(" 1/%d\n", res);
    }
    else
    {
        printf(" %d\n", res);
    }

    return 0;
}

int calcularPotencia(int base, int exp, int i, int res)
{

    if (i == exp)
    {
        return res * base;
    }

    if (exp == 1)
    {
        return base;
    }

    if (exp == 0)
    {
        return 1;
    }

    if(exp < 0){
        exp *= -1;
    }

    return calcularPotencia(base, exp, (i + 1), (res * base));
}