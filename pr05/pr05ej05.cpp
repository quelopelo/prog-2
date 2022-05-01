#include <stdio.h>

/* Ordena de menor a mayor un arreglo A de tamaño n cuyos valores están
 * en el rango [1..k], con orden de crecimiento O(n) */
void Sort1_k (int n, int * vec, int * vec_ord); 

int main() {
    
    int n;
    
    printf("Ingrese un largo para el arreglo: ");
    scanf("%d", &n);
    
    int *vec = new int[n];
    int *vec_ord = new int[n];
    
    printf("Ingrese el arreglo de enteros:\n ");
    for (int i = 0; i < n; i++)
        scanf("%d", &vec[i]);
    
    Sort1_k(n, vec, vec_ord);
    
    printf("El arreglo de enteros ordenado es:\n");
    for (int i = 0; i < n; i++)
        printf(" %d", vec_ord[i]);
    printf("\n");
    
    delete [] vec;
    delete [] vec_ord;
    
    return 0;
}

int maximo (int n, int * A) {
    int max = A[0];
    for (int i = 1; i < n; ++i)
        if (A[i] > max)
            max = A[i];
    return max;
}

void Sort1_k (int n, int * vec, int * vec_ord) {
    int max = maximo(n, vec);
    int *cant = new int[max];
    for (int i = 0; i < max; ++i)
        cant[i] = 0;
    for (int j = 0; j < n; ++j)
        ++cant[vec[j]-1];
    int j = 0;
    for (int i = 0; i < max; ++i)
        for (int k = 0; k < cant[i]; ++k) {
            vec_ord[j] = i+1;
            ++j;
        }
    delete [] cant;
}
