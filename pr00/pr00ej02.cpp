# include <math.h>  
# include <stdio.h>

bool esPrimo(int n);

int main()
{
    int a, b, i;
    
    printf("Escriba dos números naturales tal que A < B\n");
    printf(" A = ");
    scanf("%d", &a);
    printf(" B = ");
    scanf("%d", &b);
    
    printf("Los números primos en el intervalo [A B] son:\n");
    for (i = a; i <= b; i++)
        if (esPrimo(i))
            printf(" %d", i);
    printf("\n");
    
    return 0;
}

bool esPrimo(int n)
{
    int i, m;
    
    i = 2;
    m = floor(sqrt(n));
    while ((i <= m) && (n % i != 0))
        i++;
    
    return i > m;
}
