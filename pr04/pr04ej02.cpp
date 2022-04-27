#include <stdio.h>

typedef unsigned int uint;

struct nodoLista {
    uint elem ;
    nodoLista *sig ;
};
typedef nodoLista * Lista ;

struct nodoAB {
    uint elem;
    nodoAB *izq, *der;
};
typedef nodoAB * AB;

/* Recibe un árbol b y retorna una lista con los elementos de b
 * ordenados según la recorrida en orden de b */
Lista enOrden (AB b);

/* Recibe un árbol b y retorna una lista con los elementos de b
 * ordenados según la recorrida pre orden de b */
Lista preOrden (AB b);

/* Recibe un árbol b y retorna una lista con los elementos de b
 * ordenados según la recorrida post orden de b */
Lista postOrden (AB b);

/* Recibe un árbol b y una lista l, y retorna TRUE si y solo si l es 
 * igual a un camino desde la raíz a un hoja de b */
bool esCamino (AB b, Lista l);

/* Recibe un árbol b y retorna una lista con los elementos del camino
 * más largo de b (desde la raíz a una hoja). En caso de haber más de
 * un camino de igual longitud a la del camino más largo, retorna
 * cualquiera de ellos */
Lista caminoMasLargo (AB b);

/* Recibe un árbol b y retorna TRUE si y solo sí es completo. Un árbol
 * es completo cuando es estrictamente binario y todas las hojas están
 * al mismo nivel. En el práctico se le llama perfecto. */
bool esCompleto (AB b);

/* FUNCIONES DE OTROS EJERCICIOS */

/* Dados un entero x y una lista l, inserta x al final de l. */
void snoc (Lista &l, int x);

/* Recibe una lista e imprime sus elementos en un renglón. */
void imprimirLista (Lista l);

/* Retorna un árbol no vacío a partir de un natural y otros dos árboles. */
AB consArbol (uint nat, AB abizq, AB abder);

/* Recibe un árbol y retorna la atura del mismo. Si el árbol es vacío su
 * altura es 0. */
uint altura (AB ab);

/* Recibe un árbol e imprime sus elementos en orden */
void imprimirArbol (AB ab);

int main() {
    
    AB ab, abaux;
    Lista l = NULL;
    
    ab = consArbol(6, NULL, NULL);
    abaux = consArbol(5, ab, NULL);
    ab = consArbol(4, NULL, NULL);
    ab = consArbol(2, ab, abaux);
    abaux = consArbol(3, NULL, NULL);
    ab = consArbol(1, ab, abaux);
    
    printf("Árbol en orden:");
    imprimirArbol(ab);
    printf("\n----------\n");
    
    printf("Lista en orden:");
    imprimirLista(enOrden(ab));
    printf("\n");
    
    printf("Lista pre orden:");
    imprimirLista(preOrden(ab));
    printf("\n");
    
    printf("Lista post orden:");
    imprimirLista(postOrden(ab));
    printf("\n----------\n");
    
    snoc(l, 1);
    snoc(l, 2);
    snoc(l, 5);
    printf("La lista");
    imprimirLista(l);
    printf("%s es camino del árbol\n", esCamino(ab, l) ? "" : " no");
    
    snoc(l, 6);
    printf("La lista");
    imprimirLista(l);
    printf("%s es camino del árbol\n", esCamino(ab, l) ? "" : " no");
    printf("----------\n");
    
    printf("Lista con el camino más largo:");
    imprimirLista(caminoMasLargo(ab));
    printf("\n----------\n");
    
    printf("El árbol%s es completo", esCompleto(ab) ? "" : " no");
    printf("\n");
    
    return 0;
}

Lista enOrdenAux (AB b, Lista l) {
    if (b != NULL) {
        l = enOrdenAux(b->izq, l);
        Lista p = new nodoLista;
        p->elem = b->elem;
        l->sig = p;
        l = enOrdenAux(b->der, p);
    }
    return l;
}

Lista enOrden (AB b) {
    Lista l = new nodoLista;
    Lista p = enOrdenAux(b, l);
    p->sig = NULL;
    p = l->sig;
    delete l;
    return p;
}

