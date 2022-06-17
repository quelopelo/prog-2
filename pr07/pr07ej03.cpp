# include <stdio.h>

typedef unsigned int nat;

// --- TAD Árbol AVL ---

struct nodo_AVL {
    int value;
    nat height;
    nodo_AVL *left, *right;
};
typedef nodo_AVL * TAVL;

TAVL nuevoConjunto() {
    return NULL;
}

bool esVacio(TAVL avl) {
    return avl == NULL;
}

TAVL buscar(int val, TAVL avl) {
    while (!esVacio(avl) && avl->value != val)
        if (avl->value > val)
            avl = avl->left;
        else
            avl = avl->right;
    return avl;
}

bool pertenece(int val, TAVL avl) {
    return !(esVacio(buscar(val, avl)));
}

nat altura(TAVL avl) {
    if (esVacio(avl))
        return 0;
    else
        return avl->height;
}

/* Precondición: avl != NULL */
nat nuevaAltura(TAVL avl) {
    nat hl = altura(avl->left);
    nat hr = altura(avl->right);
    return ((hl > hr) ? hl : hr) + 1;
}

/* Precondición: avl != NULL && avl->right != NULL */
TAVL rotarL(TAVL avl) {
    TAVL aux = avl->left;
    avl->left = aux->right;
    aux->right = avl;
    avl->height = nuevaAltura(avl);
    aux->height = nuevaAltura(aux);
    return aux;
    
}

/* Precondición: avl != NULL && avl->right != NULL */
TAVL rotarR(TAVL avl) {
    TAVL aux = avl->right;
    avl->right = aux->left;
    aux->left = avl;
    avl->height = nuevaAltura(avl);
    aux->height = nuevaAltura(aux);
    return aux;
}

/* Precondición: avl != NULL && avl->left != NULL &&
 * avl->left->right != NULL */
TAVL rotarLR(TAVL avl) {
    avl->left = rotarR(avl->left);
    return rotarL(avl);
}

/* Precondición: avl != NULL && avl->right != NULL %%
 * avl->rigth->left != NULL */
TAVL rotarRL(TAVL avl) {
    avl->right = rotarL(avl->right);
    return rotarR(avl);
}

/* Precondición: avl != NULL */
TAVL balancear(TAVL avl) {
    nat hl = altura(avl->left);
    nat hr = altura(avl->right);
    if (hl - hr < 2 && hr - hl < 2)
        avl->height = nuevaAltura(avl);
    else if (hl > hr)
        if (altura(avl->left->left) > altura(avl->left->right))
            rotarL(avl);
        else
            rotarLR(avl);
    else
        if (altura(avl->right->right) > altura(avl->right->left))
            rotarR(avl);
        else
            rotarRL(avl);
    return avl;
}

TAVL insertar(int val, TAVL avl) {
    if (esVacio(avl)) {
        avl = new nodo_AVL;
        avl->value = val;
        avl->height = 1;
        avl->left = avl->right = NULL;
        return avl;
    }
    else
        if (avl->value == val)
            return avl;
        else if (avl->value > val)
            avl->left = insertar(val, avl->left);
        else
            avl->right = insertar(val, avl->right);
    return balancear(avl);
}

/* Precondición: avl != NULL */
TAVL buscarBorrarMax(TAVL avl, int &max) {
    if (esVacio(avl->right)) {
        TAVL aux = avl->left;
        max = avl->value;
        delete avl;
        return aux;
    }
    else {
        avl->right = buscarBorrarMax(avl->right, max);
        return balancear(avl);
    }
}

TAVL borrar(int val, TAVL avl) {
    if (esVacio(avl))
        return avl;
    else
        if (avl->value == val)
            if (esVacio(avl->left)) {
                TAVL aux = avl->right;
                delete avl;
                return aux;
            }
            else if (esVacio(avl->right)) {
                TAVL aux = avl->left;
                delete avl;
                return aux;
            }
            else {
                int max;
                avl->left = buscarBorrarMax(avl->left, max);
                avl->value = max;
            }
        else if (avl->value > val)
            avl->left = borrar(val, avl->left);
        else
            avl->right = borrar(val, avl->right);
    return balancear(avl);
}

// --- TAD Pila ---

struct nodo_Pila {
    TAVL avl;
    nodo_Pila *next;
};
typedef nodo_Pila * TPila;

TPila nuevaPila() {
    return NULL;
}

/* Precondición: p != NULL */
int consultar(TPila p) {
    return p->avl->value;
}

TPila encolar(TPila p, TAVL avl) {
    TPila n = new nodo_Pila;
    n->avl = avl;
    n->next = p;
    return n;
}

/* Precondición: p != NULL */
TPila desencolar(TPila p) {
    TPila n = p->next;
    delete p;
    return n;
}

void borrarPila(TPila p) {
    while (p != NULL)
        p = desencolar(p);
    delete p;
}

// --- Aplicaciones de unión, intersección y diferencia ---
/* Nota: las implementaciones de estas aplicaciones no están optimizadas */

TPila linealizarAux(TPila p, TAVL avl) {
    p = linealizarAux(p, avl->right);
    p = encolar(p, avl);
    p = linealizarAux(p, avl->left);
    return p;
}

TPila linealizar(TAVL avl) {
    TPila p = nuevaPila();
    return linealizarAux(p, avl);
}

TAVL Union(TAVL a1, TAVL a2) {
    TAVL avl = nuevoConjunto();
    TPila p1 = linealizar(a1);
    TPila p2 = linealizar(a2);
    while (p1 != NULL) {
        avl = insertar(consultar(p1), avl);
        p1 = desencolar(p1);
    }
    while (p2 != NULL) {
        avl = insertar(consultar(p2), avl);
        p2 = desencolar(p2);
    }
    delete p1;
    delete p2;
    return avl;
}

TAVL Interseccion(TAVL a1, TAVL a2) {
    TAVL avl = nuevoConjunto();
    TPila p1 = linealizar(a1);
    TPila p2 = linealizar(a2);
    int v1, v2;
    while (p1 != NULL && p2 != NULL) {
        v1 = consultar(p1);
        v2 = consultar(p2);
        if (v1 == v2) {
            avl = insertar(v1, avl);
            p1 = desencolar(p1);
            p2 = desencolar(p2);
        }
        else if (v1 > v2)
            p2 = desencolar(p2);
        else
            p1 = desencolar(p1);
    }
    delete p1;
    delete p2;
    return avl;
}

TAVL Diferencia(TAVL a1, TAVL a2) {
    TAVL avl = nuevoConjunto();
    TPila p1 = linealizar(a1);
    TPila p2 = linealizar(a2);
    while (p1 != NULL) {
        avl = insertar(consultar(p1), avl);
        p1 = desencolar(p1);
    }
    while (p2 != NULL) {
        avl = borrar(consultar(p2), avl);
        p2 = desencolar(p2);
    }
    delete p1;
    delete p2;
    return avl;
}
