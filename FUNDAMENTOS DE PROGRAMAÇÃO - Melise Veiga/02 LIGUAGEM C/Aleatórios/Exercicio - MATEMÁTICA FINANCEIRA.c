#include<stdio.h>
#include<math.h>

int main()
{
    float emprestimo, p, i, j, total;
    int n;

    printf("Informe emprestimo: ");
    scanf("%f",&emprestimo);
    printf("Informe entrada: ");
    scanf("%f",&p);
    printf("Informe numero de parcelas: ");
    scanf("%d",&n);
    printf("Informe Taxa de juros mensal: ");
    scanf("%f",&i);

    i = i/100;

    j = p*(pow((1+i),n)-1);

    printf("\nO rendimento eh: %.2f",j);

    total = emprestimo + j;

    printf("\nO valor total pago eh: %.2f\n\n",total);

    return 0;
}