Lista preOrdenAux (AB b, Lista l) {
    if (b != NULL) {
        Lista p = new nodoLista;
        p->elem = b->elem;
        l->sig = p;
        l = preOrdenAux(b->izq, p);
        l = preOrdenAux(b->der, l);
    }
    return l;
}

Lista preOrden (AB b) {
    Lista l = new nodoLista;
    Lista p = preOrdenAux(b, l);
    p->sig = NULL;
    p = l->sig;
    delete l;
    return p;
}

Lista postOrdenAux (AB b, Lista l) {
    if (b != NULL) {
        l = postOrdenAux(b->izq, l);
        l = postOrdenAux(b->der, l);
        Lista p = new nodoLista;
        p->elem = b->elem;
        l->sig = p;
        l = p;
    }
    return l;
}

Lista postOrden (AB b) {
    Lista l = new nodoLista;
    Lista p = postOrdenAux(b, l);
    p->sig = NULL;
    p = l->sig;
    delete l;
    return p;
}

bool esCamino (AB b, Lista l) {
    if (b == NULL)
        if (l == NULL)
            return true;
        else
            return false;
    else
        if (l == NULL)
            return false;
        else
            if (b->elem != l->elem)
                return false;
            else
                if (b->izq == NULL)
                    if (b->der == NULL)
                        return esCamino(NULL, l->sig);
                    else
                        return esCamino(b->der, l->sig);
                else
                    if (b->der == NULL)
                        return esCamino(b->izq, l->sig);
                    else
                        return esCamino(b->izq, l->sig) or
                               esCamino(b->der, l->sig);
}

Lista caminoMasLargoAux (AB b, Lista l) {
    uint hizq = altura(b->izq);
    uint hder = altura(b->der);
    if (hizq >= hder)
        if (hizq == 0) {
            l->sig = NULL;
            return l;
        }
        else {
            Lista p = new nodoLista;
            p->elem = b->izq->elem;
            l->sig = p;
            return caminoMasLargoAux(b->izq, p);
        }
    else {
        Lista p = new nodoLista;
        p->elem = b->der->elem;
        l->sig = p;
        return caminoMasLargoAux(b->der, p);
    }
}

Lista caminoMasLargo (AB b) {
    if (b == NULL)
        return NULL;
    else {
        Lista l = new nodoLista;
        l->elem = b->elem;
        caminoMasLargoAux(b, l);
        return l;
    }
}

int esCompletoAux (AB b) {
    if (b == NULL)
        return 0;
    else {
        int izq = esCompletoAux(b->izq);
        if (izq == -1)
            return -1;
        else {
            int der = esCompletoAux(b->der);
            if (der == -1)
                return -1;
            else if (izq != der)
                return -1;
            else
                return 1 + izq;
        }
    }
}

bool esCompleto (AB b) {
    return esCompletoAux(b) >= 0;
}

/* FUNCIONES DE OTROS EJERCICIOS */

void snoc (Lista &l, int x) {
    Lista p = new nodoLista;
    p->elem = x;
    if (l == NULL) {
        p->sig = NULL;
        l = p;
    }
    else {
        Lista aux = l;
        while (aux->sig != NULL)
            aux = aux->sig;
        p->sig = NULL;
        aux->sig = p;
    }
}

void imprimirLista (Lista l) {
    while (l != NULL) {
        printf(" %d", l->elem);
        l = l->sig;
    }
}

AB consArbol (uint nat, AB abizq, AB abder) {
    AB raiz = new nodoAB;
    raiz->elem = nat;
    raiz->izq = abizq;
    raiz->der = abder;
    return raiz;
}

uint altura (AB ab) {
    if (ab == NULL)
        return 0;
    else {
        uint izq = altura(ab->izq);
        uint der = altura(ab->der);
        return 1 + ((izq >= der) ? izq : der);
    }
}

void imprimirArbol (AB ab) {
    if (ab != NULL) {
        imprimirArbol(ab->izq);
        printf(" %d", ab->elem);
        imprimirArbol(ab->der);
    }
}
