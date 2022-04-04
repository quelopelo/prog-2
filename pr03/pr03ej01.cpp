#include <stdio.h>

struct nodo {
    int elem;
    nodo *sig;
};
typedef nodo * lista;

/* Dada una lista no vacía, retorna su último elemento. */
nodo last (lista l);

/* Dada una lista no vacía, retorna el promedio de sus elementos. */
float average (lista l);

/* Dados un entero x y una lista l ordenada, inserta x en l respetando
 * el órden. Comparar con la solución recursiva. */
void insOrd (lista &l, int x);

/* Dados un entero x y una lista l, inserta x al final de l. */
void snoc (lista &l, int x);

/* Dados un entero x y una lista l, elimina a x de l */
void removeAll (lista &l, int x);

/* Dadas dos listas l y p, verifica si l está incluida en p. 
 * Una lista l1 está incluida en l2 si y sólo sí existen dos listas, 
 * l3 y l4, tal que cumplen que l2 = l3l1l4. Tener en cuenta que
 * cualquier de las listas puede ser vacía. */
bool isIncluded (lista l, lista p);

/* Dada una lista, imprime en un renglón sus elementos. */
void imprimirLista (lista l);

/* Programa de prueba de las funciones implementadas. */
int main() {
    
    lista l = NULL;
    lista p = NULL;
    
    snoc(l, 4);
    printf("Lista (1):");
    imprimirLista(l);
    printf("Último: %d\n", last(l).elem);
    printf("Promedio: %.2f\n", average(l));
    
    insOrd(l, 1);
    insOrd(l, 5);
    insOrd(l, 3);
    printf("-\nLista (2):");
    imprimirLista(l);
    printf("Último: %d\n", last(l).elem);
    printf("Promedio: %.2f\n", average(l));
    
    insOrd(l, 1);
    snoc(l, 8);
    snoc(l, 1);
    printf("-\nLista (3):");
    imprimirLista(l);
    
    removeAll(l, 1);
    printf("-\nLista (4):");
    imprimirLista(l);
    
    printf("-\nLa lista");
    imprimirLista(p);
    printf("%s está en la Lista (4)\n", isIncluded(p, l) ? "SÍ" : "NO");
    
    snoc(p, 1);
    snoc(p, 3);
    printf("-\nLa lista");
    imprimirLista(p);
    printf("%s está en la Lista (4)\n", isIncluded(p, l) ? "SÍ" : "NO");
    
    removeAll(p, 1);
    printf("-\nLa lista");
    imprimirLista(p);
    printf("%s está en la Lista (4)\n", isIncluded(p, l) ? "SÍ" : "NO");
    
    insOrd(p, 4);
    insOrd(p, 8);
    insOrd(p, 5);
    printf("-\nLa lista");
    imprimirLista(p);
    printf("%s está en la Lista (4)\n", isIncluded(p, l) ? "SÍ" : "NO");
    
    return 0;
};

nodo last (lista l) {
    while (l->sig != NULL)
        l = l->sig;
    return *l;
}

float average (lista l) {
    float sum = 0, cant = 0;
    while (l != NULL) {
        sum += l->elem;
        cant++;
        l = l->sig;
    }
    return sum / cant;
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

void snoc (lista &l, int x) {
    lista p = new nodo;
    p->elem = x;
    if (l == NULL) {
        p->sig = NULL;
        l = p;
    }
    else {
        lista aux = l;
        while (aux->sig != NULL)
            aux = aux->sig;
        p->sig = NULL;
        aux->sig = p;
    }
}

void removeAll (lista &l, int x) {
    if (l != NULL) {
        lista aux = l;
        while (aux->sig != NULL)
            if (aux->sig->elem == x) {
                lista borrar = aux->sig;
                aux->sig = borrar->sig;
                delete borrar;
            }
            else
                aux = aux->sig;
        if (l->elem == x) {
            lista borrar = l;
            l = l->sig;
            delete borrar;
        }
    }
}

bool isIncluded (lista l, lista p) {
    if (l == NULL)
        return true;
    else {
        while (p != NULL) {
            if (l->elem == p->elem) {
                lista aux_l = l->sig;
                lista aux_p = p->sig;
                while (aux_l != NULL && aux_p != NULL &&
                       aux_l->elem == aux_p->elem) {
                    aux_l = aux_l->sig;
                    aux_p = aux_p->sig;
                }
                if (aux_l == NULL)
                    return true;
            }
            p = p->sig;
        }
        return false;
    }
}

void imprimirLista (lista l) {
    while (l != NULL) {
        printf(" %d", l->elem);
        l = l->sig;
    }
    printf("\n");
}
