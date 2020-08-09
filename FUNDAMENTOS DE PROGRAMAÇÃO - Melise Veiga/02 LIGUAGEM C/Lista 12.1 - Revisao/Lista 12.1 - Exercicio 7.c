#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

/*7. Escrever um algoritmo que leia uma matriz de 23 linhas por 10 colunas. Esta matriz representa a popula��o dos 10 maiores munic�pios de cada estado brasileiro.
Em cada linha, as colunas est�o em ordem decrescente, com exce��o da primeira coluna, que sempre representa a capital. O algoritmo deve ter fun��es para:
a) Retornar o n�mero da linha correspondente ao estado de capital mais populosa;
b) Retornar a m�dia das popula��es das capitais do Brasil;
c) Imprimir os n�meros dos estados (n�mero da linha) e dos munic�pios (n�mero da coluna) que tem a popula��o maior que a capital. */

void funcaoA (int  mat[][10], int *linha);
void funcaoB (int  mat[][10], float *media);
void funcaoC (int  mat[][10]);

int main ()
{
    setlocale(LC_ALL, "Portuguese");
    int mat[23][10], i, j, x=70;

    printf ("    ");
    for (i=1; i<=10; i++)
        printf ("[%d]",i);
    printf ("\n");

    for (i=0; i<23; i++){
        printf ("[%d] ",i+1);
        for (j=0; j<10; j++){
            if (j == 0){
                mat[i][j] = x++;
                printf (" %d",mat[i][j]);
            }
            else{
                mat[i][j] = rand() % 100;
                printf (" %d",mat[i][j]);
            }
        }
        printf ("\n");
    }

    //fun��o A
    int linha;
    funcaoA (mat, &linha);
    printf ("\nO estado de numero %d � o que possui a capital mais populosa\n",linha);

    //fun��o B
    float media;
    funcaoB (mat, &media);
    printf ("\nA m�dia de popula��o das capitais �: %.1f\n",media);

    //fun��o C
    funcaoC (mat);

    return 0;
}

void funcaoA (int  mat[][10], int *linha)
{
    int i, j, maior;
    maior = mat[0][0];
    for (i=0; i<23; i++){
        for (j=0; j<10; j++){
            if (j==0){
                if (mat[i][0] > maior){
                    maior = mat[i][0];
                    *linha = i+1;
                    break;
                }
            }
        }
    }

    return ;
}

void funcaoB (int  mat[][10], float *media)
{
    int i, j, soma=0;
    for (i=0; i<23; i++){
        for (j=0; j<10; j++){
            if (j==0){
                soma = soma + mat[i][j];
                break;
            }
        }
    }
    *media = (float)soma/23;

    return ;
}

void funcaoC (int  mat[][10])
{
    int i, j;

    printf ("\nAs cidades que s�o maiores que as capitas s�o: \n");
    for (i=0; i<23; i++){
        for (j=0; j<10; j++){
            if (j>0){
                if (mat[i][j] > mat[i][0]){
                    printf ("\nLinha[%d] Coluna[%d]",i+1, j+1);
                }
            }
        }
    }
    printf ("\n");

    return ;
}
