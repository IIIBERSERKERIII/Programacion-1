#ifndef FABRICA_H
#define FABRICA_H

#include <stdio.h>
#include <string.h>

#define MAX_PROD 5
#define MAX_CHARS 50

int buscar(char n[][MAX_CHARS], int total, char query[]);
void registrar(char n[][MAX_CHARS], int *c, float *t, float *r, int *total);
void editar(char n[][MAX_CHARS], int *c, float *t, float *r, int total);
void eliminar(char n[][MAX_CHARS], int *c, float *t, float *r, int *total);
void calcular(int *c, float *t, float *r, int total);

#endif