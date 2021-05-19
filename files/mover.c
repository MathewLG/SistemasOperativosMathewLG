#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
//Mathew Gabriel Lopez Garcia A01635001
int main(int argvnum, char **argv){
    if(argvnum < 2 ){
        printf("Numero incorrecto de argumentos");
        return -1;
    }
    char *path = argv[1]; 
    char *pathdos = argv[2];
    struct stat sb;
    struct stat sbdos;
    if(stat(path, &sb) == -1){
        printf("Error el archivo no existe \n");
        return -1;
    }
    if(S_ISDIR(sb.st_mode)){
        printf("El archivo a modificar es un directorio, no puedo hacer nada por ti \n");
        return -1;
    } 
    if(stat(pathdos,&sbdos) == -1){
        printf("El archivo 2 no existe \n");
        printf("Renombrando archivo 1 con el nombre de archivo 2");
        link(path,pathdos);
        unlink(path);
    }
    if(stat(pathdos,&sbdos) == 0){
        if(S_ISREG(sbdos.st_mode)){
            printf("El archivo 2 ya existe, no puedes usar su nombre\n");
            return -1;
        }
        if(S_ISDIR(sbdos.st_mode)){
            printf("Moviendo el archivo al directorio indicado \n");
            strcat(pathdos,"/");
            link(path,strcat(pathdos,path));
            unlink(path);
        }
       
    }
    return 1;
}
