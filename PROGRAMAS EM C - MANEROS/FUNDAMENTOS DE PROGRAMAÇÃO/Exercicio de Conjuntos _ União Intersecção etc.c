#include<stdio.h>
#include<stdlib.h>

/* Faça um programa que preencha dois vetores, X e Y, com dez números inteiros cada. Calcule e mostre
os seguintes vetores resultantes:
1° Uniao de X com Y (Todos elementos de X e os elementos de Y que não estejam em X);
2° A diferença de X e Y (todos elementos de X que não existam em Y);
3° A soma entre X e Y (soma de cada elemento de X com o elemento da mesma posição em Y);
4° Produto entre X e Y (multiplicação de cada elemento de X com o elemento da mesma posição em Y);
5° Interceção (apenas os elementos que aparecem nos dois vetores); */

int main ()
{
    int x[10], y[10], i, j, uniao[20], soma[10], diferenca[10], produto[10], intercecao[20], semafaro, u=10, d=0, t=0;

    printf ("Vetor de X\n");
    for (i=0; i<10; i++){
        printf("Digite o %d num:",i);
        scanf ("%d",&x[i]);
    }
    printf ("\nVetor de Y\n");
    for (i=0; i<10; i++){
        printf("Digite o %d num:",i);
        scanf ("%d",&y[i]);
    }

    for (i=0; i<10; i++){
    uniao[i] = x[i];
    soma[i] = x[i] + y[i];
    produto[i] = x[i] * y[i];
    }

    for (i=0; i<10; i++){
        semafaro=0;
        for (j=0; j<10; j++){
            if(y[i] == x[j]){
                semafaro=1;
                break;
            }
        }
        if (semafaro == 0){
            uniao[u] = y[i];
            u++;
        }
    }


    for (i=0; i<10; i++){
        for (j=0; j<10; j++){
            semafaro=0;
            if (x[i] == y[j]){
                semafaro=1;
                break;
            }
        }
        if (semafaro == 0){
            diferenca[d] = x[i];
            d++;
        }else{
            intercecao[t] = x[i];
            t++;
        }
    }

    printf ("\nElemento da uniao\n");
    for (i=0; i<u; i++){
        printf (" %d",uniao[i]);
    }

    if (d>0){
        printf ("\n\nElemento da diferenca\n");
        for (i=0; i<d; i++){
            printf (" %d",diferenca[i]);
        }
    }

    printf ("\n\nElemento da Soma\n");
    for (i=0; i<10; i++){
        printf (" %d",soma[i]);
    }

    printf ("\n\nElemento do produto\n");
    for (i=0; i<10; i++){
        printf (" %d",produto[i]);
    }

    if (t>0){
        printf ("\n\nElemento da intercecao\n");
        for (i=0; i<t; i++){
            printf (" %d",intercecao[i]);
        }
    }
    printf ("\n");

    return 0;
}
