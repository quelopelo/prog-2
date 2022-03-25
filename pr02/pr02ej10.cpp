#include <stdio.h>

#define TABLA 10;

typedef unsigned int uint;

struct Tpar
{
    int s1, s2;
};

uint Fibonacci (uint n);
uint llamadasFibonacci (uint n);

/* Devuelve el n-ésimo término de la secuencia aditiva que empieza
con a1 y a2. */
int secAditiva (uint n, int a1, int a2);

/* Devuelve el secAditiva(n-1) y secAditiva(n-2) */
Tpar secAditivaAux (uint n, int a1, int a2);

int main()
{
    const uint n = TABLA;
    
    printf("Invocaciones (parte a)\n");
    for (uint i = 0; i < n; i++)
        printf("  %d\t%d\n", i, llamadasFibonacci(i));
    
    printf("Serie de Fibonacci (parte b y c)\n");
    for (uint i = 0; i < n; i++)
        printf("  %d\t%d\n", i, Fibonacci(i));
    
    return 0;
}

uint Fibonacci (uint n)
{
    return secAditiva (n+1, 1, 1);
}

uint llamadasFibonacci (uint n)
{
    if (n <= 1)
        return 1;
    else
        return 1 + llamadasFibonacci(n-1) + llamadasFibonacci(n-2);
}

int secAditiva (uint n, int a1, int a2)
{
    switch (n)
    {
        case 1:
            return a1;
            break;
        case 2:
            return a2;
            break;
        default:
            Tpar par = secAditivaAux(n, a1, a2);
            return par.s1 + par.s2;
    }
}

Tpar secAditivaAux (uint n, int a1, int a2)
{
    Tpar res;
    
    if (n == 3)
    {
        res.s1 = a2;
        res.s2 = a1;
    }
    else
    {
        res = secAditivaAux(n-1, a1, a2);
        int aux = res.s1;
        res.s1 = res.s1 + res.s2;
        res.s2 = aux;
    }
    
    return res;
}
