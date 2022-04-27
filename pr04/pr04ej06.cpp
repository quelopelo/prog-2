#include <stdio.h>

typedef unsigned int uint;

struct nodoAG {
    int elem;
    nodoAG *pH, *sH;
};
typedef nodoAG * AG;

/* Dados un árbol g de tipo AG y un entero positivo k, retorna una copia
 * de g, sin compartir memoria con éste, con todos los nodos que están
 * en un nivel menor o igual a k. En un árbol no vacío la raíz está en
 * el nivel 1. Si g es vacío o k es cero, el resultado es el árbol
 * vacío. Se asume que g->sH es NULL. */
AG copiaParcial (AG g, uint k);

int main() {
    return 0;
}

AG copiaParcial (AG g, uint k) {
    if (g == NULL || k == 0)
        return NULL;
    else {
        AG res = new nodoAG;
        res->elem = g->elem;
        res->pH = copiaParcial(g->pH, k-1);
        res->sH = copiaParcial(g->sH, k);
        return res;
    }
}
