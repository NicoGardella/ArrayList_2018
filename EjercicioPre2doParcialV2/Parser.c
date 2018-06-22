#include "ArrayList.h"
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>

int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int retorno = -1;

    char bNombre[4096];
    char bHorasTrabajadas[4096];
    char id[4096];
    int auxHorasTrabajadas;
    int auxId;
    int a;
    Empleado* auxiliarEmpleado;

    FILE* pFile;
    pFile = fopen(fileName,"r");

    if(pFile != NULL)
    {

        fscanf(pFile,"%[^\n]\n",bNombre);

        do
        {
            a =fscanf(pFile,"%[^,],%[^,],%[^\n]\n",id,bNombre,bHorasTrabajadas);


            if(a==3)
            {
                auxId=atoi(id);
                auxHorasTrabajadas=atoi(bHorasTrabajadas);

                auxiliarEmpleado = Empleado_newConParametros(auxId,bNombre,auxHorasTrabajadas,0);
                al_add(listaEmpleados,auxiliarEmpleado);
            }

        }while(!feof(pFile));

        retorno = 1;

    }
    fclose(pFile);
    return retorno;//1= OK
}

