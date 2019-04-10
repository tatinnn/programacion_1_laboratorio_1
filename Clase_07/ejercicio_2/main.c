#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getString (char* pResultado, char *msg, char *msgError, int minimo, int maximo, int reintento);
int isValidNumber (char *cadena);
int getNumber (int *pResultado, char *msg, char *msgError, int minimo, int maximo, int reintento);

/*int main()
{
    printf("Hello world!\n");
    return 0;
}*/


int getString (char* pResultado, char *msg, char *msgError, int minimo, int maximo, int reintento) //falso string
{
    char bufferStr[4096];
    fgets(bufferStr, sizeof(bufferStr), stdin); //aca el fgets nos da lo que ingresamos por teclado + tecla enter (salto linea)
    bufferStr[strlen(bufferStr)-1] = '\0'; //aca el array bufferStr sub indice strlen(bufferStr) nos da la posicion del \0,
    //con lo cual si le restamos una posicion, dejamos afuera del string al enter.
    return 0;
}

int isValidNumber (char *cadena); //falsa validacion
{
    return 1;
}

int getNumber (int *resultado, char *msg, char *msgError, int minimo, int maximo, int reintento)
{
    int retorno = -1;
    char bufferStr[4096];
    int bufferInt;

    if(resultado != NULL && reintentos >= 0) //Faltan (esto lo puso el profe, ni idea x q)
    {
        if(getString(bufferStr, msg, msgError, 1, 7, 1) && isValidIntNumber(bufferStr))
        {
            bufferInt = atoi(bufferStr);
            if(bufferInt >= minimo && bufferInt <= maximo)
            {
                *resultado = bufferInt;
                retorno = 0;
            }
        }
    }
    return retorno;
}
