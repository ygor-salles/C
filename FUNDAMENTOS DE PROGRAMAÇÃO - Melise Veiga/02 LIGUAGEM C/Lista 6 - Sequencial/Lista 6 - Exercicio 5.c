#include<stdio.h>
#include<math.h>

/* 5. Construa um algoritmo que, tendo como dados de entrada dois pontos quaisquer do
plano, P(x1,y1) e Q(x2, y2), imprima a distância entre eles. */

int main ()
{
    float x1, x2, y1, y2, distancia;

    printf ("Digite o valor de x1: ");
    scanf ("%f",&x1);
    printf ("Digite o valor de x2: ");
    scanf ("%f",&x2);
    printf ("Digite o valor de y1: ");
    scanf ("%f",&y1);
    printf ("Digite o valor de y1: ");
    scanf ("%f",&y2);

    distancia = pow(((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)),(1/2));

    printf ("\nA distancia eh: %f\n",distancia);

    return 0;
}
