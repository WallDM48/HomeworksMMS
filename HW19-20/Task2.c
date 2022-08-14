#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#include<time.h>

int compare (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

void *routine(void* arg){
    int arr[100];  
    int n;
    int i =0;
    while (fscanf(arg,"%d",&n) !=EOF)
    {
        arr[i] = n;
        i++;
    }
    qsort(arr,i,sizeof(int),compare);
    fprintf(arg,"The numbers after sort:\n");
    for (int j = 0; j < i; j++)
    {
        fprintf(arg,"%d\n",arr[j]);
    }
    
    fclose(arg);
}

int main(int argc, char **argv){
  
    pthread_t th[argc-1];
    for (int i = 1; i < argc; i++)
    {   FILE *f = fopen(argv[i],"r+");
        if(!f){
            perror("fopen\n");
            exit(-1);
        }
        if(pthread_create(th+i,NULL,routine,f)){
            perror("pthread create\n");
            exit(-1);
        }
       
    }
    
    for (int i = 1; i < argc; i++)
    {
        if(pthread_join(th[i],NULL)){
            perror("phtread join\n");
            exit(-1);
        }
    }
    return 0;
}