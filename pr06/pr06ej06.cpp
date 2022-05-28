// Primer parcial de 2005

// Definición auxiliar para compilar
typedef int * LDig;

typedef unsigned int Digito;

/* Crea la lista de dígitos vacía */
LDig null ();

/* Inserta un elemento al principio de la lista de dígitos */
LDig cons (Digito x, LDig l);

/* Verifica si la lista de dígitos esta vacía */
bool empty (LDig l);

/* Retorna el primer elemento de la lista de dígitos.
 * Precondición: la lista no es vacía */
Digito head (LDig l);

/* Retorna la lista de dígitos sin su primer elemento.
 * Precondición: la lista no es vacía */
LDig tail (LDig l);

bool sumaAux (LDig l1, LDig l2, LDig &l) { 
    if (empty(l1)) {
        l = null();
        return false;
    }
    else {
        bool resto = sumaAux(tail(l1), tail(l2), l);
        Digito dig = head(l1) + head(l2);
        if (resto) ++dig;
        l = cons(dig % 10, l);
        return dig < 10;
    }
}

/* Retorna la lista de dígitos que representa al número natural
 * resultado de sumar los dos números naturales parámetros representados
 * mediante listas de dígitos.
 * Precondición: las listas tienen exactamente el mismo largo > 0 */
LDig suma (LDig l1, LDig l2) {
    LDig l;
    bool resto = sumaAux(l1, l2, l);
    if (resto) l = cons(1, l);
    return l;
}
