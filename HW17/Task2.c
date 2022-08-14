#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>

int main(int argc, char **argv){
    int fd[2];
    if(pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }
    pid_t pid1 = fork();
    
    if(!pid1){
        int sum1=0;
        close(fd[0]);
        for (int i = 1; i < ((argc)/2) +1; i++)
        {
            sum1 += atoi(argv[i]);
        }
        printf("sum1 = %d\n",sum1);
        write(fd[1],&sum1,sizeof(sum1));
        close(fd[1]);
    }
    else{
        close(fd[1]);
        int sum2 = 0;
        for (int i = ((argc)/2) +1; i < (argc); i++)
        {
            sum2 += atoi(argv[i]);
        }
        printf("sum2 = %d\n",sum2);
        int sumFromChild;
        read(fd[0],&sumFromChild,sizeof(int));
        wait(NULL);
        int total = sumFromChild + sum2;
        printf("total = %d\n",total);
        close(fd[0]);
    }

    return 0;
}