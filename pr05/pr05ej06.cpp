#include <stdio.h>

/* Evalúa si el arreglo A almacena en el rango 0..n-1 una permutación
 * de los enteros en {1, ..., n} */
bool esPermutacion (int *A , int n);

int main() {
    
    int n;
    
    printf("Ingrese un largo para el arreglo: ");
    scanf("%d", &n);
    
    int *vec = new int[n];
    
    printf("Ingrese el arreglo de enteros:\n ");
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);
    
    printf("El arreglo de enteros%s es una permutación\n",
           esPermutacion(vec, n) ? "" : " no");
    
    delete [] vec;
    
    return 0;
}

bool esPermutacion (int *A , int n) {
    bool *esta = new bool[n];
    for (int i = 0; i < n; ++i)
        esta[i] = false;
    int i = 0;
    while (i < n && A[i] >= 1 && A[i] <= n && !esta[A[i]-1])
        esta[A[i++]-1] = true;
    delete [] esta;
    return i == n;
}
