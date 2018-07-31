#include <stdio.h>
#include <stdlib.h>

#define AL_INCREMENT 5
#define AL_INITIAL 3

typedef struct
{
    char nombre[20];
    int edad;
}ePersona;

int main()
{
    int reservedSize=AL_INITIAL;
    int size=0;
    ePersona** arrayPersonas=(ePersona**)malloc(sizeof(ePersona*)*reservedSize);
    ePersona** auxArrayPersonas=NULL;
    int i;
    char respSalir='n';

    do
    {
        ePersona* Persona=(ePersona*)malloc(sizeof(ePersona));
        if(Persona!=NULL)
        {
            printf("Pos.: %d \tNombre: ",size);
            fflush(stdin);
            scanf("%s",Persona->nombre);

            printf("Pos.: %d \tEdad: ",size);
            scanf("%d",&Persona->edad);

            printf("Pos.: %d \tSalir (S/N): ",size);
            fflush(stdin);
            scanf("%c",&respSalir);
            arrayPersonas[size]=Persona;
            size++;

            if(size>=reservedSize)
            {
                reservedSize+=AL_INCREMENT;
                auxArrayPersonas=(ePersona**)realloc(arrayPersonas,sizeof(ePersona*)*reservedSize);
                if(auxArrayPersonas==NULL)
                {
                    printf("ERROR AL REDIMENSIONAR. Se listaran datos y se cerrara programa.\n");
                    exit(-1);
                }
                arrayPersonas=auxArrayPersonas;
                printf("Redimension lista a %d elementos.\n",reservedSize);
            }
        }
    }while(respSalir=='n' || respSalir=='N');

    for(i=0;i<size;i++)
        printf("POS: %d \tNOMBRE: %s \tEDAD: %d\n",i,arrayPersonas[i]->nombre,arrayPersonas[i]->edad);

    return 0;
}
