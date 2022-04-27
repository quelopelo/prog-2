#include <stdio.h>

typedef unsigned int uint;

struct EstInfo {
    uint nota; // dato
    int ci; // clave
};

struct nodoABB {
    EstInfo info;
    nodoABB *izq, *der;
};
typedef nodoABB * ABB;

/* Recibe un ABB no vacío b y devuelve el elemento de máximo valor en b. */
EstInfo maxABB (ABB b);

/* Recibe un ABB no vacío b y elimina el elemento de máximo valor en b. */
void removerMaxABB (ABB &b);

/* Recibe una nota n y un ABB b y devuelve un nuevo árbol solo con los
 * estudiantes que superen la nota n. */
ABB filtrado (ABB b, uint n);

int main() {
    return 0;
}

EstInfo maxABB (ABB b) {
    while (b->der != NULL)
        b = b->der;
    return b->info;
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

ABB filtrado (ABB b, uint n) {
    if (b == NULL)
        return NULL;
    else {
        ABB fizq = filtrado(b->izq, n);
        ABB fder = filtrado(b->der, n);
        if (b->info.nota > n) {
            ABB res = new nodoABB;
            res->info = b->info;
            res->izq = fizq;
            res->der = fder;
            return res;
        }
        else
            if (fizq == NULL)
                return fder;
            else if (fder == NULL)
                return fizq;
            else {
                ABB res = new nodoABB;
                res->info = maxABB(fizq);
                removerMaxABB(fizq);
                res->izq = fizq;
                res->der = fder;
                return res;
            }
    }
}
