# include <stdio.h>

typedef unsigned int nat;

struct nodoCadena {
    nat pos;
    bool live;
    nodoCadena *next;
};
typedef nodoCadena * TCadena;

/* Crea una cadena con n nodos numerados */
TCadena crearCadena (nat n);

/* Avanza k posiciones correspindientes a personas vigas en la cadena */
TCadena avanzarCadena (TCadena cad, nat k);

/* Borra la cadena y libera la memoria asociada */
void borrarCadena (TCadena cad);

/* Retorna la lista de dígitos que representa la secuencia de posiciones
 * que resuelven el problema de Josefo para n individuos y un k que indica
 * cada cuanto contar, asumiendo que la ejecución comienza para i=1 */
nat * posiciones (nat n, nat k);

/* Imprime las posiciones del vector */
void imprimirVector(nat * vec, nat n);

int main () {
    nat n, k;
    printf("PROBLEMA DE JOSEFO\n");
    printf("Ingrese la cantidad de individuos: ");
    scanf("%d", &n);
    printf("Ingrese cada cuanto contar: ");
    scanf("%d", &k);
    nat *pos = posiciones(n, k);
    printf("Posiciones: ");
    imprimirVector(pos, n);
    printf("\n");
    delete [] pos;
    return 0;
}

TCadena crearCadena (nat n) {
    TCadena cad = new nodoCadena;
    cad->pos = 1;
    cad->live = true;
    TCadena ant = cad;
    TCadena sig;
    for (nat i = 2; i <= n; ++i) {
        sig = new nodoCadena;
        sig->pos = i;
        sig->live = true;
        ant->next = sig;
        ant = sig;
    }
    sig->next = cad;
    return cad;
}

TCadena avanzarCadena (TCadena cad, nat k) {
    while (k > 0) {
        cad = cad->next;
        if (cad->live)
            --k;
    }
    return cad;
}

void borrarCadena (TCadena cad) {
    TCadena aux1 = cad->next;
    TCadena aux2;
    while (aux1 != cad) {
        aux2 = aux1->next;
        delete aux1;
        aux1 = aux2;
    }
    delete cad;
}

nat * posiciones (nat n, nat k) {
    nat * res = new nat[n];
    TCadena cad = crearCadena(n);
    res[0] = cad->pos;
    cad->live = false;
    for (nat i = 1; i < n; ++i) {
        cad = avanzarCadena(cad, k);
        cad->live = false;
        res[i] = cad->pos;
    }
    borrarCadena(cad);
    return res;
}

void imprimirVector(nat * vec, nat n) {
    printf("%d", vec[0]);
    for (nat i = 1; i < n; ++i)
        printf(" %d", vec[i]);
}
