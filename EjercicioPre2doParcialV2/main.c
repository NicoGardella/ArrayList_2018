#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"

/**
    Realizar un programa que lee de un archivo los datos de empleados y los guarda en un arraylist de entidades
    empleado.
    Luego, debera calcular el campo "sueldo" de cada uno de los empleados leidos, segun la horas que trabajaron, con el
    siguiente criterio:
    Los valores de horas varian entre 80 y 240.
    - Las primeras 120 horas la hora vale $180
    - De 120 a 160 horas, la hora vale $240
    - De 160 a 240 horas, la hora vale $350

    Para hacer este calculo, se debera desarrollar la funcion "map" en al biblioteca ArrayList, La cual recibe la lista y una funcion.
    La funcion map ejecutara la funcion recibida como parametro por cada item de la lista, y le pasaran en cada llamada, uno de los items.
    De esta manera la funcion pasada como parametro podra realizar un calculo con el item recibido, en este caso, calcular el sueldo.

    Una vez cargados los campos sueldo en las entidades, se debera generar un archivo de salida "sueldos.csv" el cual sera igual que el
    original pero con una columna mas al final, en donde se indicara el sueldo calculado.
*/

int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados);

int main()
{

    // Definir lista de empleados
    ArrayList* listaEmpleados;

    // Crear lista empledos
    //...
    listaEmpleados = al_newArrayList();

    // Leer empleados de archivo data.csv
    if(parser_parseEmpleados("data.csv",listaEmpleados)==1)
    {
        // Calcular sueldos
        printf("Calculando sueldos de empleados:  %d\n",al_len(listaEmpleados));
        al_map(listaEmpleados,em_calcularSueldo);
        al_map(listaEmpleados,empleado_print);
        int i;
        /*for(i=0;i<al_len(listaEmpleados);i++)
        {
            empleado_print(al_get(listaEmpleados,i));
        }*/

        // Generar archivo de salida
        if(generarArchivoSueldos("sueldos.csv",listaEmpleados)==1)
        {
            printf("Archivo generado correctamente\n");
        }
        else
            printf("Error generando archivo\n");

    }
    else
        printf("Error leyendo empleados\n");


    return 0;
}

int generarArchivoSueldos(char* fileName,ArrayList* listaEmpleados)
{
     int retorno = -1;

    char bNombre[4096];

    int auxHorasTrabajadas;
    int auxSueldo;
    int auxId;
    int a;
    Empleado* auxEmp;
    auxEmp = Empleado_new();

    FILE* pFile;
    pFile = fopen(fileName,"w");

    if(pFile != NULL)
    {
        fprintf(pFile,"id,nombre,horas_trabajadas,sueldo\n");
        for(a=0;a<al_len(listaEmpleados);a++)
        {
            auxEmp = al_pop(listaEmpleados,a);
            Empleado_getNombre(auxEmp,bNombre);

            Empleado_getHorasTrabajadas(auxEmp,&auxHorasTrabajadas);
            Empleado_getId(auxEmp,&auxId);
            Empleado_getSueldo(auxEmp,&auxSueldo);



            fprintf(pFile,"%d,%s,%d,%d\n",auxId,bNombre,auxHorasTrabajadas,auxSueldo);
        }

        retorno = 1;

    }
    fclose(pFile);
    return retorno;//1= OK
}
