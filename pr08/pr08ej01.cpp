# include <stdio.h>

typedef unsigned int nat;

// TAD Tabla no acotada
// Ver implementación en mapping del laboratorio

// Representación de tabla no acotada
/* Una tabla no acotada consiste en un hash (N) abierto con punteros a
 * parejas de elementos (d, r), donde d es un entero que constituye la
 * clave y r es un real, tal que r = T(d). */
typedef rep_Tabla * Tabla;

/* Retorna una tabla vacía. */
Tabla crearTabla(nat N);

/* Devuelve true si y solo si 't' no tiene elementos. */
bool esVacia(Tabla t);

/* Inserta la pareja (d, r) en la tabla 't' si 'd' no pertenece a la
 * tabla como clave. En caso contrario, actualiza el valor de 'r'. */
Tabla insertar(int d, float r, Tabla t);

/* Devuelve true si y solo si existe alguna pareja (d, r) en la tabla
 * 't', con 'd' como clave. */
bool pertenece(int d, Tabla t);

/* Elimina la pareja (d, r) en la tabla 't' si 'd' pertenece a la tabla
 * como clave. En caso contrario, no hace nada. */
Tabla eliminar(int d, Tabla t);

/* Devuelve la imagen de la clave 'd'. */
/* Precondición: pertenece(int d, Tabla t) */
float imagen(int d, Tabla t);
