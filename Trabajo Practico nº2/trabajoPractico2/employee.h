#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
typedef struct(
    int idEmployee;
    int isEmpty;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
)Employee;

int employee_Init(Employee* pEmployee,int limite);

#endif // EMPLOYEE_H_INCLUDED
