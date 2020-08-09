#include<stdio.h>
#include<stdlib.h>

/*4. Escreva uma fun��o que receba dois vetores de tamanho m�ximo 10 e retorne um terceiro vetor cujos elementos
s�o a soma dos elementos dos dois vetores. Considere que os dois vetores recebidos ter�o o mesmo n�mero de elementos ocupados.
Use a fun��o no programa principal para preenche um vetor a partir de outros dois vetores de n�meros digitados pelo usu�rio que dever�o possuir 10 elementos */

void soma (int va[], int vb[], int vc[], int i, int n)
{
    for (i=0; i<n; i++){
        vc[i] = va[i] + vb[i];
    }
    return ;
}

int main ()
{
    int va[10], vb[10], vc[10], i, n, nb;

    printf ("Digite o tamanho do vetor A <= 10: ");
    scanf ("%d",&n);
    printf ("Digite o tamanho do vetor B <= 10: ");
    scanf ("%d",&nb);

    if (n == nb && n>0 && n<=10){
        printf ("\nVetor A\n");
        for (i=0; i<n; i++){
            printf ("Digite num: ");
            scanf ("%d",&va[i]);
        }
        printf ("\nVetor B\n");
        for (i=0; i<n; i++){
            printf ("Digite num: ");
            scanf ("%d",&vb[i]);
        }

        soma (va, vb, vc, i, n);
        printf ("\nA soma dos dois vetores sao: \n");
        for (i=0; i<n; i++){
            printf ("%d ",vc[i]);
        }
        printf ("\n");

    }
    else{
        printf ("\nEntrada de dados invalidos!\n");
    }
    return 0;
}
