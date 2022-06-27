/* Representación de una cola de prioridad no acotada de elementos de
 * tipo 'T' con prioridades de tipo 'int'. */
typedef int * T;        // Definición auxiliar para compilación
struct repColaP;
typedef repColaP * TColaP;

// CONSTRUCTORAS

/* Crea y devuelve una cola de prioridad vacía. */
TColaP crearCPVacia();

/* Agrega 'elem' con prioridad 'p' a la cola de prioridad 'cp'. */
void agregarCP(T elem, int p, TColaP &cp);

// PREDICADOS

/* Devuelve 'true' si solo si 'cp' no tiene elementos. */
bool esCPVacia(TColaP cp);

// SELECTORAS

/* Devuelve el elemento prioritario de 'cp'. */
/* Precondición: !esCPVacia(cp). */
T minimoCP(TColaP cp);

// DESTRUCTORAS

/* Elimina el elemento prioritario de 'cp'. */
/* Precondición: !esCPVacia(cp). */
void eliminarMinCP(TColaP &cp);

/* Destruye la cola de prioridad 'cp' y libera la memoria. */
void destruirCP(TColaP &cp);
