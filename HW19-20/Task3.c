#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<pthread.h>
#include<getopt.h>
#include<string.h>


void *routine(void *arg){
    char *mess = (char*)arg;
    printf("My PID  = %d, Thread ID = %ld, Message : %s \n",getpid(),pthread_self(),mess);
}

int main(int argc, char **argv){
    int opt;
    int threads;
    int proc;
    char message[200];

    while((opt = getopt(argc, argv, ":P:T:M:")) != -1) 
    { 
        switch(opt) 
        { 
            case 'P': 
                sscanf(optarg,"%d",&proc); 
                break; 
            case 'T': 
                sscanf(optarg,"%d",&threads); 
                break; 
            case 'M': 
                strcpy(message,optarg);
                break; 
            case '?': 
                printf("unknown option: %c\n", optopt);
                break; 
        } 
    } 

    for (int i = 0; i < proc; i++)
    {
        pid_t pid = fork();
        if(-1 == pid){
            exit(EXIT_FAILURE);
        }
        if(!pid){
            //child
            pthread_t th[threads];
            for(int j =0;j<threads;j++){
                if(pthread_create(th+j,NULL,routine,message)){
                    exit(-1);
                }
            }
            for(int j =0;j<threads;j++){
                if(pthread_join(th[j],NULL)){
                    exit(-1);
                }
            }
            exit(EXIT_SUCCESS);
        }
        else{

            //parent

        }
    }
    for (int i = 0; i < proc; i++)
    {
        wait(NULL);
    }


    return 0;    
}