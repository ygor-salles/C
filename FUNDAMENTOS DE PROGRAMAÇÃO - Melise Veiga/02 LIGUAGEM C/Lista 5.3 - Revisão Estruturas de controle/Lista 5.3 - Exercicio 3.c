#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Faça um algoritmo para calcular o valor de S, dado por: S = 1/N +2/(N-1) + 3/(N-2)
// + ... + (N-1)/2 + N/1, sendo N fornecido pelo usuário. Valide a entrada de dados.

int main ()
{
    int i, n, den;                          //i=variável contadora; n=usuário vai digitar; den=variável do denominador
    float s;                                //s=variável da soma

    printf ("Digite o valor para N: ");
    scanf ("%d",&n);
    den = n-1;                              //inicializamos o denominador como n-1
    s = 1/(float)n;                         //inicializamos a soma com o primeiro termo da sequencia
    
    for(i=2; i<=n; i++) {                   //O contador partirá do 2º termo pois o primeiro termo da sequencia ja foi inicializado com a variável den e s.
        s = s + i/(float)den--;             //Fazemos a soma, o denominar deve decrescer passo 1 a cada loop após o 2º termo.
    }
    printf ("\n A soma S eh: %f\n",s);
    return 0;
}
