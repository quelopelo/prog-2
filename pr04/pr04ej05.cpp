#include <stdio.h>

struct nodoAG {
    int dato ;
    nodoAG *pH ;
    nodoAG *sH ;
};
typedef nodoAG * AG;

/* Dado un entero x retorna un árbol que sólo contiene a x (como una
 * hoja).*/
AG arbolHoja (int x);

/* Dado un árbol, retorna true si y solo si el árbol es un árbol hoja
 * (tiene un solo elemento) */
bool esArbolHoja (AG ag);

/* Dados un árbol y un entero x, retorna true si y solo si x pertenece
 * al árbol. */
bool pertenece (AG ag, int x);

/* Dados un árbol y un entero x, retorna el árbol con el elemento x si
 * y solo si x pertenece al árbol. En caso contrario, retorna NULL. */
AG buscar (AG ag, int x);

/* Dados un árbol y dos enteros h y p, inserta a h como el primer hijo
 * de p en el árbol (hijo más a la izquierda) si p pertenece al árbol y
 * h no pertenece al árbol. En caso contrario la operación no tiene
 * efecto. */
void insertar (AG ag, int h, int p);

/* Dados un árbol y un entero x, elimina a x del árbol si es una hoja
 * del árbol y no es la raíz del mismo. En caso contrario la operación
 * no tiene efecto. Al eliminar el elemento se debe liberar la memoria
 * asignada a él. */
void borrar (AG ag, int x);

/* Dado un árbol, elimina todos sus elementos */
void borrarArbol (AG &ag);

/* Dados un árbol y un entero x, elimina a x del árbol, si pertenece al
 * árbol y no es la raíz del mismo. En caso contrario la operación no
 * tiene efecto. Al eliminar el elemento se deberá liberar la memoria
 * asignada a los elementos que están en el subárbol dependiente de
 * éste. */
void borrarSub (AG ag, int x);

int main() {
    return 0;
}

AG arbolHoja (int x) {
    AG ag = new nodoAG;
    ag->dato = x;
    ag->pH = NULL;
    ag->sH = NULL;
    return ag;
}

bool esArbolHoja (AG ag) {
    return ag != NULL && ag->pH == NULL && ag->sH == NULL;
}

bool pertenece (AG ag, int x) {
    if (ag == NULL)
        return false;
    else
        if (ag->dato == x)
            return true;
        else
            return pertenece(ag->pH, x) || pertenece(ag->sH, x);
}

AG buscar (AG ag, int x) {
    if (ag == NULL)
        return NULL;
    else
        if (ag->dato == x)
            return ag;
        else {
            AG aux = buscar(ag->pH, x);
            if (aux != NULL)
                return aux;
            else
                return buscar(ag->sH, x);
        }
}

void insertar (AG ag, int h, int p) {
    if (!pertenece(ag, h)) {
        ag = buscar(ag, p);
        if (ag != NULL) {
            AG nuevo = new nodoAG;
            nuevo->dato = h;
            nuevo->pH = NULL;
            nuevo->sH = ag->pH;
            ag->pH = nuevo;
        }
    }
}

bool borrarAux(AG &ag, int x) {
    if (ag == NULL)
        return false;
    else {
        if (ag->dato == x) {
            if (esArbolHoja(ag)) {
                delete ag;
                ag = NULL;
            }
            return true;
        }
        else
            return borrarAux(ag->pH, x) || borrarAux(ag->sH, x);
    }
}

void borrar (AG ag, int x) {
    if (ag != NULL && ag->dato != x)
        borrarAux(ag, x);
}

void borrarArbol (AG &ag) {
    borrarArbol(ag->pH);
    borrarArbol(ag->sH);
    delete ag;
    ag = NULL;
}

bool borrarSubAux (AG &ag, int x) {
    if (ag == NULL)
        return false;
    else {
        if (ag->dato == x) {
            AG aux = ag;
            ag = ag->sH;
            aux->sH = NULL;
            borrarArbol(aux);
            return true;
        }
        else 
            return borrarSubAux(ag->pH, x) || borrarSubAux(ag->sH, x);
    }
}

void borrarSub (AG ag, int x) {
    if (ag != NULL && ag->dato != x)
        borrarSubAux(ag, x);
}
