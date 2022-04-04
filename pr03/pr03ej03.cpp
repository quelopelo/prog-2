#include <stdio.h>

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo * lista;

/* Dados un entero x y una lista l ordenada, inserta x en l respetando
 * el órden. Comparar con la solución iterativa. */
void insOrd (lista &l, int x);

/* Dados un entero x y una lista l, inserta x al final de l. */
void snoc (lista &l, int x);

/* Dados un entero x y una lista l, elimina a x de l */
void removeAll (lista &l, int x);

/* Dada una lista, imprime en un renglón sus elementos. */
void imprimirLista (lista l);

/* Programa de prueba de las funciones implementadas. */
int main() {
    
    lista l = NULL;
    
    snoc(l, 4);
    printf("Lista (1): ");
    imprimirLista(l);
    
    insOrd(l, 1);
    insOrd(l, 5);
    insOrd(l, 3);
    printf("Lista (2): ");
    imprimirLista(l);
    
    insOrd(l, 1);
    snoc(l, 8);
    snoc(l, 1);
    printf("Lista (3): ");
    imprimirLista(l);
    
    removeAll(l, 1);
    printf("Lista (4): ");
    imprimirLista(l);
    
    return 0;
}

void insOrd (lista &l, int x) {
    if (l == NULL || x <= l->elem) {
        lista nuevo = new nodo;
        nuevo->elem = x;
        nuevo->sig = l;
        l = nuevo;
    }
    else
        insOrd(l->sig, x);         
}

void snoc (lista &l, int x) {
    if (l == NULL) {
        l = new nodo;
        l->elem = x;
        l->sig = NULL;
    }
    else
        snoc(l->sig, x);
}

void removeAll (lista &l, int x) {
    if (l != NULL) {
        removeAll (l->sig, x);
        if (l->elem == x) {
            lista borrar = l;
            l = l->sig;
            delete borrar;
        }
    }
}

void imprimirLista (lista l) {
    while (l != NULL) {
        printf(" %d", l->elem);
        l = l->sig;
    }
    printf("\n");
}
