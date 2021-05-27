#include <stdio.h>
#include <stdlib.h>
#include "./student.h"
#include <string.h>
int main(int argc, char **argv){
    char *filename = argv[1];
    char* tipo = argv[2];
    char* argumentoBusqueda = argv[3];
    int nombre = strcmp(tipo,"name");
    int apellido = strcmp(tipo,"lastname");
    int id = strcmp(tipo,"id");;
    int semestre = strcmp(tipo,"semestre");;
    //printf("%s",tipo);
    FILE *forigen;
    forigen = fopen(filename, "rb");
    if(nombre == 0){
        printf("BUSCAR POR NOMBRE \n");
        for(int i = 0; i < 2; i++){
            STUDENT newstudent;
            fread(&newstudent,sizeof(newstudent),1,forigen);
            if(strstr(newstudent.name,argumentoBusqueda) != NULL){
            printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }
        
        }       
    }
    if(apellido == 0){
        printf("BUSCAR POR APELLIDO \n");
        for(int i = 0; i < 2; i++){
            STUDENT newstudent;
            fread(&newstudent,sizeof(newstudent),1,forigen);
            if(strstr(newstudent.lastname,argumentoBusqueda) != NULL){
            printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }
        
        } 
    }
    if(id == 0){
        printf("BUSCAR POR ID \n");
        for(int i = 0; i < 2; i++){
            STUDENT newstudent;
            fread(&newstudent,sizeof(newstudent),1,forigen);
            if(newstudent.id == atoi(argumentoBusqueda)){
            printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }
        
        } 
    }
    if(semestre == 0){
        printf("BUSCAR POR SEMESTRE \n");
        for(int i = 0; i < 2; i++){
            STUDENT newstudent;
            fread(&newstudent,sizeof(newstudent),1,forigen);
            if(newstudent.semestre == atoi(argumentoBusqueda)){
            printf("%s %s %d %d \n",newstudent.name,newstudent.lastname,newstudent.id,newstudent.semestre);
            }
        
        } 
    }

    
    fclose(forigen);
}