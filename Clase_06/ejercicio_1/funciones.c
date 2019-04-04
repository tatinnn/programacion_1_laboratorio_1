#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "funciones.h"

int ordenarArrayMayorMenor(int* arrayNumeros, int MAX)
{
    int i;
    int j;
    int buffer;
    for (i=0;i<MAX-1;i++)
    {
        for(j=i+1;j<MAX;j++)
        {
            if(arrayNumeros[i]>arrayNumeros[j])
            {
                buffer = arrayNumeros[i];
                arrayNumeros[i] = arrayNumeros[j];
                arrayNumeros[j] = buffer;
            }
        }
    }
    return 0;
}

int buscarNumeroEnArray(int* arrayNumeros, int MAX, int numero)
{
    int i;
    for(i=0;i<MAX;i++)
    {
        if(arrayNumeros[i]==numero)
        {
            return -1;
        }
    }
    return 0;
}

int numeroMinimo(int* arrayNumeros, int MAX, int* pResultado)
{
    int i;
    int numeroMinimo;
    numeroMinimo = arrayNumeros[0];
    for(i=0;i<MAX;i++)
    {
        if(arrayNumeros[i]<numeroMinimo)
        {
            numeroMinimo = arrayNumeros[i];
        }
    }
    *pResultado = numeroMinimo;
    return 0;
}

int numeroMaximo(int* arrayNumeros, int MAX, int* pResultado)
{
    int i;
    int numeroMaximo;
    numeroMaximo = arrayNumeros[0];
    for(i=0;i<MAX;i++)
    {
        if(arrayNumeros[i]>numeroMaximo)
        {
            numeroMaximo = arrayNumeros[i];
        }
    }
    *pResultado = numeroMaximo;
    return 0;
}

int calcularPromedio(int* parrayInt, int limite, float* pResultado)
{
    int i;
    int buffer = 0;
    for(i=0;i<limite;i++)
    {
        buffer=buffer+parrayInt[i];
    }
    *pResultado = (float)buffer/limite;
    return 0;
}

int utn_getArrayNumeros(int* parrayResultado,int limite,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int buffer;
    int i;
    int ret;
    for(i=0;i<limite;i++)
    {
        ret = utn_getNumero(&buffer,"Ingrese un numero:\n","El numero ingresado no es valido. Ingrese otro numero:\n",0,100,3);
        if(ret == -1)
        {
            break;
        }

        *(parrayResultado+i) = buffer;
    }
    return ret;
}

int utn_getNumero(int* pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    int num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getInt(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getInt(int *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atoi(buffer);
    return 0;
}

int utn_getFloat(float *pResultado,const char *mensaje,const char *mensajeError,int minimo,int maximo,int reintentos)
{
    int ret;
    float num;

    while (reintentos>0)
    {
        printf("%s",mensaje);
        if (getFloat(&num)==0)
        {
            if (num<=maximo && num>=minimo)
            {
                break;
            }
        }
                __fpurge(stdin);
                reintentos--;
                printf("%s\n",mensajeError);
    }
    if(reintentos==0)
    {
        ret=-1;
    }else
        {
            ret=0;
            *pResultado = num;
        }
    return ret;
}

int getFloat(float *pResultado)
{
    char buffer[64];
    scanf("%s",buffer);

    *pResultado = atof(buffer);
    return 0;
}

int utn_getChar(char* pResultado,const char *mensaje,const char *mensajeError,const char *minimo,const char *maximo,int reintentos)
{
    int ret = -1;
    char buffer[64];
    int i;

    do{
        printf("%s",mensaje);
        scanf("%s", buffer);
        i=0;
        while (buffer[i]!='\0' && i<2)
        {

            if (buffer[0]>=minimo[0] && buffer[0]<=maximo[0])
            {
                ret=0;
            }
            i++;
        }

        if (ret==0 && i==1)
        {
            pResultado = buffer;
            break;
        }
        reintentos--;
        printf("%s\n",mensajeError);
        ret = -1;
        __fpurge(stdin);

    }while (reintentos>0);
    return ret;
}










