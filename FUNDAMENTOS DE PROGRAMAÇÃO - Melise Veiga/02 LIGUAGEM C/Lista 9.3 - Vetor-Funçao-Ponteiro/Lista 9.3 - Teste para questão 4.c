#include<stdio.h>
#include<stdlib.h>

/* 4. Supor a declaração: int mat[4], *p, x; Quais expressões são válidas? Justifique:
a) p = mat + 1; b) p = mat++; c) p = ++mat; d) x = (*mat)++; */

int main ()
{
    int i, mat[4], *p, x;

    p = mat+1; //Colocar a alternativa nessa linha

    for (i=0; i<4; i++){
        mat[i] = rand() % 100;
        printf ("_%d_|",mat[i]);
    }

    printf ("\n\nValidacao: %d\n",*p); //Colocar o ponteiro P ou a variável X, dependendo da alternativa

    return 0;

}

#include<stdio.h>
#include<stdlib.h>

/* 4. Supor a declaração: int mat[4], *p, x; Quais expressões são válidas? Justifique:
a) p = mat + 1; b) p = mat++; c) p = ++mat; d) x = (*mat)++; */

int main ()
{
    int i, mat[4], *p, x;

    p = mat; //Colocar a alternativa nessa linha

    for (i=0; i<4; i++){
        mat[i] = rand() % 100;
        printf ("_%d_|",mat[i]);
    }

    x = (*mat)++;

    printf ("\n\nValidacao: %d\n",x); //Colocar o ponteiro P ou a variável X, dependendo da alternativa

    return 0;

}
