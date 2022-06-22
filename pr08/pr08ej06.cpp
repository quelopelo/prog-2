// Examen agosto 2020

// Declaración de tipo auxiliar para compilación
typedef int * Tabla;

// TAD Tabla
Tabla crearTabla();
void borrarTabla(Tabla &t);
Tabla insertar(int x, float y, Tabla t);
bool existe(int x, Tabla t);
float recuperar(int x, Tabla t);
Tabla eliminar(int x, Tabla t);

// Función a implementar
Tabla consolidar(Tabla t1, Tabla t2, int inf, int sup) {
    Tabla t = crearTabla();
    for (int i = inf; i <= sup; ++i)
        if (existe(i, t1))
            if (existe(i, t2))
                t = insertar(i, recuperar(i, t1) + recuperar(i, t2), t);
            else
                t = insertar(i, recuperar(i, t1), t);
        else
            if (existe(i, t2))
                t = insertar(i, recuperar(i, t2), t);
    return t;
}
