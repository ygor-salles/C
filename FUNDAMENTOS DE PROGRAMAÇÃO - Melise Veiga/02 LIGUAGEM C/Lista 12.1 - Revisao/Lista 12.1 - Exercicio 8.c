#include<stdio.h>
#include<stdlib.h>

/*8. Elabore um programa que preencha uma matriz com no máximo 50 linhas e 5 colunas,
onde cada linha contém os dados de um aluno da escola e cada coluna:
coluna 1 - número do aluno, coluna 2 - nota do aluno no 1o. bimestre, coluna 3 - nota do aluno no 2o. bimestre,
coluna 4 - nota do aluno no 3o. bimestre, coluna 5 - nota do aluno no 4o. bimestre. Crie funções para:
i. Calcular a média anual de cada aluno e retornar um vetor contendo estas médias;
ii. Dado o número do bimestre, retornar a média das notas;
iii. Dado o número do aluno, retornar a maior nota;
iv. Dado o número do aluno, retornar a média;
v. Dado o número do bimestre, retornar a quantidade de notas menores que 5. */

void anual (int mat[][5], float med[]);
void bimestre (int mat[][5], float *med_bim, int bim);
void maior_nota (int mat[][5], int numero, int *pnota, int *plinha);
void media_aluno (int mat[][5], int numero, float *pmed_aluno, int linha);
void bim_menorq5 (int mat[][5], int bim, int *pqtd);

int main ()
{
    int matriz[50][5];
    int i, j, k=0;

    for (i=0; i<50; i++){
        printf ("Digite seus dados (Numero / N1 / N2 / N3 / N4): ");
        for (j=0; j<5; j++){
            if (j == 0){
                matriz[i][j] = ++k;
                printf (" %d",matriz[i][j]);
            }else{
                matriz[i][j] = rand() % 100;
                printf (" %d",matriz[i][j]);
            }
        }
        printf ("\n");
    }
    printf ("\n");

    //funçaõ i
    float media[50];
    anual (matriz, media);
    for (i=0; i<50; i++){
        printf ("Media aluno %d eh: %.2f\n",matriz[i][0], media[i]/4);
    }

    //função ii
    float media_bim;
    int bim;
    printf ("\nDigite o numero do bimestre: ");
    scanf ("%d",&bim);
    if (bim>0 && bim<=4){
        bimestre (matriz, &media_bim, bim);
        printf ("A media do bimestre eh: %.2f\n",media_bim/50);
    }
    else{
        printf (" Valor invalido para bimestre!\n");
    }

    //função iii
    int numero, nota;
    int linha;
    printf ("\nDigite o numero do aluno: ");
    scanf ("%d",&numero);
    maior_nota(matriz, numero, &nota, &linha);
    printf ("A maior nota do aluno %d eh: %d\n",numero, nota);

    //função iv
    float med_aluno=0;
    media_aluno (matriz, numero, &med_aluno, linha);
    printf ("A media do aluno %d eh: %.2f\n",numero, med_aluno);

    //funcao v
    int qtd=0;
    printf ("\nDigite o numero do bimestre: ");
    scanf ("%d",&bim);
    bim_menorq5 (matriz, bim, &qtd);
    printf ("A quantidade de notas menores que 5, no bimestre [%d] eh: %d\n",bim, qtd);

    return 0;
}

void anual (int mat[][5], float med[])
{
    int i, j;
    for (i=0; i<50; i++){
        med[i] = 0;
        for (j=1; j<5; j++){
            med[i] = med[i] + mat[i][j];
        }
    }
    return ;
}

void bimestre (int mat[][5], float *med_bim, int bim)
{
    int i, j;
    *med_bim = 0;
    for (i=0; i<50; i++)
        for (j=0; j<5; j++)
            if (j == bim)
                *med_bim = *med_bim + mat[i][j];

    return ;
}

void maior_nota (int mat[][5], int numero, int *pnota, int *plinha)
{
    int i, j;
    for (i=0; i<50; i++)
        for (j=0; j<5; j++)
            if (j==0 && numero == mat[i][j])
                *plinha = i;

    *pnota = mat[*plinha][1];
    for (i=0; i<50; i++)
        if (i==*plinha)
            for (j=1; j<5; j++)
                if (j>0)
                    if (mat[i][j]>*pnota)
                        *pnota = mat[i][j];

    return ;
}

void media_aluno (int mat[][5], int numero, float *pmed_aluno, int linha)
{
    int i, j;
    for (i=0; i<50; i++)
        if (i==linha)
            for (j=0; j<5; j++)
                if (j>0)
                    *pmed_aluno = *pmed_aluno + mat[i][j];

    *pmed_aluno = *pmed_aluno/4;
    
    return ;
}

void bim_menorq5 (int mat[][5], int bim, int *pqtd)
{
    int i, j;
    for (i=0; i<50; i++)
        for (j=0; j<5; j++)
            if (j == bim)
                if (mat[i][j]<5)
                    ++(*pqtd);

    return ;
}
