#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Faça um programa que calcule e mostre os numeros primos entre 1 a 20. */

int main ()
{
    int primo, i, c;
    for (i=1; i<=20; i++){
        primo=0;
        for (c=1; c<=i; c++){
            if (i % c == 0){
                primo++;
            }
        }
    if (primo==2){
        printf ("%d",i);
    }
    }
}
