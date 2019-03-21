include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_REP 3
int pedirAcumularMostrar();
int pedirSumarMostrar();

int main()
{
    if(!pedirSumarMostrar())
    {
        printf("\nGOOD");
    }
    return 0;
}

int pedirSumarMostrar()
{
    float numero1;
    float numero2;
    float resultado;
    printf("Ingrese dos numeros a sumar ");
    scanf("%f", &numero1);
    scanf("%f", &numero2);
    resultado = numero1 + numero2;
    printf("\nLa suma es %.2f", resultado);
    return 0;
}

int pedirAcumularMostrar()
{
    //pida dos cosas las acumule y muestre el promedio
    int acumulador = 0;
    int buffer; //variable auxiliar
    int i;
    for(i=0; i<CANTIDAD_REP;i++)
    {
        printf("Ingrese numero a acumular: %d", i+1);
        scanf("%d", &buffer);
        //falta validar
        acumulador = acumulador + buffer;
    }
    printf("El promedio es: %f", acumulador / CANTIDAD_REP);
    return 0;
}
