# include <stdio.h>

void OrdenarArreglo(int N, int *vec, int *vec_ord);

int main()
{
    int N;
    
    printf("Ingrese un largo para el arreglo: ");
    scanf("%d", &N);
    
    int *vec = new int[N];
    int *vec_ord = new int[N];
    
    printf("Ingrese el arreglo de enteros:\n ");
    for (int i = 0; i < N; i++)
        scanf("%d", &vec[i]);
    
    OrdenarArreglo(N, vec, vec_ord);
    
    printf("El arreglo de enteros ordenado es:\n");
    for (int i = 0; i < N; i++)
        printf(" %d", vec_ord[i]);
    printf("\n");
    
    delete [] vec;
    delete [] vec_ord;
    
    return 0;
}

void OrdenarArreglo(int N, int *vec, int *vec_ord)
{
    int i, j;
    
    vec_ord[0] = vec[0];
    for (i = 1; i < N; i++)
    {
        j = i-1;
        while (j >= 0 && vec[i] < vec_ord[j])
        {
            vec_ord[j+1] = vec_ord[j];
            j--;
        }
        vec_ord[j+1] = vec[i];
    }
}
