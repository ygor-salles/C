#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER 256

int main(int argc,char *argv[]) {

    int fd=atoi(argv[1]); 
    
    printf("Meu pid = %d. Estou calculando o seno...\n", getpid());
    
    //close(fd[0]);
    char buffer_seno_escrita[BUFFER] = "0.5";
    write(fd, buffer_seno_escrita, sizeof(buffer_seno_escrita));
    
    return 0;
}
