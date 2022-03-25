#include <math.h>
#include <stdio.h>

typedef unsigned int uint;

/* Evalúa P(x):
P[0] + ... + P[i] x^i + ... + P[n] x^n */
float horner (float * P, uint n, float x);

float hornerAux (float * P, uint n, uint pos, float x);

int main()
{
    uint grado;
    float x;
    
    printf("Ingrese el grado del polinomio: ");
    scanf("%d", &grado);
    
    float *P = new float[grado+1];
    
    for (uint i = 0; i <= grado; i++)
    {
        printf("Ingrese el coeficiente de x^%d: ", i);
        scanf("%f", &P[i]);
    }
    
    printf("Ingrese el valor de x: ");
    scanf("%f", &x);
    
    float y = 0;
    for (uint i = 0; i <= grado; i++)
        y += P[i] * pow(x, i);
    
    printf("La evaluación usando el algoritmo recursivo es: %.3f\n",
        horner(P, grado, x));
    printf("La evaluación usando el algoritmo iterativo es: %.3f\n", y);
    
    return 0;
}

float horner (float * P, uint n, float x)
{
    return hornerAux(P, n, 0, x);
}

float hornerAux (float * P, uint n, uint pos, float x)
{
    if (pos == n)
        return P[pos];
    else
        return P[pos] + x * hornerAux(P, n, pos+1, x);
}
