#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*Listar operções de escolha a partir da entrada dedois números
digitados e mostrar o resultado conforme escolha de usuário.

"Opção 1: Media entre os números digitados. "
"Opção 2: Diferença do maior pelo menor. "
"Opção 3: Produto entre os números digitados. "
"Opção 4: Divisão do primeiro pelo segundo: " */

int main ()
{
    int op;
    float media, subt, produto, divis, a, b;

    printf ("Digite o valor de A: ");
    scanf ("%f",&a);
    printf ("Digite o valor de B: ");
    scanf ("%f",&b);

    printf ("\n Opcao 1: Media entre os numeros digitados. \n");
    printf ("\n Opcao 2: Diferenca do maior pelo menor. \n");
    printf ("\n Opcao 3: Produto entre os numeros digitados. \n");
    printf ("\n Opcao 4: Divisao do primeiro pelo segundo: \n");
    printf ("\n Digite a opcao desejada de 1 a 4 : ");
    scanf ("%d",&op);

    if ((op<1) || (op>4)) {
    printf ("\n\n OPCAO INVALIDA! \n\n");
    }else{
    switch (op){
case 1:
    media = (a+b)/2;
    printf ("\n\n A media dos numeros digitados eh: %.2f\n\n",media);
    break;
case 2:
    if (a>b) {
        subt = a-b;
    }
    else{
        subt = b-a;
    }
    printf ("\n\n A diferenca do maior pelo menor eh: %.2f\n\n",subt);
    break;
case 3:
    produto = a*b;
    printf ("\n\n O produto dos numeros digitados eh: %.2f\n\n",produto);
    break;
case 4:
    if (b!=0) {
        divis = a/b;
        printf ("\n\n A divisao entre os numeros eh de: %.2f\n\n",divis);
    }
    else {
        printf ("\n\n Nao existe numero divisivel por 0 dentro dos reais!\n\n");
    }

    }
    }
    return 0;
}
