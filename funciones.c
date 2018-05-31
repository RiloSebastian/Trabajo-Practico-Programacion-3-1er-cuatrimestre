#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "validaciones.h"
#define LIBRE 0
#define OCUPADO 1

void inicializar( eMovie* movie, int cant){
int i;

 if(cant > 0 && movie!=NULL){
  for(i=0; i<cant; i++){
   (movie+i)->estado=LIBRE;
   (movie+i)->id=LIBRE;
  }
 }
}


int buscarLibre(eMovie* movie, int cant){
int indice=-1;
int i;

if(cant > 0 && movie!=NULL){
 for(i=0;i<cant;i++){
  if((movie+i)->estado==0){
   indice=i;
   break;
  }
 }
}
return indice;
}


int siguienteId(eMovie* movie,int cant){
int retorno = 0;
int i;

if(cant > 0 && movie != NULL){
 for(i=0; i<cant; i++){
  if((movie+i)->estado == OCUPADO){
   if((movie+i)->id >retorno){
    retorno=(movie+i)->id;
   }
  }
 }
}
retorno++;
return retorno;
}

int agregarPelicula(eMovie* movie, int cant){
int index=-1;
int indice;

if(cant>0 && movie!=NULL){
index=0;

indice=buscarLibre(movie,cant);

printf(" ingrese el titulo de la pelicula\n ");
(movie+indice)->titulo[50]=validardescripcion((movie+indice)->titulo);

printf(" ingrese el genero de la pelicula\n ");
(movie+indice)->genero[50]=validarnombre((movie+indice)->genero);

printf(" ingrese la duracion de la pelicula (en minutos)\n ");
(movie+indice)->duracion= validarNumero((movie+indice)->duracion);

printf("ingrese una descripcion para la pelicula\n ");
(movie+indice)->descripcion[200]=validardescripcion((movie+indice)->descripcion);

printf("ingrese la puntuacion para la pelicula (1-100)\n ");

do{
(movie+indice)->puntaje= validarNumero((movie+indice)->puntaje);
if((movie+indice)->puntaje>100 || (movie+indice)->puntaje<1){
 printf("el puntaje debe estar entre 1 y 100: vuelva a escribir:\n ");
}
}while((movie+indice)->puntaje>100 || (movie+indice)->puntaje<1);

printf("ingrese un link para la imagen\n ");
scanf("%s",(movie+indice)->linkImagen);

(movie+indice)->id=siguienteId(movie,cant);

(movie+indice)->estado=OCUPADO;


 enBinario(movie,cant);
 index=1;
 }
 return index;
}


int borrarPelicula(eMovie* movie, int cant){
int index=-1;
int auxId=0;
int i;

if(cant > 0 && movie != NULL){
printf(" Ingrese ID de la pelicula que desea eliminar:\n ");
auxId=validarNumero(auxId);

    for(i=0;i<cant;i++){
     if((movie+i)->id==auxId){
      (movie+i)->estado=LIBRE;
      index=1;
      break;
     }
    }
   }
enBinario(movie,cant);
return index;
}


int modificarPelicula(eMovie* movie, int cant){
int index=-1;
int aux=0;
int i;

printf(" ingrese id de la pelicula que desee modificar\n ");
aux=validarNumero(aux);
 if(cant > 0 && movie != NULL){
  for(i=0;i<cant; i++){
    if((movie+i)->estado == OCUPADO && aux==(movie+i)->id){
     printf(" ingrese el titulo de la pelicula\n ");
     (movie+i)->titulo[20]=validardescripcion((movie+i)->titulo);

     printf(" ingrese el genero de la pelicula\n ");
     (movie+i)->genero[20]=validarnombre((movie+i)->genero);

     printf(" ingrese la duracion de la pelicula (en minutos)\n ");
     (movie+i)->duracion= validarNumero((movie+i)->duracion);

     printf("ingrese una descripcion para la pelicula\n ");
     (movie+i)->descripcion[200]=validardescripcion((movie+i)->descripcion);

     printf("ingrese la puntuacion para la pelicula (1-100)\n ");

    do{
     (movie+i)->puntaje= validarNumero((movie+i)->puntaje);

     if((movie+i)->puntaje>100 || (movie+i)->puntaje<1){
      printf("el puntaje debe estar entre 1 y 100: vuelva a escribir:\n ");
     }
    }while((movie+i)->puntaje>100 || (movie+i)->puntaje<1);

    printf("ingrese un link para la imagen\n ");
    scanf("%s",(movie+i)->linkImagen);

     enBinario(movie,cant);
     index=1;
    }
   }
  }
 return index;
}

