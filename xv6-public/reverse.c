#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    string palabra = "";
    
    if(argc == 1){
        printf("No diste valores \n");
        
    }else{
        palabra=argv[argc];
        for(int i=argc-1; i>1; i--){
       palabra=strcat(palabra, argv[i]);
        }
        
    }
    printf(palabra);
   return 0;
}
