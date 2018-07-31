#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "movie.h"

int funciones_generarHTML(EMovie** movie,int *idPeliculaActual,int cantPeliculas,char* path)
{
    int funcRetorno=-1;
    char auxTitulo[200];
    char auxGenero[50];
    int intDuracion;
    char auxDescripcion[200];
    int intPuntaje;
    char auxLinkImagen[200];
    int i;

    FILE* pFile;
    pFile = fopen(path,"w");

    if(pFile==NULL || movie==NULL || cantPeliculas<=0 || *idPeliculaActual<0 || cantPeliculas<=*idPeliculaActual)
        return funcRetorno;

        fprintf(pFile, "<!DOCTYPE html>\n");
        fprintf(pFile, "<!-- Template by Quackit.com -->\n");
        fprintf(pFile, "<html lang='en'>\n");
        fprintf(pFile, "<head>\n");
        fprintf(pFile, "<meta charset='utf-8'>\n");
        fprintf(pFile, "<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
        fprintf(pFile, "<meta name='viewport' content='width=device-width, initial-scale=1'>\n");
        fprintf(pFile, "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->\n");
        fprintf(pFile, "<title>Lista peliculas</title>\n");
        fprintf(pFile, "<!-- Bootstrap Core CSS -->\n");
        fprintf(pFile, "<link href='css/bootstrap.min.css' rel='stylesheet'>\n");
        fprintf(pFile, "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->\n");
        fprintf(pFile, "<link href='css/custom.css' rel='stylesheet'>\n");
        fprintf(pFile, "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->\n");
        fprintf(pFile, "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->\n");
        fprintf(pFile, "<!--[if lt IE 9]>\n");
        fprintf(pFile, "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>\n");
        fprintf(pFile, "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>\n");
        fprintf(pFile, "<![endif]-->\n");
        fprintf(pFile, "</head>\n");
        fprintf(pFile, "<body>\n");
        fprintf(pFile, "<div class='container'>\n");
        fprintf(pFile, "<div class='row'>\n");
        fprintf(pFile, "<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile, "<article class='col-md-4 article-intro'>\n");

        for(i=0;i<*idPeliculaActual;i++)
        {
            movie_getTitulo(movie[i],auxTitulo);
            movie_getGenero(movie[i],auxGenero);
            movie_getDescripcion(movie[i],auxDescripcion);
            movie_getDuracion(movie[i],&intDuracion);
            movie_getPuntaje(movie[i],&intPuntaje);
            movie_getLinkImagen(movie[i],auxLinkImagen);
            fprintf(pFile,"<a href='#'> <img class='img-responsive img-rounded' src='%s' alt=''> </a> <h3> <a href='#'>%s</a> </h3> <ul> <li>Género:%s</li> <li>Puntaje:%d</li> <li>Duración:%d</li> </ul> <p>%s</p>",auxLinkImagen,auxTitulo,auxGenero,intPuntaje,intDuracion,auxDescripcion);
        }

        fprintf(pFile, "</article>\n");
        fprintf(pFile, "<!-- Repetir esto para cada pelicula -->\n");
        fprintf(pFile, "</div>\n");
        fprintf(pFile, "<!-- /.row -->\n");
        fprintf(pFile, "</div>\n");
        fprintf(pFile, "<!-- /.container -->\n");
        fprintf(pFile, "<!-- jQuery -->\n");
        fprintf(pFile, "<script src='js/jquery-1.11.3.min.js'></script>\n");
        fprintf(pFile, "<!-- Bootstrap Core JavaScript -->\n");
        fprintf(pFile, "<script src='js/bootstrap.min.js'></script>\n");
        fprintf(pFile, "<!-- IE10 viewport bug workaround -->\n");
        fprintf(pFile, "<script src='js/ie10-viewport-bug-workaround.js'></script>\n");
        fprintf(pFile, "<!-- Placeholder Images -->\n");
        fprintf(pFile, "<script src='js/holder.min.js'></script>\n");
        fprintf(pFile, "</body>\n");
        fprintf(pFile, "</html>\n");

    fclose(pFile);
    funcRetorno=0;
    return funcRetorno;
}
