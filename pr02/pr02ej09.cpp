#include <stdio.h>

typedef unsigned int uint;

/* Modifica V. Solo se permite intercambio entre posiciones.
Precondición: n % 2 == 0
V[1..n/2] = {true}, V[n/2 + 1..n] = {false}.
Postcondición: V[i] = true si y solo si i%2 == 1. */
void vasos (bool *V, uint n);

void vasosAux (bool *V, uint n, uint ind);
void imprimirVasos (bool *V, uint n);

int main()
{
    uint n;
    
    printf("Ingrese la cantidad de vasos (n / n mod 2 = 0): ");
    scanf("%d", &n);
    
    bool *V = new bool[n];
    for (uint i = 0; i < n/2; i++)
        V[i] = true;
    for (uint i = n/2; i < n; i++)
        V[i] = false;
    
    printf("Vasos antes de ordenar:\n");
    imprimirVasos(V, n);
    
    vasos(V, n);
    
    printf("Vasos después de ordenar:\n");
    imprimirVasos(V, n);
    
    delete [] V;
    
    return 0;
}

void vasos (bool *V, uint n)
{
    vasosAux(V, n, 0);
}

void vasosAux (bool *V, uint n, uint ind)
{
    bool aux;
    
    if (ind < n/2)
    {
        if (ind % 2 == 1)
        {
            aux = V[ind];
            V[ind] = V[n-1-ind];
            V[n-1-ind] = aux;
        }
        vasosAux(V, n, ind+1);
    }
}

void imprimirVasos (bool *V, uint n)
{
    for (uint i = 0; i < n; i++)
        printf(" %d", V[i]);
    printf("\n");
}
