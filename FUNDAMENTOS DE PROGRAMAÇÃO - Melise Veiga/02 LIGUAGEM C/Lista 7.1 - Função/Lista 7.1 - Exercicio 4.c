#include<stdio.h>
#include<math.h>

/* Faça uma função que recebe por parâmetro o raio de uma esfera e calcula o seu volume (v = 4/3.P .R3). */

float retorna (float raio)
{
    float volume;
    volume = (4/3)*3.14*raio;
    return volume;
}

int main ()
{
    float funcao, raio;
    printf ("Digite o raio: ");
    scanf ("%f",&raio);
    funcao = retorna (raio);
    printf ("\nO valor do Volume eh: %f\n",funcao);
}
