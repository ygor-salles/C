#include<stdio.h>
#include<locale.h>

/* 7. Escreva um programa em C cujo objetivo é receber 3 valores reais (X, Y e Z) e
descobrir se esses valores formam um triângulo e, se sim, identificar o tipo do triângulo
formado. O programa deverá ter duas funções: A primeira identifica se os valores
informados pelo usuário formam um triângulo. Para tanto, é necessário que a seguinte
propriedade seja satisfeita: o comprimento de cada lado de um triângulo é menor do que
a soma do comprimento dos outros dois lados. A segunda função visa identificar o tipo
do triângulo formado, observando as seguintes definições:
a. Triângulo Equilátero: os comprimentos dos 3 lados são iguais.
b. Triângulo Isósceles: os comprimentos de 2 lados são iguais.
c. Triângulo Escaleno: os comprimentos dos 3 lados são diferentes. */

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
            printf ("\nTriângulo Equilátero.\n");
        else if (x==y || x==z || y==z)
            printf ("\nTriângulo Isóceles.\n");
        else if (x!=y && x!=z && y!=z)
            printf ("\nTriângulo Escaleno.\n");
    }
    else
        printf ("\nOs valores informados não formam um triângulo!\n");

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
