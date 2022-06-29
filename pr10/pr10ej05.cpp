# include <stdio.h>

typedef unsigned int nat;
typedef int * T;        // Declaración auxiliar para compilación

// TAD Cola de prioridad

// Representación del tipo de datos
/* Una cola de prioridad es una cola de elementos de tipo T donde las
 * prioridades están dadas por números naturales. */
struct nodoCP {
    T elem;
    nat k;
    nodoCP * sig;
};
struct repCP {
    nodoCP * primero;
    nodoCP * ultimo;
};
typedef repCP * CP;

bool esVaciaCP(CP cp);  // Declaración auxiliar para compilación

// Constructoras

/* Crea y devuelve una cola de prioridad vacía (sin elementos) . */
CP crearCP() {
    CP cp = new repCP;
    cp->primero = NULL;
    cp->ultimo = NULL;
    return cp;
}

/* Agrega el elemento 'elem' con prioridad 'k' a 'cp'. En la inserción, 
 * no se recorre la estructura. */
void agregarCP(T elem, nat k, CP &cp) {
    nodoCP * nodo = new nodoCP;
    nodo->elem = elem;
    nodo->k = k;
    nodo->sig = NULL;
    if (esVaciaCP(cp))
        cp->primero = cp->ultimo = nodo;
    else {
        cp->ultimo->sig = nodo;
        cp->ultimo = nodo;
    }
}

// Predicados
/* Retorna 'true' si y solo si 'cp' es vacía (no tiene elementos). */
bool esVaciaCP(CP cp) {
    return cp->primero == NULL;
}

// Selectoras
/* Retorna y elimina el elemento prioritario de 'cp'. El elemento
 * prioritario es el que tiene k mínimo o, en caso de haber más de uno
 * con k mínimo, el más antiguo (política FIFO). */
/* Precondición: !esVaciaCP(cp). */
T prioritarioCP(CP &cp) {
    T res;
    if (cp->primero == cp->ultimo) {
        res = cp->primero->elem;
        delete cp->primero;
        cp->primero = cp->ultimo = NULL;
    }
    else {
        nodoCP * pr = cp->primero;
        nodoCP * prant = NULL;
        nodoCP * aux = cp->primero;
        do {
            if (aux->sig->k < pr->k) {
                prant = aux;
                pr = aux->sig;
            }
            aux = aux->sig;
        }
        while (aux->sig != NULL);
        res = pr->elem;
        if (prant == NULL)
            cp->primero = pr->sig;
        else
            prant->sig = pr->sig;
        delete pr;
    }
    return res;
}

// Destructoras
/* Elimina 'cp' y libera la memoria asociada. */
void borrarCP(CP &cp) {
    while (cp->primero != NULL) {
        nodoCP * aux = cp->primero;
        cp->primero = aux->sig;
        delete aux;
    }
    delete cp;
    cp = NULL;
}
