#include <stdio.h>

typedef unsigned int uint;

void hanoi (uint N);
void hanoiAux (uint disco, char ini, char med, char fin);
void moverDisco (uint disco, char ini, char fin);

int main()
{
    uint N;
    
    printf("\nIngrese un natural positivo: ");
    scanf("%d", &N);
    
    printf("\nMOVIMIENTOS PARA LA RESOLUCIÓN DE LA TORRE DE HANOI\n\n");
    hanoi(N);
    printf("\n");
    
    return 0;
}

void hanoi (uint N)
{
    hanoiAux(N, 'A', 'B', 'C');
}

void hanoiAux (uint disco, char ini, char med, char fin)
{
    if (disco > 0)
    {
        hanoiAux(disco-1, ini, fin, med);
        moverDisco(disco, ini, fin);
        hanoiAux(disco-1, med, ini, fin);
    }
}

void moverDisco (uint disco, char ini, char fin)
{
    printf("MOVER DISCO %d DEL cilindro %c AL cilindro %c\n",
        disco, ini, fin);
}
