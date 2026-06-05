#include "fabrica.h"

int buscar(char n[][MAX_CHARS], int total, char query[]) {
    for (int i = 0; i < total; i++) {
        if (strcmp(n[i], query) == 0) return i;
    }
    return -1;
}

void registrar(char n[][MAX_CHARS], int *c, float *t, float *r, int *total) {
    if (*total >= MAX_PROD) { printf("Limite alcanzado.\n"); return; }
    printf("Nombre: "); scanf("%s", n[*total]);
    c[*total] = validar_int("Cantidad: ");
    t[*total] = validar_float("Tiempo: ");
    r[*total] = validar_float("Recurso: ");
    (*total)++;
}

void editar(char n[][MAX_CHARS], int *c, float *t, float *r, int total) {
    char query[MAX_CHARS];
    printf("Nombre a editar: "); scanf("%s", query);
    int idx = buscar(n, total, query);
    if (idx != -1) {
        c[idx] = validar_int("Nueva Cantidad: ");
        t[idx] = validar_float("Nuevo Tiempo: ");
        r[idx] = validar_float("Nuevo Recurso: ");
    } else printf("No encontrado.\n");
}

void eliminar(char n[][MAX_CHARS], int *c, float *t, float *r, int *total) {
    char query[MAX_CHARS];
    printf("Nombre a eliminar: "); scanf("%s", query);
    int idx = buscar(n, *total, query);
    if (idx != -1) {
        for (int i = idx; i < *total - 1; i++) {
            strcpy(n[i], n[i+1]);
            c[i] = c[i+1]; t[i] = t[i+1]; r[i] = r[i+1];
        }
        (*total)--;
    } else printf("No encontrado.\n");
}

void calcular(int *c, float *t, float *r, int total) {
    if (total == 0) { printf("Sin datos.\n"); return; }
    float tL = validar_float("Tiempo disp: "), rL = validar_float("Recurso disp: ");
    float tT = 0, rT = 0;
    for (int i = 0; i < total; i++) { tT += c[i] * t[i]; rT += c[i] * r[i]; }
    printf("Requerido: T:%.2f R:%.2f | %s\n", tT, rT, (tT <= tL && rT <= rL) ? "VIABLE" : "NO VIABLE");
}