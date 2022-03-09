# include <stdio.h>

# define MAX 3

// Registro con dia d, mes m y año a
struct rep_fecha
{
    unsigned int d;
    unsigned int m;
    unsigned int a;
};

void ordenarFechas(rep_fecha arreglo[MAX]);
void imprimirFechas(rep_fecha arreglo[MAX]);

int main()
{
    rep_fecha arreglo[MAX];
    
    arreglo[0].d = 10; arreglo[0].m = 10; arreglo[0].a = 2022;
    arreglo[1].d = 15; arreglo[1].m = 5; arreglo[1].a = 2022;
    arreglo[2].d = 20; arreglo[2].m = 11; arreglo[2].a = 1992;
    
    ordenarFechas(arreglo);
    imprimirFechas(arreglo);
    
    return 0;
};

void ordenarFechas(rep_fecha arreglo[MAX])
{
    rep_fecha temp;
    
    for (int i = MAX-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arreglo[j].a > arreglo[j+1].a ||
            (arreglo[j].a == arreglo[j+1].a &&
            arreglo[j].m > arreglo[j+1].m) ||
            (arreglo[j].a == arreglo[j+1].a &&
            arreglo[j].m == arreglo[j+1].m &&
            arreglo[j].d > arreglo[j+1].d))
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            };
}

void imprimirFechas(rep_fecha arreglo[MAX])
{
    for (int i = 0; i < MAX; i++)
        printf("%d/%d/%d\n", arreglo[i].d, arreglo[i].m, arreglo[i].a);
}
