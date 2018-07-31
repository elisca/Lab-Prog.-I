#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[128];
    int edad;
}ePersona;

void hardcodePersons(ePersona* array);

int main()
{





    int compr=0;
    ePersona arrayPersonas[5];
    ePersona auxPersona;
    char buffer1[2000];
    char buffer2[2000];
    FILE* archivo=NULL;
    int i=0;

    hardcodePersons(arrayPersonas);

    if((archivo=fopen("datos.txt","w"))==NULL)
    {
        printf("Error al intentar abrir archivo para lectura.\n");
        exit(-1);
    }
    for(i=0;i<5;i++)
    {
        fprintf(archivo,"%d,%s,%d\n",arrayPersonas[i].id,arrayPersonas[i].nombre,arrayPersonas[i].edad);
    }
    fclose(archivo);

    if((archivo=fopen("datos.txt","r"))==NULL)
    {
        printf("Error al intentar abrir archivo para escritura.\n");
        exit(-2);
    }

    i=0;
    while(!feof(archivo))
    {
        compr=fscanf(archivo,"%[^,],%[^,],%[^\n]\n",buffer1,auxPersona.nombre,buffer2);
        if(compr!=3)
        {
            if(feof(archivo))
                break;
            else
            {
                printf("Error al leer.\n");
                exit(-3);
            }
        }
        auxPersona.id=atoi(buffer1);
        auxPersona.edad=atoi(buffer2);
        arrayPersonas[i]=auxPersona;
        printf("ID: %d \tNombre: %s \tEdad: %d\n",arrayPersonas[i].id,arrayPersonas[i].nombre,arrayPersonas[i].edad);
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
    array[0].edad=26;
    //Persona 1
    array[1].id=1;
    strcpy(array[1].nombre,"Ariel");
    array[1].edad=21;
    //Persona 2
    array[2].id=2;
    strcpy(array[2].nombre,"Adrian");
    array[2].edad=50;
    //Persona 3
    array[3].id=3;
    strcpy(array[3].nombre,"Viviana");
    array[3].edad=46;
    //Persona 4
    array[4].id=4;
    strcpy(array[4].nombre,"Gustavo");
    array[4].edad=54;
}
