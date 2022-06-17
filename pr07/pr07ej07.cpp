// Segundo parcial de 2014

# include <stdio.h>

typedef unsigned int nat;
typedef char * string;

struct nodo_urna {
    string cand;
    nodo_urna *sig;
};
typedef nodo_urna * TUrna;

TUrna urnaVacia() {
    return NULL;
}

TUrna insertarVoto(string c, TUrna u) {
    TUrna n = new nodo_urna;
    n->cand = c;       // Comparte memoria
    n->sig = u;
    return n;
}

// Función auxiliar que compara dos strings
bool igualesString(string c1, string c2);

nat cantVotos(string c, TUrna u) {
    nat cant;
    while (u != NULL) {
        if (igualesString(c, u->cand))
            ++cant;
        u = u->sig;
    }
    return cant;
}
