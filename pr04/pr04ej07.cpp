#include <stdio.h>

struct nodoLista {
    int elem;
    nodoLista *sig;
};
typedef nodoLista * Lista;

struct nodoAG {
    int elem;
    nodoAG *pH, *sH;
};
typedef nodoAG * AG;

/* Dada una lista de enteros y un árbol general de enteros, retorne
 * TRUE si y sólo si la lista es un prefijo de algún camino del árbol
 * general, comenzando desde la raíz. Se dice que la secuencia x es
 * prefijo de la secuencia z si z es xy, esto es, la concatenación de x
 * e y. Cualquiera de las secuencias x, y, z pueden ser vacías. En
 * particular si x es vacía es prefijo de cualquier secuencia, y toda
 * secuencia es prefijo de de sí misma. */
bool esPrefijo (Lista prefijo, AG ag);

int main() {
    return 0;
}

bool esPrefijo (Lista prefijo, AG ag) {
    if (prefijo == NULL)
        return true;
    else
        if (ag == NULL)
            return false;
        else
            if (prefijo->elem == ag->elem)
                return esPrefijo(prefijo->sig, ag->pH);
            else
                return esPrefijo(prefijo, ag->sH);
}
