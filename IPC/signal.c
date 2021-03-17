#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int varGlobal;

void signalHandler(int sig){
  printf("Recibi segnal %d\n", sig);
	varGlobal = sig;
}

int main(){
  signal(2, signalHandler);
  signal(15, signalHandler);
  while(1){
    printf("Trabajando\n");
    sleep(1);
	if(varGlobal >0){
		break;
	}
  }
  printf("Ya voy a terminar \n");
  return 0;
}