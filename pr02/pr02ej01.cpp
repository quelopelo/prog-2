# include <stdio.h>

typedef unsigned int uint;

/* Ordena A[1..n] de manera creciente */
void ordenar (float *A, uint n);

/* Inserta e en A[1..n] de manera ordenada.
Precondición: n >= 0. Si n >= 1 => A[1..n] está ordenado de manera
creciente. A[n+1] es indeterminado.
Postcondición: A[1..n+1] queda ordenado de manera creciente */
void insertarOrdenado (float *A, uint n, float e);

int main()
{
    uint N;
    
    printf("Ingrese un largo para el arreglo: ");
    scanf("%d", &N);
    
    float *A = new float[N];
    
    printf("Ingrese el arreglo de reales:\n ");
    for (uint i = 0; i < N; i++)
        scanf("%f", &A[i]);
    
    ordenar(A, N);
    
    printf("El arreglo de reales ordenado es:\n");
    for (uint i = 0; i < N; i++)
        printf(" %.2f", A[i]);
    printf("\n");
    
    delete [] A;
    
    return 0;
}

void ordenar (float *A, uint n)
{
    if (n > 0)
    {
        ordenar(A, n-1);
        insertarOrdenado(A, n-1, A[n-1]);
    }
    
}

void insertarOrdenado (float *A, uint n, float e)
{
    if (n == 0)
        A[0] = e;
    else
        if (e >= A[n-1])
            A[n] = e;
        else
        {
            A[n] = A[n-1];
            insertarOrdenado(A, n-1, e);
        }
    n++;
}
