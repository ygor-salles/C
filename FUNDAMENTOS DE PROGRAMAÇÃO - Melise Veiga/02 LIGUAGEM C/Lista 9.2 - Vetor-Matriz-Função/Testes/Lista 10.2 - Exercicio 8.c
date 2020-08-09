#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>

/* 8. Uma empresa possui uma relação de N funcionários (N < 100), cada um contendo: código (valor inteiro), idade e salário. Faça um programa para:
a. Elabore uma função que leia as informações dos N funcionários, considerando que o número máximo de funcionário é 100 e que o código 0 significa que não existem mais dados.
b. Elabore uma função que retorne o código do funcionário mais velho.
c. Elabore uma função que imprima o código e a idade dos funcionários que ganham mais que a média dos salários. */

void funcaoA (int n, int c[], int id[], float sal[], float media);
void funcaoB (int n, int c[], int id[], float sal[], float media);
void funcaoC (int n, int c[], int id[], float sal[], float media);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int cod[100], idade[100], n;
    float salario[100], media;

    printf ("Digite a quantidade de funcionários: ");
    scanf ("%d",&n);

    funcaoA (n, cod, idade, salario, media);


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

    funcaoB (n, c, id, sal, media);
    return ;
}

void funcaoB (int n, int c[], int id[], float sal[], float media)
{
    int i, maior, maiorc;
    maior = id[0];
    maiorc = c[0];
    for (i=0; i<n; i++){
        if (id[i]>maior){
            maior = id[i];
            maiorc = c[i];
        }
    }
    printf ("\nO código do funcionário mais velho é: %d\n",maiorc);

    funcaoC (n, c, id, sal, media);
    return ;
}

void funcaoC (int n, int c[], int id[], float sal[], float media)
{
    int i, cod[n], idad[n], k=0;
    for (i=0; i<n; i++){
        if (sal[i]>(media/n)){
            cod[k] = c[i];
            idad[k] = id[i];
            k++;
        }
    }

    printf ("\nOs funcionários que ganham acima da média são: ");
    printf ("\n Codigo | Idade ");
    for (i=0; i<k; i++){
    printf ("\n    %d      %d  ",cod[i], idad[i]);
    }
    printf ("\n");

    return ;
}


