#include<stdio.h>
#include<math.h>

/* 9. Escreva um algoritmo para calcular e escrever a área de um triângulo, sendo dados a
sua base e a sua altura (Área = (base X altura) / 2) */

int main ()
{
    float base, altura, area;
    printf ("Digite o valor da base: ");
    scanf ("%f",&base);
    printf ("Digite o valor da altura: ");
    scanf ("%f",&altura);

    area = (base*altura)/2;
    printf ("\nO valor da area eh: %f\n",area);
    return 0;
}
