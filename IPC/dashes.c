#include <unistd.h>
#include <stdio.h>
int main(){
    int fd[2]; //Indice 0 entrada, indice 2 salida (fd significa file descriptor)
    int pid;
    pipe(fd);
    pid = fork();
    //A partir de aqui (despues del fork) tengo dos procesos clones
    if(pid == 0){//Proceso hijo
        close(fd[1]);
        dup2(fd[0],STDIN_FILENO);
        execl("/usr/bin/tr","tr","' ","-",NULL);
    }
    if(pid > 0){//Proceso padre
        close(fd[0]);
        dup2(fd[1],STDOUT_FILENO);
        execl("/usr/bin/cat","cat",NULL);
    }
	return 0;
}