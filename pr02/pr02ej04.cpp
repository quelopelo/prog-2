#include <stdio.h>

typedef unsigned int uint;

uint mcd (uint a, uint b);
uint mcdAux (uint a, uint b);

int main()
{
    uint a, b;
    
    printf("Ingrese dos naturales (al menos uno distinto de cero): ");
    scanf("%d %d", &a, &b);
    
    printf("El máximo común divisor es: %d\n", mcd(a, b));
    
    return 0;
}

uint mcd (uint a, uint b)
{
    if (a >= b)
        return mcdAux(a, b);
    else
        return mcdAux(b, a);
}

uint mcdAux (uint a, uint b)
{
    if (b == 0)
        return a;
    else
        return mcdAux(b, a % b);
}
