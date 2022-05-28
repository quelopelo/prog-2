# include <stdio.h>

struct nodeDeque {
    int val;
    nodeDeque *prev, *next;
};

struct headerDeque {
    nodeDeque *first, *last;
};
typedef headerDeque * Deque;

Deque null () {
    Deque d = new headerDeque;
    d->first = NULL;
    d->last = NULL;
    return d;
}

bool isEmpty (Deque d) {
    return d->first == NULL;
}

void insertFirst(int x, Deque d) {
    nodeDeque * node = new nodeDeque;
    node->val = x;
    node->prev = NULL;
    node->next = d->first;
    if (isEmpty(d)) d->last = node;
    d->first = node;
}

void insertLast(int x, Deque d) {
    nodeDeque * node = new nodeDeque;
    node->val = x;
    node->prev = d->last;
    node->next = NULL;
    if (isEmpty(d)) d->first = node;
    d->last = node;
}

// Precondición: ! isEmpty (d)
void deleteFirst(Deque d) {
    nodeDeque * node = d->first;
    d->first = node->next;
    if (d->first == NULL) d->last = NULL;
    delete node;
}

// Precondición: ! isEmpty (d)
void deleteLast(Deque d) {
    nodeDeque * node = d->last;
    d->last = node->prev;
    if (d->last == NULL) d->first = NULL;
    delete node;
}

int first(Deque d) {
    return d->first->val;
}

int last(Deque d) {
    return d->last->val;
}
