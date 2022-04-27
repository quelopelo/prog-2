#include <stdio.h>

typedef unsigned int uint;

struct nodoAB {
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB * AB;

/* Retorna un árbol no vacío a partir de un natural y otros dos árboles. */
AB consArbol (uint nat, AB abizq, AB abder);

/* Recibe un árbol y retorna la cantidad de elementos del mismo. */
uint contarElems (AB ab);

/* Recibe un árbol y retorna la cantidad de hojas (nodos cuyos ambos
 * subárboles son vacíos) del mismo. */
uint contarHojas (AB ab);

/* Recibe un árbol y retorna la atura del mismo. Si el árbol es vacío su
 * altura es 0. */
uint altura (AB ab);

/* Recibe un árbol y retorna una copia limpia del mismo. */
AB copiar (AB ab);

/* Recibe un árbol y elimina del mismo todos los nodos, liberando la
 * memoria asociada a cada uno de ellos. */
void liberarArbol (AB &ab);

/* Recibe un árbol y lo imprime en orden */
void imprimirArbol (AB ab);

int main() {
    
    AB ab1, ab2;
    
    ab1 = consArbol(6, NULL, NULL);
    ab2 = consArbol(5, ab1, NULL);
    ab1 = consArbol(4, NULL, NULL);
    ab1 = consArbol(2, ab1, ab2);
    ab2 = consArbol(3, NULL, NULL);
    ab1 = consArbol(1, ab1, ab2);
    
    printf("Árbol original en orden:");
    imprimirArbol(ab1);
    printf("\n");
    
    printf("Cantidad de elementos: %d\n", contarElems(ab1));
    printf("Cantidad de hojas: %d\n", contarHojas(ab1));
    printf("Altura: %d\n", altura(ab1));
    
    ab2 = copiar(ab1);
    printf("Árbol copia en orden:");
    imprimirArbol(ab2);
    printf("\n");
    
    liberarArbol(ab2);
    printf("Árbol con memoria liberada:");
    imprimirArbol(ab2);
    printf("\n");
    
    return 0;
}

AB consArbol (uint nat, AB abizq, AB abder) {
    AB raiz = new nodoAB;
    raiz->elem = nat;
    raiz->izq = abizq;
    raiz->der = abder;
    return raiz;
}

uint contarElems (AB ab) {
    if (ab == NULL)
        return 0;
    else
        return 1 + contarElems(ab->izq) + contarElems(ab->der);
}

uint contarHojas (AB ab) {
    if (ab == NULL)
        return 0;
    else
        if (ab->izq == NULL && ab->der ==NULL)
            return 1;
        else
            return contarHojas(ab->izq) + contarHojas(ab->der);
}

uint altura (AB ab) {
    if (ab == NULL)
        return 0;
    else {
        uint izq = altura(ab->izq);
        uint der = altura(ab->der);
        return 1 + ((izq >= der) ? izq : der);
    }
}

AB copiar (AB ab) {
    if (ab == NULL)
        return NULL;
    else {
        AB nodo = new nodoAB;
        nodo->elem = ab->elem;
        nodo->izq = copiar(ab->izq);
        nodo->der = copiar(ab->der);
        return nodo;
    }
}

void liberarArbol (AB &ab) {
    if (ab != NULL) {
        liberarArbol(ab->izq);
        liberarArbol(ab->der);
        delete ab;
        ab = NULL;
    }
}

void imprimirArbol (AB ab) {
    if (ab != NULL) {
        imprimirArbol(ab->izq);
        printf(" %d", ab->elem);
        imprimirArbol(ab->der);
    }
}
