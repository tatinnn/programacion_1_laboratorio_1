#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED

typedef struct{
    int idAutor;
    int isEmpty;
    char nombre[31];
    char apellido[31];
}Autor;


/**
    @brief realizar una carga de datos de manera automatica al iniciar el programa
    @param pAutor: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param nombre: guarda una cadena de caracteres recibida
    @param apellido: guarda una cadena de caracteres recibida
    @return return 0 OK, -1 error.
*/
int autor_altaForzada(Autor* pAutor,int limite,char* nombre, char* apellido);
/**
    @brief carga un valor en el mismo campo de todas las posiciones del array recibido
    @param pAutor: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int autor_inicializar(Autor* pAutor,int limite);
/**
    @brief carga valores en la posicion del array recibida
    @param pAutor: guarda el array recibido
    @param indice: guarda el int de la posicion del array
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int autor_cargarIndice(Autor* pAutor,int indice,int limite);
/**
    @brief muestra los datos de todas las posiciones del array
    @param pAutor: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int autor_mostrarIndice(Autor* pAutor,int limite);
/**
    @brief busca dentro del array hasta encontrar un indice vacio donde cargar datos
    @param pAutor: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param indiceVacio: guarda el indice de la posicion vacia del array
    @return return 0 OK, -1 error.
*/
int autor_obtenerIndiceVacio(Autor* pAutor,int limite,int* indiceVacio);
/**
    @brief recibe un ID para modificar una posicion del array
    @param pAutor: guarda el array recibido
    @param id:guarda el int recibido del ID a modificar
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int autor_modificarIndice(Autor* pAutor,int id, int limite);
/**
    @brief recibe un ID para buscar un empleado
    @param pAutor: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int del empleado a buscar
    @return return el indice del array donde esta el empleado
*/
int autor_buscarAutorPorId(Autor* pAutor,int limite,int id);
/**
    @brief recibe un ID para borrar un empleado
    @param pAutor: guarda el array recibido
    @param limite: guarda el int del limite del array
    @param id:guarda el int del empleado a borrar
    @return return 0 OK, -1 error.
*/
int autor_borrarEmployee(Autor* pAutor,int limite,int id);

/**
    @brief recibe el array para checkear si esta cargado o no
    @param pAutor: guarda el array recibido
    @param limite: guarda el int del limite del array
    @return return 0 OK, -1 error.
*/
int autor_checkIndiceVacio(Autor* pAutor,int limite);


int autor_ordenarAutorPorNombreYApellido(Autor* pAutor, int limite);



#endif // AUTOR_H_INCLUDED
