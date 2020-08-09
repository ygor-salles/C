#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Fa�a um algoritmo para calcular o valor de S, dado por: S = 1/N +2/(N-1) + 3/(N-2)
// + ... + (N-1)/2 + N/1, sendo N fornecido pelo usu�rio. Valide a entrada de dados.

int main ()
{
    int i, n, den;                          //i=vari�vel contadora; n=usu�rio vai digitar; den=vari�vel do denominador
    float s;                                //s=vari�vel da soma

    printf ("Digite o valor para N: ");
    scanf ("%d",&n);
    den = n-1;                              //inicializamos o denominador como n-1
    s = 1/(float)n;                         //inicializamos a soma com o primeiro termo da sequencia
    
    for(i=2; i<=n; i++) {                   //O contador partir� do 2� termo pois o primeiro termo da sequencia ja foi inicializado com a vari�vel den e s.
        s = s + i/(float)den--;             //Fazemos a soma, o denominar deve decrescer passo 1 a cada loop ap�s o 2� termo.
    }
    printf ("\n A soma S eh: %f\n",s);
    return 0;
}
