// Segundo parcial de 2016

# include <stdio.h>

typedef unsigned int nat;
typedef char * string;

struct nodo_pedido {
    nat clave;
    nodo_pedido *sig;
};
typedef nodo_pedido * lista_pedido;

struct str_pedidos {
    nat max, cant;
    string * pedidos;
    lista_pedido primero;
    lista_pedido ultimo;
};
typedef str_pedidos * TPedidos;

TPedidos crearVacio(nat k) {
    TPedidos p = new str_pedidos;
    p->max = k + 1;
    p->cant = 0;
    p->pedidos = new string[p->max];
    for (nat i = 0; i < p->max; ++i)
        p->pedidos[i] = NULL;
    p->primero = p->ultimo = NULL;
    return p;
}

TPedidos insertarPedido(nat i, string d, TPedidos p) {
    if (p->pedidos[i] != NULL) {
        ++p->cant;
        p->pedidos[i] = d;      // Comparte memoria
        lista_pedido n = new nodo_pedido;
        n->clave = i;
        n->sig = NULL;
        if (p->primero == NULL) {
            p->primero = n;
            p->ultimo = n;
        }
        else {
            p->ultimo->sig = n;
            p->ultimo = n;
        }
    }
    return p;
}

/* Precondicion: !esVacio(p) */
TPedidos eliminarPedidoAntiguo(TPedidos p) {
    lista_pedido n = p->primero;
    nat i = n->clave;
    --p->cant;
    delete p->pedidos[i];
    p->pedidos[i] = NULL;
    if (p->cant == 0)
        p->primero = p->ultimo = NULL;
    else
        p->primero = n->sig;
    delete n;
    return p;
}

bool esVacio(TPedidos p) {
    return p->cant == 0;
}

bool existePedido(nat i, TPedidos p) {
    return p->pedidos[i] != NULL;
}
