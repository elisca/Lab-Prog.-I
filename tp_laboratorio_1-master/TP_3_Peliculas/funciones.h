#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "movie.h"

/** \brief Genera un archivo HTML con la descripcion de las peliculas.
 *
 * \param movie EMovie** Array de punteros a estructuras EMovie.
 * \param idPeliculaActual int* ID de la pelicula.
 * \param cantPeliculas int Cantidad de peliculas.
 * \param path char* Ruta al archivo HTML que se desea generar.
 * \return int -1 Error,0 OK.
 *
 */
int funciones_generarHTML(EMovie** movie,int *idPeliculaActual,int cantPeliculas,char* path);
#endif // FUNCIONES_H_INCLUDED
