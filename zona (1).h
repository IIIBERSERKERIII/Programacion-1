#ifndef ZONA_H
#define ZONA_H

#define DIAS 30

typedef struct {
    char nombreZona[30];
    float CO2[DIAS];
    float NO2[DIAS];
    float PM25[DIAS];
    float temperatura[DIAS];
    float humedad[DIAS];
    float viento[DIAS];
    float prediccion;
} Zona;

void ingresarDatosDia(Zona *z, int dia);

#endif
