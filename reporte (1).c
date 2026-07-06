#include <stdio.h>
#include "reporte.h"
#include "estadisticas.h"

void guardarReporte(Zona zonas[], int n) {
    FILE *f = fopen("reporte.txt", "w");
    if(f == NULL) {
        printf("Error al crear archivo.\n");
        return;
    }
    fprintf(f, "REPORTE DE CONTAMINACION\n\n");
    for(int i=0; i<n; i++) {
        fprintf(f, "Zona: %s\n", zonas[i].nombreZona);
        fprintf(f, "Prediccion: %.2f\n", zonas[i].prediccion);
        fprintf(f, "Promedio CO2: %.2f\n", promedio(zonas[i].CO2, DIAS));
        fprintf(f, "Promedio NO2: %.2f\n", promedio(zonas[i].NO2, DIAS));
        fprintf(f, "Promedio PM2.5: %.2f\n", promedio(zonas[i].PM25, DIAS));
        fprintf(f, "Clima -> Temp: %.1f°C, Humedad: %.1f%%, Viento: %.1f km/h\n\n",
                zonas[i].temperatura[DIAS-1], zonas[i].humedad[DIAS-1], zonas[i].viento[DIAS-1]);
    }
    fclose(f);
    printf("Reporte guardado en 'reporte.txt'.\n");
}
