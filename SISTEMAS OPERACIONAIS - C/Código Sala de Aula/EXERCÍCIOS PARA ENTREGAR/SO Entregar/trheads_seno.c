#include<stdio.h>
#include<pthread.h>

void *imprime_seno (void *x_seno)
{
    int *x_seno = (int*)x_seno;
    
    printf ("Valor do seno eh: %.2f",*x_seno);
    
    pthread_exit(NULL);
}

int main ()
{
    pthread_t thread_seno;
    
    if (pthread_create(&thread_seno, NULL, incrementa_x, &x))
        printf ("Erro na criacao do thread_seno");

    if (pthread_seno_join(thread_seno, NULL))
        printf ("Erro na juncao do thread");

    return 0;
}