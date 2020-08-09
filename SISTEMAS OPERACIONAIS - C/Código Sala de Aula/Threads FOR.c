#include<stdio.h>
#include<pthread.h>
#define NUM_THREADS 5

void *ola(void *argumentos)
{
    printf ("\nHellow world!\n");
    pthread_exit(NULL);
}

int main ()
{
    pthread_t thread[5];
    int flag, i;
    printf ("\nCriando um novo thread!\n");

    for (i=0; i<NUM_THREADS; i++)
        pthread_create(&thread[i], NULL, ola, NULL);

    for (i=0; i<NUM_THREADS; i++)
        pthread_join(thread[i], NULL);

    /*if (pthread_create(&thread, NULL, ola, NULL))
        printf ("Erro na criacao do thread");

    if (pthread_join(thread, NULL))
        printf ("Erro na juncao do thread");*/

    /*flag = pthread_create(&thread, NULL, ola, NULL);
    if (flag!=0)
        printf ("\nERROR NA CRIACAO DO THREAD\n");
    pthread_join(thread, NULL);*/

    return 0;
}
