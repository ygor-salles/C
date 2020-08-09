#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* Parte Lógica */

double cosseno(float x, int n);
double seno(float x, int n);

int main ()
{
    double soma_cosseno, soma_seno, tangente;
    float x;
    int n;
    printf ("Digite o valor de X: ");
    scanf ("%f",&x);
    printf ("Digite a quantidade de termos da serie: ");
    scanf ("%d",&n);

    soma_cosseno = cosseno(x, n);
    printf ("\n A soma cosseno eh de: %.8f\n",soma_cosseno);

    soma_seno = seno(x, n);
    printf ("\n A soma seno eh de: %.8f\n",soma_seno);

    if (soma_cosseno != 0){
        tangente = soma_seno/soma_cosseno;
        printf ("\n\nA tagente eh: %.8f\n",tangente);
    }
    else{
        printf ("\n\nA soma cosseno deu zero, erro de calculo para a tangente!\n");
    }

    return 0;
}

double cosseno(float x, int n)
{
    int fat, i, expo=2, fatorial;
    float soma_cosseno=1;

    if (n>=2){
        for (i=2; i<=n; i++){
            fat=1;
            for(fatorial=expo; fatorial>=1; fatorial--)
                fat=fatorial*fat;

                if (i%2==0)
                    soma_cosseno= soma_cosseno-((pow(x,expo))/(float)fat);
                else
                    soma_cosseno= soma_cosseno+((pow(x,expo))/(float)fat);

                expo=expo+2;
        }
    }
    return soma_cosseno;
}

double seno(float x, int n)
{
    int fat, i, expo=3, fatorial;
    float soma_seno=x;

    if (n>=2){
        for (i=2; i<=n; i++){
            fat=1;
            for(fatorial=expo; fatorial>=1; fatorial--)
                fat=fatorial*fat;

            if (i%2==0)
                soma_seno= soma_seno-((pow(x,expo))/(float)fat);
            else
                soma_seno= soma_seno+((pow(x,expo))/(float)fat);

            expo=expo+2;
        }
    }
    return soma_seno;
}
