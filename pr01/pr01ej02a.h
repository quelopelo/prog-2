// pr01ej02a.h

# ifndef _INFO_H
# define _INFO_H

/* Representación de TInfo */
typedef struct _rep_info *TInfo ;

/* Operaciones de TInfo */

/*
Devuelve un 'TInfo' compuesto por 'natural' y 'real'.
*/
TInfo crearInfo(unsigned int natural, double real);

/*
Devuelve el componente natural de 'info'.
*/
unsigned int natInfo(TInfo info);

/*
Devuelve el componente real de 'info'.
*/
double realInfo(TInfo info);

# endif
