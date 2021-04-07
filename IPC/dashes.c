#include <unistd.h>
#include <stdio.h>
int main(){
	execl("/usr/bin/ls","ls","-l",NULL);
	printf("Esto no debe verse \n");
	return 0;
}