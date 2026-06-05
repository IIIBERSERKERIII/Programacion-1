#include <stdio.h>
#include "fabrica.h"

int main() {
    char nombres[MAX_PROD][MAX_CHARS];
    int c[MAX_PROD];           
    float t[MAX_PROD];         
    float r[MAX_PROD];         
    int total = 0, op;         

    do {
        printf("\n--- SISTEMA DE GESTION DE FABRICA ---\n");
        printf("1. Registrar nuevo producto\n");
        printf("2. Editar producto existente\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular viabilidad de produccion\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        
        if (scanf("%d", &op) != 1) {
            printf("Entrada invalida. Intente de nuevo.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch(op) {
            case 1: 
                registrar(nombres, c, t, r, &total); 
                break;
            case 2: 
                editar(nombres, c, t, r, total); 
                break;
            case 3: 
                eliminar(nombres, c, t, r, &total); 
                break;
            case 4: 
                calcular(c, t, r, total); 
                break;
            case 5: 
                printf("Cerrando sistema...\n"); 
                break;
            default: 
                printf("Opcion no valida.\n");
        }
    } while(op != 5);

    return 0;
}