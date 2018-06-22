#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Empleado* this;
    this=Empleado_new();

    if(
    !Empleado_setId(this,id)&&
    !Empleado_setNombre(this,nombre)&&
    !Empleado_setHorasTrabajadas(this,horasTrabajadas)&&
    !Empleado_setSueldo(this,sueldo))
        return this;

    Empleado_delete(this);
    return NULL;
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

void em_calcularSueldo(void* p)
{

    if(p!=NULL)
    {
        Empleado* auxEmpleado = (Empleado*) p;
        int bHoras;
        int bSueldo = 0;
        Empleado_getHorasTrabajadas(p,&bHoras);
        while(bHoras>0)
        {
            if(bHoras>160)
            {
                bSueldo += (bHoras-160)*350;
                bHoras = 160;
            }
            if(bHoras<=160 && bHoras>120)
            {
                bSueldo += (bHoras-120)*240;
                bHoras=120;
            }
            if(bHoras<=120)
            {
                bSueldo += bHoras*180;
                bHoras=0;
            }
        }
        Empleado_setSueldo(p,bSueldo);
    }
}


void empleado_print(Empleado* this)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;

    if(this != NULL)
    {
        Empleado_getId(this,&id);
        Empleado_getNombre(this, nombre);
        Empleado_getHorasTrabajadas(this,&horasTrabajadas);
        Empleado_getSueldo(this,&sueldo);


        fprintf(stdout,"\n ID:%d - Nombre: %s - HorasTrabajadas: %d - Sueldo:%d \n", id,nombre,horasTrabajadas,sueldo);
    }

}

