#include <stdio.h>

typedef unsigned int uint;

uint fact (uint n);

/* Devuelve el producto de factorial (n) por 'acum' */
uint factAcum (uint n, int acum);

int main()
{
    uint n;
    
    printf("Ingrese un natural positivo: ");
    scanf("%d", &n);
    
    printf("El factorial de %d es: %d\n", n, fact(n));
    
    return 0;
}

uint fact (uint n)
{
    return factAcum (n, 1);
}

uint factAcum (uint n, int acum)
{
    if (n == 0)
        return acum;
    else
        return factAcum(n-1, n * acum);
}
