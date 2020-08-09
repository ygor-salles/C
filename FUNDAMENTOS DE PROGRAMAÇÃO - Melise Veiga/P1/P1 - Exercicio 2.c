#include<stdio.h>

/* P1 - Exercicio 2 */

int main ()
{
    char raca, escola;
    float salario;
    int n, i, c1=0, c2=0, c3=0, c4=0;

    printf ("Digite a quantidade de alunos: ");
    scanf ("%d",&n);

    for (i=1; i<=n; i++){
        printf ("\nDigite a sua raca: (b)branca, (g)negra ou (p)parda): ");
        scanf (" %c",&raca);
        printf ("Digite sua escola (p)publica ou (r)privada: ");
        scanf (" %c",&escola);
        printf ("Informe o salario: R$");
        scanf ("%f",&salario);

        if (raca == 'g'){
            c1++;
        }
        if ((escola == 'p') && (salario<500)){
            c2++;
            if (raca == 'g'){
                c3++;
            }
        }
        if ((raca == 'g') || (escola == 'p' && salario<500)){
            c4++;
        }
    }
    printf ("\nA quantidade de alunos que atenderam a condicao 1 eh: %d",c1);
    printf ("\nA quantidade de alunos que atenderam a condicao 2 eh: %d",c2);
    printf ("\nA quantidade de alunos que atenderam as duas condicoes eh: %d",c3);
    printf ("\nA quantidade de alunos especiais eh: %d\n",c4);

    return 0;
}
