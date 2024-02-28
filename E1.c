#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main(){
    char word[100];
    printf("Introduce la cadena: ");
    scanf("%s",word);
    for(int i=0; word[i]!='\0';i++){
        word[i]=tolower(word[i]);
    }
    printf("Cadena en minusculas: %s",word);
}

