# include <stdio.h>

typedef unsigned int nat;

struct repHeap {
    int * heap;
    nat max, top;
};
typedef repHeap * THeap;

int evaluar (THeap h, nat i) {
    return h->heap[i];
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

nat hijoMin (THeap h, nat i) {
    if (hijo1(i) + 1 >= h->top)
        return hijo1(i);
    else {
        int vh1 = evaluar(h, hijo1(i));
        int vh2 = evaluar(h, hijo2(i));
        if (vh1 <= vh2)
            return hijo1(i);
        else
            return hijo2(i);
    }
}

void intercambiar (THeap &h, nat i, nat j) {
    int temp = evaluar(h, i);
    h->heap[i] = evaluar(h, j);
    h->heap[j] = temp;
}

// Ver versión iterativa en el laboratorio
void filtradoAscendente (THeap &h, nat i) {
    nat j = padre(i);
    if (i > 0 && evaluar(h, j) > evaluar(h, i)) {
        intercambiar(h, i, j);
        filtradoAscendente(h, j);
    }
}

// Ver versión iterativa en el laboratorio
void filtradoDescendente (THeap &h, nat i) {
    nat j = hijoMin(h, i);
    if (j < h->top && evaluar(h, i) > evaluar(h, j)) {
        intercambiar(h, i, j);
        filtradoDescendente(h, j);
    }
}

bool estaVacio (THeap h) {
    return h->top == 0;
}

bool estaLleno (THeap h) {
    return h->top == h->max;
}

// Precondición: !estaLleno(h)
void insertar (THeap &h, int x) {
    nat i = h->top++;
    h->heap[i] = x;
    filtradoAscendente(h, i);
}

// Precondición: !estaVacio(h)
int minimo (THeap h) {
    return h->heap[0];
}

// Precondición: !estaVacio(h)
void eliminarMin (THeap &h) {
    nat i = --h->top;
    h->heap[0] = evaluar(h, i);
    filtradoDescendente(h, 0);
}
