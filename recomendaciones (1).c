#include <stdio.h>
#include "recomendaciones.h"

// Clasificación en función del grado de contaminación
void recomendaciones(float nivel) {
    if(nivel < 25) {
        printf("  → Nivel BAJO: condiciones seguras.\n");
        printf("    Recomendación: Mantener actividades normales.\n");
        printf("    Recomendación: Continuar con monitoreo rutinario.\n");
    } else if(nivel >= 25 && nivel <= 50) {
        printf("  → Nivel MEDIO: precaución necesaria.\n");
        printf("    Recomendación: Reducir actividades físicas intensas al aire libre.\n");
        printf("    Recomendación: Promover uso de transporte público.\n");
        printf("    Recomendación: Mantener vigilancia constante de los niveles.\n");
    } else if(nivel > 50 && nivel <= 75) {
        printf("  → Nivel ALTO: alerta ambiental.\n");
        printf("    Recomendación: Limitar circulación vehicular.\n");
        printf("    Recomendación: Usar mascarilla en exteriores.\n");
        printf("    Recomendación: Suspender actividades escolares al aire libre.\n");
    } else {
        printf("  → Nivel CRÍTICO: riesgo ALTO para la salud.\n");
        printf("    Recomendación: Declarar emergencia ambiental.\n");
        printf("    Recomendación: Evitar completamente la exposición al aire libre.\n");
        printf("    Recomendación: Implementar medidas de control inmediato.\n");
    }
}

