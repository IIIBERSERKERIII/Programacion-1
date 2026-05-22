#include <stdio.h>
#include <string.h>

#define MAX_PROD 5
#define MAX_CHARS 50

// --- PROTOTIPOS (Requieren punteros) ---
int buscar(char n[][MAX_CHARS], int total, char query[]);
void registrar(char n[][MAX_CHARS], int *c, float *t, float *r, int *total);
void editar(char n[][MAX_CHARS], int *c, float *t, float *r, int total);
void eliminar(char n[][MAX_CHARS], int *c, float *t, float *r, int *total);
void calcular(int *c, float *t, float *r, int total);

int main() {
    // --- VARIABLES LOCALES (Seguras dentro de main) ---
    char nombres[MAX_PROD][MAX_CHARS];
    int cantidades[MAX_PROD];
    float tiempos[MAX_PROD];
    float recursos[MAX_PROD];
    int totalProductos = 0;
    int opcion;

    do {
        printf("\n--- MENU FABRICA V2.0 ---\n");
        printf("1. Registrar Producto\n2. Editar Producto\n3. Eliminar Producto\n4. Calcular Viabilidad\n5. Salir\nOpcion: ");
        scanf("%d", &opcion);
        getchar();

        switch(opcion) {
            case 1: registrar(nombres, cantidades, tiempos, recursos, &totalProductos); break;
            case 2: editar(nombres, cantidades, tiempos, recursos, totalProductos); break;
            case 3: eliminar(nombres, cantidades, tiempos, recursos, &totalProductos); break;
            case 4: calcular(cantidades, tiempos, recursos, totalProductos); break;
            case 5: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while(opcion != 5);
    return 0;
}

// --- LOGICA DE FUNCIONES ---
int buscar(char n[][MAX_CHARS], int total, char query[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(n[i], query) == 0) return i;
    }
    return -1;
}

void registrar(char n[][MAX_CHARS], int *c, float *t, float *r, int *total) {
    if (*total >= MAX_PROD) {
        printf("Limite maximo alcanzado.\n");
        return;
    }
    printf("Nombre: "); scanf("%s", n[*total]);
    printf("Cantidad: "); scanf("%d", &c[*total]);
    printf("Tiempo unitario: "); scanf("%f", &t[*total]);
    printf("Recurso unitario: "); scanf("%f", &r[*total]);
    (*total)++;
    printf("Producto registrado.\n");
}

void editar(char n[][MAX_CHARS], int *c, float *t, float *r, int total) {
    char query[MAX_CHARS];
    printf("Nombre a editar: "); scanf("%s", query);
    int idx = buscar(n, total, query);
    if (idx != -1) {
        printf("Nueva Cantidad: "); scanf("%d", &c[idx]);
        printf("Nuevo Tiempo: "); scanf("%f", &t[idx]);
        printf("Nuevo Recurso: "); scanf("%f", &r[idx]);
        printf("Actualizado.\n");
    } else {
        printf("No encontrado.\n");
    }
}

void eliminar(char n[][MAX_CHARS], int *c, float *t, float *r, int *total) {
    char query[MAX_CHARS];
    printf("Nombre a eliminar: "); scanf("%s", query);
    int idx = buscar(n, *total, query);
    if (idx != -1) {
        // Corrimiento de datos
        for (int i = idx; i < *total - 1; i++) {
            strcpy(n[i], n[i+1]);
            c[i] = c[i+1];
            t[i] = t[i+1];
            r[i] = r[i+1];
        }
        (*total)--;
        printf("Eliminado.\n");
    } else {
        printf("No encontrado.\n");
    }
}

void calcular(int *c, float *t, float *r, int total) {
    if (total == 0) { printf("Sin datos.\n"); return; }
    float tTotal = 0, rTotal = 0, tLimite, rLimite;
    printf("Tiempo disponible en fabrica: "); scanf("%f", &tLimite);
    printf("Recursos disponibles: "); scanf("%f", &rLimite);

    for (int i = 0; i < total; i++) {
        tTotal += c[i] * t[i];
        rTotal += c[i] * r[i];
    }
    
    printf("\nTiempo Requerido: %.2f | Disponible: %.2f\n", tTotal, tLimite);
    printf("Recurso Requerido: %.2f | Disponible: %.2f\n", rTotal, rLimite);
    if (tTotal <= tLimite && rTotal <= rLimite) printf("VIABLE\n");
    else printf("NO VIABLE\n");
}
