#include<stdio.h>
#include<math.h>

/* 10. Dado um número inteiro positivo de 3 algarismos, inverter a ordem de seus
algarismos. Os três algarismos do número dado são diferentes de zero. */

int main ()
{
    int num, un, dez, cent;
    printf ("Digite num: ");
    scanf ("%d",&num);

    cent = num/100;
    dez = (num%100)/10;
    un = (num%100)%10;

    printf ("\n%d%d%d\n",un, dez, cent);

    return 0;
}
