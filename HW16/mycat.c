#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>

int main(int argc, char **argv){
    int fr =open(argv[1],O_RDONLY);
    if(-1 == fr){
        fprintf(stderr,"Error opening!\n");
        printf("errno = %d\n",errno);
        return -1;
    }
    
    char buff[BUFSIZ];
    int n;
    while((n = read(fr,buff,BUFSIZ)) !=0){
        write(STDOUT_FILENO,buff,n);
    }

    close(fr);
    
    
    

    return 0;
}