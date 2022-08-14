#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

void *routine(void* arg){
    char buf[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    char *sym = malloc(11*sizeof(char));
    for (int i = 0; i < 10; i++)
    {
        sym[i] = buf[rand()%52];
    }
    sym[10] = '\0';
    printf("%s\n",sym);
    

}

int main(){
    srand(time(0));
    int n;
    scanf("%d",&n);
    pthread_t th[n];
    for (int i = 0; i < n; i++)
    {
        if(pthread_create(th+i,NULL,routine,NULL)){
            perror("pthread create\n");
            exit(-1);
        }
    }
    for (int i = 0; i < n; i++)
    {
       if(pthread_join(th[i],NULL)){
        perror("pthread join\n");
        exit(-1);
       }
    }
    
    


    return 0;
}