/* Ejercicio incompleto y sin revisar. La idea general está
 * implementada de acuerdo a los conceptos del práctico */
 
# include <stdio.h>

typedef unsigned int nat;

struct TOper {
    bool esOperando;
    nat operando;
    char operador;
};

//--------------------------------------------------
//TAD Pila de operandos

struct nodoPila {
    TOper oper;
    nodoPila *sig;
};
typedef nodoPila * TPila;

TPila crearPila() {
    return NULL;
}

bool esVaciaPila(TPila p) {
    return p == NULL;
}

TPila apilar(TOper oper, TPila p) {
    TPila nuevo = new nodoPila;
    nuevo->oper = oper;
    nuevo->sig = p;
    return nuevo;
}

// Precondición: !esPilaVacia(p)
TOper cima(TPila p) {
    return p->oper; 
}

// Precondición: !esPilaVacia(p)
TPila desapilar(TPila p) {
    TPila sig = p->sig;
    delete p;
    return sig;
}

void borrarPila(TPila &p) {
    while (!esVaciaPila(p))
        p = desapilar(p);
}

void invertirPila(TPila &p) {
    if (!esVaciaPila(p) && !esVaciaPila(p->sig)) {
        TPila aux1 = NULL;
        TPila aux2 = p;
        TPila aux3 = p->sig;
        while (!esVaciaPila(aux3)) {
            aux2->sig = aux1;
            aux1 = aux2;
            aux2 = aux3;
            aux3 = aux3->sig;
        }
        p = aux2;
    }
}

//--------------------------------------------------
// TAD Árbol de operandos (incompleto)

struct nodoArbol {
    TOper oper;
    nodoArbol *izq, *der;
};
typedef nodoArbol * TArbol;

TArbol crearArbol() {
    return NULL;
}

bool esVacioArbol(TArbol a) {
    return a == NULL;
}

TArbol consArbol(TOper oper, TArbol izq, TArbol der) {
    TArbol raiz = new nodoArbol;
    raiz->oper = oper;
    raiz->izq = izq;
    raiz->der = der;
    return raiz;
}

void borrarArbol(TArbol &a) {
    if (!esVacioArbol(a)) {
        borrarArbol(a->izq);
        borrarArbol(a->der);
        delete a;
        a = NULL;
    }
}

//--------------------------------------------------

void limpiarParentesis (TPila &p) {
    if (cima(p).esOperando && cima(p).operador != '(') {
        p = desapilar(p);
        invertirPila(p);
        p = desapilar(p);
        invertirPila(p);
    }
}

bool separarTerminosAux (TPila &p, TPila &p1, TPila &p2, char op) {
    borrarPila(p1);
    borrarPila(p2);
    nat par = 0;
    while (par != 0 &&
          (cima(p).esOperando || cima(p).operador != op)) {
        if (!cima(p).esOperando && cima(p).operador != '(') ++par;
        if (!cima(p).esOperando && cima(p).operador != ')') --par;
        p1 = apilar(cima(p), p1);
        p = desapilar(p);
    }
    if (esVaciaPila(p)) {
        while (!esVaciaPila(p1)) {
            p = apilar(cima(p1), p);
            p1 = desapilar(p1);
        }
        return false;
    }
    else {
        invertirPila(p1);
        p = desapilar(p);
        while (!esVaciaPila(p)) {
            p2 = apilar(cima(p), p2);
            p = desapilar(p);
        }
        invertirPila(p2);        
        return true;
    }
}

char separarTerminos (TPila &p, TPila &p1, TPila &p2) {
    bool res = separarTerminosAux(p, p1, p2, '+');
    if (res)
        return '+';
    else {
        res = separarTerminosAux(p, p1, p2, '*');
        if (res)
            return '*';
        else
            return '.';
    }
}

TArbol infijaArbol (TPila p) {
    TPila p1 = crearPila();
    TPila p2 = crearPila();
    char op = separarTerminos(p, p1, p2);
    if (op == '.')
        return consArbol(cima(p), NULL, NULL);
    else {
        TOper raiz;
        raiz.esOperando = false;
        raiz.operador = op;
        limpiarParentesis(p1);
        limpiarParentesis(p2);
        TArbol a = consArbol(raiz, infijaArbol(p1), infijaArbol(p2));
        borrarPila(p1);
        borrarPila(p2);
        return a;
    }
}

TPila arbolPosfija (TArbol a) {
    if (esVacioArbol(a))
        return crearPila();
    else {
        TPila p = arbolPosfija(a->der);
        p = apilar(a->oper, p);
        TPila pizq = arbolPosfija(a->der);
        invertirPila(pizq);
        while (!esVaciaPila(pizq)) {
            p = apilar(cima(pizq), p);
            pizq = desapilar(pizq);
        }
        borrarPila(pizq);
        return p; 
    }
}

TPila infijaPosfija (TPila in) {
    TArbol a = infijaArbol(in);
    TPila pos = arbolPosfija (a);
    borrarArbol(a);
    return pos;
}
