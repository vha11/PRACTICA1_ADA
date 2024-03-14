#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h> // Incluir para gettimeofday

void llenar(int *, int);

void imprimir(int *, int);

void ordenaInsercion(int* A, int n);

void main() {
    
    int *cadena;
    int N;
    struct timeval inicio, fin;  // Estructuras para almacenar los tiempos
    double tiempo_usado;

    printf("Ingrese el tamano de n \t");
    scanf("%d", &N);


    cadena = (int *)malloc(sizeof(int) * N);


    llenar(cadena, N);
    //imprimir(cadena, N);
    gettimeofday(&inicio, NULL);
    ordenaInsercion(cadena, N);
    gettimeofday(&fin, NULL); // Tiempo de fin

    if (N <= 50) {
        printf("\nOrdenado: ");
        for (int i = 0; i < N; i++) {
            printf("%d \n", cadena[i]);
        }
    }

    tiempo_usado = (fin.tv_sec - inicio.tv_sec) * 1e6; // Diferencia de segundos a microsegundos
    tiempo_usado = (tiempo_usado + (fin.tv_usec - inicio.tv_usec)) * 1e-6;

    free(cadena);

    printf("\nTiempo de ejecucion: %f \n", tiempo_usado);

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

void ordenaInsercion(int* A, int n){
	
	int i, j, aux;
	
	for(i=1; i < n; i++){
		j = i;
		aux = A[ i ];
		while( j > 0 && aux < A[ j-1]  ){
			A[ j ] = A[ j-1];
			j--;
		}
		A[j] = aux;
	}
}
