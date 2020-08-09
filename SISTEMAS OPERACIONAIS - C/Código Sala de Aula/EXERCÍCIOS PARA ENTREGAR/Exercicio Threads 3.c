#include<stdio.h>
#include<pthread.h>

int counter;

void *incrementa_x(void *x_void)
{
    int *x = (int*)x_void;
    int i;
    counter = 0;

    printf ("\nTrabalho %d comecou!",*x);
    for (i=0; i<10000; i++)
        counter++;
    printf ("\nTrabalho %d terminou!",*x);

    pthread_exit(NULL);
}

int main ()
{
    pthread_t thread[2];
    int x=1, y=2, i;

    pthread_create(&thread[0], NULL, incrementa_x, &x);
    pthread_create(&thread[1], NULL, incrementa_x, &y);

    for (i=0; i<2; i++)
        pthread_join (thread[i], NULL);

    return 0;
}
