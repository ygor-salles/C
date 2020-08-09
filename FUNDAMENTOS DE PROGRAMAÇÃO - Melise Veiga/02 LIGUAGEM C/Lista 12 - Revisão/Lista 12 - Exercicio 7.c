#include<stdio.h>
#include<locale.h>

/* 7. Escreva um programa em C cujo objetivo � receber 3 valores reais (X, Y e Z) e
descobrir se esses valores formam um tri�ngulo e, se sim, identificar o tipo do tri�ngulo
formado. O programa dever� ter duas fun��es: A primeira identifica se os valores
informados pelo usu�rio formam um tri�ngulo. Para tanto, � necess�rio que a seguinte
propriedade seja satisfeita: o comprimento de cada lado de um tri�ngulo � menor do que
a soma do comprimento dos outros dois lados. A segunda fun��o visa identificar o tipo
do tri�ngulo formado, observando as seguintes defini��es:
a. Tri�ngulo Equil�tero: os comprimentos dos 3 lados s�o iguais.
b. Tri�ngulo Is�sceles: os comprimentos de 2 lados s�o iguais.
c. Tri�ngulo Escaleno: os comprimentos dos 3 lados s�o diferentes. */

int teste_triangulo(float x, float y, float z)
{
    if ((x < y+z) && (y < x+z) && (z < x+y))
        return 1;
    else
        return -1;
}

void tipo_triangulo(float x, float y, float z)
{
    teste_triangulo(x, y, z);

    if (teste_triangulo(x, y, z) == 1){
        if (x==y && y==z)
            printf ("\nTri�ngulo Equil�tero.\n");
        else if (x==y || x==z || y==z)
            printf ("\nTri�ngulo Is�celes.\n");
        else if (x!=y && x!=z && y!=z)
            printf ("\nTri�ngulo Escaleno.\n");
    }
    else
        printf ("\nOs valores informados n�o formam um tri�ngulo!\n");

    return;
}

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    float x, y, z;

    printf ("Digite os valores de X, Y e Z respectivamente: \n");
    scanf("%f %f %f",&x, &y, &z);

    tipo_triangulo(x, y, z);

    return 0;
}
