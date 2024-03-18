#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h> // Incluir para gettimeofday

void llenar(int *, int);
void imprimir(int *, int);
void mergeSort(int *, int, int);
void merge(int *, int, int, int);

int main() {
    int *cadena;
    int N;
    struct timeval inicio, fin; // Estructuras para almacenar los tiempos
    double tiempo_usado;

    printf("Ingrese el tamano de n\t");
    scanf("%d", &N);

    cadena = (int *)malloc(sizeof(int) * N);

    llenar(cadena, N);

    if(N < 50){
        imprimir(cadena, N);
        printf("\n\n");
    }
    

    gettimeofday(&inicio, NULL);

    mergeSort(cadena, 0, N - 1);

    gettimeofday(&fin, NULL); // Tiempo de fin

    tiempo_usado = (fin.tv_sec - inicio.tv_sec) * 1e6; // Diferencia de segundos a microsegundos
    tiempo_usado = (tiempo_usado + (fin.tv_usec - inicio.tv_usec)) * 1e-6;
   
    if(N < 50){
        imprimir(cadena, N); // Ya ordenado
    }

    free(cadena);

    printf("Tiempo de ejecucion: %f \n", tiempo_usado);

    return 0;
}

void llenar(int *cadena, int N) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        int n = rand() % 99 + 1; // Cambiado para incluir el 99
        cadena[i] = n;
    }
}

void imprimir(int *cadena, int N) {
    for (int i = 0; i < N; i++) {
        printf("%d  ", cadena[i]);
    }
    printf("\n");
}

void mergeSort(int *cadena, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;
        mergeSort(cadena, inicio, medio);
        mergeSort(cadena, medio + 1, fin);
        merge(cadena, inicio, medio, fin);
    }
}

void merge(int *cadena, int inicio, int medio, int fin) {
    int i, j, k;
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = cadena[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = cadena[medio + 1 + j];

    i = 0;
    j = 0;
    k = inicio;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            cadena[k] = L[i];
            i++;
        } else {
            cadena[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        cadena[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        cadena[k] = R[j];
        j++;
        k++;
    }
}
