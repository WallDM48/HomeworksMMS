#include<stdio.h>

void squareRoot(int* number){
    float temp, sqrt;
    temp = 0;
    sqrt = temp / 2.0;
    while(sqrt != temp){
        temp = sqrt;
        sqrt = ( *number/temp + temp) / 2.0;
    }
    printf("%f\n",sqrt);

}    

int main(){
    
    int number;

    printf("Provide the number: \n");

    scanf("%d", &number);

    squareRoot(&number);


    return 0;
}