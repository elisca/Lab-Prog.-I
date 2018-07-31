#ifndef MOVIE_H_INCLUDED
#define MOVIE_H_INCLUDED

typedef struct{
    int id;
    char titulo[100];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[200];
}EMovie;

/** \brief Setter para salvar el ID de la pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param id int ID de la pelicula.
 * \return int -1 Error,0 OK.
 *
 */
int movie_setId(EMovie* movie,int id);

/** \brief Setter para salvar el titulo de la pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param titulo char* Titulo a guardar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_setTitulo(EMovie* movie,char* titulo);

/** \brief Setter para salvar el genero de la pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param genero char* Genero a guardar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_setGenero(EMovie* movie,char* genero);

/** \brief Setter para salvar la descripcion de la pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param descripcion char* Descripcion a guardar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_setDescripcion(EMovie* movie,char* descripcion);

/** \brief Setter para salvar el link de la imagen que describe a la pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param linkImagen char* Link a guardar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_setLinkImagen(EMovie* movie,char* linkImagen);

/** \brief Setter para salvar la duracion de la pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param duracion int Duracion a guardar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_setDuracion(EMovie* movie,int duracion);

/** \brief Setter para salvar el puntaje de la pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param puntaje int Puntaje a guardar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_setPuntaje(EMovie* movie,int puntaje);

/** \brief Getter para recuperar el ID de una pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param id int* id a recuperar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_getId(EMovie* movie,int* id);

/** \brief Getter para recuperar el titulo de una pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param titulo char* Titulo a recuperar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_getTitulo(EMovie* movie,char* titulo);

/** \brief Getter para recuperar el genero de una pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param genero char* Genero a recuperar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_getGenero(EMovie* movie,char* genero);

/** \brief Getter para recuperar la descripcion de una pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param descripcion char* Descripcion a recuperar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_getDescripcion(EMovie* movie,char* descripcion);

/** \brief Getter para recuperar el link de una imagen de una pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param linkImagen char* Link de la imagen.
 * \return int -1 Error,0 OK.
 *
 */
int movie_getLinkImagen(EMovie* movie,char* linkImagen);

/** \brief Getter para recuperar la duracion de una pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param duracion int* Duracion de la pelicula a recuperar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_getDuracion(EMovie* movie,int* duracion);

/** \brief Getter para recuperar el puntaje de una pelicula.
 *
 * \param movie EMovie* Puntero a peliculas EMovie.
 * \param puntaje int* Puntaje de la pelicula a recuperar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_getPuntaje(EMovie* movie,int* puntaje);

/** \brief Guarda toda la estructura Movie en el array con todos los argumentos seteados.
 *
 * \param id int ID de la pelicula en la base de datos.
 * \param titulo char* Titulo de la pelicula.
 * \param genero char* Genero de la pelicula.
 * \param duracion int Duracion de la pelicula.
 * \param descripcion char* Descripcion de la pelicula.
 * \param puntaje int Puntaje de la pelicula.
 * \param linkImagen char* Link de la imagen de la pelicula.
 * \return Movie* Puntero a movie, en caso de error retorna NULL.
 *
 */
EMovie* movie_guardarMovie(int id, char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* linkImagen);

/** \brief Solicita datos para cargar una nueva pelicula al array.
 *
 * \param arrayPeliculas EMovie** Array de punteros a peliculas EMovie.
 * \param idPeliculaActual int* ID actual de la pelicula a agregar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_altaPelicula(EMovie** arrayPeliculas,int* idPeliculaActual);

/** \brief Elimina una pelicula.
 *
 * \param arrayPeliculas EMovie** Array de punteros a estructuras tipo EMovie.
 * \param idPeliculaActual int* ID actual de pelicula.
 * \param id int ID a eliminar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_bajaPelicula(EMovie **arrayPeliculas,int* idPeliculaActual,int id);

/** \brief Ingresa una pelicula al array con los parametros que se le pasa a la funcion.
 *
 * \param titulo char* Titulo de la pelicula.
 * \param genero char* Genero de la pelicula.
 * \param duracion int Duracion de la pelicula.
 * \param descripcion char* Descripcion de la pelicula.
 * \param puntaje int Puntaje de la pelicula.
 * \param link char* Link de la imagen de la pelicula.
 * \return EMovie* Puntero a estructura EMovie.
 *
 */
EMovie* movie_newParam(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link);

/** \brief Funcion contructor, crea una nueva estructura EMovie en memoria dinamica.
 *
 * \param void
 * \return EMovie* Puntero a estructura EMovie.
 *
 */
EMovie* movie_new(void);

/** \brief Funcion destructor, elimina un puntero asignado a estructura EMovie en memoria dinamica.
 *
 * \param movie EMovie* Puntero a estructura EMovie.
 * \return void
 *
 */
void movie_delete(EMovie* movie);

/** \brief Muestra por consola listado de peliculas.
 *
 * \param movie EMovie** Array de punteros EMovie.
 * \param idPeliculaActual int ID de pelicula actual.
 * \return int -1 Error,0 OK.
 *
 */
int movie_listarPeliculas(EMovie** movie,int idPeliculaActual);

/** \brief Modifica los datos de una pelicula en alta.
 *
 * \param arrayPeliculas EMovie** Array de Punteros a EMovie.
 * \param idPeliculaActual int* Cantidad de peliculas en alta.
 * \param idModificar int ID de la pelicula que se desea modificar.
 * \return int -1 Error,0 OK.
 *
 */
int movie_modificarPelicula(EMovie** arrayPeliculas,int* idPeliculaActual);
#endif // MOVIE_H_INCLUDED
