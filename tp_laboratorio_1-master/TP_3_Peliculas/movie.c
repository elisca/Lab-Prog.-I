#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "input.h"

//Setter, ID de pelicula.
int movie_setId(EMovie* movie,int id)
{
    int funcRetorno = -1;
    static int ultimoId = -1;
    if(movie!=NULL)
    {
        funcRetorno=0;
        if(id>=0)
        {
            if(id>ultimoId)
                ultimoId=id;
            movie->id=id;
        }
        else
        {
            ultimoId++;
            movie->id=ultimoId;
        }
    }
    return funcRetorno;
}

//Setter, titulo de pelicula.
int movie_setTitulo(EMovie* movie,char* titulo)
{
    int funcRetorno=-1;

    if(movie==NULL || titulo==NULL || strlen(titulo)>99)
        return funcRetorno;

    funcRetorno=0;
    strcpy(movie->titulo,titulo);
    return funcRetorno;
}

//Setter, genero de pelicula.
int movie_setGenero(EMovie* movie,char* genero)
{
    int funcRetorno=-1;

    if(movie==NULL || genero==NULL || strlen(genero)>49)
        return funcRetorno;

    funcRetorno=0;
    strcpy(movie->genero,genero);
    return funcRetorno;
}

//Setter, descripcion de pelicula.
int movie_setDescripcion(EMovie* movie,char* descripcion)
{
    int funcRetorno=-1;

    if(movie==NULL || descripcion==NULL || strlen(descripcion)>199)
        return funcRetorno;

    funcRetorno=0;
    strcpy(movie->descripcion,descripcion);
    return funcRetorno;
}

//Setter, link de imagen de pelicula.
int movie_setLinkImagen(EMovie* movie,char* linkImagen)
{
    int funcRetorno=-1;

    if(movie==NULL || linkImagen==NULL || strlen(linkImagen)>199)
        return funcRetorno;

    funcRetorno=0;
    strcpy(movie->linkImagen,linkImagen);
    return funcRetorno;
}

//Setter, duracion en minutos de pelicula.
int movie_setDuracion(EMovie* movie,int duracion)
{
    int funcRetorno=-1;

    if(movie==NULL || duracion<1)
        return funcRetorno;

    funcRetorno=0;
    movie->duracion=duracion;
    return funcRetorno;
}

//Setter, puntaje de pelicula.
int movie_setPuntaje(EMovie* movie,int puntaje)
{
    int funcRetorno=-1;

    if(movie==NULL || puntaje<0)
        return funcRetorno;

    funcRetorno=0;
    movie->puntaje=puntaje;
    return funcRetorno;
}

//Getter, ID de pelicula.
int movie_getId(EMovie* movie,int* id)
{
    int funcRetorno = -1;
    if(movie==NULL || id==NULL)
        return funcRetorno;

    funcRetorno=0;
    *id = movie->id;
    return funcRetorno;
}

//Getter, titulo de la pelicula.
int movie_getTitulo(EMovie* movie,char* titulo)
{
    int funcRetorno=-1;

    if(movie==NULL || titulo==NULL || strlen(titulo)>99)
        return funcRetorno;

    funcRetorno=0;
    strcpy(titulo,movie->titulo);
    return funcRetorno;
}

//Getter, genero de pelicula.
int movie_getGenero(EMovie* movie,char* genero)
{
    int funcRetorno=-1;

    if(movie==NULL || genero==NULL || strlen(genero)>49)
        return funcRetorno;

    funcRetorno=0;
    strcpy(genero,movie->genero);
    return funcRetorno;
}

//Getter, descripcion de pelicula.
int movie_getDescripcion(EMovie* movie,char* descripcion)
{
    int funcRetorno=-1;

    if(movie==NULL || descripcion==NULL || strlen(descripcion)>199)
        return funcRetorno;

    funcRetorno=0;
    strcpy(descripcion,movie->descripcion);
    return funcRetorno;
}

//Getter, link de imagen de pelicula.
int movie_getLinkImagen(EMovie* movie,char* linkImagen)
{
    int funcRetorno=-1;

    if(movie==NULL || linkImagen==NULL || strlen(linkImagen)>199)
        return funcRetorno;

    funcRetorno=0;
    strcpy(linkImagen,movie->linkImagen);
    return funcRetorno;
}

//Getter, duracion de pelicula.
int movie_getDuracion(EMovie* movie,int* duracion)
{
    int funcRetorno=-1;

    if(movie==NULL || duracion==NULL)
        return funcRetorno;

    funcRetorno=0;
    *duracion=movie->duracion;
    return funcRetorno;
}

