#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <sys/time.h> 

void llenar(int * , int);
void imprimir(int * , int);
int buscar(int * , int, int);

void main(){

    int *cadena; 
    int N, elem;

     struct timeval inicio, fin;  // Estructuras para almacenar los tiempos
    double tiempo_usado;

    printf("Ingrese el tamano de n: ");
    scanf("%d", &N);

    printf("Ingrese el elem a buscar: ");
    scanf("%d", &elem);
    cadena = (int *)malloc( sizeof(int) * N );

    llenar(cadena, N);
   // imprimir(cadena, N);

     gettimeofday(&inicio, NULL);

     int pos = buscar(cadena, elem, N);

    gettimeofday(&fin, NULL); // Tiempo de fin

    tiempo_usado = (fin.tv_sec - inicio.tv_sec) * 1e6; // Diferencia de segundos a microsegundos
    tiempo_usado = (tiempo_usado + (fin.tv_usec - inicio.tv_usec))*1e-6; 
   if (pos != -1)
   {
    printf("%d se encuentra en la posicion %d \n", elem, pos);
   }else{
        printf("%d No se encuentra en el arreglo \n", elem);

   }
   
    free(cadena);

     

    printf("Tiempo de ejecucion: %f \n", tiempo_usado);
}

void llenar(int * cadena, int N){
    for (int i = 0; i < N; i++)
    {
         cadena[i] = i;
    }
    
}

void imprimir(int * cadena, int N){

    for (int i = 0; i < N; i++)
    {
        printf("%d ", cadena[i]);
    }
    printf("\n");
    
}

int buscar(int * cadena, int elem, int tam){

    int N = tam;
    int left = 0;
    int right = tam-1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (cadena[mid] == elem)
            return mid;

        
        if (cadena[mid] < elem)
            left = mid + 1;

        
        else
            right = mid - 1;
    }

   //No se encuentra
    return -1;
}
    
