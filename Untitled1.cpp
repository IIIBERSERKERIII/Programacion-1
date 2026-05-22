#include <stdio.h>
#include <string.h>

#define MAX_PROD 5
#define MAX_CHARS 50

// --- VARIABLES GLOBALES (Arreglos Paralelos) ---
char nombres[MAX_PROD][MAX_CHARS];
int cantidades[MAX_PROD];
float tiempos[MAX_PROD];
float recursos[MAX_PROD];
int totalProductos = 0;

// --- PROTOTIPOS ---
int buscar(char query[]);
void registrar();
void editar();
void eliminar();
void calcular();

int main() {
    int opcion;
    do {
        printf("\n--- MENU FABRICA V 1.0 ---\n");
        printf("1. Registrar Producto\n2. Editar Producto\n3. Eliminar Producto\n4. Calcular Viabilidad\n5. Salir\nOpcion: ");
        scanf("%d", &opcion);
        getchar(); 

        switch(opcion) {
            case 1: registrar(); break;
            case 2: editar(); break;
            case 3: eliminar(); break;
            case 4: calcular(); break;
            case 5: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while(opcion != 5);
    return 0;
}

// --- LOGICA DE FUNCIONES ---
int buscar(char query[]) {
    for (int i = 0; i < totalProductos; i++) {
        if (strcmp(nombres[i], query) == 0) return i;
    }
    return -1;
}

void registrar() {
    if (totalProductos >= MAX_PROD) {
        printf("Limite maximo alcanzado.\n");
        return;
    }
    printf("Nombre: "); scanf("%s", nombres[totalProductos]);
    printf("Cantidad: "); scanf("%d", &cantidades[totalProductos]);
    printf("Tiempo unitario: "); scanf("%f", &tiempos[totalProductos]);
    printf("Recurso unitario: "); scanf("%f", &recursos[totalProductos]);
    totalProductos++;
    printf("Producto registrado.\n");
}

void editar() {
    char query[MAX_CHARS];
    printf("Nombre a editar: "); scanf("%s", query);
    int idx = buscar(query);
    if (idx != -1) {
        printf("Nueva Cantidad: "); scanf("%d", &cantidades[idx]);
        printf("Nuevo Tiempo: "); scanf("%f", &tiempos[idx]);
        printf("Nuevo Recurso: "); scanf("%f", &recursos[idx]);
        printf("Actualizado.\n");
    } else {
        printf("No encontrado.\n");
    }
}

void eliminar() {
    char query[MAX_CHARS];
    printf("Nombre a eliminar: "); scanf("%s", query);
    int idx = buscar(query);
    if (idx != -1) {
        // Corrimiento de datos
        for (int i = idx; i < totalProductos - 1; i++) {
            strcpy(nombres[i], nombres[i+1]);
            cantidades[i] = cantidades[i+1];
            tiempos[i] = tiempos[i+1];
            recursos[i] = recursos[i+1];
        }
        totalProductos--;
        printf("Eliminado.\n");
    } else {
        printf("No encontrado.\n");
    }
}

void calcular() {
    if (totalProductos == 0) { printf("Sin datos.\n"); return; }
    float tTotal = 0, rTotal = 0, tLimite, rLimite;
    printf("Tiempo disponible en fabrica: "); scanf("%f", &tLimite);
    printf("Recursos disponibles: "); scanf("%f", &rLimite);

    for (int i = 0; i < totalProductos; i++) {
        tTotal += cantidades[i] * tiempos[i];
        rTotal += cantidades[i] * recursos[i];
    }
    
    printf("\nTiempo Requerido: %.2f | Disponible: %.2f\n", tTotal, tLimite);
    printf("Recurso Requerido: %.2f | Disponible: %.2f\n", rTotal, rLimite);
    if (tTotal <= tLimite && rTotal <= rLimite) printf("VIABLE\n");
    else printf("NO VIABLE\n");
}
