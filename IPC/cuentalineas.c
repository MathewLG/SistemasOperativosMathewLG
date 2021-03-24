#include <unistd.h>
#include <ctype.h>
#include <stdio.h>
int main(){
	int lineas = 0;
	char current;
	while(read(0,&current,1)){
		if(current == '\n'){
			lineas++;
		}
	}
	if(current != '\n'){
		lineas++;
	}
	printf("Lineas : %d\n",lineas);
	return 0;
}