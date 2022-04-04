#include <stdio.h>

struct nodo_doble {
    int elem;
    nodo_doble *sig;
    nodo_doble *ant;
};
typedef nodo_doble * lista;

/* Retorna una lista vacía. */
lista null ();

/* Dados un entero x y una lista l, retorna el resultado de insertar x
 * al principio de l. */
void cons (lista &l, int x);

/* Dada una lista l, verifica si l está vacía. */
bool isEmpty (lista l);

/* Dados un entero x y una lista l, retorna el resultado de eliminar
 * todas las ocurrencias de x de l. */
void removeAll (lista &l, int x);

/* Dados un entero x y una lista l ordenada, retorna el resultado de
 * insertar x en l ordenadamente. */
void insOrd (lista &l, int x);

/* Dada una lista, imprime en un renglón sus elementos. */
void imprimirLista (lista l);

int main() {
    
    lista l = null();
    
    cons(l, 3);
    printf("Lista (1):");
    imprimirLista(l);
    
    cons(l, 5);
    cons(l, 2);
    cons(l, 3);
    cons(l, 3);
    printf("Lista (2):");
    imprimirLista(l);
    
    removeAll(l, 3);
    printf("Lista (3):");
    imprimirLista(l);
    
    insOrd (l, 1);
    insOrd (l, 4);
    insOrd (l, 8);
    insOrd (l, 1);
    printf("Lista (4):");
    imprimirLista(l);
    
    return 0;
}

lista null () {
    return NULL;
}

void cons (lista &l, int x) {
    lista nuevo = new nodo_doble;
    nuevo->elem = x;
    nuevo->ant = NULL;
    if (isEmpty(l)) {
        nuevo->sig = NULL;
    }
    else {
        nuevo->sig = l;
        l->ant = nuevo;
    }
    l = nuevo;
}

bool isEmpty (lista l) {
    return l == NULL;
}

void removeAll (lista &l, int x)
{
    while (!isEmpty(l) && l->elem == x) {
        lista borrar = l;
        l = l->sig;
        delete borrar;
    }
    if (!isEmpty(l)) {
        l->ant = NULL;
        lista aux = l;
        while (!isEmpty(aux->sig))
            if (l->elem == x) {
                lista borrar = aux;
                aux = aux->sig;
                borrar->ant->sig = aux;
                aux->ant = borrar->ant;
                delete borrar;
            }
            else
                aux = aux->sig;
        if (aux->elem == x) {
            aux->ant->sig = NULL;
            delete aux;
        }
    }
}

void insOrd (lista &l, int x) {
    lista p = new nodo_doble;
    p->elem = x;
    if (isEmpty(l)) {
        p->ant = NULL;
        p->sig = NULL;
        l = p;
    }
    else {
        lista aux1 = NULL;
        lista aux2 = l;
        while (!isEmpty(aux2) && x > aux2->elem) {
            aux1 = aux2;
            aux2 = aux2->sig;
        }
        p->ant = aux1;
        p->sig = aux2;
        if (!isEmpty(aux1))
            aux1->sig = p;
        else
            l = p;
        if (!isEmpty(aux2))
            aux2->ant = p;
    }
    
}

void imprimirLista (lista l) {
    while (l != NULL) {
        printf(" %d", l->elem);
        l = l->sig;
    }
    printf("\n");
}
