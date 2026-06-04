#include "fabrica.h"

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
    printf("Nombre: "); 
    scanf("%s", n[*total]);
    printf("Cantidad: "); 
    scanf("%d", &c[*total]);
    printf("Tiempo unitario: "); 
    scanf("%f", &t[*total]);
    printf("Recurso unitario: "); 
    scanf("%f", &r[*total]);
    
    (*total)++;
    printf("Producto registrado.\n");
}

void editar(char n[][MAX_CHARS], int *c, float *t, float *r, int total) {
    char query[MAX_CHARS];
    printf("Nombre a editar: "); 
    scanf("%s", query);
    
    int idx = buscar(n, total, query);
    
    if (idx != -1) {
        printf("Nueva Cantidad: "); 
        scanf("%d", &c[idx]);
        printf("Nuevo Tiempo: "); 
        scanf("%f", &t[idx]);
        printf("Nuevo Recurso: "); 
        scanf("%f", &r[idx]);
        printf("Actualizado.\n");
    } else {
        printf("No encontrado.\n");
    }
}

void eliminar(char n[][MAX_CHARS], int *c, float *t, float *r, int *total) {
    char query[MAX_CHARS];
    printf("Nombre a eliminar: "); 
    scanf("%s", query);
    
    int idx = buscar(n, *total, query);
    
    if (idx != -1) {
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
    if (total == 0) { 
        printf("Sin datos para calcular.\n"); 
        return; 
    }
    
    float tTotal = 0, rTotal = 0, tLimite, rLimite;
    printf("Tiempo disponible en fabrica: "); 
    scanf("%f", &tLimite);
    printf("Recursos disponibles: "); 
    scanf("%f", &rLimite);

    for (int i = 0; i < total; i++) {
        tTotal += c[i] * t[i];
        rTotal += c[i] * r[i];
    }
    
    printf("\nTiempo Requerido: %.2f | Disponible: %.2f\n", tTotal, tLimite);
    printf("Recurso Requerido: %.2f | Disponible: %.2f\n", rTotal, rLimite);
    
    if (tTotal <= tLimite && rTotal <= rLimite) {
        printf(">>> RESULTADO: VIABLE <<<\n");
    } else {
        printf(">>> RESULTADO: NO VIABLE <<<\n");
    }
}