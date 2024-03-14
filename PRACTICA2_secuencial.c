#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h> // Incluir para gettimeofday


void llenar(int *, int);
void imprimir(int *, int);
void buscar(int *, int, int);

int main(){  

    int *cadena; 
    int N, elem;
      struct timeval inicio, fin;  // Estructuras para almacenar los tiempos
    double tiempo_usado;

    printf("Ingrese el tamano de n\t");
    scanf("%d", &N);

    printf("Ingrese el elem a buscar\t");
    scanf("%d", &elem);
    cadena = (int *)malloc(sizeof(int) * N);


    llenar(cadena, N);
   // imprimir(cadena, N);

   gettimeofday(&inicio, NULL);

    buscar(cadena, elem, N);

      gettimeofday(&fin, NULL); // Tiempo de fin

    tiempo_usado = (fin.tv_sec - inicio.tv_sec) * 1e6; // Diferencia de segundos a microsegundos
    tiempo_usado = (tiempo_usado + (fin.tv_usec - inicio.tv_usec))*1e-6;

    free(cadena);

    printf("Tiempo de ejecucion: %f \n", tiempo_usado);

    return 0; 
}

void llenar(int *cadena, int N){
    srand(time(NULL));
    for (int i = 0; i < N; i++){
        int n = rand() % (2*99) - 99;
        cadena[i] = n;
    }
}

void imprimir(int *cadena, int N){
    for (int i = 0; i < N; i++){
        printf("%d  ", cadena[i]);
    }
    printf("\n");
}

void buscar(int* cadena, int elem, int N){
    for (int i = 0; i < N; i++){
        if (cadena[i] == elem){
            printf("Se encuentra en la posicion %d\n", i);
            return;
        }
    }
    printf("No se encuentra en el arreglo\n");
}
