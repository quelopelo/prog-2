# include <stdio.h>
# include <string.h>

# define MAX_LINEA 100

bool EsPalindrome(char *frase);

int main()
{
    char *frase = new char[MAX_LINEA];
    
    printf("Ingrese una frase: ");
    scanf("%[^\n]s", frase);
    
    if (EsPalindrome(frase))
        printf("La frase es palindrome\n");
    else
        printf("La frase NO es palidrome\n");

    delete [] frase;
    
    return 0;
}

bool EsPalindrome(char *frase)
{
    int i = 0;
    int largo = strlen(frase);
    int medio = largo / 2;
    
    while (i < medio && frase[i] == frase[largo-i-1])
        i++;
    
    return i >= medio;
}
