#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    int id;
    char titulo[50];
    char genero[50];
    int duracion;
    char descripcion[200];
    int puntaje;
    char linkImagen[300];
    int estado;
}eMovie;

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(eMovie* movie, int cant);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(eMovie* movie, int cant);


/**
 * modifica una pelicula del archivo binario
 * @param la estructura donde se encuentra la pelicula a modificar.
 * @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int modificarPelicula(eMovie* movie, int cant);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param cantidad maxima de peliculas.
 */
void generarPagina(eMovie* movie, int cant);

/**
 *  Genera un archivo binario donde se cargan los datos de las peliculas
 *  @param  la estructura a ser agregada al archivo.
 *  @param cantidad maxima de peliculas.
 */
void enBinario(eMovie* movie, int cant);

/**
 *  inicializa los estados e Ids en 0 .
 *  @param la estructura donde se encuentran los datos de las peliculas
 *  @param cantidad maxima de peliculas.
 */
void inicializar( eMovie* movie, int cant);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param la estructura donde se encuentran los datos de las peliculas.
 *  @param cantidad maxima de peliculas.
 *  @return retorna el id correspondiente a una pelicula
 */
int siguienteId(eMovie* movie,int cant);


/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param la estructura donde se encuentran los datos de las peliculas.
 *  @param cantidad maxima de peliculas.
 *  @return retorna la posicion libre en la variable donde se encuentran las peliculas
 */
int buscarLibre(eMovie* movie, int cant);

/**
 *  muestra los datos de una pelicula
 *  @param la estructura donde se encuentran los datos de las peliculas.
 *  @param cantidad maxima de peliculas.
 */
void mostrar(eMovie* movie);

/**
 *  muestra una lista de las peliculas con sus respectivos datos
 *  @param la estructura donde se encuentran los datos de las peliculas.
 *  @param cantidad maxima de peliculas.
 */
void mostrarListado(eMovie* movie, int cant);

#endif
