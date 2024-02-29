#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
    int contMayus = 0, contMinus = 0;
    char word[100];

    printf("Introduce la cadena: ");
    scanf("%s", word);

    for (int i = 0; word[i] != '\0'; i++) {
        if (isupper(word[i])) {  //Compara si es mayuscula
            contMayus++;
        } else if (islower(word[i])) { //Compara si es minuscula 
            contMinus++;
        }
    }

    for (int i = 0; word[i] != '\0'; i++) {
        if (contMayus > contMinus) {
            // Convertir toda la cadena a mayúsculas
            word[i] = toupper(word[i]);
        } else {
            // Convertir toda la cadena a minúsculas
            word[i] = tolower(word[i]);
        }
    }

    printf("Cadena corregida: %s", word);
}
