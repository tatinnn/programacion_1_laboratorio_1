#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero;
    int numeroMayor=0;
    int contador;

    do
    {
        printf("Ingrese un numero");
        scanf("%d",&numero);

        if(contador==0)
        {
            numeroMayor= numero;
        }

        if(numero > numeroMayor)
        {
            numeroMayor= numero;
        }
    }
    while(numero != -1);

    printf("El mayor numero ingresado fue: %d",numeroMayor);
    return 0;

}
