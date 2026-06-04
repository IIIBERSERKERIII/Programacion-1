#include <stdio.h>
#include "fabrica.h"

int main() {
    char nombres[MAX_PROD][MAX_CHARS];
    int cantidades[MAX_PROD];
    float tiempos[MAX_PROD];
    float recursos[MAX_PROD];
    int totalProductos = 0;
    int opcion;

    do {
        printf("\n--- MENU FABRICA V2.0 ---\n");
        printf("1. Registrar Producto\n");
        printf("2. Editar Producto\n");
        printf("3. Eliminar Producto\n");
        printf("4. Calcular Viabilidad\n");
        printf("5. Salir\n");
        printf("Opcion: ");
        
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: 
                registrar(nombres, cantidades, tiempos, recursos, &totalProductos); 
                break;
            case 2: 
                editar(nombres, cantidades, tiempos, recursos, totalProductos); 
                break;
            case 3: 
                eliminar(nombres, cantidades, tiempos, recursos, &totalProductos); 
                break;
            case 4: 
                calcular(cantidades, tiempos, recursos, totalProductos); 
                break;
            case 5: 
                printf("Cerrando el sistema...\n"); 
                break;
            default: 
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while(opcion != 5);
    
    return 0;
}