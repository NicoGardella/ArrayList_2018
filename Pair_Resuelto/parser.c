#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Destinatario.h"


int parserLista(char* fileName , ArrayList* pArrayListEmployee, char* tdApertura)
{
    int retorno = -1;

    char bName[4096];
    char bMail[4096];
    int a;
    Destinatario* auxiliarDestinatario;

    FILE* pFile;
    pFile = fopen(fileName,tdApertura);
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            a =fscanf(pFile,"%[^,],%[^\n]\n",bName,bMail);
            if(a==2)
            {
                auxiliarDestinatario = destinatario_newParametros(bName,bMail);
                al_add(pArrayListEmployee,auxiliarDestinatario);
            }

        }

        retorno = 0;

    }

    return retorno;
}




