#include <stdio.h>
#include "validaciones.h"

int validar_int(char mensaje[]) {
    int valor;
    do {
        printf("%s", mensaje);
        if (scanf("%d", &valor) != 1 || valor < 0) {
            printf("Error: Ingrese un numero entero positivo.\n");
            while (getchar() != '\n'); // Limpia el desastre
        } else return valor;
    } while (1);
}

float validar_float(char mensaje[]) {
    float valor;
    do {
        printf("%s", mensaje);
        if (scanf("%f", &valor) != 1 || valor < 0) {
            printf("Error: Ingrese un valor numerico positivo.\n");
            while (getchar() != '\n'); // Limpia el desastre
        } else return valor;
    } while (1);
}