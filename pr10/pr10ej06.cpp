# include <stdio.h>

typedef unsigned int nat;
typedef int * T;            // Declaración auxiliar para compilación

// *** TAD PILA-COLA ***

// ESPECIFICACIÓN

// Representación del tipo de datos
/* Las pila-colas son estructuras que permiten almacenar a los sumo 'K'
 * elementos de tipo 'T', donde se respeta la política LIFO. */
struct repPC;
typedef repPC * PC;

// Constructoras

/* Crea y devuelve una pila-cola vacía (sin elementos) que puede
 * almacenar a los sumo 'K' elementos. */
PC crearPC(nat K);

/* Agrega el elemento 'elem' a 'pc'. Si, antes de la inserción, 'pc'
 * tiene 'K' elementos, entonces elimina el más antiguo. */
void apilarPC(T elem, PC &pc);

// Selectoras

/* Devuelve el elemento más nuevo de 'pc' (el último ingresado). */
/* Precondición: !esVaciaPC(pc). */ 
T topePC(PC pc);

// Destructoras

/* Elimina el elemento más nuevo de 'pc' (el último ingresado). */
/* Precondición: !esVaciaPC(pc). */ 
void desapilarPC(PC &pc);

/* Elimina la estructura 'pc' y libera la memoria asociada. */
/* Poscondición: pc == NULL. */ 
void borrarPC(PC &pc);

// Predicados

/* Devuelve 'true' si solo si 'pc' no tiene elementos. */
bool esVaciaPC(PC pc);

// IMPLEMENTACIÓN

struct nodoPC {
    T elem;
    nodoPC * ant;
    nodoPC * sig;
};

struct repPC {
    nat cant, max;
    nodoPC * primero;
    nodoPC * ultimo;
};

PC crearPC(nat K) {
    PC pc = new repPC;
    pc->cant = 0;
    pc->max = K;
    pc->primero = pc->ultimo = NULL;
    return pc;
}

// Procedimiento auxiliar para apilarPC
void desencolarPC(PC &pc) {
    --pc->cant;
    nodoPC * aux = pc->ultimo;
    pc->ultimo = aux->ant;
    pc->ultimo->sig = NULL;
    delete aux;
}

void apilarPC(T elem, PC &pc) {
    nodoPC * npc = new nodoPC;
    npc->elem = elem;
    npc->ant = NULL;
    npc->sig = pc->primero;
    ++pc->cant;
    pc->primero->ant = npc;
    pc->primero = npc;
    if (pc->cant > pc->max)
        desencolarPC(pc);
}

T topePC(PC pc) {
    return pc->primero->elem;
}

void desapilarPC(PC &pc) {
    --pc->cant;
    nodoPC * aux = pc->primero;
    pc->primero = aux->sig;
    pc->primero->ant = NULL;
    delete aux;
}

void borrarPC(PC &pc) {
    while (esVaciaPC(pc))
        desapilarPC(pc);
    delete pc;
    pc = NULL;
}

bool esVaciaPC(PC pc) {
    return pc->cant == 0;
}
