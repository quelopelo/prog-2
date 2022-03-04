# include <stdio.h>

int MinClase(int c1, int c2, int c3, int c4, int c5);
float PromClase(int c1, int c2, int c3, int c4, int c5);

int main()
{
    int c1, c2, c3, c4, c5;
    
    printf("Ingrese cinco calificaciones: ");
    scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);
    printf("Promedio: %.2f\n", PromClase(c1, c2, c3, c4, c5));
    
    return 0;
}

float PromClase(int c1, int c2, int c3, int c4, int c5)
{
    return (c1 + c2 + c3 + c4 + c5 - MinClase(c1, c2, c3, c4, c5)) / 4.0;
}

int MinClase(int c1, int c2, int c3, int c4, int c5)
{
    int min = c1;
    
    if (c2 < min)
        min = c2;
    if (c3 < min)
        min = c3;
    if (c4 < min)
        min = c4;
    if (c5 < min)
        min = c5;
    
    return min;
}
