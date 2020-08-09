#ifndef TAD_H
#define TAD_H

typedef struct complexo Complexo;

Complexo *criar(float a, float b, float c, float d);

void somar (float *x, float *y, Complexo *dados);

void subtrair (float *x, float *y, Complexo *dados);

void multiplicar (float *x, float *y, Complexo *dados);

void dividir (float *x, float *y, Complexo *dados);

void liberar (Complexo *dados);

#endif
