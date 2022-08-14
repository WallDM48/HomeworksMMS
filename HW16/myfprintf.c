#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include<string.h>

/*void myfprintf(int fd, char *format, void *value){
   
    if(strcmp(format,"%d")){
        //printf("tuk sym\n");
        write(fd,value,sizeof(int));
    }
    if(strcmp(format,"%f")){
        write(fd,value,sizeof(float));
    }
    if(strcmp(format,"%lf")){
        write(fd,value,sizeof(double));
    }
    free(value);

}*/

int main(int argc, char**argv){
   // int fd = atoi(argv[1]);
    //char *format = malloc(sizeof(argv[2]));
    int n = 5;

    //if(strcmp(format,"%d")){

    write(STDOUT_FILENO,&n,sizeof(int));
   // }



    return 0;
}