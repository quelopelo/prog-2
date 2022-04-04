#include <stdio.h>

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo * lista;
typedef unsigned int uint;

/* Dado un natural i y una lista l, retorna la lista resultado de tomar
 * los primeros i elementos de l. */
lista take (lista l, uint i);

/* Dado un natural i y una lista l, retorna la lista resultado de 
 * eliminar los primeros i elementos de l. */
lista drop (lista l, uint i);

/* Dadas dos listas ordenadas l y p, genera una lista intercalando
 * ordenadamente ambas listas. */
lista mergeSort (lista l, lista p);

/* Dadas dos listas l y p, retorna una lista que contiene a los
 * elementos de l y luego a los elementos de p, en el mismo orden. 
 * Comparar con la solución recursiva. */
lista concat (lista l, lista p);

/* Dados un entero x y una lista l ordenada, inserta x en l respetando
 * el órden. Comparar con la solución recursiva. */
void insOrd (lista &l, int x);

/* Dada una lista, imprime en un renglón sus elementos. */
void imprimirLista (lista l);

/* Programa de prueba de las funciones implementadas. */
int main() {
    
    lista l = NULL;
    lista p = NULL;
    
    insOrd(l, 8);
    insOrd(l, 5);
    insOrd(l, 3);
    insOrd(l, 7);
    insOrd(l, 1);
    printf("Lista base:");
    imprimirLista(l);
    
    printf("-\nLista con los primeros 0 elementos:");
    imprimirLista(take(l, 0));
    printf("Lista con el primer elemento:");
    imprimirLista(take(l, 1));
    printf("Lista con los primeros 4 elementos:");
    imprimirLista(take(l, 4));
    printf("Lista con los primeros 6 elementos:");
    imprimirLista(take(l, 6));
    
    printf("-\nLista sin los primeros 0 elementos:");
    imprimirLista(drop(l, 0));
    printf("Lista sin el primer elemento:");
    imprimirLista(drop(l, 1));
    printf("Lista sin los primeros 4 elementos:");
    imprimirLista(drop(l, 4));
    printf("Lista sin los primeros 6 elementos:");
    imprimirLista(drop(l, 6));
    
    printf("-\nConsiderando la lista");
    imprimirLista(p);
    printf("se obtiene la lista ordenada");
    imprimirLista(mergeSort(l, p));
    printf("se obtiene la lista concatenada");
    imprimirLista(concat(l, p));
    
    insOrd(p, 2);
    printf("-\nConsiderando la lista");
    imprimirLista(p);
    printf("se obtiene la lista ordenada");
    imprimirLista(mergeSort(l, p));
    printf("se obtiene la lista concatenada");
    imprimirLista(concat(l, p));
    
    insOrd(p, 1);
    insOrd(p, 9);
    insOrd(p, 3);
    insOrd(p, 4);
    insOrd(p, 1);
    printf("-\nConsiderando la lista");
    imprimirLista(p);
    printf("se obtiene la lista ordenada");
    imprimirLista(mergeSort(l, p));
    printf("se obtiene la lista concatenada");
    imprimirLista(concat(l, p));
    
    return 0;
}

lista take (lista l, uint i) {
    lista p;
    if (l == NULL || i == 0)
        p = NULL;
    else {
        p = new nodo;
        p->elem = l->elem;
        lista aux = p;
        l = l->sig;
        while (l != NULL && --i > 0) {
            lista nuevo = new nodo;
            nuevo->elem = l->elem;
            aux->sig = nuevo;
            aux = nuevo;
            l = l->sig;
        }
        aux->sig = NULL;
    }
    return p;
}

lista drop (lista l, uint i) {
    while (l != NULL && i-- > 0)
        l = l->sig;
    lista p;
    if (l == NULL)
        p = NULL;
    else {
        p = new nodo;
        p->elem = l->elem;
        lista aux = p;
        l = l->sig;
        while (l != NULL) {
            lista nuevo = new nodo;
            nuevo->elem = l->elem;
            aux->sig = nuevo;
            aux = nuevo;
            l = l->sig;
        }
        aux->sig = NULL;
    }
    return p;
}

lista mergeSort (lista l, lista p) {
    lista res;
    if (l == NULL && p == NULL)
        res = NULL;
    else {
        res = new nodo;
        if (l == NULL) {
            res->elem = p->elem;
            p = p->sig;
        }
        else if (p == NULL) {
            res->elem = l->elem;
            l = l->sig;
        }
        else if (l->elem > p->elem) {
            res->elem = p->elem;
            p = p->sig;
        }
        else { // if l->elem <= p->elem
            res->elem = l->elem;
            l = l->sig;
        }
        lista aux = res;
        while (l != NULL && p != NULL) {
            lista nuevo = new nodo;
            if (l->elem > p->elem) {
                nuevo->elem = p->elem;
                p = p->sig;
            }
            else { // if l->elem <= p->elem
                nuevo->elem = l->elem;
                l = l->sig;
            }
            aux->sig = nuevo;
            aux = nuevo;
        }
        lista q;
        if (l == NULL)
            q = p;
        else
            q = l;
        while (q != NULL) {
            lista nuevo = new nodo;
            nuevo->elem = q->elem;
            aux->sig = nuevo;
            aux = nuevo;
            q = q->sig;
        }
        aux->sig = NULL;
    }
    return res;
}

lista concat (lista l, lista p) {
    lista res;
    if (l == NULL && p == NULL)
        res = NULL;
    else {
        res = new nodo;
        if (l == NULL) {
            res->elem = p->elem;
            p = p->sig;
        }
        else {
            res->elem = l->elem;
            l = l->sig;
        }
        lista aux = res;
        while (l != NULL) {
            lista nuevo = new nodo;
            nuevo->elem = l->elem;
            aux->sig = nuevo;
            aux = nuevo;
            l = l->sig;
        }
        while (p != NULL) {
            lista nuevo = new nodo;
            nuevo->elem = p->elem;
            aux->sig = nuevo;
            aux = nuevo;
            p = p->sig;
        }
        aux->sig = NULL;
    }
    return res;
}

void insOrd (lista &l, int x) {
    lista p = new nodo;
    p->elem = x;
    if (l == NULL || x <= l->elem) {
        p->sig = l;
        l = p;
    }
    else {
        lista aux = l;
        while (aux->sig != NULL && x > aux->sig->elem)
            aux = aux->sig;
        p->sig = aux->sig;
        aux->sig = p;
    }
}

void imprimirLista (lista l) {
    while (l != NULL) {
        printf(" %d", l->elem);
        l = l->sig;
    }
    printf("\n");
}
