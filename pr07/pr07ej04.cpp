# include <stdio.h>

# define N 100

typedef unsigned int nat;
typedef bool * set;

void inicializar(set &c) {
    for (nat i = 0; i < N; ++i)
        c[i] = false;
}

bool esVacio(set c) {
    nat i = 0;
    while (i < N && !c[i])
        ++i;
    return i == N;
}

/* Precondición: x > 0 && x <= n */
bool pertenece(nat x, set &c) {
    return c[x + 1];
}

/* Precondición: x > 0 && x <= n */
void incluir(nat x, set &c) {
    c[x + 1] = true;
}

/* Precondición: x > 0 && x <= n */
void excluir(nat x, set &c) {
    c[x + 1] = false;
}

void Union(set a, set b, set &c) {
    for (nat i = 0; i < N; ++i)
        c[i] = a[i] || b[i];
}

void Interseccion(set a, set b, set &c) {
    for (nat i = 0; i < N; ++i)
        c[i] = a[i] && b[i];
}

void Diferencia(set a, set b, set &c) {
    for (nat i = 0; i < N; ++i)
        c[i] = a[i] && !b[i];
}
