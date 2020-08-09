#include<stdio.h>
#include<stdlib.h>

/* Faça uma função que receba, por parâmetro, a altura (alt)
e o sexo de uma pessoa e retorna o seu peso ideal.
Para homens, calcular o peso ideal usando a fórmula peso ideal = 72.7 x alt - 58 
e, para mulheres, peso ideal = 62.1 x alt - 44.7. 
Utilize esta função no programa principal para retornar o peso ideal de uma lista de pessoas.
O programa deve ser finalizado quando a altura digitada for menor ou igual a 0. */

float imc (float h, char s)
{
    if (s == 'm' || s == 'M'){
        return 72.7*h-58;
    }
    else if (s == 'f' || s == 'F'){
        return 62.1*h-44.7;
    }
}

int main ()
{
    float altura;
    char sexo;
    float funcao;

    do{
        printf ("\nDigite a sua altura: ");
        scanf ("%f",&altura);
        printf ("Digite o seu sexo: ");
        scanf (" %c",&sexo);
        funcao = imc (altura, sexo);
        printf ("O peso ideal eh: %.2f\n",funcao);
    } while (altura>0);
    return 0;
}
