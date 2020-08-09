#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<conio.h>

/* 8. Uma empresa possui uma rela��o de N funcion�rios (N < 100), cada um contendo: c�digo (valor inteiro), idade e sal�rio. Fa�a um programa para:
a. Elabore uma fun��o que leia as informa��es dos N funcion�rios, considerando que o n�mero m�ximo de funcion�rio � 100 e que o c�digo 0 significa que n�o existem mais dados.
b. Elabore uma fun��o que retorne o c�digo do funcion�rio mais velho.
c. Elabore uma fun��o que imprima o c�digo e a idade dos funcion�rios que ganham mais que a m�dia dos sal�rios. */

void funcaoA (int n, int c[], int id[], float sal[], float media);
void funcaoC (int n, int c[], int id[], float sal[], float media);
int funcaoB (int nn, int c[], int id[]);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int c[100], id[100], n, velho;
    float sal[100], media=0;

    printf ("Digite a quantidade de funcion�rios: ");
    scanf ("%d",&n);

    funcaoA (n, c, id, sal, media);

    velho = funcaoB (n, c, id);
    printf ("\nO c�digo do funcion�rio mais velho �: %d\n",velho);

    return 0;
}

 void funcaoA (int n, int c[], int id[], float sal[], float media)
 {
    int i;
    media = 0;
    for (i=0; i<n; i++){
        printf ("Digite o codigo: ");
        scanf ("%d",&c[i]);
        if (c[i]== 0){
            break;
        }
        printf ("Digite a idade: ");
        scanf ("%d",&id[i]);
        printf ("Digite o salario: ");
        scanf ("%f",&sal[i]);
        media = media+sal[i];
        printf ("\n");
    }
    funcaoC (n, c, id, sal, media);
    return ;
}

void funcaoC (int n, int c[], int id[], float sal[], float media)
{
    int i, k=0, codf[100], idad[1000];
    for (i=0; i<n; i++){
        if (sal[i]>(media/n)){
            codf[k] = c[i];
            idad[k] = id[i];
            k++;
        }
    }
    printf ("\nOs funcion�rios que ganham acima da m�dia s�o: ");
    printf ("\n Codigo | Idade ");
    for (i=0; i<k; i++){
    printf ("\n    %d      %d  ",codf[i], idad[i]);
    }
    printf ("\n");
    return ;
}

int funcaoB (int nn, int c[], int id[])
{
    int i, maior, maiorc;
    maior = id[0];
    maiorc = c[0];
    for (i=0; i<nn; i++){
        if (id[i]>maior){
            maior = id[i];
            maiorc = c[i];
        }
    }
    return maiorc;
}




