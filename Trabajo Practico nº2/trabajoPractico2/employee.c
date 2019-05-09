#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "employee.h"


static int proximoId();

int employee_Init(Employee* pEmployee,int limite){
    int retorno=-1;
    int i;


    if(pEmployee != NULL && limite>0){
        for(i=0; i<limite; i++){
            retorno=0;
            pEmployee[i].isEmpty=1;
        }
    }
    return retorno;
}

int employee_Alta(Employee* pEmployee.)





















static int proximoId(){
    static int proximoId;
    proximoId++;
    return proximoId;
}
