/*
Programa: Evaluación de empleado
Autor: Samuel 
Fecha: 15/10/2025

Descripción:
Determina si un empleado obtiene una evaluación positiva en función de tres factores:
 - Productividad (0–10)
 - Trabajo en equipo (0–10)
 - Puntuación del supervisor (0–10)

Cálculo final:
 - Productividad: 40%
 - Trabajo en equipo: 30%
 - Supervisor: 30%

Criterio de aprobación:
 - Media ≥ 7.0
 - Ninguna puntuación individual menor que 5.0
*/

#include <stdio.h>

int main (){

    char c1, c2, c3;
    float productividad = 0, supervisor = 0, trabajo_equipo = 0, media = 0;
    int resultadoscanf1 = 0, resultadoscanf2 = 0, resultadoscanf3 = 0, repetir = 0;

    //No incluyo las tildes por los múltiples carácteres erroneos que muestran muchos compiladores de C.
    printf("Evalue a su empleado en funcion de su productividad, su trabajo en equipo y la puntuacion dada por el supervisor. (0-10)\n");

    do {

        repetir = 0;

        printf("\nProductividad: ");
        resultadoscanf1 = scanf("%f%c", &productividad, &c1);
        
        if (resultadoscanf1 != 2 || c1 != '\n') {
            printf("Introduzca un numero valido. (Ej: 7.6)\n");
            while(getchar() != '\n'); 
            repetir = 1; 
        } else if (productividad < 0 || productividad > 10) {
            printf("La nota de Productividad debe estar entre 0 y 10.\n");
            repetir = 1;
        }


        if (repetir == 0) { 
            printf("Trabajo en equipo: ");
            resultadoscanf2 = scanf("%f%c", &trabajo_equipo, &c2);

            if (resultadoscanf2 != 2 || c2 != '\n') {
                printf("Introduzca un numero valido y solo un numero.\n");
                while(getchar() != '\n'); 
                repetir = 1;
            } else if (trabajo_equipo < 0 || trabajo_equipo > 10) {
                printf("La nota de Trabajo en equipo debe estar entre 0 y 10.\n");
                repetir = 1;
            }
        }
        
        if (repetir == 0) {
            
            printf("Puntuacion del supervisor: ");
            resultadoscanf3 = scanf("%f%c", &supervisor, &c3);

            if (resultadoscanf3 != 2 || c3 != '\n') {
                printf("Introduzca un numero valido y solo un numero.\n");
                while(getchar() != '\n');
                repetir = 1;
            } else if (supervisor < 0 || supervisor > 10) {
                printf("La nota del Supervisor debe estar entre 0 y 10.\n");
                repetir = 1;
            }
        }

    } while (repetir == 1);

    //printf("\nDatos validos: %f, %f, %f", productividad, trabajo_equipo, supervisor);


    media = ((productividad * 0.4) + (trabajo_equipo * 0.3) + (supervisor * 0.3));
    printf("\nNota media final: %.2f", media);

    if ((media < 7) || (productividad < 5) || (trabajo_equipo < 5) || (supervisor < 5)){
        printf("\nEvaluacion negativa.\n");
    } else {
        printf("\nEvaluacion positiva.\n");
    }

    return 0;
}


