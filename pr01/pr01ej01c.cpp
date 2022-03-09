# include <stdio.h>

# define MAX 3

// Registro con dia d, mes m y año a
struct rep_fecha
{
    unsigned int d;
    unsigned int m;
    unsigned int a;
};

typedef struct rep_fecha * TFecha;

/* Devuelve un 'TFecha' con dia d, mes m y año a */
TFecha crear_fecha(unsigned int d, unsigned int m, unsigned int a);

/* Devuelve true si f1 es anterior a f2 , false en otro caso */
bool comparar_fechas(TFecha f1, TFecha f2);

/* Devuelve el día correspondiente a fecha */
unsigned int dia(TFecha fecha);

/* Devuelve el mes correspondiente a fecha */
unsigned int mes(TFecha fecha);

/* Devuelve el año correspondiente a fecha */
unsigned int anio(TFecha fecha);

void ordenarFechas(TFecha arreglo[MAX]);
void imprimirFechas(TFecha arreglo[MAX]);

int main()
{
    TFecha arreglo[MAX];
    
    arreglo[0] = crear_fecha(10, 10, 2022);
    arreglo[1] = crear_fecha(15, 5, 2022);
    arreglo[2] = crear_fecha(20, 11, 1992);
    
    ordenarFechas(arreglo);
    imprimirFechas(arreglo);
    
    return 0;
};

TFecha crear_fecha(unsigned int d, unsigned int m, unsigned int a)
{
    TFecha fecha = new rep_fecha;
    fecha->d = d;
    fecha->m = m;
    fecha->a = a;
    return fecha;
}

bool comparar_fechas(TFecha f1, TFecha f2)
{
    return f1->a > f2->a || (f1->a == f2->a && f1->m > f2->m) ||
           (f1->a == f2->a && f1->m == f2->m && f1->d > f2->d);
}

unsigned int dia(TFecha fecha)
{
    return fecha->d;
}

unsigned int mes(TFecha fecha)
{
    return fecha->m;
}

unsigned int anio(TFecha fecha)
{
    return fecha->a;
}

void ordenarFechas(TFecha arreglo[MAX])
{
    TFecha temp;
    
    for (int i = MAX-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (comparar_fechas(arreglo[j], arreglo[j+1]))
            {
                temp = arreglo[j];
                arreglo[j] = arreglo[j+1];
                arreglo[j+1] = temp;
            };
}

void imprimirFechas(TFecha arreglo[MAX])
{
    for (int i = 0; i < MAX; i++)
        printf("%d/%d/%d\n", dia(arreglo[i]),
                             mes(arreglo[i]),
                             anio(arreglo[i]));
}
