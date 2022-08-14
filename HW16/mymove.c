#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>

int main(int argc, char *argv[] )
{
    int i,fd1,fd2;
    char buf[2];

    printf("file1=%s file2=%s",argv[1],argv[2]);
    fd1=open(argv[1],O_RDONLY,0777);
    fd2=creat(argv[2],0777);
    while(i=read(fd1,buf,1)>0){
    write(fd2,buf,1);}

    remove(argv[1]);
    close(fd1);
    close(fd2);
    return 0;
}