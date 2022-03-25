#include <stdio.h>

typedef unsigned int uint;

uint contarCaminos (uint n);

int main()
{
    uint n;
    
    printf("Ingrese el valor de n (n > 0): ");
    scanf("%d", &n);
    
    printf("La cantidad de caminos posibles para n = %d es: %d\n", n,
        contarCaminos(n));
    
    return 0;
}

uint contarCaminos (uint n)
{
    if (n <= 1)
        return 1;
    else
        return contarCaminos(n-1) + contarCaminos(n-2);
}
