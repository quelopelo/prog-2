# include <stdio.h>

struct nodoLEnt {
    int val;
    nodoLEnt *next;
};
typedef nodoLEnt * LEnt;

/* Crea la lista vacía. */
LEnt null () {
    return NULL;
}

/* Inserta el entero x al principio de la lista. */
void insertar (int x, LEnt & l) {
    LEnt nuevo = new nodoLEnt;
    nuevo->val = x;
    nuevo->next = l;
    l = nuevo;
}

/* Verifica si la lista está vacía. */
bool esVacia (LEnt l) {
    return l == NULL;
}

/* Devuelve el primer elemento de una lista.
 * Precondición: ! esVacia (l) */
int primero (LEnt l) {
    return l->val;
}

/* Devuelve la lista l sin su primer elemento.
 * Devuelve la memoria asociada al primer elemento.
 * Precondición: ! esVacia (l) */
void resto (LEnt & l) {
    LEnt res = l->next;
    delete l;
    l = res;
}
