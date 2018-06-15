#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Destinatario.h"

static int isValidName(char* name);
static int isValidMail(char* mail);


Destinatario* destinatario_new(void)
{

    Destinatario* returnAux = (Destinatario*) malloc(sizeof(Destinatario));
    return returnAux;

}

Destinatario* destinatario_newParametros(char* name, char* mail)
{
    int id;

    Destinatario* this;
    this = destinatario_new();
    if(
        !destinatario_setName(this,name) &&
        !destinatario_setMail(this,mail)

       )
    {
        return this;
    }
    destinatario_delete(this);
    return NULL;
}


void destinatario_delete(Destinatario* this)
{
    if(this != NULL)
        free(this);
}





int destinatario_setName(Destinatario* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL && isValidName(name))
    {
        retorno = 0;
        strcpy(this->name,name);
    }
    return retorno;
}

int destinatario_getName(Destinatario* this, char* name)
{
    int retorno = -1;
    if(this != NULL && name != NULL)
    {
        retorno = 0;
        strcpy(name,this->name);
    }
    return retorno;
}

int destinatario_setMail(Destinatario* this, char* mail)
{
    int retorno = -1;
    if(this != NULL && mail != NULL && isValidMail(mail))
    {
        retorno = 0;
        strcpy(this->mail,mail);
    }
    return retorno;
}

int destinatario_getMail(Destinatario* this, char* mail)
{
    int retorno = -1;
    if(this != NULL && mail != NULL)
    {
        retorno = 0;
        strcpy(mail,this->mail);
    }
    return retorno;
}



static int isValidName(char* name)
{
    return 1;
}

static int isValidMail(char* mail)
{
    return 1;
}
int comparoDest(void* el0, void* el1)
{


    Destinatario* d0 = (Destinatario*)el0;
    Destinatario* d1 = (Destinatario*)el1;
    char name1[128];
    char mail1[128];
    char name2[128];
    char mail2[128];

    destinatario_getName(d0,name1);
    destinatario_getName(d1,name2);

    destinatario_getMail(d0,mail1);
    destinatario_getMail(d1,mail2);

    if(!strcmp(name1,name2))
    {
        if(!strcmp(mail1,mail2))
        {
            return 0;
        }
    }
    return 1;
}

int destinatario_compareName(Destinatario* pDestinatarioA,Destinatario* pDestinatarioB)
{
    char nameDestinatarioA[51];
    char nameDestinatarioB[51];
    int retorno = -2;
    if(pDestinatarioA!=NULL && pDestinatarioB != NULL)
    {

        destinatario_getName(pDestinatarioA,nameDestinatarioA);
        destinatario_getName(pDestinatarioB,nameDestinatarioB);
        retorno = strcmp(nameDestinatarioA,nameDestinatarioB);
    }
    return retorno ;
}

int destinatario_compareMail(Destinatario* pDestinatarioA,Destinatario* pDestinatarioB)
{
    char nameDestinatarioA[51];
    char nameDestinatarioB[51];
    int retorno = -2;
    if(pDestinatarioA!=NULL && pDestinatarioB != NULL)
    {
        destinatario_getMail(pDestinatarioA,nameDestinatarioA);
        destinatario_getMail(pDestinatarioB,nameDestinatarioB);
        retorno = strcmp(nameDestinatarioA,nameDestinatarioB);
    }
    return retorno ;
}

int destinatario_compare(Destinatario* pDestinatarioA,Destinatario* pDestinatarioB)
{
    /*int idDestinatarioA;
    int idDestinatarioB;

    if(pDestinatarioA!=NULL && pDestinatarioB != NULL)
    {
        destinatario_getId(pDestinatarioA,&idDestinatarioA);
        destinatario_getId(pDestinatarioB,&idDestinatarioB);
        if(idDestinatarioA > idDestinatarioB)
        {
            retorno = 1;
        }
        else if(idDestinatarioA < idDestinatarioB)
        {
            retorno = -1;
        }

    }*/
    int retorno = 0;
    return retorno;

}


void destinatario_print(Destinatario* this)
{
    char name[51];
    char mail[51];

    if(this != NULL)
    {

        destinatario_getName(this,name);
        destinatario_getMail(this,mail);
        fprintf(stdout,"\n Nombre: %s - Mail: %s ", name,mail);
    }

}


void destinatario_print2(Destinatario* this)
{
    int id;
    char name[51];
    char mail[51];
    int isEmpty;
    if(this != NULL)
    {

        destinatario_getName(this,name);
        destinatario_getMail(this,mail);
        fprintf(stdout,"%s,%s\n", name,mail);
    }

}
