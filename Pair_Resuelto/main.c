#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Destinatario.h"

int main()
{
    ArrayList* listaDestinatarios = al_newArrayList();
    ArrayList* listaNegra = al_newArrayList();
    Destinatario* auxiliarDestinatario;
    int i;
    int indice;
    char seguir='s';
    int opcion=0;
    int id;
    while(seguir=='s')
    {
        printf("\n----MENU----\n");
        printf("\n1. Cargar destinatarios\n");
        printf("2. Cargar lista negra\n");
        printf("3. Depurar\n");
        printf("4. Listar\n");
        printf("5. Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:

                parserLista("destinatarios.csv",listaDestinatarios,"r");

                break;
            case 2:
                parserLista("black_list.csv",listaNegra,"r");
                break;
            case 3:
                for(i=0; i < al_len(listaNegra);i++)
                {
                    do
                    {
                        indice=-1;
                        indice =al_indexOfFuncion(listaDestinatarios, al_get(listaNegra,i),comparoDest);
                        if(indice!=-1)
                        {
                            al_remove(listaDestinatarios,indice);
                        }
                    }while(indice!=-1);

                }
                break;
            case 4:
                 printf("\n----Destinatarios final----\n");

                for(i=0; i < al_len(listaDestinatarios);i++)
                {
                    auxiliarDestinatario = al_get(listaDestinatarios,i);
                    destinatario_print(auxiliarDestinatario);
                }
                break;
            case 5:
                seguir = 'n';
                break;
        }
    }


    return 0;
}
