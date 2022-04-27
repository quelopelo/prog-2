#include <stdio.h>

typedef unsigned int uint;

struct nodoABB {
    uint elem;
    nodoABB *izq, *der;
};
typedef nodoABB * ABB;

/* Recibe un natural x, y un ABB b, e inserta x en b manteniendo su
 * cualidad de árbol binario de búsqueda. Si x pertenece al árbol la
 * operación no tiene efecto. */
void insertarABB (uint x, ABB &b);

/* Recibe un natural x y un ABB b y devuelve true si y solo si x es un
 * elemento del árbol b. */
bool perteneceABB (uint x, ABB b);

/* Recibe un ABB no vacío b y devuelve el elemento de máximo valor en b. */
uint maxABB (ABB b);

/* Recibe un ABB no vacío b y elimina el elemento de máximo valor en b. */
void removerMaxABB (ABB &b);

/* Recibe un natural x y un ABB b y elimina el elemento de valor x de b,
manteniendo su cualidad de ABB */
void removerABB (uint x, ABB &b);

/* Recibe un natural k y un ABB b y retorna el subárbol que tiene al
 * k-ésimo menor elemento de b como raíz. Si en b hay menos de k
 * elementos o k es cero, la función debe retornar el árbol vacío. Si k
 * es 1, se refiere al menor elemento del árbol, si k es 2 al 2do
 * elemento más pequeño del árbol y así sucesivamente. La solución
 * no puede visitar ningún nodo más de una vez. */
ABB kMinABB (uint k, ABB b);

/* Recibe un árbol e imprime sus elementos en orden */
void imprimirArbol (ABB ab);

int main() {
    
    ABB abb = NULL;
    
    insertarABB(12, abb);
    insertarABB(8, abb);
    insertarABB(18, abb);
    insertarABB(5, abb);
    insertarABB(11, abb);
    insertarABB(17, abb);
    insertarABB(4, abb);
    insertarABB(7, abb);
    insertarABB(2, abb);
    
    printf("Árbol en orden:");
    imprimirArbol(abb);
    printf("\n----------\n");
    
    printf("El número 1%s pertenece al árbol\n", 
           perteneceABB(1, abb) ? "" : " no");
    printf("El número 2%s pertenece al árbol\n", 
           perteneceABB(2, abb) ? "" : " no");
    printf("El número 5%s pertenece al árbol\n", 
           perteneceABB(5, abb) ? "" : " no");
    printf("----------\n");
    
    printf("El elemento de máximo valor es %d\n", maxABB(abb));
    printf("----------\n");
    
    printf("El elemento de mínimo valor es %d\n", kMinABB(1, abb)->elem);
    printf("El 3-esimo elemento de menor valor es %d\n", kMinABB(3, abb)->elem);
    printf("El 7-esimo elemento de menor valor es %d\n", kMinABB(7, abb)->elem);
    printf("El 8-esimo elemento de menor valor es %d\n", kMinABB(8, abb)->elem);
    printf("----------\n");
    
    removerMaxABB(abb);
    printf("Árbol en orden sin el máximo:");
    imprimirArbol(abb);
    printf("\n");
    
    removerABB(5, abb);
    printf("Árbol en orden sin el máximo y el 5:");
    imprimirArbol(abb);
    printf("\n");
    
    removerABB(12, abb);
    removerABB(8, abb);
    removerABB(18, abb);
    removerABB(5, abb);
    removerABB(11, abb);
    removerABB(17, abb);
    removerABB(4, abb);
    removerABB(2, abb);
    printf("Árbol en orden sin todos los elementos menos el 7:");
    imprimirArbol(abb);
    printf("\n");
    
    removerABB(7, abb);
    printf("Árbol en orden sin todos los elementos:");
    imprimirArbol(abb);
    printf("\n");
    
    return 0;
}

void insertarABB (uint x, ABB &b) {
    if (b == NULL) {
        b = new nodoABB;
        b->elem = x;
        b->izq = b->der = NULL;
    }
    else
        if (x < b->elem)
            insertarABB(x, b->izq);
        else if (x > b->elem)
            insertarABB(x, b->der);
}

bool perteneceABB (uint x, ABB b) {
    if (b == NULL)
        return false;
    else
        if (x == b->elem)
            return true;
        else if (x < b->elem)
            return perteneceABB(x, b->izq);
        else
            return perteneceABB(x, b->der);
}

uint maxABB (ABB b) {
    while (b->der != NULL)
        b = b->der;
    return b->elem;
}

void removerMaxABB (ABB &b) {
    ABB borrar;
    if (b->der == NULL) {
        borrar = b;
        b = b->izq;
    }
    else {
        ABB aux = b;
        while (aux->der->der != NULL)
            aux = aux->der;
        borrar = aux->der;
        aux->der = borrar->izq;
    }
    delete borrar;
}

uint removerMaxABBAux (ABB &b) {
    ABB borrar;
    if (b->der == NULL) {
        borrar = b;
        b = b->izq;
    }
    else {
        ABB aux = b;
        while (aux->der->der != NULL)
            aux = aux->der;
        borrar = aux->der;
        aux->der = borrar->izq;
    }
    uint max = borrar->elem;
    delete borrar;
    return max;
}

void removerABB (uint x, ABB &b) {
    if (b != NULL) {
        if (x < b->elem)
            removerABB(x, b->izq);
        else if (x > b->elem)
            removerABB(x, b->der);
        else
            if (b->izq == NULL) {
                ABB borrar = b;
                b = b->der;
                delete borrar;
            }
            else if (b->der == NULL) {
                ABB borrar = b;
                b = b->izq;
                delete borrar;
            }
            else
                b->elem = removerMaxABBAux(b->izq);
    }
}

ABB kMinABBAux (uint &k, ABB b) {
    if (b == NULL)
        return NULL;
    else {
        ABB aux;
        aux = kMinABBAux(k, b->izq);
        if (k == 0)
            return aux;
        else if (k == 1) {
            --k;
            return b;
        }
        else {
            aux = kMinABBAux(k, b->der);
            if (k == 0)
                return aux;
            else if (k == 1) {
                --k;
                return b;
            }
            else {
                --k;
                return NULL;
            }
        }
    }
}

ABB kMinABB (uint k, ABB b) {
    return kMinABBAux(k, b);
}

void imprimirArbol (ABB ab) {
    if (ab != NULL) {
        imprimirArbol(ab->izq);
        printf(" %d", ab->elem);
        imprimirArbol(ab->der);
    }
}
