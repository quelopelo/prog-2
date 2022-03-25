#include <stdio.h>

typedef unsigned int uint;

void reglaGraduada (uint n);
void reglaGraduadaAux (uint n);
void imprimirRenglon (uint n);

int main()
{
    uint n;
    
    printf("Ingrese el parámetro p de la regla (p > 0): ");
    scanf("%d", &n);
    
    reglaGraduada(n);
    
    return 0;
}

void reglaGraduada (uint n)
{
    imprimirRenglon(n);
    reglaGraduadaAux(n-1);
    imprimirRenglon(n);
    
}

void reglaGraduadaAux (uint n)
{
    if (n > 0)
    {
        reglaGraduadaAux(n-1);
        imprimirRenglon(n);
        reglaGraduadaAux(n-1);
    }
}

void imprimirRenglon (uint n)
{
    for (uint i = 0; i < n; i++)
        printf("-");
    printf("\n");
}
