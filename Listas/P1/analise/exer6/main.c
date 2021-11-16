#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    int algA = 1, algB = 0;
    int n = 1;

    while (algB < algA)
    {
        n++;
        algA = pow(n, 5);
        algB = pow(2, n);
    }
    
    printf("%d", n);

    return 0;
}