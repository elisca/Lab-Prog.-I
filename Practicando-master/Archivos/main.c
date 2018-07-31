#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[128];
    char apellido[128];
    int edad;
}ePersona;

void hardcodePersons(ePersona* array);

int main()
{
    ePersona arrayPersonas[5];
//    ePersona auxPersona;
    FILE* archivo=NULL;
    int i=0;
    int cantBuffer=0;

    hardcodePersons(arrayPersonas);

    if((archivo=fopen("datos.txt","wb"))==NULL)
    {
        printf("Error al intentar abrir para escritura el archivo.\n");
        exit(-1);
    }

    for(i=0;i<5;i++)
    {
        cantBuffer=fwrite(&arrayPersonas[i],sizeof(ePersona),1,archivo);
        if(cantBuffer!=1)
        {
            if(!feof(archivo))
            {
                printf("Error al intentar escribir en el archivo.\n");
                exit(-2);
            }
            else
                break;
        }
    }
    fclose(archivo);

    if((archivo=fopen("datos.txt","rb"))==NULL)
    {
        printf("Error al intentar abrir archivo para lectura.\n");
        exit(-3);
    }

    i=0;
    while(!feof(archivo))
    {
        cantBuffer=fread(&arrayPersonas[i],sizeof(ePersona),1,archivo);
        if(cantBuffer!=1)
        {
            if(!feof(archivo))
            {
                printf("Error al intentar leer una linea.\n");
                exit(-4);
            }
            else
                break;
        }
        printf("ID: %d \tNombre: %s \tApellido: %s \tEdad: %d\n",arrayPersonas[i].id,arrayPersonas[i].nombre,arrayPersonas[i].apellido,arrayPersonas[i].edad);
        i++;
    }
    fclose(archivo);
    return 0;
}

void hardcodePersons(ePersona* array)
{
    //Persona 0
    array[0].id=0;
    strcpy(array[0].nombre,"Ezequiel");
    strcpy(array[0].apellido,"Lisca");
    array[0].edad=26;
    //Persona 1
    array[1].id=1;
    strcpy(array[1].nombre,"Ariel");
    strcpy(array[1].apellido,"Lisca");
    array[1].edad=21;
    //Persona 2
    array[2].id=2;
    strcpy(array[2].nombre,"Adrian");
    strcpy(array[2].apellido,"Lisca");
    array[2].edad=50;
    //Persona 3
    array[3].id=3;
    strcpy(array[3].nombre,"Viviana");
    strcpy(array[3].apellido,"Sciume");
    array[3].edad=46;
    //Persona 4
    array[4].id=4;
    strcpy(array[4].nombre,"Gustavo");
    strcpy(array[4].apellido,"Sciume");
    array[4].edad=54;
}
