# include <stdio.h>

# define MAX 3

struct rep_fecha
{
    unsigned int f; // AAAAMMDD
};

void ordenarFechas(rep_fecha arreglo[MAX]);
void imprimirFechas(rep_fecha arreglo[MAX]);

int main()
{
    rep_fecha arreglo[MAX];
    
    arreglo[0].f = 20221010;
    arreglo[1].f = 20220515;
    arreglo[2].f = 19921120;
    
    ordenarFechas(arreglo);
    imprimirFechas(arreglo);
    
    return 0;
};

void ordenarFechas(rep_fecha arreglo[MAX])
{
    rep_fecha temp;
    
    for (int i = MAX-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (arreglo[j].f > arreglo[j+1].f)
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            };
}

void imprimirFechas(rep_fecha arreglo[MAX])
{
    for (int i = 0; i < MAX; i++)
        printf("%d/%d/%d\n", arreglo[i].f / 10000, 
                             (arreglo[i].f /100) % 100,
                             arreglo[i].f % 100);
}

