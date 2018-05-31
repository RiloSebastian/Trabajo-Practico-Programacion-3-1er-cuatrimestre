#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "validaciones.h"



char validarnombre(char input[]){

int i;
int j=0;
int retorno;

do{
 fflush(stdin);
 gets(input);
 i=strlen(input);

  while(j<i){
   if((input[j]> 64 && input[j]<91) || (input[j]>96 && input[j]<123) || input[j]==160 || input[j]==161 || input[j]==162 || input[j]==168 || input[j]==173){
    retorno= 0;
    j++;
   }
   else if((input[j]>159 && input[j]<166) || input[j]== 32 || input[j]== 44 || input[j]==130 || input[j]==181 || input[j]==144 || input[j]==214 || input[j]==224 || input[j]==233){
    retorno= 0;
    j++;
   }
   else{
    retorno= 1;
    printf(" Error, vuelva a ingresar:\n ");
    break;
   }
  }
 }while(retorno!=0);


return input[50];
}


char validardescripcion(char input[]){
int i;
int j=0;
int retorno;

do{
 fflush(stdin);
 gets(input);
 i=strlen(input);

  while(j<i){
   if((input[j]> 64 && input[j]<91) || (input[j]>96 && input[j]<123) || (input[j]>159 && input[j]<166) || input[j]==168 || input[j]==173){
    retorno= 0;
    j++;
   }
   else if((input[j]> 31 && input[j]<64) || input[j]==130 || input[j]==181 || input[j]==144 || input[j]==214 || input[j]==224 || input[j]==233){
    retorno= 0;
    j++;
   }
   else{
    retorno= 1;
    printf(" Error, vuelva a ingresar:\n ");
    break;
   }
  }
 }while(retorno!=0);


return input[200];
}


int validarNumero(int numero){
int num;
int i;
int j=0;
int retorno;
char numAux[30];

do{
 fflush(stdin);
 gets(numAux);

 i=strlen(numAux);

 while(j<i){

  if((numAux[j]> 47 && numAux[j]<58) || (numAux[j]>43 && numAux[j]<47)){
   retorno= 0;
   j++;
  }
  else{
   retorno= 1;
   break;
  }
 }
 if(retorno!=0){
  printf("Error: debe ingresar datos enteros\n vuelva a ingresar: ");
  }
}while(retorno!=0);

num=atoi(numAux);
numero=num;
return numero;
}
