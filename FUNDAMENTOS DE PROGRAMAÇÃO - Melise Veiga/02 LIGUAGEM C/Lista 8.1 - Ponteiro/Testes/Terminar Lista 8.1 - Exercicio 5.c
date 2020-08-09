#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

/* Faça um programa que imprima invertidos os nomes dos algarismos de um número
inteiro de três dígitos. Use a sua função no programa principal. Não é necessário validar
a entrada do número. Ex: 234 saída: quatro três dois. */

void algarismo (int x, int *pc, int *pd, int *pu)
{
    char str[0]="Zero"; str[1]="Um"; str[2]="Dois"; str[3]="Tres"; str[4]="Quatro";
    str[5]="Cinco"; str[6]="Seis"; str[7]="Sete"; str[8]="Oito"; str[9]="Nove";
    
    *pc = x/100;
    *pd = (x%100)/10;
    *pu = (x%100)%10;

    if ((*pc==0) || (*pd==0) || (*pu==0)) {
        str[0];
    }
        if ((*pc==1) || (*pd==1) || (*pu==1)) {
            str[1];
        }
            if ((*pc==2) || (*pd==2) || (*pu==2)) {
                str[2];
            }
                if ((*pc==3) || (*pd==3) || (*pu==3)) {
                    str[3];
                }
                    if ((*pc==4) || (*pd==4) || (*pu==4)) {
                        str[4];
                    }
                        if ((*pc==5) || (*pd==5) || (*pu==5)) {
                            str[5];
                        }
                            if ((*pc==6) || (*pd==6) || (*pu==6)) {
                                str[6];
                            }
                                if ((*pc==7) || (*pd==7) || (*pu==7)) {
                                    str[7];
                                }
                                    if ((*pc==8) || (*pd==8) || (*pu==8)) {
                                        str[8];
                                    }
                                        if ((*pc==9) || (*pd==9) || (*pu==9)) {
                                            str[9];
                                        }

    sprintf (str, str, str, "%i %i %i", *pu, *pd, *pc);
    return ;
}

int main ()
{
    int num, c, d, u;
    printf ("Digite um valor inteiro: ");
    scanf ("%d",&num);

    algarismo (num, &c, &d, &u);
    return 0;
}
