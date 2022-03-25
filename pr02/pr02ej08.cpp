#include <stdio.h>

typedef unsigned int uint;

/* Devuelve las combinaciones de m tomadas de a n.
Precondición: m >= n */
uint comb (uint m, uint n);

int main()
{
    uint m, n;
    
    printf("Combinaciones de m tomadas de a n (m >= n)\n");
    printf("Ingrese m y n separados por espacios: ");
    scanf("%d %d", &m, &n);
    
    printf("Las combinaciones de %d tomadas de a %d son: %d\n",
        m, n, comb(m, n));
    
    return 0;
}

uint comb (uint m, uint n)
{
    if (n == 0 || n == m)
        return 1;
    else
        return comb(m-1, n) + comb(m-1, n-1);
}
