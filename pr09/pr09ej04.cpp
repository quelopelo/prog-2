# include <stdio.h>
# include <stdlib.h>
# include <time.h>

typedef unsigned int nat;

struct repHeap {
    int * heap;
    nat max, top;
};
typedef repHeap * THeap;

void ordenarDescendente (int * array, nat n);
void imprimirArreglo (int * array, nat n);

int main () {
    // Entrada de datos
    clock_t t;
    nat max, n;
    printf("Ingrese un largo para el arreglo: ");
    scanf("%d", &n);
    int * array = new int[n];
    printf("Ingrese un máximo para los enteros del arreglo: ");
    scanf("%d", &max);
    // Procesamiento y salida de datos
    for (nat i = 0; i < n; ++i)
        array[i] = rand() % max + 1;
    printf("El arreglo de enteros desordenado es:\n");
    imprimirArreglo (array, n);
    printf("\n");
    printf("El arreglo de enteros ordenado es:\n");
    t = clock();
    ordenarDescendente(array, n);
    t = clock() - t;
    imprimirArreglo (array, n);
    printf("\n");
    printf("El tiempo consumido en ordenar el arreglo fue: %f s\n",
           (float)t/CLOCKS_PER_SEC);
    return 0;
}

// Versión alternativa con entrada del vector
/*
int main () {
    // Entrada de datos
    nat n;
    printf("Ingrese un largo para el arreglo: ");
    scanf("%d", &n);
    int * array = new int[n];
    printf("Ingrese el arreglo de enteros:\n");
    for (nat i = 0; i < n; ++i)
        scanf("%d", &array[i]);
    // Procesamiento
    ordenarDescendente(array, n);
    // Salida de datos
    printf("El arreglo de enteros ordenado es:\n");
    imprimirArreglo (array, n);
    printf("\n");
    return 0;
}*/

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

THeap construirHeap (int * array, nat top, nat max) {
    THeap h = new repHeap;
    h->heap = new int[max];
    for (nat i = 0; i < top; ++i)
        h->heap[i] = array[i];
    h->top = top;
    h->max = max;
    for (int i = h->top - 1; i >= 0; --i)
        filtradoDescendente(h, i);
    return h;
}

void destruirHeap (THeap &h) {
    delete [] h->heap;
    delete h;
    h = NULL;
}

void ordenarDescendente (int * array, nat n) {
    THeap h = construirHeap(array, n, n);
    array[0] = minimo(h);
    for (nat i = 1; i < n; ++i) {
        eliminarMin(h);
        array[i] = minimo(h);
    }
    destruirHeap(h);
}

void imprimirArreglo (int * array, nat n) {
    printf("%d", array[0]);
    for (nat i = 1; i < n; ++i)
        printf(" %d", array[i]);
}
