# include <stdio.h>

// Tipos de datos auxiliares para compilar
typedef int * TArbol;
typedef int * TPila;
typedef int * TCola;

// TAD Árbol
bool esVacioArbol (TArbol a);
TArbol izquierda (TArbol a);
TArbol derecha (TArbol a);
void imprimirRaiz (TArbol a);

// TAD Pila
TPila crearPila ();
bool esVaciaPila (TPila p);
TArbol cima (TPila p);
void apilar (TPila &p, TArbol a);
void desapilar (TPila p);
void borrarPila (TCola &p);

// TAD Cola
TCola crearCola ();
bool esVaciaCola (TCola c);
TArbol primero (TCola c);
void encolar (TCola &c, TArbol a);
void desencolar (TCola &c);
void borrarCola (TCola &c);

void imprimirPorNiveles1Aux (TCola &c) {
    if (!esVaciaCola(c)) {
        TArbol a = primero(c);
        if (!esVacioArbol(izquierda(a))) encolar(c, izquierda(a));
        if (!esVacioArbol(derecha(a))) encolar(c, derecha(a));
        imprimirRaiz(a);
        printf(" ");
        desencolar(a);
    }
}

void imprimirPorNiveles1 (TArbol a) {
    TCola c = crearCola();
    encolar(c, a);
    imprimirPorNiveles1Aux (c);
    borrarCola(c);
}

void imprimirPorNiveles2Aux (TPila &p, TCola &c) {
    if (!esVaciaCola(c)) {
        TArbol a = primero(c);
        if (!esVacioArbol(derecha(a))) encolar(c, derecha(a));
        if (!esVacioArbol(izquierda(a))) encolar(c, izquierda(a));
        apilar(p, a);
    }
}

void imprimirPorNiveles2 (TArbol a) {
    TPila p = crearPila();
    TCola c = crearCola();
    encolar(c, a);
    imprimirPorNiveles2Aux (p, c);
    borrarCola(c);
    while (!esVaciaPila(p)) {
        imprimirRaiz(cima(p));
        desapilar(p);
    }
    borrarPila(p);
}
