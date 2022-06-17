# include <stdio.h>

typedef unsigned int nat;

struct nodo_AVL {
    int value;
    nat height;
    nodo_AVL *left, *right;
};
typedef nodo_AVL * TAVL;

TAVL buscar(int val, TAVL avl) {
    while (avl != NULL && avl->value != val)
        if (avl->value > val)
            avl = avl->left;
        else
            avl = avl->right;
    return avl;
}

nat altura(TAVL avl) {
    if (avl == NULL)
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
    if (avl == NULL) {
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
    if (avl->right == NULL) {
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
    if (avl == NULL)
        return avl;
    else
        if (avl->value == val)
            if (avl->left == NULL) {
                TAVL aux = avl->right;
                delete avl;
                return aux;
            }
            else if (avl->right == NULL) {
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
