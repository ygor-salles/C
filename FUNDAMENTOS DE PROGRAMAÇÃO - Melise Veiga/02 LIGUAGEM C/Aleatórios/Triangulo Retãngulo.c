#include<stdio.h>

int main()
{
    int i, n, j;

    printf("Digite valor de N: "); scanf("%d",&n);
    for (i=1; i<=n; i++){
        printf("\n #");
        for(j=1; j<i; j++)
            printf("#");
    }

    printf("\n\n");
    return 0;
}
