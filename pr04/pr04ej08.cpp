#include <stdio.h>

struct par {
    int max, her;
};

struct nodoAG {
    int elem;
    nodoAG *pH, *sH;
};
typedef nodoAG * AG;

/* Retorna la amplitud del nodo del árbol de mayor amplitud. La amplitud
 * de un nodo se define como la cantidad de hijos (directos) que tiene.
 * Si el árbol es vacío o la raíz no tiene hijos, la función retorna 0. */
int mayorAmplitud(AG g);

int main() {
    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

par mayorAmplitudAux(AG g) {
    par res;
    if (g == NULL)
        res.max = res.her = 0;
    else {
        par res_pH = mayorAmplitudAux(g->pH);
        par res_sH = mayorAmplitudAux(g->sH);
        res.max = max(res_pH.max, res_sH.max);
        res.max = max(res.max, res_pH.her);
        res.her = res_sH.her + 1;
    }
    return res;
}

int mayorAmplitud(AG g) {
    par res = mayorAmplitudAux(g);
    return res.max;
}
