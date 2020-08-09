#include<stdio.h>

/* P1 - Exercicio 3 */

int main ()
{
    int sup, inf, i, s=0;

    printf ("Digite o limite inferior: ");
    scanf ("%d",&inf);
    printf ("Digite o limite superior: ");
    scanf ("%d",&sup);

    if (inf>sup){
        printf ("\nEntrada de dados invalidos!\n\n");
    }
    else{
        for (i=inf; i<=sup; i++){
            if (i%2!=0){
                s = s+i;
            }
        }
        printf ("\nA soma dos impares no intervalo fechado eh: %d\n\n",s);
    }
    return 0;
}
