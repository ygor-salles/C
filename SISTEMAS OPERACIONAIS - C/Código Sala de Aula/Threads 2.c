#include<stdio.h>
#include<pthread.h>
#define NUM_THREADS 5

void *incrementa_x(void *x_void_ptr)
{
    int *x_ptr = (int*)x_void_ptr;
    ++(*x_ptr);

    printf ("Valor final de x: %d\n",*x_ptr);

    pthread_exit(NULL);
}

int main ()
{
    pthread_t thread;
    int x=5;

    printf ("\nCriando um novo thread!\n");

    if (pthread_create(&thread, NULL, incrementa_x, &x))
        printf ("Erro na criacao do thread");

    if (pthread_join(thread, NULL))
        printf ("Erro na juncao do thread");

    return 0;
}
