#include <stdio.h>
#include "zona.h"

// Permite ingresar datos de contaminantes y clima para un día específico
void ingresarDatosDia(Zona *z, int dia) {
    printf("Ingresar datos para zona %s (día %d):\n", z->nombreZona, dia+1);
    printf("  CO2: "); scanf("%f", &z->CO2[dia]);
    printf("  NO2: "); scanf("%f", &z->NO2[dia]);
    printf("  PM2.5: "); scanf("%f", &z->PM25[dia]);
    printf("  Temperatura (°C): "); scanf("%f", &z->temperatura[dia]);
    printf("  Humedad (%%): "); scanf("%f", &z->humedad[dia]);
    printf("  Viento (km/h): "); scanf("%f", &z->viento[dia]);
}
