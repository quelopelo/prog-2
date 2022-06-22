struct Punto {
    int x, y;
};

struct nodoPunto {
    Punto pt;
    nodoPunto *sig;
};
typedef nodoPunto * Lista;

struct repGrafica {
    Lista * hash;
    int n, N;
};
typedef repGrafica * Grafica;

/* Devuelve un punto con las coordenadas 'x' e 'y'. */
Punto CrearPunto(int x, int y);

/* Devuelve una lista vacia. */
Lista CrearLista();

/* Agrega 'pt' al inicio de 'l'. */
void Cons(Punto pt, Lista &l);

/* Devuelve el primer elemento de 'l'.
 * Precondición: !EsVaciaLista(l). */
Punto Primero(Lista l);

/* Devuelve 'l' sin el primer elemento.
 * Precondición: !EsVaciaLista(l). */
Lista Resto(Lista l);

/* Devuelve true si y sólo si 'l' es vacia. */
bool EsVaciaLista(Lista l);

/* Devuelve true si y sólo si en 'l' hay un punto cuya primera
 * coordenada es 'x'. */
bool ExisteX(int x, Lista l);

/* Remueve el primer elemento de 'l' cuya primera coordenada es 'x'.
 * Precondición: ExisteX(x,l). */
void RemoverX(int x, Lista &l);

/* Devuelve una gráfica vacia que puede mantener hasta 'N' asociaciones.
 * Precondición: N > 0. */
Grafica CrearGrafica (int N) {
    Grafica g = new repGrafica;
    g->hash = new Lista[N];
    for (int i = 0; i < N; ++i)
        g->hash[i] = CrearLista();
    g->N = N;
    g->n = 0;
    return g;
}

/* Si en 'g' hay menos de 'N' asociaciones , asigna 'y' como valor
 * asociado a 'x'; en caso contrario la operación no tiene efecto.
 * Precondición: x > 0, y > 0, Valor (x, g) == -1. */
void Asociar (int x, int y, Grafica &g) {
    if (g->n < g->N) {
        int h = x % g->N;
        Cons(CrearPunto(x, y), g->hash[h]);
        ++g->n;
    }
}

/* Actualiza la asociación de 'x' en 'g', asignando 'y' como su valor
 * asociado.
 * Precondición: x > 0, y > 0, Valor (x, g) != -1. */
void Actualizar (int x, int y, Grafica &g) {
    int h = x % g->N;
    Cons(CrearPunto(x, y), g->hash[h]);
}

/* Si en 'g' existe asociación para 'x', devuelve el valor asociado a
 * 'x'; en otro caso devuelve -1.
 * Precondición: x > 0. */
int Valor (int x, Grafica g) {
    int h = x % g->N;
    Lista l = g->hash[h];
    while (!EsVaciaLista(l) && Primero(l).x != x)
        l = Resto(l);
    if (EsVaciaLista(l))
        return -1;
    else
        return Primero(l).y;
}

/* Elimina de 'g' la asociación para 'x', si existe tal asociación; en
 * caso contrario la operación no tiene efecto.
 * Precondición: x > 0. */
void Desasociar (int x, Grafica &g) {
    int h = x % g->N;
    if (ExisteX(x, g->hash[h])) {
        do {
            RemoverX(x, g->hash[h]);
        }
        while (ExisteX(x, g->hash[h]));
        --g->n;
    }
}
