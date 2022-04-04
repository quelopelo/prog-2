#include <stdio.h>

struct nodo_doble {
    int elem;
    nodo_doble *sig;
    nodo_doble *ant;
};
typedef nodo_doble * lista;
typedef unsigned int uint;

/* Dados un natural p y una lista l, retorna verdadero si, y solamente
 * si, existe un elemento en esa posición. */
bool isDefined (lista l, uint p);

/* Dados un entero x, un natural p y una lista l de longitud m, inserta
 * a x en la lista. Si p no esta definida, inserta a x en la posición m.
 * En otro caso, inserta a x en la posición p y desplaza en una posición
 * los elementos que estuvieran en las posiciones siguientes. */
void insert (lista &l, uint p, uint x);

/* Dados un natural p y una lista l, retorna el elemento en la posición
 * p. Tiene como precondición que la posición p esté definida */
uint element (lista l, uint p);

/* Dados un natural p y una lista l, elimina de la lista el elemento que
 * se encuentra en la posición p. Si la posición no está definida, la
 * operación no tiene efecto. Si la posición está definida, elimina el
 * elemento en dicha posición y desplaza en una posición los elementos
 * que estuvieran en las posiciones posteriores a p (contrae la lista). */
void remove (lista &l, uint p);

/* Dada una lista, imprime en un renglón sus elementos. */
void imprimirLista (lista l);

int main() {
    
    lista l = NULL;
    
    insert(l, 0, 1);
    printf("Lista (1):");
    imprimirLista(l);
    
    insert(l, 0, 3);
    insert(l, 5, 2);
    printf("Lista (2):");
    imprimirLista(l);
    
    remove(l, 5);
    remove(l, 0);
    printf("Lista (3):");
    imprimirLista(l);
    
    remove(l, 1);
    remove(l, 0);
    remove(l, 0);
    printf("Lista (4):");
    imprimirLista(l);
    
    return 0;
}

bool isDefined (lista l, uint p) {
    while (l != NULL && p-- > 0)
        l = l->sig;
    return l != NULL;
}

void insert (lista &l, uint p, uint x) {
    lista nuevo = new nodo_doble;
    nuevo->elem = x;
    lista ant = NULL;
    lista sig = l;
    while (sig != NULL && p-- > 0) {
        ant = sig;
        sig = sig->sig;
    }
    nuevo->ant = ant;
    nuevo->sig = sig;
    if (ant != NULL)
        ant->sig = nuevo;
    else
        l = nuevo;
    if (sig != NULL)
        sig->ant = nuevo;
}

uint element (lista l, uint p) {
    for (; p > 0; p--)
        l = l->sig;
    return l->elem;
}

void remove (lista &l, uint p) {
    lista borrar = l;
    while (borrar != NULL && p-- > 0)
        borrar = borrar->sig;
    if (borrar != NULL) {
        if (borrar->ant != NULL)
            borrar->ant->sig = borrar->sig;
        else
            l = borrar->sig;
        if (borrar->sig != NULL)
            borrar->sig->ant = borrar->ant;
        delete borrar;
    }
}

void imprimirLista (lista l) {
    while (l != NULL) {
        printf(" %d", l->elem);
        l = l->sig;
    }
    printf("\n");
}
