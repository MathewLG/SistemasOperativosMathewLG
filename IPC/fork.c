#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
int varGlobal;

void signalHandler(int sig){
  printf("Recibi segnal %d\n", sig);
	varGlobal = sig;
}
int main(){
	int pid = fork();
	int pidHijoTermino;
	if(pid == 0){
		//Proceso hijo 
		printf("Soy el proceso hijo \n");
	}else{
		signal(17, signalHandler);
		while(1){
			printf("Estoy trabajando \n");
			sleep(.1);
			if(varGlobal == 17){
				break;
			}
		}
		printf("Soy el proceso padre y mi hijo es %d\n",pid);
		//pidHijoTermino = wait(NULL);
		printf("Mi hijo termino %d \n", pidHijoTermino);
	}
	printf("Terminando\n");
	return 0;
}