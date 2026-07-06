#include "estadisticas.h"

// Promedio simple
float promedio(float datos[], int n) {
    float suma = 0;
    for(int i=0; i<n; i++) suma += datos[i];
    return suma / n;
}

// Algoritmo de predicción explicado paso a paso
float prediccionConClima(Zona *z) {
    // Paso 1: promedio ponderado últimos 5 días de contaminantes
    int inicio = DIAS-5;
    float suma = 0, peso = 0;
    for(int i=inicio; i<DIAS; i++) {
        int w = (i - inicio + 1);
        float indice = (z->CO2[i] + z->NO2[i] + z->PM25[i]) / 3.0;
        suma += indice * w;
        peso += w;
    }
    float base = suma / peso;

    // Paso 2: ajuste por clima
    float f_temp = (z->temperatura[DIAS-1] > 25) ? 0.01 * (z->temperatura[DIAS-1] - 25) : 0;
    float f_hum = 0.005 * (z->humedad[DIAS-1] / 10.0);
    float f_viento = 0.02 * (z->viento[DIAS-1] / 5.0);

    // Paso 3: predicción final
    float prediccion = base * (1 + f_temp + f_hum - f_viento);
    return prediccion;
}
