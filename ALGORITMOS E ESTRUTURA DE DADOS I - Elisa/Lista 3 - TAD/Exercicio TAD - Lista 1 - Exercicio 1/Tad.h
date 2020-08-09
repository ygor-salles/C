#ifndef TAD_H
#define TAD_H

typedef struct habitantes Habitantes;

Habitantes *aloca(int n);

void funcaoA (int n, Habitantes *h);

void funcaoB (int n, Habitantes *h, float *media);

int funcaoC (int n, Habitantes *h);

void funcaoD (int n, Habitantes *h, int *individuo);

void funcaoE (int n, Habitantes *h, int **mat);

#endif
