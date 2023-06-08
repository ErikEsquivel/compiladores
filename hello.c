#include <stdio.h>
#include <math.h>
float x1 (float a,float b,float c);
float x1 (float a,float b,float c);

int main(){ 
    
    float a,b,c;
    printf("Ingresa el valor de a ");
    scanf("%f",&a);
    printf("Ingresa el valor de b ");
    scanf("%f",&b);
    printf("Ingresa el valor de c ");
    scanf("%f",&c);


    float determinante = sqrt(pow(b,2)+4*a*c);

    if(determinante>=0){

        float Rx1 = Calcularx1(a,b,c);
        printf("\n El valor de X1 es: %f",Rx1);
        float Rx2 = Calcularx2(a,b,c);
        printf("\n El valor de X2 es: %f",Rx2);
    }else{

        printf("No existen raices reales");
    }

    return 0;
}

float Calcularx1 (float a,float b,float c){

    float r=-b+sqrt(pow(b,2)+4*a*c)/2*a;
    return r;
}

float Calcularx2  (float a,float b,float c){

    float r2 = -b + sqrt(pow(b,2)+4*a*c)/2*a;
    return r2;
}