//Getter, puntaje de pelicula.
int movie_getPuntaje(EMovie* movie,int* puntaje)
{
    int funcRetorno=-1;

    if(movie==NULL || puntaje==NULL)
        return funcRetorno;

    funcRetorno=0;
    *puntaje=movie->puntaje;
    return funcRetorno;
}

//Llama a un constructor y llama para crea una nueva estructura pelicula. Solicita datos para la misma y los valida.
int movie_altaPelicula(EMovie** arrayPeliculas,int* idPeliculaActual)
{
    int funcRetorno=-1;
    char auxTitulo[4096];
    char auxGenero[4096];
    char auxDuracion[4096];
    int auxIntDuracion;
    char auxDescripcion[4096];
    char auxPuntaje[4096];
    int auxIntPuntaje;
    char auxLink[4096];

    if(arrayPeliculas==NULL || *idPeliculaActual<0)
    {
        printf("ERROR al recibir el array de peliculas y el id de pelicula actual.\n");
        return funcRetorno;
    }
    if(getString("Titulo: ",auxTitulo)<0 || strlen(auxTitulo)<3 || strlen(auxTitulo)>199)
    {
        printf("ERROR, el titulo debe tener una longitud entre 3 y 199 caracteres.\n");
        return funcRetorno;
    }
    if(getString("Genero: ",auxGenero)<0 || strlen(auxGenero)<3 || strlen(auxGenero)>49)
    {
        printf("ERROR, el genero debe tener una longitud entre 3 y 49 caracteres.\n");
        return funcRetorno;
    }
    if(getStringNumeros("Duracion: ",auxDuracion)<0 || atoi(auxDuracion)<10)
    {
        printf("ERROR, la duracion no recibio un dato correcto, o es menor a 10 minutos.\n");
        return funcRetorno;
    }
    if(getString("Descripcion: ",auxDescripcion)<0 || strlen(auxDescripcion)<10 || strlen(auxDescripcion)>199)
    {
        printf("ERROR, la descripcion debe tener una longitud entre 10 y 199 caracteres.\n");
        return funcRetorno;
    }
    if(getStringNumeros("Puntaje: ",auxPuntaje)<0 || atoi(auxPuntaje)<0 ||  atoi(auxPuntaje)>10)
    {
        printf("ERROR, el puntaje recibio un valor incorrecto o no esta comprendido entre 0 y 10 puntos.\n");
        return funcRetorno;
    }
    if(getString("Link a Imagen: ",auxLink )<0 || strlen(auxLink)<10 || strlen(auxLink)>199)
    {
        printf("ERROR, el link debe tener una longitud entre 10 y 199 caracteres.\n");
        return funcRetorno;
    }

    auxIntDuracion=atoi(auxDuracion);
    auxIntPuntaje=atoi(auxPuntaje);

    arrayPeliculas[*idPeliculaActual]=movie_newParam(auxTitulo,auxGenero,auxIntDuracion,auxDescripcion,auxIntPuntaje,auxLink);
    *idPeliculaActual=(*idPeliculaActual)+1;
    funcRetorno = 0;
    return funcRetorno;
}

//Solicita la baja de una pelicula con determinado ID, utiliza una funcion destructor y compacta el array de punteros.
int movie_bajaPelicula(EMovie **arrayPeliculas,int* idPeliculaActual,int id)
{
    int funcRetorno=-1;
    int auxId;
    int i;
    int j;

    if(arrayPeliculas==NULL || *idPeliculaActual<=0 || id<0)
        return funcRetorno;

    for(i=0;i<*idPeliculaActual;i++)
    {
        movie_getId(arrayPeliculas[i],&auxId);
        if(auxId==id)
        {
            funcRetorno=0;
            break;
        }
    }

    if(i>=(*idPeliculaActual))
        return funcRetorno;

    for(j=i;j<*idPeliculaActual;j++)
        arrayPeliculas[j]=arrayPeliculas[j+1];
    movie_delete(arrayPeliculas[*idPeliculaActual]);
    (*idPeliculaActual)--;
    return funcRetorno;
}

//Constructor, crea una nueva estructura pelicula con los argumentos que reciba.
EMovie* movie_newParam(char* titulo, char* genero,int duracion,char* descripcion,int puntaje,char* link)
{
    EMovie* auxMovies = movie_new();
    movie_setTitulo(auxMovies,titulo);
    movie_setDescripcion(auxMovies,descripcion);
    movie_setDuracion(auxMovies,duracion);
    movie_setGenero(auxMovies,genero);
    movie_setLinkImagen(auxMovies,link);
    movie_setId(auxMovies,-1);
    movie_setPuntaje(auxMovies,puntaje);

    return auxMovies;
}

