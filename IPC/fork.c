#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int varGlobal;

void signalHandler(int sig){
    printf("Recibi segnal %d\n", sig);
	printf("Mi hijo termino \n");
	varGlobal = wait(NULL);
}
int main(){
	int pid = fork();
	int pidHijoTermino;
	signal(17, signalHandler);
	if(pid == 0){
		//Proceso hijo 
		printf("Soy el proceso hijo \n");
	}else{
		while(1){
			printf("Estoy trabajando \n");
			sleep(1);
		}
		printf("Soy el proceso padre y mi hijo es %d\n",pid);
		//pidHijoTermino = wait(NULL);
		printf("Mi hijo termino \n");
	}
	printf("Terminando\n");
	return 0;
}