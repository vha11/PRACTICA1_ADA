#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validar(char *);
int iniciador(char *, int);
int ContarP(char *, int);
void leerCadena(char *);

void main(){

    char *cadena; int numP;
    cadena = (char *)malloc( sizeof(char) * 100 );
    leerCadena(cadena);
    int tam = validar(cadena);
    printf(" Peridos Necesarios (>): %d",ContarP(cadena, tam));
    free(cadena);
}

void leerCadena(char * expresion) {
    printf(" Ingresa la expresion a verificar: ");
    scanf("%s", expresion);
}

int validar(char * expresion){
    int tamanioExpresion, maximoP=0,contador=0;
    tamanioExpresion=strlen(expresion);
    
    return tamanioExpresion;  
}

int iniciador(char * expresion, int lenght){
    int i = 0;
    while (expresion[i] != 'A')
    {
        i++;
    }
    return i;

}

int ContarP(char * expresion, int tamanioExpresion){
    int maximoP = 0, contador = 0, inic = iniciador(expresion, tamanioExpresion);

    if (tamanioExpresion == inic)
    {
        return 0;
    }


    for(int i= inic; i<=tamanioExpresion;i++){
        if(expresion[i]=='P'){
            contador++;
            if(contador>maximoP){
                maximoP=contador;
            }
        }else{ contador=0; }     
    }
    
    return maximoP;  
}
