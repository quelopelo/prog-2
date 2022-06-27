# include <stdio.h>

# define K 10

/* Representación de una cola de impresión, que consiste un una cola de
 * prioridad de elementos de tipo 'string' con prioridades 'int'. */
typedef int * string;       // Definición auxiliar para compilación
typedef int * TCola;        // Definición auxiliar para compilación
struct repColaP {
    int cant;
    TCola * vec;
};
typedef repColaP * TColaP;

// AUXILIARES
string copiarStr(string s);

// TAD COLA
TCola crearColaVacia();
void encolar(string s, TCola &c);
bool esColaVacia(TCola c);
string primero(TCola c);
void desencolar(TCola &c);

// CONSTRUCTORAS

/* Crea y devuelve una cola de impresión vacía. */
TColaP crearCPVacia() {
    TColaP cp = new repColaP;
    cp->cant = 0;
    cp->vec = new TCola[K];
    for (int i = 0; i < K; ++i)
        cp->vec[i] = crearColaVacia();
    return cp;
}

/* Agrega 's' con prioridad 'k' a la cola de prioridad 'cp'. */
void agregarCP(string s, int k, TColaP &cp) {
    ++cp->cant;
    encolar(s, cp->vec[k-1]);
};

// PREDICADOS

/* Devuelve 'true' si solo si 'cp' no tiene elementos. */
bool esCPVacia(TColaP cp) {
    return cp->cant == 0;
};

// SELECTORAS Y DESTRUCTORAS

/* Devuelve y elimina el elemento prioritario de 'cp'. El elemento
 * prioritario es el que tenga menor prioridad o, en caso de tener la
 * misma prioridad, el que haya sido ingresado antes. */
/* Precondición: !esCPVacia(cp). */
string imprimirMinCP(TColaP &cp) {
    --cp->cant;
    int i = 0;
    while (esColaVacia(cp->vec[i]))
        ++i;
    string s = copiarStr(primero(cp->vec[i]));
    desencolar(cp->vec[i]);
    return s;
}

/* Destruye la cola de prioridad 'cp' y libera la memoria. */
void destruirCP(TColaP &cp) {
    while (!esCPVacia(cp))
        imprimirMinCP(cp);
    delete cp->vec;
    delete cp;
    cp = NULL;
}
