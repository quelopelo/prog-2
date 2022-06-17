// Examen de febrero de 2015

// Definiciones auxiliares para compilación
typedef int * Coord;
typedef int * ConjCoord;

/* Crea una coordenada con el par (x, y) */
Coord crearCoord (int x, int y);

/* Retorna el primer elemento de una coordenada c */
int coordX (Coord c);

/* Retorna el segundo elemento de una coordenada c */
int coordY (Coord c);

// TAD ConjCoord
ConjCoord crearConjCoord ();
bool esConjCoordVacio (ConjCoord conj);
ConjCoord agregarCoord (Coord c, ConjCoord conj);
bool perteneceCoord (Coord c, ConjCoord conj);
ConjCoord borrarCoord (Coord c, ConjCoord conj);
void borrarConjCoord (ConjCoord &conj);
ConjCoord conjUnion (ConjCoord conj1, ConjCoord conj2);
ConjCoord conjInterseccion (ConjCoord conj1, ConjCoord conj2);
ConjCoord conjDiferencia (ConjCoord conj1, ConjCoord conj2);

/* Retorna un conjunto de coordenadas con todas las coordenadas de conj
 * que contienen a x como primer elemento del par */
ConjCoord subconjX (int x, ConjCoord conj);

/* Retorna un conjunto de coordenadas con todas las coordenadas de conj
 * que contienen a y como segundo elemento del par */
ConjCoord subconjY (int Y, ConjCoord conj);

/* Retorna todas las coordenadas de conj que se encuentran dentro del
 * rectángulo formado por los puntos (c1.x, c1.y), (c2.x, c1.y), (c2.x,
 * c2.y), (c1.x, c2.y). Si hay elementos en el borde del rectángulo
 * también deben aparecer en el conjunto resultado */
ConjCoord coordenadasInternas (Coord c1, Coord c2, ConjCoord conj) {
    ConjCoord cx = crearConjCoord();
    int x1 = coordX(c1);
    int x2 = coordX(c2);
    if (x1 > x2) {
        x2 = x1;
        x1 = coordX(c2);
    }
    for (; x1 > x2; ++x1)
        cx = conjUnion(cx, subconjX(x1, conj));
    ConjCoord cy = crearConjCoord();
    int y1 = coordY(c1);
    int y2 = coordY(c2);
    if (y1 > y2) {
        y2 = y1;
        y1 = coordY(c2);
    }
    for (; y1 > y2; ++y1)
        cy = conjUnion(cy, subconjY(y1, conj));
    ConjCoord cint = conjInterseccion(cx, cy);
    borrarConjCoord(cx);
    borrarConjCoord(cy);
    return cint;
}
