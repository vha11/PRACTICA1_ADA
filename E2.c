#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar(char *);
void leerCadena(char *);

void main(){
    char *cadena; int numP;
    cadena = (char *)malloc( sizeof(char) * 100 );
    leerCadena(cadena);
    printf(" 'P' consecutivas (>): %d",validar(cadena));
    free(cadena);
}

void leerCadena(char * expresion) {
    printf(" Ingresa la expresion a verificar: ");
    scanf("%s", expresion);
}

int validar(char * expresion){
    int tamanioExpresion, maximoP=0,contador=0;
    tamanioExpresion=strlen(expresion);
    for(int i=0; i<=tamanioExpresion;i++){
        if(expresion[i]=='P'){
            contador++;
            if(contador>maximoP){
                maximoP=contador;
            }
        }else{ contador=0; }     
    }
    return maximoP;  
}