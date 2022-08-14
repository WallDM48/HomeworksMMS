#include<stdio.h>
#include<signal.h>
#include<stdbool.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>

void ms_sleep(int s){
    usleep(s*100000);
}

int main()
{
    if (SIG_ERR == signal(SIGINT, SIG_IGN)) // ignore ctrl +c
    {
        perror("signal");
        exit(EXIT_FAILURE);
    }
    if (SIG_ERR == signal(SIGTSTP, SIG_IGN)) // ignore ctrl+z 
    {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    printf("PID: %d\n",getpid());
    while (1){
        
        printf("MMS STAR CAMP!\n");
        ms_sleep(5);
        
    }
        
// we can stop the program only with kill -9 and kill -19 because they sent signals to the core 

    return EXIT_SUCCESS;
}