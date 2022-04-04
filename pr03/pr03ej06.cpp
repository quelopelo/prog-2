#include <stdio.h>

struct nodo {
    int elem;
    nodo *sig;
};
struct cabezal {
    nodo *primero;
    nodo *actual;
};
typedef cabezal * lista;
typedef unsigned int uint;

/* Crea una lista vacía. */
lista null ();

/* Dada una lista l no vacía, coloca la posición actual al inicio de l. */
void start (lista l);

/* Dada una lista l no vacía, mueve la posición actual al siguiente nodo
 * (elemento). En caso de que la posición actual sea el final de la
 * lista, coloca la posición actual al inicio de la lista (tiene un
 * comportamiento circular). */
void next (lista l);

/* Dados un entero x y una lista l, inserta el elemento x luego de la
 * posición actual en la lista. La posición actual pasa a ser el
 * elemento (nodo) recién insertado. Si la lista l está vacía, el
 * resultado es la lista unitaria que contiene a x, siendo este elemento
 * la posición actual en la lista resultado. */
void insert (lista l, int x);

/* Dada una lista l no vacía, retorna el elemento en la posición actual
 * de l. */
int element (lista l);

/* Dada una lista, imprime en un renglón sus elementos. */
void imprimirLista (nodo *l);

int main() {
    
    lista l = null();
    
    insert(l, 1);
    printf("Lista (1):");
    imprimirLista(l->primero);
    
    insert(l, 2);
    insert(l, 3);
    printf("Lista (2):");
    imprimirLista(l->primero);
    
    start(l);
    next(l);
    insert(l, 5);
    printf("Lista (3):");
    imprimirLista(l->primero);
    
    return 0;
}

lista null () {
    lista l = new cabezal;
    l->primero = NULL;
    l->actual = NULL;
    return l;
}

void start (lista l) {
    l->actual = l->primero;
}

void next (lista l) {
    if (l->actual != NULL) {
        if (l->actual->sig == NULL)
            l->actual = l->primero;
        else
            l->actual = l->actual->sig;
        }
}

void insert (lista l, int x) {
    nodo *nuevo = new nodo;
    nuevo->elem = x;
    if (l->actual == NULL) {
        nuevo->sig = NULL;
        l->primero = nuevo;
        l->actual = nuevo;
    }
    else {
        nuevo->sig = l->actual->sig;
        l->actual->sig = nuevo;
        l->actual = nuevo;
    }
}

int element (lista l) {
    return l->actual->elem;
}

void imprimirLista (nodo *l) {
    while (l != NULL) {
        printf(" %d", l->elem);
        l = l->sig;
    }
    printf("\n");
}
