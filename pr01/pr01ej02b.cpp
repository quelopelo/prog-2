# include <stdio.h>

# include "pr01ej02a.h"

# define MAX 3

int main()
{
    TInfo registro[MAX];
    
    registro[0] = crearInfo(3, 67.1);
    registro[1] = crearInfo(5, 98.3);
    registro[2] = crearInfo(7, 103.5);
    
    for (int i = 0; i < MAX; i++)
    {
        printf("-> Paciente %d\n", i+1);
        printf("Edad: %d\n", natInfo(registro[i]));
        printf("Altura: %.1f\n\n", realInfo(registro[i]));
    };
    
    return 0;
}
