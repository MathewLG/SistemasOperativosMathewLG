#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define NUMTHREADS 20

void *printHelloWorld(void *datos) { 
    printf("Hello world desde un hilo %d\n", *(int*)datos); 
    sleep(3);
    printf("otra cosa\n");
    pthread_exit(NULL);
}

int main() { 
    pthread_t myThreads[NUMTHREADS];
    int tIds[NUMTHREADS];
    for(int i = 0; i< NUMTHREADS; i++){
        tIds[i] = i;
         pthread_create(&myThreads[i],NULL,printHelloWorld, &tIds[i]);
    }
   
    pthread_exit(NULL);
}
