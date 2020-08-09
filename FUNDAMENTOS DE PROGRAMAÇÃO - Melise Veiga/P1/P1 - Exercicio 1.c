#include<stdio.h>

/* P1 - Exercicio 1 */

int main ()
{
    float salario, receber;
    printf ("Digite seu salario bruto: ");
    scanf ("%f",&salario);

    if ((salario<=0) || (salario>6000)){
        printf ("\nEntrada de dados invalida!\n");
    }
    else{
        if ((salario>0) && (salario<=1000)){
            receber = salario+100-(salario*0.07);
        }
        else if ((salario>1000) && (salario<2000)){
            receber = salario+75-(salario*0.07);
        }
        else if ((salario>=2000) && (salario<=3000)){
            receber = salario+50-(salario*0.07);
        }
        else{
            receber = salario+35-(salario*0.07);
        }
        printf ("\nO novo valor a receber eh: R$%.2f\n",receber);
    }
    return 0;
}
