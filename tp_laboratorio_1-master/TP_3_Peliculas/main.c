#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //Conversion a minuscula en opcion 5, confirmacion de salida del programa.
#include "funciones.h" //Lee array peliculas y trabaja en el HTML.
#include "movie.h" //Funciones de peliculas,setters,getters,ABM.
#include "input.h" //Ingresos de datos y validaciones varias.

#define QTY_MOVIES 50

int main()
{
    char seguir='n'; //Respuesta de confirmacion salir del programa.
    EMovie* arrayMovie[QTY_MOVIES]; //Array de estructuras de peliculas.
    int cantAltas=0; //Cantidad total de peliculas en estado de alta.
    char charOpcion[10]; //Auxiliar para validacion de opcion seleccionada en el menu.
    char auxChar[20]; //Auxiliar de caracteres.
    int auxIntRetornos; //Auxiliar de retornos de funciones que devuelven entero (si hubo error o no).
    int opcion=0; //Opcion seleccionada en el menu (ya validada anteriormente en un char).

    //Menu de opciones
    while(seguir=='n')
    {
        do
        {
            system("cls");
            printf("1- Agregar pelicula\n2- Modificar pelicula\n3- Borrar pelicula\n4- Generar pagina web\n5- Salir\n\n");

            //Valida que la opcion ingresada sea numerica, caso correcto convierte la opcion a entero
            auxIntRetornos=getStringNumeros("Opcion: ",charOpcion);
            if(auxIntRetornos)
                opcion=atoi(charOpcion);

            //Valida que la opcion ingresada sea numerica y dentro del rango valido
            if(!auxIntRetornos || opcion<1 || opcion>5)
            {
                system("cls");
                printf("ERROR, opcion incorrecta.\n");
                system("pause");
            }
        }while(opcion<1 || opcion>5);

        //Las opciones 2,3 y 4 necesitan al menos una pelicula en alta para poder utilizarlas.
        if((opcion>=2 && opcion<=4) && cantAltas<=0)
            printf("No existen actualmente peliculas en alta.\n");
        else
        {
            //Segun la opcion seleccionada toma una accion
            switch(opcion)
            {
                case 1://Agregar Pelicula
                    auxIntRetornos=movie_altaPelicula(arrayMovie,&cantAltas);
                    if(auxIntRetornos<0)
                    {
                        printf("Error al intentar agregar una nueva pelicula.\n");
                        break;
                    }
                    printf("Pelicula agregada a la lista.\n");
                    break;
                case 2://Modificar Pelicula
                    //Muestra las peliculas en alta
                    movie_listarPeliculas(arrayMovie,cantAltas);
                    //Pide elegir por ID que pelicula modificar, y solicita los datos a guardarle.
                    auxIntRetornos=movie_modificarPelicula(arrayMovie,&cantAltas);
                    if(auxIntRetornos<0)
                    {
                        printf("Error al intentar modificar una pelicula. Verifique que sea existente y que los datos ingresados sean validos.\n");
                        break;
                    }
                    printf("Pelicula modificada correctamente.\n");
                    break;
                case 3://Borrar Pelicula
                    //Muestra las peliculas en alta
                    movie_listarPeliculas(arrayMovie,cantAltas);
                    //Solicita ID de la pelicula a dar baja.
                    if(!getStringNumeros("Pelicula a borrar. ID: ",auxChar) || atoi(auxChar)<0)
                    {
                        printf("Error, el dato ingresado no corresponde a un ID o su valor no es valido.\n");
                        break;
                    }

                    //Da baja a la pelicula seleccionada validando que la pelicula exista y este en alta.
                    auxIntRetornos=movie_bajaPelicula(arrayMovie,&cantAltas,atoi(auxChar));
                    if(auxIntRetornos<0)
                    {
                        printf("Error al intentar borrar una pelicula.\n");
                        break;
                    }
                    printf("Se elimino correctamente la pelicula.\n");
                   break;
                case 4://Generar archivo HTML
                    auxIntRetornos=funciones_generarHTML(arrayMovie,&cantAltas,QTY_MOVIES,"template/index.html");
                    if(auxIntRetornos<0)
                    {
                        printf("Error al generar archivo HTML.\n");
                        break;
                    }
                    printf("Archivo HTML generado exitosamente.\n");
                   break;
                case 5://Salir
                    do
                    {
                        seguir = getChar("Confirma que desea salir?(S/N): ");
                        seguir=tolower(seguir);
                    }while(seguir!='n' && seguir!='s');
                    break;
            }
        }
        //Si se eligio salir del programa, es la unica opcion en la que no necesitamos pausar la consola para visualizar datos.
        if(opcion!=5)
            system("pause");
    }

    return 0;
}
