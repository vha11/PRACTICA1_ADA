#include <stdio.h>
#include <stdlib.h>

//Sucesion

float validar(float[3]);
float get_type(float[3]);
float get_grow(float, float[3]);
void next_value(float [3], float, float);

void main(){

    float nums[3];

    do
    {
        for (int i = 0; i < 3; i++)
        {
            printf("Ingrese la cadena de numeros \n");
            scanf("%f", &nums[i]); /* code */
        }
        for (int i = 0; i < 3; i++)
        {
            printf("%f \t",nums[i] );
           
        }
        
        if (validar(nums)){
           float tipo = get_type(nums);
            float crec =  get_grow(tipo, nums);
             next_value(nums,tipo, crec);
        }
        
    } while (validar(nums));
    

}

float validar(float num[3]){
    float bandera = 3;

    for (int i = 0; i < 3; i++)
    {
        if (num[i] == 0) bandera--;
    }
    return bandera;    //si son 3 0ś entonces devuelve 0
}

float get_type (float nums[3]){

    float coc = nums[2] / nums[1];
    float coc2 = nums[1] / nums[0];

    float inc = nums[2] - nums[1];
    float inc2 = nums[1] - nums[0];

    if (coc == coc2){
        return 2;    // es deol tipo Geometrica
    }else if (inc == inc2)
    {
        return 1;  //es del tipo aritmetica
    }else{
        return 0;  // no tiene ningun tipo
    }

}

float get_grow(float tipo, float nums[3]){
    if (tipo == 1)
    {
       return nums[2] - nums[1];
    }
     if (tipo == 2)
    {
       return nums[2] / nums[1];
    }
    return 0;
}

void next_value(float nums[3], float tipo , float crec){

   if (tipo == 1) {
       printf("%2f \n sucecion de Tipo Aritmetica \n", (nums[2] + crec));
    } 
    if (tipo == 2) {
        printf("%2f \n sucecion de Tipo Geometrica \n", (nums[2] * crec));
    } 
    if (tipo == 0){
        printf("0 \n sucecion de Tipo Inexistente \n");
    }
       
}
