#include<stdio.h>

int main(){
    double max = __DBL_MIN__;
    double number;
    for (int i = 0; i < 3; i++)
    {
        scanf("%lf",&number);
        if(max<number){
            max=number;
        }
    }
    printf("The biggest number is: %.2lf", max);

    /*The linux command code :
        gcc Task1.c -o t1 
        ./t1 < numbers*/
    return 0;
}