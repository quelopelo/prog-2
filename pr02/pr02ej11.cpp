#include <math.h>
#include <stdio.h>

typedef unsigned int uint;

/* Devuelve la aproximación de e^x hasta el término que sea menor a tol.
Devuelve en 'cantidad' la cantidad de términos evaluados. */
float expAprox (float x, float tol, uint &cantidad);

int main()
{
    float x, tol;
    
    printf("Ingrese un real x tal que 0 ≤ x < 1: ");
    scanf("%f", &x);
    printf("Ingrese una tolerancia para la aproximación: ");
    scanf("%f", &tol);
    
    printf("La evaluación de e^x es: %.6f\n", exp(x));
    
    uint cant = 0;
    printf("La aproximación de e^x es: %.6f\n", expAprox(x, tol, cant));
    printf("En la aproximación se evaluaron %d términos\n", cant);
    
    return 0;
}

float expAprox (float x, float tol, uint &cantidad)
{
    cantidad += 1;
    if (tol > 1)
        return 1;
    else
    {
        float aux = x / cantidad;
        return 1 + aux * expAprox(x, tol / aux, cantidad);
    }
}
