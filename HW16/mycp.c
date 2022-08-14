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
    int fw = open(argv[2],O_WRONLY | O_CREAT | O_APPEND,0777);
    char buff[BUFSIZ];
    int n;
    while((n = read(fr,buff,BUFSIZ)) !=0){
        write(fw,buff,n);
    }

    close(fr);
    close(fw);
    return 0;
}
    