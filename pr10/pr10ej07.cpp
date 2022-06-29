# include <stdio.h>

typedef unsigned int nat;

// ESPECIFICACIÓN

// Representación del tipo de datos
/* Las matrices de naturales son tablas de 'n' x 'm' naturales, donde
 * donde 'n' es la cantidad de filas y 'm' la cantidad de columnas. */
struct repMatriz;
typedef repMatriz * Matriz;

/* Crea una matriz de 'n' x 'm' naturales. Asigna el valor por defecto
 * '0' a todas las entradas. */
Matriz crearMatrizNula(nat m, nat n);

/* Dados una matriz 'M', un número de fila 'f' y un número de columna
 * 'c', devuelve el natural ubicado en la entrada (f,c) de M. */
nat valorEnPos(Matriz M, nat f, nat c);

/* Dados una matriz 'M', un número de fila 'f' y un número de columna
 * 'c', asigna el natural 'x' en la entrada (f,c) de M. */
void asignarEnPos(Matriz M, nat x, nat f, nat c);

/* Dados una matriz 'M' y un número de fila 'f', imprime todos los
 * elementos de esa fila. */
void imprimirFila(Matriz M, nat f);

/* Dados una matriz 'M' y un número de columna 'c', imprime todos los
 * elementos de esa columna. */
void imprimirColumna(Matriz M, nat c);

// IMPLEMENTACIÓN

struct Nodo {
    nat fila;
    nat columna;
    nat valor;
    Nodo * sFila;
    Nodo * sColumna;
};
typedef Nodo * Lista; 

struct repMatriz {
    nat m, n;
    Lista * filas;
    Lista * columnas;
};

Matriz crearMatrizNula(nat m, nat n) {
    Matriz M = new repMatriz;
    M->m = m;
    M->n = n;
    M->filas = new Lista[n];
    for (nat i = 0; i < n; ++i)
        M->filas[i] = NULL;
    M->columnas = new Lista[m];
    for (nat i = 0; i < m; ++i)
        M->columnas[i] = NULL;
    return M;
}

// Función auxiliar de asignarEnPos
Lista crearNodo(nat x, nat f, nat c, Lista sFila, Lista sColumna) {
    Lista nodo = new Nodo;
    nodo->fila = f;
    nodo->columna = c;
    nodo->valor = x;
    nodo->sFila = sFila;
    nodo->sColumna = sColumna;
    return nodo; 
}

void asignarEnPos(Matriz M, nat x, nat f, nat c) {
    Lista lF = M->filas[f-1];
    Lista lC = M->columnas[c-1];
    if (lF != NULL)
        while (lF->sColumna != NULL && c >= lF->columna)
            lF = lF->sColumna;
    if (lC != NULL)
        while (lC->sFila != NULL && f >= lF->fila)
            lC = lC->sFila;
    if (lF == NULL || lF->columna == c)
        lF->valor = x;
    else {
        Lista nodo = crearNodo(x, f, c, lC->sFila, lF->sColumna);
        lF->sColumna = lC->sFila = nodo;
    }
}
