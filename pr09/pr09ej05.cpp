# include <stdio.h>

typedef unsigned int nat;

struct repHeap {
    int * heap;
    nat max, top;
};
typedef repHeap * THeap;


bool estaVacio (THeap h) {
    return h->top == 0;
}

bool estaLleno (THeap h) {
    return h->top == h->max;
}

int evaluar (THeap h, nat i) {
    return h->heap[i];
}

// Precondición: !estaVacio(h)
int minimo (THeap h) {
    return h->heap[0];
}

nat padre (nat i) {
    return i / 2 + i % 2 - 1;
}

nat hijo1 (nat i) {
    return 2 * i + 1;
}

nat hijo2 (nat i) {
    return hijo1(i) + 1;
}

int buscarAux (THeap h, int val, nat i) {
    if (i >= h->top || evaluar(h, i) > val)
        return -1;
    else if (evaluar(h, i) == val)
        return i;
    else {
        int aux = buscarAux(h, val, hijo1(i));
        if (aux >= 0)
            return aux;
        else
            return buscarAux(h, val, hijo2(i));
    }
}

int buscar (THeap h, int val) {
    return buscarAux(h, val, 0);
}
