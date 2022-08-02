#include<stdio.h>
#include<stdlib.h>
#include<time.h>



int main(){
    
    //int arr[1000];
    int* ptr; 
    int count=0;
    srand(time(0));
    ptr = (int*) malloc(1000*sizeof(int));
    for(int i = 0; i<1000; i++){
        ptr[i] = 250 + (rand()%500);
        printf("%d\t",ptr[i]);
        if(i%15 == 0){
            puts("\n");
        }
        if(ptr[i] == 500){
            count++;
        }
    }
    free(ptr);
    printf("The amount of 500 is : %d\n",count);
    return 0;
}