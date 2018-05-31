#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"
#define TAM 10


int main()
{

eMovie movie[TAM];
eMovie* direc;
direc= movie;
char seguir='s';
int opcion=0;
int index=-1;

inicializar(movie, TAM);
    while(seguir=='s')
    {
     fflush(stdin);
     printf("\n 1- Agregar pelicula\n");
     printf(" 2- Borrar pelicula\n");
     printf(" 3- modificar pelicula\n");
     printf(" 4- Generar pagina web\n");
     printf(" 5- mostrar lista de peliculas\n");
     printf(" 6- Salir\n\n ");

     opcion=validarNumero(opcion);

     switch(opcion)
      {
       case 1:

         index= agregarPelicula(direc, TAM);
         if(index==1){
          printf(" pelicula agregada\n");
         }
        else{
          printf(" la pelicula no ha sido agregada\n");
         }
        break;
       case 2:
         mostrarListado(direc,TAM);
         index= borrarPelicula(direc, TAM);
         if(index==1){
          printf(" pelicula eliminada\n");
         }
         else{
           printf(" pelicula no eliminada\n");
         }
        break;
       case 3:
          mostrarListado(direc,TAM);
          index=modificarPelicula(direc, TAM);
         if(index==1){
           printf(" pelicula modificada\n");
         }
         else{
            printf(" pelicula no modificada\n");
         }
        break;
       case 4:
        generarPagina(direc,TAM);
        break;
       case 5:
        mostrarListado(direc,TAM);
        break;
       case 6:
        seguir = 'n';
        break;
       default:
         printf(" Ingrese una e las opciones mostradas con anterioridad\n");
        break;
        }
    }

    return 0;
}
