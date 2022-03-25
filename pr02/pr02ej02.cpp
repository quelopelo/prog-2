# include <stdio.h>
# include <string.h>

# define MAX 100

typedef unsigned int uint;

bool esPalindrome (char *frase);
bool esPalindromeAux (char *frase, uint largo, uint ind);

int main()
{
    char *frase = new char[MAX];
    
    printf("Ingrese una frase:\n ");
    scanf("%[^\n]s", frase);
    
    if (esPalindrome(frase))
        printf("La frase es palindrome\n");
    else
        printf("La frase NO es palindrome\n");
    
    delete [] frase;
    
    return 0;
}

bool esPalindrome (char *frase)
{
    return esPalindromeAux(frase, strlen(frase), 0);
}

bool esPalindromeAux (char *frase, uint largo, uint ind)
{
    bool res;
    
    if (ind >= largo/2)
        res = true;
    else
        if (frase[ind] != frase[largo-1-ind])
            res = false;
        else
            res = esPalindromeAux(frase, largo, ind+1);
    
    return res;
}
