#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

#define COMMAND_COUNT 2

int fork_exec(const char *name)
{
    pid_t pid = fork();

    if(-1 == pid){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if(!pid){
        if (-1 == execlp(name,name, NULL))
        {
            perror("execlp");
            exit(EXIT_FAILURE);
        }
    }

    int status;
    if (-1 == wait(&status))
    {
        perror("wait");
        exit(EXIT_FAILURE);
    }

    return WEXITSTATUS(status);
}

int main(int argc, char **argv)
{
    if (argc < COMMAND_COUNT + 1)
        exit(-1);

    int exit_status = fork_exec(argv[1]);
    if (0 == exit_status){
        return exit_status;
    }
    exit_status = fork_exec(argv[2]);

    return exit_status;
}