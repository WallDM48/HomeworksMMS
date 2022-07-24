#include <stdio.h>
#include <stdlib.h>


int sum(int* arr,int n){
    int s = 0;
    for(int i = 0; i < n; i++){
        s += arr[i];
    }
    return s;

}
int mult(int* arr,int n){
    int m = 1;
    for(int i = 0; i < n; i++){
        m *= arr[i];
    }
    return m;

}
void arrayEvaluate(int* arr, size_t n, int(*f)(int*,int)){
    int fpr = (*f)(arr,n);
    printf("%d\n",fpr);
}


int main(){
    int arr[] = {1,2,3,4};
    int(*f)(int*,int);
    f = &sum;
    arrayEvaluate(arr,4,sum);
    f = &mult;
    arrayEvaluate(arr,4,mult);
    
    return 0;
}