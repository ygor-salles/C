#include<stdio.h>
#include<string.h>

/* Converter um numero de 0-999 inclusive em uma string correspondente ao valor de entrada */

int main ()
{
    int num, c, d, u;
    char centena[11], dezena[11], unidade[11];

    printf ("\nDigite um valor inteiro de 0-999: ");
    scanf ("%d",&num);

    if (num<0 || num>999){
        printf("\nNumero invalido!\n");
        return 0;
    }

    //processamento de 3 dígitos
    c = num/100;
    d = (num%100)/10;
    u = (num%100)%10;


    //declaração de inteiros para string
    if (c==0)
        strcpy(centena," ");
    if (d==0)
        strcpy(dezena," ");
    if (u==0)
        strcpy(unidade,"zero");

    if (c==1)
        strcpy(centena,"cento");
    if (u==1)
        strcpy(unidade,"um");

    if (c==2)
        strcpy(centena,"duzentos");
    if (d==2)
        strcpy(dezena,"vinte");
    if (u==2)
        strcpy(unidade,"dois");

    if (c==3)
        strcpy(centena,"trezentos");
    if (d==3)
        strcpy(dezena,"trinta");
    if (u==3)
        strcpy(unidade,"tres");

    if (c==4)
        strcpy(centena,"quatrocentos");
    if (d==4)
        strcpy(dezena,"quarenta");
    if (u==4)
        strcpy(unidade,"quatro");

    if (c==5)
        strcpy(centena,"quinhentos");
    if (d==5)
        strcpy(dezena,"cinquenta");
    if (u==5)
        strcpy(unidade,"cinco");

    if (c==6)
        strcpy(centena,"seiscentos");
    if (d==6)
        strcpy(dezena,"sescenta");
    if (u==6)
        strcpy(unidade,"seis");

    if (c==7)
        strcpy(centena,"setecentos");
    if (d==7)
        strcpy(dezena,"setenta");
    if (u==7)
        strcpy(unidade,"sete");

    if (c==8)
        strcpy(centena,"oitocentos");
    if (d==8)
        strcpy(dezena,"oitenta");
    if (u==8)
        strcpy(unidade,"oito");

    if (c==9)
        strcpy(centena,"novecentos");
    if (d==9)
        strcpy(dezena,"noventa");
    if (u==9)
        strcpy(unidade,"nove");

    if (d==1){
        if (u==0)
            strcpy(dezena,"dez");
        if (u==1)
            strcpy(dezena,"onze");
        if (u==2)
            strcpy(dezena,"doze");
        if (u==3)
            strcpy(dezena,"treze");
        if (u==4)
            strcpy(dezena,"quatorze");
        if (u==5)
            strcpy(dezena,"quinze");
        if (u==6)
            strcpy(dezena,"dezesseis");
        if (u==7)
            strcpy(dezena,"dezessete");
        if (u==8)
            strcpy(dezena,"dezoito");
        if (u==9)
            strcpy(dezena,"dezenove");
    }

    //impressão:
    if (c==0){
        if (d == 0)
            printf ("\n %s\n",unidade);
        else if (d == 1 || u==0)
            printf("\n %s\n",dezena);
        else
            printf("\n %s e %s\n",dezena, unidade);
    }

    else{
        if (d==0){
            if (u==0){
                if (c==1)
                    printf("\n cem\n");
                else
                    printf("\n %s\n",centena);
            }
            else
                printf("\n %s e %s\n",centena, unidade);
        }
        else if (u==0 || d==1)
            printf ("\n %s e %s\n", centena, dezena);
        else
            printf ("\n %s e %s e %s\n", centena, dezena, unidade);
    }

    return 0;
}
