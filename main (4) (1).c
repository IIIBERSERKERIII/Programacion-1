#include <stdio.h>
#include "zona.h"
#include "estadisticas.h"
#include "recomendaciones.h"
#include "reporte.h"

#define ZONAS 5  

int main() {
    Zona zonas[ZONAS] = {
        {"Centro"},
        {"Norte"},
        {"Sur"},
        {"Este"},
        {"Oeste"}
    };

    // Ingresar datos del día 30 para cada zona
    for(int i=0; i<ZONAS; i++) {
        ingresarDatosDia(&zonas[i], DIAS-1);
        zonas[i].prediccion = prediccionConClima(&zonas[i]);

        printf("\nZona: %s\n", zonas[i].nombreZona);

        // Mostrar los datos ingresados del día 30
        printf("  Día 30 -> CO2: %.2f, NO2: %.2f, PM2.5: %.2f\n",
               zonas[i].CO2[DIAS-1], zonas[i].NO2[DIAS-1], zonas[i].PM25[DIAS-1]);
        printf("           Temp: %.1f°C, Humedad: %.1f%%, Viento: %.1f km/h\n",
               zonas[i].temperatura[DIAS-1], zonas[i].humedad[DIAS-1], zonas[i].viento[DIAS-1]);

        // Mostrar predicción y recomendaciones
        printf("  Prediccion: %.2f\n", zonas[i].prediccion);
        recomendaciones(zonas[i].prediccion);
    }

    guardarReporte(zonas, ZONAS);
    return 0;
}

