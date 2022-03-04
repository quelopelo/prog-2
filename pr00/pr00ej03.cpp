# include <stdio.h> 
# include <string.h>

# define MAX_LINEA 100

int Ocurrencias(char frase[MAX_LINEA], int largo, char letra);

int main()
{
    char frase[MAX_LINEA] = "Hoy es el día más hermoso de nuestra vida, querido "
                            "Sancho; los obstáculos más grandes ...";
    char letra = 'a';

    printf("La letra %c ocurre %d veces\n", letra,
        Ocurrencias(frase, strlen(frase), letra));

    return 0;
}

int Ocurrencias(char frase[MAX_LINEA], int largo, char letra)
{
    int cant = 0;
    if (largo > MAX_LINEA)
        largo = MAX_LINEA;
    
    for (int i = 0; i < largo; i++)
        if (frase[i] == letra)
            cant++;
    
    return cant;
}
