#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "autor.h"
#define MENU_MODIFICAR "Ingrese la opcion que desea modificar:\n\
1)Nombre\n\
2)Apellido\n\
3)Sector\n\
4)Salario\n\
5)Terminar\n\
Elija:"

static int proximoId();

int autor_altaForzada(Autor* pAutor,int limite,char* nombre, char* apellido)
{
    int retorno=-1;
    int indice;
    autor_obtenerIndiceVacio(pAutor,limite,&indice);

    if(pAutor!=NULL && limite>0)
    {
          if(indice >= 0)
          {
            strncpy(pAutor[indice].nombre,nombre,31);
            strncpy(pAutor[indice].apellido,apellido,31);
            pAutor[indice].idAutor=proximoId();
            pAutor[indice].isEmpty=0;
            retorno =0;
          }

    }


    return retorno;
}

int autor_cargarDatosVacio(Autor* pAutor, int limite)
{
    int retorno=-1;
    int i;
    if(pAutor != NULL && limite >0)
    {
        for(i=0;i<limite;i++)
        {
            pAutor[i].isEmpty=-1;
        }
        retorno=0;
    }

    return retorno;
}
int autor_cargarIndice(Autor* pAutor,int indice,int limite)
{
    int retorno=-1;
    char auxNombre[31];
    char auxApellido[31];

    if(pAutor!=NULL && limite>0)
    {
        if(utn_getLetras(auxApellido,50,2,"Ingrese nombre del autor: ","Ese no es un nombre valido\n")==0)
        {
            strncpy(pAutor[indice].nombre,auxNombre,31);
            if(utn_getLetras(auxApellido,50,2,"Ingrese apellido del autor: ","Ese no es un apellido valido \n")==0)
            {
                        strncpy(pAutor[indice].apellido,auxApellido,31);
                        pAutor[indice].idAutor=proximoId();
                        pAutor[indice].isEmpty=0;
                        retorno =0;

            }
        }
    }
    return retorno;
}

int autor_modificarIndice(Autor* pAutor,int id, int limite)
{
    int retorno=-1;
    char auxNombre[31];
    char auxApellido[31];
    int indice;
    int opcion;
    int salir;
    indice=autor_buscarAutorPorId(pAutor,limite,id);
    if(indice>=0)
    {
        if(pAutor!=NULL && limite>0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                if(utn_getEntero(&opcion,2,MENU_MODIFICAR,"Esa no es una opcion valida\n",0,6)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                            system("cls");
                            if(utn_getLetras(auxNombre,50,2,"Ingrese el nuevo nombre del autor: ","Ese no es un nombre valido\n")==0)
                            {
                                strncpy(pAutor[indice].nombre,auxNombre,50);
                            }
                            fflush(stdin);
                            break;
                        case 2:
                            system("cls");
                            if(utn_getLetras(auxApellido,50,2,"Ingrese el nuevo apellido del autor: ","Ese no es un apellido valido\n")==0)
                            {
                                    strncpy(pAutor[indice].apellido,auxApellido,50);
                            }
                            fflush(stdin);
                            break;
                        case 3:
                            salir=1;
                    }

                 }
            }while(salir==0);
            retorno=0;
        }

    }else
    {
        printf("El ID no existe\n");
        system("pause");
    }
    return retorno;
    return 0;
}

int autor_buscarAutorPorId(Autor* pAutor,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pAutor[i].isEmpty==0)
        {
            if(pAutor[i].idAutor==id)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int autor_borrarAutor(Autor* pAutor,int limite,int id)
{
    int retorno=-1;
    int i;

    for(i=0;i<limite;i++)
    {
        if(pAutor[i].isEmpty==0)
        {
            if(pAutor[i].idAutor==id)
            {
                pAutor[i].isEmpty=-1;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int autor_mostrarIndice(Autor* pAutor,int limite)
{
    int retorno=-1;
    int i;
    if(pAutor != NULL && limite > 0)
    {
        if(autor_ordenarAutorPorNombreYApellido(pAutor,limite)==0)
        {
            for(i=0;i<limite;i++)
            {
                if(pAutor[i].isEmpty==0)
                {
                    printf("\nEl ID del empleado es: %d", pAutor[i].idAutor);
                    printf("\nEl nombre del empleado es: %s",pAutor[i].nombre);
                    printf("\nEl apellido del empleado es: %s",pAutor[i].apellido);
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}

int autor_ordenarAutorPorNombreYApellido(Autor* pAutor, int limite)
{
    int retorno=-1;
    int i=0;
    int flagSwap;
    Autor auxAutor;
    if(pAutor != NULL && limite > 0)
    {
        retorno=0;
        if(pAutor[i].isEmpty==0)
        {
            do
            {
                flagSwap=0;
                for(i=0;i<limite-1;i++)
                {
                    if((pAutor[i].apellido > pAutor[i+1].apellido) ||
                        (pAutor[i].apellido == pAutor[i+1].apellido && strcmp(pAutor[i].nombre,pAutor[i+1].nombre)>0))
                    {
                        flagSwap=1;
                        auxAutor=pAutor[i];
                        pAutor[i]=pAutor[i+1];
                        pAutor[i+1]=auxAutor;
                    }
                }
            }while(flagSwap==1);

        }
    }
    return retorno;
}

int autor_obtenerIndiceVacio(Autor* pAutor,int limite,int* indiceVacio)
{
    int i=0;
    int retorno = -1;
    if(pAutor != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pAutor[i].isEmpty==-1)
            {
                *indiceVacio=i;
                retorno = 0;
                break;
            }
            i++;
        }
    }

    return retorno;
}

int autor_checkIndiceVacio(Autor* pAutor,int limite)
{
    int i=0;
    int retorno = 0;
    if(pAutor != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pAutor[i].isEmpty==0)
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }
    return retorno;
}


static int proximoId()
{
    static int proximoId;
    proximoId++;
    return proximoId;
}