void enBinario(eMovie* movie, int cant){
int i;
FILE* pelicula;
pelicula=fopen("peliculas.bin","wb");

 if(cant>0 && pelicula!= NULL){
  for(i=0;i<cant;i++){
   if((movie+i)->estado==OCUPADO){
    fwrite(movie,sizeof(eMovie),cant,pelicula);
   }
  }
 }
 fclose(pelicula);
}


void generarPagina(eMovie* movie, int cant){
FILE* pelicula;
int i;

pelicula=fopen("peliculas.bin","rb");
if(cant>0 && pelicula!= NULL){

while(!feof(pelicula)){
 fread(movie,sizeof(eMovie),cant,pelicula);
 if(feof(pelicula)){
  break;
 }
  i++;
}

 fclose(pelicula);

 pelicula=fopen("paginaPelicula.html","w");
 for(i=0;i<cant;i++){
            if((movie+i)->estado == OCUPADO){
                fprintf(pelicula,"<html lang='en'><head>"
                                "<meta charset='utf-8'>"
                                "<meta http-equiv='X-UA-Compatible' content='IE=edge'>"
                                "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                                "<title>LISTADO DE PELICULAS</title></head><body style=background-color:darkred;>");
                fprintf(pelicula,"<div style='background-color:darkgray; margin:10px;' class='container'>"
                                "<div ;style='overflow:visible;' class='row'>"
                                "<article class='col-md-4 article-intro'>"
                                "<a href='#'>");
                fprintf(pelicula,"<img style='width:100px; height:100px; padding:15px;' class='img-responsive img-rounded' src='%s' alt=''>",(movie+i)->linkImagen);
                fprintf(pelicula,"</a>");
                fprintf(pelicula,"<h3 style='padding:10px;'>");
                fprintf(pelicula,"<a>%s</a>",(movie+i)->titulo);
                fprintf(pelicula,"</h3>");
                fprintf(pelicula,"<ul>");
                fprintf(pelicula,"<li>GENERO: %s</li>",(movie+i)->genero);
                fprintf(pelicula,"<li>DURACION: %d</li>",(movie+i)->duracion);
                fprintf(pelicula,"<li>PUNTAJE: %d</li>",(movie+i)->puntaje);

                fprintf(pelicula,"</ul>");
                fprintf(pelicula,"<p style='padding:15px;'> SINOPSIS: %s</p>",(movie+i)->descripcion);
                fprintf(pelicula,"</article>" "</div>""<!-- /.row -->""</div>""<!-- /.container -->""</body></html>");
            }
        }
}
    fclose(pelicula);
}


void mostrar(eMovie* movie){
printf(" TITULO:%s\n GENERO:%s\n DURACION:%d\n DESCRIPCION:%s\n PUNTAJE:%d\n LINK DE IMAGEN:%s\n ID:%d\n\n",movie->titulo,movie->genero,movie->duracion,movie->descripcion,movie->puntaje,movie->linkImagen,movie->id);
}

void mostrarListado(eMovie* movie, int cant){
int i;

   if(cant > 0 && movie != NULL){
        for(i=0; i<cant; i++){
            if((movie+i)->estado==OCUPADO){
             fflush(stdin);
             mostrar((movie+i));
   }
  }
 }
}
