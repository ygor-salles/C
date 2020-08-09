#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER 256

int main() {
    
    int fd[2];  // descritores de arquivo do pipe
    
    pipe(fd);
    
    // fd[0] = leitura
    // fd[1] = escrita    
    
    char *args2[] = {"./cosseno", NULL};
    
    pid_t pid1 = -10;
    pid_t pid2 = -10;
    
    printf("Pid do pai = %d\n", getpid());
    
    pid1 = fork();  
    
    if (pid1 > 0)
        pid2 = fork();
    
    if (pid1 == 0) {
				char targ[10];
        sprintf(targ,"%d",fd[1]);
				char *args1[] = {"./seno", targ, NULL};
				execv("./seno", args1);
		}
        
    
    if (pid2 == 0)
        execv("./cosseno", args2);
    
    wait( NULL );
    
    char buffer_seno[BUFFER];
    close( fd[1] );
    read( fd[0], buffer_seno, sizeof(buffer_seno) );
    
    printf("Valor do seno que foi lido: '%s'\n", buffer_seno);
    
    return 0;
}





