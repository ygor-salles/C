#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER 256

int main() {
    
    int fd1[2];
    int fd2[2];  // descritores de arquivo do pipe
    
    pipe(fd1);
    pipe(fd2);
    
    // fd[0] = leitura
    // fd[1] = escrita    
    
    char *args2[] = {"./cosseno", NULL};
    char *args1[] = {"./seno", NULL};
    
    pid_t pid1 = -10;
    pid_t pid2 = -10;
    
    printf("Pid do pai = %d\n", getpid());
    
    pid1 = fork();  
    
    if (pid1 > 0)
        pid2 = fork();
    
    if (pid1 == 0) {
        char targ1[10];
        sprintf(targ1,"%d",fd1[1]);
        char *args1[] = {"./seno", targ1, NULL};
        execv("./seno", args1);
    }
        
    
    if (pid2 == 0){
        char targ2[10];
        sprintf(targ2,"%d",fd2[1]);
        char *args2[] = {"./coseno", targ2, NULL};
        execv("./cosseno", args2);
    }
    wait( NULL );
    
    char buffer_seno[BUFFER];
    close( fd1[1] );
    read( fd[0], buffer_seno, sizeof(buffer_seno) );
    printf("Valor do seno que foi lido: '%s'\n", buffer_cosseno);
    
    char buffer_cosseno[BUFFER];
    close( fd2[1] );
    read( fd2[0], buffer_cosseno, sizeof(buffer_cosseno) );
    printf("Valor do seno que foi lido: '%s'\n", buffer_cosseno);
    
    return 0;
}





