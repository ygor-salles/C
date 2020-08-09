#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<math.h>
#include<sys/types.h>

#define BUFFER 256

double cosseno(float x, int n);
double seno(float x, int n);

int main(void)
{
    int fd[2], n;
    pid_t pid;
    float x, soma_seno, soma_cosseno, tangente;

    printf ("Digite o valor de X: ");
    scanf ("%f",&x);
    printf ("Digite a quantidade de termos da serie: ");
    scanf ("%d",&n);

    soma_cosseno = cosseno(x, n);
    printf ("\n A soma cosseno eh de: %.8f\n",soma_cosseno);

    soma_seno = seno(x, n);
    printf ("\n A soma seno eh de: %.8f\n",soma_seno);
    if (soma_cosseno != 0){
        tangente = soma_seno/soma_cosseno;
    }
    else{
        printf ("\n\nA soma cosseno deu zero, erro de calculo para a tangente!\n");
        return 0;
    }

    //Criação de Pipes
    if(pipe(fd)<0) {
        perror("pipe") ;
        return -1 ;
    }
    if ((pid = fork()) < 0){
        perror("fork");
        exit(1);
    }
    //Processando
    if (pid > 0){
        close(fd[0]);

        double tangente;
        printf("Tangente enviada pelo filho no Pipe: %.8f\n\n",tangente);

        write(fd[1], tangente, sizeof(tangente) + 1);
    }
    else{
        double tangente_recebida;

        close(fd[1]);

        read(fd[0], tangente_recebida, sizeof(tangente_recebida));
        printf("Tangente lida pelo pai no Pipe : %.8f\n\n",tangente_recebida);
    }

    return 0;
}

double cosseno(float x, int n)
{
    int fat, i, expo=2, fatorial;
    float soma_cosseno=1;

    if (n>=2){
        for (i=2; i<=n; i++){
            fat=1;
            for(fatorial=expo; fatorial>=1; fatorial--)
                fat=fatorial*fat;

                if (i%2==0)
                    soma_cosseno= soma_cosseno-((pow(x,expo))/(float)fat);
                else
                    soma_cosseno= soma_cosseno+((pow(x,expo))/(float)fat);

                expo=expo+2;
        }
    }
    return soma_cosseno;
}

double seno(float x, int n)
{
    int fat, i, expo=3, fatorial;
    float soma_seno=x;

    if (n>=2){
        for (i=2; i<=n; i++){
            fat=1;
            for(fatorial=expo; fatorial>=1; fatorial--)
                fat=fatorial*fat;

            if (i%2==0)
                soma_seno= soma_seno-((pow(x,expo))/(float)fat);
            else
                soma_seno= soma_seno+((pow(x,expo))/(float)fat);

            expo=expo+2;
        }
    }
    return soma_seno;
}