//Constructor de pelicula.
EMovie* movie_new(void)
{
    return (EMovie*)malloc(sizeof(EMovie));
}

//Destructor de pelicula.
void movie_delete(EMovie* movie)
{
    free(movie);
}

//Muestra en pantalla todas las peliculas cargadas en alta.
int movie_listarPeliculas(EMovie** movie,int idPeliculaActual)
{
    int funcRetorno=-1;
    char auxTitulo[200];
    int auxId;
    int i;

    if(movie==NULL || idPeliculaActual<=0)
        return funcRetorno;

    for(i=0;i<idPeliculaActual;i++)
    {
        movie_getTitulo(movie[i],auxTitulo);
        movie_getId(movie[i],&auxId);
        printf("ID: %d \tTitulo: %s\n",auxId,auxTitulo);
    }
    funcRetorno=0;
    return funcRetorno;
}

//Modifica datos de una pelicula con el ID que se especifica. Solicita los nuevos datos y los valida.
int movie_modificarPelicula(EMovie** arrayPeliculas,int* idPeliculaActual)
{
    int funcRetorno=-1;
    int i;
    int auxId;
    char auxIdModificar[4096];
    int idModificar;
    char auxTitulo[4096];
    char auxGenero[4096];
    char auxDuracion[4096];
    int auxIntDuracion;
    char auxDescripcion[4096];
    char auxPuntaje[4096];
    int auxIntPuntaje;
    char auxLink[4096];

    if(arrayPeliculas==NULL || *idPeliculaActual<0)
    {
        printf("ERROR al recibir el array de peliculas y el id de pelicula actual.\n");
        return funcRetorno;
    }
    if(getStringNumeros("ID: ",auxIdModificar)<0 || atoi(auxIdModificar)<0 || atoi(auxIdModificar)>*idPeliculaActual)
    {
        printf("ERROR, no se ingreso un ID, o no es valido dentro del rango de IDs que se encuentran en alta.\n");
        return funcRetorno;
    }
    idModificar=atoi(auxIdModificar);

    for(i=0;i<*idPeliculaActual;i++)
    {
        movie_getId(arrayPeliculas[i],&auxId);
        if(auxId==idModificar)
        {
            funcRetorno=0;
            break;
        }
    }

    if(i>=(*idPeliculaActual))
        return funcRetorno;

    if(getString("Titulo: ",auxTitulo)<0 || strlen(auxTitulo)<3 || strlen(auxTitulo)>199)
    {
        printf("ERROR, el titulo debe tener una longitud entre 3 y 199 caracteres.\n");
        return funcRetorno;
    }
    if(getString("Genero: ",auxGenero)<0 || strlen(auxGenero)<3 || strlen(auxGenero)>49)
    {
        printf("ERROR, el genero debe tener una longitud entre 3 y 49 caracteres.\n");
        return funcRetorno;
    }
    if(getStringNumeros("Duracion: ",auxDuracion)<0 || atoi(auxDuracion)<10)
    {
        printf("ERROR, la duracion no recibio un dato correcto, o es menor a 10 minutos.\n");
        return funcRetorno;
    }
    if(getString("Descripcion: ",auxDescripcion)<0 || strlen(auxDescripcion)<10 || strlen(auxDescripcion)>199)
    {
        printf("ERROR, la descripcion debe tener una longitud entre 10 y 199 caracteres.\n");
        return funcRetorno;
    }
    if(getStringNumeros("Puntaje: ",auxPuntaje)<0 || atoi(auxPuntaje)<0 ||  atoi(auxPuntaje)>10)
    {
        printf("ERROR, el puntaje recibio un valor incorrecto o no esta comprendido entre 0 y 10 puntos.\n");
        return funcRetorno;
    }
    if(getString("Link a Imagen: ",auxLink )<0 || strlen(auxLink)<10 || strlen(auxLink)>199)
    {
        printf("ERROR, el link debe tener una longitud entre 10 y 199 caracteres.\n");
        return funcRetorno;
    }

    auxIntDuracion=atoi(auxDuracion);
    auxIntPuntaje=atoi(auxPuntaje);

    movie_setTitulo(arrayPeliculas[i],auxTitulo);
    movie_setDescripcion(arrayPeliculas[i],auxDescripcion);
    movie_setDuracion(arrayPeliculas[i],auxIntDuracion);
    movie_setGenero(arrayPeliculas[i],auxGenero);
    movie_setLinkImagen(arrayPeliculas[i],auxLink);
    movie_setPuntaje(arrayPeliculas[i],auxIntPuntaje);

    funcRetorno = 0;
    return funcRetorno;
}
