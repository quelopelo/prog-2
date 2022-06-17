# include <stdio.h>

typedef unsigned int nat;

struct node_Hash {
    int value;
    node_Hash *next;
};

struct header_Hash {
    node_Hash ** table;
    nat num;
    nat max;
};
typedef header_Hash * Hash;

nat hashFun(int x, nat n) {
    return x % n;
}

Hash nuevaTabla(nat n) {
    Hash h = new header_Hash;
    h->table = new node_Hash * [n];
    for (nat i = 0; i < n; ++i)
        h->table[i] = 0;
    h->num = 0;
    h->max = n;
    return h;
}

void borrarTabla(Hash h) {
    for (nat i = 0; i < h->max; ++i)
        while (h->table[i] != NULL) {
            node_Hash * n = h->table[i];
            h->table[i] = h->table[i]->next;
            delete n;
        }
    delete [] h->table;
    delete h;
}

bool existe(int x, Hash h) {
    nat i = hashFun(x, h->max);
    node_Hash * n = h->table[i];
    while (n != NULL && n->value != x)
        n = n->next;
    return n != NULL;
}

/* Precondición: !existe(x, h) */
Hash insertar(int x, Hash h) {
    nat i = hashFun(x, h->max);
    node_Hash * n = new node_Hash;
    n->value = x;
    n->next = h->table[i];
    h->table[i] = n;
    ++h->num;
    return h;
}

/* Precondición: existe(x, h) */
Hash borrar(int x, Hash h) {
    nat i = hashFun(x, h->max);
    node_Hash * n = h->table[i];
    if (n->value == x) {
        h->table[i] = h->table[i]->next;
        delete n;
    }
    else {
        while (n->next->value != x)
            n = n->next;
        node_Hash * b = n->next;
        n->next = b->next;
        delete b;
    }
    --h->num;
    return h;
}
