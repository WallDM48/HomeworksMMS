#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<time.h>

void rand_char(char *arr){
    
    char buf[] = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    for (int i = 0; i < 10; i++)
    {
        arr[i] = buf[rand()%52];
    }
    
}

int main(){
    srand(time(0));
    int n;
    scanf("%d",&n);
    
    
    for (int i = 0; i < n; i++)
    {
        char *sym = malloc(10*sizeof(char));
        rand_char(sym);
        pid_t pid = fork();
        
        
        if(-1 == pid){
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if(0 == pid){
           
        
            printf("10 rand syms : %s\n",sym);
            
            exit(EXIT_SUCCESS);
        }
        free(sym);
        
        
    }

    for (int i = 0; i < n; i++)
    {
        wait(NULL);
    }
     

    return 0;
}